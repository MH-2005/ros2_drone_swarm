#!/bin/bash
# Fix RMW implementation issues

echo "Fixing RMW Implementation Issues..."

# 1. Install correct RMW implementation
echo "Installing RMW CycloneDX implementation..."
sudo apt update
sudo apt install -y ros-humble-rmw-cyclonedx-cpp

# 2. Also install Fastrtps as backup
echo "Installing RMW FastRTPS implementation..."
sudo apt install -y ros-humble-rmw-fastrtps-cpp

# 3. Check available RMW implementations
echo "Available RMW implementations:"
ros2 doctor --report | grep rmw || echo "ros2 doctor not working, checking manually..."

# 4. Set environment variable correctly
echo "Setting RMW_IMPLEMENTATION environment variable..."
export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp

# Verify installation
if [ -f "/opt/ros/humble/lib/librmw_cyclonedx_cpp.so" ]; then
    echo "✅ CycloneDX implementation installed correctly"
elif [ -f "/opt/ros/humble/lib/librmw_fastrtps_cpp.so" ]; then
    echo "✅ FastRTPS implementation found, switching to it"
    export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
else
    echo "❌ No RMW implementation found"
    exit 1
fi

# 5. Update the run script
echo "Updating run_competition.sh with correct RMW..."
sed -i 's/export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp/export RMW_IMPLEMENTATION=rmw_fastrtps_cpp/' run_competition.sh

echo "✅ RMW implementation fixed!"
echo ""
echo "Now run:"
echo "source /opt/ros/humble/setup.bash"
echo "export RMW_IMPLEMENTATION=rmw_fastrtps_cpp"
echo "./run_competition.sh"