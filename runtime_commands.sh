#!/bin/bash
# دستورات Runtime برای مسابقه Swarm
# طبق شیوه‌نامه مراحل شبیه‌سازی

echo "=== دستورات Runtime مسابقه پهپادهای دسته‌جمعی ==="
echo ""

function show_help() {
    echo "استفاده:"
    echo "  $0 [COMMAND] [ARGS...]"
    echo ""
    echo "دستورات موجود:"
    echo ""
    echo "مرحله ۱ - شکل‌های چندضلعی:"
    echo "  line [SIZE] [ALTITUDE]     - تشکیل خط"
    echo "  triangle [SIZE] [ALTITUDE] - تشکیل مثلث"
    echo "  square [SIZE] [ALTITUDE]   - تشکیل مربع"
    echo ""
    echo "مرحله ۲ - جابجایی و دوران:"
    echo "  move [FORMATION] [X] [Y] [Z]           - جابجایی شکل"
    echo "  rotate [FORMATION] [X] [Y] [Z]         - دوران شکل"
    echo "  vertical [FORMATION] [SIZE]            - تنظیم عمودی"
    echo "  horizontal [FORMATION] [SIZE]          - تنظیم افقی"
    echo ""
    echo "مرحله ۳ - پیروی از رهبر:"
    echo "  manual_leader [FORMATION] [SPACING]    - کنترل دستی رهبر"
    echo "  auto_path [PATH_FILE] [DURATION]       - مسیر خودکار"
    echo ""
    echo "مرحله ۴ - حذف رهبر:"
    echo "  disarm_leader                          - خاموش کردن رهبر"
    echo ""
    echo "دستورات کمکی:"
    echo "  status        - وضعیت سیستم"
    echo "  help          - نمایش این راهنما"
    echo ""
    echo "مثال‌ها:"
    echo "  $0 square 5.0 6.0"
    echo "  $0 move square 3.0 2.0 0.0"
    echo "  $0 rotate triangle 0 0 90"
    echo "  $0 disarm_leader"
}

function wait_for_services() {
    echo "در حال انتظار برای آماده شدن سرویس‌ها..."
    ros2 service list | grep -q "/change_formation" || {
        echo "خطا: سرویس formation در دسترس نیست"
        echo "لطفاً ابتدا شبیه‌سازی را اجرا کنید: ./run_competition.sh"
        exit 1
    }
    echo "سرویس‌ها آماده هستند ✓"
}

case "${1,,}" in
    "line")
        wait_for_services
        SIZE=${2:-5.0}
        ALT=${3:-5.0}
        echo "اجرای تشکیل خط با اندازه $SIZE و ارتفاع $ALT"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: 'line', size: $SIZE, altitude: $ALT}"
        ;;
        
    "triangle")
        wait_for_services
        SIZE=${2:-6.0}
        ALT=${3:-5.0}
        echo "اجرای تشکیل مثلث با اندازه $SIZE و ارتفاع $ALT"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: 'triangle', size: $SIZE, altitude: $ALT}"
        ;;
        
    "square")
        wait_for_services
        SIZE=${2:-5.0}
        ALT=${3:-5.0}
        echo "اجرای تشکیل مربع با اندازه $SIZE و ارتفاع $ALT"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: 'square', size: $SIZE, altitude: $ALT}"
        ;;
        
    "move")
        wait_for_services
        FORMATION=${2:-square}
        MOVE_X=${3:-2.0}
        MOVE_Y=${4:-0.0}
        MOVE_Z=${5:-0.0}
        echo "جابجایی شکل $FORMATION به موقعیت ($MOVE_X, $MOVE_Y, $MOVE_Z)"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: '$FORMATION', size: 5.0, move_x: $MOVE_X, move_y: $MOVE_Y, move_z: $MOVE_Z}"
        ;;
        
    "rotate")
        wait_for_services
        FORMATION=${2:-square}
        ROT_X=${3:-0}
        ROT_Y=${4:-0}
        ROT_Z=${5:-90}
        echo "دوران شکل $FORMATION با زاویه ($ROT_X°, $ROT_Y°, $ROT_Z°)"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: '$FORMATION', size: 5.0, rotate_x: $ROT_X, rotate_y: $ROT_Y, rotate_z: $ROT_Z}"
        ;;
        
    "vertical")
        wait_for_services
        FORMATION=${2:-square}
        SIZE=${3:-5.0}
        echo "تنظیم شکل $FORMATION به حالت عمودی"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: '$FORMATION', orientation: 'vertical', size: $SIZE}"
        ;;
        
    "horizontal")
        wait_for_services
        FORMATION=${2:-square}
        SIZE=${3:-5.0}
        echo "تنظیم شکل $FORMATION به حالت افقی"
        ros2 service call /change_formation swarm_msgs/srv/ChangeFormation \
        "{formation_type: '$FORMATION', orientation: 'horizontal', size: $SIZE}"
        ;;
        
    "manual_leader")
        wait_for_services
        FORMATION=${2:-line}
        SPACING=${3:-4.0}
        echo "شروع کنترل دستی رهبر با شکل $FORMATION و فاصله $SPACING"
        ros2 action send_goal /execute_mission swarm_msgs/action/ExecuteMission \
        "{mission_type: 'manual_leader', formation_type: '$FORMATION', formation_spacing: $SPACING}"
        ;;
        
    "auto_path")
        wait_for_services
        PATH_FILE=${2:-leader_path.csv}
        DURATION=${3:-120.0}
        echo "شروع مسیر خودکار از فایل $PATH_FILE با مدت $DURATION ثانیه"
        ros2 action send_goal /execute_mission swarm_msgs/action/ExecuteMission \
        "{mission_type: 'auto_path', path_file: '$PATH_FILE', max_duration: $DURATION}"
        ;;
        
    "disarm_leader")
        wait_for_services
        echo "خاموش کردن رهبر فعلی و بازگشت به خانه..."
        ros2 service call /disarm_leader swarm_msgs/srv/DisarmLeader \
        "{leader_id: -1, return_to_home: true}"
        ;;
        
    "status")
        echo "=== وضعیت سیستم ==="
        echo "نودهای فعال:"
        ros2 node list | grep -E "(drone|formation|mission)" || echo "  هیچ نودی یافت نشد"
        echo ""
        echo "سرویس‌های موجود:"
        ros2 service list | grep -E "(formation|disarm)" || echo "  هیچ سرویسی یافت نشد"
        echo ""
        echo "اکشن‌های موجود:"
        ros2 action list | grep -E "mission" || echo "  هیچ اکشنی یافت نشد"
        ;;
        
    "help"|"-h"|"--help"|"")
        show_help
        ;;
        
    *)
        echo "خطا: دستور نامعتبر '$1'"
        echo "برای مشاهده راهنما: $0 help"
        exit 1
        ;;
esac

echo "✓ دستور اجرا شد"