import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    IncludeLaunchDescription, 
    DeclareLaunchArgument,
    TimerAction,
    GroupAction
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

def generate_launch_description():
    # Get package directories
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_swarm_controller = get_package_share_directory('swarm_controller')

    # Configuration files
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    params_file = os.path.join(pkg_swarm_controller, 'config', 'swarm_params.yaml')
    sdf_file = os.path.join(pkg_swarm_controller, 'models', 'x500', 'model.sdf')

    # Launch Arguments
    use_sim_time = LaunchConfiguration('use_sim_time')
    
    # Declare launch arguments
    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation time'
    )

    # Start Gazebo
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={
            'gz_args': f'-r -v4 {world_path}',
            'gui': 'true'
        }.items()
    )

    launch_actions = [declare_use_sim_time, gazebo]

    # Spawn multiple drones
    num_drones = 4
    drone_group_actions = []

    for i in range(num_drones):
        drone_name = f'x500_{i}'
        drone_ns = f'drone_{i}'

        # Spawn drone with delay
        spawn_drone = Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                '-world', 'default',
                '-file', sdf_file,
                '-name', drone_name,
                '-x', str(i * 2.0 - 3.0),
                '-y', '0.0',
                '-z', '0.5',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'
            ],
            output='screen'
        )

        # Bridge for each drone
        bridge = Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            name=f'bridge_{drone_name}',
            parameters=[{'use_sim_time': use_sim_time}],
            arguments=[
                # Odometry
                f'/model/{drone_name}/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                # Command velocity
                f'/{drone_ns}/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                # IMU data
                f'/model/{drone_name}/imu@sensor_msgs/msg/Imu[gz.msgs.IMU'
            ],
            remappings=[
                (f'/model/{drone_name}/odometry', f'/{drone_ns}/odom'),
                (f'/model/{drone_name}/imu', f'/{drone_ns}/imu')
            ],
            output='screen'
        )

        # Drone controller
        controller = Node(
            package='swarm_controller',
            executable='swarm_drone',
            name=f'controller_{i}',
            namespace=drone_ns,
            parameters=[
                {'drone_id': i},
                {'role': 'leader' if i == 0 else 'follower'},
                {'use_sim_time': use_sim_time}
            ],
            output='screen'
        )

        # Group actions for each drone with proper timing
        drone_actions = GroupAction([
            TimerAction(
                period=2.0 * i,  # Staggered spawn
                actions=[spawn_drone]
            ),
            TimerAction(
                period=2.0 * i + 1.0,  # Bridge after spawn
                actions=[bridge]
            ),
            TimerAction(
                period=2.0 * i + 2.0,  # Controller after bridge
                actions=[controller]
            )
        ])
        
        drone_group_actions.append(drone_actions)

    # Clock bridge
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='clock_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )

    # Formation controller
    formation_controller = Node(
        package='swarm_controller',
        executable='formation_controller',
        name='formation_controller',
        parameters=[params_file, {'use_sim_time': use_sim_time}],
        output='screen'
    )

    # Mission executor
    mission_executor = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_executor',
        parameters=[params_file, {'use_sim_time': use_sim_time}],
        output='screen'
    )

    # Add all actions with proper timing
    launch_actions.extend([
        clock_bridge,
        *drone_group_actions,
        TimerAction(
            period=10.0,
            actions=[formation_controller]
        ),
        TimerAction(
            period=12.0,
            actions=[mission_executor]
        )
    ])

    return LaunchDescription(launch_actions)