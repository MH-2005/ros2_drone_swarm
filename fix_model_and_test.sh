#!/bin/bash
set -e

echo "🔧 Fixing Drone Model and Testing System"
echo "========================================"

# Check if ROS is sourced
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS2 environment not sourced!"
    exit 1
fi

# Source workspace
if [ -f "install/setup.bash" ]; then
    source install/setup.bash
else
    echo "❌ Workspace not built! Run ./fix_build_system.sh first"
    exit 1
fi

# Step 1: Replace the broken SDF model
echo "🔧 Replacing broken SDF model..."
SDF_FILE="src/swarm_controller/models/x500/model.sdf"

if [ ! -f "$SDF_FILE" ]; then
    echo "❌ SDF file not found: $SDF_FILE"
    exit 1
fi

# Backup original
cp "$SDF_FILE" "$SDF_FILE.backup"
echo "📁 Original SDF backed up"

# Replace with fixed version (you need to copy the content from the artifact above)
cat > "$SDF_FILE" << 'EOF'
<?xml version="1.0"?>
<sdf version="1.9">
  <model name="x500">
    <pose>0 0 0.3 0 0 0</pose>
    
    <link name="base_link">
      <inertial>
        <mass>1.5</mass>
        <inertia>
          <ixx>0.029125</ixx>
          <iyy>0.029125</iyy>
          <izz>0.055225</izz>
        </inertia>
      </inertial>
      
      <visual name="base_visual">
        <geometry>
          <box>
            <size>0.47 0.47 0.11</size>
          </box>
        </geometry>
        <material>
          <ambient>0.2 0.2 0.2 1</ambient>
          <diffuse>0.2 0.2 0.2 1</diffuse>
          <specular>0.1 0.1 0.1 1</specular>
        </material>
      </visual>
      
      <collision name="base_collision">
        <geometry>
          <box>
            <size>0.47 0.47 0.11</size>
          </box>
        </geometry>
      </collision>
    </link>

    <!-- Rotor 0 -->
    <link name="rotor_0">
      <pose>0.13 -0.22 0.023 0 0 0</pose>
      <inertial>
        <mass>0.005</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.0001667</iyy>
          <izz>0.0001676</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.1 0.1 0.1 1</ambient>
          <diffuse>0.1 0.1 0.1 1</diffuse>
        </material>
      </visual>
      <collision name="collision">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
      </collision>
    </link>
    
    <joint name="rotor_0_joint" type="revolute">
      <parent>base_link</parent>
      <child>rotor_0</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
      </axis>
    </joint>

    <!-- Rotor 1 -->
    <link name="rotor_1">
      <pose>-0.13 0.2 0.023 0 0 0</pose>
      <inertial>
        <mass>0.005</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.0001667</iyy>
          <izz>0.0001676</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.1 0.1 0.1 1</ambient>
          <diffuse>0.1 0.1 0.1 1</diffuse>
        </material>
      </visual>
      <collision name="collision">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
      </collision>
    </link>
    
    <joint name="rotor_1_joint" type="revolute">
      <parent>base_link</parent>
      <child>rotor_1</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
      </axis>
    </joint>

    <!-- Rotor 2 -->
    <link name="rotor_2">
      <pose>0.13 0.22 0.023 0 0 0</pose>
      <inertial>
        <mass>0.005</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.0001667</iyy>
          <izz>0.0001676</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.1 0.1 0.1 1</ambient>
          <diffuse>0.1 0.1 0.1 1</diffuse>
        </material>
      </visual>
      <collision name="collision">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
      </collision>
    </link>
    
    <joint name="rotor_2_joint" type="revolute">
      <parent>base_link</parent>
      <child>rotor_2</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
      </axis>
    </joint>

    <!-- Rotor 3 -->
    <link name="rotor_3">
      <pose>-0.13 -0.2 0.023 0 0 0</pose>
      <inertial>
        <mass>0.005</mass>
        <inertia>
          <ixx>9.75e-07</ixx>
          <iyy>0.0001667</iyy>
          <izz>0.0001676</izz>
        </inertia>
      </inertial>
      <visual name="visual">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
        <material>
          <ambient>0.1 0.1 0.1 1</ambient>
          <diffuse>0.1 0.1 0.1 1</diffuse>
        </material>
      </visual>
      <collision name="collision">
        <geometry>
          <cylinder>
            <radius>0.128</radius>
            <length>0.005</length>
          </cylinder>
        </geometry>
      </collision>
    </link>
    
    <joint name="rotor_3_joint" type="revolute">
      <parent>base_link</parent>
      <child>rotor_3</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e16</lower>
          <upper>1e16</upper>
        </limit>
      </axis>
    </joint>
    
    <!-- Motor Model Plugins -->
    <plugin filename="gz-sim-multicopter-motor-model-system" 
            name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_0_joint</jointName>
      <linkName>rotor_0</linkName>
      <turningDirection>ccw</turningDirection>
      <timeConstantUp>0.0125</timeConstantUp>
      <timeConstantDown>0.025</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>8.54858e-06</motorConstant>
      <momentConstant>0.06</momentConstant>
      <commandSubTopic>command/motor_speed</commandSubTopic>
      <motorNumber>0</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>1e-06</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/0</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
      <motorType>velocity</motorType>
    </plugin>

    <plugin filename="gz-sim-multicopter-motor-model-system" 
            name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_1_joint</jointName>
      <linkName>rotor_1</linkName>
      <turningDirection>cw</turningDirection>
      <timeConstantUp>0.0125</timeConstantUp>
      <timeConstantDown>0.025</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>8.54858e-06</motorConstant>
      <momentConstant>0.06</momentConstant>
      <commandSubTopic>command/motor_speed</commandSubTopic>
      <motorNumber>1</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>1e-06</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/1</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
      <motorType>velocity</motorType>
    </plugin>

    <plugin filename="gz-sim-multicopter-motor-model-system" 
            name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_2_joint</jointName>
      <linkName>rotor_2</linkName>
      <turningDirection>ccw</turningDirection>
      <timeConstantUp>0.0125</timeConstantUp>
      <timeConstantDown>0.025</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>8.54858e-06</motorConstant>
      <momentConstant>0.06</momentConstant>
      <commandSubTopic>command/motor_speed</commandSubTopic>
      <motorNumber>2</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>1e-06</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/2</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
      <motorType>velocity</motorType>
    </plugin>

    <plugin filename="gz-sim-multicopter-motor-model-system" 
            name="gz::sim::systems::MulticopterMotorModel">
      <jointName>rotor_3_joint</jointName>
      <linkName>rotor_3</linkName>
      <turningDirection>cw</turningDirection>
      <timeConstantUp>0.0125</timeConstantUp>
      <timeConstantDown>0.025</timeConstantDown>
      <maxRotVelocity>1100</maxRotVelocity>
      <motorConstant>8.54858e-06</motorConstant>
      <momentConstant>0.06</momentConstant>
      <commandSubTopic>command/motor_speed</commandSubTopic>
      <motorNumber>3</motorNumber>
      <rotorDragCoefficient>0.000806428</rotorDragCoefficient>
      <rollingMomentCoefficient>1e-06</rollingMomentCoefficient>
      <motorSpeedPubTopic>motor_speed/3</motorSpeedPubTopic>
      <rotorVelocitySlowdownSim>10</rotorVelocitySlowdownSim>
      <motorType>velocity</motorType>
    </plugin>

    <!-- Multicopter Control Plugin -->
    <plugin filename="gz-sim-multicopter-control-system" 
            name="gz::sim::systems::MulticopterVelocityControl">
      <robotNamespace></robotNamespace>
      <commandSubTopic>cmd_vel</commandSubTopic>
      <motorControlPubTopic>command/motor_speed</motorControlPubTopic>
      <enableSubTopic>enable</enableSubTopic>
      <comLinkName>base_link</comLinkName>
      <velocityGain>2.7 2.7 2.7</velocityGain>
      <attitudeGain>3.0 3.0 0.15</attitudeGain>
      <angularRateGain>0.52 0.52 0.025</angularRateGain>
      <maximumLinearVelocity>5 5 3</maximumLinearVelocity>
      <maximumLinearAcceleration>5 5 3</maximumLinearAcceleration>
      <maximumAngularVelocity>3 3 1</maximumAngularVelocity>
      <linearVelocityNoiseMean>0 0 0</linearVelocityNoiseMean>
      <linearVelocityNoiseStdDev>0.1 0.1 0.1</linearVelocityNoiseStdDev>
      <angularVelocityNoiseMean>0 0 0</angularVelocityNoiseMean>
      <angularVelocityNoiseStdDev>0.05 0.05 0.05</angularVelocityNoiseStdDev>
      
      <rotorConfiguration>
        <rotor>
          <jointName>rotor_0_joint</jointName>
          <forceConstant>8.54858e-06</forceConstant>
          <momentConstant>0.06</momentConstant>
          <direction>1</direction>
        </rotor>
        <rotor>
          <jointName>rotor_1_joint</jointName>
          <forceConstant>8.54858e-06</forceConstant>
          <momentConstant>0.06</momentConstant>
          <direction>-1</direction>
        </rotor>
        <rotor>
          <jointName>rotor_2_joint</jointName>
          <forceConstant>8.54858e-06</forceConstant>
          <momentConstant>0.06</momentConstant>
          <direction>1</direction>
        </rotor>
        <rotor>
          <jointName>rotor_3_joint</jointName>
          <forceConstant>8.54858e-06</forceConstant>
          <momentConstant>0.06</momentConstant>
          <direction>-1</direction>
        </rotor>
      </rotorConfiguration>
    </plugin>

    <!-- Odometry Publisher -->
    <plugin filename="gz-sim-odometry-publisher-system" 
            name="gz::sim::systems::OdometryPublisher">
      <odom_frame>odom</odom_frame>
      <robot_base_frame>base_link</robot_base_frame>
      <odom_topic>odometry</odom_topic>
      <odom_publish_frequency>50</odom_publish_frequency>
    </plugin>

  </model>
