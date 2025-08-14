#!/bin/bash
# Fix drone control system and plugin issues

set -e

echo "🔧 Fixing Drone Control System and Physics"
echo "=========================================="

# Create a proper working X500 model with working plugins
cat > src/swarm_controller/models/x500/model.sdf << 'EOF'
<?xml version="1.0"?>
<sdf version="1.9">
  <model name="x500">
    <pose>0 0 0.194 0 0 0</pose>
    
    <!-- Main body link -->
    <link name="base_link">
      <inertial>
        <pose>0 0 0 0 0 0</pose>
        <mass>1.5</mass>
        <inertia>
          <ixx>0.029125</ixx>
          <ixy>0.0</ixy>
          <ixz>0.0</ixz>
          <iyy>0.029125</iyy>
          <iyz>0.0</iyz>
          <izz>0.055225</izz>
        </inertia>
      </inertial>

      <!-- Main body visual -->
      <visual name="base_visual">
        <pose>0 0 0 0 0 0</pose>
        <geometry>
          <box>
            <size>0.47 0.47 0.11</size>
          </box>
        </geometry>
        <material>
          <ambient>0.3 0.3 0.3 1.0</ambient>
          <diffuse>0.3 0.3 0.3 1.0</diffuse>
          <specular>0.1 0.1 0.1 1.0</specular>
        </material>
      </visual>

      <!-- Main body collision -->
      <collision name="base_collision">
        <pose>0 0 0 0 0 0</pose>
        <geometry>
          <box>
            <size>0.47 0.47 0.11</size>
          </box>
        </geometry>
        <surface>
          <contact>
            <collide_bitmask>0x01</collide_bitmask>
          </contact>
        </surface>
      </collision>

      <!-- Rotor visuals -->
      <visual name="rotor_0_visual">
        <pose>0.13 -0.22 0.023 0 0 0</pose>
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.2 0.2 1.0 0.8</ambient>
          <diffuse>0.2 0.2 1.0 0.8</diffuse>
        </material>
      </visual>

      <visual name="rotor_1_visual">
        <pose>-0.13 0.2 0.023 0 0 0</pose>
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.2 0.2 1.0 0.8</ambient>
          <diffuse>0.2 0.2 1.0 0.8</diffuse>
        </material>
      </visual>

      <visual name="rotor_2_visual">
        <pose>0.13 0.22 0.023 0 0 0</pose>
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>1.0 0.2 0.2 0.8</ambient>
          <diffuse>1.0 0.2 0.2 0.8</diffuse>
        </material>
      </visual>

      <visual name="rotor_3_visual">
        <pose>-0.13 -0.2 0.023 0 0 0</pose>
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>1.0 0.2 0.2 0.8</ambient>
          <diffuse>1.0 0.2 0.2 0.8</diffuse>
        </material>
      </visual>
    </link>

    <!-- Rotor links (for physics) -->
    <link name="rotor_0">
      <pose>0.13 -0.22 0.023 0 0 0</pose>
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.000166704</iyy>
          <izz>0.000167604</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>0 0 1 0.5</ambient>
          <diffuse>0 0 1 0.7</diffuse>
        </material>
      </visual>
    </link>

    <link name="rotor_1">
      <pose>-0.13 0.2 0.023 0 0 0</pose>
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.000166704</iyy>
          <izz>0.000167604</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>0 0 1 0.5</ambient>
          <diffuse>0 0 1 0.7</diffuse>
        </material>
      </visual>
    </link>

    <link name="rotor_2">
      <pose>0.13 0.22 0.023 0 0 0</pose>
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.000166704</iyy>
          <izz>0.000167604</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>1 0 0 0.5</ambient>
          <diffuse>1 0 0 0.7</diffuse>
        </material>
      </visual>
    </link>

    <link name="rotor_3">
      <pose>-0.13 -0.2 0.023 0 0 0</pose>
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.000166704</iyy>
          <izz>0.000167604</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <length>0.005</length>
            <radius>0.128</radius>
          </cylinder>
        </geometry>
        <material>
          <ambient>1 0 0 0.5</ambient>
          <diffuse>1 0 0 0.7</diffuse>
        </material>
      </visual>
    </link>

    <!-- Rotor joints -->
    <joint name="rotor_0_joint" type="revolute">
      <child>rotor_0</child>
      <parent>base_link</parent>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>

    <joint name="rotor_1_joint" type="revolute">
      <child>rotor_1</child>
      <parent>base_link</parent>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>

    <joint name="rotor_2_joint" type="revolute">
      <child>rotor_2</child>
      <parent>base_link</parent>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>

    <joint name="rotor_3_joint" type="revolute">
      <child>rotor_3</child>
      <parent>base_link</parent>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>

    <!-- IMU Sensor -->
    <link name="imu_link">
      <pose>0 0 0 0 0 0</pose>
      <inertial>
        <mass>0.01</mass>
        <inertia>
          <ixx>1e-05</ixx>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyy>1e-05</iyy>
          <iyz>0</iyz>
          <izz>1e-05</izz>
        </inertia>
      </inertial>
      <sensor name="imu_sensor" type="imu">
        <always_on>1</always_on>
        <update_rate>100</update_rate>
        <visualize>false</visualize>
        <topic>imu</topic>
        <enable_metrics>false</enable_metrics>
      </sensor>
    </link>

    <joint name="imu_joint" type="fixed">
      <child>imu_link</child>
      <parent>base_link</parent>
    </joint>

    <!-- Working Multicopter plugins with correct names -->
    <plugin
        filename="gz-sim-multicopter-motor-model-system"
        name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_0_joint</jointName>
      <linkName>rotor_0</linkName>
      <turningDirection>ccw</turningDirection>
      <timeConstantUp>0.0182</timeConstantUp>
      <timeConstantDown>0.0274</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>0.00000854858</motorConstant>
      <momentConstant>0.016</momentConstant>
      <commandSubTopic>gazebo/command/motor_speed</commandSubTopic>
      <motorNumber>0</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>0.0000001</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/0</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
    </plugin>

    <plugin
        filename="gz-sim-multicopter-motor-model-system"
        name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_1_joint</jointName>
      <linkName>rotor_1</linkName>
      <turningDirection>cw</turningDirection>
      <timeConstantUp>0.0182</timeConstantUp>
      <timeConstantDown>0.0274</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>0.00000854858</motorConstant>
      <momentConstant>0.016</momentConstant>
      <commandSubTopic>gazebo/command/motor_speed</commandSubTopic>
      <motorNumber>1</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>0.0000001</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/1</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
    </plugin>

    <plugin
        filename="gz-sim-multicopter-motor-model-system"
        name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_2_joint</jointName>
      <linkName>rotor_2</linkName>
      <turningDirection>ccw</turningDirection>
      <timeConstantUp>0.0182</timeConstantUp>
      <timeConstantDown>0.0274</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>0.00000854858</motorConstant>
      <momentConstant>0.016</momentConstant>
      <commandSubTopic>gazebo/command/motor_speed</commandSubTopic>
      <motorNumber>2</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>0.0000001</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/2</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
    </plugin>

    <plugin
        filename="gz-sim-multicopter-motor-model-system"
        name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_3_joint</jointName>
      <linkName>rotor_3</linkName>
      <turningDirection>cw</turningDirection>
      <timeConstantUp>0.0182</timeConstantUp>
      <timeConstantDown>0.0274</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>0.00000854858</motorConstant>
      <momentConstant>0.016</momentConstant>
      <commandSubTopic>gazebo/command/motor_speed</commandSubTopic>
      <motorNumber>3</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>0.0000001</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/3</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
    </plugin>

    <!-- Multicopter velocity control plugin -->
    <plugin
        filename="gz-sim-multicopter-control-system"
        name="gz::sim::systems::MulticopterVelocityControl">
      <robotNamespace></robotNamespace>
      <commandSubTopic>cmd_vel</commandSubTopic>
      <motorSpeedCommandPubTopic>gazebo/command/motor_speed</motorSpeedCommandPubTopic>
      <enableSubTopic>enable</enableSubTopic>
      <comLinkName>base_link</comLinkName>
      <velocityGain>2.7 2.7 2.7</velocityGain>
      <attitudeGain>3.0 3.0 0.15</attitudeGain>
      <angularRateGain>0.52 0.52 0.025</angularRateGain>
      <maximumLinearAcceleration>2 2 2</maximumLinearAcceleration>
      <maximumLinearVelocity>5 5 5</maximumLinearVelocity>
      <maximumAngularVelocity>3 3 3</maximumAngularVelocity>
      <linearVelocityNoiseMean>0 0 0</linearVelocityNoiseMean>
      <linearVelocityNoiseStdDev>0.1 0.1 0.1</linearVelocityNoiseStdDev>
      <angularVelocityNoiseMean>0 0 0</angularVelocityNoiseMean>
      <angularVelocityNoiseStdDev>0.05 0.05 0.05</angularVelocityNoiseStdDev>
    </plugin>

    <!-- Odometry publisher -->
    <plugin
        filename="gz-sim-odometry-publisher-system"
        name="gz::sim::systems::OdometryPublisher">
      <odom_frame>odom</odom_frame>
      <robot_base_frame>base_link</robot_base_frame>
      <odom_topic>odometry</odom_topic>
      <odom_publish_frequency>50</odom_publish_frequency>
    </plugin>

  </model>
