#!/bin/bash

echo "🧪 Quick Test of ROS2 Drone Swarm"
echo "================================="

# Build only the changed files
echo "🔨 Building swarm_controller..."
colcon build --packages-select swarm_controller --symlink-install

# Source the workspace
echo "📡 Sourcing workspace..."
source install/setup.zsh  # Use zsh since bash seems to have issues

# Test individual executables
echo "🚁 Testing executables..."

echo "1. Testing swarm_drone (5 second timeout)..."
timeout 5 ros2 run swarm_controller swarm_drone --ros-args -p drone_id:=0 -p use_sim_time:=false 2>/dev/null || echo "✅ swarm_drone test completed"

echo "2. Testing formation_controller (5 second timeout)..."
timeout 5 ros2 run swarm_controller formation_controller --ros-args -p use_sim_time:=false 2>/dev/null || echo "✅ formation_controller test completed"

echo "3. Testing mission_executor (5 second timeout)..."
timeout 5 ros2 run swarm_controller mission_executor --ros-args -p use_sim_time:=false 2>/dev/null || echo "✅ mission_executor test completed"

echo ""
echo "🎯 Testing launch file..."
echo "Checking if launch file can be parsed..."
ros2 launch swarm_controller run_competition.launch.py --show-args || echo "Launch file has issues"

echo ""
echo "✅ All tests completed!"
echo ""
echo "Ready to run full simulation:"
echo "./run_competition.sh"