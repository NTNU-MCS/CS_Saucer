;; Auto-generated. Do not edit!


(when (boundp 'messages::observer_message)
  (if (not (find-package "MESSAGES"))
    (make-package "MESSAGES"))
  (shadow 'observer_message (find-package "MESSAGES")))
(unless (find-package "MESSAGES::OBSERVER_MESSAGE")
  (make-package "MESSAGES::OBSERVER_MESSAGE"))

(in-package "ROS")
;;//! \htmlinclude observer_message.msg.html


(defclass messages::observer_message
  :super ros::object
  :slots (_eta _nu _bias ))

(defmethod messages::observer_message
  (:init
   (&key
    ((:eta __eta) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:nu __nu) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:bias __bias) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _eta __eta)
   (setq _nu __nu)
   (setq _bias __bias)
   self)
  (:eta
   (&optional __eta)
   (if __eta (setq _eta __eta)) _eta)
  (:nu
   (&optional __nu)
   (if __nu (setq _nu __nu)) _nu)
  (:bias
   (&optional __bias)
   (if __bias (setq _bias __bias)) _bias)
  (:serialization-length
   ()
   (+
    ;; float64[] _eta
    (* 8    (length _eta)) 4
    ;; float64[] _nu
    (* 8    (length _nu)) 4
    ;; float64[] _bias
    (* 8    (length _bias)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _eta
     (write-long (length _eta) s)
     (dotimes (i (length _eta))
       (sys::poke (elt _eta i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _nu
     (write-long (length _nu) s)
     (dotimes (i (length _nu))
       (sys::poke (elt _nu i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _bias
     (write-long (length _bias) s)
     (dotimes (i (length _bias))
       (sys::poke (elt _bias i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _eta
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eta (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _eta i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _nu
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _nu (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _nu i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _bias
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _bias (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _bias i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get messages::observer_message :md5sum-) "7f3202088d21e8801c58a7a4f2fe213a")
(setf (get messages::observer_message :datatype-) "messages/observer_message")
(setf (get messages::observer_message :definition-)
      "float64[] eta
float64[] nu
float64[] bias
")



(provide :messages/observer_message "7f3202088d21e8801c58a7a4f2fe213a")


