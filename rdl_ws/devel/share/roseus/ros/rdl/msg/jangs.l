;; Auto-generated. Do not edit!


(when (boundp 'rdl::jangs)
  (if (not (find-package "RDL"))
    (make-package "RDL"))
  (shadow 'jangs (find-package "RDL")))
(unless (find-package "RDL::JANGS")
  (make-package "RDL::JANGS"))

(in-package "ROS")
;;//! \htmlinclude jangs.msg.html


(defclass rdl::jangs
  :super ros::object
  :slots (_q ))

(defmethod rdl::jangs
  (:init
   (&key
    ((:q __q) (make-array 5 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _q __q)
   self)
  (:q
   (&optional __q)
   (if __q (setq _q __q)) _q)
  (:serialization-length
   ()
   (+
    ;; float32[5] _q
    (* 4    5)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[5] _q
     (dotimes (i 5)
       (sys::poke (elt _q i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[5] _q
   (dotimes (i (length _q))
     (setf (elt _q i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get rdl::jangs :md5sum-) "d7d622de160bc058ec8b0b47fd78e313")
(setf (get rdl::jangs :datatype-) "rdl/jangs")
(setf (get rdl::jangs :definition-)
      "float32[5] q

")



(provide :rdl/jangs "d7d622de160bc058ec8b0b47fd78e313")


