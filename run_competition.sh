#!/bin/bash
# اسکریپت اجرای کامل مسابقه پهپادهای دسته‌جمعی

set -e

echo "==========================================="
echo "مسابقه پهپادهای دسته‌جمعی ROS2 - اجرای کامل"
echo "==========================================="

# بررسی محیط ROS2
if [ -z "$ROS_DISTRO" ]; then
    echo "خطا: ROS2 source نشده است. لطفاً اجرا کنید:"
    echo "source /opt/ros/humble/setup.bash"
    exit 1
fi

echo "محیط ROS2 $ROS_DISTRO تشخیص داده شد ✓"

# پاکسازی پردازش‌های قبلی
echo "پاکسازی پردازش‌های قبلی..."
killall -9 gz gzserver gzclient ruby &>/dev/null || true
pkill -f "ros2" &>/dev/null || true
pkill -f "gazebo" &>/dev/null || true
sleep 2

# ساخت workspace
echo "ساخت ROS2 workspace..."
if ! colcon build --symlink-install; then
    echo "خطا: ساخت workspace ناموفق بود"
    exit 1
fi

# Source کردن workspace
echo "تنظیم محیط workspace..."
source install/setup.bash

# ایجاد دایرکتوری‌های لازم
echo "ایجاد دایرکتوری‌های خروجی..."
mkdir -p videos logs

# تنظیم متغیرهای محیطی
export GZ_SIM_RESOURCE_PATH=$(pwd)/worlds:$(pwd)/models:${GZ_SIM_RESOURCE_PATH:-}
export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp

# نمایش اطلاعات سیستم
echo ""
echo "=== اطلاعات سیستم ==="
echo "ROS Distribution: $ROS_DISTRO"
echo "Workspace Path: $(pwd)"
echo "Python Version: $(python3 --version)"
echo "Gazebo Version: $(gz sim --version 2>/dev/null || echo 'Unknown')"
echo ""

# اجرای شبیه‌سازی
echo "🚀 راه‌اندازی شبیه‌سازی مسابقه..."
echo ""
echo "نکات مهم:"
echo "• ویدیوها در پوشه ./videos/ ذخیره می‌شوند"
echo "• لاگ‌ها در پوشه ./logs/ ذخیره می‌شوند"  
echo "• برای توقف از Ctrl+C استفاده کنید"
echo "• برای دستورات runtime از ./runtime_commands.sh استفاده کنید"
echo ""

# راه‌اندازی launch file
ros2 launch swarm_controller run_competition.launch.py \
    record_video:=true \
    use_sim_time:=true \
    headless:=false \
    world_file:="$(pwd)/src/swarm_controller/worlds/swarm_arena.world" \
    2>&1 | tee logs/competition_run_$(date +%Y%m%d_%H%M%S).log &

LAUNCH_PID=$!

# تابع پاکسازی
cleanup() {
    echo ""
    echo "🛑 متوقف کردن شبیه‌سازی..."
    kill $LAUNCH_PID 2>/dev/null || true
    sleep 3
    killall -9 gz gzserver gzclient ruby &>/dev/null || true
    pkill -f "ros2" &>/dev/null || true
    echo "پاکسازی کامل شد ✓"
}

trap cleanup EXIT INT TERM

echo "شبیه‌سازی در حال اجرا..."
echo "برای متوقف کردن: Ctrl+C"
echo ""

# انتظار برای اتمام
wait $LAUNCH_PID

echo ""
echo "🎯 اجرای مسابقه تکمیل شد!"
echo ""
echo "فایل‌های خروجی:"
echo "  📹 ویدیوها: $(ls -la videos/ 2>/dev/null | wc -l) فایل در ./videos/"
echo "  📄 لاگ‌ها: $(ls -la logs/ 2>/dev/null | wc -l) فایل در ./logs/"