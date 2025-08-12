#!/bin/bash
# Install all required dependencies

set -e

echo "Installing ROS2 Swarm Competition Dependencies..."

# Update system packages
sudo apt update

# Install ROS2 Humble if not present
if ! command -v ros2 &> /dev/null; then
    echo "Installing ROS2 Humble..."
    sudo apt install -y software-properties-common
    sudo add-apt-repository universe
    sudo apt update && sudo apt install -y curl
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
    sudo apt update
    sudo apt install -y ros-humble-desktop
    sudo apt install -y python3-argcomplete python3-colcon-common-extensions
fi

# Install Gazebo Fortress with proper setup
echo "Installing Gazebo Fortress..."
sudo apt-get update
sudo apt-get install -y lsb-release wget gnupg

# Add Gazebo repository
sudo wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null

sudo apt-get update

# Install Gazebo Fortress specifically  
sudo apt-get install -y gz-fortress

# Install ROS-Gazebo bridge for Humble and Fortress
sudo apt install -y ros-humble-ros-gz-bridge ros-humble-ros-gz-sim ros-humble-ros-gz

# Install additional ROS packages
sudo apt install -y \
    ros-humble-tf2-tools \
    ros-humble-tf2-geometry-msgs \
    ros-humble-rviz2 \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-xacro \
    ros-humble-gazebo-ros-pkgs

# Install Python dependencies
echo "Installing Python dependencies..."
if [ -f "requirements.txt" ]; then
    pip3 install -r requirements.txt
else
    # Fallback - install essential packages
    pip3 install numpy scipy matplotlib opencv-python transforms3d pandas pyyaml psutil
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
echo "1. Source ROS2: source /opt/ros/humble/setup.bash"
echo "2. Build project: ./build_project.sh"  
echo "3. Run competition: ./run_competition.sh"