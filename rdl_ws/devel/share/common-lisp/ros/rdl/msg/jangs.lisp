; Auto-generated. Do not edit!


(cl:in-package rdl-msg)


;//! \htmlinclude jangs.msg.html

(cl:defclass <jangs> (roslisp-msg-protocol:ros-message)
  ((q
    :reader q
    :initarg :q
    :type (cl:vector cl:float)
   :initform (cl:make-array 5 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass jangs (<jangs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jangs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jangs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rdl-msg:<jangs> is deprecated: use rdl-msg:jangs instead.")))

(cl:ensure-generic-function 'q-val :lambda-list '(m))
(cl:defmethod q-val ((m <jangs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rdl-msg:q-val is deprecated.  Use rdl-msg:q instead.")
  (q m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jangs>) ostream)
  "Serializes a message object of type '<jangs>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'q))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jangs>) istream)
  "Deserializes a message object of type '<jangs>"
  (cl:setf (cl:slot-value msg 'q) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'q)))
    (cl:dotimes (i 5)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jangs>)))
  "Returns string type for a message object of type '<jangs>"
  "rdl/jangs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jangs)))
  "Returns string type for a message object of type 'jangs"
  "rdl/jangs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jangs>)))
  "Returns md5sum for a message object of type '<jangs>"
  "d7d622de160bc058ec8b0b47fd78e313")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jangs)))
  "Returns md5sum for a message object of type 'jangs"
  "d7d622de160bc058ec8b0b47fd78e313")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jangs>)))
  "Returns full string definition for message of type '<jangs>"
  (cl:format cl:nil "float32[5] q~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jangs)))
  "Returns full string definition for message of type 'jangs"
  (cl:format cl:nil "float32[5] q~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jangs>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'q) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jangs>))
  "Converts a ROS message object to a list"
  (cl:list 'jangs
    (cl:cons ':q (q msg))
))
