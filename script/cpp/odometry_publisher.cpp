#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>
#include <math.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "odometry_publisher");

	ros::NodeHandle n;
	ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);

	tf::TransformBroadcaster odom_broadcaster;

	double x = 0.0;
	double y = 0.0;
	double th = 0.0;
//Here we'll set some velocities that will cause the "base_link" frame to move in the "odom" frame at a rate of 0.1m/s in the x direction, -0.1m/s in the y direction, and 0.1rad/s in the th direction.
	double vx = 0.1;
	double vy = 0.1;
	double vth = 0.1;

	ros::Time current_time, last_time;
	current_time = ros::Time::now(); //Khoi tao thoi gian ban dau
	last_time = ros::Time::now();

	ros::Rate r(1.0);

	while(n.ok()){
		ros::spinOnce(); //check for incoming messages
		// Cho cho toi khi nhan duoc messages
		current_time = ros::Time::now(); //cap nhat thoi gian khi nhan messages
		//Compute odometry in a typical way given the velocities of the robot

		double dt = (current_time - last_time).toSec();
		double d_x = (vx * cos(th) - vy * sin(th))*dt; //drives in a circle
		double d_y = (vx * sin(th) + vy * cos(th))*dt;
		double d_th = vth * dt;

		x += d_x;
		y += d_y;
		th += d_th;
		//since all odometry is 6DOF we'll need a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);//create a quaternion from th value

		//First, publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = current_time;
		odom_trans.header.frame_id = "odom";
		odom_trans.child_frame_id = "base_link";

        odom_trans.transform.translation.x = x;
        odom_trans.transform.translation.y = y;
        odom_trans.transform.translation.z = 0.0;
        odom_trans.transform.rotation = odom_quat;

        //send the transform
        odom_broadcaster.sendTransform(odom_trans);

        //Publish the odometry message over ROS
        nav_msgs::Odometry odom;
        odom.header.stamp = current_time;
        odom.header.frame_id = "odom";



		//set the position
		odom.pose.pose.position.x = x;
		odom.pose.pose.position.y = y;
		odom.pose.pose.position.z = 0.0;
		odom.pose.pose.orientation = odom_quat;

		//set the velocity
		odom.child_frame_id = "base_link";
		//We'll set the child_frame_id of the message to be the "base_link" frame since that's the coordinate frame we're sending our velocity information in. 
		odom.twist.twist.linear.x = vx;
		odom.twist.twist.linear.y = vy;
		odom.twist.twist.angular.z = vth;

		//publish message
		odom_pub.publish(odom);

		last_time = current_time;
		r.sleep();


	}


}