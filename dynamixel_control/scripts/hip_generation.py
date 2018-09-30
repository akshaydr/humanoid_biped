#!/usr/bin/env python

import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

pres_time = 0.0
total_time = 1.0
initial_angle = 180.4
peak_angle = 1000.6

# val = [2036, 22.8, 36.8, 42.8, 41.7, 34, 20.3, 0.8, -23.9, -53.8, -88.6, -128.2, -172.4, -221.3, -275.2, -334.3, -399.4, -471.5, -552.4, -645.4]
# hip_val = [2036, 2059, 2073, 2079, 2078, 2070, 2056, 2037, 2012, 1982, 1947, 1908, 1863, 1815, 1761, 1702, 1637, 1565, 1484, 1391]
# knee_val = [2036, 1955, 1888, 1833, 1790, 1758, 1735, 1722, 1719, 1724, 1739, 1763, 1796, 1839, 1893, 1958, 2036, 2129, 2240, 2375]

hip_val = [2793, 2815, 2829, 2835, 2834, 2826, 2813, 2793, 2768, 2738, 2704, 2664, 2620, 2571, 2517, 2458, 2393, 2321, 2240, 2147]
knee_val = [720, 639, 573, 518, 475, 443, 420, 407, 403, 408, 423, 447, 480, 524, 577, 643, 721, 814, 925, 1060]

i = 0;

if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)
    pub1 = rospy.Publisher('knee_angle', Float64, queue_size=10)
    pub2 = rospy.Publisher('hip_angle', Float64, queue_size=10)

while (pres_time < total_time):
    pres_time += 0.05
    print (hip_val[i])
    pub1.publish(hip_val[i])
    pub2.publish(knee_val[i])
    i += 1
    sleep(0.05)
