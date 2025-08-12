#!/bin/bash
# Install all required dependencies

set -e

echo "Installing ROS2 Swarm Competition Dependencies..."

# Update system packages
sudo apt update

# Detect ROS_DISTRO if not set
if [ -z "$ROS_DISTRO" ]; then
    if [ -d "/opt/ros/humble" ]; then
        export ROS_DISTRO="humble"
    elif [ -d "/opt/ros/iron" ]; then
        export ROS_DISTRO="iron"
    elif [ -d "/opt/ros/jazzy" ]; then
        export ROS_DISTRO="jazzy"
    else
        echo "Error: No ROS2 installation found"
        exit 1
    fi
fi

echo "Detected ROS2 distribution: $ROS_DISTRO"

# Install ROS2 if not present
if ! command -v ros2 &> /dev/null; then
    echo "Installing ROS2 $ROS_DISTRO..."
    sudo apt install -y software-properties-common
    sudo add-apt-repository universe
    sudo apt update && sudo apt install -y curl
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
    sudo apt update
    sudo apt install -y ros-$ROS_DISTRO-desktop
    sudo apt install -y python3-argcomplete python3-colcon-common-extensions
fi

# Detect shell type and set appropriate setup file
if [ -n "$ZSH_VERSION" ]; then
    SETUP_FILE="setup.zsh"
else
    SETUP_FILE="setup.bash"
fi

# Install Gazebo (version depends on ROS distro)
echo "Installing Gazebo..."
if [ "$ROS_DISTRO" = "humble" ]; then
    sudo apt install -y gz-fortress
elif [ "$ROS_DISTRO" = "iron" ] || [ "$ROS_DISTRO" = "jazzy" ]; then
    sudo apt install -y gz-harmonic
fi

# Install ROS-Gazebo bridge
sudo apt install -y ros-$ROS_DISTRO-ros-gz-bridge ros-$ROS_DISTRO-ros-gz-sim

# Install additional ROS packages
sudo apt install -y \
    ros-$ROS_DISTRO-tf2-tools \
    ros-$ROS_DISTRO-tf2-geometry-msgs \
    ros-$ROS_DISTRO-rviz2 \
    ros-$ROS_DISTRO-robot-state-publisher \
    ros-$ROS_DISTRO-joint-state-publisher \
    ros-$ROS_DISTRO-xacro

# Install Python dependencies from updated requirements
echo "Installing Python dependencies..."
if [ -f "requirements.txt" ]; then
    pip3 install -r requirements.txt
else
    # Fallback - install essential packages
    pip3 install numpy>=1.21.0 scipy>=1.7.0 matplotlib>=3.5.0 \
                opencv-python>=4.5.0 transforms3d>=0.4.1 pyyaml>=6.0 \
                pandas>=1.3.0 psutil>=5.8.0
fi

# Install video recording tools
sudo apt install -y ffmpeg v4l-utils

# Verify installations
echo ""
echo "Verifying installations..."
echo "ROS2 version: $(ros2 --version 2>/dev/null || echo 'Not found')"
echo "Gazebo version: $(gz sim --version 2>/dev/null || echo 'Not found')"
echo "Python version: $(python3 --version)"
echo "FFmpeg version: $(ffmpeg -version 2>/dev/null | head -n1 || echo 'Not found')"

echo ""
echo "✅ Dependencies installation completed!"
echo ""
echo "Next steps:"
echo "1. Source ROS2: source /opt/ros/$ROS_DISTRO/$SETUP_FILE"
echo "2. Build project: ./build_project.sh"
echo "3. Run competition: ./run_competition.sh"