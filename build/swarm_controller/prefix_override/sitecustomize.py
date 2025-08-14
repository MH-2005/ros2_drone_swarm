import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/mh/Documents/ros2_drone_swarm/install/swarm_controller'
