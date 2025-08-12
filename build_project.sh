#!/bin/bash
# Enhanced build script with better error handling and validation

set -e

echo "🚁 Building ROS2 Swarm Competition Project..."
echo "=============================================="

# Color codes for better output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Helper function for colored output
print_status() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️  $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

# Check prerequisites
check_prerequisites() {
    echo "Checking prerequisites..."
    
    # Check if ROS2 is sourced
    if [ -z "$ROS_DISTRO" ]; then
        print_error "ROS2 environment not sourced!"
        echo "Please run: source /opt/ros/jazzy/setup.bash"
        exit 1
    fi
    print_status "ROS2 $ROS_DISTRO environment detected"
    
    # Check for required commands
    if ! command -v colcon &> /dev/null; then
        print_error "colcon not found!"
        echo "Please install: sudo apt install python3-colcon-common-extensions"
        exit 1
    fi
    print_status "colcon build system available"
    
    if ! command -v gz &> /dev/null; then
        print_warning "Gazebo (gz) not found in PATH"
        echo "Make sure Gazebo Harmonic is installed"
    else
        print_status "Gazebo installation found"
    fi
    
    echo ""
}

# Validate package structure
validate_structure() {
    echo "Validating package structure..."
    
    required_files=(
        "src/swarm_msgs/package.xml"
        "src/swarm_msgs/CMakeLists.txt" 
        "src/swarm_controller/package.xml"
        "src/swarm_controller/setup.py"
        "src/swarm_controller/swarm_controller/swarm_drone.py"
        "src/swarm_controller/swarm_controller/formation_controller.py"
        "src/swarm_controller/swarm_controller/mission_executor.py"
        "src/swarm_controller/launch/run_competition.launch.py"
        "src/swarm_controller/worlds/swarm_arena.world"
        "src/swarm_controller/config/swarm_params.yaml"
        "leader_path.csv"
    )
    
    missing_files=0
    for file in "${required_files[@]}"; do
        if [ ! -f "$file" ]; then
            print_error "Missing required file: $file"
            missing_files=$((missing_files + 1))
        fi
    done
    
    if [ $missing_files -gt 0 ]; then
        print_error "$missing_files required files are missing!"
        exit 1
    fi
    
    print_status "All required files present"
    echo ""
}

# Create models directory structure
create_model_structure() {
    echo "Creating model directory structure..."
    
    # Create models directory
    mkdir -p src/swarm_controller/models/x500
    
    # Check if model.sdf exists
    if [ ! -f "src/swarm_controller/models/x500/model.sdf" ]; then
        print_warning "model.sdf not found, you need to create it"
        echo "A template will be created in the models directory"
        
        # Create basic model.sdf template
        cat > src/swarm_controller/models/x500/model.sdf << 'EOF'
<?xml version="1.0" ?>
<sdf version="1.8">
  <model name="x500">
    <pose>0 0 0.194 0 0 0</pose>
    <!-- Model content will be provided separately -->
  </model>
</sdf>
EOF
    fi
    
    print_status "Model structure created"
}

# Clean previous builds
clean_build() {
    echo "Cleaning previous builds..."
    
    rm -rf build/ install/ log/
    find . -name "*.pyc" -delete
    find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true
    
    print_status "Build environment cleaned"
    echo ""
}

# Build packages
build_packages() {
    echo "Building packages with colcon..."
    
    # Build with verbose output and symlink install
    if colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release; then
        print_status "Build completed successfully!"
    else
        print_error "Build failed!"
        exit 1
    fi
    
    echo ""
}

# Source the built workspace
source_workspace() {
    echo "Sourcing workspace..."
    
    if [ -f "install/setup.bash" ]; then
        source install/setup.bash
        print_status "Workspace sourced successfully"
    else
        print_error "install/setup.bash not found!"
        exit 1
    fi
    
    echo ""
}

# Validate build
validate_build() {
    echo "Validating build..."
    
    # Check if custom messages are available
    if ros2 interface show swarm_msgs/msg/DroneState &>/dev/null; then
        print_status "Custom messages built correctly"
    else
        print_error "Custom messages not built correctly"
        exit 1
    fi
    
    # Check if executables are available
    executables=("swarm_drone" "formation_controller" "mission_executor")
    for exe in "${executables[@]}"; do
        if ros2 pkg executables swarm_controller | grep -q "$exe"; then
            print_status "Executable '$exe' available"
        else
            print_error "Executable '$exe' not found"
            exit 1
        fi
    done
    
    echo ""
}

# Show final information
show_final_info() {
    echo "================================================"
    echo "🎉 Build completed successfully!"
    echo "================================================"
    echo ""
    echo "Next steps:"
    echo "1. Make sure Gazebo Harmonic is installed"
    echo "2. Source the workspace: source install/setup.bash"
    echo "3. Run competition: ./run_competition.sh"
    echo ""
    echo "Available commands:"
    echo "• ros2 launch swarm_controller run_competition.launch.py"
    echo "• ./runtime_commands.sh help"
    echo ""
    echo "Package info:"
    echo "• Messages: $(ros2 pkg executables swarm_msgs 2>/dev/null | wc -l) interfaces"
    echo "• Executables: $(ros2 pkg executables swarm_controller 2>/dev/null | wc -l) nodes"
    echo "• Launch files: $(find src/swarm_controller/launch -name "*.launch.py" | wc -l) files"
    echo ""
}

# Main execution
main() {
    check_prerequisites
    validate_structure
    create_model_structure
    clean_build
    build_packages
    source_workspace
    validate_build
    show_final_info
}

# Error handling
trap 'print_error "Build script failed at line $LINENO"' ERR

# Run main function
main "$@"