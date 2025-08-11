#!/bin/bash
# Create final submission package

echo "Creating competition submission package..."

# Validate first
./validate_package.sh
if [ $? -ne 0 ]; then
    echo "Validation failed. Please fix issues first."
    exit 1
fi

# Create submission directory
SUBMISSION_DIR="swarm_competition_submission_$(date +%Y%m%d_%H%M%S)"
mkdir -p $SUBMISSION_DIR

# Copy all necessary files
echo "Copying files for submission..."

# Source code
cp -r src/ $SUBMISSION_DIR/

# Worlds and models
cp -r worlds/ $SUBMISSION_DIR/
cp -r models/ $SUBMISSION_DIR/

# Configuration files
cp -r config/ $SUBMISSION_DIR/ 2>/dev/null || echo "No config directory found"

# Documentation
cp README.md $SUBMISSION_DIR/
cp requirements.txt $SUBMISSION_DIR/

# Scripts
cp run_competition.sh $SUBMISSION_DIR/
cp install_dependencies.sh $SUBMISSION_DIR/
cp build_project.sh $SUBMISSION_DIR/

# Sample files
cp leader_path.csv $SUBMISSION_DIR/

# Create videos directory placeholder
mkdir -p $SUBMISSION_DIR/videos
echo "Video files will be generated here during competition run" > $SUBMISSION_DIR/videos/README.txt

# Create submission README
cat > $SUBMISSION_DIR/SUBMISSION_README.md << 'SUBEOF'
# ROS2 Swarm Drone Competition - Submission Package

## Quick Start

1. Install dependencies:
   ```bash
   ./install_dependencies.sh
   ```

2. Build project:
   ```bash  
   ./build_project.sh
   ```

3. Run complete competition:
   ```bash
   ./run_competition.sh
   ```

## Files Included

- `src/` - Complete ROS2 workspace with all packages
- `worlds/` - Gazebo simulation world  
- `models/` - Drone models
- `videos/` - Output directory for recorded videos
- `README.md` - Complete documentation
- `requirements.txt` - Python dependencies
- All executable scripts for running competition

## Competition Phases

This package implements all 4 required phases:
1. Formation shapes (line, triangle, square)
2. Movement and rotation
3. Leader following  
4. Leader disarm and re-election

All phases are executed automatically with video recording.

Videos are saved in `videos/` directory after completion.
SUBEOF

# Create archive
echo "Creating ZIP archive..."
zip -r "${SUBMISSION_DIR}.zip" $SUBMISSION_DIR

echo ""
echo "✅ Submission package created: ${SUBMISSION_DIR}.zip"
echo ""
echo "Package contents:"
echo "- Complete ROS2 workspace"
echo "- All executable scripts"  
echo "- Documentation and README"
echo "- Sample configuration files"
echo "- Ready-to-run competition code"
echo ""
echo "Total size: $(du -sh ${SUBMISSION_DIR}.zip | cut -f1)"

# Cleanup temporary directory  
rm -rf $SUBMISSION_DIR

echo "Ready for submission! 🚀"
