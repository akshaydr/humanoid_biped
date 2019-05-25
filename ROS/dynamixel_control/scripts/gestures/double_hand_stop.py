#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 1.0
initial_angle = 180.4
peak_angle = 1000.6
sample_size = 20

# Hand double
right_1 = [3144, 3144, 2036]
right_2 = [2101, 2101, 2036]
right_3 = [1155, 1155, 2036]
right_4 = [2352, 2352, 2036]
right_5 = [1788, 1788, 2036]

left_1 = [900, 900, 2036]
left_2 = [2133, 2133, 2036]
left_3 = [3054, 3054, 2036]
left_4 = [1722, 1722, 2036]
left_5 = [2298, 2298, 2036]

head =   [2036, 2036, 2036]

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
    pub1 = rospy.Publisher('right_1', Float64, queue_size=10)
    pub2 = rospy.Publisher('right_2', Float64, queue_size=10)
    pub3 = rospy.Publisher('right_3', Float64, queue_size=10)
    pub4 = rospy.Publisher('right_4', Float64, queue_size=10)
    pub5 = rospy.Publisher('right_5', Float64, queue_size=10)

    pub6 =  rospy.Publisher('left_1', Float64, queue_size=10)
    pub7 =  rospy.Publisher('left_2', Float64, queue_size=10)
    pub8 =  rospy.Publisher('left_3', Float64, queue_size=10)
    pub9 =  rospy.Publisher('left_4', Float64, queue_size=10)
    pub10 = rospy.Publisher('left_5', Float64, queue_size=10)

    pub11 = rospy.Publisher('head', Float64, queue_size=10)

    right_1 = extend_sample(right_1, len(right_1), sample_size)
    right_2 = extend_sample(right_2, len(right_2), sample_size)
    right_3 = extend_sample(right_3, len(right_3), sample_size)
    right_4 = extend_sample(right_4, len(right_4), sample_size)
    right_5 = extend_sample(right_5, len(right_5), sample_size)

    left_1 = extend_sample(left_1, len(left_1), sample_size)
    left_2 = extend_sample(left_2, len(left_2), sample_size)
    left_3 = extend_sample(left_3, len(left_3), sample_size)
    left_4 = extend_sample(left_4, len(left_4), sample_size)
    left_5 = extend_sample(left_5, len(left_5), sample_size)

    head = extend_sample(head, len(head), sample_size)

while (j < 1):
    while (pres_time < total_time):
        pres_time += total_time/len(right_1)
        print (right_1[i], right_2[i], right_3[i], right_4[i], right_5[i])

        pub1.publish(right_1[i])
        pub2.publish(right_2[i])
        pub3.publish(right_3[i])
        pub4.publish(right_4[i])
        pub5.publish(right_5[i])

        pub6.publish(left_1[i])
        pub7.publish(left_2[i])
        pub8.publish(left_3[i])
        pub9.publish(left_4[i])
        pub10.publish(left_5[i])

        pub11.publish(head[i])

        i += 1
        sleep(total_time/len(right_1))
    i = -1
    pres_time = 0.0
    j += 1
