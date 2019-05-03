import os
import signal
import time

os.system("python /home/akshay/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/trajectory_generation.py")
time.sleep(1)
os.system("rosbag play -u 6 /home/akshay/catkin_ws/src/humanoid_biped/dynamixel_control/bag/walking_gait_10mm.bag")
time.sleep(6.5)
os.system("python /home/akshay/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/trajectory_generation2.py")
