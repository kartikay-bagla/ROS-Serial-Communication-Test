#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"

int Arr[4];
void arrayCallback(const std_msgs::Int32MultiArray::ConstPtr& array){
    int i = 0;
    for(std::vector<int>::const_iterator it = array->data.begin(); it !=array->data.end(); ++it){
        Arr[i] = *it;
        i++;
    }

    for(int j = 0; j < 4; j++)
    {
        printf("%d, ", Arr[j]);
    }
    printf("\n");
}

int main(int argc, char **argv){
    ros::init(argc, argv, "arraySubscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("array", 100, arrayCallback);
    ros::spin();
    return 0;
}