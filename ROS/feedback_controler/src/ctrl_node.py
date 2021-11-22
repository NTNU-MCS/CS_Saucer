#!/usr/bin/env python3
import rospy
from feedback_controler import loop
from lib import controlNodeInit, nodeEnd
import yaml
import os

cwd = os.getcwd()
with open(r"{0}/src/controller/src/params.yaml".format(cwd)) as file:
    params = yaml.load(file, Loader=yaml.FullLoader)


if __name__ == '__main__':

    node = controlNodeInit()
    r = rospy.Rate(params["runfrequency"])

    while not rospy.is_shutdown():
        loop()
        r.sleep()
    
    nodeEnd(node)