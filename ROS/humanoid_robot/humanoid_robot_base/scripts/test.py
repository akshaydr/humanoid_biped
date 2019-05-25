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
    pub = rospy.Publisher('odom_pub', String, queue_size=10)
    rate = rospy.Rate(40)

while not rospy.is_shutdown():
    pub.publish("10,10")
    time.sleep(0.1)
    pub.publish("20,10")
    time.sleep(0.1)
    pub.publish("30,10")
    time.sleep(0.1)
    pub.publish("40,10")
    time.sleep(0.1)
    pub.publish("50,10")
    time.sleep(0.1)
    pub.publish("60,10")
    time.sleep(0.1)
    pub.publish("70,10")
    time.sleep(0.1)
    pub.publish("80,10")
    time.sleep(0.1)
    pub.publish("90,10")
    time.sleep(0.1)
    pub.publish("100,10")
    time.sleep(0.1)
    pub.publish("110,10")
    time.sleep(0.1)
    pub.publish("120,10")
    time.sleep(0.1)
    pub.publish("130,10")
    time.sleep(0.1)
    pub.publish("140,10")
    time.sleep(0.1)
    pub.publish("150,10")
    time.sleep(0.1)
    pub.publish("160,10")
    time.sleep(0.1)
    pub.publish("170,10")
    time.sleep(0.1)
    pub.publish("180,10")
    time.sleep(0.1)
    pub.publish("190,10")
    time.sleep(0.1)
    pub.publish("200,10")
    time.sleep(0.1)
    rate.sleep()
