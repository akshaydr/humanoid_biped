#!/usr/bin/env python
import os
import rospy
from time import sleep
from std_msgs.msg import Float64
from motor_param import *


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
DXL15_ID                     = 15                             # Dynamixel ID: 1
DXL16_ID                     = 16
DXL17_ID                     = 17                            # Dynamixel ID: 1
DXL18_ID                     = 18
DXL19_ID                     = 19                            # Dynamixel ID: 1
DXL20_ID                     = 20
DXL21_ID                     = 21                            # Dynamixel ID: 1
DXL22_ID                     = 22
DXL23_ID                     = 23
DXL24_ID                     = 24

DXL25_ID                     = 25

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

right_1 = 2036
right_2 = 2036
right_3 = 2036
right_4 = 2036
right_5 = 2036

left_1 = 2036
left_2 = 2036
left_3 = 2036
left_4 = 2036
left_5 = 2036

head = 2036

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


def right_1_callback(msg):
    global right_1
    right_1 = msg.data
def right_2_callback(msg):
    global right_2
    right_2 = msg.data
def right_3_callback(msg):
    global right_3
    right_3 = msg.data
def right_4_callback(msg):
    global right_4
    right_4 = msg.data
def right_5_callback(msg):
    global right_5
    right_5 = msg.data

def left_1_callback(msg):
    global left_1
    left_1 = msg.data
def left_2_callback(msg):
    global left_2
    left_2 = msg.data
def left_3_callback(msg):
    global left_3
    left_3 = msg.data
def left_4_callback(msg):
    global left_4
    left_4 = msg.data
def left_5_callback(msg):
    global left_5
    left_5 = msg.data

def head_callback(msg):
    global head
    head = msg.data

if __name__ == '__main__':

    initialize_motor(DXL15_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL16_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL17_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL18_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL19_ID) #Enter Motor ID to enable torque and add parameter storage

    initialize_motor(DXL20_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL21_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL22_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL23_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL24_ID) #Enter Motor ID to enable torque and add parameter storage

    initialize_motor(DXL25_ID) #Enter Motor ID to enable torque and add parameter storage

    rospy.init_node('motor_drive', anonymous=True)
    rospy.Subscriber("right_1", Float64, right_1_callback)
    rospy.Subscriber("right_2", Float64, right_2_callback)
    rospy.Subscriber("right_3", Float64, right_3_callback)
    rospy.Subscriber("right_4", Float64, right_4_callback)
    rospy.Subscriber("right_5", Float64, right_5_callback)

    rospy.Subscriber("left_1", Float64, left_1_callback)
    rospy.Subscriber("left_2", Float64, left_2_callback)
    rospy.Subscriber("left_3", Float64, left_3_callback)
    rospy.Subscriber("left_4", Float64, left_4_callback)
    rospy.Subscriber("left_5", Float64, left_5_callback)

    rospy.Subscriber("head", Float64, head_callback)

    run_motor(DXL19_ID, right_1)
    run_motor(DXL20_ID, right_2 + 20)
    run_motor(DXL21_ID, right_3)
    run_motor(DXL22_ID, right_4)
    run_motor(DXL23_ID, right_5)

    run_motor(DXL15_ID, left_1 + 25)
    run_motor(DXL16_ID, left_2 + 100)
    run_motor(DXL17_ID, left_3)
    run_motor(DXL18_ID, left_4)
    run_motor(DXL24_ID, left_5)

    run_motor(DXL25_ID, head)

    rate = rospy.Rate(1000)

while not rospy.is_shutdown():
    run_motor(DXL19_ID, right_1)
    run_motor(DXL20_ID, right_2 + 20)
    run_motor(DXL21_ID, right_3)
    run_motor(DXL22_ID, right_4)
    run_motor(DXL23_ID, right_5)

    run_motor(DXL15_ID, left_1 + 25)
    run_motor(DXL16_ID, left_2 + 100)
    run_motor(DXL17_ID, left_3)
    run_motor(DXL18_ID, left_4)
    run_motor(DXL24_ID, left_5)

    run_motor(DXL25_ID, head)

    # print (right_1, right_2, right_3, right_4, right_5)
    rate.sleep()

    if (rospy.is_shutdown()):
        torque_diable(DXL15_ID)
        torque_diable(DXL16_ID)
        torque_diable(DXL17_ID)
        torque_diable(DXL18_ID)
        torque_diable(DXL19_ID)

        torque_diable(DXL20_ID)
        torque_diable(DXL21_ID)
        torque_diable(DXL22_ID)
        torque_diable(DXL23_ID)
        torque_diable(DXL24_ID)

        torque_diable(DXL25_ID)

        print("Shutting down. Motor torque disabled.")

        portHandler.closePort()   # Close port
        print("Port Closed")
