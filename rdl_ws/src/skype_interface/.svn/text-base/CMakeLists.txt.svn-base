cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
include($ENV{ROS_ROOT}/core/rosbuild/FindPkgConfig.cmake)

rosbuild_add_library(skype-service src/skype-service.cpp)
pkg_check_modules(GDK REQUIRED gdk-2.0)
include_directories(${GDK_INCLUDE_DIRS})
link_directories(${GDK_LIBRARY_DIRS})
target_link_libraries(skype-service ${GDK_LIBRARIES})
pkg_check_modules(DBUS REQUIRED dbus-1)
include_directories(${DBUS_INCLUDE_DIRS})
link_directories(${DBUS_LIBRARY_DIRS})
target_link_libraries(skype-service ${DBUS_LIBRARIES})
pkg_check_modules(DBUSG REQUIRED dbus-glib-1)
include_directories(${DBUSG_INCLUDE_DIRS})
link_directories(${DBUSG_LIBRARY_DIRS})
target_link_libraries(skype-service ${DBUSG_LIBRARIES})

rosbuild_add_executable(skype_node src/skype_node.cpp)

pkg_check_modules(GTK REQUIRED gtk+-2.0)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
target_link_libraries(skype_node ${GTK_LIBRARIES})

pkg_check_modules(GTHREAD REQUIRED gthread-2.0)
include_directories(${GTHREAD_INCLUDE_DIRS})
link_directories(${GTHREAD_LIBRARY_DIRS})
target_link_libraries(skype_node ${GTHREAD_LIBRARIES})


target_link_libraries(skype_node skype-service)
target_link_libraries(skype_node ${GDK_LIBRARIES})
target_link_libraries(skype_node ${DBUS_LIBRARIES})
target_link_libraries(skype_node ${DBUSG_LIBRARIES})
