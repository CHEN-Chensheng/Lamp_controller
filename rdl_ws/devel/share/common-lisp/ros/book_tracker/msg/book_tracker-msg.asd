
(cl:in-package :asdf)

(defsystem "book_tracker-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "book_pos" :depends-on ("_package_book_pos"))
    (:file "_package_book_pos" :depends-on ("_package"))
  ))