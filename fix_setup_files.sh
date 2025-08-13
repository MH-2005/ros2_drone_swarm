#!/bin/bash

echo "🔧 Fixing ROS2 Setup Files"
echo "=========================="

# Check current status
echo "1. Current install directory:"
ls -la install/

echo -e "\n2. Check what's trying to source local_setup files:"
if [ -f "install/setup.bash" ]; then
    echo "Found install/setup.bash, checking its content:"
    head -20 install/setup.bash
    echo "..."
    tail -10 install/setup.bash
fi

echo -e "\n3. Checking if executables are actually installed:"
find install -name "*swarm*" -type f -executable 2>/dev/null || echo "No swarm executables found"

echo -e "\n4. Checking Python site-packages installation:"
find install -path "*/site-packages/swarm_controller*" -type d 2>/dev/null || echo "swarm_controller not in site-packages"

echo -e "\n5. Looking for entry_points.txt:"
find install -name "entry_points.txt" -exec cat {} \; 2>/dev/null || echo "No entry_points.txt found"

echo -e "\n6. Check bin directory:"
if [ -d "install/swarm_controller/bin" ]; then
    echo "✅ bin directory exists:"
    ls -la install/swarm_controller/bin/
else
    echo "❌ bin directory not found"
fi

# Create missing local_setup files if they don't exist
echo -e "\n7. Creating missing setup files..."

# Create root local_setup.bash
cat > local_setup.bash << 'EOF'
# Generated local setup file
# This file should not normally be needed, but ROS seems to be looking for it

# Nothing to setup at workspace root level
# All setup is handled in install/setup.bash
EOF

# Create root local_setup.sh
cat > local_setup.sh << 'EOF'
# Generated local setup file  
# This file should not normally be needed, but ROS seems to be looking for it

# Nothing to setup at workspace root level
# All setup is handled in install/setup.sh
EOF

echo "✅ Created missing local_setup files"

# Try to fix the executable installation
echo -e "\n8. Checking setuptools installation method..."
if [ -f "src/swarm_controller/setup.py" ]; then
    echo "Current setup.py entry_points:"
    grep -A 10 "entry_points" src/swarm_controller/setup.py
    
    echo -e "\nTrying manual executable installation..."
    cd src/swarm_controller
    python3 setup.py develop --user 2>/dev/null || echo "Manual install failed"
    cd ../..
fi

echo -e "\n9. Final verification:"
source install/setup.bash 2>/dev/null
if command -v ros2 >/dev/null; then
    echo "ROS2 available, checking packages:"
    ros2 pkg list | grep swarm || echo "No swarm packages found"
    echo "Checking executables:"
    ros2 pkg executables swarm_controller 2>/dev/null || echo "No executables found"
fi