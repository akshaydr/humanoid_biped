#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 1.0
initial_angle = 180.4
peak_angle = 1000.6

abduc_val_right =   [2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2058, 2069, 2092, 2103, 2125, 2136, 2158, 2169, 2192, 2192, 2169, 2158, 2136, 2125, 2103, 2092, 2069, 2058, 2036]
hip_val_right =     [2141, 2187, 2228, 2263, 2295, 2324, 2350, 2373, 2394, 2412, 2427, 2440, 2450, 2458, 2462, 2463, 2461, 2455, 2445, 2431, 2431, 2420, 2408, 2396, 2384, 2371, 2358, 2344, 2330, 2315, 2300, 2285, 2269, 2252, 2235, 2217, 2199, 2181, 2161, 2141]
knee_val_right =    [2527, 2588, 2639, 2682, 2717, 2747, 2772, 2791, 2806, 2817, 2823, 2825, 2822, 2815, 2804, 2788, 2767, 2740, 2708, 2669, 2669, 2669, 2667, 2666, 2663, 2660, 2656, 2651, 2645, 2639, 2632, 2624, 2615, 2605, 2595, 2583, 2571, 2557, 2543, 2527]
ankle_val_right =   [1651, 1635, 1625, 1618, 1614, 1613, 1614, 1618, 1623, 1631, 1640, 1651, 1664, 1678, 1694, 1711, 1730, 1751, 1773, 1798, 1798, 1787, 1777, 1767, 1757, 1747, 1738, 1729, 1721, 1712, 1704, 1697, 1689, 1682, 1676, 1670, 1664, 1659, 1655, 1651]
ankle_twist_right = [2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2014, 2003, 1980, 1969, 1947, 1936, 1914, 1903, 1880, 1880, 1903, 1914, 1936, 1947, 1969, 1980, 2003, 2014, 2036]

abduc_val_left =    [2036, 2014, 2003, 1980, 1969, 1947, 1936, 1914, 1903, 1880, 1880, 1903, 1914, 1936, 1947, 1969, 1980, 2003, 2014, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036]
hip_val_left =      [2431, 2420, 2408, 2396, 2384, 2371, 2358, 2344, 2330, 2315, 2300, 2285, 2269, 2252, 2235, 2217, 2199, 2181, 2161, 2141, 2141, 2187, 2228, 2263, 2295, 2324, 2350, 2373, 2394, 2412, 2427, 2440, 2450, 2458, 2462, 2463, 2461, 2455, 2445, 2431]
knee_val_left =     [2669, 2669, 2667, 2666, 2663, 2660, 2656, 2651, 2645, 2639, 2632, 2624, 2615, 2605, 2595, 2583, 2571, 2557, 2543, 2527, 2527, 2588, 2639, 2682, 2717, 2747, 2772, 2791, 2806, 2817, 2823, 2825, 2822, 2815, 2804, 2788, 2767, 2740, 2708, 2669]
ankle_val_left =    [1798, 1787, 1777, 1767, 1757, 1747, 1738, 1729, 1721, 1712, 1704, 1697, 1689, 1682, 1676, 1670, 1664, 1659, 1655, 1651, 1651, 1635, 1625, 1618, 1614, 1613, 1614, 1618, 1623, 1631, 1640, 1651, 1664, 1678, 1694, 1711, 1730, 1751, 1773, 1798]
ankle_twist_left =  [2036, 2058, 2069, 2092, 2103, 2125, 2136, 2158, 2169, 2192, 2192, 2169, 2158, 2136, 2125, 2103, 2092, 2069, 2058, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036, 2036]

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
