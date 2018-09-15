#include <stdio.h>
#include <stdlib.h>

#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"

#include "std_msgs/Int32MultiArray.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "arrayPublisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Int32MultiArray>("array", 100);
    while(ros::ok()){
        std_msgs::Int32MultiArray array;
        array.data.clear();
        
        for(int i = 0; i < 4; i++){
            array.data.push_back(rand() % 255);
        }
        pub.publish(array);
        ROS_INFO("Published!");
        ros::spinOnce();
        sleep(2);        
    }
}
