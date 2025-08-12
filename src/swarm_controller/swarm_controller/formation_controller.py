import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
import math
import time
import numpy as np
from threading import Lock

from geometry_msgs.msg import Pose, Point
from swarm_msgs.msg import DroneState
from swarm_msgs.srv import ChangeFormation

class FormationController(Node):
    def __init__(self):
        super().__init__('formation_controller')
        
        # Parameters
        self.declare_parameter('num_drones', 4)
        self.declare_parameter('formation_timeout', 120.0)
        self.declare_parameter('position_tolerance', 1.2)
        self.declare_parameter('use_sim_time', True)

        self.num_drones = self.get_parameter('num_drones').value
        self.formation_timeout = self.get_parameter('formation_timeout').value
        self.tolerance = self.get_parameter('position_tolerance').value
        self.use_sim_time = self.get_parameter('use_sim_time').value

        # State management
        self.state_lock = Lock()
        self.drone_states = {}
        self.target_poses = {}
        self.formation_status = "idle"

        # Publishers for target poses
        self.target_publishers = {}
        for i in range(self.num_drones):
            self.target_publishers[i] = self.create_publisher(
                Pose, f'/swarm/target_pose/drone_{i}', 10
            )

        # Subscribers for drone states
        for i in range(self.num_drones):
            self.create_subscription(
                DroneState, f'/swarm/state/drone_{i}', 
                self.drone_state_callback, 10
            )

        # Formation service
        self.formation_service = self.create_service(
            ChangeFormation, '/change_formation', 
            self.handle_formation_request
        )
        
        self.get_logger().info("Formation Controller initialized and ready")

    def drone_state_callback(self, msg):
        with self.state_lock:
            self.drone_states[msg.drone_id] = msg

    def handle_formation_request(self, request, response):
        self.get_logger().info(
            f"Formation request: {request.formation_type} "
            f"(size: {request.size}, orientation: {request.orientation})"
        )

        current_leader = self.find_current_leader()
        if not current_leader:
            response.success = False
            response.message = "No leader found in swarm"
            return response

        # Calculate formation positions
        self.compute_formation_targets(request, current_leader)
        
        # Send targets to all drones
        for drone_id, target_pose in self.target_poses.items():
            if drone_id in self.target_publishers:
                self.target_publishers[drone_id].publish(target_pose)

        # Wait for formation completion
        return self.monitor_formation_execution(response)

    def find_current_leader(self):
        with self.state_lock:
            for state in self.drone_states.values():
                if hasattr(state, 'role') and state.role == 'leader':
                    return state
            # Fallback: return drone_0 if no explicit leader
            return self.drone_states.get(0, None)

    def compute_formation_targets(self, request, leader_state):
        with self.state_lock:
            self.target_poses.clear()
            
            # Formation center calculation
            center_pos = Point()
            center_pos.x = leader_state.pose.position.x + request.move_x
            center_pos.y = leader_state.pose.position.y + request.move_y
            center_pos.z = (request.altitude if request.altitude > 0 
                           else leader_state.pose.position.z + request.move_z)

            # Leader position (center of formation)
            leader_pose = Pose()
            leader_pose.position = center_pos
            self.target_poses[leader_state.drone_id] = leader_pose

            # Calculate formation offsets
            formation_offsets = self.get_formation_pattern(request.formation_type, request.size)
            
            # Apply rotation if requested
            if any([request.rotate_x, request.rotate_y, request.rotate_z]):
                formation_offsets = self.apply_rotation_transform(
                    formation_offsets, request.rotate_x, request.rotate_y, request.rotate_z
                )
            
            # Apply orientation transformation
            if request.orientation == 'vertical':
                formation_offsets = self.apply_vertical_orientation(formation_offsets)

            # Assign positions to followers
            follower_ids = sorted([i for i in range(self.num_drones) 
                                 if i != leader_state.drone_id])
            
            for idx, follower_id in enumerate(follower_ids):
                if idx < len(formation_offsets):
                    offset = formation_offsets[idx]
                    follower_pose = Pose()
                    follower_pose.position.x = center_pos.x + offset.x
                    follower_pose.position.y = center_pos.y + offset.y
                    follower_pose.position.z = center_pos.z + offset.z
                    self.target_poses[follower_id] = follower_pose

    def get_formation_pattern(self, formation_type, size):
        patterns = []
        
        if formation_type == 'line':
            # Horizontal line formation
            patterns = [
                Point(x=-size, y=0.0, z=0.0),
                Point(x=-2*size, y=0.0, z=0.0),
                Point(x=-3*size, y=0.0, z=0.0)
            ]
        elif formation_type == 'triangle':
            # Equilateral triangle
            h = size * math.sqrt(3) / 2
            patterns = [
                Point(x=-h, y=-size/2, z=0.0),
                Point(x=-h, y=size/2, z=0.0),
                Point(x=-h*1.5, y=0.0, z=0.0)
            ]
        elif formation_type == 'square':
            # Square formation around leader
            d = size / math.sqrt(2)
            patterns = [
                Point(x=d, y=d, z=0.0),
                Point(x=d, y=-d, z=0.0),
                Point(x=-d, y=d, z=0.0)
            ]
        
        # Ensure we have enough positions
        while len(patterns) < self.num_drones - 1:
            patterns.append(Point(x=0.0, y=0.0, z=0.0))
            
        return patterns[:self.num_drones-1]

    def apply_rotation_transform(self, offsets, rx, ry, rz):
        # Convert degrees to radians
        rx_rad = math.radians(rx)
        ry_rad = math.radians(ry) 
        rz_rad = math.radians(rz)
        
        rotated_offsets = []
        
        for offset in offsets:
            x, y, z = offset.x, offset.y, offset.z
            
            # Rotation around Z axis (yaw)
            if rz_rad != 0:
                cos_z, sin_z = math.cos(rz_rad), math.sin(rz_rad)
                x_new = x * cos_z - y * sin_z
                y_new = x * sin_z + y * cos_z
                x, y = x_new, y_new
            
            # Rotation around Y axis (pitch)
            if ry_rad != 0:
                cos_y, sin_y = math.cos(ry_rad), math.sin(ry_rad)
                x_new = x * cos_y + z * sin_y
                z_new = -x * sin_y + z * cos_y
                x, z = x_new, z_new
            
            # Rotation around X axis (roll)
            if rx_rad != 0:
                cos_x, sin_x = math.cos(rx_rad), math.sin(rx_rad)
                y_new = y * cos_x - z * sin_x
                z_new = y * sin_x + z * cos_x
                y, z = y_new, z_new
            
            rotated_offset = Point()
            rotated_offset.x, rotated_offset.y, rotated_offset.z = x, y, z
            rotated_offsets.append(rotated_offset)
        
        return rotated_offsets

    def apply_vertical_orientation(self, offsets):
        # Rotate formation 90 degrees around X axis for vertical orientation
        return self.apply_rotation_transform(offsets, 90.0, 0.0, 0.0)

    def monitor_formation_execution(self, response):
        start_time = self.get_clock().now()
        self.formation_status = "executing"
        
        while rclpy.ok():
            current_time = self.get_clock().now()
            elapsed = (current_time - start_time).nanoseconds / 1e9

            if elapsed > self.formation_timeout:
                response.success = False
                response.message = f"Formation timeout after {elapsed:.1f} seconds"
                self.formation_status = "timeout"
                return response

            if self.check_formation_completion():
                response.success = True
                response.message = "Formation completed successfully"
                response.execution_time = elapsed
                self.formation_status = "completed"
                self.get_logger().info(f"Formation achieved in {elapsed:.2f} seconds")
                return response
            
            time.sleep(0.3)  # Check every 300ms

        response.success = False
        response.message = "Formation interrupted by shutdown"
        return response

    def check_formation_completion(self):
        with self.state_lock:
            if not self.target_poses or len(self.drone_states) < self.num_drones:
                return False

            for drone_id, target in self.target_poses.items():
                if drone_id not in self.drone_states:
                    return False
                
                current = self.drone_states[drone_id].pose.position
                target_pos = target.position
                
                distance = math.sqrt(
                    (current.x - target_pos.x)**2 +
                    (current.y - target_pos.y)**2 +
                    (current.z - target_pos.z)**2
                )
                
                if distance > self.tolerance:
                    return False
            
            # Additional safety check: verify minimum distances
            return self.verify_safety_constraints()

    def verify_safety_constraints(self):
        positions = []
        for state in self.drone_states.values():
            pos = state.pose.position
            positions.append([pos.x, pos.y, pos.z])
        
        # Check minimum distance constraint (3m minimum)
        for i in range(len(positions)):
            for j in range(i + 1, len(positions)):
                dist = math.sqrt(sum((a - b)**2 for a, b in zip(positions[i], positions[j])))
                if dist < 3.0:  # Below minimum safe distance
                    return False
        
        return True

def main(args=None):
    rclpy.init(args=args)
    executor = MultiThreadedExecutor()
    formation_controller = FormationController()
    executor.add_node(formation_controller)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        formation_controller.get_logger().info("Formation Controller shutting down...")
    finally:
        executor.shutdown()
        formation_controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()