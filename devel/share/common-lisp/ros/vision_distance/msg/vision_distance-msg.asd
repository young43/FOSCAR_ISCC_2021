
(cl:in-package :asdf)

(defsystem "vision_distance-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Colorcone" :depends-on ("_package_Colorcone"))
    (:file "_package_Colorcone" :depends-on ("_package"))
    (:file "ColorconeArray" :depends-on ("_package_ColorconeArray"))
    (:file "_package_ColorconeArray" :depends-on ("_package"))
  ))