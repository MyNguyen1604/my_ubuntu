//#ifdef TRUCK_TRAILER_RECOVERY_CPP
#define TRUCK_TRAILER_RECOVERY_CPP

//#include <ros/ros.h>
//#include <nav_core/recovery_behavior.h>
//#include <costmap_2d/costmap_2d_ros.h>
#include <iostream>

namespace stop_and_wait
{
    class StopAndWait{
       public:
       StopAndWait();
       ~StopAndWait();
       
       void initialize();
       void runBehavior();
         
    };
  
};
//#endif
