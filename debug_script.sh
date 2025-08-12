#!/bin/bash
# Debug script for diagnosing swarm project issues

set -e

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_header() {
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE} $1 ${NC}"
    echo -e "${BLUE}========================================${NC}"
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️  $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

# Check ROS2 environment
check_ros_environment() {
    print_header "ROS2 Environment Check"
    
    if [ -z "$ROS_DISTRO" ]; then
        print_error "ROS2 not sourced!"
        echo "Run: source /opt/ros/jazzy/setup.bash"
        return 1
    else
        print_success "ROS2 $ROS_DISTRO detected"
    fi
    
    # Check RMW implementation
    if [ -z "$RMW_IMPLEMENTATION" ]; then
        print_warning "RMW_IMPLEMENTATION not set"
        echo "Consider: export RMW_IMPLEMENTATION=rmw_fastrtps_cpp"
    else
        print_success "RMW: $RMW_IMPLEMENTATION"
    fi
    
    echo ""
}

# Check Gazebo installation
check_gazebo() {
    print_header "Gazebo Check"
    
    if command -v gz &> /dev/null; then
        GZ_VERSION=$(gz --version 2>/dev/null | head -1 || echo "Unknown")
        print_success "Gazebo found: $GZ_VERSION"
        
        # Check for Harmonic specifically
        if gz --version | grep -q "harmonic\|garden"; then
            print_success "Compatible Gazebo version detected"
        else
            print_warning "Gazebo version may not be compatible"
            echo "This project requires Gazebo Harmonic"
        fi
    else
        print_error "Gazebo (gz) not found!"
        echo "Install: sudo apt install gz-harmonic"
        return 1
    fi
    
    echo ""
}

# Check workspace structure
check_workspace_structure() {
    print_header "Workspace Structure Check"
    
    # Check if we're in the right directory
    if [ ! -d "src" ]; then
        print_error "No 'src' directory found!"
        echo "Make sure you're in the workspace root"
        return 1
    fi
    
    # Check packages
    if [ -d "src/swarm_msgs" ]; then
        print_success "swarm_msgs package found"
    else
        print_error "swarm_msgs package missing"
    fi
    
    if [ -d "src/swarm_controller" ]; then
        print_success "swarm_controller package found"
    else
        print_error "swarm_controller package missing"
    fi
    
    # Check critical files
    critical_files=(
        "src/swarm_controller/swarm_controller/swarm_drone.py"
        "src/swarm_controller/swarm_controller/formation_controller.py"
        "src/swarm_controller/swarm_controller/mission_executor.py"
        "src/swarm_controller/launch/run_competition.launch.py"
        "src/swarm_controller/models/x500/model.sdf"
        "src/swarm_controller/worlds/swarm_arena.world"
        "leader_path.csv"
    )
    
    for file in "${critical_files[@]}"; do
        if [ -f "$file" ]; then
            print_success "Found: $(basename $file)"
        else
            print_error "Missing: $file"
        fi
    done
    
    echo ""
}

# Check Python dependencies
check_python_dependencies() {
    print_header "Python Dependencies Check"
    
    required_packages=("numpy" "scipy" "matplotlib" "transforms3d" "pyyaml" "pandas")
    
    for package in "${required_packages[@]}"; do
        if python3 -c "import $package" 2>/dev/null; then
            version=$(python3 -c "import $package; print($package.__version__)" 2>/dev/null || echo "unknown")
            print_success "$package ($version)"
        else
            print_error "$package not installed"
            echo "Install: pip3 install $package"
        fi
    done
    
    echo ""
}

# Check build status
check_build_status() {
    print_header "Build Status Check"
    
    if [ -d "build" ] && [ -d "install" ]; then
        print_success "Build directories exist"
        
        # Check if workspace is sourced
        if [ -f "install/setup.bash" ]; then
            print_success "install/setup.bash exists"
            
            # Source and check packages
            source install/setup.bash 2>/dev/null || true
            
            # Check if packages are available
            if ros2 pkg list | grep -q "swarm_msgs"; then
                print_success "swarm_msgs package registered"
            else
                print_error "swarm_msgs not found in package list"
            fi
            
            if ros2 pkg list | grep -q "swarm_controller"; then
                print_success "swarm_controller package registered"
            else
                print_error "swarm_controller not found in package list"
            fi
            
        else
            print_error "install/setup.bash missing"
            echo "Run: ./build_project.sh"
        fi
        
    else
        print_error "Project not built"
        echo "Run: ./build_project.sh"
    fi
    
    echo ""
}

