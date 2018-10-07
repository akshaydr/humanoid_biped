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
DXL1_ID                     = 1              # Dynamixel#1 ID : 1
DXL2_ID                     = 2                # Dynamixel#1 ID : 1
DXL3_ID                     = 3                 # Dynamixel#1 ID : 1
DXL4_ID                     = 4                  # Dynamixel#1 ID : 1
DXL5_ID                     = 5                  # Dynamixel#1 ID : 1
DXL6_ID                     = 6                  # Dynamixel#1 ID : 1

DXL7_ID                     = 7              # Dynamixel#1 ID : 1
DXL8_ID                     = 8                # Dynamixel#1 ID : 1
DXL9_ID                     = 9                 # Dynamixel#1 ID : 1
DXL10_ID                    = 10                  # Dynamixel#1 ID : 1
DXL11_ID                    = 11                 # Dynamixel#1 ID : 1
DXL12_ID                    = 12                 # Dynamixel#1 ID : 1

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

# hip_angle_val =   2036
# knee_angle_val =  2036
# ankle_angle_val = 2036
#
# hip_angle_left =   2036
# knee_angle_left =  2036
# ankle_angle_left = 2036

# hip_val =   [2141, 2187, 2228, 2263, 2295, 2324, 2350, 2373, 2394, 2412, 2427, 2440, 2450, 2458, 2462, 2463, 2461, 2455, 2445, 2431, 2431, 2420, 2408, 2396, 2384, 2371, 2358, 2344, 2330, 2315, 2300, 2285, 2269, 2252, 2235, 2217, 2199, 2181, 2161, 2141]
# knee_val =  [2527, 2588, 2639, 2682, 2717, 2747, 2772, 2791, 2806, 2817, 2823, 2825, 2822, 2815, 2804, 2788, 2767, 2740, 2708, 2669, 2669, 2669, 2667, 2666, 2663, 2660, 2656, 2651, 2645, 2639, 2632, 2624, 2615, 2605, 2595, 2583, 2571, 2557, 2543, 2527]
# ankle_val = [1651, 1635, 1625, 1618, 1614, 1613, 1614, 1618, 1623, 1631, 1640, 1651, 1664, 1678, 1694, 1711, 1730, 1751, 1773, 1798, 1798, 1787, 1777, 1767, 1757, 1747, 1738, 1729, 1721, 1712, 1704, 1697, 1689, 1682, 1676, 1670, 1664, 1659, 1655, 1651]

hip_angle_right =   2141
knee_angle_right =  2527
ankle_angle_right = 1651


hip_angle_left =    2431
knee_angle_left =   2669
ankle_angle_left =  1798

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


def knee_angle_r_callback(msg):
    global knee_angle_right
    knee_angle_right = msg.data

def hip_angle_r_callback(msg):
    global hip_angle_right
    hip_angle_right = msg.data

def ankle_angle_r_callback(msg):
    global ankle_angle_right
    ankle_angle_right = msg.data

def knee_angle_l_callback(msg):
    global knee_angle_left
    knee_angle_left = msg.data

def hip_angle_l_callback(msg):
    global hip_angle_left
    hip_angle_left = msg.data

def ankle_angle_l_callback(msg):
    global ankle_angle_left
    ankle_angle_left = msg.data

if __name__ == '__main__':
    initialize_motor(DXL1_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL2_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL3_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL4_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL5_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL6_ID) #Enter Motor ID to enable torque and add parameter storage

    initialize_motor(DXL7_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL8_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL9_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL10_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL11_ID) #Enter Motor ID to enable torque and add parameter storage
    initialize_motor(DXL12_ID) #Enter Motor ID to enable torque and add parameter storage

    rospy.init_node('motor_drive', anonymous=True)
    rospy.Subscriber("hip_angle_r", Float64, hip_angle_r_callback)
    rospy.Subscriber("knee_angle_r", Float64, knee_angle_r_callback)
    rospy.Subscriber("ankle_angle_r", Float64, ankle_angle_r_callback)

    rospy.Subscriber("hip_angle_l", Float64, hip_angle_l_callback)
    rospy.Subscriber("knee_angle_l", Float64, knee_angle_l_callback)
    rospy.Subscriber("ankle_angle_l", Float64, ankle_angle_l_callback)

    run_motor(DXL1_ID, constrain(2036, DXL1_ID))
    run_motor(DXL2_ID, constrain(2036, DXL2_ID))
    run_motor(DXL3_ID, constrain(2036, DXL3_ID))
    run_motor(DXL4_ID, constrain(2036, DXL4_ID))
    run_motor(DXL5_ID, constrain(2036, DXL5_ID))
    run_motor(DXL6_ID, constrain(2036, DXL6_ID))

    run_motor(DXL7_ID, constrain(2036, DXL1_ID))
    run_motor(DXL8_ID, constrain(2036, DXL2_ID))
    run_motor(DXL9_ID, constrain(2036, DXL3_ID))
    run_motor(DXL10_ID, constrain(2036, DXL4_ID))
    run_motor(DXL11_ID, constrain(2036, DXL5_ID))
    run_motor(DXL12_ID, constrain(2036, DXL6_ID))

    rate = rospy.Rate(100)

while not rospy.is_shutdown():
    # print ("Hip_angle =", hip_angle_val, "Knee_angle =", knee_angle_val, "Ankle_angle =", ankle_angle_val)

    run_motor(DXL3_ID, constrain(hip_angle_right, DXL3_ID))
    run_motor(DXL4_ID, constrain(knee_angle_right, DXL4_ID))
    run_motor(DXL5_ID, constrain(ankle_angle_right, DXL5_ID))

    run_motor(DXL9_ID, constrain(hip_angle_left, DXL9_ID))
    run_motor(DXL10_ID, constrain(knee_angle_left, DXL10_ID))
    run_motor(DXL11_ID, constrain(ankle_angle_left, DXL11_ID))

    rate.sleep()

    if (rospy.is_shutdown()):
        torque_diable(DXL1_ID)
        torque_diable(DXL2_ID)
        torque_diable(DXL3_ID)
        torque_diable(DXL4_ID)
        torque_diable(DXL5_ID)
        torque_diable(DXL6_ID)

        torque_diable(DXL7_ID)
        torque_diable(DXL8_ID)
        torque_diable(DXL9_ID)
        torque_diable(DXL10_ID)
        torque_diable(DXL11_ID)
        torque_diable(DXL12_ID)
        print("Shutting down. Motor torque disabled.")

        portHandler.closePort()   # Close port
        print("Port Closed")
