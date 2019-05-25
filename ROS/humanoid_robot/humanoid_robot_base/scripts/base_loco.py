#!/usr/bin/env python
import socket
import os
import rospy
import numpy as np
import time
from std_msgs.msg import Float64
from std_msgs.msg import String

if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)
    pub = rospy.Publisher('base_drive', Float64, queue_size=10)
    rate = rospy.Rate(1000)

while not rospy.is_shutdown():
    pub.publish(10.0)
    time.sleep(2)
    pub.publish(0.0)
    time.sleep(2)
    rate.sleep()
