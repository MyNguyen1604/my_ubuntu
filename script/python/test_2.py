import rospy
import signal
import time
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

dist = 0.0
speed = 0.0
d_old = 0.0
dist0 = 0.0
def linearcallback(data):
	# e1 = time.time()
	global dist0
	global d_old
	global d_new
	# e2 = time.time()
	# print e2 - e1
	# d_new = data.pose.pose.position.x
	if (((dist - dist0) < 0.3*dist) & ((dist - dist0) >= 0)):
		msg.linear.x = (dist - dist0)/dist*speed
	elif (((dist - dist0) > 0.3*dist) & ((dist - dist0) >= 0)):
		msg.linear.x = speed
# 	dist0 = d_new - d_old
	dist0 = data.pose.pose.position.x
# 	d_old = d_new
	print dist0 
# 	print "Current position: %f" %dist0, "Speed: %f" %msg.linear.x

	pub.publish(msg)

	#print data.pose.pose.position.x
msg = Twist()
msg.linear.x = 0
msg.linear.y = 0
msg.linear.z = 0
msg.angular.x = 0
msg.angular.y = 0
msg.angular.z = 0

# d = Odometry()
# d.pose.pose.position.x = 0
# d.pose.pose.position.y = 0
# d.pose.pose.position.z = 0

print "Robot will go forward!"
dist = input("Desired distance: ")
speed = input("Desired speed (maxvalue 0.7m/s): ")
while (speed > 0.7):
	speed = input("(Retype) Desired speed (maxvalue 0.7m/s):")
print "Robot is going to target!"

rospy.init_node('linearmotion', anonymous=True) 
pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10)
pos = rospy.Subscriber('/RosAria/pose', Odometry, linearcallback)

# print d.pose.pose.position.x
rospy.spin()