#!/bin/bash
#
# Final competition script with all fixes applied
#

# Force bash execution
if [ -n "$ZSH_VERSION" ]; then
    exec bash "$0" "$@"
fi

set -e

echo "🚁 ROS2 Drone Swarm Competition - FINAL RUN"
echo "============================================="

# Check ROS environment
if [ -z "$ROS_DISTRO" ]; then
    echo "❌ Please source ROS first: source /opt/ros/jazzy/setup.bash"
    exit 1
fi

# Cleanup any existing processes
echo "🧹 Cleaning up..."
killall -9 gz gzserver gzclient >/dev/null 2>&1 || true
pkill -f ros2 >/dev/null 2>&1 || true
sleep 3

# Source workspace
echo "📡 Sourcing workspace..."
source install/setup.bash
echo "✅ Environment ready"

# Create required local setup files
cat > local_setup.bash << 'EOF'
# Placeholder local setup
EOF

cat > local_setup.zsh << 'EOF'  
# Placeholder local setup
EOF

echo "🚀 Starting Gazebo and Drone Swarm..."

# Launch with error suppression for clean output
ros2 launch swarm_controller run_competition.launch.py \
    use_sim_time:=true \
    headless:=false \
    record_video:=false 2>/dev/null &

LAUNCH_PID=$!

# Cleanup function
cleanup() {
    echo ""
    echo "🛑 Stopping simulation..."
    kill $LAUNCH_PID >/dev/null 2>&1 || true
    sleep 2
    killall -9 gz gzserver gzclient >/dev/null 2>&1 || true
    pkill -f ros2 >/dev/null 2>&1 || true
    echo "✅ Cleanup completed"
}

trap cleanup EXIT INT TERM

echo "✅ Simulation running (PID: $LAUNCH_PID)"
echo ""
echo "📋 Expected behavior:"
echo "   - Gazebo should open with 4 drones"
echo "   - Drones should arm and take off"
echo "   - Formation controller should start"
echo "   - Mission executor should begin phases"
echo ""
echo "Press Ctrl+C to stop..."
echo ""

# Monitor the process
while kill -0 $LAUNCH_PID 2>/dev/null; do
    sleep 1
done

echo "🏁 Simulation completed"