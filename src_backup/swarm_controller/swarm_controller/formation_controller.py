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
        
        # --- Parameters ---
        self.declare_parameter('num_drones', 4)
        self.declare_parameter('formation_timeout', 60.0)
        self.declare_parameter('position_tolerance', 1.0)
        self.declare_parameter('use_sim_time', True)

        self.num_drones = self.get_parameter('num_drones').value
        self.formation_timeout = self.get_parameter('formation_timeout').value
        self.tolerance = self.get_parameter('position_tolerance').value
        self.use_sim_time = self.get_parameter('use_sim_time').value

        # --- State Tracking ---
        self.lock = Lock()
        self.drone_states = {}
        self.target_poses = {}

        # --- Publishers & Subscribers ---
        self.target_pose_pubs = {}
        for i in range(self.num_drones):
            self.target_pose_pubs[i] = self.create_publisher(
                Pose, 
                f'/swarm/target_pose/drone_{i}', 
                10
            )

        for i in range(self.num_drones):
            self.create_subscription(
                DroneState, 
                f'/swarm/state/drone_{i}', 
                self.drone_state_callback, 
                10
            )

        # --- Services ---
        self.formation_service = self.create_service(
            ChangeFormation, 
            '/change_formation', 
            self.change_formation_callback
        )
        
        self.get_logger().info("Formation Controller ready")

        
    def drone_state_callback(self, msg):
        with self.lock:
            self.drone_states[msg.drone_id] = msg

    def change_formation_callback(self, request, response):
        self.get_logger().info(f"Received formation change request: {request.formation_type} with size {request.size}")

        leader_state = self.get_leader_state()
        if not leader_state:
            response.success = False
            response.message = "Failed to change formation: Leader not found."
            self.get_logger().error(response.message)
            return response

        # 1. Calculate new target poses for all drones
        self.calculate_all_target_poses(request, leader_state)
        
        # 2. Publish new target poses to all drones
        for i in range(self.num_drones):
            if i in self.target_poses:
                self.target_pose_pubs[i].publish(self.target_poses[i])

        # 3. Enter blocking loop to wait for completion
        return self.wait_for_completion(response)

    def get_leader_state(self):
        with self.lock:
            for state in self.drone_states.values():
                if state.role == 'leader':
                    return state
        return None

    def calculate_all_target_poses(self, request, leader_state):
        with self.lock:
            self.target_poses = {} # Clear previous targets
            
            # The formation center is relative to the leader's CURRENT position plus any requested movement
            formation_center = Point()
            formation_center.x = leader_state.pose.position.x + request.move_x
            formation_center.y = leader_state.pose.position.y + request.move_y
            formation_center.z = request.altitude if request.altitude > 0 else leader_state.pose.position.z + request.move_z

            # The leader's target is the new formation center.
            self.target_poses[leader_state.drone_id] = Pose(position=formation_center)

            # Calculate follower positions relative to the new formation center
            formation_offsets = self.get_formation_offsets(request.formation_type, request.size)
            
            # Sort follower IDs to ensure consistent assignment to formation slots
            follower_ids = sorted([id for id in range(self.num_drones) if id != leader_state.drone_id])

            for i, follower_id in enumerate(follower_ids):
                if i < len(formation_offsets):
                    offset = formation_offsets[i]
                    target_pose = Pose()
                    target_pose.position.x = formation_center.x + offset.x
                    target_pose.position.y = formation_center.y + offset.y
                    target_pose.position.z = formation_center.z + offset.z
                    self.target_poses[follower_id] = target_pose

    def get_formation_offsets(self, formation_type, size):
        offsets = []
        if formation_type == 'line':
            # A horizontal line behind the leader
            offsets = [Point(x=-size, y=0.0, z=0.0), Point(x=-2*size, y=0.0, z=0.0), Point(x=-3*size, y=0.0, z=0.0)]
        elif formation_type == 'triangle':
            # Equilateral triangle with leader at the front vertex
            height = (math.sqrt(3)/2) * size
            offsets = [Point(x=-height, y=-size/2, z=0.0), Point(x=-height, y=size/2, z=0.0), Point(x=-height, y=0.0, z=size/2)]
        elif formation_type == 'square':
            # Followers form a square with the leader at the center (0,0) of the XY plane projection
            s = size / math.sqrt(2) # diagonal half-length for a square of side `size`
            offsets = [Point(x=s, y=s, z=0.0), Point(x=s, y=-s, z=0.0), Point(x=-s, y=s, z=0.0)]
        
        # Ensure we have enough offsets for all followers
        while len(offsets) < self.num_drones - 1:
            offsets.append(Point()) # Default to co-location if not defined
            
        return offsets[:self.num_drones-1]

    def is_formation_complete(self):
        with self.lock:
            if not self.target_poses or len(self.drone_states) < self.num_drones:
                return False

            for drone_id, target_pose in self.target_poses.items():
                if drone_id not in self.drone_states:
                    return False
                
                current_pos = self.drone_states[drone_id].pose.position
                target_pos = target_pose.position
                
                distance = math.sqrt(
                    (current_pos.x - target_pos.x)**2 +
                    (current_pos.y - target_pos.y)**2 +
                    (current_pos.z - target_pos.z)**2
                )
                
                if distance > self.tolerance:
                    return False
        
        return True

    def wait_for_completion(self, response):
        start_time = self.get_clock().now()
        while rclpy.ok():
            current_time = self.get_clock().now()
            elapsed_time = (current_time - start_time).nanoseconds / 1e9

            if elapsed_time > self.formation_timeout:
                response.success = False
                response.message = f"Formation change timed out after {self.formation_timeout:.1f}s."
                self.get_logger().warn(response.message)
                return response

            if self.is_formation_complete():
                response.success = True
                response.message = "Formation change completed successfully."
                response.execution_time = elapsed_time
                self.get_logger().info(f"{response.message} in {elapsed_time:.2f}s.")
                return response
            
            time.sleep(0.5)

        response.success = False
        response.message = "Shutdown was requested during formation change."
        return response

def main(args=None):
    rclpy.init(args=args)
    # Using a MultiThreadedExecutor allows the service callback to run in a separate
    # thread, so it can block without freezing the node's other activities (like subscribers).
    executor = MultiThreadedExecutor()
    formation_controller = FormationController()
    executor.add_node(formation_controller)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        formation_controller.get_logger().info("Shutting down Formation Controller.")
        executor.shutdown()
        formation_controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()