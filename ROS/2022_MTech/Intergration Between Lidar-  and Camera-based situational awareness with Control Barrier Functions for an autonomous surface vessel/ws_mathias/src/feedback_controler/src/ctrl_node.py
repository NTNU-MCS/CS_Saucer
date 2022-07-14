#!/usr/bin/env python3
import rospy
from feedback_controler import loop
from lib import controlNodeInit, nodeEnd
import yaml
import os

cwd = os.getcwd()

if __name__ == '__main__':

    node = controlNodeInit()
    r = rospy.Rate(100)

    while not rospy.is_shutdown():
        loop()
        r.sleep()
    
    nodeEnd(node)