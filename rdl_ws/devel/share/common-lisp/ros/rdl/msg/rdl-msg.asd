
(cl:in-package :asdf)

(defsystem "rdl-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "jangs" :depends-on ("_package_jangs"))
    (:file "_package_jangs" :depends-on ("_package"))
  ))