#!/bin/bash
# Clean build environment thoroughly

set -e

echo "Cleaning build environment..."

# Remove build directories
rm -rf build/ install/ log/

# Clean Python cache files
find . -type f -name "*.pyc" -delete
find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true

# Clean ROS2 specific files
find . -type f -name "*.log" -delete
find . -type d -name "build" -exec rm -rf {} + 2>/dev/null || true
find . -type d -name "install" -exec rm -rf {} + 2>/dev/null || true

# Clean temporary files
rm -rf .pytest_cache/ .coverage htmlcov/

echo "✓ Build environment cleaned"