#!/bin/bash

sleepTime=5

#roslaunch rdl robotic_lamp_nodes.launch
roslaunch rdl robotic_lamp_Node1.launch &
sleep $sleepTime
roslaunch rdl robotic_lamp_Node2.launch 
#sleep $sleepTime
roslaunch rdl robotic_lamp_Node3.launch 
#sleep $sleepTime
roslaunch rdl robotic_lamp_Node4.launch 
#sleep $sleepTime
roslaunch rdl robotic_lamp_Node5.launch 

