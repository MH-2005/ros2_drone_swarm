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
    """
    Generates the complete launch description for drone swarm competition.
    """
    
    # --- 1. GET PATHS AND DECLARE ARGUMENTS ---
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    
    # Define paths
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    params_file = os.path.join(pkg_swarm_controller, 'config', 'swarm_params.yaml')
    
    # Model path for SDF spawning
    model_path = os.path.join(pkg_swarm_controller, 'models')
    x500_sdf = os.path.join(model_path, 'x500', 'model.sdf')
    
    # Launch arguments
    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation time'
    )
    
    declare_headless = DeclareLaunchArgument(
        'headless',
        default_value='false',
        description='Run headless simulation'
    )
    
    declare_record_video = DeclareLaunchArgument(
        'record_video',
        default_value='true',
        description='Enable video recording'
    )
    
    # --- 2. LAUNCH GAZEBO SIMULATION ---
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch',
                'gz_sim.launch.py'
            ])
        ]),
        launch_arguments={
            'gz_args': f'-r -v4 {world_path}',
            'on_exit_shutdown': 'true'
        }.items()
    )
    
    # --- 3. ROS-GAZEBO BRIDGE FOR CLOCK ---
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )
    
    # --- 4. SPAWN DRONES AND CREATE CONTROLLERS ---
    launch_actions = [
        declare_use_sim_time,
        declare_headless,
        declare_record_video,
        gazebo_launch,
        clock_bridge
    ]
    
    num_drones = 4
    spawn_delay = 2.0  # Delay between spawning drones
    
    for i in range(num_drones):
        drone_name = f'x500_{i}'
        namespace = f'drone_{i}'
        
        # Calculate spawn position
        spawn_x = i * 3.0 - 4.5  # Spread drones horizontally
        spawn_y = 0.0
        spawn_z = 0.5
        
        # Spawn drone in Gazebo
        spawn_drone = ExecuteProcess(
            cmd=[
                'gz', 'service', '-s', '/world/swarm_arena/create',
                '--reqtype', 'gz.msgs.EntityFactory',
                '--reptype', 'gz.msgs.Boolean',
                '--timeout', '5000',
                '--req',
                f'sdf_filename: "{x500_sdf}", '
                f'name: "{drone_name}", '
                f'pose: {{position: {{x: {spawn_x}, y: {spawn_y}, z: {spawn_z}}} }}'
            ],
            output='screen',
            shell=False
        )
        
        # Add delay for spawning
        delayed_spawn = TimerAction(
            period=spawn_delay * i,
            actions=[spawn_drone]
        )
        
        # Create drone group with namespace
        drone_group = GroupAction([
            PushRosNamespace(namespace),
            
            # ROS-Gazebo bridge for this drone
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
            
            # Drone controller node
            Node(
                package='swarm_controller',
                executable='swarm_drone',
                name='controller',
                parameters=[
                    {
                        'drone_id': i,
                        'role': 'leader' if i == 0 else 'follower',
                        'use_sim_time': LaunchConfiguration('use_sim_time'),
                        'max_velocity': 2.5,
                        'safety_distance': 3.5,
                        'home_position': [spawn_x, spawn_y, 5.0]
                    }
                ],
                output='screen'
            )
        ])
        
        launch_actions.extend([delayed_spawn, drone_group])
    
    # --- 5. GLOBAL CONTROLLERS ---
    
    # Formation controller
    formation_controller = Node(
        package='swarm_controller',
        executable='formation_controller',
        name='formation_controller',
        parameters=[
            params_file,
            {'use_sim_time': LaunchConfiguration('use_sim_time')}
        ],
        output='screen'
    )
    
    # Mission executor
    mission_executor = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_executor',
        parameters=[
            params_file,
            {
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'video_recording': LaunchConfiguration('record_video')
            }
        ],
        output='screen'
    )
    
    # Add delay for controllers to start after drones
    delayed_formation = TimerAction(
        period=10.0,  # Wait for all drones to spawn
        actions=[formation_controller]
    )
    
    delayed_mission = TimerAction(
        period=12.0,  # Start mission executor after formation controller
        actions=[mission_executor]
    )
    
    launch_actions.extend([delayed_formation, delayed_mission])
    
    return LaunchDescription(launch_actions)