#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cmath>
#include <iostream>

using namespace std;
#define PI 3.14159265

float r = 1.0; //minimum radius of circle truck can follow
float v = 0.2; //m/s

float lr;//0.28
float lt;//0.525
float phi_max;
float d;//0.5
float k = 1.5;//1.05;//1.2;

void computeES(void){
    float rmin;//minimum turning radius of truck
    float rmin2;//minimum turning radius of trailer
    float xr; // equivalent size
    phi_max = phi_max * PI/180.0;
    
    if (lt >= lr){
       rmin2 = (lr + lt*cos(phi_max))/(sin(phi_max));
       rmin = sqrt( pow(rmin2,2.0) + 2*( pow(lt,2.0) - pow(lr,2.0) ));
       xr = rmin - rmin2 + d/2;
    }
    else{
       rmin = (lr + lt*cos(phi_max))/(sin(phi_max));
       rmin2 = sqrt( pow(rmin,2.0) + 2*( pow(lr,2.0) - pow(lt,2.0) ));
       xr = rmin2 - rmin + d/2;
    }
    r = k*rmin;
    cout << "Minimum turning of truck: "<<rmin<<endl;
    cout << "Turning radius of truck: "<<r<<endl;
    cout << "Equivalent size of truck-trailer: "<<xr<<endl;
}

void initialize(void){
    cout << "=======Test Equivalent Size======="<<endl;
    cout << "Description of system"<<endl;
    cout << "Distance from center of truck to joint, lr(m): " <<endl;
    cin >> lr;
    cout << "Distance from joint to center of trailer, lt(m): "<<endl;
    cin >> lt;
    cout << "Maximum width of truck and trailer, d: "<<endl;
    cin >> d;
    cout <<"The maximum angle of joint, phi_max(degree): "<<endl;
    cin >> phi_max;
    cout << "=======Initialize Complete======="<<endl;
    cout <<"================================="<<endl;
    
    computeES();
}


int main(int argc, char **argv)
{
    ros::init(argc, argv,"equivalent_size_test",ros::init_options::AnonymousName);
    ros::NodeHandle n;
    
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",1000);
    ros::Rate rate(10);
    
    initialize();
    
    geometry_msgs::Twist msg;
    
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;
    
    while(ros::ok())
    {      
         msg.linear.x = v;
         msg.angular.z = v/r;
         pub.publish(msg);
         ros::spinOnce();
         rate.sleep();
         
    }
    return 0;

}
