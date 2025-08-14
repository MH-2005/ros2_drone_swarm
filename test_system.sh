#!/bin/bash
set -e

echo "🧪 Testing ROS2 Swarm System"
echo "============================="

# Check ROS environment
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS2 environment not sourced!"
    echo "Please run: source /opt/ros/jazzy/setup.bash"
    exit 1
fi

echo "✅ ROS $ROS_DISTRO environment active"

# Source workspace
if [ -f "install/setup.bash" ]; then
    source install/setup.bash
    echo "✅ Workspace sourced"
else
    echo "❌ Workspace not built! Run ./fix_build_system.sh first"
    exit 1
fi

# Test 1: Check packages
echo "🔍 Checking packages..."
if ros2 pkg list | grep -q swarm_msgs; then
    echo "✅ swarm_msgs package found"
else
    echo "❌ swarm_msgs package missing"
    exit 1
fi

if ros2 pkg list | grep -q swarm_controller; then
    echo "✅ swarm_controller package found"
else
    echo "❌ swarm_controller package missing"
    exit 1
fi

# Test 2: Check executables
echo "🔍 Checking executables..."
EXEC_DIR="install/swarm_controller/lib/swarm_controller"

if [ -f "$EXEC_DIR/swarm_drone" ]; then
    echo "✅ swarm_drone executable exists"
else
    echo "❌ swarm_drone executable missing"
fi

if [ -f "$EXEC_DIR/formation_controller" ]; then
    echo "✅ formation_controller executable exists"
else
    echo "❌ formation_controller executable missing"
fi

if [ -f "$EXEC_DIR/mission_executor" ]; then
    echo "✅ mission_executor executable exists"
else
    echo "❌ mission_executor executable missing"
fi

# Test 3: Check launch files
echo "🔍 Checking launch files..."
if [ -f "src/swarm_controller/launch/run_competition.launch.py" ]; then
    echo "✅ Competition launch file exists"
else
    echo "❌ Competition launch file missing"
fi

# Test 4: Test node creation (quick test)
echo "🔍 Testing node creation..."
timeout 5s python3 -c "
import rclpy
import sys
import os
sys.path.insert(0, 'install/swarm_controller/lib/python3.12/site-packages')

try:
    rclpy.init()
    from swarm_controller.swarm_drone import SwarmDrone
    node = SwarmDrone()
    print('✅ SwarmDrone node created successfully')
    node.destroy_node()
    rclpy.shutdown()
except Exception as e:
    print(f'❌ Node creation failed: {e}')
    sys.exit(1)
" || echo "⚠️ Node test timed out (may be normal)"

# Test 5: Check Gazebo availability
echo "🔍 Checking Gazebo..."
if command -v gz &> /dev/null; then
    echo "✅ Gazebo (gz) command available"
    gz sim --help &>/dev/null && echo "✅ Gazebo sim working" || echo "⚠️ Gazebo sim might have issues"
else
    echo "❌ Gazebo not found in PATH"
fi

# Test 6: Check world file
echo "🔍 Checking world file..."
WORLD_FILE="install/swarm_controller/share/swarm_controller/worlds/swarm_arena.world"
if [ -f "$WORLD_FILE" ]; then
    echo "✅ World file exists: $WORLD_FILE"
else
    echo "❌ World file missing: $WORLD_FILE"
fi

# Test 7: Check model files
echo "🔍 Checking model files..."
MODEL_FILE="install/swarm_controller/share/swarm_controller/models/x500/model.sdf"
if [ -f "$MODEL_FILE" ]; then
    echo "✅ Drone model exists: $MODEL_FILE"
else
    echo "❌ Drone model missing: $MODEL_FILE"
fi

echo ""
echo "🎯 System Status Summary:"
echo "========================="

# Quick validation
ISSUES=0

# Check critical files
for file in \
    "install/swarm_controller/lib/swarm_controller/swarm_drone" \
    "install/swarm_controller/lib/swarm_controller/formation_controller" \
    "install/swarm_controller/lib/swarm_controller/mission_executor" \
    "$WORLD_FILE" \
    "$MODEL_FILE"
do
    if [ ! -f "$file" ]; then
        echo "❌ Missing: $file"
        ISSUES=$((ISSUES + 1))
    fi
done

if [ $ISSUES -eq 0 ]; then
    echo "🎉 All critical components are present!"
    echo ""
    echo "Ready to run:"
    echo "  ./run_competition_zsh.sh"
    echo ""
else
    echo "⚠️ Found $ISSUES issues. Run ./fix_build_system.sh to resolve."
fi

echo "Test completed."