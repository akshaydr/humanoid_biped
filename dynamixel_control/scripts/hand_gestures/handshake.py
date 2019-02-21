#!/usr/bin/env python

import os, ctypes
from sensor_msgs.msg import JointState
import serial
import time
import numpy as np
import Tkinter as tk
import rospy
from std_msgs.msg import String
import pyttsx3
import rospy
from time import sleep

if os.name == 'nt':
    import msvcrt
    def getch():
        return msvcrt.getch().decode()
else:
    import sys, tty, termios
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    def getch():
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch
             # Path setting

# os.sys.path.append('../dynamixel_functions_py')

import dynamixel_functions as dynamixel                     # Uses Dynamixel SDK library

# Control table address
#ADDR_PRO_TORQUE_ENABLE      = 562                           # Control table address is different in Dynamixel model
#ADDR_PRO_GOAL_POSITION      = 596
#ADDR_PRO_PRESENT_POSITION   = 611
ADDR_PRO_TORQUE_ENABLE       = 64                          # Control table address is different in Dynamixel model
ADDR_PRO_GOAL_POSITION       = 116
ADDR_PRO_PRESENT_POSITION    = 132
ADDR_PRO_PROFILE_ACCELERATION= 108
ADDR_PRO_PROFILE_VELOCITY    = 112
DXL_VELOCITY=30
DXL_ACCELERATION = 100
# Data Byte Length
LEN_PRO_GOAL_POSITION       = 4
LEN_PRO_PRESENT_POSITION    = 4
LEN_PRO_GOAL_VELOCITY = 4
# Protocol version
PROTOCOL_VERSION            = 2                             # See which protocol version is used in the Dynamixel

# Default setting
DXL1_ID                     = 15                             # Dynamixel ID: 1
DXL2_ID                     = 16
DXL3_ID                     = 17                            # Dynamixel ID: 1
DXL4_ID                     = 18
DXL5_ID                     = 19                            # Dynamixel ID: 1
DXL6_ID                     = 20
DXL7_ID                     = 21                            # Dynamixel ID: 1
DXL8_ID                     = 22
# DXL9_ID                     = 9                             # Dynamixel ID: 1
# DXL10_ID                    = 10
DXL11_ID                    = 23
DXL12_ID                    = 24
BAUDRATE                    = 1000000
DEVICENAME                  = "/dev/ttyUSB1".encode('utf-8')# Check which port is being used on your controller
                                                            # ex) Windows: "COM1"   Linux: "/dev/ttyUSB0" Mac: "/dev/tty.usbserial-*"

TORQUE_ENABLE               = 1                             # Value for enabling the torque
TORQUE_DISABLE              = 0                             # Value for disabling the torque
#DXL1_MINIMUM_POSITION_VALUE  = 0                            # Dynamixel will rotate between this value
#DXL1_MAXIMUM_POSITION_VALUE  = 4095                        # and this value (note that the Dynamixel would not move when the position valueout of movable range. Check e-manual about the range of the Dynamixel you use.)
#DXL2_MINIMUM_POSITION_VALUE  = 0
#DXL2_MAXIMUM_POSITION_VALUE  = 2048
DXL1_MOVING_STATUS_THRESHOLD = 20                            # Dynamixel moving status threshold
DXL2_MOVING_STATUS_THRESHOLD = 20
DXL3_MOVING_STATUS_THRESHOLD = 20                            # Dynamixel moving status threshold
DXL4_MOVING_STATUS_THRESHOLD = 20
DXL5_MOVING_STATUS_THRESHOLD = 20                            # Dynamixel moving status threshold
DXL6_MOVING_STATUS_THRESHOLD = 20
DXL7_MOVING_STATUS_THRESHOLD = 20                            # Dynamixel moving status threshold
DXL8_MOVING_STATUS_THRESHOLD = 20
# DXL9_MOVING_STATUS_THRESHOLD = 20                            # Dynamixel moving status threshold
# DXL10_MOVING_STATUS_THRESHOLD = 20
DXL11_MOVING_STATUS_THRESHOLD = 20
DXL12_MOVING_STATUS_THRESHOLD = 20
ESC_ASCII_VALUE             = 0x1b

COMM_SUCCESS                = 0                             # Communication Success result value
COMM_TX_FAIL                = -1001                         # Communication Tx Failed

# Initialize PortHandler Structs
# Set the port path
# Get methods and members of PortHandlerLinux or PortHandlerWindows
port_num = dynamixel.portHandler(DEVICENAME)

# Initialize PacketHandler Structs
dynamixel.packetHandler()

