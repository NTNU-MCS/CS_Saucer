; Auto-generated. Do not edit!


(cl:in-package messages-msg)


;//! \htmlinclude s.msg.html

(cl:defclass <s> (roslisp-msg-protocol:ros-message)
  ((s
    :reader s
    :initarg :s
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (s_dot
    :reader s_dot
    :initarg :s_dot
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass s (<s>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <s>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 's)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name messages-msg:<s> is deprecated: use messages-msg:s instead.")))

(cl:ensure-generic-function 's-val :lambda-list '(m))
(cl:defmethod s-val ((m <s>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:s-val is deprecated.  Use messages-msg:s instead.")
  (s m))

(cl:ensure-generic-function 's_dot-val :lambda-list '(m))
(cl:defmethod s_dot-val ((m <s>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:s_dot-val is deprecated.  Use messages-msg:s_dot instead.")
  (s_dot m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <s>) ostream)
  "Serializes a message object of type '<s>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 's))))
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
   (cl:slot-value msg 's))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 's_dot))))
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
   (cl:slot-value msg 's_dot))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <s>) istream)
  "Deserializes a message object of type '<s>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 's) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 's)))
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
  (cl:setf (cl:slot-value msg 's_dot) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 's_dot)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<s>)))
  "Returns string type for a message object of type '<s>"
  "messages/s")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 's)))
  "Returns string type for a message object of type 's"
  "messages/s")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<s>)))
  "Returns md5sum for a message object of type '<s>"
  "14fb056663501f0195cd852f090d3a8f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 's)))
  "Returns md5sum for a message object of type 's"
  "14fb056663501f0195cd852f090d3a8f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<s>)))
  "Returns full string definition for message of type '<s>"
  (cl:format cl:nil "float64[] s~%float64[] s_dot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 's)))
  "Returns full string definition for message of type 's"
  (cl:format cl:nil "float64[] s~%float64[] s_dot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <s>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 's) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 's_dot) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <s>))
  "Converts a ROS message object to a list"
  (cl:list 's
    (cl:cons ':s (s msg))
    (cl:cons ':s_dot (s_dot msg))
))
