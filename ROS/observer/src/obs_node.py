#!/usr/bin/env python3
import rospy
from obs_student import loop
from lib import observerNodeInit, nodeEnd
import os 
import yaml

cwd = os.getcwd()
with open(r"{0}/src/observer/src/params.yaml".format(cwd)) as file:
    params = yaml.load(file, Loader=yaml.FullLoader)



if __name__ == '__main__':

    observerNodeInit()
    r = rospy.Rate(params["runfrequency"]) # Usually set to 100 Hz

    while not rospy.is_shutdown():
        
        loop()
        r.sleep()
    
    nodeEnd()