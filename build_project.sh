#!/bin/bash
# Build complete swarm competition project

set -e

echo "Building ROS2 Swarm Competition Project..."

# Check prerequisites
if [ -z "$ROS_DISTRO" ]; then
    echo "Error: Please source ROS2 first: source /opt/ros/humble/setup.bash"
    exit 1
fi

# Clean previous builds from the workspace root
echo "Cleaning previous builds..."
rm -rf build/
rm -rf install/
rm -rf log/

echo "Building all packages from workspace root..."
# Run colcon build from the root, not from inside src
colcon build --symlink-install

# Source the built workspace
echo "Sourcing the workspace..."
source install/setup.bash

echo ""
echo "Build completed successfully!"
echo ""
echo "To run the competition:"
echo "1. source install/setup.bash"
echo "2. ./run_competition.sh"
echo ""
echo "Or use launch file directly:"
echo "ros2 launch swarm_controller run_competition.launch.py"