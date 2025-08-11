#!/bin/bash
# Main competition execution script

set -e

echo "==========================================="
echo "ROS2 Swarm Drone Competition - Full Run"
echo "==========================================="

# Check environment
if [ -z "$ROS_DISTRO" ]; then
    echo "Error: ROS2 not sourced. Please run: source /opt/ros/humble/setup.bash"
    exit 1
fi

# Clean up any zombie processes
echo "Cleaning up..."
killall -9 gzserver gzclient ign gazebo &>/dev/null || true
pkill -f ros2 &>/dev/null || true

# Build the workspace
echo "Building ROS2 workspace..."
colcon build --symlink-install

# Source the workspace
source install/setup.bash

echo "Starting competition simulation..."

# Create necessary directories
mkdir -p videos
mkdir -p logs

# Set environment variables
export IGN_GAZEBO_RESOURCE_PATH=$(pwd)/worlds:$(pwd)/models:${IGN_GAZEBO_RESOURCE_PATH}
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

# Launch the simulation
echo "Launching swarm simulation with all phases..."
ros2 launch swarm_controller run_competition.launch.py \
    record_video:=true \
    use_sim_time:=true \
    headless:=false 2>&1 | tee logs/competition_run.log &

LAUNCH_PID=$!

# Cleanup function
cleanup() {
    echo "Cleaning up..."
    kill $LAUNCH_PID 2>/dev/null || true
    killall -9 gzserver gzclient ign gazebo &>/dev/null || true
    pkill -f ros2 &>/dev/null || true
    echo "Cleanup complete"
}

trap cleanup EXIT

echo "Simulation running... Press Ctrl+C to stop"
echo "Videos: ./videos/ | Logs: ./logs/"

wait $LAUNCH_PID

echo "Competition run completed!"