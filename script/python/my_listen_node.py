#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
#from turtlesim.msg import Pose
def callback(data):
	#rospy.loginfo("Vi tri cua node %f \n %f",data.linear, data.angular)
	#print("linear")
	#print(data.linear)
	#print("\n")
	#print("angular")
	#print(data.angular)
	#print("\n")
	return data
def listener():
	rospy.init_node('listener_node', anonymous=True) 
	data = rospy.Subscriber('/RosAria/pose', Odometry, callback) #rostopic list | rostopic type /turtle1/cmd_vel
# Topic turtle1/pose se co tin nhan la turtlesim/Pose
	rospy.spin()
if __name__ == '__main__':
    listener()
	
