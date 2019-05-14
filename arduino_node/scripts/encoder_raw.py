#!/usr/bin/env python

import rospy
import math
import tf
from nav_msgs.msg import Odometry
from std_msgs.msg import String

from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3

data = '0.0,0.0'

def callback(msg):
    global data
    data = msg.data
    vals = msg.data.split(",")

    en1 = float(vals[0])
    en2 = float(vals[1]) 

    print en1, en2

if __name__ == '__main__':
    global data
    rospy.init_node('encoders')
    rospy.Subscriber('encoderFeedback_raw', String, callback)
    pub = rospy.Publisher('odom_pub', String, queue_size=10)

    rate = rospy.Rate(50) # 50hz

    while not rospy.is_shutdown():
        try:
            pub.publish(data)
            rate.sleep()
        except rospy.ROSInterruptException:
            pass
