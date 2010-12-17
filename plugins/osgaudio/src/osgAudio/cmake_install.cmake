# Install script for directory: C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/src/osgAudio

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
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/Debug/../osgAudiod.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/Release/../osgAudio.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/MinSizeRel/../osgAudio.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/lib/RelWithDebInfo/../osgAudio.lib")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/Debug/../osgAudiod.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/Release/../osgAudio.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/MinSizeRel/../osgAudio.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Aru/Git/OSG_ShootingGallery/plugins/osgaudio2005/bin/RelWithDebInfo/../osgAudio.dll")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgAudio" TYPE FILE FILES
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/AudioEnvironment.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Config.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Error.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Export.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/FileStream.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Listener.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/OccludeCallback.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Sample.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SoundManager.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SoundNode.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SoundUpdateCB.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SoundRoot.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SoundState.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Source.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/SourceBase.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Stream.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/Version.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgAudio/BackendOpenALpp" TYPE FILE FILES
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/AudioEnvironmentOpenALpp.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/FileStreamOpenALpp.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/ListenerOpenALpp.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/SampleOpenALpp.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/SourceOpenALpp.h"
    "C:/Users/Aru/Desktop/osgaudio/2005/osgAudio_02_00_00/osgAudio_02_00_00/include/osgAudio/BackendOpenALpp/StreamOpenALpp.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libosgaudio-dev")

