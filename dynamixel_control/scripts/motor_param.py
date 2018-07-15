#!/usr/bin/env python

import rospy

# Maximum and minimum angles
# abduction_left = 1872 - 2687 (No zero)
# rotation_left = 0 - 4090
# flexion_left = 1302 - 2720 (No zero)
#  knee_left = 780 - 3324 (No zero)
#  ankle_left = TODO

# abduction_right = 1621 - 2663
# rotation_right = 0 - 4090
# flexion_right = 1954 - 3328
#  knee_right = 728 - 3362
#  ankle_right = TODO

# mid_section = 1621 - 2296
# body_section = 1149 - 2511

# Initial position angles
# abduction_left = 2642
# rotation_left = 3062
# flexion_left = 1536
#  knee_left = 2050
#  ankle_left = TODO

# abduction_right = 2621
# rotation_right = 2040
# flexion_right = 3054
#  knee_right = 2031
#  ankle_right = TODO

# mid_section = 2012
# body_section = 2015

def constrain(mag, joint):

    if (joint == "abduction_left"):
        min = 1872.0
        max = 2687.0

    elif (joint == "rotation_left"):
        min = 0.0
        max = 4090.0

    elif (joint == "flexion_left"):
        min = 1300.0
        max = 2700.0

    elif (joint == "knee_left"):
        min = 800.0
        max = 3320.0


    elif (joint == "abduction_right"):
        min = 1621.0
        max = 2663.0

    elif (joint == "rotation_right"):
        min = 0.0
        max = 4090.0

    elif (joint == "flexion_right"):
        min = 1354.0
        max = 3328.0

    elif (joint == "knee_right"):
        min = 728.0
        max = 3362.0


    elif (joint == "mid_section"):
        min = 1621.0
        max = 2296.0

    elif (joint == "uppper_body"):
        min = 1149.0
        max = 2511.0

    if (mag < min):
        return (min)
    elif (mag > max):
        return (max)
    else:
        return mag
