# Install script for directory: /home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/samples" TYPE FILE FILES
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/MQTTAsync_publish.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/MQTTAsync_subscribe.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/MQTTClient_publish.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/MQTTClient_publish_async.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/MQTTClient_subscribe.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/paho_c_pub.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/paho_c_sub.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/paho_cs_pub.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/paho_cs_sub.c"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/samples/pubsub_opts.c"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/CONTRIBUTING.md"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/epl-v10"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/edl-v10"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/README.md"
    "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/notice.html"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/src/cmake_install.cmake")
  include("/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/xiaopgw/26051/c/文件及网址之类的/paho/paho.mqtt.c-1.3.0/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
