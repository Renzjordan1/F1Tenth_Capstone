# F1Tenth_Capstone
>CSE 596 Capstone Spring 2024, F1Tenth Autonomous Racing

<br /> 



## How to Run
**Source ROS prior to running any ROS2 related commands in a new terminal:** <br />
```
source /opt/ros/<ROS-DISTRO>/setup.bash
source install/local_setup.bash
```
<br />

**To build ROS packages:** <br />
```
colcon build
```
<br />

**Launch the simulation node:** <br />
```
ros2 launch f1tenth_gym_ros gym_bridge_launch.py
```
<br />

**Run Pure Pusuit node:** <br />
```
ros2 run pursuit_lab pure_pursuit_node.py
```
<br />

**To start F1Tenth car and slam_toolbox (requires Autoware and F1Tenth car):** <br />
```
chmod +x /LaunchSlam.sh
./LaunchSlam.sh
```

## Tech Stack

* ROS2 Galactic, C++, Python

