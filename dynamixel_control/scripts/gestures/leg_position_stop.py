#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 2.0
initial_angle = 180.4
peak_angle = 1000.6
sample_size = 40

# Hand single
rotation_angle_r =    [2036, 2036, 2036]
abduction_angle_r =   [2036, 2036, 2036]
hip_angle_r =         [2147, 2147, 2036]
knee_angle_r =        [2602, 2602, 2036]
ankle_angle_r =       [1581, 1581, 2036]
ankle_twist_angle_r = [2036, 2036, 2036]

rotation_angle_l =    [2036, 2036, 2036]
abduction_angle_l =   [2036, 2036, 2036]
hip_angle_l =         [2412, 2412, 2036]
knee_angle_l =        [2721, 2721, 2036]
ankle_angle_l =       [1727, 1727, 2036]
ankle_twist_angle_l = [2036, 2036, 2036]

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

    rotation_angle_r = extend_sample(rotation_angle_r, len(rotation_angle_r), sample_size)
    abduction_angle_r = extend_sample(abduction_angle_r, len(abduction_angle_r), sample_size)
    hip_angle_r = extend_sample(hip_angle_r, len(hip_angle_r), sample_size)
    knee_angle_r = extend_sample(knee_angle_r, len(knee_angle_r), sample_size)
    ankle_angle_r = extend_sample(ankle_angle_r, len(ankle_angle_r), sample_size)
    ankle_twist_angle_r = extend_sample(ankle_twist_angle_r, len(ankle_twist_angle_r), sample_size)

    rotation_angle_l = extend_sample(rotation_angle_l, len(rotation_angle_l), sample_size)
    abduction_angle_l = extend_sample(abduction_angle_l, len(abduction_angle_l), sample_size)
    hip_angle_l = extend_sample(hip_angle_l, len(hip_angle_l), sample_size)
    knee_angle_l = extend_sample(knee_angle_l, len(knee_angle_l), sample_size)
    ankle_angle_l = extend_sample(ankle_angle_l, len(ankle_angle_l), sample_size)
    ankle_twist_angle_l = extend_sample(ankle_twist_angle_l, len(ankle_twist_angle_l), sample_size)

while (j < 1):
    while (pres_time < total_time):
        pres_time += total_time/len(abduction_angle_r)
        print (rotation_angle_r[i], abduction_angle_r[i], hip_angle_r[i], knee_angle_r[i], ankle_angle_r[i])

        pub1.publish(rotation_angle_r[i])
        pub2.publish(abduction_angle_r[i])
        pub3.publish(hip_angle_r[i])
        pub4.publish(knee_angle_r[i])
        pub5.publish(ankle_angle_r[i])
        pub6.publish(ankle_twist_angle_r[i])

        pub7.publish(rotation_angle_l[i])
        pub8.publish(abduction_angle_l[i])
        pub9.publish(hip_angle_l[i])
        pub10.publish(knee_angle_l[i])
        pub11.publish(ankle_angle_l[i])
        pub12.publish(ankle_twist_angle_l[i])

        i += 1
        sleep(total_time/len(abduction_angle_l))
    i = -1
    pres_time = 0.0
    j += 1
