#!/bin/bash
#
# Final, optimized script for the full drone swarm competition run.
# This script handles environment setup, building, execution, and cleanup.
#

# Exit immediately if a command exits with a non-zero status.
set -e

# --- Helper Functions ---

# Detects the user's shell and sets the appropriate ROS setup file.
detect_shell() {
    if [ -n "$ZSH_VERSION" ]; then
        SETUP_FILE="setup.zsh"
    elif [ -n "$BASH_VERSION" ]; then
        SETUP_FILE="setup.bash"
    else
        # Fallback for other or unknown shells
        case "$(basename "$SHELL")" in
            zsh)  SETUP_FILE="setup.zsh" ;;
            bash) SETUP_FILE="setup.bash" ;;
            *)
                echo "⚠️  WARNING: Unknown shell. Defaulting to setup.bash."
                SETUP_FILE="setup.bash"
                ;;
        esac
    fi
    echo "✅  Shell detected. Using '${SETUP_FILE}' for setup."
}

# Verifies that all prerequisites are met before running.
check_prerequisites() {
    # Check if the ROS environment has been sourced.
    if [ -z "$ROS_DISTRO" ]; then
        echo "❌  ERROR: ROS environment not sourced."
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

# Cleans up any lingering processes from previous runs.
cleanup_processes() {
    echo "🧹  Cleaning up previous processes..."
    # The '|| true' prevents the script from exiting if no processes are found to kill.
    killall -9 gz gzserver gzclient &>/dev/null || true
    pkill -f "ros2" &>/dev/null || true
    sleep 2 # Brief pause to allow processes to terminate.
}

# Builds the colcon workspace.
build_workspace() {
    echo "🛠️  Building the workspace with colcon..."
    colcon build --symlink-install
    echo "✅  Workspace built successfully."
}

# Sources the local workspace to make packages available.
source_workspace() {
    echo "🔗  Sourcing the local workspace..."
    if [ -f "install/${SETUP_FILE}" ]; then
        source install/${SETUP_FILE}
        echo "✅  Local workspace sourced successfully."
    else
        echo "❌  ERROR: install/${SETUP_FILE} not found!"
        echo "Make sure you've built the workspace first with: ./build_project.sh"
        exit 1
    fi
}

# --- Main Execution Logic ---
main() {
    echo "==========================================="
    echo "   ROS 2 Swarm Competition - Shahin Team"
    echo "==========================================="
    
    # Run setup steps in order.
    detect_shell
    check_prerequisites
    cleanup_processes
    # build_workspace  # Commented out - assume already built
    source_workspace

    echo "🚀  Launching simulation..."
    
    # Launch the simulation in the background.
    # The output is piped to 'tee' to display on the terminal AND save to a log file.
    ros2 launch swarm_controller run_competition.launch.py \
        record_video:=true \
        use_sim_time:=true \
        headless:=false &

    # Store the Process ID (PID) of the launch command.
    LAUNCH_PID=$!

    # Set a trap to run the cleanup function on EXIT, INT, or TERM signals.
    # This ensures cleanup happens even if the script is interrupted (e.g., with Ctrl+C).
    trap 'echo "🛑  Stopping simulation..."; kill $LAUNCH_PID &>/dev/null; cleanup_processes' EXIT

    echo "✅  Simulation is running (PID: $LAUNCH_PID). Press Ctrl+C to stop."

    # Wait for the launch process to complete.
    wait $LAUNCH_PID
}

# --- Script Entry Point ---
main "$@"