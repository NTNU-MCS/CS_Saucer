; Auto-generated. Do not edit!


(cl:in-package qualisys-msg)


;//! \htmlinclude Markers.msg.html

(cl:defclass <Markers> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (markers
    :reader markers
    :initarg :markers
    :type (cl:vector qualisys-msg:Marker)
   :initform (cl:make-array 0 :element-type 'qualisys-msg:Marker :initial-element (cl:make-instance 'qualisys-msg:Marker))))
)

(cl:defclass Markers (<Markers>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Markers>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Markers)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name qualisys-msg:<Markers> is deprecated: use qualisys-msg:Markers instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Markers>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader qualisys-msg:header-val is deprecated.  Use qualisys-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'markers-val :lambda-list '(m))
(cl:defmethod markers-val ((m <Markers>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader qualisys-msg:markers-val is deprecated.  Use qualisys-msg:markers instead.")
  (markers m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Markers>) ostream)
  "Serializes a message object of type '<Markers>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'markers))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'markers))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Markers>) istream)
  "Deserializes a message object of type '<Markers>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'markers) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'markers)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'qualisys-msg:Marker))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Markers>)))
  "Returns string type for a message object of type '<Markers>"
  "qualisys/Markers")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Markers)))
  "Returns string type for a message object of type 'Markers"
  "qualisys/Markers")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Markers>)))
  "Returns md5sum for a message object of type '<Markers>"
  "6ba87eb5111a9609174c0acf8542f67d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Markers)))
  "Returns md5sum for a message object of type 'Markers"
  "6ba87eb5111a9609174c0acf8542f67d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Markers>)))
  "Returns full string definition for message of type '<Markers>"
  (cl:format cl:nil "Header header~%qualisys/Marker[] markers~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: qualisys/Marker~%string name~%string subject_name~%geometry_msgs/Point position~%bool occluded~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Markers)))
  "Returns full string definition for message of type 'Markers"
  (cl:format cl:nil "Header header~%qualisys/Marker[] markers~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: qualisys/Marker~%string name~%string subject_name~%geometry_msgs/Point position~%bool occluded~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Markers>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'markers) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Markers>))
  "Converts a ROS message object to a list"
  (cl:list 'Markers
    (cl:cons ':header (header msg))
    (cl:cons ':markers (markers msg))
))
