
# ----------------------------------------------------------------------------
# This code is part of the Mathias Solheim's master thesis
# Created By: M. Solheim
# Created Date: 2022-04-08
# Version = '1.0'
# Revised: <date>	<developer> <description>
#          <date>	<developer> <description>
# Tested:  2022-04-08 M.Solheim
#
# Copyright (C) 202x: <organization>, <place>
# Licensed under GPL-3.0-or-later
# ---------------------------------------------------------------------------

import rospy
import cv2
import time
import sys
import numpy as np

from yolo import *

INPUT_WIDTH = 640
INPUT_HEIGHT = 640
SCORE_THRESHOLD = 0.2
NMS_THRESHOLD = 0.4
CONFIDENCE_THRESHOLD = 0.4


if __name__ == '__main__':

    node = detectorNodeInit()
    r = rospy.Rate(10) # Usually set to 100 Hz, but considering the detecor will operate in the range of 5-15 fps 10 Hz should be sufficient

    class_list = load_classes()
    colors = [(255, 255, 0), (0, 255, 0), (0, 255, 255), (255, 0, 0)]
    is_cuda = len(sys.argv) > 1 and sys.argv[1] == "cuda"
    net = build_model(is_cuda)
    capture = load_capture()
    start = time.time_ns()
    frame_count = 0
    total_frames = 0
    fps = -1

    while not rospy.is_shutdown():
        _, frame = capture.read()
        if frame is None:
            print("End of stream")
            break

        inputImage = format_yolov5(frame)
        outs = detect(inputImage, net)

        class_ids, confidences, boxes = wrap_detection(inputImage, outs[0])

        frame_count += 1
        total_frames += 1

        for (classid, confidence, box) in zip(class_ids, confidences, boxes):
             color = colors[int(classid) % len(colors)]
             cv2.rectangle(frame, box, color, 2)
             cv2.rectangle(frame, (box[0], box[1] - 20), (box[0] + box[2], box[1]), color, -1)
             cv2.putText(frame, class_list[classid], (box[0], box[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, .5, (0,0,0))

        if frame_count >= 30:
            end = time.time_ns()
            fps = 1000000000 * frame_count / (end - start)
            frame_count = 0
            start = time.time_ns()

        if fps > 0:
            fps_label = "FPS: %.2f" % fps
            cv2.putText(frame, fps_label, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        cv2.imshow("output", frame)

        if cv2.waitKey(1) > -1:
            print("finished by user")
            break

        r.sleep()

    nodeEnd(node)
