import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node

def generate_launch_description():
    pkg_swarm_controller = get_package_share_directory('swarm_controller')
    
    # Launch arguments
    world_file = LaunchConfiguration('world_file')
    use_sim_time = LaunchConfiguration('use_sim_time')
    headless = LaunchConfiguration('headless')
    record_video = LaunchConfiguration('record_video')
    
    # Use the installed world file path
    world_file_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    
    # Gazebo simulation - بهبود یافته برای Gazebo Fortress
    gazebo_server = ExecuteProcess(
        cmd=['gz', 'sim', world_file_path, '-r', '--verbose', '1'],
        output='screen',
        name='gazebo_server'
    )
    
    gazebo_client = ExecuteProcess(
        cmd=['gz', 'sim', '-g'],
        output='screen',
        name='gazebo_client',
        condition=UnlessCondition(headless)
    )
    
    # ROS-Gazebo bridge - بهبود یافته برای Fortress
    bridge_node = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='ros_gz_bridge',
        arguments=[
            # Clock bridge
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            
            # Drone pose bridges
            '/model/drone_0/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_1/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',  
            '/model/drone_2/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            '/model/drone_3/pose@geometry_msgs/msg/PoseStamped[gz.msgs.Pose',
            
            # Command velocity bridges
            '/model/drone_0/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/drone_1/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/model/drone_2/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist', 
            '/model/drone_3/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
        ],
        output='screen',
        parameters=[{'use_sim_time': use_sim_time}]
    )
    
    # Spawn drones at initial positions
    drone_spawns = []
    drone_positions = [
        {'id': 0, 'x': 0.0, 'y': 0.0, 'z': 0.5},
        {'id': 1, 'x': 4.0, 'y': 0.0, 'z': 0.5},
        {'id': 2, 'x': 0.0, 'y': 4.0, 'z': 0.5},
        {'id': 3, 'x': -4.0, 'y': 0.0, 'z': 0.5}
    ]
    
    model_file = os.path.join(pkg_swarm_controller, 'models', 'x500', 'model.sdf')
    
    for drone in drone_positions:
        spawn_cmd = ExecuteProcess(
            cmd=[
                'gz', 'service', '-s', '/world/swarm_arena/create',
                '--reqtype', 'gz.msgs.EntityFactory',
                '--reptype', 'gz.msgs.Boolean',
                '--timeout', '10000',
                '--req',
                f'sdf_filename: "{model_file}", '
                f'name: "drone_{drone["id"]}", '
                f'pose: {{ position: {{ x: {drone["x"]}, y: {drone["y"]}, z: {drone["z"]} }} }}'
            ],
            output='screen'
        )
        drone_spawns.append(TimerAction(period=10.0 + drone['id'] * 2.0, actions=[spawn_cmd]))
    
    # تصحیح: استفاده از یک executable برای همه پهپادها
    drone_controllers = []
    home_positions = [[0.0, 0.0, 5.0], [4.0, 0.0, 5.0], [0.0, 4.0, 5.0], [-4.0, 0.0, 5.0]]
    
    for i in range(4):
        role = 'leader' if i == 0 else 'follower'
        controller = Node(
            package='swarm_controller',
            executable='swarm_drone',
            name=f'drone_{i}_controller',
            namespace=f'drone_{i}',
            parameters=[
                {'drone_id': i},
                {'role': role}, 
                {'home_position': home_positions[i]},
                {'max_velocity': 2.0},
                {'safety_distance': 3.0},
                {'use_sim_time': use_sim_time}
            ],
            remappings=[
                ('pose', f'/model/drone_{i}/pose'),
                ('cmd_vel', f'/model/drone_{i}/cmd_vel')
            ],
            output='screen'
        )
        drone_controllers.append(controller)
    
    # Formation manager
    formation_manager = Node(
        package='swarm_controller', 
        executable='formation_controller',
        name='formation_manager',
        parameters=[
            {'num_drones': 4},
            {'formation_timeout': 180.0},
            {'position_tolerance': 1.5},
            {'use_sim_time': use_sim_time}
        ],
        output='screen'
    )
    
    # Mission coordinator
    mission_coordinator = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_coordinator', 
        parameters=[
            {'video_recording': record_video},
            {'video_output_dir': './videos/'},
            {'mission_timeout': 200.0},
            {'use_sim_time': use_sim_time}
        ],
        output='screen'
    )
    
    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument('world_file', default_value=world_file_path),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('record_video', default_value='true'),
        
        # Launch sequence with proper delays
        gazebo_server,
        TimerAction(period=3.0, actions=[gazebo_client]),
        TimerAction(period=5.0, actions=[bridge_node]),
        *drone_spawns,  # Spawn drones with delays
        TimerAction(period=20.0, actions=[formation_manager]),
        TimerAction(period=22.0, actions=drone_controllers),
        TimerAction(period=25.0, actions=[mission_coordinator]),
    ])