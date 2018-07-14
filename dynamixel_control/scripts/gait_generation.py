#!/usr/bin/env python

import rospy
from dynamixel_workbench_msgs.srv import JointCommand
from motor_param import *
from time import sleep
from std_msgs.msg import Float64

if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)

    abduction_left_pub = rospy.Publisher('abduction_left_value', Float64, queue_size=10)
    rotation_left_pub = rospy.Publisher('rotation_left_value', Float64, queue_size=10)
    flexion_left_pub = rospy.Publisher('flexion_left_value', Float64, queue_size=10)
    knee_left_pub = rospy.Publisher('knee_left_value', Float64, queue_size=10)

    rate = rospy.Rate(10) # 10hz

    while not rospy.is_shutdown():
        type = raw_input("Enter the motion gait type:")
        if (type == "init"):
            abduction_left_pub.publish(2545.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(1536.0)
            knee_left_pub.publish(2050.0)

        if (type == "move"):
            sleep(1)
            abduction_left_pub.publish(2545.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(2129.0)
            knee_left_pub.publish(1428.0)

            abduction_left_pub.publish(2545.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(1536.0)
            knee_left_pub.publish(2050.0)

        rate.sleep()
