;; Auto-generated. Do not edit!


(when (boundp 'messages::s)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 's (find-package "MESSAGES")))
(unless (find-package "MESSAGES::S")
  (make-package "MESSAGES::S"))

(in-package "ROS")
;;//! \htmlinclude s.msg.html


(defclass messages::s
  :super ros::object
  :slots (_s _s_dot ))

(defmethod messages::s
  (:init
   (&key
    ((:s __s) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:s_dot __s_dot) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _s __s)
   (setq _s_dot __s_dot)
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
    ;; float64[] _s
    (* 8    (length _s)) 4
    ;; float64[] _s_dot
    (* 8    (length _s_dot)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _s
     (write-long (length _s) s)
     (dotimes (i (length _s))
       (sys::poke (elt _s i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _s_dot
     (write-long (length _s_dot) s)
     (dotimes (i (length _s_dot))
       (sys::poke (elt _s_dot i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _s
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _s (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _s i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _s_dot
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _s_dot (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _s_dot i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get messages::s :md5sum-) "14fb056663501f0195cd852f090d3a8f")
(setf (get messages::s :datatype-) "messages/s")
(setf (get messages::s :definition-)
      "float64[] s
float64[] s_dot

")



(provide :messages/s "14fb056663501f0195cd852f090d3a8f")


