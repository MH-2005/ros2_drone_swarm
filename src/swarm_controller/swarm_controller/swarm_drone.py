import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
import math
import numpy as np
import csv
from threading import Lock
import time

from geometry_msgs.msg import Pose, Twist, Point
from std_msgs.msg import Bool

from swarm_msgs.msg import DroneState
from swarm_msgs.srv import DisarmLeader
from swarm_msgs.action import ExecuteMission

try:
    from tf_transformations import euler_from_quaternion
except ImportError:
    # Fallback for ROS2 environments without tf_transformations
    def euler_from_quaternion(quaternion):
        import math
        x, y, z, w = quaternion
        # Simple yaw extraction
        yaw = math.atan2(2.0 * (w * z + x * y), 1.0 - 2.0 * (y * y + z * z))
        return 0.0, 0.0, yaw

class SwarmDrone(Node):
    def __init__(self):
        super().__init__('swarm_drone_node')
        
        # --- Parameters ---
        self.declare_parameter('drone_id', 0)
        self.declare_parameter('role', 'follower')
        self.declare_parameter('max_velocity', 2.0)
        self.declare_parameter('safety_distance', 3.0)
        self.declare_parameter('home_position', [0.0, 0.0, 5.0])
        
        self.drone_id = self.get_parameter('drone_id').value
        self.role = self.get_parameter('role').value
        self.max_vel = self.get_parameter('max_velocity').value
        self.safety_distance = self.get_parameter('safety_distance').value
        self.home_pos = self.get_parameter('home_position').value
        
        # --- State Variables ---
        self.lock = Lock()
        self.current_pose = Pose()
        self.target_pose = Pose(position=Point(x=self.home_pos[0], y=self.home_pos[1], z=self.home_pos[2]))
        self.is_armed = False
        self.other_drones = {}
        self.last_update_time = {}
        self.mission_active = False
        self.waypoints = []
        self.current_waypoint_idx = 0
        self.leader_id = 0
        self.leader_last_seen = self.get_clock().now().nanoseconds / 1e9
        self.leadership_timeout = 5.0

        # --- Publishers ---
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.state_pub = self.create_publisher(DroneState, f'/swarm/state/drone_{self.drone_id}', 10)

        # --- Subscribers ---
        self.pose_sub = self.create_subscription(Pose, 'pose', self.pose_callback, 10)
        self.arm_sub = self.create_subscription(Bool, 'arm', self.arm_callback, 10)
        
        for i in range(4):
            if i != self.drone_id:
                self.create_subscription(
                    DroneState, 
                    f'/swarm/state/drone_{i}',
                    lambda msg, id=i: self.other_drone_state_callback(msg, id), 
                    10
                )
        
        self.target_pose_sub = self.create_subscription(
            Pose, 
            f'/swarm/target_pose/drone_{self.drone_id}', 
            self.target_pose_callback, 
            10
        )

        # --- Services and Actions ---
        self.mission_action_server = ActionServer(self, ExecuteMission, '/execute_mission', self.execute_mission_callback)
        self.disarm_service = self.create_service(DisarmLeader, '/disarm_leader', self.disarm_leader_callback)

        # --- Timers ---
        self.control_timer = self.create_timer(0.1, self.control_loop)
        self.state_timer = self.create_timer(0.2, self.publish_state)
        self.leader_check_timer = self.create_timer(1.0, self.check_leader_status)

        self.get_logger().info(f"Drone {self.drone_id} initialized as {self.role}")

    def pose_callback(self, msg):
        with self.lock:
            self.current_pose = msg

    def arm_callback(self, msg):
        with self.lock:
            if self.is_armed != msg.data:
                self.is_armed = msg.data
                self.get_logger().info(f"Drone {self.drone_id} {'ARMED' if self.is_armed else 'DISARMED'}")

    def target_pose_callback(self, msg):
        with self.lock:
            self.target_pose = msg

    def other_drone_state_callback(self, msg, drone_id):
        current_time = self.get_clock().now().nanoseconds / 1e9
        with self.lock:
            self.other_drones[drone_id] = msg
            self.last_update_time[drone_id] = current_time
            if msg.role == 'leader':
                if self.leader_id != drone_id:
                    self.get_logger().info(f"Detected new leader: {drone_id}")
                self.leader_id = drone_id
                self.leader_last_seen = current_time

    def control_loop(self):
        if not self.is_armed:
            self.cmd_vel_pub.publish(Twist()) # Publish zero velocity if not armed
            return

        with self.lock:
            if self.role == 'leader':
                self.leader_control_logic()
            else: # Follower
                self.follower_control_logic()
    
    def leader_control_logic(self):
        if self.mission_active and self.current_waypoint_idx < len(self.waypoints):
            target_wp = self.waypoints[self.current_waypoint_idx]
            self.target_pose.position.x = target_wp[0]
            self.target_pose.position.y = target_wp[1]
            self.target_pose.position.z = target_wp[2]
            
            distance_to_wp = self.calculate_distance_to_point(self.target_pose.position)
            if distance_to_wp < 1.0:
                self.current_waypoint_idx += 1
                if self.current_waypoint_idx < len(self.waypoints):
                    self.get_logger().info(f"Moving to waypoint {self.current_waypoint_idx}")
                else:
                    self.get_logger().info("Mission complete")
                    self.mission_active = False

        kp = 1.0
        error_x = self.target_pose.position.x - self.current_pose.position.x
        error_y = self.target_pose.position.y - self.current_pose.position.y
        error_z = self.target_pose.position.z - self.current_pose.position.z

        cmd = Twist()
        cmd.linear.x = np.clip(kp * error_x, -self.max_vel, self.max_vel)
        cmd.linear.y = np.clip(kp * error_y, -self.max_vel, self.max_vel)
        cmd.linear.z = np.clip(kp * error_z, -self.max_vel, self.max_vel)
        
        # Yaw control only if moving horizontally
        if abs(cmd.linear.x) > 0.1 or abs(cmd.linear.y) > 0.1:
            desired_yaw = math.atan2(error_y, error_x)
            cmd.angular.z = self.yaw_controller(desired_yaw)

        self.cmd_vel_pub.publish(cmd)

    def follower_control_logic(self):
        """
        Control logic for follower drones - follows the leader while maintaining formation
        """
        if self.leader_id not in self.other_drones:
            self.get_logger().warn(f"Leader {self.leader_id} not found in other_drones")
            # Hover in place if no leader
            cmd = Twist()
            self.cmd_vel_pub.publish(cmd)
            return
        
        leader_state = self.other_drones[self.leader_id]
        
        # Use target_pose set by formation controller if available
        # Otherwise maintain default following distance
        if hasattr(self, 'target_pose') and self.target_pose.position.x != 0:
            target_pos = self.target_pose.position
        else:
            # Default: stay behind leader
            leader_pos = leader_state.pose.position
            offset_distance = 5.0
            target_pos = Point()
            target_pos.x = leader_pos.x - offset_distance
            target_pos.y = leader_pos.y
            target_pos.z = leader_pos.z
        
        # Calculate control commands to reach target
        kp = 1.0  # Proportional gain
        error_x = target_pos.x - self.current_pose.position.x
        error_y = target_pos.y - self.current_pose.position.y
        error_z = target_pos.z - self.current_pose.position.z

        cmd = Twist()
        cmd.linear.x = np.clip(kp * error_x, -self.max_vel, self.max_vel)
        cmd.linear.y = np.clip(kp * error_y, -self.max_vel, self.max_vel)
        cmd.linear.z = np.clip(kp * error_z, -self.max_vel, self.max_vel)
        
        # Apply collision avoidance
        cmd = self.apply_collision_avoidance(cmd)
        
        # Yaw control - face direction of movement
        if abs(cmd.linear.x) > 0.1 or abs(cmd.linear.y) > 0.1:
            desired_yaw = math.atan2(error_y, error_x)
            cmd.angular.z = self.yaw_controller(desired_yaw)
        
        self.cmd_vel_pub.publish(cmd)

    def apply_collision_avoidance(self, cmd):
        current_time = self.get_clock().now().nanoseconds / 1e9
        for drone_id, state in self.other_drones.items():
            if current_time - self.last_update_time.get(drone_id, 0) > 2.0:
                continue 
            
            dist_vec = np.array([state.pose.position.x - self.current_pose.position.x,
                                 state.pose.position.y - self.current_pose.position.y,
                                 state.pose.position.z - self.current_pose.position.z])
            distance = np.linalg.norm(dist_vec)

            if 0.1 < distance < self.safety_distance:
                repulsion_strength = (self.safety_distance - distance) / distance
                repulsion_vec = -dist_vec / distance
                
                cmd.linear.x += repulsion_vec[0] * repulsion_strength * 0.5
                cmd.linear.y += repulsion_vec[1] * repulsion_strength * 0.5
                cmd.linear.z += repulsion_vec[2] * repulsion_strength * 0.3
        return cmd

    def yaw_controller(self, desired_yaw):
        current_q = self.current_pose.orientation
        _, _, current_yaw = euler_from_quaternion([current_q.x, current_q.y, current_q.z, current_q.w])
        
        yaw_error = desired_yaw - current_yaw
        if yaw_error > math.pi:
            yaw_error -= 2 * math.pi
        elif yaw_error < -math.pi:
            yaw_error += 2 * math.pi
            
        kp_yaw = 1.0
        return np.clip(kp_yaw * yaw_error, -1.0, 1.0)
        
    def check_leader_status(self):
        current_time = self.get_clock().now().nanoseconds / 1e9
        if self.role == 'follower' and (current_time - self.leader_last_seen) > self.leadership_timeout:
            self.get_logger().warn(f"Leader (ID: {self.leader_id}) is lost. Starting re-election.")
            
            potential_leader_id = self.drone_id
            active_drones = {id: state for id, state in self.other_drones.items() if current_time - self.last_update_time.get(id, 0) < self.leadership_timeout}

            for id in active_drones:
                if id < potential_leader_id:
                    potential_leader_id = id
            
            if potential_leader_id == self.drone_id:
                self.promote_to_leader()

    def promote_to_leader(self):
        with self.lock:
            if self.role == 'follower':
                self.get_logger().info(f"PROMOTING Drone {self.drone_id} to LEADER.")
                self.role = 'leader'
                self.leader_id = self.drone_id
                self.mission_active = True 

    def publish_state(self):
        state = DroneState()
        state.drone_id = self.drone_id
        state.role = self.role
        state.pose = self.current_pose
        state.is_armed = self.is_armed
        self.state_pub.publish(state)
        
    def calculate_distance_to_point(self, point):
        pos = self.current_pose.position
        return math.sqrt((pos.x - point.x)**2 + (pos.y - point.y)**2 + (pos.z - point.z)**2)

    def load_waypoints_from_csv(self, filepath):
        try:
            self.waypoints = []
            with open(filepath, 'r') as f:
                reader = csv.DictReader(f)
                for row in reader:
                    self.waypoints.append((float(row['x']), float(row['y']), float(row['z'])))
            self.get_logger().info(f"Loaded {len(self.waypoints)} waypoints from {filepath}")
        except Exception as e:
            self.get_logger().error(f"Failed to load waypoints: {e}. Creating default mission.")
            self.waypoints = [(self.home_pos[0], self.home_pos[1], self.home_pos[2])]

    def disarm_leader_callback(self, request, response):
        if self.role != 'leader':
            response.success = False
            response.message = f"Request failed: Drone {self.drone_id} is not the leader."
            return response
        
        self.get_logger().info(f"Leader (ID: {self.drone_id}) has been disarmed by request.")
        self.is_armed = False
        self.role = 'follower' 
        self.mission_active = False

        if request.return_to_home:
            self.target_pose.position = Point(x=self.home_pos[0], y=self.home_pos[1], z=self.home_pos[2])

        response.success = True
        response.old_leader_id = self.drone_id
        response.new_leader_id = -1 
        response.message = f"Leader {self.drone_id} disarmed and is returning home."
        return response

    def execute_mission_callback(self, goal_handle):
        if self.role != 'leader':
            self.get_logger().error("Mission request rejected: This drone is not the leader.")
            goal_handle.abort()
            return ExecuteMission.Result(success=False, final_status="Not a leader")

        request = goal_handle.request
        self.get_logger().info(f"Executing mission type: {request.mission_type}")

        with self.lock:
            if request.path_file:
                self.load_waypoints_from_csv(request.path_file)
            elif request.waypoints:
                self.waypoints = [(wp.x, wp.y, wp.z) for wp in request.waypoints]
            else:
                self.get_logger().warn("No waypoints provided. Staying at home position.")
                self.waypoints = [(self.home_pos[0], self.home_pos[1], self.home_pos[2])]
            
            self.current_waypoint_idx = 0
            self.mission_active = True
        
        goal_handle.succeed()
        
        start_time = self.get_clock().now()
        feedback_msg = ExecuteMission.Feedback()

        while self.mission_active:
            if self.role != 'leader':
                self.get_logger().warn("Mission aborted: Lost leadership role.")
                goal_handle.abort()
                return ExecuteMission.Result(success=False, final_status="Lost leadership")
            
            elapsed_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
            if request.max_duration > 0 and elapsed_time > request.max_duration:
                self.get_logger().warn("Mission timeout reached.")
                self.mission_active = False
                break
            
            feedback_msg.current_waypoint = self.current_waypoint_idx
            feedback_msg.elapsed_time = elapsed_time
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1.0) 

        result = ExecuteMission.Result()
        result.success = (self.current_waypoint_idx >= len(self.waypoints))
        result.total_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
        result.waypoints_completed = self.current_waypoint_idx
        result.final_status = "Mission completed" if result.success else "Mission failed or timed out"
        goal_handle.succeed()
        return result

# ... (main function remains the same) ...

def main(args=None):
    rclpy.init(args=args)
    drone_node = SwarmDrone()
    try:
        rclpy.spin(drone_node)
    except KeyboardInterrupt:
        pass
    finally:
        drone_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()