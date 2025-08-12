#!/bin/bash
# Fix RMW implementation issues

echo "Fixing RMW Implementation Issues..."

# Detect ROS version
if [ -z "$ROS_DISTRO" ]; then
    source /opt/ros/*/setup.$([ -n "$ZSH_VERSION" ] && echo "zsh" || echo "bash")
fi

echo "ROS2 Distribution: $ROS_DISTRO"

# Install FastRTPS as the default RMW
echo "Installing RMW FastRTPS implementation..."
sudo apt install -y ros-$ROS_DISTRO-rmw-fastrtps-cpp

# Check available RMW implementations
echo "Available RMW implementations:"
ros2 doctor --report | grep rmw || echo "ros2 doctor not working, checking manually..."

# Set environment variable
echo "Setting RMW_IMPLEMENTATION environment variable..."
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp

# Verify installation
if [ -f "/opt/ros/$ROS_DISTRO/lib/librmw_fastrtps_cpp.so" ]; then
    echo "✅ FastRTPS implementation installed correctly"
else
    echo "❌ No RMW implementation found"
    exit 1
fi

# Update run script if it exists
if [ -f "run_competition.sh" ]; then
    echo "Updating run_competition.sh with correct RMW..."
    sed -i "s/export RMW_IMPLEMENTATION=.*/export RMW_IMPLEMENTATION=rmw_fastrtps_cpp/" run_competition.sh
fi

echo "✅ RMW implementation fixed!"
echo ""
echo "Now run:"
echo "source /opt/ros/$ROS_DISTRO/setup.$([ -n "$ZSH_VERSION" ] && echo "zsh" || echo "bash")"
echo "export RMW_IMPLEMENTATION=rmw_fastrtps_cpp"
echo "./run_competition.sh"