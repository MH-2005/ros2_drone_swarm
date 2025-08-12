import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
import math
import numpy as np
import csv
from threading import Lock
import time

from geometry_msgs.msg import Pose, Twist, Point, PoseStamped
from std_msgs.msg import Bool
from swarm_msgs.msg import DroneState
from swarm_msgs.srv import DisarmLeader
from swarm_msgs.action import ExecuteMission

# Simple quaternion to euler conversion
def euler_from_quaternion(quaternion):
    x, y, z, w = quaternion
    yaw = math.atan2(2.0 * (w * z + x * y), 1.0 - 2.0 * (y * y + z * z))
    return 0.0, 0.0, yaw

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
        self.target_pose = Pose()
        self.target_pose.position = Point(x=self.home_position[0], 
                                        y=self.home_position[1], 
                                        z=self.home_position[2])
        self.is_armed = False
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
        self.state_publisher = self.create_publisher(
            DroneState, f'/swarm/state/drone_{self.drone_id}', 10
        )
        
        # Subscribers
        self.pose_subscriber = self.create_subscription(
            PoseStamped, 'pose', self.pose_update_callback, 10
        )
        self.arm_subscriber = self.create_subscription(
            Bool, 'arm', self.arm_command_callback, 10
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
        
        self.get_logger().info(f"Drone {self.drone_id} started as {self.role}")

    def pose_update_callback(self, msg):
        with self.state_lock:
            self.current_pose = msg.pose

    def arm_command_callback(self, msg):
        with self.state_lock:
            if self.is_armed != msg.data:
                self.is_armed = msg.data
                status = "ARMED" if self.is_armed else "DISARMED"
                self.get_logger().info(f"Drone {self.drone_id} {status}")

    def target_update_callback(self, msg):
        with self.state_lock:
            self.target_pose = msg

    def other_drone_update_callback(self, msg, drone_id):
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
        if not self.is_armed:
            # Send zero velocity when disarmed
            self.velocity_publisher.publish(Twist())
            return

        with self.state_lock:
            if self.role == 'leader':
                self.execute_leader_control()
            else:
                self.execute_follower_control()

    def execute_leader_control(self):
        # Mission waypoint following for leader
        if self.mission_active and self.current_waypoint_index < len(self.waypoint_list):
            target_waypoint = self.waypoint_list[self.current_waypoint_index]
            self.target_pose.position.x = target_waypoint[0]
            self.target_pose.position.y = target_waypoint[1]
            self.target_pose.position.z = target_waypoint[2]
            
            # Check if waypoint is reached
            distance_to_waypoint = self.calculate_distance_to_target()
            if distance_to_waypoint < 1.5:
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
        
        # Add yaw control
        if abs(control_cmd.linear.x) > 0.15 or abs(control_cmd.linear.y) > 0.15:
            target_yaw = math.atan2(
                self.target_pose.position.y - self.current_pose.position.y,
                self.target_pose.position.x - self.current_pose.position.x
            )
            control_cmd.angular.z = self.calculate_yaw_control(target_yaw)
        
        self.velocity_publisher.publish(control_cmd)

    def execute_follower_control(self):
        # Find leader position
        if self.leader_id not in self.other_drones:
            # No leader found, hover in place
            self.velocity_publisher.publish(Twist())
            return
        
        leader_state = self.other_drones[self.leader_id]
        
        # Use formation target if available, otherwise default following
        if (self.target_pose.position.x != 0 or 
            self.target_pose.position.y != 0 or 
            self.target_pose.position.z != 0):
            # Formation control active
            target_position = self.target_pose.position
        else:
            # Default following behavior
            leader_pos = leader_state.pose.position
            following_distance = 6.0
            target_position = Point()
            target_position.x = leader_pos.x - following_distance
            target_position.y = leader_pos.y
            target_position.z = leader_pos.z
        
        # Update internal target
        self.target_pose.position = target_position
        
        # Calculate control command
        control_cmd = self.calculate_position_control()
        
        # Apply collision avoidance
        control_cmd = self.apply_collision_avoidance(control_cmd)
        
        # Yaw control
        if abs(control_cmd.linear.x) > 0.15 or abs(control_cmd.linear.y) > 0.15:
            target_yaw = math.atan2(
                target_position.y - self.current_pose.position.y,
                target_position.x - self.current_pose.position.x
            )
            control_cmd.angular.z = self.calculate_yaw_control(target_yaw)
        
        self.velocity_publisher.publish(control_cmd)

    def calculate_position_control(self):
        # PID position controller
        kp = 1.2  # Proportional gain
        
        error_x = self.target_pose.position.x - self.current_pose.position.x
        error_y = self.target_pose.position.y - self.current_pose.position.y
        error_z = self.target_pose.position.z - self.current_pose.position.z
        
        cmd = Twist()
        cmd.linear.x = np.clip(kp * error_x, -self.max_velocity, self.max_velocity)
        cmd.linear.y = np.clip(kp * error_y, -self.max_velocity, self.max_velocity)
        cmd.linear.z = np.clip(kp * error_z, -self.max_velocity, self.max_velocity)
        
        return cmd

    def apply_collision_avoidance(self, cmd):
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
            
            # Collision avoidance: minimum 3 meters
            if 0.2 < distance < 3.0:
                avoidance_strength = (3.0 - distance) / distance
                avoidance_direction = -distance_vector / distance  # Move away
                
                cmd.linear.x += avoidance_direction[0] * avoidance_strength * 1.5
                cmd.linear.y += avoidance_direction[1] * avoidance_strength * 1.5
                cmd.linear.z += avoidance_direction[2] * avoidance_strength * 0.8
                
                self.get_logger().warn(f"Avoiding collision with drone_{drone_id}: {distance:.2f}m")
            
            # Formation maintenance: maximum 10 meters
            elif distance > 10.0:
                attraction_strength = min((distance - 10.0) / distance, 0.4)
                attraction_direction = distance_vector / distance  # Move closer
                
                cmd.linear.x += attraction_direction[0] * attraction_strength * 0.4
                cmd.linear.y += attraction_direction[1] * attraction_strength * 0.4
                cmd.linear.z += attraction_direction[2] * attraction_strength * 0.2
        
        # Velocity limits
        cmd.linear.x = np.clip(cmd.linear.x, -self.max_velocity, self.max_velocity)
        cmd.linear.y = np.clip(cmd.linear.y, -self.max_velocity, self.max_velocity)
        cmd.linear.z = np.clip(cmd.linear.z, -self.max_velocity, self.max_velocity)
        
        return cmd

    def calculate_yaw_control(self, desired_yaw):
        current_orientation = self.current_pose.orientation
        _, _, current_yaw = euler_from_quaternion([
            current_orientation.x, current_orientation.y,
            current_orientation.z, current_orientation.w
        ])
        
        yaw_error = desired_yaw - current_yaw
        
        # Normalize angle to [-pi, pi]
        while yaw_error > math.pi:
            yaw_error -= 2 * math.pi
        while yaw_error < -math.pi:
            yaw_error += 2 * math.pi
        
        kp_yaw = 1.5
        return np.clip(kp_yaw * yaw_error, -1.2, 1.2)

    def calculate_distance_to_target(self):
        current_pos = self.current_pose.position
        target_pos = self.target_pose.position
        return math.sqrt(
            (current_pos.x - target_pos.x)**2 +
            (current_pos.y - target_pos.y)**2 +
            (current_pos.z - target_pos.z)**2
        )

    def check_leadership_status(self):
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        if (self.role == 'follower' and 
            (current_time - self.last_leader_contact) > self.leader_timeout):
            
            self.get_logger().warn(f"Leader timeout detected. Starting re-election...")
            
            # Simple election: lowest ID among active drones
            active_drones = set([self.drone_id])
            for drone_id, last_time in self.last_communication.items():
                if (current_time - last_time) < self.leader_timeout:
                    active_drones.add(drone_id)
            
            new_leader_id = min(active_drones)
            
            if new_leader_id == self.drone_id:
                self.promote_to_leader()

    def promote_to_leader(self):
        with self.state_lock:
            if self.role == 'follower':
                self.get_logger().info(f"Drone {self.drone_id} promoted to LEADER")
                self.role = 'leader'
                self.leader_id = self.drone_id
                self.mission_active = True
                # Continue any active mission

    def publish_drone_state(self):
        state_msg = DroneState()
        state_msg.drone_id = self.drone_id
        state_msg.role = self.role
        state_msg.pose = self.current_pose
        state_msg.is_armed = self.is_armed
        state_msg.is_connected = True
        state_msg.battery_level = 100.0  # Simulated
        state_msg.status = "active" if self.is_armed else "standby"
        
        self.state_publisher.publish(state_msg)

    def load_waypoints_from_file(self, filepath):
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
        if self.role != 'leader':
            response.success = False
            response.message = f"Drone {self.drone_id} is not the current leader"
            return response
        
        self.get_logger().info(f"Disarm request received for leader drone_{self.drone_id}")
        
        with self.state_lock:
            self.is_armed = False
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
            
            self.current_waypoint_index = 0
            self.mission_active = True
        
        goal_handle.succeed()
        
        # Monitor mission progress
        start_time = self.get_clock().now()
        feedback_msg = ExecuteMission.Feedback()
        
        while self.mission_active and self.role == 'leader':
            elapsed_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
            
            if request.max_duration > 0 and elapsed_time > request.max_duration:
                self.get_logger().warn("Mission timeout reached")
                self.mission_active = False
                break
            
            # Update feedback
            feedback_msg.current_waypoint = self.current_waypoint_index
            feedback_msg.elapsed_time = elapsed_time
            feedback_msg.leader_pose = self.current_pose
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