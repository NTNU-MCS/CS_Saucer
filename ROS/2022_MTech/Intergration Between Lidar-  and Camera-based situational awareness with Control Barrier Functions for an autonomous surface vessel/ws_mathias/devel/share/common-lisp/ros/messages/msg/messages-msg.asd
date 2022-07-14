
(cl:in-package :asdf)

(defsystem "messages-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Fusion" :depends-on ("_package_Fusion"))
    (:file "_package_Fusion" :depends-on ("_package"))
    (:file "Object" :depends-on ("_package_Object"))
    (:file "_package_Object" :depends-on ("_package"))
    (:file "guidance_signals" :depends-on ("_package_guidance_signals"))
    (:file "_package_guidance_signals" :depends-on ("_package"))
    (:file "observer_message" :depends-on ("_package_observer_message"))
    (:file "_package_observer_message" :depends-on ("_package"))
    (:file "obstacle" :depends-on ("_package_obstacle"))
    (:file "_package_obstacle" :depends-on ("_package"))
    (:file "reference_message" :depends-on ("_package_reference_message"))
    (:file "_package_reference_message" :depends-on ("_package"))
    (:file "s" :depends-on ("_package_s"))
    (:file "_package_s" :depends-on ("_package"))
    (:file "s_message" :depends-on ("_package_s_message"))
    (:file "_package_s_message" :depends-on ("_package"))
    (:file "state_estimation" :depends-on ("_package_state_estimation"))
    (:file "_package_state_estimation" :depends-on ("_package"))
  ))