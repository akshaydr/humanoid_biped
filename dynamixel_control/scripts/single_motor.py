#!/usr/bin/env python
import os
import rospy
from time import sleep
from std_msgs.msg import Float64
from motor_param import *

# Shifted repository to private

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

abr_er = 0
hr_er = 50
kr_er = -100
anr_er = 40
atr_er = 0

abl_er = 0
hl_er = 50
kl_er = -60
anl_er = -40
atl_er = -20

abduction_right =   2048 + abr_er
hip_right =         2141 + hr_er
knee_right =        2527 + kr_er
ankle_right =       1651 + anr_er
ankle_twist_right = 2048 + atr_er

abduction_left =    2048 + abl_er
hip_left =          2431 + hl_er    #+
knee_left =         2669 + kl_er   #-
ankle_left =        1798 + anl_er
ankle_twist_left =  2048 + atl_er
#
# abduction_right =   2048
# hip_right =         2048
# knee_right =        2048 - 100
# ankle_right =       2048 - 100
# ankle_twist_right = 2048
#
# abduction_left =    2048
# hip_left =          2048
# knee_left =         2048 - 60
# ankle_left =        2048 - 40
# ankle_twist_left =  2048 - 20

# Blanced stance (Standing straight)
# abduction_right =   2036
# hip_right =         2036 + 50
# knee_right =        2036 - 60
# ankle_right =       2036
# ankle_twist_right = 2036
#
# abduction_left =    2036
# hip_left =          2036 + 50
# knee_left =         2036 - 60
# ankle_left =        2036
# ankle_twist_left =  2036

# Balanced stance (Standing bent)
# abduction_right =   2048
# hip_right =         2048 + 180
# knee_right =        2048 + 310
# ankle_right =       2048 - 250
# ankle_twist_right = 2048
#
# abduction_left =    2048
# hip_left =          2048 + 180
# knee_left =         2048 + 310
# ankle_left =        2048 - 250
# ankle_twist_left =  2048

print("R_Hip", (hip_right * 360)/4096)
print("R_Knee", (knee_right * 360)/4096)
print("R_Ankle", (ankle_right * 360)/4096)
print("L_Hip",  (hip_left * 360)/4096)
print("L_Knee", (knee_left * 360)/4096)
print("L_Ankle", (ankle_left * 360)/4096)

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

def abduction_r_callback(msg):
    global abduction_right, abr_er
    abduction_right = msg.data + abr_er
def knee_r_callback(msg):
    global knee_right, kr_er
    knee_right = msg.data + kr_er
def hip_r_callback(msg):
    global hip_right, hr_er
    hip_right = msg.data + hr_er
def ankle_r_callback(msg):
    global ankle_right, anr_er
    ankle_right = msg.data + anr_er
def ankle_twist_r_callback(msg):
    global ankle_twist_right, atr_er
    ankle_twist_right = msg.data + atr_er

def abduction_l_callback(msg):
    global abduction_left, abl_er
    abduction_left = msg.data + abl_er
def hip_l_callback(msg):
    global hip_left, hl_er
    hip_left = msg.data + hl_er
def knee_l_callback(msg):
    global knee_left, kl_er
    knee_left = msg.data + kl_er
def ankle_l_callback(msg):
    global ankle_left, anl_er
    ankle_left = msg.data + anl_er
def ankle_twist_l_callback(msg):
    global ankle_twist_left, atl_er
    ankle_twist_left = msg.data + atl_er

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
    rospy.Subscriber("abduction_angle_r", Float64, abduction_r_callback)
    rospy.Subscriber("hip_angle_r", Float64, hip_r_callback)
    rospy.Subscriber("knee_angle_r", Float64, knee_r_callback)
    rospy.Subscriber("ankle_angle_r", Float64, ankle_r_callback)
    rospy.Subscriber("ankle_twist_angle_r", Float64, ankle_twist_r_callback)

    rospy.Subscriber("abduction_angle_l", Float64, abduction_l_callback)
    rospy.Subscriber("hip_angle_l", Float64, hip_l_callback)
    rospy.Subscriber("knee_angle_l", Float64, knee_l_callback)
    rospy.Subscriber("ankle_angle_l", Float64, ankle_l_callback)
    rospy.Subscriber("ankle_twist_angle_l", Float64, ankle_twist_l_callback)

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
    # print (abduction_right, ankle_twist_right, abduction_left, ankle_twist_left)

    run_motor(DXL2_ID, constrain(abduction_right, DXL2_ID))
    run_motor(DXL3_ID, constrain(hip_right, DXL3_ID))
    run_motor(DXL4_ID, constrain(knee_right, DXL4_ID))
    run_motor(DXL5_ID, constrain(ankle_right, DXL5_ID))
    run_motor(DXL6_ID, constrain(ankle_twist_right, DXL6_ID))

    run_motor(DXL8_ID, constrain(abduction_left, DXL8_ID))
    run_motor(DXL9_ID, constrain(hip_left, DXL9_ID))
    run_motor(DXL10_ID, constrain(knee_left, DXL10_ID))
    run_motor(DXL11_ID, constrain(ankle_left, DXL11_ID))
    run_motor(DXL12_ID, constrain(ankle_twist_left, DXL12_ID))

    rate.sleep()

    if (rospy.is_shutdown()):
        # torque_diable(DXL1_ID)
        # torque_diable(DXL2_ID)
        # torque_diable(DXL3_ID)
        # torque_diable(DXL4_ID)
        # torque_diable(DXL5_ID)
        # torque_diable(DXL6_ID)
        #
        # torque_diable(DXL7_ID)
        # torque_diable(DXL8_ID)
        # torque_diable(DXL9_ID)
        # torque_diable(DXL10_ID)
        # torque_diable(DXL11_ID)
        # torque_diable(DXL12_ID)
        print("Shutting down. Motor torque disabled.")

        portHandler.closePort()   # Close port
        print("Port Closed")
