import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
import math
import numpy as np
import csv
from threading import Lock
import time

from geometry_msgs.msg import Pose, Twist, Point
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool
from swarm_msgs.msg import DroneState
from swarm_msgs.srv import DisarmLeader
from swarm_msgs.action import ExecuteMission

# Simple quaternion to euler conversion
def euler_from_quaternion(x, y, z, w):
    """Convert quaternion to euler angles (roll, pitch, yaw)"""
    # Roll (x-axis rotation)
    sinr_cosp = 2 * (w * x + y * z)
    cosr_cosp = 1 - 2 * (x * x + y * y)
    roll = math.atan2(sinr_cosp, cosr_cosp)

    # Pitch (y-axis rotation)
    sinp = 2 * (w * y - z * x)
    if abs(sinp) >= 1:
        pitch = math.copysign(math.pi / 2, sinp)  # use 90 degrees if out of range
    else:
        pitch = math.asin(sinp)

    # Yaw (z-axis rotation)
    siny_cosp = 2 * (w * z + x * y)
    cosy_cosp = 1 - 2 * (y * y + z * z)
    yaw = math.atan2(siny_cosp, cosy_cosp)

    return roll, pitch, yaw

class SwarmDrone(Node):
    def __init__(self):
        super().__init__('swarm_drone_node')
        
        # Parameter declarations
        self.declare_parameter('drone_id', 0)
        self.declare_parameter('role', 'follower')
        self.declare_parameter('max_velocity', 2.5)
        self.declare_parameter('safety_distance', 3.5)
        self.declare_parameter('home_position', [0.0, 0.0, 5.0])
        self.declare_parameter('use_sim_time', True)
        
        # Get parameters
        self.drone_id = self.get_parameter('drone_id').value
        self.role = self.get_parameter('role').value
        self.max_velocity = self.get_parameter('max_velocity').value
        self.safety_distance = self.get_parameter('safety_distance').value
        self.home_position = self.get_parameter('home_position').value
        
        # State variables
        self.state_lock = Lock()
        self.current_pose = Pose()
        self.current_velocity = Twist()
        self.target_pose = Pose()
        self.target_pose.position = Point(
            x=self.home_position[0], 
            y=self.home_position[1], 
            z=self.home_position[2]
        )
        self.is_armed = False
        self.is_enabled = False
        self.other_drones = {}
        self.last_communication = {}
        self.mission_active = False
        self.waypoint_list = []
        self.current_waypoint_index = 0
        self.leader_id = 0
        self.leader_timeout = 8.0
        self.last_leader_contact = self.get_clock().now().nanoseconds / 1e9
        
        # Publishers
        self.velocity_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.enable_publisher = self.create_publisher(Bool, 'enable', 10)
        self.state_publisher = self.create_publisher(
            DroneState, f'/swarm/state/drone_{self.drone_id}', 10
        )
        
        # Subscribers
        self.odom_subscriber = self.create_subscription(
            Odometry, 'odom', self.odometry_callback, 10
        )
        self.arm_subscriber = self.create_subscription(
            Bool, f'/drone_{self.drone_id}/arm', self.arm_command_callback, 10
        )
        self.target_subscriber = self.create_subscription(
            Pose, f'/swarm/target_pose/drone_{self.drone_id}', 
            self.target_update_callback, 10
        )
        
        # Subscribe to other drones
        for i in range(4):
            if i != self.drone_id:
                self.create_subscription(
                    DroneState, f'/swarm/state/drone_{i}',
                    lambda msg, drone_id=i: self.other_drone_update_callback(msg, drone_id),
                    10
                )
        
        # Services and actions
        self.mission_action_server = ActionServer(
            self, ExecuteMission, '/execute_mission', 
            self.execute_mission_callback
        )
        self.disarm_service = self.create_service(
            DisarmLeader, '/disarm_leader', 
            self.handle_disarm_request
        )
        
        # Timers
        self.control_timer = self.create_timer(0.08, self.control_loop)  # 12.5 Hz
        self.state_timer = self.create_timer(0.15, self.publish_drone_state)  # 6.7 Hz
        self.leadership_timer = self.create_timer(1.5, self.check_leadership_status)
        self.enable_timer = self.create_timer(0.5, self.publish_enable_status)
        
        # Initialize as armed and enabled for leader
        if self.role == 'leader':
            self.is_armed = True
            self.is_enabled = True
        
        self.get_logger().info(f"Drone {self.drone_id} started as {self.role}")

    def odometry_callback(self, msg):
        """Handle odometry messages from Gazebo"""
        with self.state_lock:
            self.current_pose = msg.pose.pose
            self.current_velocity = msg.twist.twist

    def arm_command_callback(self, msg):
        """Handle arm/disarm commands"""
        with self.state_lock:
            if self.is_armed != msg.data:
                self.is_armed = msg.data
                self.is_enabled = msg.data  # Enable/disable motor control
                status = "ARMED" if self.is_armed else "DISARMED"
                self.get_logger().info(f"Drone {self.drone_id} {status}")

    def target_update_callback(self, msg):
        """Handle new target pose from formation controller"""
        with self.state_lock:
            self.target_pose = msg
            
    def publish_enable_status(self):
        """Publish enable status to Gazebo multicopter plugin"""
        enable_msg = Bool()
        enable_msg.data = self.is_enabled
        self.enable_publisher.publish(enable_msg)

    def other_drone_update_callback(self, msg, drone_id):
        """Handle updates from other drones"""
        current_time = self.get_clock().now().nanoseconds / 1e9
        with self.state_lock:
            self.other_drones[drone_id] = msg
            self.last_communication[drone_id] = current_time
            
            # Track leader
            if hasattr(msg, 'role') and msg.role == 'leader':
                if self.leader_id != drone_id:
                    self.get_logger().info(f"New leader detected: drone_{drone_id}")
                self.leader_id = drone_id
                self.last_leader_contact = current_time

    def control_loop(self):
        """Main control loop"""
        if not self.is_armed or not self.is_enabled:
            # Send zero velocity when disarmed
            self.velocity_publisher.publish(Twist())
            return

        with self.state_lock:
            if self.role == 'leader':
                self.execute_leader_control()
            else:
                self.execute_follower_control()

    def execute_leader_control(self):
        """Control logic for leader drone"""
        # Mission waypoint following for leader
        if self.mission_active and self.current_waypoint_index < len(self.waypoint_list):
            target_waypoint = self.waypoint_list[self.current_waypoint_index]
            self.target_pose.position.x = target_waypoint[0]
            self.target_pose.position.y = target_waypoint[1]
            self.target_pose.position.z = target_waypoint[2]
            
            # Check if waypoint is reached
            distance_to_waypoint = self.calculate_distance_to_target()
            if distance_to_waypoint < 2.0:  # Increased tolerance
                self.current_waypoint_index += 1
                if self.current_waypoint_index < len(self.waypoint_list):
                    self.get_logger().info(
                        f"Leader moving to waypoint {self.current_waypoint_index + 1}"
                    )
                else:
                    self.get_logger().info("Leader mission completed")
                    self.mission_active = False

        # PID control for position
        control_cmd = self.calculate_position_control()
        
        # Apply safety constraints
        control_cmd = self.apply_collision_avoidance(control_cmd)
        
        # Add yaw control for forward movement
        if abs(control_cmd.linear.x) > 0.1 or abs(control_cmd.linear.y) > 0.1:
            target_yaw = math.atan2(
                self.target_pose.position.y - self.current_pose.position.y,
                self.target_pose.position.x - self.current_pose.position.x
            )
            control_cmd.angular.z = self.calculate_yaw_control(target_yaw)
        
        self.velocity_publisher.publish(control_cmd)

    def execute_follower_control(self):
        """Control logic for follower drones"""
        # Find leader position
        if self.leader_id not in self.other_drones:
            # No leader found, hover in place or go to formation target
            if (self.target_pose.position.x == 0 and 
                self.target_pose.position.y == 0 and 
                self.target_pose.position.z == 0):
                # No target, hover
                self.velocity_publisher.publish(Twist())
                return
        
        # Use formation target if available
        if (self.target_pose.position.x != 0 or 
            self.target_pose.position.y != 0 or 
            self.target_pose.position.z != 0):
            # Formation control active - use target from formation controller
            target_position = self.target_pose.position
        else:
            # Default following behavior if no formation target
            if self.leader_id in self.other_drones:
                leader_state = self.other_drones[self.leader_id]
                leader_pos = leader_state.pose.position
                following_distance = 6.0
                
                # Follow behind leader
                target_position = Point()
                target_position.x = leader_pos.x - following_distance
                target_position.y = leader_pos.y + (self.drone_id - 1) * 2.0  # Offset by ID
                target_position.z = leader_pos.z
            else:
                # No leader, go to home
                target_position = Point(
                    x=self.home_position[0],
                    y=self.home_position[1],
                    z=self.home_position[2]
                )
        
        # Update internal target
        temp_target = Pose()
        temp_target.position = target_position
        self.target_pose = temp_target
        
        # Calculate control command
        control_cmd = self.calculate_position_control()
        
        # Apply collision avoidance
        control_cmd = self.apply_collision_avoidance(control_cmd)
        
        # Yaw control
        if abs(control_cmd.linear.x) > 0.1 or abs(control_cmd.linear.y) > 0.1:
            target_yaw = math.atan2(
                target_position.y - self.current_pose.position.y,
                target_position.x - self.current_pose.position.x
            )
            control_cmd.angular.z = self.calculate_yaw_control(target_yaw)
        
        self.velocity_publisher.publish(control_cmd)

    def calculate_position_control(self):
        """PID position controller"""
        kp = 1.0  # Proportional gain - reduced for stability
        
        error_x = self.target_pose.position.x - self.current_pose.position.x
        error_y = self.target_pose.position.y - self.current_pose.position.y
        error_z = self.target_pose.position.z - self.current_pose.position.z
        
        cmd = Twist()
        cmd.linear.x = np.clip(kp * error_x, -self.max_velocity, self.max_velocity)
        cmd.linear.y = np.clip(kp * error_y, -self.max_velocity, self.max_velocity)
        cmd.linear.z = np.clip(kp * error_z, -self.max_velocity, self.max_velocity)
        
        return cmd

    def apply_collision_avoidance(self, cmd):
        """Apply collision avoidance and formation maintenance"""
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        for drone_id, state in self.other_drones.items():
            # Skip stale data
            if current_time - self.last_communication.get(drone_id, 0) > 3.0:
                continue
                
            # Calculate distance vector
            other_pos = state.pose.position
            current_pos = self.current_pose.position
            
            distance_vector = np.array([
                other_pos.x - current_pos.x,
                other_pos.y - current_pos.y,
                other_pos.z - current_pos.z
            ])
            distance = np.linalg.norm(distance_vector)
            
            # Skip if too close (numerical issues)
            if distance < 0.1:
                continue
            
            # Collision avoidance: minimum 3.5 meters
            if distance < self.safety_distance:
                avoidance_strength = (self.safety_distance - distance) / distance
                avoidance_direction = -distance_vector / distance  # Move away
                
                cmd.linear.x += avoidance_direction[0] * avoidance_strength * 2.0
                cmd.linear.y += avoidance_direction[1] * avoidance_strength * 2.0
                cmd.linear.z += avoidance_direction[2] * avoidance_strength * 1.0
                
                self.get_logger().warn(
                    f"Avoiding collision with drone_{drone_id}: {distance:.2f}m",
                    throttle_duration_sec=2.0
                )
            
            # Formation maintenance: maximum 12 meters
            elif distance > 12.0:
                attraction_strength = min((distance - 12.0) / distance, 0.3)
                attraction_direction = distance_vector / distance  # Move closer
                
                cmd.linear.x += attraction_direction[0] * attraction_strength
                cmd.linear.y += attraction_direction[1] * attraction_strength
                cmd.linear.z += attraction_direction[2] * attraction_strength * 0.5
        
        # Velocity limits
        cmd.linear.x = np.clip(cmd.linear.x, -self.max_velocity, self.max_velocity)
        cmd.linear.y = np.clip(cmd.linear.y, -self.max_velocity, self.max_velocity)
        cmd.linear.z = np.clip(cmd.linear.z, -self.max_velocity, self.max_velocity)
        
        return cmd

    def calculate_yaw_control(self, desired_yaw):
        """Calculate yaw control command"""
        current_orientation = self.current_pose.orientation
        _, _, current_yaw = euler_from_quaternion(
            current_orientation.x, current_orientation.y,
            current_orientation.z, current_orientation.w
        )
        
        yaw_error = desired_yaw - current_yaw
        
        # Normalize angle to [-pi, pi]
        while yaw_error > math.pi:
            yaw_error -= 2 * math.pi
        while yaw_error < -math.pi:
            yaw_error += 2 * math.pi
        
        kp_yaw = 1.0  # Reduced for stability
        return np.clip(kp_yaw * yaw_error, -1.0, 1.0)

    def calculate_distance_to_target(self):
        """Calculate 3D distance to target"""
        current_pos = self.current_pose.position
        target_pos = self.target_pose.position
        return math.sqrt(
            (current_pos.x - target_pos.x)**2 +
            (current_pos.y - target_pos.y)**2 +
            (current_pos.z - target_pos.z)**2
        )

    def check_leadership_status(self):
        """Check for leader timeout and handle re-election"""
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        if (self.role == 'follower' and 
            (current_time - self.last_leader_contact) > self.leader_timeout):
            
            self.get_logger().warn("Leader timeout detected. Starting re-election...")
            
            # Simple election: lowest ID among active drones
            active_drones = set([self.drone_id])
            for drone_id, last_time in self.last_communication.items():
                if (current_time - last_time) < self.leader_timeout:
                    active_drones.add(drone_id)
            
            new_leader_id = min(active_drones)
            
            if new_leader_id == self.drone_id:
                self.promote_to_leader()

    def promote_to_leader(self):
        """Promote this drone to leader role"""
        with self.state_lock:
            if self.role == 'follower':
                self.get_logger().info(f"Drone {self.drone_id} promoted to LEADER")
                self.role = 'leader'
                self.leader_id = self.drone_id
                self.mission_active = True
                # Continue any active mission

    def publish_drone_state(self):
        """Publish current drone state"""
        state_msg = DroneState()
        state_msg.drone_id = self.drone_id
        state_msg.role = self.role
        state_msg.pose = self.current_pose
        state_msg.velocity = self.current_velocity
        state_msg.is_armed = self.is_armed
        state_msg.is_connected = True
        state_msg.battery_level = 100.0  # Simulated
        state_msg.status = "active" if self.is_armed else "standby"
        
        self.state_publisher.publish(state_msg)

    def load_waypoints_from_file(self, filepath):
        """Load waypoints from CSV file"""
        try:
            self.waypoint_list = []
            with open(filepath, 'r') as csvfile:
                reader = csv.DictReader(csvfile)
                for row in reader:
                    waypoint = (float(row['x']), float(row['y']), float(row['z']))
                    self.waypoint_list.append(waypoint)
            
            self.get_logger().info(f"Loaded {len(self.waypoint_list)} waypoints from {filepath}")
            return True
        except Exception as e:
            self.get_logger().error(f"Failed to load waypoints: {str(e)}")
            # Fallback waypoints
            self.waypoint_list = [
                (self.home_position[0], self.home_position[1], self.home_position[2]),
                (self.home_position[0] + 10, self.home_position[1], self.home_position[2]),
                (self.home_position[0] + 10, self.home_position[1] + 10, self.home_position[2]),
                (self.home_position[0], self.home_position[1] + 10, self.home_position[2])
            ]
            return False

    def handle_disarm_request(self, request, response):
        """Handle disarm leader service request"""
        if self.role != 'leader':
            response.success = False
            response.message = f"Drone {self.drone_id} is not the current leader"
            return response
        
        self.get_logger().info(f"Disarm request received for leader drone_{self.drone_id}")
        
        with self.state_lock:
            self.is_armed = False
            self.is_enabled = False
            self.role = 'follower'
            self.mission_active = False
            
            if request.return_to_home:
                self.target_pose.position = Point(
                    x=self.home_position[0],
                    y=self.home_position[1], 
                    z=self.home_position[2]
                )
                self.get_logger().info("Returning to home position")
        
        response.success = True
        response.old_leader_id = self.drone_id
        response.new_leader_id = -1  # Will be determined by election
        response.message = f"Leader drone_{self.drone_id} disarmed successfully"
        
        return response

    def execute_mission_callback(self, goal_handle):
        """Handle mission execution action"""
        if self.role != 'leader':
            goal_handle.abort()
            result = ExecuteMission.Result()
            result.success = False
            result.final_status = "Mission rejected: Not a leader"
            return result
        
        request = goal_handle.request
        self.get_logger().info(f"Mission started: {request.mission_type}")
        
        # Load mission waypoints
        with self.state_lock:
            if request.path_file:
                self.load_waypoints_from_file(request.path_file)
            elif request.waypoints:
                self.waypoint_list = [(wp.x, wp.y, wp.z) for wp in request.waypoints]
            else:
                self.get_logger().warn("No waypoints provided, using default path")
                self.waypoint_list = [
                    (0.0, 0.0, 5.0),
                    (10.0, 0.0, 5.0),
                    (10.0, 10.0, 6.0),
                    (0.0, 10.0, 6.0),
                    (0.0, 0.0, 5.0)
                ]
            
            self.current_waypoint_index = 0
            self.mission_active = True
        
        goal_handle.succeed()
        
        # Monitor mission progress
        start_time = self.get_clock().now()
        feedback_msg = ExecuteMission.Feedback()
        
        while self.mission_active and self.role == 'leader' and rclpy.ok():
            elapsed_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
            
            if request.max_duration > 0 and elapsed_time > request.max_duration:
                self.get_logger().warn("Mission timeout reached")
                self.mission_active = False
                break
            
            # Update feedback
            feedback_msg.current_waypoint = self.current_waypoint_index
            feedback_msg.elapsed_time = elapsed_time
            feedback_msg.leader_pose = self.current_pose
            feedback_msg.distance_to_target = self.calculate_distance_to_target()
            feedback_msg.status_message = f"Moving to waypoint {self.current_waypoint_index + 1}"
            goal_handle.publish_feedback(feedback_msg)
            
            time.sleep(1.0)  # 1 Hz feedback
        
        # Mission completed
        result = ExecuteMission.Result()
        result.success = (self.current_waypoint_index >= len(self.waypoint_list))
        result.total_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
        result.waypoints_completed = self.current_waypoint_index
        result.final_status = "Mission completed" if result.success else "Mission incomplete"
        
        return result

def main(args=None):
    rclpy.init(args=args)
    drone_node = SwarmDrone()
    
    try:
        rclpy.spin(drone_node)
    except KeyboardInterrupt:
        drone_node.get_logger().info("Shutting down drone node...")
    finally:
        drone_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()