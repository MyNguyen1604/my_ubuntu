#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <signal.h>
#include <termios.h>
#include "sensor_msgs/PointCloud.h"
#include "math.h"
#include "string.h"
#include "std_msgs/String.h"
using namespace std;



class Listener
{
public:
  Listener();
  void sonarCallback(const sensor_msgs::PointCloud::ConstPtr& pointCloud);
private:
  ros::NodeHandle n;
  ros::Subscriber sub;
};
Listener::Listener()
{
  sub = n.subscribe("/RosAria/sonar", 1000, &Listener::sonarCallback, this);
}

void Listener::sonarCallback(const sensor_msgs::PointCloud::ConstPtr& pointCloud)
{
//  cout << "So cam bien: " << pointCloud->points.size() << endl;

  cout << "sonar 7: " << abs(98.96642*(pointCloud->points[7].y))-23.1195
       << " sonar 8: " << abs(98.96642*(pointCloud->points[8].y))-23.1195
       << endl;

//cout << -pointCloud->points[8].y << endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "minh_test_1");
  Listener listener;
  ros::spin();
}