# Initialize Groupsyncwrite instance
groupwrite_num = dynamixel.groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_PRO_GOAL_POSITION, LEN_PRO_GOAL_POSITION)

# Initialize Groupsyncread Structs for Present Position
groupread_num = dynamixel.groupSyncRead(port_num, PROTOCOL_VERSION, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

index = 0
dxl_comm_result = COMM_TX_FAIL                              # Communication result
dxl_addparam_result = 0                                     # AddParam result
dxl_getdata_result = 0                                      # GetParam result
dxl1_goal_position = 0
dxl2_goal_position = 0
dxl3_goal_position = 0
dxl4_goal_position = 0
dxl5_goal_position = 0
dxl6_goal_position = 0
dxl7_goal_position = 0
dxl8_goal_position = 0
# dxl9_goal_position = 0
# dxl10_goal_position = 0
dxl11_goal_position = 0
dxl12_goal_position = 0

dxl_error = 0                                               # Dynamixel error
dxl1_present_position = 0                                   # Present position
dxl2_present_position = 0
dxl4_present_position = 0                                   # Present position
dxl3_present_position = 0
dxl5_present_position = 0                                   # Present position
dxl6_present_position = 0
dxl7_present_position = 0                                   # Present position
dxl8_present_position = 0
# dxl9_present_position = 0                                   # Present position
# dxl10_present_position = 0
dxl11_present_position = 0
dxl12_present_position = 0

# Open port
if dynamixel.openPort(port_num):
    print("Succeeded to open the port!")
else:
    print("Failed to open the port!")
    print("Press any key to terminate...")
    getch()
    quit()


# Set port baudrate
if dynamixel.setBaudRate(port_num, BAUDRATE):
    print("Succeeded to change the baudrate!")
else:
    print("Failed to change the baudrate!")
    print("Press any key to terminate...")
    getch()
    quit()


# Enable Dynamixel#1 Torque
dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL1_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL1_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL1_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#1 has been successfully connected")

# Enable Dynamixel#2 Torque
dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL2_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL2_ID, ADDR_PRO_PROFILE_VELOCITY, 7)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL2_ID, ADDR_PRO_PROFILE_ACCELERATION, 20)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#2 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL3_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL3_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL3_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#3 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL4_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL4_ID, ADDR_PRO_PROFILE_ACCELERATION, 100)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL4_ID, ADDR_PRO_PROFILE_VELOCITY, 30)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#4 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL5_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL5_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL5_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#5 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL6_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL6_ID, ADDR_PRO_PROFILE_ACCELERATION, 15)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL6_ID, ADDR_PRO_PROFILE_VELOCITY, 5)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#6 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL7_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL7_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL7_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#7 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL8_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL8_ID, ADDR_PRO_PROFILE_ACCELERATION, 100)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL8_ID, ADDR_PRO_PROFILE_VELOCITY, 30)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#8 has been successfully connected")

# dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL9_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
# dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL9_ID, ADDR_PRO_PROFILE_ACCELERATION, 20)
# dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL9_ID, ADDR_PRO_PROFILE_VELOCITY, 7)
# dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
# dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
# if dxl_comm_result != COMM_SUCCESS:
#     print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
# elif dxl_error != 0:
#     print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
# else:
#     print("Dynamixel#9 has been successfully connected")
#
# dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL10_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
# dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL10_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
# dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL10_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
# dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
# dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
# if dxl_comm_result != COMM_SUCCESS:
#     print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
# elif dxl_error != 0:
#     print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
# else:
#     print("Dynamixel#10 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL11_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL11_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL11_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#11 has been successfully connected")

dynamixel.write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL12_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL12_ID, ADDR_PRO_PROFILE_ACCELERATION, DXL_ACCELERATION)
dynamixel.write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL12_ID, ADDR_PRO_PROFILE_VELOCITY, DXL_VELOCITY)
dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
dxl_error = dynamixel.getLastRxPacketError(port_num, PROTOCOL_VERSION)
if dxl_comm_result != COMM_SUCCESS:
    print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))
elif dxl_error != 0:
    print(dynamixel.getRxPacketError(PROTOCOL_VERSION, dxl_error))
else:
    print("Dynamixel#12 has been successfully connected")

# Add parameter storage for Dynamixel#1 present position value
dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL1_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL1_ID))
    quit()

# Add parameter storage for Dynamixel#2 present position value
dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL2_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL2_ID))
    quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL3_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL3_ID))
    quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL4_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL4_ID))
    quit()

# Add parameter storage for Dynamixel#5 present position value
dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL5_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL5_ID))
    quit()

# Add parameter storage for Dynamixel#6 present position value
dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL6_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL6_ID))
    quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL7_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL7_ID))
    quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL8_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL8_ID))
    quit()

# dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL9_ID)).value
# if dxl_addparam_result != 1:
#     print("[ID:%03d] groupSyncRead addparam failed" % (DXL9_ID))
#     quit()
#
# dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL10_ID)).value
# if dxl_addparam_result != 1:
#     print("[ID:%03d] groupSyncRead addparam failed" % (DXL10_ID))
#     quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL11_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL11_ID))
    quit()

dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncReadAddParam(groupread_num, DXL12_ID)).value
if dxl_addparam_result != 1:
    print("[ID:%03d] groupSyncRead addparam failed" % (DXL12_ID))
    quit()



def home():
        time.sleep(3)
        y = np.array([0.0, 0.0, -.11, 0.0, 0.0, 0.0, 0.0, 1.38097807196551, -8.858780171722174e-05, 6.12030400428921e-05, 1.8102984875440598e-06, -4.31329638697207e-05])
        motor(y)
	i=0
        for i in range (0,3):
            y = np.array([0.0, 0.0, -.11, 0.0, 0.0, 0.0, 0.0, 1.38097807196551, -8.858780171722174e-05, 6.12030400428921e-05, 1.8102984875440598e-06, -4.31329638697207e-05])
            motor(y)
            time.sleep(1)
            y1 = np.array([0.0, 0.0, -.11, 0.0, 0.0, 0.0, 0.0, 1.3809486451338044, -5.251366132870317e-05, -4.605242689140141e-05, 0.34527781052766365, -2.8771334933117034e-05])
            motor(y1)
            time.sleep(1)
        y2= np.array([0,0,-.11,0,0,0,0,0,0,0,0,0])
        motor(y2)
	quit()







