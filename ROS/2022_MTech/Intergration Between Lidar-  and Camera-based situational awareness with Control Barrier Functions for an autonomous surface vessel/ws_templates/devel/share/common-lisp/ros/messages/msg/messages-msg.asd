
(cl:in-package :asdf)

(defsystem "messages-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "observer_message" :depends-on ("_package_observer_message"))
    (:file "_package_observer_message" :depends-on ("_package"))
    (:file "reference_message" :depends-on ("_package_reference_message"))
    (:file "_package_reference_message" :depends-on ("_package"))
    (:file "s_message" :depends-on ("_package_s_message"))
    (:file "_package_s_message" :depends-on ("_package"))
  ))