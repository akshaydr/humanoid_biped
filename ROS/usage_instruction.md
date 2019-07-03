## Usage Instructions
The ROS folder contains all the codes required to run SLAM and also perform Hand gestures. There are three folders in this such as,

1. [humanoid_robot](humanoid_robot/) which contains SLAM codes 
2. [dynamixel_control](dynamixel_control/) which contains codes relating to hand gestures and walking gaits. It contains all the libraries that are required to control dynamixel actuators
3. [realsense-2.2.2](realsense-2.2.2/) which contains the wrapper required to get data from Intel realsense camera into ROS

## SLAM
The camera used in this project is [Intel Realsense D435i.](https://www.intelrealsense.com/depth-camera-d435i/) It is capable of getting RGPD depth data with a range of 10 meters. This is the most advanced technology at the time of conducting the project in 2019 and also very compact in design.

We have used ROS packages to perform simulatneous localization and mapping (SLAM) in our project. [Rtabmap](http://wiki.ros.org/rtabmap_ros) is used for 3D mapping. There are many other 3D mapping packages but this package gave better and stable results in generating clear 3D map of the place.  

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

```python
<arg name="gui" default="True"/>
```  
If variable gui is true, then all the simulation softwares like rviz and gazebo will launch. This should be kept true to visualize the map or debug the system.  



In order to perform SLAM, the first stage is to setup [navigation stack](http://wiki.ros.org/navigation/Tutorials/RobotSetup) for our own robot.
