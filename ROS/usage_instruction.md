## Usage Instructions
The ROS folder contains all the codes required to run SLAM and also perform Hand gestures. There are three folders in this such as,

1. [humanoid_robot](humanoid_robot/) which contains SLAM codes 
2. [dynamixel_control](dynamixel_control/) which contains codes relating to hand gestures and walking gaits. It constains all the libraries that are required to control dynamcxel actuators
3. [realsense-2.2.2](realsense-2.2.2/) which contains the wrapper required to get data from intel realsense camera into ROS

## SLAM
The camera used in this project is [Intel Realsense D435i.](https://www.intelrealsense.com/depth-camera-d435i/) It is capable of getting RGPD depth data with a range of 10 meters. This is most advanced technology at the time of conducting the project in 2019 and also very compact in design. 
