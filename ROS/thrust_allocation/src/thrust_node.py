#!/usr/bin/env python3
import rospy
from thrust_allocation import loop
from lib import thrustAllocationNodeInit, nodeEnd
import os 
import yaml

cwd = os.getcwd()

if __name__ == '__main__':

    node = thrustAllocationNodeInit()
    r = rospy.Rate(100) # Usually set to 100 Hz

    while not rospy.is_shutdown():
        
        loop()
        r.sleep()
    
    nodeEnd(node)