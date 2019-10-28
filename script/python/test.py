#!/usr/bin/env python

import rospy
import signal
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

Dist = 0.0;
Speed = 0.0;

print "Robot will go forward!"
Dist = input("Desired distance: ")
Speed = input("Desired speed (maxvalue 0.7m/s): ")
while (Speed > 0.7):
	Speed = input("(Retype) Desired speed (maxvalue 0.7m/s):")
print "Robot is going to target!"
msg = Twist() #Gan msg la mot msg String (Giong nhu quy dinh kieu du lieu trong C) #Gan bien msg la message Twist
msg.linear.x = 0.0
msg.linear.y = 0.0
msg.linear.z = 0.0
msg.angular.x = 0.0
msg.angular.y = 0.0
msg.angular.z = 0.0
def linearcallback(data):
	Dist0 = 0.0;
	# tsamp = 0.2;
    if ((Dist - Dist0) < (0.3 * Dist)):
        msg.linear.x = (Dist - Dist0)/(0.3*Dist)*Speed
    else:

    	msg.linear.x = Speed

    pub.publish(msg)
    Dist0 = data.pose.pose.positon.x
    print "Current Position: %f" % Dist0




rospy.init_node('linearmotion', anonymous=True) 
pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10)
pos = rospy.Subscriber('/RosAria/pose', Odometry, linearcallback)

rospy.spin()
