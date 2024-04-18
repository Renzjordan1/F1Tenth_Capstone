<<<<<<< HEAD
# Install script for directory: /home/rstole01/Documents/CapstoneGit/humble_ws/src/pursuit_lab

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rstole01/Documents/CapstoneGit/humble_ws/install/pursuit_lab")
=======
# Install script for directory: /home/rstole01/Documents/CSE-596/humble_ws/src/pursuit_lab

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rstole01/Documents/CSE-596/humble_ws/install/pursuit_lab")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/pursuit_lab-0.0.0-py3.10.egg-info" TYPE DIRECTORY FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_python/pursuit_lab/pursuit_lab.egg-info/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/pursuit_lab" TYPE DIRECTORY FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/src/pursuit_lab/pursuit_lab/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/pursuit_lab-0.0.0-py3.10.egg-info" TYPE DIRECTORY FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_python/pursuit_lab/pursuit_lab.egg-info/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/pursuit_lab" TYPE DIRECTORY FILES "/home/rstole01/Documents/CSE-596/humble_ws/src/pursuit_lab/pursuit_lab/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
<<<<<<< HEAD
        "/usr/bin/python3" "-m" "compileall"
        "/home/rstole01/Documents/CapstoneGit/humble_ws/install/pursuit_lab/local/lib/python3.10/dist-packages/pursuit_lab"
=======
        "/usr/bin/python3.10" "-m" "compileall"
        "/home/rstole01/Documents/CSE-596/humble_ws/install/pursuit_lab/local/lib/python3.10/dist-packages/pursuit_lab"
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pursuit_lab" TYPE PROGRAM FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/src/pursuit_lab/pursuit_lab/pure_pursuit_node.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/pursuit_lab")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/pursuit_lab")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pursuit_lab" TYPE PROGRAM FILES "/home/rstole01/Documents/CSE-596/humble_ws/src/pursuit_lab/pursuit_lab/pure_pursuit_node.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/pursuit_lab")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/pursuit_lab")
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/ament_prefix_path.dsv")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/ament_prefix_path.dsv")
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/packages/pursuit_lab")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/environment" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_index/share/ament_index/resource_index/packages/pursuit_lab")
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab/cmake" TYPE FILE FILES
<<<<<<< HEAD
    "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_core/pursuit_labConfig.cmake"
    "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/ament_cmake_core/pursuit_labConfig-version.cmake"
=======
    "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_core/pursuit_labConfig.cmake"
    "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/ament_cmake_core/pursuit_labConfig-version.cmake"
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CapstoneGit/humble_ws/src/pursuit_lab/package.xml")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pursuit_lab" TYPE FILE FILES "/home/rstole01/Documents/CSE-596/humble_ws/src/pursuit_lab/package.xml")
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/home/rstole01/Documents/CapstoneGit/humble_ws/build/pursuit_lab/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/rstole01/Documents/CSE-596/humble_ws/build/pursuit_lab/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> ce1a67ebf7edb694f0f93a1943a2aeb630cdb943
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
