#!/bin/bash
#
# ZSH-compatible script for the full drone swarm competition run.
#

# Force bash mode even if called from zsh
if [ -n "$ZSH_VERSION" ]; then
    echo "⚠️  ZSH detected. Switching to bash for ROS compatibility..."
    exec bash "$0" "$@"
    exit
fi

set -e

echo "==========================================="
echo "   ROS 2 Swarm Competition - Shahin Team"
echo "==========================================="

# --- Helper Functions ---

check_prerequisites() {
    # Check if the ROS environment has been sourced.
    if [ -z "$ROS_DISTRO" ]; then
        echo "❌  ERROR: ROS environment not sourced!"
        echo "Please source your ROS 2 installation first. Example:"
        echo "source /opt/ros/jazzy/setup.bash"
        exit 1
    fi
    echo "✅  ROS $ROS_DISTRO environment is active."

    # Check if Gazebo is installed and available in the path.
    if ! command -v gz &> /dev/null; then
        echo "❌  ERROR: Gazebo (gz sim) not found."
        echo "Please ensure Gazebo is installed correctly."
        exit 1
    fi
    echo "✅  Gazebo installation found."
}

cleanup_processes() {
    echo "🧹  Cleaning up previous processes..."
    killall -9 gz gzserver gzclient &>/dev/null || true
    pkill -f "ros2" &>/dev/null || true
    sleep 2
}

source_workspace() {
    echo "🔗  Sourcing the local workspace..."
    if [ -f "install/setup.bash" ]; then
        source install/setup.bash
        echo "✅  Local workspace sourced successfully."
    else
        echo "❌  ERROR: install/setup.bash not found!"
        echo "Make sure you've built the workspace first with: ./build_project.sh"
        exit 1
    fi
}

# --- Main Execution Logic ---
main() {
    check_prerequisites
    cleanup_processes
    source_workspace

    echo "🚀  Launching simulation..."
    
    # Launch with explicit bash environment
    SHELL=/bin/bash ros2 launch swarm_controller run_competition.launch.py \
        record_video:=false \
        use_sim_time:=true \
        headless:=false &

    LAUNCH_PID=$!

    trap 'echo "🛑  Stopping simulation..."; kill $LAUNCH_PID &>/dev/null; cleanup_processes' EXIT INT TERM

    echo "✅  Simulation is running (PID: $LAUNCH_PID). Press Ctrl+C to stop."

    # Wait for the launch process to complete.
    wait $LAUNCH_PID
}

main "$@"