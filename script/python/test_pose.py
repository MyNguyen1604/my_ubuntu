#!/usr/bin/env python

import rospy
import signal
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Pose
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool


def posecallback(data):

	print data

rospy.init_node('test', anonymous = True)

rospy.Subscriber('/RosAria/motors_state', Bool, posecallback)

rospy.spin()
# kt = 0

# rospy.init_node('test', anonymous = True)
# pub = rospy.Publisher('/RosAria/motors_state', Bool, queue_size=10)
# rate = rospy.Rate(10)
# msg = Bool()
# while ((not rospy.is_shutdown()) & ((kt != 3 ))):
# 	kt = input("Motor State (0: Turn off; 1: Turn on; 3: Exit): ")
# 	if (kt == 0): #TURN OFF
# 		msg.data = False
# 	else:
# 		msg.data = True
# 	pub.publish(msg)
# 	print msg
# 	rate.sleep()
