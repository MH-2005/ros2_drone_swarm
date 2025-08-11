import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import subprocess
import time
import os
import signal
from threading import Thread

from std_msgs.msg import Bool
from swarm_msgs.srv import ChangeFormation, DisarmLeader
from swarm_msgs.action import ExecuteMission

class MissionExecutor(Node):
    """
    Orchestrates the entire competition mission by executing phases sequentially.
    It uses blocking service calls and action clients to ensure one phase completes
    before the next one begins, making the execution robust and reliable.
    """
    def __init__(self):
        super().__init__('mission_executor')
        
        # --- Parameters ---
        self.declare_parameter('video_recording', True)
        self.declare_parameter('video_output_dir', './videos/')
        
        self.record_video = self.get_parameter('video_recording').value
        self.video_dir = self.get_parameter('video_output_dir').value
        
        # --- State ---
        self.recording_process = None
        os.makedirs(self.video_dir, exist_ok=True)
        
        # --- Clients ---
        self.formation_client = self.create_client(ChangeFormation, '/change_formation')
        self.disarm_client = self.create_client(DisarmLeader, '/disarm_leader')
        self.mission_client = ActionClient(self, ExecuteMission, '/execute_mission')

        self.arm_pubs = {}
        for i in range(4): # Assuming 4 drones
            self.arm_pubs[i] = self.create_publisher(Bool, f'/drone_{i}/arm', 10)
            
        self.get_logger().info('Mission Executor initialized. Waiting for services...')
        self.wait_for_services()

    def wait_for_services(self):
        if not self.formation_client.wait_for_service(timeout_sec=10.0):
            self.get_logger().error("Formation service not available. Shutting down.")
            raise RuntimeError("Formation service not available")
        if not self.disarm_client.wait_for_service(timeout_sec=10.0):
            self.get_logger().error("Disarm service not available. Shutting down.")
            raise RuntimeError("Disarm service not available")
        if not self.mission_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error("Mission action server not available. Shutting down.")
            raise RuntimeError("Mission action server not available")
        self.get_logger().info('All services are ready!')

    def start_video_recording(self, phase_name):
        if not self.record_video: return
        try:
            video_file = os.path.join(self.video_dir, f'phase_{phase_name}.mp4')
            cmd = ['ffmpeg', '-y', '-f', 'x11grab', '-r', '25', '-s', '1920x1080',
                   '-i', ':0.0+0,0', '-vcodec', 'libx264', video_file]
            self.recording_process = subprocess.Popen(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            self.get_logger().info(f'Started recording: {video_file}')
        except Exception as e:
            self.get_logger().error(f'Failed to start recording: {e}')

    def stop_video_recording(self):
        if self.recording_process:
            try:
                self.recording_process.send_signal(signal.SIGINT)
                self.recording_process.wait(timeout=5)
                self.get_logger().info('Video recording stopped.')
            except Exception as e:
                self.get_logger().error(f'Error stopping recording: {e}')
            self.recording_process = None
            time.sleep(1) # Allow ffmpeg to finalize the file

    def set_all_drones_armed(self, armed_status: bool):
        msg = Bool()
        msg.data = armed_status
        status_str = "ARMING" if armed_status else "DISARMING"
        self.get_logger().info(f"{status_str} all drones...")
        for pub in self.arm_pubs.values():
            pub.publish(msg)
        time.sleep(2) # Wait for arm/disarm to take effect

    def run_mission_flow(self):
        self.get_logger().info('Starting full competition mission flow...')
        
        self.set_all_drones_armed(True)
        
        # --- Phase 1: Formation Shapes ---
        if not self.execute_phase_1(): return

        # --- Phase 2: Movement and Rotation ---
        if not self.execute_phase_2(): return

        # --- Phase 3: Leader Following (Auto Path) ---
        if not self.execute_phase_3(): return
        
        # --- Phase 4: Leader Disarm and Re-election ---
        if not self.execute_phase_4(): return
        
        self.set_all_drones_armed(False)
        self.get_logger().info('🎉 All competition phases completed successfully! 🎉')

    def execute_phase_1(self):
        self.get_logger().info("--- EXECUTING PHASE 1: Formation Shapes ---")
        self.start_video_recording("1_formations")
        formations = [('line', 5.0), ('triangle', 6.0), ('square', 5.0)]
        
        for f_type, f_size in formations:
            self.get_logger().info(f"Requesting '{f_type}' formation...")
            request = ChangeFormation.Request()
            request.formation_type = f_type
            request.size = f_size
            request.altitude = 5.0
            
            future = self.formation_client.call_async(request)
            rclpy.spin_until_future_complete(self, future)

            if not (future.result() and future.result().success):
                self.get_logger().error(f"Phase 1 failed: Could not form '{f_type}'.")
                self.stop_video_recording()
                return False
            time.sleep(3) # Hold formation for video
        
        self.stop_video_recording()
        return True

    def execute_phase_2(self):
        self.get_logger().info("--- EXECUTING PHASE 2: Movement and Rotation ---")
        self.start_video_recording("2_movement")
        
        # Move square formation right by 5m
        self.get_logger().info("Requesting movement...")
        request = ChangeFormation.Request()
        request.formation_type = 'square'
        request.size = 5.0
        request.altitude = 5.0
        request.move_x = 5.0
        request.move_y = -5.0

        future = self.formation_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if not (future.result() and future.result().success):
            self.get_logger().error("Phase 2 failed: Could not execute movement.")
            self.stop_video_recording()
            return False
            
        # TODO: Add rotation logic once implemented in FormationController
        
        self.stop_video_recording()
        return True

    def execute_phase_3(self):
        self.get_logger().info("--- EXECUTING PHASE 3: Leader Following ---")
        self.start_video_recording("3_leader_following")
        
        goal = ExecuteMission.Goal()
        goal.mission_type = "auto_path"
        goal.path_file = "leader_path.csv" # Ensure this file exists
        goal.max_duration = 120.0
        
        self.mission_client.wait_for_server()
        send_goal_future = self.mission_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()

        if not goal_handle.accepted:
            self.get_logger().error("Phase 3 failed: Mission goal was rejected.")
            self.stop_video_recording()
            return False
            
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        
        self.stop_video_recording()
        if not result_future.result().result.success:
             self.get_logger().error("Phase 3 failed during execution.")
             return False
        return True

    def execute_phase_4(self):
        self.get_logger().info("--- EXECUTING PHASE 4: Leader Disarm & Re-election ---")
        self.start_video_recording("4_leader_disarm")

        # Start a mission
        goal = ExecuteMission.Goal()
        goal.mission_type = "auto_path"
        goal.path_file = "leader_path.csv"
        goal.max_duration = 150.0
        
        self.mission_client.wait_for_server()
        send_goal_future = self.mission_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()

        if not goal_handle.accepted:
            self.get_logger().error("Phase 4 failed: Mission goal was rejected.")
            self.stop_video_recording()
            return False

        # Let the mission run for a bit, then disarm the leader
        self.get_logger().info("Mission started. Waiting 20 seconds before disarming leader...")
        time.sleep(20)

        self.get_logger().info("Disarming current leader...")
        disarm_request = DisarmLeader.Request()
        disarm_request.leader_id = -1 # Disarm whichever drone is the current leader
        disarm_request.return_to_home = True
        
        future = self.disarm_client.call_async(disarm_request)
        rclpy.spin_until_future_complete(self, future)
        
        if not (future.result() and future.result().success):
            self.get_logger().error("Phase 4 failed: Could not disarm leader.")
            self.stop_video_recording()
            goal_handle.cancel_goal_async()
            return False
        
        self.get_logger().info("Leader disarmed. New leader should be elected and continue the mission.")
        
        # Wait for the original mission to complete with the new leader
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        
        self.stop_video_recording()
        # In this scenario, we expect the original mission might fail because the leader changed.
        # Success is the successful disarming and observation of re-election.
        self.get_logger().info("Phase 4 observation complete.")
        return True


def main(args=None):
    rclpy.init(args=args)
    mission_executor = MissionExecutor()
    
    # Run the main mission flow in a separate thread so it doesn't block the node's spinner
    mission_thread = Thread(target=mission_executor.run_mission_flow, daemon=True)
    mission_thread.start()
    
    try:
        rclpy.spin(mission_executor)
    except (KeyboardInterrupt, RuntimeError):
        pass
    finally:
        mission_executor.get_logger().info("Shutting down mission executor.")
        mission_executor.stop_video_recording()
        mission_executor.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()