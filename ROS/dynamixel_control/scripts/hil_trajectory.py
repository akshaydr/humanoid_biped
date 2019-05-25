#!/usr/bin/env python
import socket
import os
import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64
from std_msgs.msg import String

def data_callback(msg):
    data = msg.data
    print data
    val = data.split(",")
    rotation_right, abduc_val_right, hip_val_right, knee_val_right, ankle_val_right, ankle_twist_right, rotation_left, abduc_val_left, hip_val_left,  knee_val_left, ankle_val_left, ankle_twist_left = data.split(",")
    print rotation_right, abduc_val_right, hip_val_right, knee_val_right, ankle_val_right, ankle_twist_right, rotation_left, abduc_val_left, hip_val_left,  knee_val_left, ankle_val_left, ankle_twist_left

    rotation_right = float(rotation_right)
    abduc_val_right = float(abduc_val_right)
    hip_val_right = float(hip_val_right)
    knee_val_right = float(knee_val_right)
    ankle_val_right = float(ankle_val_right)
    ankle_twist_right = float(ankle_twist_right)

    rotation_left = float(rotation_left)
    abduc_val_left = float(abduc_val_left)
    hip_val_left = float(hip_val_left)
    knee_val_left = float(knee_val_left)
    ankle_val_left = float(ankle_val_left)
    ankle_twist_left = float(ankle_twist_left)
    rate.sleep()


    pub1.publish(rotation_right)
    pub2.publish(abduc_val_right)
    pub3.publish(hip_val_right)
    pub4.publish(knee_val_right)
    pub5.publish(ankle_val_right)
    pub6.publish(ankle_twist_right)

    pub7.publish(rotation_left)
    pub8.publish(abduc_val_left)
    pub9.publish(hip_val_left)
    pub10.publish(knee_val_left)
    pub11.publish(ankle_val_left)
    pub12.publish(ankle_twist_left)


if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)
    pub1 = rospy.Publisher('rotation_angle_r', Float64, queue_size=10)
    pub2 = rospy.Publisher('abduction_angle_r', Float64, queue_size=10)
    pub3 = rospy.Publisher('hip_angle_r', Float64, queue_size=10)
    pub4 = rospy.Publisher('knee_angle_r', Float64, queue_size=10)
    pub5 = rospy.Publisher('ankle_angle_r', Float64, queue_size=10)
    pub6 = rospy.Publisher('ankle_twist_angle_r', Float64, queue_size=10)

    pub7 = rospy.Publisher('rotation_angle_l', Float64, queue_size=10)
    pub8 = rospy.Publisher('abduction_angle_l', Float64, queue_size=10)
    pub9 = rospy.Publisher('hip_angle_l', Float64, queue_size=10)
    pub10 = rospy.Publisher('knee_angle_l', Float64, queue_size=10)
    pub11 = rospy.Publisher('ankle_angle_l', Float64, queue_size=10)
    pub12 = rospy.Publisher('ankle_twist_angle_l', Float64, queue_size=10)

    rospy.Subscriber("speedgoat_data", String, data_callback)

    rate = rospy.Rate(1000)

while not rospy.is_shutdown():
    rate.sleep()
