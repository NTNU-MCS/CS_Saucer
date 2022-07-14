;; Auto-generated. Do not edit!


(when (boundp 'messages::reference_message)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 'reference_message (find-package "MESSAGES")))
(unless (find-package "MESSAGES::REFERENCE_MESSAGE")
  (make-package "MESSAGES::REFERENCE_MESSAGE"))

(in-package "ROS")
;;//! \htmlinclude reference_message.msg.html


(defclass messages::reference_message
  :super ros::object
  :slots (_eta_d _eta_ds _eta_ds2 _w _v_s _v_ss ))

(defmethod messages::reference_message
  (:init
   (&key
    ((:eta_d __eta_d) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:eta_ds __eta_ds) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:eta_ds2 __eta_ds2) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:w __w) 0.0)
    ((:v_s __v_s) 0.0)
    ((:v_ss __v_ss) 0.0)
    )
   (send-super :init)
   (setq _eta_d __eta_d)
   (setq _eta_ds __eta_ds)
   (setq _eta_ds2 __eta_ds2)
   (setq _w (float __w))
   (setq _v_s (float __v_s))
   (setq _v_ss (float __v_ss))
   self)
  (:eta_d
   (&optional __eta_d)
   (if __eta_d (setq _eta_d __eta_d)) _eta_d)
  (:eta_ds
   (&optional __eta_ds)
   (if __eta_ds (setq _eta_ds __eta_ds)) _eta_ds)
  (:eta_ds2
   (&optional __eta_ds2)
   (if __eta_ds2 (setq _eta_ds2 __eta_ds2)) _eta_ds2)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:v_s
   (&optional __v_s)
   (if __v_s (setq _v_s __v_s)) _v_s)
  (:v_ss
   (&optional __v_ss)
   (if __v_ss (setq _v_ss __v_ss)) _v_ss)
  (:serialization-length
   ()
   (+
    ;; float64[] _eta_d
    (* 8    (length _eta_d)) 4
    ;; float64[] _eta_ds
    (* 8    (length _eta_ds)) 4
    ;; float64[] _eta_ds2
    (* 8    (length _eta_ds2)) 4
    ;; float64 _w
    8
    ;; float64 _v_s
    8
    ;; float64 _v_ss
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _eta_d
     (write-long (length _eta_d) s)
     (dotimes (i (length _eta_d))
       (sys::poke (elt _eta_d i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _eta_ds
     (write-long (length _eta_ds) s)
     (dotimes (i (length _eta_ds))
       (sys::poke (elt _eta_ds i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _eta_ds2
     (write-long (length _eta_ds2) s)
     (dotimes (i (length _eta_ds2))
       (sys::poke (elt _eta_ds2 i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64 _w
       (sys::poke _w (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _v_s
       (sys::poke _v_s (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _v_ss
       (sys::poke _v_ss (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _eta_d
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eta_d (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _eta_d i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _eta_ds
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eta_ds (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _eta_ds i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _eta_ds2
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eta_ds2 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _eta_ds2 i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64 _w
     (setq _w (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _v_s
     (setq _v_s (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _v_ss
     (setq _v_ss (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get messages::reference_message :md5sum-) "02538cc248bfc219710e188e6f1af3e2")
(setf (get messages::reference_message :datatype-) "messages/reference_message")
(setf (get messages::reference_message :definition-)
      "float64[] eta_d
float64[] eta_ds
float64[] eta_ds2
float64 w
float64 v_s
float64 v_ss
")



(provide :messages/reference_message "02538cc248bfc219710e188e6f1af3e2")


