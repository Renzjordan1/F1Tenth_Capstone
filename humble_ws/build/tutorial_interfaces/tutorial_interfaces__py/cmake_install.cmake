<<<<<<< HEAD
<<<<<<< HEAD
# Install script for directory: /home/rstole01/Documents/CapstoneGit/humble_ws/build/tutorial_interfaces/tutorial_interfaces__py

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rstole01/Documents/CapstoneGit/humble_ws/install/tutorial_interfaces")
=======
=======
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
# Install script for directory: /home/rstole01/Documents/CSE-596/humble_ws/build/tutorial_interfaces/tutorial_interfaces__py

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rstole01/Documents/CSE-596/humble_ws/install/tutorial_interfaces")
<<<<<<< HEAD
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
=======
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
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

