#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 2.0
initial_angle = 180.4
peak_angle = 1000.6

abduc_val_right =   [2048, ]
hip_val_right =     [2048, ]
knee_val_right =    [2048, ]
ankle_val_right =   [2048, ]
ankle_twist_right = [2048, ]

abduc_val_left =    [2048, ]
hip_val_left =      [2048, ]
knee_val_left =     [2048, ]
ankle_val_left =    [2048, ]
ankle_twist_left =  [2048, ]

# hip_val_right = [2036, 1800, 1500, 1800, 2036]
# knee_val_right = [2036, 1800, 1500, 1800, 2036]
# ankle_val_right = [2036, 2150, 2150, 2150, 2036]

i = -1;
j = 0

def extend_sample(data, present_sample, new_sample):
    new_data = []
    for i in range(present_sample - 1):
        x = data[i]
        y = data[i+1]
        val = (y - x)/new_sample
        new_data.append(data[i])
        for j in range(new_sample):
            angle = val + x
            x = angle
            new_data.append(angle)
            j += 1
        new_data.append(data[i + 1])
        i += 1
    return new_data


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

    abduc_val_right = extend_sample(abduc_val_right, len(abduc_val_right), 15)
    hip_val_right = extend_sample(hip_val_right, len(hip_val_right), 15)
    knee_val_right = extend_sample(knee_val_right, len(knee_val_right), 15)
    ankle_val_right = extend_sample(ankle_val_right, len(ankle_val_right), 15)
    ankle_twist_right = extend_sample(ankle_twist_right, len(ankle_twist_right), 15)

    abduc_val_left = extend_sample(abduc_val_left, len(abduc_val_left), 15)
    hip_val_left = extend_sample(hip_val_left, len(hip_val_left), 15)
    knee_val_left = extend_sample(knee_val_left, len(knee_val_left), 15)
    ankle_val_left = extend_sample(ankle_val_left, len(ankle_val_left), 15)
    ankle_twist_left = extend_sample(ankle_twist_left, len(ankle_twist_left), 15)

    # print len(hip_val_right)
while (j < 5):
    while (pres_time < total_time):
        pres_time += total_time/len(hip_val_right)
        print (abduc_val_right[i], ankle_twist_right[i], abduc_val_left[i], ankle_twist_left[i])

        pub2.publish(abduc_val_right[i])
        pub3.publish(hip_val_right[i])
        pub4.publish(knee_val_right[i])
        pub5.publish(ankle_val_right[i])
        pub6.publish(ankle_twist_right[i])

        pub8.publish(abduc_val_left[i])
        pub9.publish(hip_val_left[i])
        pub10.publish(knee_val_left[i])
        pub11.publish(ankle_val_left[i])
        pub12.publish(ankle_twist_left[i])

        i += 1
        sleep(total_time/len(hip_val_right))
    i = -1
    pres_time = 0.0
    j += 1
