#!/usr/bin/env python
import rospy
import numpy as np
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

#Goal position
x_g = 0.0
y_g = 0.0
th_g = 0.0 #Goc giua vector goal va phuong ngang

kp_dis =  9.0 #9.0
kp_alpha = 15.0 #15.0
kp_beta = -3.0 #-3.0
v_limit = 0.2
w_limit = 0.2
class quadtoeuler:
	def __init__(self, qx, qy, qz, qw):
		self.qx = qx
		self.qy = qy
		self.qz = qz
		self.qw = qw
	def roll(self):
		t0 = 2.0*(self.qw*self.qx + self.qy*self.qz)
		t1 = 1.0 - 2.0*(self.qx**2 + self.qy**2)
		roll = np.arctan2(t0,t1)
		return roll
	def pitch(self):
		t2 = 2.0*(self.qw*self.qy + self.qz*self.qx)
		if (t2 > 1.0):
			t2 = 1.0
		elif (t2 < -1.0):
			t2 = -1.0
		pitch = np.arcsin(t2)
		return pitch
	def yaw(self):
		t3 = 2.0*(self.qw*self.qz + self.qx*self.qy)
		t4 = 1.0 - 2.0*(self.qy**2 + self.qz**2)
		yaw = np.arctan2(t3,t4)
		return yaw

def move_to_goal(odom):
	global msg, pub, sub
	x = odom.pose.pose.position.x*1000 #mm
	y = odom.pose.pose.position.y*1000 #mm
	quad = odom.pose.pose.orientation
	th = quadtoeuler(quad.x, quad.y, quad.z, quad.w).yaw()
	v = 0.0
	w = 0.0

	x_diff = x_g - x
	y_diff = y_g - y

	# dis = np.sqrt(x_diff**2 + y_diff**2)
	# alpha = np.arctan2(y_diff,x_diff) - th
	# beta = th_g - th - alpha
	dis = np.sqrt(x_diff**2 + y_diff**2)
	alpha = (np.arctan2(y_diff,x_diff) - th + np.pi)%(2*np.pi) - np.pi #alpha in [-pi, pi]
	beta = (th_g - th - alpha + np.pi)%(2*np.pi) - np.pi
	angle_tolerence = abs(alpha)*180/np.pi + abs(beta)*180/np.pi
	# print "x: " + str(x) + ", y: " + str(y)
	print "theta: " + str(th*180/np.pi)
	print "dis: " + str(dis) + ", alpha: " + str(alpha*180/np.pi) + ", beta: " + str(beta*180/np.pi)
	if (dis > 10.0):
		v = kp_dis*dis/1000
		w = kp_alpha*alpha + kp_beta*beta
		if alpha > np.pi/2 or alpha < -np.pi/2:
			v = -v
		if v > v_limit:
			v = v_limit
		elif v < -v_limit:
			v = -v_limit
		if (dis < 100):
			v = (dis - 15)/dis*v #tolerance for dis
		# elif v < -v_limit:
		# 	v = -v_limit

		if w > w_limit:
			w = w_limit
		elif w < -w_limit:
			w = -w_limit
		if (abs(beta*180/np.pi)<10):
			w = (beta*180/np.pi - 2)/(beta*180/np.pi)*w #tolerance for beta
		# if (angle_tolerence < 2):
		# 	w = 0
		# print "v (m/s): " + str(v) + ", w(rad/s): " + str(w)
	else:
		sub.unregister()
		for i in xrange(2):
			msg.linear.x = 0.0
			msg.angular.z = 0.0
	# if (angle_tolerence > 5):
	# 	w = kp_alpha*alpha + kp_beta*beta
	# 	if w > w_limit:
	# 		w = w_limit
	# 	elif w < -w_limit:
	# 		w = -w_limit
	print "v (m/s): " + str(v) + ", w(rad/s): " + str(w)
		# pub.unregister()

	msg.linear.x = v
	msg.angular.z = w
	pub.publish(msg)



	# print th


try:
	msg = Twist()
	[msg.linear.x, msg.linear.y, msg.linear.z] = [0.0, 0.0, 0.0]
	msg.angular.z = 0.0

	print "Robot move to goal!"
	x_g = input("x goal (mm): ")
	y_g = input("y goal (mm): ")
	th_g = input("theta goal (do): ")
	th_g = th_g * np.pi/180

	rospy.init_node("simple_move_to_goal", anonymous = True)
	pub = rospy.Publisher("/RosAria/cmd_vel", Twist, queue_size = 10)
	sub = rospy.Subscriber("/RosAria/pose", Odometry, move_to_goal)
	rospy.spin()
except rospy.ROSInterruptException:
	pass

