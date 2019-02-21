#!/usr/bin/env python

import socket
import os
import rospy
from time import sleep
from std_msgs.msg import Float64
from motor_param import *

UDP_IP_ADDRESS = "192.168.2.101"
UDP_PORT_NO = 8001

serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))

if __name__ == '__main__':

    rospy.init_node('udp_comm', anonymous=True)
    pub = rospy.Publisher('motor_angle', Float64, queue_size=10)
    rate = rospy.Rate(100)


while not rospy.is_shutdown():
    data, addr = serverSock.recvfrom(1024)
    data = data.translate(None, '\x00')

    val = float(data)
    print (data)
    # val = (val*180)/ 3.14
    # val = val + 270
    val = (val*4000)/360
    val = val + 2036

    serverSock.sendto(data, ("192.168.7.3", 8001))

    pub.publish(val)
    rate.sleep()
