#!/usr/bin/env python

import rospy

# rotation_left = 0 - 4090
# abduction_left =
# flexion_left = 1302 - 2720 (No zero)
#  knee_left = 780 - 3324 (No zero)
#  ankle_left =

# rotation_right = 0 - 4090
# abduction_right =
# flexion_right = 1302 - 2720 (No zero)
#  knee_right = 780 - 3324 (No zero)
#  ankle_right =

def constrain(mag, joint):
    if (joint == "flexion_left"):
        max = 2700.0
        min = 1300.0

    elif (joint == "knee_left"):
        max = 3320.0
        min = 800.0

    elif (joint == "rotation_left"):
        max = 4090.0
        min = 0.0

    if (mag < min):
        return (min)
    elif (mag > max):
        return (max)
    else:
        return mag