# Check custom messages
check_custom_messages() {
    print_header "Custom Messages Check"
    
    if [ -f "install/setup.bash" ]; then
        source install/setup.bash 2>/dev/null || true
        
        messages=("DroneState" "FormationCommand")
        services=("ChangeFormation" "DisarmLeader") 
        actions=("ExecuteMission")
        
        for msg in "${messages[@]}"; do
            if ros2 interface show "swarm_msgs/msg/$msg" &>/dev/null; then
                print_success "Message: $msg"
            else
                print_error "Message missing: $msg"
            fi
        done
        
        for srv in "${services[@]}"; do
            if ros2 interface show "swarm_msgs/srv/$srv" &>/dev/null; then
                print_success "Service: $srv"
            else
                print_error "Service missing: $srv"
            fi
        done
        
        for action in "${actions[@]}"; do
            if ros2 interface show "swarm_msgs/action/$action" &>/dev/null; then
                print_success "Action: $action"
            else
                print_error "Action missing: $action"
            fi
        done
        
    else
        print_warning "Cannot check messages - workspace not built"
    fi
    
    echo ""
}

# Test launch file syntax
test_launch_file() {
    print_header "Launch File Test"
    
    if [ -f "src/swarm_controller/launch/run_competition.launch.py" ]; then
        if python3 -m py_compile src/swarm_controller/launch/run_competition.launch.py; then
            print_success "Launch file syntax OK"
        else
            print_error "Launch file has syntax errors"
        fi
    else
        print_error "Launch file not found"
    fi
    
    echo ""
}

# Network diagnostics
check_network() {
    print_header "Network Diagnostics"
    
    # Check if ROS_DOMAIN_ID is set
    if [ -n "$ROS_DOMAIN_ID" ]; then
        print_success "ROS_DOMAIN_ID: $ROS_DOMAIN_ID"
    else
        print_warning "ROS_DOMAIN_ID not set (using default: 0)"
    fi
    
    # Check localhost connectivity
    if ping -c 1 127.0.0.1 >/dev/null 2>&1; then
        print_success "Localhost connectivity OK"
    else
        print_error "Localhost connectivity failed"
    fi
    
    echo ""
}

# System resource check
check_system_resources() {
    print_header "System Resources"
    
    # Memory check
    mem_total=$(free -m | awk '/^Mem:/ {print $2}')
    mem_available=$(free -m | awk '/^Mem:/ {print $7}')
    
    if [ "$mem_total" -gt 4000 ]; then
        print_success "Memory: ${mem_total}MB total, ${mem_available}MB available"
    else
        print_warning "Low memory: ${mem_total}MB total"
    fi
    
    # Disk space check
    disk_available=$(df -BG . | awk 'NR==2 {print $4}' | sed 's/G//')
    
    if [ "$disk_available" -gt 5 ]; then
        print_success "Disk space: ${disk_available}GB available"
    else
        print_warning "Low disk space: ${disk_available}GB available"
    fi
    
    # CPU check
    cpu_cores=$(nproc)
    print_success "CPU cores: $cpu_cores"
    
    echo ""
}

# Provide solutions for common problems
suggest_solutions() {
    print_header "Common Solutions"
    
    echo "If you're having issues, try these steps:"
    echo ""
    echo "1. Environment setup:"
    echo "   source /opt/ros/jazzy/setup.bash"
    echo "   export RMW_IMPLEMENTATION=rmw_fastrtps_cpp"
    echo ""
    echo "2. Clean rebuild:"
    echo "   ./clean_build.sh"
    echo "   ./build_project.sh"
    echo ""
    echo "3. Install missing dependencies:"
    echo "   ./install_dependencies.sh"
    echo ""
    echo "4. Check Gazebo installation:"
    echo "   sudo apt install gz-harmonic"
    echo ""
    echo "5. Fix RMW issues:"
    echo "   ./fix_rmw.sh"
    echo ""
    echo "6. Validate package structure:"
    echo "   ./validate_package.sh"
    echo ""
}

# Main execution
main() {
    echo -e "${BLUE}🔧 ROS2 Swarm Project Diagnostics${NC}"
    echo ""
    
    check_ros_environment
    check_gazebo
    check_workspace_structure
    check_python_dependencies
    check_build_status
    check_custom_messages
    test_launch_file
    check_network
    check_system_resources
    suggest_solutions
    
    echo -e "${BLUE}Diagnostics complete!${NC}"
}

# Run diagnostics
main "$@"