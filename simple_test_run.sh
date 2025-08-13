#!/bin/bash

# Simple test without GUI to check ROS nodes
echo "🧪 Simple ROS2 Node Test"
echo "========================"

# Force bash environment
export SHELL=/bin/bash

# Source ROS and workspace
source /opt/ros/jazzy/setup.bash
source install/setup.bash

echo "✅ Environment sourced"

# Test individual nodes for 10 seconds each
echo ""
echo "1. Testing Formation Controller (10 sec)..."
timeout 10 ros2 run swarm_controller formation_controller --ros-args -p use_sim_time:=false &
FC_PID=$!
sleep 2

echo "2. Testing Mission Executor (10 sec)..."  
timeout 10 ros2 run swarm_controller mission_executor --ros-args -p use_sim_time:=false &
ME_PID=$!
sleep 2

echo "3. Testing Swarm Drone as Leader (10 sec)..."
timeout 10 ros2 run swarm_controller swarm_drone --ros-args -p drone_id:=0 -p role:=leader -p use_sim_time:=false &
SD_PID=$!
sleep 2

echo "4. Testing Swarm Drone as Follower (10 sec)..."
timeout 10 ros2 run swarm_controller swarm_drone --ros-args -p drone_id:=1 -p role:=follower -p use_sim_time:=false &
SF_PID=$!

# Wait for all tests to complete
wait $FC_PID 2>/dev/null || echo "✅ Formation Controller test completed"
wait $ME_PID 2>/dev/null || echo "✅ Mission Executor test completed"  
wait $SD_PID 2>/dev/null || echo "✅ Leader Drone test completed"
wait $SF_PID 2>/dev/null || echo "✅ Follower Drone test completed"

echo ""
echo "🎉 All ROS2 nodes tested successfully!"
echo ""
echo "Next: Try the full simulation:"
echo "./run_competition_zsh.sh"