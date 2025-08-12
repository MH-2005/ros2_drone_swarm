import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

def generate_launch_description():
    """
    Generates the launch description for the full drone swarm competition.
    
    This launch file initializes the Gazebo simulation, spawns a configurable
    number of drones, sets up the necessary ROS-Gazebo bridges, and launches
    the required controller nodes.
    """
    
    # --- 1. GET PATHS AND DECLARE ARGUMENTS ---
    
    # Standard practice to find package paths
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_swarm_controller = get_package_share_directory('swarm_controller')

    # Define paths to essential files
    world_path = os.path.join(pkg_swarm_controller, 'worlds', 'swarm_arena.world')
    params_file = os.path.join(pkg_swarm_controller, 'config', 'swarm_params.yaml')
    sdf_file = os.path.join(pkg_swarm_controller, 'models', 'x500', 'model.sdf')

    # Declare the launch arguments that can be passed from the command line
    declare_use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )
    
    # --- 2. LAUNCH GAZEBO SIMULATION ---

    # The standard and most robust way to launch Gazebo with ROS 2 integration
    # is by including the launch file from the `ros_gz_sim` package.
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        # Pass the world file and other Gazebo arguments here
        launch_arguments={'gz_args': f'-r -v4 {world_path}'}.items(),
    )

    # --- 3. PREPARE LAUNCH ACTIONS ---

    # Create a list to hold all the actions we want to launch
    launch_actions = [
        declare_use_sim_time_arg,
        gazebo,
    ]

    # --- 4. SPAWN DRONES AND LAUNCH NODES ---

    # Define the number of drones to spawn.
    # NOTE: This is set as a Python variable. Using a LaunchConfiguration here
    # to control a 'for' loop is not possible, as the loop runs before the
    # launch configuration is evaluated. For a variable number of drones,
    # this is the simplest and most reliable approach.
    num_drones = 4

    for i in range(num_drones):
        drone_name = f'x500_{i}'
        namespace = f'drone_{i}'

        # Create a GroupAction for each drone...
        drone_group = GroupAction([
            PushRosNamespace(namespace),

            # Spawn the drone entity in Gazebo by its globally known name.
            Node(
                package='ros_gz_sim',
                executable='create',
                arguments=[
                    '-world', 'default',
                    '-name', 'x500', 
                    '-string', f'<model name="{drone_name}"/>', # <-- تغییر نام مدل در شبیه‌سازی
                    '-x', str(i * 2.0 - 3.0),
                    '-y', '0.0',
                    '-z', '0.5'
                ],
                output='screen'
            ),

            # Create a ROS-Gazebo bridge for this drone's topics.
            # This translates messages between the two systems.
            Node(
                package='ros_gz_bridge',
                executable='parameter_bridge',
                arguments=[
                    # Correct Syntax: /ros/topic@ROS_MSG_TYPE[gz.msgs.GZ_MSG_TYPE
                    f'/model/{drone_name}/odometry@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                    'cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                ],
                # Remap the Gazebo-style topics to cleaner, namespaced ROS topics.
                remappings=[
                    (f'/model/{drone_name}/odometry', 'odom'),
                ],
                output='screen'
            ),

            # Launch the individual controller node for this drone.
            Node(
                package='swarm_controller',
                executable='swarm_drone', # The entry point from your setup.py
                name='controller',
                parameters=[
                    {'drone_id': i},
                    {'role': 'leader' if i == 0 else 'follower'},
                    # Pass the use_sim_time argument to the node
                    {'use_sim_time': LaunchConfiguration('use_sim_time')}
                ],
                output='screen'
            )
        ])
        
        launch_actions.append(drone_group)

    # --- 5. LAUNCH CENTRAL CONTROLLERS AND GLOBAL NODES ---

    # Bridge for the simulation clock (needed by all ROS nodes)
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )
    launch_actions.append(clock_bridge)

    # Central formation controller node
    formation_controller = Node(
        package='swarm_controller',
        executable='formation_controller',
        name='formation_controller',
        parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}],
        output='screen'
    )
    launch_actions.append(formation_controller)

    # Central mission executor node
    mission_executor = Node(
        package='swarm_controller',
        executable='mission_executor',
        name='mission_executor',
        parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}],
        output='screen'
    )
    launch_actions.append(mission_executor)

    # --- 6. RETURN THE COMPLETE LAUNCH DESCRIPTION ---
    
    return LaunchDescription(launch_actions)