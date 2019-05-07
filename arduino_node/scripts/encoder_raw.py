#!/usr/bin/env python

import rospy
import math
import tf
from nav_msgs.msg import Odometry
from std_msgs.msg import String

from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3

def callback(msg):
    global current_time, last_time, olden1, olden2, olden3, olden4, x, y, th, vx, vy, vth, odom
    vals = msg.data.split(",")

    current_time = rospy.Time.now()
    odom_broadcaster = tf.TransformBroadcaster()

    en1 = float(vals[0])
    en2 = float(vals[1])
    print en1, en2

if __name__ == '__main__':
    rospy.init_node('encoders')
    rospy.Subscriber('encoderFeedback_raw', String, callback)

    rate = rospy.Rate(50) # 50hz

    while not rospy.is_shutdown():
        try:
            rate.sleep()
        except rospy.ROSInterruptException:
            pass
