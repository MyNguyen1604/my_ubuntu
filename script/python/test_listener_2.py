#!/usr/bin/env python
import rospy
import yaml
from nav_msgs.msg import Odometry

i = 1
def callback(data):
	global i
	pse = dict(initial_pose_x = data.pose.pose.position.x,
		initial_pose_y = data.pose.pose.position.y,
		initial_pose_a = data.pose.pose.orientation.z)
	if i == 1:
		with open('data.yaml','w') as f:
			yaml.dump(pse,f,default_flow_style=False)
		print('Done!')
	i = i +1

rospy.init_node('listener_pose', anonymous=True)
rospy.Subscriber('/RosAria/pose', Odometry, callback)

rospy.spin()

