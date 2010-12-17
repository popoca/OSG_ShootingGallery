# Install script for directory: C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/examples

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/osgAudio")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
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

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/osgaudio/cmake_install.cmake")
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/osgaudiomultiple/cmake_install.cmake")
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/osgaudioocclude/cmake_install.cmake")
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/osgaudioviewer/cmake_install.cmake")
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/osgaudio-lowlevel/cmake_install.cmake")
  INCLUDE("C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/examples/openalpp/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

