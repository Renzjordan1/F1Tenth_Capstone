# F1Tenth_Capstone
F1Tenth Capstone Spring 2024 

(requires ROS 2)

**Source ROS prior to running any ROS2 related commands in a new terminal:** <br />
source /opt/ros/<ROS-DISTRO>/setup.bash <br />
source install/local_setup.bash <br /> <br /> <br />

**To build ROS packages:** <br />
colcon build <br /> <br /> <br />

**Launch the simulation node:** <br />
ros2 launch f1tenth_gym_ros gym_bridge_launch.py <br /> <br /> <br />

**Run Pure Pusuit node:** <br />
ros2 run pursuit_lab pure_pursuit_node.py <br /> <br /> <br />

**To start F1Tenth car and slam_toolbox (requires Autoware and F1Tenth car):** <br />
chmod +x /LaunchSlam.sh <br />
./LaunchSlam.sh <br />



