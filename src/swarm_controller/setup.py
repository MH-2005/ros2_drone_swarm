from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'swarm_controller'

# Get all Python files in the package
python_files = []
for root, dirs, files in os.walk('swarm_controller'):
    for file in files:
        if file.endswith('.py'):
            python_files.append(os.path.join(root, file))

setup(
    name=package_name,
    version='1.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all launch files
        (os.path.join('share', package_name, 'launch'), 
         glob(os.path.join('launch', '*.launch.py'))),
        # Include all world files  
        (os.path.join('share', package_name, 'worlds'), 
         glob(os.path.join('worlds', '*.world'))),
        # Include all config files
        (os.path.join('share', package_name, 'config'), 
         glob(os.path.join('config', '*.yaml')) + glob(os.path.join('config', '*.rviz'))),
        # Include models
        (os.path.join('share', package_name, 'models', 'x500'), 
         glob(os.path.join('models', 'x500', '*'))),
    ],
    install_requires=[
        'setuptools',
        'rclpy',
        'numpy',
        'scipy',
        'pyyaml',
    ],
    zip_safe=True,
    maintainer='Shahin Team',
    maintainer_email='shahin.team@email.com',
    description='Main controller package for the ROS 2 drone swarm.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'swarm_drone = swarm_controller.swarm_drone:main',
            'formation_controller = swarm_controller.formation_controller:main',
            'mission_executor = swarm_controller.mission_executor:main',
        ],
    },
)