#!/bin/bash
# اسکریپت اجرای کامل مسابقه پهپادهای دسته‌جمعی - نسخه تصحیح شده

set -e

echo "==========================================="
echo "مسابقه پهپادهای دسته‌جمعی ROS2 - اجرای کامل"
echo "==========================================="

# بررسی محیط ROS2
if [ -z "$ROS_DISTRO" ]; then
    echo "خطا: ROS2 source نشده است. اجرا می‌شود..."
    source /opt/ros/humble/setup.bash
fi

echo "محیط ROS2 $ROS_DISTRO تشخیص داده شد ✓"

# تنظیم RMW implementation
echo "تنظیم RMW implementation..."
if [ -f "/opt/ros/humble/lib/librmw_cyclonedx_cpp.so" ]; then
    export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp
    echo "استفاده از CycloneDX"
elif [ -f "/opt/ros/humble/lib/librmw_fastrtps_cpp.so" ]; then
    export RMW_IMPLEMENTATION=rmw_fastrtps_cpp  
    echo "استفاده از FastRTPS"
else
    echo "هشدار: RMW implementation مناسب پیدا نشد، استفاده از پیش‌فرض"
    unset RMW_IMPLEMENTATION
fi

# پاکسازی پردازش‌های قبلی
echo "پاکسازی پردازش‌های قبلی..."
killall -9 gz gzserver gzclient ruby &>/dev/null || true
pkill -f "ros2" &>/dev/null || true
pkill -f "gazebo" &>/dev/null || true
pkill -f "ign" &>/dev/null || true
sleep 3

# نصب dependencies اگر نیاز باشد
if [ ! -f "/opt/ros/humble/lib/librmw_fastrtps_cpp.so" ] && [ ! -f "/opt/ros/humble/lib/librmw_cyclonedx_cpp.so" ]; then
    echo "نصب RMW dependencies..."
    sudo apt update
    sudo apt install -y ros-humble-rmw-fastrtps-cpp ros-humble-rmw-cyclonedx-cpp
    export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
fi

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
export GZ_SIM_RESOURCE_PATH=$(pwd)/src/swarm_controller/worlds:$(pwd)/src/swarm_controller/models:${GZ_SIM_RESOURCE_PATH:-}

# بررسی Gazebo
if ! command -v gz &> /dev/null; then
    echo "خطا: Gazebo نصب نیست"
    echo "لطفاً اجرا کنید: ./install_dependencies.sh"
    exit 1
fi

# نمایش اطلاعات سیستم
echo ""
echo "=== اطلاعات سیستم ==="
echo "ROS Distribution: $ROS_DISTRO"
echo "RMW Implementation: ${RMW_IMPLEMENTATION:-default}"
echo "Workspace Path: $(pwd)"
echo "Python Version: $(python3 --version)"
echo "Gazebo Version: $(gz sim --version 2>/dev/null || echo 'Unknown')"
echo ""

# تست اتصال ROS2
echo "تست ROS2..."
timeout 3 ros2 topic list &>/dev/null || {
    echo "خطا: ROS2 daemon مشکل دارد، ریستارت..."
    ros2 daemon stop &>/dev/null || true
    sleep 2
    ros2 daemon start &>/dev/null || true
    sleep 2
}

# اجرای شبیه‌سازی
echo "🚀 راه‌اندازی شبیه‌سازی مسابقه..."
echo ""
echo "نکات مهم:"
echo "• ویدیوها در پوشه ./videos/ ذخیره می‌شوند"
echo "• لاگ‌ها در پوشه ./logs/ ذخیره می‌شوند"  
echo "• برای توقف از Ctrl+C استفاده کنید"
echo "• اگر خطا دیدید، با Ctrl+C متوقف کرده و دوباره تلاش کنید"
echo ""

# راه‌اندازی launch file
echo "شروع launch file..."
timeout 300 ros2 launch swarm_controller run_competition.launch.py \
    record_video:=true \
    use_sim_time:=true \
    headless:=false 2>&1 | tee logs/competition_run_$(date +%Y%m%d_%H%M%S).log &

LAUNCH_PID=$!

# تابع پاکسازی
cleanup() {
    echo ""
    echo "🛑 متوقف کردن شبیه‌سازی..."
    kill $LAUNCH_PID 2>/dev/null || true
    sleep 5
    killall -9 gz gzserver gzclient ruby &>/dev/null || true
    pkill -f "ros2" &>/dev/null || true
    pkill -f "gazebo" &>/dev/null || true
    echo "پاکسازی کامل شد ✓"
}

trap cleanup EXIT INT TERM

echo "شبیه‌سازی در حال اجرا..."
echo "برای متوقف کردن: Ctrl+C"
echo "اگر بیش از 60 ثانیه منتظر ماندید، احتمالاً مشکلی وجود دارد"
echo ""

# انتظار برای اتمام با timeout
wait $LAUNCH_PID 2>/dev/null || true

echo ""
echo "🎯 اجرای مسابقه تکمیل شد!"
echo ""
echo "فایل‌های خروجی:"
if [ -d "videos" ]; then
    echo "  📹 ویدیوها: $(ls videos/ 2>/dev/null | wc -l) فایل در ./videos/"
fi
if [ -d "logs" ]; then
    echo "  📄 لاگ‌ها: $(ls logs/ 2>/dev/null | wc -l) فایل در ./logs/"
fi

echo ""
echo "برای اجرای دوباره:"
echo "  ./run_competition.sh"