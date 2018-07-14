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
        max = 2700
        min = 1300

    elif (joint == "knee_left"):
        max = 3320
        min = 800

    if (mag < min):
        return (mini)
    elif (mag > max):
        return (maxi)
    else:
        return mag

def flexion_left(mag):
    if (mag<1302):
        return (mini)
    elif (mag>2702):
        return (maxi)
    else:
        return mag
