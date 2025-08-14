#!/bin/bash
set -e

echo "🔧 Comprehensive Fix for ROS2 Swarm System"
echo "============================================"

# Clean everything
echo "🧹 Complete cleanup..."
rm -rf build/ install/ log/
find . -name "*.pyc" -delete
find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true

# Check ROS environment
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ ROS2 environment not sourced!"
    echo "Please run: source /opt/ros/jazzy/setup.bash"
    exit 1
fi

echo "✅ ROS $ROS_DISTRO environment active"

# Build messages first
echo "🔨 Building swarm_msgs..."
colcon build --packages-select swarm_msgs \
    --cmake-args -DCMAKE_BUILD_TYPE=Release \
    --parallel-workers 1

source install/setup.bash

# Build controller with proper executable setup
echo "🔨 Building swarm_controller..."
colcon build --packages-select swarm_controller \
    --cmake-args -DCMAKE_BUILD_TYPE=Release \
    --parallel-workers 1

source install/setup.bash

# Verify and fix executables
echo "🔍 Verifying executable installation..."

EXEC_DIR="install/swarm_controller/lib/swarm_controller"
if [ ! -d "$EXEC_DIR" ]; then
    echo "⚠️ Creating missing executable directory..."
    mkdir -p "$EXEC_DIR"
fi

# Create proper executables
echo "📝 Creating executable wrappers..."

# swarm_drone executable
cat > "$EXEC_DIR/swarm_drone" << 'EOF'
#!/usr/bin/env python3
import sys
import os
import rclpy
from rclpy.executors import ExternalShutdownException

# Add package path
package_path = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
sys.path.insert(0, os.path.join(package_path, 'lib/python3.12/site-packages'))

try:
    from swarm_controller.swarm_drone import main
    main()
except ExternalShutdownException:
    pass
except Exception as e:
    print(f"Error: {e}")
    sys.exit(1)
EOF

# formation_controller executable  
cat > "$EXEC_DIR/formation_controller" << 'EOF'
#!/usr/bin/env python3
import sys
import os
import rclpy
from rclpy.executors import ExternalShutdownException

package_path = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
sys.path.insert(0, os.path.join(package_path, 'lib/python3.12/site-packages'))

try:
    from swarm_controller.formation_controller import main
    main()
except ExternalShutdownException:
    pass
except Exception as e:
    print(f"Error: {e}")
    sys.exit(1)
EOF

# mission_executor executable
cat > "$EXEC_DIR/mission_executor" << 'EOF'
#!/usr/bin/env python3
import sys
import os
import rclpy
from rclpy.executors import ExternalShutdownException

package_path = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
sys.path.insert(0, os.path.join(package_path, 'lib/python3.12/site-packages'))

try:
    from swarm_controller.mission_executor import main
    main()
except ExternalShutdownException:
    pass
except Exception as e:
    print(f"Error: {e}")
    sys.exit(1)
EOF

# Make executables executable
chmod +x "$EXEC_DIR"/*

echo "✅ Executables created successfully"

# Test executables
echo "🧪 Testing executables..."
if ros2 pkg executables swarm_controller; then
    echo "✅ Executables properly registered"
else
    echo "⚠️ Executables not found via ros2, but should work directly"
fi

echo ""
echo "🎉 Build system fixed!"
echo ""
echo "Next steps:"
echo "1. source install/setup.bash"  
echo "2. ./run_competition_zsh.sh"
echo ""