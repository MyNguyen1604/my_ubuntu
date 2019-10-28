# from math import *
import numpy as np


PI = 3.14
dist = 0.0
angle = 0.0
z = 0.0
def goto(x, y):
	global PI, dist, angle, z

	kt = 0
	# print x, y
	#Current position of robot
	posx = 0.0
	posy = 0.0
	z = (y - posy)/(x - posx)
	print z
	#Deterimg angle between robot initial direction and goal
	if (((x - posx) >=0) & ((y - posy) >=0)):
		print (x - posx), (y - posy)
		angle = np.arctan((y-posy)/(x-posx))
		# angle = 1
		print np.arctan((y-posy) / (x-posx))
	# elif (((x - posx) <0) & ((y - posy) > 0)):
	# 	angle = atan((y - posy)/ (x - posx)) + PI
	# elif (((x - posx) < 0) & ((y - posy) <0)):
	# 	angle = atan((y - posy)/(x - posx)) + PI
	# else:
	# 	angle = atan((y - posy)/(x - posx)) + 2*PI

goto(10, 5)