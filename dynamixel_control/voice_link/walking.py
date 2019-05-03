import os
import signal
import time

os.system("python catkin_ws/src/humanoid_biped/dynamixel_control/trajectory_generation.py")
time.sleep(1)
os.system("rosbag play -u 5 catkin_ws/src/humanoid_biped/dynamixel_control/bag/walking_gait_6mm.bag")
