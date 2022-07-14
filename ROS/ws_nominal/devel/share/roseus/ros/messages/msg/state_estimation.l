;; Auto-generated. Do not edit!


(when (boundp 'messages::state_estimation)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 'state_estimation (find-package "MESSAGES")))
(unless (find-package "MESSAGES::STATE_ESTIMATION")
  (make-package "MESSAGES::STATE_ESTIMATION"))

(in-package "ROS")
;;//! \htmlinclude state_estimation.msg.html


(defclass messages::state_estimation
  :super ros::object
  :slots (_eta_hat _nu_hat _bias_hat ))

(defmethod messages::state_estimation
  (:init
   (&key
    ((:eta_hat __eta_hat) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:nu_hat __nu_hat) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:bias_hat __bias_hat) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _eta_hat __eta_hat)
   (setq _nu_hat __nu_hat)
   (setq _bias_hat __bias_hat)
   self)
  (:eta_hat
   (&optional __eta_hat)
   (if __eta_hat (setq _eta_hat __eta_hat)) _eta_hat)
  (:nu_hat
   (&optional __nu_hat)
   (if __nu_hat (setq _nu_hat __nu_hat)) _nu_hat)
  (:bias_hat
   (&optional __bias_hat)
   (if __bias_hat (setq _bias_hat __bias_hat)) _bias_hat)
  (:serialization-length
   ()
   (+
    ;; float64[] _eta_hat
    (* 8    (length _eta_hat)) 4
    ;; float64[] _nu_hat
    (* 8    (length _nu_hat)) 4
    ;; float64[] _bias_hat
    (* 8    (length _bias_hat)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _eta_hat
     (write-long (length _eta_hat) s)
     (dotimes (i (length _eta_hat))
       (sys::poke (elt _eta_hat i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _nu_hat
     (write-long (length _nu_hat) s)
     (dotimes (i (length _nu_hat))
       (sys::poke (elt _nu_hat i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _bias_hat
     (write-long (length _bias_hat) s)
     (dotimes (i (length _bias_hat))
       (sys::poke (elt _bias_hat i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _eta_hat
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eta_hat (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _eta_hat i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _nu_hat
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _nu_hat (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _nu_hat i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _bias_hat
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _bias_hat (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _bias_hat i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get messages::state_estimation :md5sum-) "8f1bb4322eba02c2ff0b75462df79905")
(setf (get messages::state_estimation :datatype-) "messages/state_estimation")
(setf (get messages::state_estimation :definition-)
      "float64[] eta_hat
float64[] nu_hat
float64[] bias_hat

")



(provide :messages/state_estimation "8f1bb4322eba02c2ff0b75462df79905")


