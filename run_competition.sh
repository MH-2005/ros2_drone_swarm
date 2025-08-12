#!/bin/bash
# Script for running complete swarm competition

set -e

echo "==========================================="
echo "ROS2 Swarm Competition - Complete Run"
echo "==========================================="

# Detect shell and ROS setup
if [ -n "$ZSH_VERSION" ]; then
    SETUP_FILE="setup.zsh"
else
    SETUP_FILE="setup.bash"
fi

# Check ROS2 environment
if [ -z "$ROS_DISTRO" ]; then
    echo "Error: ROS2 not sourced. Attempting to source..."
    source /opt/ros/*/setup.${SETUP_FILE}
fi

echo "Detected ROS2 $ROS_DISTRO environment ✓"

# Clean up previous processes
echo "Cleaning up previous processes..."
killall -9 gz gzserver gzclient ruby &>/dev/null || true
pkill -f "ros2" &>/dev/null || true
pkill -f "gazebo" &>/dev/null || true
sleep 3

# Build workspace
echo "Building ROS2 workspace..."
if ! colcon build --symlink-install; then
    echo "Error: Workspace build failed"
    exit 1
fi

# Source workspace
echo "Setting up workspace environment..."
source install/setup.${SETUP_FILE}

# Create required directories
echo "Creating output directories..."
mkdir -p videos logs

# Set Gazebo model path
export GZ_SIM_RESOURCE_PATH=$(pwd)/src/swarm_controller/worlds:$(pwd)/src/swarm_controller/models:${GZ_SIM_RESOURCE_PATH:-}

# Check Gazebo
if ! command -v gz &> /dev/null; then
    echo "Error: Gazebo not installed"
    echo "Please run: ./install_dependencies.sh"
    exit 1
fi

# Display system info
echo ""
echo "=== System Information ==="
echo "ROS Distribution: $ROS_DISTRO"
echo "Workspace Path: $(pwd)"
echo "Python Version: $(python3 --version)"
echo "Gazebo Version: $(gz sim --version 2>/dev/null || echo 'Unknown')"
echo ""

# Test ROS2 connection
echo "Testing ROS2..."
timeout 3 ros2 topic list &>/dev/null || {
    echo "Error: ROS2 daemon issue, restarting..."
    ros2 daemon stop &>/dev/null || true
    sleep 2
    ros2 daemon start &>/dev/null || true
    sleep 2
}

# Launch simulation
echo "🚀 Launching competition simulation..."
echo ""
echo "Important notes:"
echo "• Videos will be saved in ./videos/"
echo "• Logs will be saved in ./logs/"
echo "• Use Ctrl+C to stop"
echo "• If errors occur, stop with Ctrl+C and try again"
echo ""

# Launch with appropriate parameters
echo "Starting launch file..."
timeout 300 ros2 launch swarm_controller run_competition.launch.py \
    record_video:=true \
    use_sim_time:=true \
    headless:=false 2>&1 | tee logs/competition_run_$(date +%Y%m%d_%H%M%S).log &

LAUNCH_PID=$!

# Cleanup function
cleanup() {
    echo ""
    echo "🛑 Stopping simulation..."
    kill $LAUNCH_PID 2>/dev/null || true
    sleep 5
    killall -9 gz gzserver gzclient ruby &>/dev/null || true
    pkill -f "ros2" &>/dev/null || true
    echo "Cleanup complete ✓"
}

trap cleanup EXIT INT TERM

echo "Simulation running..."
echo "Press Ctrl+C to stop"
echo ""

# Wait for completion with timeout
wait $LAUNCH_PID 2>/dev/null || true

echo ""
echo "🎯 Competition run completed!"
echo ""
echo "Output files:"
if [ -d "videos" ]; then
    echo "  📹 Videos: $(ls videos/ 2>/dev/null | wc -l) files in ./videos/"
fi
if [ -d "logs" ]; then
    echo "  📄 Logs: $(ls logs/ 2>/dev/null | wc -l) files in ./logs/"
fi

echo ""
echo "To run again:"
echo "  ./run_competition.sh"