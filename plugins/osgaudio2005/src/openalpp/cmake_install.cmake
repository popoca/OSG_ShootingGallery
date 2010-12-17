# Install script for directory: C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/src/openalpp

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/Debug/../openalppd.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/Release/../openalpp.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/MinSizeRel/../openalpp.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/RelWithDebInfo/../openalpp.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/Debug/../openalppd.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/Release/../openalpp.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/MinSizeRel/../openalpp.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/RelWithDebInfo/../openalpp.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openalpp" TYPE FILE FILES
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/AudioBase.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/AudioConvert.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/AudioEnvironment.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Capture.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/config.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/DeviceUpdater.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Error.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Export.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/FileStream.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/FileStreamUpdater.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/GroupSource.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Listener.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/NetStream.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/NetUpdater.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/PositionedObject.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Sample.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/SoundData.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Source.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/SourceBase.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/Stream.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/StreamUpdater.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/openalpp/windowsstuff.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")

