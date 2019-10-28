#!/usr/bin/env python

import rospy
import time
from geometry_msgs.msg import Twist

def talker():
    pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=10) #pub = rospy.Publisher("chatter", String, queue_size=10) declares that your node is publishing to the chatter topic using the message type String. 
    rospy.init_node('test_public', anonymous=True) 
    rate = rospy.Rate(2) # 10hz
    #With its argument of 10, we should expect to go through the loop 10 times per second
    msg = Twist() #Gan msg la mot msg String (Giong nhu quy dinh kieu du lieu trong C)
    msg.linear.x = 0 #Ghi data cua msg String 
    msg.linear.y = 0
    msg.linear.z = 0
    msg.angular.x = 0
    msg.angular.y = 0
    msg.angular.z = 0
    pub.publish(msg)
    BASE_SPEED, MOVE_TIME, CLOCK_SPEED = 0.2, 30.0, 0.5
    count = 0;
#While loop will finish in 1/rospy.Rate()
    rospy.loginfo("Waiting for 10 seconds to move forward!");
    rospy.sleep(10.);
    while ((not rospy.is_shutdown()) & (count < MOVE_TIME/CLOCK_SPEED + 1)):#Have to check the rospy.is_shutdown() flag
        #hello_str = "hello world %s" % rospy.get_time()
        # if (count == 0 | count == 1):
        	# msg.linear.x = BASE_SPEED
        	# pub.publish(msg)
    	msg.linear.x = BASE_SPEED
    	pub.publish(msg)
        rospy.loginfo("Base speed(m/s): %f", BASE_SPEED)       
        rospy.loginfo("Time move(s): %f", (count*CLOCK_SPEED)) 
    	count = count + 1

        #rospy.loginfo(hello_str) #A it's duty is printing message to sreen
        #which performs triple-duty: the messages get printed to screen, it gets written to the Node's log file, and it gets written to rosout. 
        #rosout is a handy for debugging: you can pull up messages using rqt_console instead of having to find the console window with your Node's output
        #rospy.loginfo(msg)
        #pub.publish(hello_str) #publishes a string to our chatter topic (not printed to sreen, just publish to topic)

        rate.sleep() #The loop calls rate.sleep(), which sleeps just long enough to maintain the desired rate through the loop.
    for i in xrange(2): 
    	msg.linear.x = 0 #Ghi data cua msg String 
    	msg.linear.y = 0
    	msg.linear.z = 0
    	pub.publish(msg)
    rospy.loginfo("Robot finished moving!")
    # msg.linear.x = 0 #Ghi data cua msg String 
    # msg.linear.y = 0
	# msg.linear.z = 0
	# pub.publish(msg)
    rate.sleep()



if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:  #Ap sung cho truong hop dang o trong rate.sleep() (che do ngu) nhung ta nhan ctrl + C, thi chuong trinh se tat 
        # a rospy.ROSInterruptException exception, which can be thrown by rospy.sleep() and rospy.Rate.sleep() methods when Ctrl-C is pressed or your Node is otherwise shutdown.
        pass
