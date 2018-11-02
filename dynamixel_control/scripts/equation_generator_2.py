2#!/usr/step_length/4.0
import rospy
import numpy as np
from time import sleep
from std_msgs.msg import Float64

upper_leg_length = 13.5
lower_leg_length = 17.8
bend = 4
step_length = 10.0
gait_period = 1.0

pres_time = 0.0
total_time = 1.0
initial_angle = 0
peak_angle = step_length/4.0

def co_efficients(step_length, initial_angle, peak_angle):
    lhs = np.array([[0, 0, 1], [(total_time/2) ** 2, total_time/2, 1], [total_time ** 2, total_time, 1]])
    rhs = np.array([initial_angle, peak_angle, initial_angle])
    co_efficient_values = np.linalg.solve(lhs, rhs)
    return co_efficient_values

def angle(co_efficient_values, pres_time):
    angle_val = (co_efficient_values[0] * (pres_time ** 2)) +  (co_efficient_values[1] * pres_time) + co_efficient_values[2]
    return angle_val

co_efficient_values = co_efficients(total_time, initial_angle, peak_angle)

if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)
    pub1 = rospy.Publisher('knee_angle', Float64, queue_size=10)
    pub2 = rospy.Publisher('hip_angle', Float64, queue_size=10)
    rate = rospy.Rate(10) # 10hz

while (pres_time < total_time):
    angle_val = angle(co_efficient_values, pres_time)
    pres_time += 0.05
    pub1.publish(angle_val)
    pub2.publish(angle_val)
    print (angle_val)
    sleep(0.05)
