import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Get package directory
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    model_path = os.path.join(pkg_swarm_controller, 'models')

    # Setup Gazebo environment
    if 'GZ_SIM_RESOURCE_PATH' in os.environ:
        os.environ['GZ_SIM_RESOURCE_PATH'] += os.pathsep + model_path
    else:
        os.environ['GZ_SIM_RESOURCE_PATH'] = model_path

    # Launch arguments
    declare_use_sim_time = DeclareLaunchArgument('use_sim_time', default_value='true')

    # Gazebo launch
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch', 'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'{world_path} -r',
            'on_exit_shutdown': 'true'
        }.items()
    )

    # Clock bridge
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )

    # Spawn a single drone first for testing
    spawn_drone = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', 'test_drone',
            '-file', os.path.join(model_path, 'x500', 'model.sdf'),
            '-x', '0', '-y', '0', '-z', '0.5'
        ],
        output='screen'
    )

    # Bridge for the test drone
    drone_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/model/test_drone/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
            '/model/test_drone/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/test_drone/enable@std_msgs/msg/Bool]gz.msgs.Boolean',
        ],
        remappings=[
            ('/model/test_drone/odometry', '/drone_0/odom'),
            ('/model/test_drone/cmd_vel', '/drone_0/cmd_vel'),
            ('/model/test_drone/enable', '/drone_0/enable'),
        ],
        output='screen'
    )

    # Simple drone controller
    drone_controller = Node(
        package='swarm_controller',
        executable='swarm_drone',
        namespace='drone_0',
        name='controller',
        parameters=[{
            'drone_id': 0,
            'role': 'leader',
            'use_sim_time': True,
            'max_velocity': 1.0,
            'safety_distance': 2.0,
            'home_position': [0.0, 0.0, 3.0]
        }],
        output='screen'
    )

    return LaunchDescription([
        declare_use_sim_time,
        gazebo_launch,
        TimerAction(period=3.0, actions=[clock_bridge]),
        TimerAction(period=8.0, actions=[spawn_drone]),
        TimerAction(period=12.0, actions=[drone_bridge]),
        TimerAction(period=15.0, actions=[drone_controller]),
    ])
