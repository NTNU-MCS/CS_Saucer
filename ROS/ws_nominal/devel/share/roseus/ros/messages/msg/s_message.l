;; Auto-generated. Do not edit!


(when (boundp 'messages::s_message)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 's_message (find-package "MESSAGES")))
(unless (find-package "MESSAGES::S_MESSAGE")
  (make-package "MESSAGES::S_MESSAGE"))

(in-package "ROS")
;;//! \htmlinclude s_message.msg.html


(defclass messages::s_message
  :super ros::object
  :slots (_s _s_dot ))

(defmethod messages::s_message
  (:init
   (&key
    ((:s __s) 0.0)
    ((:s_dot __s_dot) 0.0)
    )
   (send-super :init)
   (setq _s (float __s))
   (setq _s_dot (float __s_dot))
   self)
  (:s
   (&optional __s)
   (if __s (setq _s __s)) _s)
  (:s_dot
   (&optional __s_dot)
   (if __s_dot (setq _s_dot __s_dot)) _s_dot)
  (:serialization-length
   ()
   (+
    ;; float64 _s
    8
    ;; float64 _s_dot
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _s
       (sys::poke _s (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _s_dot
       (sys::poke _s_dot (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _s
     (setq _s (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _s_dot
     (setq _s_dot (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get messages::s_message :md5sum-) "44991c89fe9397efcd14043a99f9f1c5")
(setf (get messages::s_message :datatype-) "messages/s_message")
(setf (get messages::s_message :definition-)
      "float64 s
float64 s_dot

")



(provide :messages/s_message "44991c89fe9397efcd14043a99f9f1c5")


