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
project(ISP_APP_SHELL)

if(DEFINED QTLESS)
    if(${QTLESS} STREQUAL 0)
        set (QTLESS 0)
    else(${QTLESS} STREQUAL 0)
        set (QTLESS 1)
    endif(${QTLESS} STREQUAL 0)
else(DEFINED QTLESS)
    #default value of QTLESS
set (QTLESS 0)
endif(DEFINED QTLESS)

if(DEFINED TUNINGEXT)
    if(${TUNINGEXT} STREQUAL 0)
        set (TUNINGEXT 0)
    else(${TUNINGEXT} STREQUAL 0)
        set (TUNINGEXT 1)
    endif(${TUNINGEXT} STREQUAL 0)
else(DEFINED TUNINGEXT)
    #default value of TUNINGEXT
set (TUNINGEXT 0)
endif(DEFINED TUNINGEXT)

if(DEFINED FULL_SRC_COMPILE)
    if(${FULL_SRC_COMPILE} STREQUAL 0)
        set (FULL_SRC_COMPILE 0)
    else(${FULL_SRC_COMPILE} STREQUAL 0)
    set (FULL_SRC_COMPILE 1)
    endif(${FULL_SRC_COMPILE} STREQUAL 0)
else(DEFINED FULL_SRC_COMPILE)
    #default value of FULL_SRC_COMPILE
    set (FULL_SRC_COMPILE 0)
endif(DEFINED FULL_SRC_COMPILE)

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

if(DEFINED WITH_DRM)
    if(${WITH_DRM} STREQUAL 0)
        set (WITH_DRM 0)
    else(${WITH_DRM} STREQUAL 0)
        set (WITH_DRM 1)
    endif(${WITH_DRM} STREQUAL 0)
else(DEFINED WITH_DRM)
    #default value of WITH_DRM
    set (WITH_DRM 0)
endif(DEFINED WITH_DRM)

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    message("-DCMAKE_INSTALL_PREFIX=... missing from cmake call, use default /usr")
    set (CMAKE_INSTALL_PREFIX "/usr")
