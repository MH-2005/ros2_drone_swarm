#!/bin/bash

echo "=== ROS2 Build Diagnosis ==="

echo "1. Current directory:"
pwd

echo -e "\n2. Install directory structure:"
if [ -d "install" ]; then
    find install -type f -name "*.bash" -o -name "*.sh" | head -20
else
    echo "❌ install directory not found!"
fi

echo -e "\n3. Check swarm_controller in install:"
if [ -d "install/swarm_controller" ]; then
    echo "✅ swarm_controller directory exists"
    ls -la install/swarm_controller/
else
    echo "❌ swarm_controller not found in install"
fi

echo -e "\n4. Check Python site-packages:"
if [ -d "install/swarm_controller/lib" ]; then
    find install/swarm_controller/lib -name "swarm_controller" -type d
else
    echo "❌ lib directory not found"
fi

echo -e "\n5. Check setup.py entry_points:"
if [ -f "src/swarm_controller/setup.py" ]; then
    echo "✅ setup.py found"
    grep -A 10 "entry_points" src/swarm_controller/setup.py
else
    echo "❌ setup.py not found"
fi

echo -e "\n6. Check if packages were installed correctly:"
if [ -f "install/setup.bash" ]; then
    source install/setup.bash
    echo "Available packages:"
    ros2 pkg list | grep -E "(swarm_msgs|swarm_controller)"
else
    echo "❌ install/setup.bash not found"
fi

echo -e "\n7. Check colcon build logs:"
if [ -d "log" ]; then
    echo "Latest build logs:"
    find log -name "*.log" -newer log 2>/dev/null | head -5
else
    echo "❌ log directory not found"
fi