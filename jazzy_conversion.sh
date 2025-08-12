#!/bin/bash
# Convert project from Humble to Jazzy

echo "=== تبدیل پروژه از Humble به Jazzy ==="

# 1. Update package.xml files
echo "1. بروزرسانی package.xml..."
find . -name "package.xml" -exec sed -i 's/ros-humble/ros-jazzy/g' {} \;

# 2. Update dependencies for Jazzy
echo "2. بروزرسانی dependencies..."

# Install Jazzy packages
sudo apt update
sudo apt install -y \
  ros-jazzy-desktop \
  ros-jazzy-gazebo-ros-pkgs \
  ros-jazzy-ros-gz-bridge \
  ros-jazzy-ros-gz-sim \
  ros-jazzy-tf2-tools \
  ros-jazzy-tf2-geometry-msgs \
  ros-jazzy-rviz2 \
  ros-jazzy-robot-state-publisher \
  ros-jazzy-joint-state-publisher \
  ros-jazzy-xacro

# 3. Install Gazebo Harmonic (for Jazzy)
echo "3. نصب Gazebo Harmonic..."
sudo wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
sudo apt update
sudo apt install -y gz-harmonic

# 4. Update environment setup
echo "4. تنظیم محیط جدید..."
cat >> ~/.bashrc << 'EOF'

# ROS2 Jazzy Setup
source /opt/ros/jazzy/setup.bash
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
export GZ_VERSION=harmonic
EOF

source ~/.bashrc

# 5. Update launch files for Jazzy compatibility
echo "5. بروزرسانی launch files..."
# Gazebo Harmonic uses different commands
sed -i 's/gz-fortress/gz-harmonic/g' src/swarm_controller/launch/*.py
sed -i 's/fortress/harmonic/g' src/swarm_controller/launch/*.py

# 6. Create Jazzy-specific requirements
cat > requirements_jazzy.txt << 'EOF'
# Python dependencies for ROS2 Jazzy
numpy>=1.21.0
scipy>=1.7.0
matplotlib>=3.5.0
opencv-python>=4.5.0
transforms3d>=0.4.1
pyyaml>=6.0
pandas>=1.3.0
psutil>=5.8.0
EOF

echo "✅ تبدیل به Jazzy تکمیل شد!"
echo ""
echo "مراحل بعدی:"
echo "1. source /opt/ros/jazzy/setup.bash"
echo "2. colcon build"
echo "3. source install/setup.bash"
echo "4. ./run_competition.sh"