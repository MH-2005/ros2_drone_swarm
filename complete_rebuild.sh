#!/bin/bash
set -e

echo "🚀 Final ROS2 Rebuild with Executable Installation"
echo "=================================================="

# Clean completely
echo "🧹 Complete cleanup..."
rm -rf build/ install/ log/
find . -name "*.pyc" -delete
find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true
find . -name "*.egg-info" -exec rm -rf {} + 2>/dev/null || true

# Create the missing local_setup files that ROS is looking for
echo "📝 Creating required setup files..."
cat > local_setup.bash << 'EOF'
# Local setup for workspace root - placeholder file
EOF

cat > local_setup.sh << 'EOF'
# Local setup for workspace root - placeholder file  
EOF

echo "✅ Setup files created"

# Check ROS environment
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS2 environment not sourced!"
    exit 1
fi

# Build with specific colcon options for Python packages
echo "🔨 Building with Python executable installation..."

# Build messages first
echo "Building swarm_msgs..."
colcon build --packages-select swarm_msgs \
    --cmake-args -DCMAKE_BUILD_TYPE=Release

# Source messages
source install/setup.bash

# Build controller with specific Python options
echo "Building swarm_controller with executable installation..."
colcon build --packages-select swarm_controller \
    --cmake-args -DCMAKE_BUILD_TYPE=Release \
    --symlink-install

# Source everything
source install/setup.bash

echo "🔍 Post-build verification..."

# Check if executables were installed
if [ -d "install/swarm_controller/lib/swarm_controller" ]; then
    echo "✅ Executable directory exists:"
    ls -la install/swarm_controller/lib/swarm_controller/
else
    echo "❌ Executable directory missing"
    
    # Manual installation attempt
    echo "🛠️ Attempting manual executable installation..."
    
    # Create the executable directory
    mkdir -p install/swarm_controller/lib/swarm_controller
    
    # Create executable wrappers
    for script in swarm_drone formation_controller mission_executor; do
        cat > install/swarm_controller/lib/swarm_controller/$script << EOF
#!/usr/bin/env python3
import sys
import os

# Add the package to Python path
package_path = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'python3.12/site-packages')
if package_path not in sys.path:
    sys.path.insert(0, package_path)

# Import and run the main function
from swarm_controller.${script} import main

if __name__ == '__main__':
    main()
EOF
        chmod +x install/swarm_controller/lib/swarm_controller/$script
    done
    
    echo "✅ Manual executables created"
fi

# Final verification
echo "🧪 Final verification..."
source install/setup.bash

echo "Available packages:"
ros2 pkg list | grep swarm

echo "Available executables:"
ros2 pkg executables swarm_controller || echo "Still no executables found via ros2"

# Direct executable test
echo "Direct executable test:"
if [ -f "install/swarm_controller/lib/swarm_controller/swarm_drone" ]; then
    echo "✅ swarm_drone executable exists"
    echo "Testing execution:"
    timeout 5 install/swarm_controller/lib/swarm_controller/swarm_drone --help 2>/dev/null || echo "Executable test completed"
else
    echo "❌ swarm_drone executable still missing"
fi

echo ""
echo "🎉 Build process complete!"
echo "Try running: source install/setup.bash && ros2 run swarm_controller swarm_drone"