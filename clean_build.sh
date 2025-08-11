#!/bin/bash
# پاکسازی کامل محیط ساخت
rm -rf build install log
find . -name "*.pyc" -delete
echo "Build environment cleaned"