</sdf>
EOF

echo "✅ SDF model updated"

# Step 2: Create simple test launch file
echo "🔧 Creating simple test launch file..."
cat > "src/swarm_controller/launch/simple_drone_test.launch.py" << 'EOF'
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Get package directory
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    model_path = os.path.join(pkg_swarm_controller, 'models')

    # Setup Gazebo environment
    if 'GZ_SIM_RESOURCE_PATH' in os.environ:
        os.environ['GZ_SIM_RESOURCE_PATH'] += os.pathsep + model_path
    else:
        os.environ['GZ_SIM_RESOURCE_PATH'] = model_path

    # Launch arguments
    declare_use_sim_time = DeclareLaunchArgument('use_sim_time', default_value='true')

    # Gazebo launch
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch', 'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'{world_path} -r',
            'on_exit_shutdown': 'true'
        }.items()
    )

    # Clock bridge
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )

    # Spawn a single drone first for testing
    spawn_drone = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'test_drone',
            '-file', os.path.join(model_path, 'x500', 'model.sdf'),
            '-x', '0', '-y', '0', '-z', '0.5'
        ],
        output='screen'
    )

    # Bridge for the test drone
    drone_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/model/test_drone/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
            '/model/test_drone/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/test_drone/enable@std_msgs/msg/Bool]gz.msgs.Boolean',
        ],
        remappings=[
            ('/model/test_drone/odometry', '/drone_0/odom'),
            ('/model/test_drone/cmd_vel', '/drone_0/cmd_vel'),
            ('/model/test_drone/enable', '/drone_0/enable'),
        ],
        output='screen'
    )

    # Simple drone controller
    drone_controller = Node(
        package='swarm_controller',
        executable='swarm_drone',
        namespace='drone_0',
        name='controller',
        parameters=[{
            'drone_id': 0,
            'role': 'leader',
            'use_sim_time': True,
            'max_velocity': 1.0,
            'safety_distance': 2.0,
            'home_position': [0.0, 0.0, 3.0]
        }],
        output='screen'
    )

    return LaunchDescription([
        declare_use_sim_time,
        gazebo_launch,
        TimerAction(period=3.0, actions=[clock_bridge]),
        TimerAction(period=8.0, actions=[spawn_drone]),
        TimerAction(period=12.0, actions=[drone_bridge]),
        TimerAction(period=15.0, actions=[drone_controller]),
    ])
EOF

echo "✅ Test launch file created"

# Step 3: Rebuild the package
echo "🔨 Rebuilding package..."
colcon build --packages-select swarm_controller \
    --cmake-args -DCMAKE_BUILD_TYPE=Release

source install/setup.bash

echo ""
echo "🎯 Fix Complete!"
echo "==============="
echo ""
echo "Now you can test with:"
echo "1. Simple test: ros2 launch swarm_controller simple_drone_test.launch.py"
echo "2. Or try the full system again: ./run_competition_zsh.sh"
echo ""
echo "The main fixes:"
echo "✅ Fixed SDF model with proper joint names"
echo "✅ Added complete motor model plugins"
echo "✅ Added proper multicopter control system"
echo "✅ Created simple test launch for debugging"
echo ""