#include <ros/ros.h>
#include <sensor_msgs/PointCloud.h>

int main(int argc, char** argv){
	ros::init (argc, argv, "point_cloud_publisher");
	ros::NodeHandle n;
	ros::Publisher cloud_pub = n.advertise<sensor_msgs::PointCloud>("cloud",50);//ta co the tu tao mot topics moi tu cau lenh nay, o day ta tao topic /cloud

	unsigned int num_points = 100;//moi mot cam bien sieu am se la mot point

	int count = 0;
	ros::Rate r(1.0);
	while(n.ok()){
		sensor_msgs::PointCloud cloud;
		cloud.header.stamp = ros::Time::now();
		cloud.header.frame_id = "sensor_frame";

		cloud.points.resize(num_points);
		cloud.channels.resize(1);
		cloud.channels[0].name = "intensities";
		cloud.channels[0].values.resize(num_points); //du lieu tu channels duoc su dung de lam gi
        //sizes it to match the number of points that we'll have in the cloud. 
		for(unsigned int i = 0; i < num_points; ++i){
			cloud.points[i].x = 1 + count;
			cloud.points[i].y = 2 + count;
			cloud.points[i].z = 3 + count;
			cloud.channels[0].values[i] = 100 + count;
		}
		cloud_pub.publish(cloud);
		++count;
		r.sleep();

	}
}