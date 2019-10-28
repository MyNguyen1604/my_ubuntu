#!/usr/bin/env python
import rospy
import time
from math import *
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

PI = 3.14

# dist = 0.0
speed = 0.0
dist0 = 0.0

# angle = 0.0
speedr = 0.0
angle0 = 0.0

#Variables store coordinate of goal
x = 0.0
y = 0.0
dist = 0.0
angle = 0.0
kt = 0
kt2 = 0
#Parameter of controller
kp_linear = 0.001;
kp_angular = 0.3355;

#Limit velocity and angular
v_limit = 0.2; #m/s
w_limit = 0.2; #rad/s

def linear(dist):
	global msg, pub
	# print dist
	if (dist > 10):
		v = kp_linear*dist
		print v
		if (v > v_limit):
			v = v_limit
		msg.linear.x = v
		pub.publish(msg)
	else:
		# print 1
		for i in xrange(2):
			msg.linear.x = 0
			msg.angular.z = 0
		return 1
	return 0

def rotation(delta_angle):
	global msg, pub, PI

	if (abs(delta_angle*180/PI) > 2):
		w = kp_angular*delta_angle
		if (w > w_limit):
			w = w_limit
		elif (w < -w_limit):
			w = -w_limit
		msg.angular.z = w
		pub.publish(msg)
	else:
		for i in xrange(2):
			msg.linear.x = 0
			msg.angular.z = 0
		return 1
	return 0



def goto(odom):
	global PI, msg, pub, dist, angle, kt, kt2
	# turnleft = False
	# turnright = False
	# print x, y

	#Current position of robot
	posx = odom.pose.pose.position.x*1000#Position in m
	posy = odom.pose.pose.position.y*1000
	# print "posx : %f" %(posx), "posy: %f" %(posy)
	#Quaternion
	qx = odom.pose.pose.orientation.x
	qy = odom.pose.pose.orientation.y
	qz = odom.pose.pose.orientation.z
	qw = odom.pose.pose.orientation.w

	
	#Convert Quaternion to Euler

	##yaw (z-axis rotation)
	t0 = 2.0*(qw*qz + qx*qy)
	t1 = 1.0 - 2.0*(qy*qy + qz*qz)
	angle_ini = atan2(t0,t1)
	print angle_ini*180/pi
	angle = atan2((y - posy),(x - posx))

	if ((angle_ini < 0.0) & (angle == atan2(0,-1))):
		angle = -atan2(0,-1)
	delta_angle = angle - angle_ini
	# print delta_angle

	dist = sqrt((x - posx)*(x - posx) + (y - posy)*(y - posy))
	# print dist
	# linear(dist)
	# rotation(delta_angle)
	if (kt2 == 0):
		if ((delta_angle != 0) & (kt == 0)):
			kt = rotation(delta_angle)
			# print kt
		else:
			kt2 = linear(dist)
			# print kt2
	else:
		print "Robot reach the target!"











def callback(odom):

	goto(odom)
	# rospy.loginfo("Robot finished moving!")
    # msg.linear.x = 0 #Ghi data cua msg String 
    # msg.linear.y = 0
	# msg.linear.z = 0
	# pub.publish(msg)


if __name__ == '__main__':
    try:
    	msg = Twist() #Gan msg la mot msg String (Giong nhu quy dinh kieu du lieu trong C)
        msg.linear.x = 0 #Ghi data cua msg String 
        msg.linear.y = 0
        msg.linear.z = 0
        msg.angular.x = 0
        msg.angular.y = 0
        msg.angular.z = 0

        print "Robot move to point!"
        #Type Goal
        # while ((x==0.0) & (y==0.0)):
        x = input("Coordinate of point x_point (mm): ")
        y = input("y_point (mm): ")

    	pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10) #pub = rospy.Publisher("chatter", String, queue_size=10) declares that your node is publishing to the chatter topic using the message type String. 
    	rospy.init_node('move_to_goal', anonymous=True)
    	sub = rospy.Subscriber('/RosAria/pose', Odometry, callback)
    	rospy.spin() # hz
    	# talker()


    except rospy.ROSInterruptException:  #Ap sung cho truong hop dang o trong rate.sleep() (che do ngu) nhung ta nhan ctrl + C, thi chuong trinh se tat 
        # a rospy.ROSInterruptException exception, which can be thrown by rospy.sleep() and rospy.Rate.sleep() methods when Ctrl-C is pressed or your Node is otherwise shutdown.
        pass
