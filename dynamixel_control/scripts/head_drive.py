#!/usr/bin/env python
import os
import rospy
from time import sleep
from std_msgs.msg import Float64
from motor_param import *
from realsense_ros_object.msg import *

# Maximum Width camera can cover 2.4
# Distance to which angle was generated 2.5
# Angle camera can cover is 50 degrees
# In dynamixel 2450 - 1680

# Up - Down maximum angles is 1850 - 2246


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

from dynamixel_sdk import *                    # Uses Dynamixel SDK library
# 1850
up_down_joint = 2048
left_right_joint = 2048
previous_val = 0
first_val = True

# Control table address
ADDR_PRO_TORQUE_ENABLE      = 64               # Control table address is different in Dynamixel model
ADDR_PRO_GOAL_POSITION      = 116
ADDR_PRO_PRESENT_POSITION   = 132

# Data Byte Length
LEN_PRO_GOAL_POSITION       = 4
LEN_PRO_PRESENT_POSITION    = 4

# Protocol version
PROTOCOL_VERSION            = 2.0               # See which protocol version is used in the Dynamixel

# Default setting
DXL13_ID                     = 13              # Dynamixel#1 ID : 1
DXL14_ID                     = 14                # Dynamixel#1 ID : 1

BAUDRATE                    = 1000000             # Dynamixel default baudrate : 57600
DEVICENAME                  = '/dev/ttyUSB0'    # Check which port is being used on your controller
                                                # ex) Windows: "COM1"   Linux: "/dev/ttyUSB0" Mac: "/dev/tty.usbserial-*"

TORQUE_ENABLE               = 1                 # Value for enabling the torque
TORQUE_DISABLE              = 0                 # Value for disabling the torque
DXL_MINIMUM_POSITION_VALUE  = 100          # Dynamixel will rotate between this value
DXL_MAXIMUM_POSITION_VALUE  = 4000            # and this value (note that the Dynamixel would not move when the position value is out of movable range. Check e-manual about the range of the Dynamixel you use.)
DXL_MOVING_STATUS_THRESHOLD = 20                # Dynamixel moving status threshold

index = 0
dxl_goal_position = [DXL_MINIMUM_POSITION_VALUE, DXL_MAXIMUM_POSITION_VALUE]         # Goal position


portHandler = PortHandler(DEVICENAME)
packetHandler = PacketHandler(PROTOCOL_VERSION)
groupSyncWrite = GroupSyncWrite(portHandler, packetHandler, ADDR_PRO_GOAL_POSITION, LEN_PRO_GOAL_POSITION)
groupSyncRead = GroupSyncRead(portHandler, packetHandler, ADDR_PRO_PRESENT_POSITION, LEN_PRO_PRESENT_POSITION)

# Open port
if portHandler.openPort():
    print("Succeeded to open the port")
else:
    print("Failed to open the port")
    print("Press any key to terminate...")
    getch()
    quit()

# Set port baudrate
if portHandler.setBaudRate(BAUDRATE):
    print("Succeeded to change the baudrate")
else:
    print("Failed to change the baudrate")
    print("Press any key to terminate...")
    getch()
    quit()


def initialize_motor(ID):
    # Enable Dynamixel#1 Torque
    dxl_comm_result, dxl_error = packetHandler.write1ByteTxRx(portHandler, ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE)
    if dxl_comm_result != COMM_SUCCESS:
        print("%s" % packetHandler.getTxRxResult(dxl_comm_result))
    elif dxl_error != 0:
        print("%s" % packetHandler.getRxPacketError(dxl_error))
    else:
        print("Dynamixel#%d has been successfully connected" % ID)

    # Add parameter storage for Dynamixel#1 present position value
    dxl_addparam_result = groupSyncRead.addParam(ID)
    if dxl_addparam_result != True:
        print("[ID:%03d] groupSyncRead addparam failed" % ID)
        quit()

