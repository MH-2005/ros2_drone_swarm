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
      <visual name="base_visual">
        <geometry>
          <box><size>0.47 0.47 0.11</size></box>
        </geometry>
      </visual>
      <collision name="base_collision">
        <geometry>
          <box><size>0.47 0.47 0.11</size></box>
        </geometry>
      </collision>
    </link>

    <link name="rotor_0"><pose>0.13 -0.22 0.023 0 0 0</pose><inertial><mass>0.01</mass><inertia><ixx>9.75e-07</ixx><iyy>0.000166704</iyy><izz>0.000167604</izz></inertia></inertial></link>
    <link name="rotor_1"><pose>-0.13 0.2 0.023 0 0 0</pose><inertial><mass>0.01</mass><inertia><ixx>9.75e-07</ixx><iyy>0.000166704</iyy><izz>0.000167604</izz></inertia></inertial></link>
    <link name="rotor_2"><pose>0.13 0.22 0.023 0 0 0</pose><inertial><mass>0.01</mass><inertia><ixx>9.75e-07</ixx><iyy>0.000166704</iyy><izz>0.000167604</izz></inertia></inertial></link>
    <link name="rotor_3"><pose>-0.13 -0.2 0.023 0 0 0</pose><inertial><mass>0.01</mass><inertia><ixx>9.75e-07</ixx><iyy>0.000166704</iyy><izz>0.000167604</izz></inertia></inertial></link>
    <joint name="rotor_0_joint" type="revolute"><parent>base_link</parent><child>rotor_0</child><axis><xyz>0 0 1</xyz></axis></joint>
    <joint name="rotor_1_joint" type="revolute"><parent>base_link</parent><child>rotor_1</child><axis><xyz>0 0 1</xyz></axis></joint>
    <joint name="rotor_2_joint" type="revolute"><parent>base_link</parent><child>rotor_2</child><axis><xyz>0 0 1</xyz></axis></joint>
    <joint name="rotor_3_joint" type="revolute"><parent>base_link</parent><child>rotor_3</child><axis><xyz>0 0 1</xyz></axis></joint>

    <link name="imu_link"><sensor name="imu_sensor" type="imu"><always_on>1</always_on><update_rate>100</update_rate></sensor></link>
    <joint name="imu_joint" type="fixed"><parent>base_link</parent><child>imu_link</child></joint>

    <plugin filename="gz-sim-multicopter-motor-model-system" name="gz::sim::systems::MulticopterMotorModel"><jointName>rotor_0_joint</jointName><actuator_number>0</actuator_number><turningDirection>ccw</turningDirection></plugin>
    <plugin filename="gz-sim-multicopter-motor-model-system" name="gz::sim::systems::MulticopterMotorModel"><jointName>rotor_1_joint</jointName><actuator_number>1</actuator_number><turningDirection>cw</turningDirection></plugin>
    <plugin filename="gz-sim-multicopter-motor-model-system" name="gz::sim::systems::MulticopterMotorModel"><jointName>rotor_2_joint</jointName><actuator_number>2</actuator_number><turningDirection>ccw</turningDirection></plugin>
    <plugin filename="gz-sim-multicopter-motor-model-system" name="gz::sim::systems::MulticopterMotorModel"><jointName>rotor_3_joint</jointName><actuator_number>3</actuator_number><turningDirection>cw</turningDirection></plugin>

    <plugin filename="gz-sim-multicopter-control-system" name="gz::sim::systems::MulticopterVelocityControl">
      <commandSubTopic>cmd_vel</commandSubTopic>
      <enableSubTopic>enable</enableSubTopic>
      <comLinkName>base_link</comLinkName>

      <rotorConfiguration>
        <rotor>
          <actuator_number>0</actuator_number>
          <angle>-135</angle>
          <direction>ccw</direction>
          <forceConstant>0.00000854858</forceConstant>
          <momentConstant>0.016</momentConstant>
        </rotor>
        <rotor>
          <actuator_number>1</actuator_number>
          <angle>45</angle>
          <direction>cw</direction>
          <forceConstant>0.00000854858</forceConstant>
          <momentConstant>0.016</momentConstant>
        </rotor>
        <rotor>
          <actuator_number>2</actuator_number>
          <angle>135</angle>
          <direction>ccw</direction>
          <forceConstant>0.00000854858</forceConstant>
          <momentConstant>0.016</momentConstant>
        </rotor>
        <rotor>
          <actuator_number>3</actuator_number>
          <angle>-45</angle>
          <direction>cw</direction>
          <forceConstant>0.00000854858</forceConstant>
          <momentConstant>0.016</momentConstant>
        </rotor>
      </rotorConfiguration>

    </plugin>

    <plugin filename="gz-sim-odometry-publisher-system" name="gz::sim::systems::OdometryPublisher">
      <odom_frame>odom</odom_frame>
      <robot_base_frame>base_link</robot_base_frame>
      <odom_topic>odometry</odom_topic>
    </plugin>

  </model>
</sdf>
EOF

echo "✅ Enhanced drone control system created!"