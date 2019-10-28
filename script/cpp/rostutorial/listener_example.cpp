#include "ros/ros.h"
#include "std_msgs/String.h"

void chattercallback(const std_msgs::String::Ptr& msg)
{
     ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
     ros::init(argc, argv, "listener",ros::init_options::AnonymousName);
     ros::NodeHandle n;
     ros::Subscriber sub=n.subscribe("chatter",1000,chattercallback);
     ros::spin();
     return 0;

}
