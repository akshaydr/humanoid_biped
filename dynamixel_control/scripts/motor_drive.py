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

abduction_right_angle = JointCommand()
abduction_right_angle.unit = "raw"
abduction_right_angle.id = 5

rotation_right_angle = JointCommand()
rotation_right_angle.unit = "raw"
rotation_right_angle.id = 4

flextion_right_angle = JointCommand()
flextion_right_angle.unit = "raw"
flextion_right_angle.id = 3

knee_right_angle = JointCommand()
knee_right_angle.unit = "raw"
knee_right_angle.id = 2

mid_section_angle = JointCommand()
mid_section_angle.unit = "raw"
mid_section_angle.id = 11

uppper_body_angle = JointCommand()
uppper_body_angle.unit = "raw"
uppper_body_angle.id = 12

def abduction_left_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(abduction_left_angle.unit, abduction_left_angle.id, constrain(msg.data, "abduction_left"))

def rotation_left_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(rotation_left_angle.unit, rotation_left_angle.id, constrain(msg.data, "rotation_left"))

def flexion_left_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(flextion_left_angle.unit, flextion_left_angle.id, constrain(msg.data, "flexion_left"))

def knee_left_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(knee_left_angle.unit, knee_left_angle.id, constrain(msg.data, "flexion_left"))

def abduction_right_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(abduction_right_angle.unit, abduction_right_angle.id, constrain(msg.data, "abduction_right"))

def rotation_right_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(rotation_right_angle.unit, rotation_right_angle.id, constrain(msg.data, "rotation_right"))

def flexion_right_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(flextion_right_angle.unit, flextion_right_angle.id, constrain(msg.data, "flexion_right"))

def knee_right_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(knee_right_angle.unit, knee_right_angle.id, constrain(msg.data, "flexion_right"))

def mid_section_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(mid_section_angle.unit, mid_section_angle.id, constrain(msg.data, "mid_section"))

def uppper_body_callback(msg):
    angle_service = rospy.ServiceProxy('joint_command', JointCommand)
    angle_service(uppper_body_angle.unit, uppper_body_angle.id, constrain(msg.data, "uppper_body"))

if __name__ == '__main__':
    rospy.init_node('motor_drive', anonymous=True)

    rospy.Subscriber("flexion_left_value", Float64, flexion_left_callback)
    rospy.Subscriber("abduction_left_value", Float64, abduction_left_callback)
    rospy.Subscriber("knee_left_value", Float64, knee_left_callback)
    rospy.Subscriber("rotation_left_value", Float64, rotation_left_callback)

    rospy.Subscriber("flexion_right_value", Float64, flexion_right_callback)
    rospy.Subscriber("abduction_right_value", Float64, abduction_right_callback)
    rospy.Subscriber("knee_right_value", Float64, knee_right_callback)
    rospy.Subscriber("rotation_right_value", Float64, rotation_right_callback)

    rospy.Subscriber("mid_section_value", Float64, mid_section_callback)
    rospy.Subscriber("uppper_body_value", Float64, uppper_body_callback)

    rospy.spin()
