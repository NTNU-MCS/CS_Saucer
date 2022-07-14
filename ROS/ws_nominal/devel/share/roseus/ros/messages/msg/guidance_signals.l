;; Auto-generated. Do not edit!


(when (boundp 'messages::guidance_signals)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 'guidance_signals (find-package "MESSAGES")))
(unless (find-package "MESSAGES::GUIDANCE_SIGNALS")
  (make-package "MESSAGES::GUIDANCE_SIGNALS"))

(in-package "ROS")
;;//! \htmlinclude guidance_signals.msg.html


(defclass messages::guidance_signals
  :super ros::object
  :slots (_eta_d _pd_s1 _pd_s2 _pd_ss1 _pd_ss2 _psi_d_dot _psi_d_ddot ))

(defmethod messages::guidance_signals
  (:init
   (&key
    ((:eta_d __eta_d) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pd_s1 __pd_s1) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pd_s2 __pd_s2) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pd_ss1 __pd_ss1) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:pd_ss2 __pd_ss2) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:psi_d_dot __psi_d_dot) 0.0)
    ((:psi_d_ddot __psi_d_ddot) 0.0)
    )
   (send-super :init)
   (setq _eta_d __eta_d)
   (setq _pd_s1 __pd_s1)
   (setq _pd_s2 __pd_s2)
   (setq _pd_ss1 __pd_ss1)
   (setq _pd_ss2 __pd_ss2)
   (setq _psi_d_dot (float __psi_d_dot))
   (setq _psi_d_ddot (float __psi_d_ddot))
   self)
  (:eta_d
   (&optional __eta_d)
   (if __eta_d (setq _eta_d __eta_d)) _eta_d)
  (:pd_s1
   (&optional __pd_s1)
   (if __pd_s1 (setq _pd_s1 __pd_s1)) _pd_s1)
  (:pd_s2
   (&optional __pd_s2)
   (if __pd_s2 (setq _pd_s2 __pd_s2)) _pd_s2)
  (:pd_ss1
   (&optional __pd_ss1)
   (if __pd_ss1 (setq _pd_ss1 __pd_ss1)) _pd_ss1)
  (:pd_ss2
   (&optional __pd_ss2)
   (if __pd_ss2 (setq _pd_ss2 __pd_ss2)) _pd_ss2)
  (:psi_d_dot
   (&optional __psi_d_dot)
   (if __psi_d_dot (setq _psi_d_dot __psi_d_dot)) _psi_d_dot)
  (:psi_d_ddot
   (&optional __psi_d_ddot)
   (if __psi_d_ddot (setq _psi_d_ddot __psi_d_ddot)) _psi_d_ddot)
  (:serialization-length
   ()
   (+
    ;; float64[] _eta_d
    (* 8    (length _eta_d)) 4
    ;; float64[] _pd_s1
    (* 8    (length _pd_s1)) 4
    ;; float64[] _pd_s2
    (* 8    (length _pd_s2)) 4
    ;; float64[] _pd_ss1
    (* 8    (length _pd_ss1)) 4
    ;; float64[] _pd_ss2
    (* 8    (length _pd_ss2)) 4
    ;; float64 _psi_d_dot
    8
    ;; float64 _psi_d_ddot
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
     ;; float64[] _pd_s1
     (write-long (length _pd_s1) s)
     (dotimes (i (length _pd_s1))
       (sys::poke (elt _pd_s1 i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _pd_s2
     (write-long (length _pd_s2) s)
     (dotimes (i (length _pd_s2))
       (sys::poke (elt _pd_s2 i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _pd_ss1
     (write-long (length _pd_ss1) s)
     (dotimes (i (length _pd_ss1))
       (sys::poke (elt _pd_ss1 i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _pd_ss2
     (write-long (length _pd_ss2) s)
     (dotimes (i (length _pd_ss2))
       (sys::poke (elt _pd_ss2 i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64 _psi_d_dot
       (sys::poke _psi_d_dot (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _psi_d_ddot
       (sys::poke _psi_d_ddot (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64[] _pd_s1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pd_s1 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pd_s1 i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _pd_s2
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pd_s2 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pd_s2 i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _pd_ss1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pd_ss1 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pd_ss1 i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _pd_ss2
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pd_ss2 (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _pd_ss2 i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64 _psi_d_dot
     (setq _psi_d_dot (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _psi_d_ddot
     (setq _psi_d_ddot (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get messages::guidance_signals :md5sum-) "fd30d3a050e6c9293f8dcca19a9c94ca")
(setf (get messages::guidance_signals :datatype-) "messages/guidance_signals")
(setf (get messages::guidance_signals :definition-)
      "float64[] eta_d
float64[] pd_s1
float64[] pd_s2
float64[] pd_ss1
float64[] pd_ss2
float64 psi_d_dot
float64 psi_d_ddot

")



(provide :messages/guidance_signals "fd30d3a050e6c9293f8dcca19a9c94ca")


