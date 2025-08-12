#!/bin/bash
# Fix RMW implementation issues

set -e

# Helper function for shell detection
detect_shell_and_setup() {
    local setup="bash"
    
    if [ -n "$ZSH_VERSION" ]; then
        setup="zsh"
    elif [ -n "$BASH_VERSION" ]; then
        setup="bash"
    else
        case "$SHELL" in
            */zsh) setup="zsh" ;;
            */bash) setup="bash" ;;
            */sh) setup="sh" ;;
            *) echo "Warning: Unknown shell, defaulting to bash" ;;
        esac
    fi
    
    if [ ! -f "/opt/ros/$ROS_DISTRO/setup.${setup}" ]; then
        for shell_type in "zsh" "bash" "sh"; do
            if [ -f "/opt/ros/$ROS_DISTRO/setup.${shell_type}" ]; then
                setup="${shell_type}"
                break
            fi
        done
    fi
    
    echo "setup.${setup}"
}

echo "Fixing RMW Implementation Issues..."

# Detect ROS version and shell
SETUP_FILE=$(detect_shell_and_setup)
if [ -z "$ROS_DISTRO" ]; then
    source /opt/ros/*/setup.${SETUP_FILE}
fi

echo "ROS2 Distribution: $ROS_DISTRO"
echo "Using shell setup: $SETUP_FILE"

# Install FastRTPS
echo "Installing RMW FastRTPS implementation..."
sudo apt update
sudo apt install -y ros-$ROS_DISTRO-rmw-fastrtps-cpp

# Verify installation
if [ -f "/opt/ros/$ROS_DISTRO/lib/librmw_fastrtps_cpp.so" ]; then
    echo "✅ FastRTPS implementation installed correctly"
else
    echo "❌ No RMW implementation found"
    exit 1
fi

# Set environment variable in shell config
SHELL_CONFIG="$HOME/.$(basename $SHELL)rc"
if [ -f "$SHELL_CONFIG" ]; then
    if ! grep -q "RMW_IMPLEMENTATION" "$SHELL_CONFIG"; then
        echo "" >> "$SHELL_CONFIG"
        echo "# ROS2 RMW Configuration" >> "$SHELL_CONFIG"
        echo "export RMW_IMPLEMENTATION=rmw_fastrtps_cpp" >> "$SHELL_CONFIG"
    fi
fi

# Export for current session
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp

echo "✅ RMW implementation fixed!"
echo ""
echo "Changes made:"
echo "1. Installed FastRTPS"
echo "2. Set RMW_IMPLEMENTATION in shell config"
echo "3. Exported variable for current session"
echo ""
echo "Please run:"
echo "source $SHELL_CONFIG"
echo "./run_competition.sh"