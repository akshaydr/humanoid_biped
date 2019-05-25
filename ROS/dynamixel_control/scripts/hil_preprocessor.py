#!/usr/bin/env python
import socket
import os
import rospy
import numpy as np
from time import sleep
from std_msgs.msg import String

UDP_IP_ADDRESS = "192.168.2.101"
UDP_PORT_NO = 8001

UDP_IP = "192.168.7.3"
UDP_PORT = 1234

serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))


if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)
    pub1 = rospy.Publisher('speedgoat_data', String, queue_size=10)

    rate = rospy.Rate(1000)

while not rospy.is_shutdown():
    data, addr = serverSock.recvfrom(1024)
    data = data.translate(None, '\x00')
    # print data
    pub1.publish(data)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(data, (UDP_IP, UDP_PORT))
