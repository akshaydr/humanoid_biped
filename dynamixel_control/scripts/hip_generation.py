#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 1.0
initial_angle = 180.4
peak_angle = 1000.6

hip_val =   [2141, 2187, 2228, 2263, 2295, 2324, 2350, 2373, 2394, 2412, 2427, 2440, 2450, 2458, 2462, 2463, 2461, 2455, 2445, 2431, 2431, 2420, 2408, 2396, 2384, 2371, 2358, 2344, 2330, 2315, 2300, 2285, 2269, 2252, 2235, 2217, 2199, 2181, 2161, 2141]
knee_val =  [2527, 2588, 2639, 2682, 2717, 2747, 2772, 2791, 2806, 2817, 2823, 2825, 2822, 2815, 2804, 2788, 2767, 2740, 2708, 2669, 2669, 2669, 2667, 2666, 2663, 2660, 2656, 2651, 2645, 2639, 2632, 2624, 2615, 2605, 2595, 2583, 2571, 2557, 2543, 2527]
ankle_val = [1651, 1635, 1625, 1618, 1614, 1613, 1614, 1618, 1623, 1631, 1640, 1651, 1664, 1678, 1694, 1711, 1730, 1751, 1773, 1798, 1798, 1787, 1777, 1767, 1757, 1747, 1738, 1729, 1721, 1712, 1704, 1697, 1689, 1682, 1676, 1670, 1664, 1659, 1655, 1651]

# hip_val = [2036, 1800, 1500, 1800, 2036]
# knee_val = [2036, 1800, 1500, 1800, 2036]
# ankle_val = [2036, 2150, 2150, 2150, 2036]

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
    pub1 = rospy.Publisher('hip_angle', Float64, queue_size=10)
    pub2 = rospy.Publisher('knee_angle', Float64, queue_size=10)
    pub3 = rospy.Publisher('ankle_angle', Float64, queue_size=10)

    hip_val = extend_sample(hip_val, len(hip_val), 15)
    knee_val = extend_sample(knee_val, len(knee_val), 15)
    ankle_val = extend_sample(ankle_val, len(ankle_val), 15)
    # print len(hip_val)
while (j < 5):
    while (pres_time < total_time):
        pres_time += total_time/len(hip_val)
        print (hip_val[i])
        pub1.publish(hip_val[i])
        pub2.publish(knee_val[i])
        pub3.publish(ankle_val[i])
        i += 1
        sleep(total_time/len(hip_val))
    i = -1
    pres_time = 0.0
    j += 1
