#!/usr/bin/env python

import rospy
import signal
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
# from tf2_msgs.msg import TFMessage
# from sensor_msgs.msg import Joy

def lasercallback(data):
    rospy.loginfo(data)

rospy.init_node('laser_node', anonymous=True) 
    # rospy.Subscriber('/tf', TFMessage, sonarcallback) #rostopic list | rostopic type /turtle1/cmd_vel
rospy.Subscriber('/base_scan', LaserScan, lasercallback)
    # pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10)
    #rospy.loginfo(data)
# Topic turtle1/pose se co tin nhan la turtlesim/Pose

rospy.spin()

