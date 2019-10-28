#!/usr/bin/env python
import rospy
import time
from math import *
from geometry_msgs.msg import Twist

PI = 3.14

# dist = 0.0
speed = 0.0
dist0 = 0.0
dt = 0.1

# angle = 0.0
speedr = 0.0
angle0 = 0.0

def linearmotion(speed, dist):
	global dist0, dt, msg

	print "Robot will go forward!"
	# dist = input("Desired distance: ")
	# speed = input("Desired speed (maxvalue 0.7m/s): ")
	while (speed >= 0.7):
		speed = input("(Retype) Desired speed (maxvalue 0.7m/s):")
	print "Robot is going to target!"

	while ((not rospy.is_shutdown()) & ((dist - dist0) > 0.001)):
		if (((dist - dist0) < 0.3*dist) & ((dist - dist0) >= 0)):
			msg.linear.x = (dist - dist0)/(0.4*dist)*speed + 0.08
		elif (((dist - dist0) > 0.3*dist) & ((dist - dist0) >= 0)):
			msg.linear.x = speed
		else:
			msg.linear.x = 0
		pub.publish(msg)
		print "Current positiom: %f" %dist0, " Speed: %f" %msg.linear.x 
		rate.sleep()
		dist0 = dist0 + msg.linear.x*dt
	for i in xrange(2):
		msg.linear.x = 0 
		msg.linear.y = 0
		msg.linear.z = 0
		pub.publish(msg)
	rate.sleep()
	return 1

def rotation(speedr, angle):
	global angle0, dt, msg, PI

	print "Robot will turn!"
	# angle = input("Desired angle (>0): ")
	while (angle < 0):
		angle = input("(Retype) Desired angle (>0): ")

	# speedr = input("Desired angular (maxvalue 0.5 rad/s): ")
	while (abs(speedr) > 0.5):
		speedr = input("(Retype) Desired angular (<0.5 rad/s): ")

	print "Robot is going to turn"
	# angle = angle*PI/180
	
	while ((not rospy.is_shutdown()) & ((angle + 0.065 > angle0 ))):
		if (speedr > 0): #TURN LEFT
			if ((angle - angle0) < 0.3*angle):
				msg.angular.z = (angle - angle0)/(0.4*angle)*speedr + 0.08
			else:
				msg.angular.z = speedr
		else:
			if ((angle - angle0) < 0.3*angle):
				msg.angular.z = (angle - angle0)/(0.4*angle)*speedr - 0.08
			else:
				msg.angular.z = speedr
		pub.publish(msg)
		print "Current angle: %f" %(angle0*180/PI), "Agular: %f" %(msg.angular.z)
		rate.sleep()
		angle0 = angle0 + abs(msg.angular.z)*dt
	for  i in xrange(2):
		msg.angular.x = 0
		msg.angular.y = 0
		msg.angular.z = 0
		pub.publish(msg)
	rate.sleep()
	return 1

def goto(x, y):
	global PI
	turnleft = False
	turnright = False

	dist = 0.0
	angle = 0.0
	kt = 0
	# print x, y
	#Current position of robot
	posx = 0.0
	posy = 0.0 #LUU Y, PHAI CUNG KIEU DU LIEU TRONG CAC PHEP TINH


	#Deterimg angle between robot initial direction and goal


	if (((x - posx) >0) & ((y - posy) >=0)):
		angle = atan2((y - posy) , (x - posx))
		turnleft = True

	elif (((x - posx) <0) & ((y - posy) > 0)):
		angle = atan2((y - posy) ,(x - posx)) + PI
		turnleft = True

	elif (((x - posx) < 0) & ((y - posy) <=0)):
		angle = atan2((y - posy) , (x - posx)) + PI
		turnright = True

	elif (((x - posx) == 0) & ((y - posy) > 0)):
		angle = PI/2
		turnleft = True

	elif (((x - posx) == 0) & ((y - posy) < 0)):
		angle = 3*PI/2
		turnright = True

	else:
		angle = atan2((y - posy),(x - posx)) + 2*PI
		turnright = True




	dist = sqrt((x - posx)*(x - posx) + (y - posy)*(y - posy))
	if (angle != 0):
		if (turnright == True):
			kt = rotation(-0.4, (2*PI - angle))
			print "Robot turn right!"
		else:
			kt = rotation(0.4, angle)
			print "Robot turn left!"
	else:
		kt = 1
	if (kt == 1):
		linearmotion(0.5, dist)
	turnright = False
	turnleft = False


	#Goal nam o goc phan tu thu nhat







def talker():
	x = 0.0
	y = 0.0
	print "Robot move to point!"
	while ((x==0.0) & (y==0.0)):
		x = input("Coordinate of point x_point: ")
		y = input("y_point: ")
	goto(x, y)
	rospy.loginfo("Robot finished moving!")
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
    	pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10) #pub = rospy.Publisher("chatter", String, queue_size=10) declares that your node is publishing to the chatter topic using the message type String. 
    	rospy.init_node('test_public', anonymous=True) 

    	rate = rospy.Rate(10) # hz
    	talker()


    except rospy.ROSInterruptException:  #Ap sung cho truong hop dang o trong rate.sleep() (che do ngu) nhung ta nhan ctrl + C, thi chuong trinh se tat 
        # a rospy.ROSInterruptException exception, which can be thrown by rospy.sleep() and rospy.Rate.sleep() methods when Ctrl-C is pressed or your Node is otherwise shutdown.
        pass
