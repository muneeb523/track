#/****************************************************************************
# *
# * The MIT License (MIT)
# *
# * Copyright (c) 2020-2024 VeriSilicon Holdings Co., Ltd.
# *
# * Permission is hereby granted, free of charge, to any person obtaining a
# * copy of this software and associated documentation files (the "Software"),
# * to deal in the Software without restriction, including without limitation
# * the rights to use, copy, modify, merge, publish, distribute, sublicense,
# * and/or sell copies of the Software, and to permit persons to whom the
# * Software is furnished to do so, subject to the following conditions:
# *
# * The above copyright notice and this permission notice shall be included in
# * all copies or substantial portions of the Software.
# *
# * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# * DEALINGS IN THE SOFTWARE.
# *
# *****************************************************************************/

cmake_minimum_required(VERSION 3.1.0)
project(ISPcore_SW_STACK)
if( NOT DEFINED APPSHELL_TOP_COMPILE)

  if(DEFINED QTLESS)
      if(${QTLESS} STREQUAL 0)
          set (QTLESS 0)
      else(${QTLESS} STREQUAL 0)
          set (QTLESS 1)
      endif(${QTLESS} STREQUAL 0)
  else(DEFINED QTLESS)
      #default value of QTLESS
  set (QTLESS 1)
  endif(DEFINED QTLESS)

  set (PLATFORM $ENV{COMPILE_PLATFORM})
  if(DEFINED PLATFORM)
      if(${PLATFORM} STREQUAL ARM64)
          message("==========SET platform to ARM64==========")
          set (CMAKE_SYSTEM_NAME Linux)
          set (CMAKE_SYSTEM_PROCESSOR AArch64)

          set(CMAKE_PREFIX_PATH $ENV{Qt_DIR5_ARM64})
          set(QWT6_PATH $ENV{QWT_DIR_ARM64})
          message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
          message("QWT6_PATH: ${QWT6_PATH}")
          set (ARM64 1)
      elseif(${PLATFORM} STREQUAL ARMV7)
          message("==========SET platform to ARMV7==========")
          set (PLATFORM ARMV7)
          set(CMAKE_PREFIX_PATH $ENV{Qt_DIR5_ARMV7})
          set(QWT6_PATH $ENV{QWT_DIR_ARMV7})
          message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
          message("QWT6_PATH: ${QWT6_PATH}")
          set (ARMV7 1)
      elseif(${PLATFORM} STREQUAL X86)
          message("==========SET platform to X86==========")
          set (PLATFORM X86)

          set(CMAKE_PREFIX_PATH $ENV{Qt_DIR5_X86})
          set(QWT6_PATH $ENV{QWT_DIR_X86})
          message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
          message("QWT6_PATH: ${QWT6_PATH}")
      elseif(${PLATFORM} STREQUAL CSKY)
          message("==========SET platform to CSKY==========")
          set (PLATFORM CSKY)
      else(${PLATFORM} STREQUAL ARM64)
          message(FATAL_ERROR "CFG_ERROR PLATFORM=${PLATFORM} error, can not found configuration settings, exit")
      endif (${PLATFORM} STREQUAL ARM64)
  else(DEFINED PLATFORM)
      message("==========SET DEFAILT platform to X86==========")
      set (PLATFORM X86)
  endif(DEFINED PLATFORM)

  set(PROJECT_SUB_DIR "${PROJECT_BINARY_DIR}/obj")
  set(UNITS_TOP_DIRECTORY ${CMAKE_HOME_DIRECTORY})

  set (V4L2 1)
  add_definitions(-DSUPPORT_PASS_JSON)

  if(DEFINED PARTITION_BUILD)
    if(${PARTITION_BUILD} STREQUAL 0)
      set (GENERATE_PARTITION_BUILD 0)
    else(${PARTITION_BUILD} STREQUAL 0)
      set (GENERATE_PARTITION_BUILD 1)
    endif(${PARTITION_BUILD} STREQUAL 0)
  else(DEFINED PARTITION_BUILD)
    #default value of GENERATE_PARTITION_BUILD
    set (GENERATE_PARTITION_BUILD 1)
  endif(DEFINED PARTITION_BUILD)

  if(DEFINED 3A_SRC_BUILD)
    if(${3A_SRC_BUILD} STREQUAL 0)
      set (GENERATE_3A_LIB 0)
    else(${3A_SRC_BUILD} STREQUAL 0)
      set (GENERATE_3A_LIB 1)
    endif(${3A_SRC_BUILD} STREQUAL 0)
  else(DEFINED 3A_SRC_BUILD)
    #default value of GENERATE_PARTITION_BUILD
    set (GENERATE_3A_LIB 1)
  endif(DEFINED 3A_SRC_BUILD)

    if(${QTLESS} STREQUAL 0)
  set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
  set(Qt5Core_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Core")
  set(Qt5Gui_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Gui")
  set(Qt5Qml_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Qml")
  set(Qt5Quick_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Quick")
  set(Qt5Network_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Network")
  set(Qt5Multimedia_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Multimedia")
  set(Qt5MultimediaWidgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5MultimediaWidgets")
  set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")
  set(Qt5Xml_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Xml")
  #set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")

  #set(Qt5LinguistTools_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5LinguistTools")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  set(CMAKE_AUTOMOC ON)
  set(CMAKE_AUTOUIC ON)
  set(CMAKE_AUTORCC ON)

  find_package(Qt5 COMPONENTS Core Gui Qml Quick Multimedia MultimediaWidgets Widgets Xml REQUIRED)

endif(${QTLESS} STREQUAL 0)

#By configuration option choice for selections
#########################################################
#HW configuration begin
#ISP_VERSION selection choices:
# ISP8000NANO
# ISP8000NANO_V1801
# ISP8000NANO_V1802
#
# ISP8000L
# ISP8000L_V1801 *default
#
# ISP8000
#
#
#########################################################

message("## ISP_VERSION input: ${ISP_VERSION}")
set (PROJECT_CFG_FILE product_cfg_${ISP_VERSION}.cmake)
set (PROJECT_CFG_DIR ${UNITS_TOP_DIRECTORY}/mkrel)
include(${PROJECT_CFG_DIR}/${ISP_VERSION}/${PROJECT_CFG_FILE})

#HW configuration end
#########################################################

else( NOT DEFINED APPSHELL_TOP_COMPILE)
  set(PROJECT_SUB_DIR "${PROJECT_BINARY_DIR}/obj")
  set(UNITS_TOP_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../units)
endif( NOT DEFINED APPSHELL_TOP_COMPILE)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpic")
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

message(STATUS "=============================================================================")
set(PROJ_DESC "ISP driver project")
message(STATUS "Project description: " ${PROJ_DESC})

message(STATUS "project bin:" ${PROJECT_BINARY_DIR})
message(STATUS "project obj dir:" ${PROJECT_SUB_DIR})
message(STATUS "project src:" ${PROJECT_SOURCE_DIR})
message(STATUS "Cmake root dir:" ${UNITS_TOP_DIRECTORY})

if (NOT LIB_ROOT)
    get_filename_component(LIB_ROOT ${PROJECT_BINARY_DIR}/generated ABSOLUTE)
endif (NOT LIB_ROOT)
message ("LIB_ROOT is at: ${LIB_ROOT}")


if (NOT INSTALL_ROOT)
    get_filename_component(INSTALL_ROOT ${PROJECT_BINARY_DIR}/dist ABSOLUTE)
endif (NOT INSTALL_ROOT)
message ("INSTALL_ROOT is at: ${INSTALL_ROOT}")

# global verbosity enable
###set ( CMAKE_VERBOSE_MAKEFILE 1 )

###set ( FAST_BUILD 1 ) ###NOTE: ONLY FOR EXPERTS

# add some compiler switches for the whole project
if ( WIN32 )
    MESSAGE("system: WIN32")
    add_definitions(-DWIN32)
endif( WIN32 )

if ( UNIX )
    MESSAGE("system: UNIX")
    add_definitions(-DLINUX)
endif ( UNIX )

# add_definitions(-DFPGA_USE_MMAP)
add_definitions(-DMARVIN_HW_ALTERA)

# configure MIPI API for CamerIc MIPI module usage
set ( MIPI_USE_CAMERIC 1 )
if(MIPI_USE_CAMERIC)
    add_definitions(-DMIPI_USE_CAMERIC)
endif(MIPI_USE_CAMERIC)


# select which HAL to use, take care to define only one at a time!
add_definitions(-DHAL_ALTERA)
##add_definitions(-DHAL_MOCKUP)


#include global rules valid for the whole project:
include (globals.cmake)

# select where to draw (MOM is default)
add_definitions(-DCAM_ENGINE_DRAW_DOM_ONLY)

if(SENSOR)
if(ARM64)
add_definitions(-DARM64)
else(ARM64)
endif()
add_definitions(-DLIVE_SENSOR)
endif()

if ( ANDROID )
    MESSAGE("system: ANDROID")
    add_definitions(-DANDROID)
    set(LIB_PTHREAD_NAME "")
    set(LIB_RT_NAME "")
else ()
    set(LIB_PTHREAD_NAME "pthread")
    set(LIB_RT_NAME "rt")
endif ( ANDROID )

if (SUBDEV_CHAR)
add_definitions(-DSUBDEV_CHAR)
endif()

if (SUBDEV_V4L2)
add_definitions(-DSUBDEV_V4L2)
# Treat all warnings as errors
add_definitions(-Werror)
endif()

add_custom_target(clobber
                  COMMAND ${CMAKE_COMMAND} -E remove_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}
                  COMMENT "Delete ${LIB_ROOT}/${CMAKE_BUILD_TYPE}")

add_custom_target(create_dir
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/include
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${ISP_VERSION}

                  COMMENT "Create directory ${LIB_ROOT}")

add_custom_target(create_alldir
                   COMMENT "Create all modules' include directories")

if (NOT SENSOR)
if (NOT EXISTS ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${ISP_VERSION}/case)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/mkrel/${ISP_VERSION}/case ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${ISP_VERSION}/case)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/test/case/engine/resource ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${ISP_VERSION}/case/engine/resource)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/test/vgswcase.sh ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/vgswcase.sh)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/test/vgbmcase.sh ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/vgbmcase.sh)
endif()
endif()

if ( UNIX )
    add_custom_target(strip
                      COMMAND strip --strip-all "${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/*"
                      COMMENT "Stripping all files in ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin")
    add_custom_target(ctags
                      COMMAND ctags -R -f../tags --tag-relative=no  --totals=no  --exclude=.svn --exclude=../debug --exclude=../release --exclude=../build --exclude=${CMAKE_BUILD_TYPE} ..
                      COMMAND ctags -R -f./tags  --tag-relative=yes --totals=yes --exclude=.svn --exclude=../debug --exclude=../release --exclude=../build --exclude=${CMAKE_BUILD_TYPE} ..
                      COMMENT "Creating ctags file for all modules")
endif ( UNIX )


# Panasonic face recognition library
if(ENABLE_PFID)
    include(FindPkgConfig)
    pkg_check_modules(LIBPFID libpfid)
    if(LIBPFID_FOUND)
        add_definitions(-DHAVE_PFID)
        message(STATUS "Panasonic face recognition enabled" )
    else(LIBPFID_FOUND)
        message(STATUS "Panasonic face recognition lib not found" )
    endif(LIBPFID_FOUND)
else(ENABLE_PFID)
    message(STATUS "Panasonic face recognition disabled" )
endif(ENABLE_PFID)

# some usefull groups of libraries
set ( base_libs ebase_shared oslayer_shared version_shared common_shared bufferpool_shared )
set ( android_partial_base_libs ebase oslayer version common )
set ( base_test_libs )
#set ( base_test_libs embUnit_shared )
set ( platform_libs fpga_shared i2c_drv_shared hal_shared )
set ( android_partial_platform_libs fpga i2c_drv )
#set ( subctrl_libs vom_ctrl_shared som_ctrl_shared exa_ctrl_shared )

set ( drv_libs dl cameric_drv_shared cameric_reg_drv_shared isi_shared mipi_drv_shared cam_calibdb_shared )
set ( android_partial_drv_libs dl cameric_reg_drv isi mipi_drv cam_calibdb )
set ( aaa_libs aec_shared awb_shared af_shared adpf_shared adpcc_shared a2dnr_shared a3dnr_shared awdr3_shared ahdr_shared aee_shared aflt_shared avs_shared )

set ( ctrl_libs mim_ctrl_shared mom_ctrl_shared bufsync_ctrl_shared )
set ( appl_libs cam_engine_shared )
set ( exa_libs )

#set ENABLE_EMULATOR "TRUE" or "FALSE" to enable/disable CModule support
set (ENABLE_EMULATOR FALSE)

if(ENABLE_EMULATOR)
add_definitions(-DEMULATOR)
endif(ENABLE_EMULATOR)

if (GENERATE_PARTITION_BUILD)

# add all units of the project here:
# - base modules first
add_subdirectory(ebase ${PROJECT_SUB_DIR}/ebase)
#add_subdirectory(embUnit ${PROJECT_SUB_DIR}/embUnit )
add_subdirectory(oslayer ${PROJECT_SUB_DIR}/oslayer )
# - user/project modules/apps next
add_subdirectory(version ${PROJECT_SUB_DIR}/version )
### platform_libsq
add_subdirectory( fpga  ${PROJECT_SUB_DIR}/fpga )
add_subdirectory( i2c_drv ${PROJECT_SUB_DIR}/i2c_drv )
add_subdirectory( hal ${PROJECT_SUB_DIR}/hal )
### base_libs (well, almost...)
add_subdirectory( scmi ${PROJECT_SUB_DIR}/scmi )
add_subdirectory( common ${PROJECT_SUB_DIR}/common )
add_subdirectory( bufferpool ${PROJECT_SUB_DIR}/bufferpool )
### subctrl_libs (well, almost...)
#add_subdirectory( xom_ctrl ${PROJECT_SUB_DIR}/xom_ctrl )
add_subdirectory( vom_ctrl ${PROJECT_SUB_DIR}/vom_ctrl )
add_subdirectory( som_ctrl ${PROJECT_SUB_DIR}/som_ctrl )


add_subdirectory( ibd ${PROJECT_SUB_DIR}/ibd )
#add_subdirectory( exa_ctrl ${PROJECT_SUB_DIR}/exa_ctrl )
add_subdirectory( bufsync_ctrl ${PROJECT_SUB_DIR}/bufsync_ctrl )
### drv_libs
add_subdirectory( cameric_reg_drv ${PROJECT_SUB_DIR}/cameric_reg_drv )
add_subdirectory( cameric_drv ${PROJECT_SUB_DIR}/cameric_drv )
add_subdirectory( mipi_drv ${PROJECT_SUB_DIR}/mipi_drv  )
add_subdirectory( isi ${PROJECT_SUB_DIR}/isi )
add_subdirectory( cam_calibdb ${PROJECT_SUB_DIR}/cam_calibdb )
###
add_subdirectory( aaa ${PROJECT_SUB_DIR}/aaa )
###
add_subdirectory( mim_ctrl ${PROJECT_SUB_DIR}/mim_ctrl )
add_subdirectory( mom_ctrl ${PROJECT_SUB_DIR}/mom_ctrl )
###
add_subdirectory( cim_ctrl ${PROJECT_SUB_DIR}/cim_ctrl )
###
add_subdirectory( cam_engine ${PROJECT_SUB_DIR}/cam_engine )
###

if( (NOT DEFINED APPSHELL_TOP_COMPILE) AND ANDROID )
  add_subdirectory(${UNITS_TOP_DIRECTORY}/../utils3rd/3rd/jsoncpp ${PROJECT_SUB_DIR}/jsoncpp)
endif( (NOT DEFINED APPSHELL_TOP_COMPILE) AND ANDROID )

add_subdirectory( cam_device ${PROJECT_SUB_DIR}/cam_device )

else (GENERATE_PARTITION_BUILD)
  #partition build
  add_subdirectory( isi ${PROJECT_SUB_DIR}/isi )
  add_custom_target(units ALL
    COMMENT "units accomplish partition build"
  )
  add_dependencies(units copy_shell_libs_isi)
endif (GENERATE_PARTITION_BUILD)