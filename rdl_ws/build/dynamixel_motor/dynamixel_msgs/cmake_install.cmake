# Install script for directory: /home/chenshengchen/New_lamp_control/rdl_ws/src/dynamixel_motor/dynamixel_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/chenshengchen/New_lamp_control/rdl_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dynamixel_msgs/msg" TYPE FILE FILES
    "/home/chenshengchen/New_lamp_control/rdl_ws/src/dynamixel_motor/dynamixel_msgs/msg/JointState.msg"
    "/home/chenshengchen/New_lamp_control/rdl_ws/src/dynamixel_motor/dynamixel_msgs/msg/MotorState.msg"
    "/home/chenshengchen/New_lamp_control/rdl_ws/src/dynamixel_motor/dynamixel_msgs/msg/MotorStateList.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dynamixel_msgs/cmake" TYPE FILE FILES "/home/chenshengchen/New_lamp_control/rdl_ws/build/dynamixel_motor/dynamixel_msgs/catkin_generated/installspace/dynamixel_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/chenshengchen/New_lamp_control/rdl_ws/devel/include/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/chenshengchen/New_lamp_control/rdl_ws/devel/share/roseus/ros/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/chenshengchen/New_lamp_control/rdl_ws/devel/share/common-lisp/ros/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/chenshengchen/New_lamp_control/rdl_ws/devel/share/gennodejs/ros/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/chenshengchen/New_lamp_control/rdl_ws/devel/lib/python2.7/dist-packages/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/chenshengchen/New_lamp_control/rdl_ws/devel/lib/python2.7/dist-packages/dynamixel_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/chenshengchen/New_lamp_control/rdl_ws/build/dynamixel_motor/dynamixel_msgs/catkin_generated/installspace/dynamixel_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dynamixel_msgs/cmake" TYPE FILE FILES "/home/chenshengchen/New_lamp_control/rdl_ws/build/dynamixel_motor/dynamixel_msgs/catkin_generated/installspace/dynamixel_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dynamixel_msgs/cmake" TYPE FILE FILES
    "/home/chenshengchen/New_lamp_control/rdl_ws/build/dynamixel_motor/dynamixel_msgs/catkin_generated/installspace/dynamixel_msgsConfig.cmake"
    "/home/chenshengchen/New_lamp_control/rdl_ws/build/dynamixel_motor/dynamixel_msgs/catkin_generated/installspace/dynamixel_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dynamixel_msgs" TYPE FILE FILES "/home/chenshengchen/New_lamp_control/rdl_ws/src/dynamixel_motor/dynamixel_msgs/package.xml")
endif()

