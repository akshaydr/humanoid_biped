#!/usr/bin/env python

import rospy
from dynamixel_workbench_msgs.srv import JointCommand
from motor_param import *
from std_msgs.msg import Float64

abduction_left_angle = JointCommand()
abduction_left_angle.unit = "raw"
abduction_left_angle.id = 6

rotation_left_angle = JointCommand()
rotation_left_angle.unit = "raw"
rotation_left_angle.id = 7

flextion_left_angle = JointCommand()
flextion_left_angle.unit = "raw"
flextion_left_angle.id = 8

knee_left_angle = JointCommand()
knee_left_angle.unit = "raw"
knee_left_angle.id = 9

def abduction_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(abduction_left_angle.unit, abduction_left_angle.id, constrain(msg.data, "abduction_left"))

def rotation_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(rotation_left_angle.unit, rotation_left_angle.id, constrain(msg.data, "rotation_left"))

def flexion_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(flextion_left_angle.unit, flextion_left_angle.id, constrain(msg.data, "flexion_left"))

def knee_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(knee_left_angle.unit, knee_left_angle.id, constrain(msg.data, "flexion_left"))

if __name__ == '__main__':
    rospy.init_node('motor_drive', anonymous=True)
    rospy.Subscriber("flexion_left_value", Float64, flexion_callback)
    rospy.Subscriber("abduction_left_value", Float64, abduction_callback)
    rospy.Subscriber("knee_left_value", Float64, knee_callback)
    rospy.Subscriber("rotation_left_value", Float64, rotation_callback)

    rospy.spin()
