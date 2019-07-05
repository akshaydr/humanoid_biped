# Usage Instructions
The ROS folder contains all the codes required to run SLAM and also perform Hand gestures. There are three folders in this such as,

1. [humanoid_robot](humanoid_robot/) which contains SLAM codes
2. [dynamixel_control](dynamixel_control/) which contains codes relating to hand gestures and walking gaits. It contains all the libraries that are required to control dynamixel actuators
3. [realsense-2.2.2](realsense-2.2.2/) which contains the wrapper required to get data from Intel realsense camera into ROS

## SLAM
The camera used in this project is [Intel Realsense D435i.](https://www.intelrealsense.com/depth-camera-d435i/) It is capable of getting RGPD depth data with a range of 10 meters. This is the most advanced technology at the time of conducting the project in 2019 and also very compact in design.

We have used ROS packages to perform simultaneous localization and mapping (SLAM) in our project. [Rtabmap](http://wiki.ros.org/rtabmap_ros) is used for 3D mapping. There are many other 3D mapping packages but this package gave better and stable results in generating clear 3D map of the place.  

### Main launch files explained
The following are the important code snippets which helps in understanding the working easily.

1. The [robot.launch](humanoid_robot/humanoid_robot/launch/robot.launch) file which will run all the packages to perform SLAM.
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

Note: Go through [rtabmap](http://wiki.ros.org/rtabmap_ros) and [navigation stack](http://wiki.ros.org/navigation/Tutorials/RobotSetup) tutorials to better understand the overall flow.

2. The [move_base.launch](humanoid_robot/humanoid_robot_slam/launch/move_base.launch) which is responsible for moving the robot from one place to another.
```xml {.line-numbers}
<launch>
  <node pkg="move_base" type="move_base" respawn="false" name="move_base" output="screen">
    <rosparam file="$(find humanoid_robot_slam)/config/costmap_common_params.yaml" command="load" ns="global_costmap"/>
    <rosparam file="$(find humanoid_robot_slam)/config/costmap_common_params.yaml" command="load" ns="local_costmap"/>
    <rosparam file="$(find humanoid_robot_slam)/config/local_costmap_params.yaml" command="load"/>
    <rosparam file="$(find humanoid_robot_slam)/config/global_costmap_params.yaml" command="load"/>
    <rosparam file="$(find humanoid_robot_slam)/config/base_local_planner_params.yaml" command="load"/>
    <remap from="/odom" to="/rtabmap/odom"/>
    <remap from="/map" to="/rtabmap/proj_map"/>
    <param name="use_sim_time" value="true" />
     <param name="initial_pose_x" value="0.0"/>
     <param name="initial_pose_y" value="0.0"/>
     <param name="initial_pose_a" value="0.0"/>
  </node>
</launch>
```
In order to perform SLAM, the first stage is to setup [navigation stack](http://wiki.ros.org/navigation/Tutorials/RobotSetup) for our own robot. Check the link for detailed explanation of robot setup. Once this is done, we need to setup a mapping package based on our requirement and type of camera used. 

3. The [rtabmap.launch](humanoid_robot/humanoid_robot_slam/launch/rtabmap.launch) will setup the mapping parameters. Few changes which are to be made is shown in below code snippet.
he robot from one place to another.

```xml {.line-numbers}
  <arg name="frame_id" default="base_link"/>
  <arg name="odom_frame_id" default="odom"/>
  <arg name="map_frame_id" default="map"/>
```
These are the transformations which are to be modified based on the robot configuration. `frame_id` is the robot's base, `odom_frame_id` is the odometry from the wheels of the robot and `map_frame_id` is the map tf obtained from rtabmap.

## Running the SLAM
Now that we've got everything set up, we can run the SLAM. To do this we'll need one terminal on the robot. In a terminal, we'll launch the `robot.launch` file that we just created.

Terminal 1:
```
rorun humanoid_robot robot.launch
```
This will automatically launch everything that is required for initializing SLAM.