</sdf>
EOF

echo "🚁 Creating enhanced drone controller with better physics integration..."

# Create a simplified but more reliable swarm_drone controller
cat > src/swarm_controller/swarm_controller/swarm_drone.py << 'EOF'
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
        self.mission_action_server = ActionServer(
            self, ExecuteMission, '/execute_mission', 
            self.execute_mission_callback
        )
        self.disarm_service = self.create_service(
            DisarmLeader, '/disarm_leader', 
            self.handle_disarm_request
        )
        
        # Timers
        self.control_timer = self.create_timer(0.1, self.control_loop)  # 10 Hz
        self.state_timer = self.create_timer(0.2, self.publish_drone_state)  # 5 Hz
        self.leadership_timer = self.create_timer(2.0, self.check_leadership_status)
        self.enable_timer = self.create_timer(0.5, self.publish_enable_status)
        
        # Initialize as armed and enabled for leader
        if self.role == 'leader':
            self.is_armed = True
            self.is_enabled = True
            
        # Wait a bit for initialization
        time.sleep(1.0)
        
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
                self.is_enabled = msg.data
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
            
            if hasattr(msg, 'role') and msg.role == 'leader':
                if self.leader_id != drone_id:
                    self.get_logger().info(f"New leader detected: drone_{drone_id}")
                self.leader_id = drone_id
                self.last_leader_contact = current_time

    def control_loop(self):
        """Main control loop - simplified PID controller"""
        if not self.is_armed or not self.is_enabled:
            self.velocity_publisher.publish(Twist())
            return

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
                
                self.get_logger().warn(
                    f"Avoiding collision with drone_{drone_id}: {distance:.2f}m",
                    throttle_duration_sec=3.0
                )
        
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
                self.is_armed = True
                self.is_enabled = True
                self.mission_active = True if self.waypoint_list else False

    def publish_drone_state(self):
        """Publish current drone state"""
        state_msg = DroneState()
        state_msg.drone_id = self.drone_id
        state_msg.role = self.role
        state_msg.pose = self.current_pose
        state_msg.velocity = self.current_velocity
        state_msg.is_armed = self.is_armed
        state_msg.is_connected = True
        state_msg.battery_level = 100.0
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
            feedback_msg.status_message = f"Moving to waypoint {self.current_waypoint_index + 1}/{len(self.waypoint_list)}"
            goal_handle.publish_feedback(feedback_msg)
            
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
EOF

