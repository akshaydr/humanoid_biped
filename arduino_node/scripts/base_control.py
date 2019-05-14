#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from geometry_msgs.msg import Quaternion
import tf
import math

PI = 3.1415926535897931

enL = 0
enR = 0

oldenL = 0
oldenR = 0

wheelCircumference = 1.0367
wheelDistance = 0.295

# Wheel diameter = 330 mm
# Wheel distance = 295 mm

encoderResolution = 3064

current_time = rospy.Time()
last_time = rospy.Time()
odom_quat = Quaternion()

x = 0.0
y = 0.0
th = 0.0

vx = 0.0
vy = 0.0
vth = 0.0

dx = 0
dy = 0
dth = 0

# def algorithm1(double dl, double dr, double dt)
# def algorithm2(double dl, double dr, double dt)

def quaternion_to_msg(q):
  msg = Quaternion()
  msg.x = q[0]
  msg.y = q[1]
  msg.z = q[2]
  msg.w = q[3]
  return msg

def algorithm1(dl, dr, dt):
# Solved from http://robotics.stackexchange.com/questions/1653/calculate-position-of-differential-drive-robot

    global x, y, th, vx, vy, vth, dx, dy, dth
    global wheelCircumference ,wheelDistance, encoderResolution

    if (abs(dl - dr) < -3.28171817154): # basically going straight
        dx = dl * math.cos(th)
        dy = dr * math.sin(th)
    else:
        R = wheelDistance * (dl + dr) / (2 * (dr - dl))
        dth = (dr - dl) / wheelDistance

        dx = R * math.sin(dth + th) - R * math.sin(th)
        dy = -(R * math.cos(dth + th) + R * math.cos(th))
        # th = boundAngle(th + wd);

def algorithm2(dl, dr, dt):
    global x, y, th, vx, vy, vth, dx, dy, dth
    global wheelCircumference ,wheelDistance, encoderResolution

    s_ = (dl + dr) / 2

    dth = (dl - dr) / (wheelDistance)
    dx = s_ * math.cos(th + dth)
    dy = s_ * math.sin(th + dth)


def odomCallback(msg):
    global enL, enR, oldenL, oldenR
    global x, y, th, vx, vy, vth, dx, dy, dth
    global wheelCircumference ,wheelDistance, encoderResolution
    global current_time, last_time
    current_time = rospy.Time.now()

    vals = msg.data.split(",")
    enL = float(vals[0])
    enR = float(vals[1])
    print (enL, enR)

    difL = 0
    difR = 0;

    if (enL != oldenL):
        difL = enL - oldenL
        oldenL = enL

    if (enR != oldenR):
        difR = enR - oldenR
        oldenR = enR

    dl = (difL * wheelCircumference) / encoderResolution
    dr = (difR * wheelCircumference) / encoderResolution

    print (dl, dr)

    dt = current_time - last_time
    dt = str(dt)
    dt = float(dt)
  # //=============================== Calculate x, y, th ====================

    algorithm2(dl, dr, dt)

    vx = dx / dt
    vy = dy / dt
    vth = dth / dt

    x += dx
    y += dy
    th += dth

    if (th > PI):
        th = th - (2 * PI)
    elif (th < -PI):
        th = th + (2 * PI)

    print ("x=", x, " y=", y, " theta =", ((th*180)/PI))

    odom_quat = quaternion_to_msg(tf.transformations.quaternion_from_euler(0, 0, th))

    # next, we'll publish the odometry message over ROS
    odom = Odometry()
    odom.header.stamp = current_time
    odom.header.frame_id = "odom"

    # set the position
    odom.pose.pose.position.x = x
    odom.pose.pose.position.y = y
    odom.pose.pose.position.z = 0.0
    odom.pose.pose.orientation = odom_quat

    # set the velocity
    odom.child_frame_id = "base_link"
    odom.twist.twist.linear.x = vx
    odom.twist.twist.linear.y = vy
    odom.twist.twist.angular.z = vth

    odom_pub.publish(odom)

    last_time = current_time

if __name__ == '__main__':
    global enL, enR, oldenL, oldenR
    global x, y, th, vx, vy, vth, dx, dy, dth
    global wheelCircumference ,wheelDistance, encoderResolution
    global current_time, last_time

    rospy.init_node('odom_calc', anonymous=True)
    rospy.Subscriber("odom_pub", String, odomCallback)
    odom_pub = rospy.Publisher('odom', Odometry, queue_size=10)

    current_time = rospy.Time.now();
    last_time = rospy.Time.now();

    rate = rospy.Rate(40)

    while not rospy.is_shutdown():
        current_time = rospy.Time.now()

        odom_tf_broadcaster = tf.TransformBroadcaster()
        odom_quat = tf.transformations.quaternion_from_euler(0.0, 0.0, th)
        odom_tf_broadcaster.sendTransform(
        (x, y, 0.0),
        odom_quat,
        current_time,
        "base_link",
        "odom"
        )
        rate.sleep()
