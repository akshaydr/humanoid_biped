import os
import signal
import time

os.system("python /home/ajit2/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/gestures/double_hand_start.py")
os.system("python /home/ajit2/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/gestures/leg_position_start.py")
time.sleep(0.5)
os.system("rosbag play -u 6 /home/ajit2/catkin_ws/src/humanoid_biped/dynamixel_control/bag/walking_gait_10mm.bag")
time.sleep(4.0)
os.system("python /home/ajit2/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/gestures/leg_position_stop.py")
os.system("python /home/ajit2/catkin_ws/src/humanoid_biped/dynamixel_control/scripts/gestures/double_hand_stop.py")
