#!/usr/bin/env python

import rospy

# Maximum and minimum angles
# rotation_left = 0 - 4090
# abduction_left = 1872 - 2687 (No zero)
# flexion_left = 1302 - 2720 (No zero)
#  knee_left = 780 - 3324 (No zero)
#  ankle_left = TODO

# rotation_right = TODO
# abduction_right = TODO
# flexion_right = TODO
#  knee_right = TODO
#  ankle_right = TODO

# mid_section = 1621 - 2296


# Initial position angles
# abduction_left = 2545
# rotation_left = 3062
# flexion_left = 1536
#  knee_left = 2050
#  ankle_left = TODO

# rotation_right = 0 - 4090
# abduction_right =
# flexion_right = 1302 - 2720 (No zero)
#  knee_right = 780 - 3324 (No zero)
#  ankle_right =

# mid_section = 2012


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

    elif (joint == "abduction_left"):
        max = 2687.0
        min = 1872.0

    if (mag < min):
        return (min)
    elif (mag > max):
        return (max)
    else:
        return mag
