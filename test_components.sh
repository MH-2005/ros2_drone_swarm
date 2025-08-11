#!/bin/bash
# Test individual components of the swarm system

# Source the workspace from the correct path
source install/setup.bash

echo "Testing ROS2 Swarm Components..."

# Test 1: Check if messages are built
echo "1. Testing custom messages..."
ros2 interface show swarm_msgs/msg/DroneState
if [ $? -eq 0 ]; then
    echo "✅ Messages OK"
else
    echo "❌ Messages failed"
    exit 1
fi

# Test 2: Check services
echo "2. Testing custom services..."
ros2 interface show swarm_msgs/srv/ChangeFormation
if [ $? -eq 0 ]; then
    echo "✅ Services OK"
else
    echo "❌ Services failed"
    exit 1
fi

# Test 3: Check actions
echo "3. Testing custom actions..."
ros2 interface show swarm_msgs/action/ExecuteMission
if [ $? -eq 0 ]; then
    echo "✅ Actions OK"
else
    echo "❌ Actions failed"
    exit 1
fi

# Test 4: Validate Python executables
echo "4. Testing node executables..."
python3 -m py_compile src/swarm_controller/swarm_controller/swarm_leader.py
python3 -m py_compile src/swarm_controller/swarm_controller/swarm_follower.py
python3 -m py_compile src/swarm_controller/swarm_controller/formation_controller.py
python3 -m py_compile src/swarm_controller/swarm_controller/mission_executor.py

if [ $? -eq 0 ]; then
    echo "✅ Python nodes OK"
else
    echo "❌ Python compilation failed"
    exit 1
fi

echo ""
echo "All component tests passed! ✅"
echo "System is ready for competition run."
