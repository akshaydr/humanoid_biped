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

    abduction_right_pub = rospy.Publisher('abduction_right_value', Float64, queue_size=10)
    rotation_right_pub = rospy.Publisher('rotation_right_value', Float64, queue_size=10)
    flexion_right_pub = rospy.Publisher('flexion_right_value', Float64, queue_size=10)
    knee_right_pub = rospy.Publisher('knee_right_value', Float64, queue_size=10)

    mid_section_pub = rospy.Publisher('mid_section_value', Float64, queue_size=10)
    uppper_body_pub = rospy.Publisher('uppper_body_value', Float64, queue_size=10)

    rate = rospy.Rate(10) # 10hz

    while not rospy.is_shutdown():
        type = raw_input("Enter the motion gait type:")
        if (type == "init"):
            abduction_left_pub.publish(2642.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(1536.0)
            knee_left_pub.publish(2050.0)

            abduction_right_pub.publish(2621.0)
            rotation_right_pub.publish(2040.0)
            flexion_right_pub.publish(3054.0)
            knee_right_pub.publish(2031.0)

            mid_section_pub.publish(2012.0)
            uppper_body_pub.publish(2015.0)

        if (type == "move"):
            abduction_left_pub.publish(2545.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(2242.0)
            knee_left_pub.publish(1164.0)

            abduction_left_pub.publish(2642.0)
            rotation_left_pub.publish(3062.0)
            flexion_left_pub.publish(1536.0)
            knee_left_pub.publish(2050.0)

            sleep(2)

            abduction_right_pub.publish(2621.0)
            rotation_right_pub.publish(2040.0)
            flexion_right_pub.publish(2281.0)
            knee_right_pub.publish(2929.0)


            abduction_right_pub.publish(2621.0)
            rotation_right_pub.publish(2040.0)
            flexion_right_pub.publish(3054.0)
            knee_right_pub.publish(2031.0)
        rate.sleep()
