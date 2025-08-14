import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument, IncludeLaunchDescription, 
    GroupAction, ExecuteProcess, TimerAction
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Get paths
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    params_file = os.path.join(pkg_swarm_controller, 'config', 'swarm_params.yaml')
    
    # Set Gazebo model path
    model_path = os.path.join(pkg_swarm_controller, 'models')
    
    # Launch arguments
    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time', default_value='true'
    )
    declare_headless = DeclareLaunchArgument(
        'headless', default_value='false'
    )
    declare_record_video = DeclareLaunchArgument(
        'record_video', default_value='false'
    )
    
    # Set environment variable for Gazebo models
    os.environ['GZ_SIM_RESOURCE_PATH'] = model_path
    
    # Launch Gazebo
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch', 'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'-r -v4 {world_path}',
            'on_exit_shutdown': 'true'
        }.items()
    )
    
    # ROS-Gazebo bridge for clock
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )
    
    launch_actions = [
        declare_use_sim_time,
        declare_headless, 
        declare_record_video,
        gazebo_launch,
        clock_bridge
    ]
    
    # Spawn drones
    num_drones = 4
    spawn_positions = [
        [-4.5, 0.0, 0.5], [-1.5, 0.0, 0.5], 
        [1.5, 0.0, 0.5], [4.5, 0.0, 0.5]
    ]
    
    for i in range(num_drones):
        drone_name = f'x500_{i}'
        namespace = f'drone_{i}'
        pos = spawn_positions[i]
        
        # Spawn drone model
        spawn_drone = Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                '-name', drone_name,
                '-file', os.path.join(model_path, 'x500', 'model.sdf'),
                '-x', str(pos[0]), '-y', str(pos[1]), '-z', str(pos[2])
            ],
            output='screen'
        )
        
        # Drone group with namespace
        drone_group = GroupAction([
            PushRosNamespace(namespace),
            
            # ROS-Gazebo bridges
            Node(
                package='ros_gz_bridge',
                executable='parameter_bridge',
                arguments=[
                    f'/model/{drone_name}/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                    f'/model/{drone_name}/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                    f'/model/{drone_name}/enable@std_msgs/msg/Bool]gz.msgs.Boolean',
                ],
                remappings=[
                    (f'/model/{drone_name}/odometry', 'odom'),
                    (f'/model/{drone_name}/cmd_vel', 'cmd_vel'),
                    (f'/model/{drone_name}/enable', 'enable'),
                ],
                output='screen'
            ),
            
            # Drone controller
            Node(
                package='swarm_controller',
                executable='swarm_drone',
                name='controller',
                parameters=[{
                    'drone_id': i,
                    'role': 'leader' if i == 0 else 'follower',
                    'use_sim_time': LaunchConfiguration('use_sim_time'),
                    'max_velocity': 2.5,
                    'safety_distance': 3.5,
                    'home_position': [pos[0], pos[1], 5.0]
                }],
                output='screen'
            )
        ])
        
        # Add delay between spawning
        delayed_spawn = TimerAction(
            period=3.0 * i,  # 3 seconds between each drone
            actions=[spawn_drone]
        )
        
        launch_actions.extend([delayed_spawn, drone_group])
    
    # Formation controller
    formation_controller = TimerAction(
        period=15.0,  # Wait for all drones to spawn
        actions=[
            Node(
                package='swarm_controller',
                executable='formation_controller',
                name='formation_controller',
                parameters=[params_file, {
                    'use_sim_time': LaunchConfiguration('use_sim_time')
                }],
                output='screen'
            )
        ]
    )
    
    # Mission executor
    mission_executor = TimerAction(
        period=20.0,  # Start after formation controller
        actions=[
            Node(
                package='swarm_controller',
                executable='mission_executor',
                name='mission_executor',
                parameters=[params_file, {
                    'use_sim_time': LaunchConfiguration('use_sim_time'),
                    'video_recording': LaunchConfiguration('record_video')
                }],
                output='screen'
            )
        ]
    )
    
    launch_actions.extend([formation_controller, mission_executor])
    
    return LaunchDescription(launch_actions)
