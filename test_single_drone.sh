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
