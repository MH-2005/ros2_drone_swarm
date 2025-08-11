#!/bin/bash
# Validate complete package structure

echo "Validating ROS2 Swarm Package Structure..."

# Check main files exist
files=(
    "src/swarm_msgs/package.xml"
    "src/swarm_msgs/CMakeLists.txt"
    "src/swarm_controller/package.xml"
    "src/swarm_controller/setup.py"
    "src/swarm_controller/swarm_controller/swarm_leader.py"
    "src/swarm_controller/swarm_controller/swarm_follower.py"
    "src/swarm_controller/swarm_controller/formation_controller.py" 
    "src/swarm_controller/swarm_controller/mission_executor.py"
    "src/swarm_controller/launch/run_competition.launch.py"
    "worlds/swarm_arena.world"
    "models/x500/model.sdf"
    "leader_path.csv"
    "requirements.txt"
    "README.md"
)

missing_files=0

for file in "${files[@]}"; do
    if [ ! -f "$file" ]; then
        echo "❌ Missing: $file"
        missing_files=$((missing_files + 1))
    else
        echo "✅ Found: $file"
    fi
done

if [ $missing_files -eq 0 ]; then
    echo ""
    echo "🎉 All required files present!"
    echo "Package structure is complete and ready for submission."
    
    # Show file sizes
    echo ""
    echo "File sizes:"
    echo "----------"
    echo "Total Python lines of code: $(find . -name "*.py" -exec cat {} \; | wc -l)"
    
else
    echo ""
    echo "⚠️  $missing_files files are missing!"
    echo "Please create the missing files before proceeding."
    exit 1
fi
