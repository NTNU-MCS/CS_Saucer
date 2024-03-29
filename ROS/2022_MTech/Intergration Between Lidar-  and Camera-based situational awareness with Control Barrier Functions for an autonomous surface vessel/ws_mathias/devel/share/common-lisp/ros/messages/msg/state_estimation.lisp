; Auto-generated. Do not edit!


(cl:in-package messages-msg)


;//! \htmlinclude state_estimation.msg.html

(cl:defclass <state_estimation> (roslisp-msg-protocol:ros-message)
  ((eta_hat
    :reader eta_hat
    :initarg :eta_hat
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (nu_hat
    :reader nu_hat
    :initarg :nu_hat
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (bias_hat
    :reader bias_hat
    :initarg :bias_hat
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass state_estimation (<state_estimation>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <state_estimation>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'state_estimation)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name messages-msg:<state_estimation> is deprecated: use messages-msg:state_estimation instead.")))

(cl:ensure-generic-function 'eta_hat-val :lambda-list '(m))
(cl:defmethod eta_hat-val ((m <state_estimation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:eta_hat-val is deprecated.  Use messages-msg:eta_hat instead.")
  (eta_hat m))

(cl:ensure-generic-function 'nu_hat-val :lambda-list '(m))
(cl:defmethod nu_hat-val ((m <state_estimation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:nu_hat-val is deprecated.  Use messages-msg:nu_hat instead.")
  (nu_hat m))

(cl:ensure-generic-function 'bias_hat-val :lambda-list '(m))
(cl:defmethod bias_hat-val ((m <state_estimation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:bias_hat-val is deprecated.  Use messages-msg:bias_hat instead.")
  (bias_hat m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <state_estimation>) ostream)
  "Serializes a message object of type '<state_estimation>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'eta_hat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'eta_hat))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'nu_hat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'nu_hat))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'bias_hat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'bias_hat))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <state_estimation>) istream)
  "Deserializes a message object of type '<state_estimation>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'eta_hat) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'eta_hat)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'nu_hat) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'nu_hat)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'bias_hat) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'bias_hat)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<state_estimation>)))
  "Returns string type for a message object of type '<state_estimation>"
  "messages/state_estimation")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'state_estimation)))
  "Returns string type for a message object of type 'state_estimation"
  "messages/state_estimation")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<state_estimation>)))
  "Returns md5sum for a message object of type '<state_estimation>"
  "8f1bb4322eba02c2ff0b75462df79905")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'state_estimation)))
  "Returns md5sum for a message object of type 'state_estimation"
  "8f1bb4322eba02c2ff0b75462df79905")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<state_estimation>)))
  "Returns full string definition for message of type '<state_estimation>"
  (cl:format cl:nil "float64[] eta_hat~%float64[] nu_hat~%float64[] bias_hat~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'state_estimation)))
  "Returns full string definition for message of type 'state_estimation"
  (cl:format cl:nil "float64[] eta_hat~%float64[] nu_hat~%float64[] bias_hat~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <state_estimation>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'eta_hat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'nu_hat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'bias_hat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <state_estimation>))
  "Converts a ROS message object to a list"
  (cl:list 'state_estimation
    (cl:cons ':eta_hat (eta_hat msg))
    (cl:cons ':nu_hat (nu_hat msg))
    (cl:cons ':bias_hat (bias_hat msg))
))
