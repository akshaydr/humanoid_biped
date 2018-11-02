#!/usr/bin/env python

import rospy

# Rotation = 1036 - 3036 (ID 1)
# Abduction = 1500 - 2500 (ID 2)
# Flexion = 1036 - 3036 (ID 3)
# Knee = 550 - 2236 (ID 4)
# Ankle Twist = 1500 - 2600 (ID 5)
# Ankle = 1500 - 2500 (ID 6)

# Invert ID's 2, 3

def constrain(mag, joint):

    if (joint == 1):
        min = 1036.0
        max = 3036.0

    elif (joint == 2):
        min = 1500.0
        max = 2500.0
        # mag = invert(mag)

    elif (joint == 3):
        min = 1036.0
        max = 3036.0
        mag = invert(mag)

    elif (joint == 4):
        min = 550.0
        max = 2236.0
        mag = invert(mag)

    elif (joint == 5):
        min = 1500.0
        max = 2600.0
        mag = invert(mag)

    elif (joint == 6):
        min = 1500.0
        max = 2500.0
        # mag = invert(mag)

    if (joint == 7):
        min = 1036.0
        max = 3036.0

    elif (joint == 8):
        min = 1500.0
        max = 2500.0
        # mag = invert(mag)

    elif (joint == 9):
        min = 1036.0
        max = 3036.0
        mag = invert(mag)

    elif (joint == 10):
        min = 550.0
        max = 2236.0
        mag = invert(mag)

    elif (joint == 11):
        min = 1500.0
        max = 2600.0
        mag = invert(mag)

    elif (joint == 12):
        min = 1500.0
        max = 2500.0
        # mag = invert(mag)

    elif (joint == 13):
        min = 1500.0
        max = 2500.0
        mag = invert(mag)

    elif (joint == 14):
        min = 1470.0
        max = 2600.0
        mag = invert(mag)

    if (mag < min):
        return (min)
    elif (mag > max):
        return (max)
    else:
        return mag

def invert(val):
    mid = 2036
    temp = mid - val
    return (mid + temp)
