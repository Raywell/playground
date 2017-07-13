# Install script for directory: /home/artem/gl/project/libs/glfw-3.2.1

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/artem/gl/project/libs/glfw-3.2.1/include/GLFW" FILES_MATCHING REGEX "/glfw3\\.h$" REGEX "/glfw3native\\.h$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3" TYPE FILE FILES
    "/home/artem/gl/project/libs/glfw-3.2.1/src/glfw3Config.cmake"
    "/home/artem/gl/project/libs/glfw-3.2.1/src/glfw3ConfigVersion.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3/glfw3Targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3/glfw3Targets.cmake"
         "/home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles/Export/lib64/cmake/glfw3/glfw3Targets.cmake")
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3/glfw3Targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3/glfw3Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3" TYPE FILE FILES "/home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles/Export/lib64/cmake/glfw3/glfw3Targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/glfw3" TYPE FILE FILES "/home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles/Export/lib64/cmake/glfw3/glfw3Targets-noconfig.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/pkgconfig" TYPE FILE FILES "/home/artem/gl/project/libs/glfw-3.2.1/src/glfw3.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/artem/gl/project/libs/glfw-3.2.1/src/cmake_install.cmake")
  INCLUDE("/home/artem/gl/project/libs/glfw-3.2.1/examples/cmake_install.cmake")
  INCLUDE("/home/artem/gl/project/libs/glfw-3.2.1/tests/cmake_install.cmake")
  INCLUDE("/home/artem/gl/project/libs/glfw-3.2.1/docs/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/artem/gl/project/libs/glfw-3.2.1/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/artem/gl/project/libs/glfw-3.2.1/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
