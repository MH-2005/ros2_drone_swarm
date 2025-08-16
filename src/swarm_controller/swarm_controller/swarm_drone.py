import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.executors import ExternalShutdownException
import math
import numpy as np
import csv
from threading import Lock
import time
import signal
import sys

from geometry_msgs.msg import Pose, Twist, Point
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool
from swarm_msgs.msg import DroneState
from swarm_msgs.srv import DisarmLeader
from swarm_msgs.action import ExecuteMission

def euler_from_quaternion(x, y, z, w):
    """Convert quaternion to euler angles (roll, pitch, yaw)"""
    sinr_cosp = 2 * (w * x + y * z)
    cosr_cosp = 1 - 2 * (x * x + y * y)
    roll = math.atan2(sinr_cosp, cosr_cosp)

    sinp = 2 * (w * y - z * x)
    if abs(sinp) >= 1:
        pitch = math.copysign(math.pi / 2, sinp)
    else:
        pitch = math.asin(sinp)

    siny_cosp = 2 * (w * z + x * y)
    cosy_cosp = 1 - 2 * (y * y + z * z)
    yaw = math.atan2(siny_cosp, cosy_cosp)

    return roll, pitch, yaw

class SwarmDrone(Node):
    def __init__(self):
        super().__init__('swarm_drone_node')
        
        # Graceful shutdown setup
        self._shutdown_requested = False
        signal.signal(signal.SIGINT, self._signal_handler)
        signal.signal(signal.SIGTERM, self._signal_handler)
        
        # Parameter declarations
        self.declare_parameter('drone_id', 0)
        self.declare_parameter('role', 'follower')
        self.declare_parameter('max_velocity', 2.0)
        self.declare_parameter('safety_distance', 3.5)
        self.declare_parameter('home_position', [0.0, 0.0, 5.0])
        
        try:
            self.declare_parameter('use_sim_time', True)
        except Exception:
            pass
        
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
        
        # Control gains (reduced for stability)
        self.kp_linear = 0.8
        self.kd_linear = 0.1
        self.kp_angular = 0.6
        self.previous_error = [0.0, 0.0, 0.0]
        
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
        try:
            self.mission_action_server = ActionServer(
                self, ExecuteMission, '/execute_mission', 
                self.execute_mission_callback
            )
            self.disarm_service = self.create_service(
                DisarmLeader, '/disarm_leader', 
                self.handle_disarm_request
            )
        except Exception as e:
            self.get_logger().warn(f"Could not create action server or service: {e}")
        
        # Timers
        self.control_timer = self.create_timer(0.1, self.control_loop)  # 10 Hz
        self.state_timer = self.create_timer(0.2, self.publish_drone_state)  # 5 Hz
        self.leadership_timer = self.create_timer(2.0, self.check_leadership_status)
        self.enable_timer = self.create_timer(0.5, self.publish_enable_status)
        
        # Initialize as armed and enabled for leader
        if self.role == 'leader':
            self.is_armed = True
            self.is_enabled = True
            
        self.get_logger().info(f"Drone {self.drone_id} started as {self.role}")

    def _signal_handler(self, signum, frame):
        """Handle shutdown signals gracefully"""
        self.get_logger().info(f"Drone {self.drone_id} received shutdown signal {signum}")
        self._shutdown_requested = True
        
        # Stop all movement
        with self.state_lock:
            self.is_armed = False
            self.is_enabled = False
            self.mission_active = False
        
        # Send zero velocity
        zero_cmd = Twist()
        try:
            self.velocity_publisher.publish(zero_cmd)
            enable_msg = Bool()
            enable_msg.data = False
            self.enable_publisher.publish(enable_msg)
        except Exception:
            pass

    def odometry_callback(self, msg):
        """Handle odometry messages from Gazebo"""
        if self._shutdown_requested:
            return
        with self.state_lock:
            self.current_pose = msg.pose.pose
            self.current_velocity = msg.twist.twist

    def arm_command_callback(self, msg):
        """Handle arm/disarm commands"""
        if self._shutdown_requested:
            return
        with self.state_lock:
            if self.is_armed != msg.data:
                self.is_armed = msg.data
                self.is_enabled = msg.data
                status = "ARMED" if self.is_armed else "DISARMED"
                self.get_logger().info(f"Drone {self.drone_id} {status}")

    def target_update_callback(self, msg):
        """Handle new target pose from formation controller"""
        if self._shutdown_requested:
            return
        with self.state_lock:
            self.target_pose = msg
            
    def publish_enable_status(self):
        """Publish enable status to Gazebo multicopter plugin"""
        if self._shutdown_requested:
            return
        try:
            enable_msg = Bool()
            enable_msg.data = self.is_enabled and not self._shutdown_requested
            self.enable_publisher.publish(enable_msg)
        except Exception:
            pass

    def other_drone_update_callback(self, msg, drone_id):
        """Handle updates from other drones"""
        if self._shutdown_requested:
            return
        current_time = self.get_clock().now().nanoseconds / 1e9
        with self.state_lock:
            self.other_drones[drone_id] = msg
            self.last_communication[drone_id] = current_time
            
            if hasattr(msg, 'role') and msg.role == 'leader':
                if self.leader_id != drone_id:
                    self.get_logger().info(f"New leader detected: drone_{drone_id}")
                self.leader_id = drone_id
                self.last_leader_contact = current_time

    def control_loop(self):
        """Main control loop - simplified PID controller"""
        if self._shutdown_requested or not self.is_armed or not self.is_enabled:
            try:
                self.velocity_publisher.publish(Twist())
            except Exception:
                pass
            return

        try:
            with self.state_lock:
                # Get current position
                current_pos = self.current_pose.position
                target_pos = self.target_pose.position
                
                # Handle mission waypoints for leader
                if self.role == 'leader' and self.mission_active:
                    self.update_leader_mission_target()
                elif self.role == 'follower':
                    self.update_follower_target()
                
                # Calculate position error
                error = [
                    target_pos.x - current_pos.x,
                    target_pos.y - current_pos.y, 
                    target_pos.z - current_pos.z
                ]
                
                # PD Controller
                derivative = [error[i] - self.previous_error[i] for i in range(3)]
                self.previous_error = error.copy()
                
                # Calculate control commands
                cmd = Twist()
                cmd.linear.x = self.kp_linear * error[0] + self.kd_linear * derivative[0]
                cmd.linear.y = self.kp_linear * error[1] + self.kd_linear * derivative[1] 
                cmd.linear.z = self.kp_linear * error[2] + self.kd_linear * derivative[2]
                
                # Velocity limits
                cmd.linear.x = np.clip(cmd.linear.x, -self.max_velocity, self.max_velocity)
                cmd.linear.y = np.clip(cmd.linear.y, -self.max_velocity, self.max_velocity)
                cmd.linear.z = np.clip(cmd.linear.z, -self.max_velocity, self.max_velocity)
                
                # Apply collision avoidance
                cmd = self.apply_safety_constraints(cmd)
                
                # Yaw control towards target
                if abs(error[0]) > 0.5 or abs(error[1]) > 0.5:
                    target_yaw = math.atan2(error[1], error[0])
                    current_yaw = self.get_current_yaw()
                    yaw_error = target_yaw - current_yaw
                    
                    # Normalize yaw error
                    while yaw_error > math.pi:
                        yaw_error -= 2 * math.pi
                    while yaw_error < -math.pi:
                        yaw_error += 2 * math.pi
                    
                    cmd.angular.z = np.clip(self.kp_angular * yaw_error, -1.0, 1.0)
                
                # Publish velocity command
                self.velocity_publisher.publish(cmd)
        except Exception as e:
            self.get_logger().warn(f"Control loop error: {e}")

    def update_leader_mission_target(self):
        """Update target for leader following waypoints"""
        if self.current_waypoint_index < len(self.waypoint_list):
            waypoint = self.waypoint_list[self.current_waypoint_index]
            self.target_pose.position.x = waypoint[0]
            self.target_pose.position.y = waypoint[1]
            self.target_pose.position.z = waypoint[2]
            
            # Check if reached waypoint
            distance = math.sqrt(
                (self.current_pose.position.x - waypoint[0])**2 +
                (self.current_pose.position.y - waypoint[1])**2 +
                (self.current_pose.position.z - waypoint[2])**2
            )
            
            if distance < 2.5:  # Waypoint reached
                self.current_waypoint_index += 1
                if self.current_waypoint_index < len(self.waypoint_list):
                    self.get_logger().info(f"Leader reached waypoint {self.current_waypoint_index}")
                else:
                    self.get_logger().info("Leader mission completed")
                    self.mission_active = False

    def update_follower_target(self):
        """Update target for follower drones"""
        # Use formation target if available
        if (self.target_pose.position.x == 0 and 
            self.target_pose.position.y == 0 and 
            self.target_pose.position.z == 0):
            
            # No formation target, follow leader or go home
            if self.leader_id in self.other_drones:
                leader_state = self.other_drones[self.leader_id]
                leader_pos = leader_state.pose.position
                
                # Follow behind and to the side of leader
                offset_distance = 5.0
                side_offset = (self.drone_id - 1) * 3.0  # Different side positions
                
                self.target_pose.position.x = leader_pos.x - offset_distance
                self.target_pose.position.y = leader_pos.y + side_offset
                self.target_pose.position.z = leader_pos.z
            else:
                # No leader found, return to home
                self.target_pose.position.x = self.home_position[0]
                self.target_pose.position.y = self.home_position[1]
                self.target_pose.position.z = self.home_position[2]

    def apply_safety_constraints(self, cmd):
        """Apply collision avoidance and safety limits"""
        if self._shutdown_requested:
            return Twist()
            
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        for drone_id, state in self.other_drones.items():
            # Skip old data
            if current_time - self.last_communication.get(drone_id, 0) > 5.0:
                continue
                
            other_pos = state.pose.position
            current_pos = self.current_pose.position
            
            # Calculate distance
            distance = math.sqrt(
                (other_pos.x - current_pos.x)**2 +
                (other_pos.y - current_pos.y)**2 +
                (other_pos.z - current_pos.z)**2
            )
            
            # Collision avoidance
            if distance < self.safety_distance and distance > 0.1:
                # Calculate avoidance vector
                avoid_x = (current_pos.x - other_pos.x) / distance
                avoid_y = (current_pos.y - other_pos.y) / distance
                avoid_z = (current_pos.z - other_pos.z) / distance
                
                # Apply avoidance force
                avoidance_strength = (self.safety_distance - distance) / self.safety_distance
                cmd.linear.x += avoid_x * avoidance_strength * 1.5
                cmd.linear.y += avoid_y * avoidance_strength * 1.5
                cmd.linear.z += avoid_z * avoidance_strength * 0.8
        
        # Final velocity limits
        cmd.linear.x = np.clip(cmd.linear.x, -self.max_velocity, self.max_velocity)
        cmd.linear.y = np.clip(cmd.linear.y, -self.max_velocity, self.max_velocity)
        cmd.linear.z = np.clip(cmd.linear.z, -self.max_velocity, self.max_velocity)
        
        return cmd

    def get_current_yaw(self):
        """Get current yaw angle from quaternion"""
        q = self.current_pose.orientation
        _, _, yaw = euler_from_quaternion(q.x, q.y, q.z, q.w)
        return yaw

    def check_leadership_status(self):
        """Check for leader timeout and handle re-election"""
        if self._shutdown_requested:
            return
            
        current_time = self.get_clock().now().nanoseconds / 1e9
        
        if (self.role == 'follower' and self.is_armed and
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
                self.is_armed = True
                self.is_enabled = True
                self.mission_active = True if self.waypoint_list else False

    def publish_drone_state(self):
        """Publish current drone state"""
        if self._shutdown_requested:
            return
        try:
            state_msg = DroneState()
            state_msg.drone_id = self.drone_id
            state_msg.role = self.role
            state_msg.pose = self.current_pose
            state_msg.velocity = self.current_velocity
            state_msg.is_armed = self.is_armed and not self._shutdown_requested
            state_msg.is_connected = True
            state_msg.battery_level = 100.0
            state_msg.status = "active" if self.is_armed else "standby"
            
            self.state_publisher.publish(state_msg)
        except Exception:
            pass

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
            # Default waypoints
            self.waypoint_list = [
                (0.0, 0.0, 5.0),
                (10.0, 0.0, 6.0),
                (10.0, 10.0, 7.0),
                (0.0, 10.0, 6.0),
                (0.0, 0.0, 5.0)
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
                self.target_pose.position.x = self.home_position[0]
                self.target_pose.position.y = self.home_position[1]
                self.target_pose.position.z = self.home_position[2]
        
        response.success = True
        response.old_leader_id = self.drone_id
        response.new_leader_id = -1
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
                # Default circular pattern
                self.waypoint_list = [
                    (0.0, 0.0, 5.0),
                    (8.0, 0.0, 5.5),
                    (8.0, 8.0, 6.0),
                    (0.0, 8.0, 6.0),
                    (0.0, 0.0, 5.0)
                ]
            
            self.current_waypoint_index = 0
            self.mission_active = True
        
        goal_handle.succeed()
        
        # Monitor mission progress
        start_time = self.get_clock().now()
        feedback_msg = ExecuteMission.Feedback()
        
        while (self.mission_active and self.role == 'leader' and 
               not self._shutdown_requested and rclpy.ok()):
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
            feedback_msg.status_message = f"Moving to waypoint {self.current_waypoint_index + 1}/{len(self.waypoint_list)}"
            
            try:
                goal_handle.publish_feedback(feedback_msg)
            except Exception:
                break
            
            time.sleep(2.0)  # 0.5 Hz feedback
        
        # Mission completed
        result = ExecuteMission.Result()
        result.success = (self.current_waypoint_index >= len(self.waypoint_list))
        result.total_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
        result.waypoints_completed = self.current_waypoint_index
        result.final_status = "Mission completed" if result.success else "Mission incomplete"
        
        return result

    def calculate_distance_to_target(self):
        """Calculate 3D distance to current target"""
        current_pos = self.current_pose.position
        target_pos = self.target_pose.position
        return math.sqrt(
            (current_pos.x - target_pos.x)**2 +
            (current_pos.y - target_pos.y)**2 +
            (current_pos.z - target_pos.z)**2
        )

def main(args=None):
    if not rclpy.ok():
        rclpy.init(args=args)
    
    drone_node = None
    
    try:
        drone_node = SwarmDrone()
        rclpy.spin(drone_node)
    except (KeyboardInterrupt, ExternalShutdownException, SystemExit):
        pass
    except Exception as e:
        if drone_node:
            drone_node.get_logger().error(f"Unexpected error: {e}")
    finally:
        # Graceful cleanup
        if drone_node:
            try:
                drone_node.get_logger().info(f"Drone {drone_node.drone_id} shutting down gracefully...")
                
                # Stop all movement
                zero_cmd = Twist()
                enable_msg = Bool()
                enable_msg.data = False
                
                try:
                    drone_node.velocity_publisher.publish(zero_cmd)
                    drone_node.enable_publisher.publish(enable_msg)
                except Exception:
                    pass
                
                # Destroy node properly
                drone_node.destroy_node()
            except Exception:
                pass
        
        # Only shutdown rclpy if we're not already shutting down
        try:
            if rclpy.ok():
                rclpy.try_shutdown()
        except Exception:
            pass

if __name__ == '__main__':
    main()