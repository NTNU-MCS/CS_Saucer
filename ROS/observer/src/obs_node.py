#!/usr/bin/env python3
import rospy
from obs_student import loop
from lib import observerNodeInit, nodeEnd
import os 
import yaml

cwd = os.getcwd()

if __name__ == '__main__':

    node = observerNodeInit()
    r = rospy.Rate(100) # Usually set to 100 Hz

    while not rospy.is_shutdown():
        
        loop()
        r.sleep()
    
    nodeEnd(node)