echo ""
echo "🚁 Creating test script for individual drone control..."

# Create test script for debugging drone control
cat > test_single_drone.sh << 'EOF'
#!/bin/bash
# Test single drone physics and control

echo "🧪 Testing Single Drone Control"
echo "==============================="

# Source environment
source /opt/ros/jazzy/setup.bash
source install/setup.bash

echo "Starting Gazebo with single drone..."

# Launch gazebo with single drone
gz sim -r -v4 src/swarm_controller/worlds/swarm_arena.world &
GAZEBO_PID=$!

sleep 5

echo "Spawning single drone..."
ros2 run ros_gz_sim create -name test_x500 -file src/swarm_controller/models/x500/model.sdf -x 0 -y 0 -z 1

sleep 3

echo "Starting ROS-Gazebo bridges..."
ros2 run ros_gz_bridge parameter_bridge /model/test_x500/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry --ros-args --remap /model/test_x500/odometry:=/test/odom &
BRIDGE1_PID=$!

ros2 run ros_gz_bridge parameter_bridge /model/test_x500/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist --ros-args --remap /model/test_x500/cmd_vel:=/test/cmd_vel &
BRIDGE2_PID=$!

ros2 run ros_gz_bridge parameter_bridge /model/test_x500/enable@std_msgs/msg/Bool]gz.msgs.Boolean --ros-args --remap /model/test_x500/enable:=/test/enable &
BRIDGE3_PID=$!

sleep 3

echo "Testing basic commands..."
echo "1. Enabling drone..."
ros2 topic pub --once /test/enable std_msgs/msg/Bool "{data: true}"

sleep 2

echo "2. Sending upward velocity..."
ros2 topic pub --rate 10 /test/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0, y: 0.0, z: 1.0}}" &
CMD_PID=$!

sleep 5
kill $CMD_PID

echo "3. Sending forward velocity..."
ros2 topic pub --rate 10 /test/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0, y: 0.0, z: 0.0}}" &
CMD_PID=$!

sleep 5
kill $CMD_PID

echo "4. Hover (zero velocity)..."
ros2 topic pub --rate 10 /test/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0, y: 0.0, z: 0.0}}" &
CMD_PID=$!

sleep 3
kill $CMD_PID

echo ""
echo "Test completed. Press Ctrl+C to stop all processes."

cleanup() {
    echo "Cleaning up..."
    kill $GAZEBO_PID $BRIDGE1_PID $BRIDGE2_PID $BRIDGE3_PID $CMD_PID 2>/dev/null
    killall -9 gz 2>/dev/null
    exit 0
}

trap cleanup INT

wait
EOF

chmod +x test_single_drone.sh

echo "✅ Enhanced drone control system created!"
echo ""
echo "Key improvements:"
echo "- Fixed SDF model with proper plugin names and structure"
echo "- Enhanced swarm_drone controller with better PID control"
echo "- Proper rotor joints and physics"
echo "- Collision avoidance and safety constraints"
echo "- Simplified but robust control logic"
echo ""
echo "Next steps:"
echo "1. Rebuild: ./clean_build.sh && ./complete_rebuild.sh"
echo "2. Test single drone: ./test_single_drone.sh (optional)"
echo "3. Run full competition: ./run_competition_zsh.sh"
echo ""
echo "The drones should now be visible and controllable! 🚁"