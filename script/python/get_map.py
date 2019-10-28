#!/usr/bin/env python
import rospy
import numpy as np
import cv2 as cv
from nav_msgs.msg import OccupancyGrid
from matplotlib import pyplot as plt

def cvrt2darray(data):
	res = data.info.resolution # resolution of map
	w = data.info.width #width of map
	h = data.info.height #height of map
	x = data.info.origin.position.x
	y = data.info.origin.position.y
	frame_id = data.header.frame_id
	slam_map = data.data
	raw_map = np.zeros((w,h),np.int)
	draw_map = np.zeros((w,h),np.uint8)
    
	for i in xrange(len(slam_map)):
		raw_map[i%w, int(i/w)] = slam_map[i]
	for x in xrange(w):
		for y in xrange(h):
			if (raw_map[x, y] == -1):
				draw_map[x, y] = 255
			elif (raw_map[x, y] > 0):
				draw_map[x, y] = 0
			else:
				draw_map[x, y] = 255
	print frame_id
	print "w: " + str(w) + " ,h: " + str(h)
	# print draw_map.shape
	print "x_origin: " + str(x) + ", y_origin: " + str(y)
		# draw_map[i%w , int(i/w)] = slam_map[i]

	sub.unregister()
	M = cv.getRotationMatrix2D((w/2, h/2),90,1)
	show_image = cv.warpAffine(draw_map,M,(w,h))
	plt.imshow(show_image,'gray')
	plt.plot(x,y,'xb')
	plt.axis('equal')
	plt.show()







rospy.init_node('get_map', anonymous = True)
sub = rospy.Subscriber('/map',OccupancyGrid,cvrt2darray)
rospy.spin()