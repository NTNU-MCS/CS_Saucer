#!/usr/bin/env python3
# ----------------------------------------------------------------------------
# This code is part of the Mathias Solheim's master thesis, and contains an
# an implementation of a obstacle class to be used in conjunction with the
# SA-system and CBF's. Import the obstacle class to the relevant scripts, and
#
#
# Created By: M. Solheim
# Created Date: 2022-04-10
# Version = '1.0'
# Revised: <date>	<developer> <description>
#          <date>	<developer> <description>
# Tested:  2022-04-08 self.M.Solheim
#
# Copyright (C) 202x: <organization>, <place>
# Licensed under GPL-3.0-or-later
# ---------------------------------------------------------------------------

class Obstacle(object):
    def __init__(self, p0, nu = None, delta = None, id):
        self.id = id                                 # Assigns the obstacle an integer id
        self.p0 = p0                                 # Position of the obstacle
        self.nu = np.zeros(3) if nu is None else nu  # Velocity of the obstavle
        self.delta = delta                           # Distance between obstacle and Own ship
        printf("Obstacle detected at (%.3f, %.3f)", self.p0)

    def __del__(self):
        printf("Obstacle %2d destroyed", self.id)

    def updatePose(self, p):
        """
        Updates the obstacle pose based on the SA measurements
        """
        self.p0 = p

    def updateVel(self, nu):
        """
        Updates the obstacle velocity based on SA tracking and stuff
        """
        self.nu = nu

    def updateRange(self, delta):
        """
        Updates the range to the obstacle based on the Lidar measurements and clustering algorithms
        """
        self.delta = delta
