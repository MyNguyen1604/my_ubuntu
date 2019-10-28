#!/usr/bin/env python

## Every Python ROS Node will have this declaration at the top. The first line makes sure your script is executed as a Python script

## Simple talker demo that published std_msgs/Strings messages
## to the 'chatter' topic

import rospy #You need to import rospy if you are writing a ROS Node
from std_msgs.msg import String #Can reuse the std_msgs/String message type

def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10) #pub = rospy.Publisher("chatter", String, queue_size=10) declares that your node is publishing to the chatter topic using the message type String. 
    #String here is actually the class std_msgs.msg.String. 
    #The queue_size argument is New in ROS hydro and limits the amount of queued messages if any subscriber is not receiving them fast enough
    rospy.init_node('talker', anonymous=True) #Important
    #it tells rospy the name of your node -- until rospy has this information, it cannot start communicating with the ROS Master
    #In this case, your node will take on the name talker
    #the name must be a base name, i.e. it cannot contain any slashes "/"
    #anonymous = True ensures that your node has a unique name by adding random numbers to the end of NAME
    #Visit: http://wiki.ros.org/rospy/Overview/Initialization%20and%20Shutdown#Initializing_your_ROS_Node

    rate = rospy.Rate(10) # 10hz
    #With its argument of 10, we should expect to go through the loop 10 times per second
    msg = String() #Gan msg la mot msg String (Giong nhu quy dinh kieu du lieu trong C)
    msg.data = "Hello Quoc My Nguyen" #Ghi data cua msg String 

    while not rospy.is_shutdown():#Have to check the rospy.is_shutdown() flag
        #hello_str = "hello world %s" % rospy.get_time()
        

        #rospy.loginfo(hello_str) #A it's duty is printing message to sreen
        #which performs triple-duty: the messages get printed to screen, it gets written to the Node's log file, and it gets written to rosout. 
        #rosout is a handy for debugging: you can pull up messages using rqt_console instead of having to find the console window with your Node's output
        rospy.loginfo(msg.data)


        #pub.publish(hello_str) #publishes a string to our chatter topic (not printed to sreen, just publish to topic)
        pub.publish(msg.data)

        rate.sleep() #The loop calls rate.sleep(), which sleeps just long enough to maintain the desired rate through the loop. 

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:  #Ap sung cho truong hop dang o trong rate.sleep() (che do ngu) nhung ta nhan ctrl + C, thi chuong trinh se tat 
        # a rospy.ROSInterruptException exception, which can be thrown by rospy.sleep() and rospy.Rate.sleep() methods when Ctrl-C is pressed or your Node is otherwise shutdown.
        pass
