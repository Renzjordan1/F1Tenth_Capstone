#A shell script for opening 3 terminals, launching necessary ROS2 nodes for #SLAM, and launching RViz. This automates the SLAM map building preparation. 

#!/bin/bash

# Open Terminal 1
#Launching F1tenth stack (including streaming sensor data)
gnome-terminal -- bash -c 'cd ~/Documents; source /opt/ros/galactic/setup.bash; cd autoware && . install/setup.bash; ros2 launch f1tenth_stack bringup_launch.py; exec bash'

# Open Terminal 2
#Launching Slam Toolbox for building map
gnome-terminal -- bash -c 'cd ~/Documents; source /opt/ros/galactic/setup.bash; cd autoware && . install/setup.bash; ros2 launch slam_toolbox online_async_launch.py slam_params_file:=/home/aimslab/Documents/autoware/src/universe/autoware.universe/f1tenth/f1tenth_system/f1tenth_stack/config/f1tenth_online_async.yaml; exec bash'

# Open Terminal 3
#Opening simulation window for map building preview
gnome-terminal -- bash -c 'cd ~/Documents; rviz2'