else(NOT DEFINED CMAKE_INSTALL_PREFIX)
    if (NOT CMAKE_INSTALL_PREFIX)
        set (CMAKE_INSTALL_PREFIX "/usr")
    endif (NOT CMAKE_INSTALL_PREFIX)
    message("-DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
endif(NOT DEFINED CMAKE_INSTALL_PREFIX)

# toolchain header file include path
if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    message("-DCMAKE_INSTALL_INCLUDEDIR=... missing from cmake call, use default include")
    set (CMAKE_INSTALL_INCLUDEDIR "include")
else(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
    if (NOT CMAKE_INSTALL_INCLUDEDIR)
        set (CMAKE_INSTALL_INCLUDEDIR "include")
    endif (NOT CMAKE_INSTALL_INCLUDEDIR)
    message("-DCMAKE_INSTALL_INCLUDEDIR=${CMAKE_INSTALL_INCLUDEDIR}")
endif(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)

set (TOOLCHAIN_INCLUDE_DIR "${SDKTARGETSYSROOT}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
message("TOOLCHAIN_INCLUDE_DIR=${TOOLCHAIN_INCLUDE_DIR}")

##default path of drm header path
if (NOT ${WITH_DRM} STREQUAL 0 )
    if(NOT DEFINED SDKTARGETSYSROOT)
        message(FATAL_ERROR "-DSDKTARGETSYSROOT=... missing from cmake call")
    endif()
    set (DRM_HEADER_PATH ${TOOLCHAIN_INCLUDE_DIR}/drm/)
endif(NOT ${WITH_DRM} STREQUAL 0)

# toolchain lib path
if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    message("-DCMAKE_INSTALL_LIBDIR=... missing from cmake call, use default lib")
    set (CMAKE_INSTALL_LIBDIR "lib")
else(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    if (NOT CMAKE_INSTALL_LIBDIR)
        set (CMAKE_INSTALL_LIBDIR "lib")
    endif (NOT CMAKE_INSTALL_LIBDIR)
    message("-DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}")
endif(NOT DEFINED CMAKE_INSTALL_LIBDIR)

set (TOOLCHAIN_LIB_DIR "${SDKTARGETSYSROOT}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
message("TOOLCHAIN_LIB_DIR=${TOOLCHAIN_LIB_DIR}")

set (APPSHELL_TOP_COMPILE 1)
set (SENSOR ON)

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

set (V4L2 1)
add_definitions(-DSUPPORT_PASS_JSON)

message("## Full source compile, ISP_VERSION input: ${ISP_VERSION}")
#set (PROJECT_CFG_FILE product_cfg_${ISP_VERSION}.cmake)
if(${ISP_VERSION} STREQUAL ISP8000NANO)
message("##NANO CFG")
add_definitions(-DISP8000NANO)
set (PROJECT_CFG_FILE product_cfg_ISP8000NANO.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000NANO_V1801)
message("##NANO_V1801 CFG")
add_definitions(-DISP8000NANO_V1801)
set (PROJECT_CFG_FILE product_cfg_ISP8000NANO_V1801.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000NANO_V1802)
message("##NANO_V1802 CFG")
add_definitions(-DISP8000NANO_V1802)
set (PROJECT_CFG_FILE product_cfg_ISP8000NANO_V1802.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L)
message("##8000L CFG")
add_definitions(-DISP8000L)
set (PROJECT_CFG_FILE product_cfg_ISP8000L.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V1801)
message("##8000L_V1801 CFG")
add_definitions(-DISP8000L_V1801)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V1801.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V1901)
message("##8000L_V1901 CFG")
add_definitions(-DISP8000L_V1901)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V1901.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V1902)
message("##8000L_V1902 CFG")
add_definitions(-DISP8000L_V1902)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V1902.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000)
message("##8000 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000_V01)
set (PROJECT_CFG_FILE product_cfg_ISP8000.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000_V1901)
message("##8000_V1901 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000_V1901)
set (PROJECT_CFG_FILE product_cfg_ISP8000_V1901.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000_V2003)
message("##8000_V2003 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000_V2003)
set (PROJECT_CFG_FILE product_cfg_ISP8000_V2003.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V2001)
message("##8000L_V2001 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000L_V2001)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V2001.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V2002)
message("##8000L_V2002 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000L_V2002)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V2002.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V2006)
message("##8000L_V2006 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000L_V2006)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V2006.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V1903)
message("##8000L_V1903 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000L_V1903)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V1903.cmake)

elseif(${ISP_VERSION} STREQUAL ISP8000L_V1905)
message("##8000L_V1905 CFG")
add_definitions(-DISP8000BASE)
add_definitions(-DISP8000L_V1905)
set (PROJECT_CFG_FILE product_cfg_ISP8000L_V1905.cmake)
else(${ISP_VERSION} STREQUAL ISP8000NANO)

message(FATAL_ERROR "CFG_ERROR ISP_VERSION=${ISP_VERSION} error, can not found version settings, exit")

endif(${ISP_VERSION} STREQUAL ISP8000NANO)

message("## ISP_VERSION configure setting: ${ISP_VERSION}")

set (PROJECT_CFG_DIR ${CMAKE_HOME_DIRECTORY}/../units/mkrel)
include(${PROJECT_CFG_DIR}/${ISP_VERSION}/${PROJECT_CFG_FILE})

#HW configuration end
#########################################################


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -fPIC")
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

message(STATUS "=============================================================================")
set(PROJ_DESC "ISP app shell for test app and UIs")

message(STATUS "Project description: " ${PROJ_DESC})

set(PROJECT_SUB_DIR "${PROJECT_BINARY_DIR}/obj")
message(STATUS "project bin:" ${PROJECT_BINARY_DIR})
message(STATUS "project obj dir:" ${PROJECT_SUB_DIR})
message(STATUS "project src:" ${PROJECT_SOURCE_DIR})
message(STATUS "Cmake root dor:" ${CMAKE_HOME_DIRECTORY})

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

if ( ANDROID )
    MESSAGE("system: ANDROID")
    add_definitions(-DANDROID)
    set(LIB_PTHREAD_NAME "")
    set(LIB_RT_NAME "")
    set(LIB_LOG_NAME "log")
    set(JSONCPP_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/../utils3rd/3rd/jsoncpp/include")
else ()
    set(LIB_PTHREAD_NAME "pthread")
    set(LIB_RT_NAME "rt")
    set(LIB_LOG_NAME "")
    set(JSONCPP_INCLUDE_DIR "${TOOLCHAIN_INCLUDE_DIR}/json")
endif ( ANDROID )
message ("JSONCPP_INCLUDE_DIR is at: ${JSONCPP_INCLUDE_DIR}")

#include global rules valid for the whole project:
include (globals.cmake)

include_directories(
    ../utils3rd/include/
    ../units/cam_device/include
    ../vvcam/common
    ${JSONCPP_INCLUDE_DIR}
)

add_custom_target(top_clobber
                  COMMAND ${CMAKE_COMMAND} -E remove_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}
                  COMMENT "Delete ${LIB_ROOT}/${CMAKE_BUILD_TYPE}")

add_custom_target(top_create_dir
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/include
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/${ISP_VERSION}
                  COMMENT "Create directory ${LIB_ROOT}")

add_custom_target(top_create_alldir
                   COMMENT "Create all modules' include directories")

if ( UNIX )
    add_custom_target(top_strip
                      COMMAND strip --strip-all "${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin/*"
                      COMMENT "Stripping all files in ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin")
    add_custom_target(top_ctags
                      COMMAND ctags -R -f../tags --tag-relative=no  --totals=no  --exclude=.svn --exclude=../debug --exclude=../release --exclude=../build --exclude=${CMAKE_BUILD_TYPE} ..
                      COMMAND ctags -R -f./tags  --tag-relative=yes --totals=yes --exclude=.svn --exclude=../debug --exclude=../release --exclude=../build --exclude=${CMAKE_BUILD_TYPE} ..
                      COMMENT "Creating ctags file for all modules")
endif ( UNIX )

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

if (IMX_G2D)
add_definitions(-DIMX_G2D)
endif()

# add all units of the project here:
# - base modules first
add_subdirectory(yuv ${PROJECT_SUB_DIR}/yuv)
add_subdirectory(display ${PROJECT_SUB_DIR}/display)

message("Using full source compile")
if (ANDROID)
add_subdirectory(${PROJECT_SOURCE_DIR}/../utils3rd/3rd/jsoncpp ${PROJECT_SUB_DIR}/jsoncpp)
set (units_libs jsoncpp_lib cam_device_shared)
else (ANDROID)
set (units_libs ${TOOLCHAIN_LIB_DIR}/libjsoncpp.so cam_device_shared)
endif (ANDROID)

if(${GENERATE_PARTITION_BUILD} STREQUAL 0)
    add_custom_target(copy_units_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/shell_libs/include/units_headers ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/include
        COMMENT "Copy units headers to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/include"
        DEPENDS top_create_dir
    )
endif(${GENERATE_PARTITION_BUILD} STREQUAL 0)

add_subdirectory( ${PROJECT_SOURCE_DIR}/../units ${PROJECT_SUB_DIR}/units )
if(${GENERATE_PARTITION_BUILD} STREQUAL 0)
    add_custom_target(copy_units ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/shell_libs/ispcore/${PLATFORM} ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
        COMMENT "Copy units lib to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib"
        DEPENDS units
    )
endif(${GENERATE_PARTITION_BUILD} STREQUAL 0)

if (SUBDEV_V4L2)
    if(${GENERATE_PARTITION_BUILD} STREQUAL 1)
        add_subdirectory( ${PROJECT_SOURCE_DIR}/../mediacontrol ${PROJECT_SUB_DIR}/mediacontrol )
    else(${GENERATE_PARTITION_BUILD} STREQUAL 1)
        add_custom_target(copy_mediacontrol ALL
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/../mediacontrol/install/lib ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
            COMMENT "Copy mediacontrol lib to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/../mediacontrol/install/bin ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin
            COMMENT "Copy mediacontrol bin to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin"
            DEPENDS units
        )

        if(WITH_DWE)
            add_custom_target(copy_dewarp ALL
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/../dewarp/proprietories/hal/lib ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/../dewarp/proprietories/parser/lib ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib
                COMMENT "Copy dewarp lib to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/lib"
                DEPENDS units
            )
        endif(WITH_DWE)
    endif(${GENERATE_PARTITION_BUILD} STREQUAL 1)
endif(SUBDEV_V4L2)

if (SUBDEV_CHAR)
add_definitions(-DSUBDEV_CHAR)
endif()

if (SUBDEV_V4L2)
add_definitions(-DSUBDEV_V4L2)
endif()

if(${TUNINGEXT} STREQUAL 1)
    #tunningext
    if(${GENERATE_PARTITION_BUILD} STREQUAL 1)
        add_subdirectory( ../tuningext ${PROJECT_SUB_DIR}/tuningext )
    else(${GENERATE_PARTITION_BUILD} STREQUAL 1)
        add_custom_target(copy_tuningext ALL
            COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/../tuningext/install/tuningext ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin
            COMMENT "Copy tuningext to ${LIB_ROOT}/${CMAKE_BUILD_TYPE}/bin")
        add_dependencies(copy_tuningext top_create_dir)
    endif(${GENERATE_PARTITION_BUILD} STREQUAL 1)

    add_subdirectory(${PROJECT_SOURCE_DIR}/../utils3rd/3rd/cpp-netlib ${PROJECT_SUB_DIR}/cpp-netlib)
endif(${TUNINGEXT} STREQUAL 1)

#    if(NOT ANDROID)
add_subdirectory( v4l_drm_test ${PROJECT_SUB_DIR}/v4l_drm_test )
#    endif(NOT ANDROID)
add_subdirectory( vvext ${PROJECT_SUB_DIR}/vvext )