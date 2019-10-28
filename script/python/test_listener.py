#!/usr/bin/env python

import rospy
import yaml
from nav_msgs.msg import Odometry
i = 1
def callback(data):
    global i
    amcl = {'initial_pose_x' : data.pose.pose.position.x,
	'initial_pose_y' : data.pose.pose.position.y,
	'initial_pose_a' : data.pose.pose.orientation.z}
	# if (i == 1):
		# print 1
	# 	with open('/home/nguyenquocmy/catkin_ws/src/my_ubuntu/script/python/data.yml', 'w') as outfile:
	# 		yaml.dump(data, outfile, default_flow_style=False)
 #    i = i+1
	print amcl
def listener():
	rospy.init_node('listener_node', anonymous=True)
	rospy.Subscriber('/RosAria/pose', Odometry, callback)
	rospy.spin()
if __name__ == '__main__':
    listener()
	
