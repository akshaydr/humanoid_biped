#!/usr/bin/env python
import rospy
from sensor_msgs.msg import PointCloud2

def data_callback(msg):
    pub.publish(msg)

if __name__ == '__main__':
    rospy.init_node('gait_generation', anonymous=True)

    pub = rospy.Publisher('cloud_in', PointCloud2, queue_size=10)
    rospy.Subscriber("/voxel_cloud", PointCloud2, data_callback)

    rate = rospy.Rate(40)
while not rospy.is_shutdown():
    rate.sleep()
