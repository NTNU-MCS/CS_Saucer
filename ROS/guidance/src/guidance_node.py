#!/usr/bin/env python3
import rospy
from guidance_stud import loop
from lib import guidanceNodeInit, nodeEnd
import yaml
import os

cwd = os.getcwd()



if __name__ == '__main__':

    guidanceNodeInit()
    r = rospy.Rate(100)

    while not rospy.is_shutdown():
        loop()
        r.sleep()
    
    nodeEnd()