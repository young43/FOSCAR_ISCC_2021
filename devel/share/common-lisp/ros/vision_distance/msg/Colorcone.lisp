; Auto-generated. Do not edit!


(cl:in-package vision_distance-msg)


;//! \htmlinclude Colorcone.msg.html

(cl:defclass <Colorcone> (roslisp-msg-protocol:ros-message)
  ((flag
    :reader flag
    :initarg :flag
    :type cl:integer
    :initform 0)
   (dist_x
    :reader dist_x
    :initarg :dist_x
    :type cl:float
    :initform 0.0)
   (dist_y
    :reader dist_y
    :initarg :dist_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass Colorcone (<Colorcone>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Colorcone>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Colorcone)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name vision_distance-msg:<Colorcone> is deprecated: use vision_distance-msg:Colorcone instead.")))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <Colorcone>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vision_distance-msg:flag-val is deprecated.  Use vision_distance-msg:flag instead.")
  (flag m))

(cl:ensure-generic-function 'dist_x-val :lambda-list '(m))
(cl:defmethod dist_x-val ((m <Colorcone>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vision_distance-msg:dist_x-val is deprecated.  Use vision_distance-msg:dist_x instead.")
  (dist_x m))

(cl:ensure-generic-function 'dist_y-val :lambda-list '(m))
(cl:defmethod dist_y-val ((m <Colorcone>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vision_distance-msg:dist_y-val is deprecated.  Use vision_distance-msg:dist_y instead.")
  (dist_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Colorcone>) ostream)
  "Serializes a message object of type '<Colorcone>"
  (cl:let* ((signed (cl:slot-value msg 'flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dist_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dist_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Colorcone>) istream)
  "Deserializes a message object of type '<Colorcone>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dist_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dist_y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Colorcone>)))
  "Returns string type for a message object of type '<Colorcone>"
  "vision_distance/Colorcone")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Colorcone)))
  "Returns string type for a message object of type 'Colorcone"
  "vision_distance/Colorcone")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Colorcone>)))
  "Returns md5sum for a message object of type '<Colorcone>"
  "f94403809a4a82603b54e67d56403620")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Colorcone)))
  "Returns md5sum for a message object of type 'Colorcone"
  "f94403809a4a82603b54e67d56403620")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Colorcone>)))
  "Returns full string definition for message of type '<Colorcone>"
  (cl:format cl:nil "int32 flag~%float64 dist_x~%float64 dist_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Colorcone)))
  "Returns full string definition for message of type 'Colorcone"
  (cl:format cl:nil "int32 flag~%float64 dist_x~%float64 dist_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Colorcone>))
  (cl:+ 0
     4
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Colorcone>))
  "Converts a ROS message object to a list"
  (cl:list 'Colorcone
    (cl:cons ':flag (flag msg))
    (cl:cons ':dist_x (dist_x msg))
    (cl:cons ':dist_y (dist_y msg))
))
