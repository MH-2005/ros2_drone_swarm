
#Install all required dependencies

echo "Installing ROS2 Swarm Competition Dependencies..."

# Update system
sudo apt update

# Install ROS2 Humble (if not already installed)
if ! command -v ros2 &> /dev/null; then
    echo "Installing ROS2 Humble..."
    sudo apt install -y software-properties-common
    sudo add-apt-repository universe
    sudo apt update && sudo apt install -y curl
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
    sudo apt update
    sudo apt install -y ros-humble-desktop ros-humble-ros-base
    sudo apt install -y python3-argcomplete python3-colcon-common-extensions
fi

# Install Gazebo Fortress
if ! command -v gz &> /dev/null; then
    echo "Installing Gazebo Fortress..."
    sudo apt-get update
    sudo apt-get install -y lsb-release wget gnupg
    sudo wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
    sudo apt-get update
    sudo apt-get install -y ignition-fortress
fi

# Install ROS-Gazebo bridge
sudo apt install -y ros-humble-ros-gz-bridge ros-humble-ros-gz-sim

# Install additional ROS packages
sudo apt install -y \
    ros-humble-tf2-tools \
    ros-humble-tf2-geometry-msgs \
    ros-humble-rviz2 \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-xacro

# Install Python dependencies
pip3 install -r requirements.txt

# Install video recording tools
sudo apt install -y ffmpeg v4l-utils