; Auto-generated. Do not edit!


(cl:in-package book_tracker-msg)


;//! \htmlinclude book_pos.msg.html

(cl:defclass <book_pos> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass book_pos (<book_pos>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <book_pos>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'book_pos)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name book_tracker-msg:<book_pos> is deprecated: use book_tracker-msg:book_pos instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <book_pos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader book_tracker-msg:x-val is deprecated.  Use book_tracker-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <book_pos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader book_tracker-msg:y-val is deprecated.  Use book_tracker-msg:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <book_pos>) ostream)
  "Serializes a message object of type '<book_pos>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <book_pos>) istream)
  "Deserializes a message object of type '<book_pos>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<book_pos>)))
  "Returns string type for a message object of type '<book_pos>"
  "book_tracker/book_pos")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'book_pos)))
  "Returns string type for a message object of type 'book_pos"
  "book_tracker/book_pos")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<book_pos>)))
  "Returns md5sum for a message object of type '<book_pos>"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'book_pos)))
  "Returns md5sum for a message object of type 'book_pos"
  "ff8d7d66dd3e4b731ef14a45d38888b6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<book_pos>)))
  "Returns full string definition for message of type '<book_pos>"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'book_pos)))
  "Returns full string definition for message of type 'book_pos"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <book_pos>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <book_pos>))
  "Converts a ROS message object to a list"
  (cl:list 'book_pos
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
