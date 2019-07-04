## Usage Instructions
The ROS folder contains all the codes required to run SLAM and also perform Hand gestures. There are three folders in this such as,

1. [humanoid_robot](humanoid_robot/) which contains SLAM codes
2. [dynamixel_control](dynamixel_control/) which contains codes relating to hand gestures and walking gaits. It contains all the libraries that are required to control dynamixel actuators
3. [realsense-2.2.2](realsense-2.2.2/) which contains the wrapper required to get data from Intel realsense camera into ROS

## SLAM
The camera used in this project is [Intel Realsense D435i.](https://www.intelrealsense.com/depth-camera-d435i/) It is capable of getting RGPD depth data with a range of 10 meters. This is the most advanced technology at the time of conducting the project in 2019 and also very compact in design.

We have used ROS packages to perform simultaneous localization and mapping (SLAM) in our project. [Rtabmap](http://wiki.ros.org/rtabmap_ros) is used for 3D mapping. There are many other 3D mapping packages but this package gave better and stable results in generating clear 3D map of the place.  

The following are the important code snippets which helps in understanding the working easily.

1. The [code snippet](humanoid_robot/humanoid_robot/launch/robot.launch) which will run all the packages to perform SLAM.
```xml {.line-numbers}
<launch>
<arg name="gui" default="True"/>
<arg name="sim" default="False"/>
<arg name="debug" default="False"/>
<!-- <arg name="bag_file" default="/home/akshay/my_bagfile_1.bag"/> -->
<arg name="bag_file" default="/home/ajit2/my_bagfile_1.bag"/>

<include file="$(find humanoid_robot_description)/launch/display.launch"/>
<include file="$(find humanoid_robot_slam)/launch/move_base.launch"/>
<include file="$(find humanoid_robot_slam)/launch/rtabmap.launch">
<arg name="args" value="--delete_db_on_start"/>
<arg name="rgb_topic" value="/camera/color/image_raw"/>
<arg name="depth_topic" value="/camera/aligned_depth_to_color/image_raw"/>
<arg name="camera_info_topic" value="/camera/color/camera_info"/>
<arg name="depth_camera_info_topic" value="/camera/depth/camera_info"/>
</include>
</launch>
```
Remember this is just the code snippet which includes only lines which are to be explained. For full code, navigate to the respective link which is given above. This is a launch file which will run all the launch files, nodes and packages to start SLAM.

The first three lines are arguments of type boolean.

```xml {.line-numbers}
<arg name="gui" default="True"/>
<arg name="sim" default="False"/>
<arg name="debug" default="False"/>
```  
* If `gui` is true, then all the simulation software like rviz and gazebo will launch. This should be kept true to visualize the map or debug the system.  
* `sim` is used to either enable or disable simulation. Usually, any robot is tested either on the hardware or in the simulation software. When running a simulation, keep `sim` as true to use recorded bag file instead of the actual sensor. When running on the hardware, keep `sim` to false to take data from the real-time sensor.
* Putting `debug` to true will start `rqt_graph` and `rqt_tf_tree` during the runtime. This will help in easy debug of the entire system.

```xml {.line-numbers}
<include file="$(find humanoid_robot_description)/launch/display.launch"/>
<include file="$(find humanoid_robot_slam)/launch/move_base.launch"/>
<include file="$(find humanoid_robot_slam)/launch/rtabmap.launch">
```
These three files will run three important parts of SLAM which are,
* `display.launch` will run the robot urdf file to visualize the robot in rviz or gazebo.
* `move_base.launch` provides a ROS interface for configuring, running, and interacting with the navigation stack on a robot.
*  `rtabmap.launch` will setup mapping parameters and also get date from the camera.

Note: Go through [rtabmap](http://wiki.ros.org/rtabmap_ros) and [navigation stack](http://wiki.ros.org/navigation/Tutorials/RobotSetup) tutorials to better understand the overall process.
