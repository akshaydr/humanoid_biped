#!/usr/bin/env python

import rospy

# Maximum and minimum angles
# rotation_left =
# abduction_left =
# flexion_left =
#  knee_left =
#  ankle_left =

# rotation_right = 1036 - 3036 (ID 1)
# abduction_right = 1500 - 2500 (ID 2)
# flexion_right = 1036 - 3036 (ID 3)
# knee_right = 550 - 2236 (ID 4)
# ankle__twist_right = 1500 - 2600 (ID 5)
# ankle_right = 1500 - 2500 (ID 6)

# mid_section = 1621 - 2296
# body_section = 1149 - 2511

def constrain(mag, joint):

    if (joint == 1):
        min = 1036.0
        max = 3036.0

    elif (joint == 2):
        min = 1500.0
        max = 2500.0

    elif (joint == 3):
        min = 1036.0
        max = 3036.0

    elif (joint == 4):
        min = 550.0
        max = 2236.0

    elif (joint == 5):
        min = 1500.0
        max = 2600.0

    elif (joint == 6):
        min = 1500.0
        max = 2500.0

    if (mag < min):
        return (min)
    elif (mag > max):
        return (max)
    else:
        return mag