def run_motor(ID, data):
    # Allocate goal position value into byte array
    param_goal_position = [DXL_LOBYTE(DXL_LOWORD(int(data))), DXL_HIBYTE(DXL_LOWORD(int(data))), DXL_LOBYTE(DXL_HIWORD(int(data))), DXL_HIBYTE(DXL_HIWORD(int(data)))]

    # Add Dynamixel#1 goal position value to the Syncwrite parameter storage
    dxl_addparam_result = groupSyncWrite.addParam(ID, param_goal_position)
    if dxl_addparam_result != True:
        print("[ID:%03d] groupSyncWrite addparam failed" % ID)
        quit()

    # Syncwrite goal position
    dxl_comm_result = groupSyncWrite.txPacket()
    if dxl_comm_result != COMM_SUCCESS:
        print("%s" % packetHandler.getTxRxResult(dxl_comm_result))

    groupSyncWrite.clearParam()
    # Clear syncwrite parameter storage

def torque_diable(ID):
    # Disable Dynamixel Torque
    dxl_comm_result, dxl_error = packetHandler.write1ByteTxRx(portHandler, ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_DISABLE)
    if dxl_comm_result != COMM_SUCCESS:
        print("%s" % packetHandler.getTxRxResult(dxl_comm_result))
    elif dxl_error != 0:
        print("%s" % packetHandler.getRxPacketError(dxl_error))

# def change_detect(value, change):
#     global first_val, previous_val
#     if (first_val == True):
#         previous_val = value
#         first_val = False
#         return previous_val
#
#     print(value, previous_val, change)
#
#     if (value - previous_val >= change or value - previous_val <= -change):
#         print ("previous_val")
#         previous_val = value
#         return value
#     else:
#         return previous_val
#     # previous_val = left_right_joint

def object_callback(msg):
    global left_right_joint, lf_joint
    for i in range(len(msg.objects_vector)):
        # print(msg.objects_vector[i].object.object_name)
        if (msg.objects_vector[i].object.object_name == "cabinet"):
            # X = Left/Right, Y = Up/Down Z = Distance
            # X range =
            # print(msg.objects_vector[i].location.coordinates)
            # print(msg.objects_vector[i].object_bbox.x)
            if (msg.objects_vector[i].object_bbox.x == 0 or msg.objects_vector[i].object_bbox.y == 0):
                left_right_joint = 2048
            else:
                # left_right_joint = (change_detect(msg.objects_vector[i].object_bbox.x, 300) + 1110) #1110
                left_right_joint = (msg.objects_vector[i].object_bbox.x + 1110) #1110
                up_down_joint = (msg.objects_vector[i].object_bbox.y + 1850) #1110
            # print left_right_joint
            # print(msg.objects_vector[i].object_bbox.y)

    # print (msg.objects_vector[2].object.object_name)

if __name__ == '__main__':
    initialize_motor(DXL13_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL14_ID) #Enter Motor ID to enable torque and add parameter storage

    rospy.init_node('motor_drive', anonymous=True)
    rospy.Subscriber("/realsense/localized_tracked_objects", ObjectsInBoxes, object_callback)

    # run_motor(DXL13_ID, constrain(up_down_joint, DXL13_ID))
    # run_motor(DXL14_ID, constrain(left_right_joint, DXL14_ID))

    rate = rospy.Rate(100)

while not rospy.is_shutdown():
    # print (abduction_right, ankle_twist_right, abduction_left, ankle_twist_left)
    # 570 - 1350
    # 1680 - 2450

    time.sleep(1)
    if (first_val == True):
        first_val = False
        print(left_right_joint)
        run_motor(DXL14_ID, constrain(left_right_joint , DXL14_ID))
        run_motor(DXL13_ID, constrain(up_down_joint , DXL13_ID))

    # run_motor(DXL14_ID, constrain(, DXL14_ID))

    rate.sleep()

    if (rospy.is_shutdown()):
        print("Shutting down. Motor torque disabled.")
        # torque_diable(DXL13_ID)
        # torque_diable(DXL14_ID)
        portHandler.closePort()   # Close port
        print("Port Closed")
