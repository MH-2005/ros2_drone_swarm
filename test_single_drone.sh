#!/bin/bash
set -e

echo "🧪 Testing Single Drone"
echo "======================="

# Check ROS environment
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS2 environment not sourced!"
    echo "Please run: source /opt/ros/jazzy/setup.bash"
    exit 1
fi

# Source workspace
if [ -f "install/setup.bash" ]; then
    source install/setup.bash
    echo "✅ Workspace sourced"
else
    echo "❌ Workspace not built! Run ./fix_build_system.sh first"
    exit 1
fi

# Clean up any running processes
echo "🧹 Cleaning up previous processes..."
killall -9 gz gzserver gzclient &>/dev/null || true
pkill -f "ros2\|python3.*swarm" &>/dev/null || true
sleep 2

echo "🚀 Starting single drone test..."
echo "This will:"
echo "1. Launch Gazebo with world"
echo "2. Spawn one drone" 
echo "3. Start ROS bridges"
echo "4. Start drone controller"
echo ""
echo "Press Ctrl+C to stop"
echo ""

# Launch the simple test
ros2 launch swarm_controller simple_drone_test.launch.py &
LAUNCH_PID=$!

# Setup cleanup trap
cleanup() {
    echo ""
    echo "🛑 Stopping test..."
    kill $LAUNCH_PID &>/dev/null || true
    killall -9 gz gzserver gzclient &>/dev/null || true
    pkill -f "ros2\|python3.*swarm" &>/dev/null || true
    echo "✅ Test stopped"
}

trap cleanup EXIT INT TERM

echo "✅ Test launched (PID: $LAUNCH_PID)"
echo ""
echo "📊 Monitoring topics (in another terminal, you can run):"
echo "  ros2 topic list"
echo "  ros2 topic echo /drone_0/odom"
echo "  ros2 topic echo /swarm/state/drone_0"
echo ""
echo "🎮 Manual control test (in another terminal):"
echo "  ros2 topic pub /drone_0/cmd_vel geometry_msgs/msg/Twist \"{linear: {x: 0.0, y: 0.0, z: 1.0}}\""
echo ""

# Wait for the process
wait $LAUNCH_PID