def motor(y):




    z=np.array([57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578,57.29578])
    mul=y*z
    s=np.array([0,0,0,0,0,0,0,0,0,0,0,0])
    add = mul+s
    li=add.tolist()

    trunk_pitch_joint,trunk_roll_joint,left_shoulder_pitch_joint,left_shoulder_roll_joint,left_shoulder_yaw_joint,left_shoulder_elbow_pitch_joint,left_wrist_roll_joint,right_shoulder_pitch_joint,right_shoulder_roll_joint,right_shoulder_yaw_joint,right_shoulder_elbow_pitch_joint,right_wrist_roll_joint=li
    dxl1_goal_position=left_shoulder_pitch_joint
    dxl2_goal_position=left_shoulder_roll_joint
    dxl3_goal_position=left_shoulder_yaw_joint
    dxl4_goal_position=left_shoulder_elbow_pitch_joint
    dxl5_goal_position=right_shoulder_pitch_joint
    dxl6_goal_position=right_shoulder_roll_joint
    dxl7_goal_position=right_shoulder_yaw_joint
    dxl8_goal_position=right_shoulder_elbow_pitch_joint
    # dxl9_goal_position=trunk_pitch_joint
    # dxl10_goal_position=trunk_roll_joint
    dxl11_goal_position=right_wrist_roll_joint
    dxl12_goal_position=left_wrist_roll_joint
    #1
    if dxl1_goal_position>=0:
    	dxl1_goal_position=int((11.37*dxl1_goal_position)+2048)
    else:
	    dxl1_goal_position=int((2048)+(11.37*dxl1_goal_position))
    #2
    if dxl2_goal_position>=0:
    	dxl2_goal_position=int((11.37*dxl2_goal_position)+2048)
    else:
	    dxl2_goal_position=int(2048+(11.37*dxl2_goal_position))
    #3
    if dxl3_goal_position>=0:
    	dxl3_goal_position=int((11.37*dxl3_goal_position)+2048)
    else:
	    dxl3_goal_position=int(2048+(11.37*dxl3_goal_position))
    #4
    if dxl4_goal_position>=0:
    	dxl4_goal_position=int((11.37*dxl4_goal_position)+2048)
    else:
	    dxl4_goal_position=int(2048+(11.37*dxl4_goal_position))
    #5
    if dxl5_goal_position>=0:
    	dxl5_goal_position=int((11.37*dxl5_goal_position)+2048)
    else:
	    dxl5_goal_position=int(2048+(11.37*dxl5_goal_position))
    #6
    if dxl6_goal_position>=0:
    	dxl6_goal_position=int((11.37*dxl6_goal_position)+2048)
    else:
	    dxl6_goal_position=int(2048+(11.37*dxl6_goal_position))
    #7
    if dxl7_goal_position>=0:
    	dxl7_goal_position=int((11.37*dxl7_goal_position)+2048)
    else:
	    dxl7_goal_position=int(2048+(11.37*dxl7_goal_position))
    #8
    if dxl8_goal_position>=0:
    	dxl8_goal_position=int((11.37*dxl8_goal_position)+2048)
    else:
	    dxl8_goal_position=int(2048+(11.37*dxl8_goal_position))
    #9
    # if dxl9_goal_position>=0:
    # 	dxl9_goal_position=int((11.37*dxl9_goal_position)+2048)
    # else:
	#     dxl9_goal_position=int(2048+(11.37*dxl9_goal_position))
    # #10
    # if dxl10_goal_position>=0:
    # 	dxl10_goal_position=int((11.37*dxl10_goal_position)+2048)
    # else:
	#     dxl10_goal_position=int(2048+(11.37*dxl10_goal_position))
    #11
    if dxl11_goal_position>=0:
    	dxl11_goal_position=int((11.37*dxl11_goal_position)+2048)
    else:
	    dxl11_goal_position=int(2048+(11.37*dxl11_goal_position))
    #12
    if dxl12_goal_position>=0:
    	dxl12_goal_position=int((11.37*dxl12_goal_position)+2048)
    else:
	    dxl12_goal_position=int(2048+(11.37*dxl12_goal_position))

    print(dxl12_goal_position)
    print(dxl11_goal_position)
    # print(dxl10_goal_position)
    # print(dxl9_goal_position)
    print(dxl8_goal_position)
    print(dxl7_goal_position)
    print(dxl6_goal_position)
    print(dxl5_goal_position)
    print(dxl4_goal_position)
    print(dxl3_goal_position)
    print(dxl2_goal_position)
    print(dxl1_goal_position)

    if (dxl1_goal_position>=0) and (dxl1_goal_position<114):
        dxl1_goal_position = 114
    elif dxl1_goal_position>3868:
        dxl1_goal_position=3868
    #elif dxl1_goal_position<1:
        #dxl1_goal_position = 2048
    if dxl2_goal_position<1820:
        dxl2_goal_position=1820
    elif dxl2_goal_position>3982:
        dxl2_goal_position=3982
    if (dxl3_goal_position>=0) and (dxl3_goal_position<114):
        dxl3_goal_position = 114
    elif dxl3_goal_position>4038:
        dxl3_goal_position=4038
    #elif dxl3_goal_position<1:
        #dxl3_goal_position = 2048
    if dxl4_goal_position>3300:
        dxl4_goal_position = 3300
    elif dxl4_goal_position<1024:
        dxl4_goal_position=1024
    if (dxl5_goal_position>=0) and (dxl5_goal_position<114):
        dxl5_goal_position = 114
    elif dxl5_goal_position>3868:
        dxl5_goal_position=3868
    #elif dxl5_goal_position<1:
        #dxl5_goal_position = 2048
    if dxl6_goal_position>3868:
        dxl6_goal_position=3868
    elif dxl6_goal_position<1820:
        dxl6_goal_position=1820
    if (dxl7_goal_position>=0) and (dxl7_goal_position<114):
        dxl7_goal_position = 114
    elif dxl7_goal_position>4038:
        dxl7_goal_position=4038
        #elif dxl7_goal_position<1:
        #dxl7_goal_position = 2048
    if dxl8_goal_position>3300:
        dxl8_goal_position = 3300
    elif dxl8_goal_position<1024:
        dxl8_goal_position=1024
    # if dxl9_goal_position>2732:
    #     dxl9_goal_position = 2732
    # elif dxl9_goal_position<2048:
    #     dxl9_goal_position=2048
    # if dxl10_goal_position>2276:
    #     dxl10_goal_position = 2276
    # elif dxl10_goal_position<1820:
    #     dxl10_goal_position=1820
    if dxl11_goal_position>3072:
        dxl11_goal_position = 3072
    elif dxl11_goal_position<1024:
        dxl11_goal_position=1024
    if dxl12_goal_position>3072:
        dxl12_goal_position = 3072
    elif dxl12_goal_position<1024:
        dxl12_goal_position=1024


    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL1_ID, dxl1_goal_position, LEN_PRO_GOAL_POSITION)).value
    print(dxl_addparam_result)
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL1_ID))
        quit()

    # Add Dynamixel#2 goal position value to the Syncwrite parameter storage
    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL2_ID, dxl2_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL2_ID))
        quit()

    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL3_ID, dxl3_goal_position, LEN_PRO_GOAL_POSITION)).value
    print(dxl_addparam_result)
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL3_ID))
        quit()

    # Add Dynamixel#2 goal position value to the Syncwrite parameter storage
    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL4_ID, dxl4_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL4_ID))
        quit()

    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL5_ID, dxl5_goal_position, LEN_PRO_GOAL_POSITION)).value
    print(dxl_addparam_result)
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL5_ID))
        quit()

    # Add Dynamixel#2 goal position value to the Syncwrite parameter storage
    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL6_ID, dxl6_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL6_ID))
        quit()

    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL7_ID, dxl7_goal_position, LEN_PRO_GOAL_POSITION)).value
    print(dxl_addparam_result)
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL7_ID))
        quit()

    # Add Dynamixel#2 goal position value to the Syncwrite parameter storage
    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL8_ID, dxl8_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL8_ID))
        quit()

    # dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL9_ID, dxl9_goal_position, LEN_PRO_GOAL_POSITION)).value
    # print(dxl_addparam_result)
    # if dxl_addparam_result != 1:
    #     print("[ID:%03d] groupSyncWrite addparam failed" % (DXL9_ID))
    #     quit()
    #
    # # Add Dynamixel#2 goal position value to the Syncwrite parameter storage
    # dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL10_ID, dxl10_goal_position, LEN_PRO_GOAL_POSITION)).value
    # if dxl_addparam_result != 1:
    #     print("[ID:%03d] groupSyncWrite addparam failed" % (DXL10_ID))
    #     quit()
    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL11_ID, dxl11_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL11_ID))
        quit()

    dxl_addparam_result = ctypes.c_ubyte(dynamixel.groupSyncWriteAddParam(groupwrite_num, DXL12_ID, dxl12_goal_position, LEN_PRO_GOAL_POSITION)).value
    if dxl_addparam_result != 1:
        print("[ID:%03d] groupSyncWrite addparam failed" % (DXL12_ID))
        quit()

    # Syncwrite goal position
    dynamixel.groupSyncWriteTxPacket(groupwrite_num)
    dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
    if dxl_comm_result != COMM_SUCCESS:
        print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))

    # Clear syncwrite parameter storage
    dynamixel.groupSyncWriteClearParam(groupwrite_num)

    while 1:
        # Syncread present position
        dynamixel.groupSyncReadTxRxPacket(groupread_num)
        dxl_comm_result = dynamixel.getLastTxRxResult(port_num, PROTOCOL_VERSION)
        if dxl_comm_result != COMM_SUCCESS:
            print(dynamixel.getTxRxResult(PROTOCOL_VERSION, dxl_comm_result))

        # Check if groupsyncread data of Dynamixel#1 is available
        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL1_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL1_ID))
            quit()

        # Check if groupsyncread data of Dynamixel#2 is available
        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL2_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL2_ID))
            quit()

        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL3_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL3_ID))
            quit()

        # Check if groupsyncread data of Dynamixel#2 is available
        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL4_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL4_ID))
            quit()

        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL5_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL5_ID))
            quit()

        # Check if groupsyncread data of Dynamixel#2 is available
        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL6_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL6_ID))
            quit()

        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL7_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL7_ID))
            quit()

        # Check if groupsyncread data of Dynamixel#2 is available
        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL8_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL8_ID))
            quit()

        # dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL9_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        # if dxl_getdata_result != 1:
        #     print("[ID:%03d] groupSyncRead getdata failed" % (DXL9_ID))
        #     quit()
        #
        # # Check if groupsyncread data of Dynamixel#2 is available
        # dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL10_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        # if dxl_getdata_result != 1:
        #     print("[ID:%03d] groupSyncRead getdata failed" % (DXL10_ID))
        #     quit()

        dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL11_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL11_ID))
            quit()
	# dxl_getdata_result = ctypes.c_ubyte(dynamixel.groupSyncReadIsAvailable(groupread_num, DXL10_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)).value
        if dxl_getdata_result != 1:
            print("[ID:%03d] groupSyncRead getdata failed" % (DXL12_ID))
            quit()


        # Get Dynamixel#1 present position value
        dxl1_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL1_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        # Get Dynamixel#2 present position value
        dxl2_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL2_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        dxl3_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL3_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        # Get Dynamixel#2 present position value
        dxl4_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL4_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

# Get Dynamixel#5 present position value
        dxl5_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL5_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        # Get Dynamixel#6 present position value
        dxl6_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL6_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        dxl7_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL7_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        # Get Dynamixel#2 present position value
        dxl8_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL8_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        # dxl9_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL9_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)
        #
        # # Get Dynamixel#2 present position value
        # dxl10_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL10_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        dxl11_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL11_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        dxl12_present_position = dynamixel.groupSyncReadGetData(groupread_num, DXL12_ID, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

        break

if __name__ == '__main__':
    rospy.init_node('handshake_program', anonymous=True)
    home()
