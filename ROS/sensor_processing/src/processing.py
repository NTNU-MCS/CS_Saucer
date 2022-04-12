#!/usr/bin/env python3
# ----------------------------------------------------------------------------
# This code is part of the Mathias Solheim's master thesis. The script contains
# the situational awareness component for the CSS. It handles sensor processing,
# sensor fusion and obstacle identification.
#
# Created By: self.M. Solheim
# Created Date: 2022-04-10
# Version = '1.0'
# Revised: <date>	<developer> <description>
#          <date>	<developer> <description>
# Tested:  2022-04-08 self.M.Solheim
#
# Copyright (C) 202x: <organization>, <place>
# Licensed under GPL-3.0-or-later
# ---------------------------------------------------------------------------

import rospy
import numpy as np



if __name__ == '__main__':

    node = controlNodeInit()
    r = rospy.Rate(100)

    while not rospy.is_shutdown():
        loop()
        r.sleep()

    nodeEnd(node)
