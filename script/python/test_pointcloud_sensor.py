#!/usr/bin/env python

import rospy
import signal
from geometry_msgs.msg import Twist
from sensor_msgs.msg import PointCloud ##Cac gia tri x, y, z pointcloud tra ve la xet trong he toa toa cam bien, x,y nam trong mat phang (x nam ngang, y huong len)
# from tf2_msgs.msg import TFMessage
# from sensor_msgs.msg import Joy

d0 = 20.0; #40
v0 = 0.2; #maximum velocity of pioneer 3at is 0.7m/s
w0 = 0.3;
s4_gan = 30.0; #70




#Robot p3at-sh MobileSim

def sonarcallback(data):
    #rospy.loginfo("Vi tri cua node %f \n %f",data.linear, data.angular)
    # print("linear")
    # print(data.linear)
    msg = Twist() #Gan msg la mot msg String (Giong nhu quy dinh kieu du lieu trong C) #Gan bien msg la message Twist
    msg.linear.x = 0 #Ghi data cua msg String 
    msg.linear.y = 0
    msg.linear.z = 0
    msg.angular.x = 0
    msg.angular.y = 0
    msg.angular.z = 0
    # rospy.loginfo(data.points[5].x)
    s4 = 81.48765*data.points[4].x - 18.52059; #Calib sensor, Max = 400, Min = 10 (cm)
    s7 = -81.48765*data.points[7].y - 18.52059;
    s8 = -81.48765*data.points[8].y - 18.52059;
    s = [s4, s7, s8]
    rospy.loginfo(s)
    if (s4 > s4_gan):
        if ((s7 > 0.9*d0) & (s7 < 1.1*d0)) & ((s8 > 0.9*d0) & (s8 < 1.1*d0)):
            msg.linear.x = v0
        elif ((s7 > 1.1*d0)) & ((s8 > 0.9*d0) & (s8 < 1.1*d0)) :
            msg.angular.z = -0.5*w0
            msg.linear.x = 0.5*v0
        elif ((s7 < 0.9*d0)) & ((s8 > 0.9*d0) & (s8 < 1.1*d0)): #S7 thay doi, S8 giu nguyen
            msg.angular.z = 0.5*w0
            msg.linear.x = 0.5*v0
        elif ((s7 > 0.9*d0) & (s7 < 1.1*d0)) & (s8 > 1.1*d0): #s8 thay doi, s7 giu nguyen
            msg.angular.z = 0.5*w0
            msg.linear.x = 0.5*v0
        elif ((s7 > 0.9*d0) & (s7 < 1.1*d0)) & (s8 < 0.9*d0): 
            msg.angular.z = -0.5*w0
            msg.linear.x = 0.5*v0
        elif (s7 < 0.9*d0) & ((s8 < 0.9*d0)|(s8 > 1.1*d0)): 
            msg.angular.z = 0.5*w0
            msg.linear.x = 0.5*v0
        elif (s7 > 1.1*d0) & ((s8 < 0.9*d0)|(s8 > 1.1*d0)): 
            msg.angular.z = -0.5*w0
            msg.linear.x = 0.5*v0
    else:
        msg.angular.z = 0.5*w0
        msg.linear.x = 0.5*v0

        # else:
        #     msg.angular.z = -0.5*w0
        # else:
        #     msg.linear.x = v0
    # else:
    #     msg.angular.z = w0

    # s7 = -98.96642*(data.points[7].y)-23.1195;
    # s8 = -98.96642*(data.points[8].y)-23.1195;
    # s4 = 98.96642*(data.points[4].x)-23.1195;
    # s0 = 98.96642*(data.points[0].y)-23.1195;
    print "Linear: %s" % msg.linear.x, "Angular: %s" % msg.angular.z
    # print "Angular: %s" % msg.angular.z
    pub.publish(msg)

rospy.init_node('listener_node', anonymous=True) 
# rospy.Subscriber('/tf', TFMessage, sonarcallback) #rostopic list | rostopic type /turtle1/cmd_vel
data = rospy.Subscriber('/RosAria/sonar', PointCloud, sonarcallback)
pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10)

rospy.spin()
