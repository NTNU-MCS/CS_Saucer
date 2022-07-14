; Auto-generated. Do not edit!


(cl:in-package messages-msg)


;//! \htmlinclude s_message.msg.html

(cl:defclass <s_message> (roslisp-msg-protocol:ros-message)
  ((s
    :reader s
    :initarg :s
    :type cl:float
    :initform 0.0)
   (s_dot
    :reader s_dot
    :initarg :s_dot
    :type cl:float
    :initform 0.0))
)

(cl:defclass s_message (<s_message>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <s_message>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 's_message)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name messages-msg:<s_message> is deprecated: use messages-msg:s_message instead.")))

(cl:ensure-generic-function 's-val :lambda-list '(m))
(cl:defmethod s-val ((m <s_message>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:s-val is deprecated.  Use messages-msg:s instead.")
  (s m))

(cl:ensure-generic-function 's_dot-val :lambda-list '(m))
(cl:defmethod s_dot-val ((m <s_message>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader messages-msg:s_dot-val is deprecated.  Use messages-msg:s_dot instead.")
  (s_dot m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <s_message>) ostream)
  "Serializes a message object of type '<s_message>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 's))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 's_dot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <s_message>) istream)
  "Deserializes a message object of type '<s_message>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 's) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 's_dot) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<s_message>)))
  "Returns string type for a message object of type '<s_message>"
  "messages/s_message")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 's_message)))
  "Returns string type for a message object of type 's_message"
  "messages/s_message")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<s_message>)))
  "Returns md5sum for a message object of type '<s_message>"
  "44991c89fe9397efcd14043a99f9f1c5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 's_message)))
  "Returns md5sum for a message object of type 's_message"
  "44991c89fe9397efcd14043a99f9f1c5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<s_message>)))
  "Returns full string definition for message of type '<s_message>"
  (cl:format cl:nil "float64 s~%float64 s_dot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 's_message)))
  "Returns full string definition for message of type 's_message"
  (cl:format cl:nil "float64 s~%float64 s_dot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <s_message>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <s_message>))
  "Converts a ROS message object to a list"
  (cl:list 's_message
    (cl:cons ':s (s msg))
    (cl:cons ':s_dot (s_dot msg))
))
