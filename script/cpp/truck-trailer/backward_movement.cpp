#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float32.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265
float v=0.0, w=0.0;
float vr=0.15, wr=vr/1.0;
float lr;//0.28
float lt;//0.525
float phi_max;
float d;//0.5
float r = 1.0;
float phi;
float k = 10.0; //1.5; //1.2
int ch = 0;
using namespace std;


class Backward {
   public:
      Backward();
      void callback(const std_msgs::Float32::Ptr& msg);
      ros::NodeHandle n;
      ros::Publisher pub;
      ros::Subscriber sub;
      geometry_msgs::Twist cmd_vel;
      
      
};
Backward::Backward(){
   pub = n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",10);
   sub= n.subscribe("/angular_deviation",10,&Backward::callback,this);
   cmd_vel.linear.x = 0.0;
   cmd_vel.linear.y = 0.0;
   cmd_vel.linear.z = 0.0;
    
   cmd_vel.angular.x = 0.0;
   cmd_vel.angular.y = 0.0;
   cmd_vel.angular.z = 0.0;
   ROS_INFO("Done Initialize...");
}
void Backward::callback(const std_msgs::Float32::Ptr& msg)
{
     ROS_INFO("I heard: [%f]", msg->data);
     
     if (ch == 1){
         phi = PI*msg->data/180;
     }
     else {
         phi = k*PI*msg->data/180;
     }
     
     v = -(vr*cos(-phi) + wr*lt*sin(-phi));
     w = (-vr*sin(-phi)/lr - lt*wr*cos(-phi)/lr); 
     ROS_INFO("Velocity: [%f], Angular: [%f]", v, w);
     
     cmd_vel.linear.x = v;
     cmd_vel.angular.z = w;
     pub.publish(cmd_vel);
}









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
    r = rmin;
    cout << "Minimum turning of truck: "<<rmin<<endl;
    cout << "Turning radius of truck: "<<r<<endl;
    cout << "Equivalent size of truck-trailer: "<<xr<<endl;
    cout << "===================================" << endl;
    cout << "Kind of backward movement" << endl;
    do {
    cout << "0. Straight line backward" << endl;
    cout << "1. Circle backward" << endl;
    cout << "Choose: "<<endl;
    cin >> ch;
    }while (ch != 0 && ch != 1);
    
    if (ch == 0){
        vr = 0.1;
        wr = 0.0;
    }
    else {
        vr = 0.1;
        wr = vr/1.0;
    }
    
    
}

void initialize(void){
    cout << "=======Test Backward Movement======="<<endl;
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
    initialize();
    ros::init(argc, argv,"backward_movement",ros::init_options::AnonymousName);
    //ros::NodeHandle n;
    //ros::Duration(15).sleep();
    Backward backward;
        
    ros::spin();
    return 0;

}
