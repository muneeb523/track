# Copyright (c) Dean Michael Berris 2010.
# Copyright 2016 Google, Inc.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8)
project(CPP-NETLIB)

option( CPP-NETLIB_BUILD_SHARED_LIBS "Build cpp-netlib as shared libraries." ON )
option( CPP-NETLIB_BUILD_TESTS "Build the cpp-netlib project tests." OFF)
# option( CPP-NETLIB_BUILD_EXPERIMENTS "Build the cpp-netlib project experiments." ON)
option( CPP-NETLIB_BUILD_EXAMPLES "Build the cpp-netlib project examples." OFF)
option( CPP-NETLIB_ENABLE_HTTPS "Build cpp-netlib with support for https if OpenSSL is found." OFF)
option( CPP-NETLIB_STATIC_OPENSSL "Build cpp-netlib using static OpenSSL" OFF)
option( CPP-NETLIB_STATIC_BOOST "Build cpp-netlib using static Boost" OFF)

include(GNUInstallDirs)

if(NOT CMAKE_INSTALL_LIBDIR)
	set(CMAKE_INSTALL_LIBDIR "/usr/lib")
endif()

# determine install path for CMake config files
if(WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else()
    set(DEF_INSTALL_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/cppnetlib)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative cmake install path absolute (needed later on)
if(NOT IS_ABSOLUTE "${INSTALL_CMAKE_DIR}")
    set(INSTALL_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/${INSTALL_CMAKE_DIR}")
endif()

if(CPP-NETLIB_BUILD_SHARED_LIBS OR BUILD_SHARED_LIBS)
  message (STATUS "Linking boost testing libs dynamically...")
  set(CPP-NETLIB_BUILD_SHARED_LIBS ON)
  set(BUILD_SHARED_LIBS ON)
else()
  set(CPP-NETLIB_BUILD_SHARED_LIBS OFF)
  set(BUILD_SHARED_LIBS OFF)
endif()

# Use Boost's static libraries
if (CPP-NETLIB_STATIC_BOOST)
  set(Boost_USE_STATIC_LIBS ON)
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "debug")
  set(Boost_USE_DEBUG_LIBS ON)
elseif (${CMAKE_BUILD_TYPE} STREQUAL "release")
  set(Boost_USE_RELEASE_LIBS ON)
endif()

# We need this for all tests to use the dynamic version.
add_definitions(-DBOOST_TEST_DYN_LINK)

# Always use multi-threaded Boost libraries.
set(Boost_USE_MULTI_THREADED ON)

find_package(Boost 1.58.0 REQUIRED COMPONENTS system thread)

if (CPP-NETLIB_ENABLE_HTTPS)
 if (APPLE)
   # If we're on OS X check for Homebrew's copy of OpenSSL instead of Apple's
   if (NOT OpenSSL_DIR)
     find_program(HOMEBREW brew)
     if (HOMEBREW STREQUAL "HOMEBREW-NOTFOUND")
       message(WARNING "Homebrew not found: not using Homebrew's OpenSSL")
       if (NOT OPENSSL_ROOT_DIR)
         message(WARNING "Use -DOPENSSL_ROOT_DIR for non-Apple OpenSSL")
       endif()
     else()
       execute_process(COMMAND brew --prefix openssl
         OUTPUT_VARIABLE OPENSSL_ROOT_DIR
         OUTPUT_STRIP_TRAILING_WHITESPACE)
     endif()
   endif()
 endif()
 if (CPP-NETLIB_STATIC_OPENSSL)
   set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
 endif()
 find_package(OpenSSL)
endif()

find_package( Threads )
set(CMAKE_VERBOSE_MAKEFILE true)

set(CPPNETLIB_VERSION_MAJOR 0) # MUST bump this whenever we make ABI-incompatible changes
set(CPPNETLIB_VERSION_MINOR 13)
set(CPPNETLIB_VERSION_PATCH 0)
set(CPPNETLIB_VERSION_STRING ${CPPNETLIB_VERSION_MAJOR}.${CPPNETLIB_VERSION_MINOR}.${CPPNETLIB_VERSION_PATCH})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DBOOST_NETWORK_DEBUG)
endif()

if (OPENSSL_FOUND)
    add_definitions(-DBOOST_NETWORK_ENABLE_HTTPS)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

if (${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
  # Use C++11 when using GNU compilers.
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  # We want to link in C++11 mode in Clang too, but also set a high enough
  # template depth for the template metaprogramming.
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ftemplate-depth=256 -std=c++11")
  if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Use libc++ only in OS X.
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++")
  endif()
endif()


if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    set(gtest_force_shared_crt true)
endif()

if (Boost_FOUND)
    if (MSVC)
      add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    endif(MSVC)
    if (WIN32)
      add_definitions(-D_WIN32_WINNT=0x0501)
    endif(WIN32)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})

    enable_testing()
    add_subdirectory(libs/network/src)
    if (CPP-NETLIB_BUILD_TESTS)
      add_subdirectory(deps/googletest)
      add_subdirectory(libs/network/test)
    endif (CPP-NETLIB_BUILD_TESTS)
    if (CPP-NETLIB_BUILD_EXAMPLES)
      add_subdirectory(libs/network/example)
    endif (CPP-NETLIB_BUILD_EXAMPLES)
endif(Boost_FOUND)

enable_testing()

set(CPP-NETLIB_LIBRARIES ${Boost_LIBRARIES} CACHE INTERNAL "Dependent libraries for header-only use")

install(DIRECTORY boost DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

###
## Export Targets
# (so cpp-netlib can be easily used by other CMake projects)
# [see http://www.cmake.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file]

# Add all targets to the build-tree export set
export(TARGETS cppnetlib-client-connections cppnetlib-server-parsers cppnetlib-uri
    FILE "${PROJECT_BINARY_DIR}/cppnetlibTargets.cmake")
# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE cppnetlib)
# Create the cppnetlibConfig.cmake and cppnetlibConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
    "${CMAKE_INSTALL_FULL_INCLUDEDIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" ${Boost_INCLUDE_DIRS})
configure_file(cppnetlibConfig.cmake.in
    "${PROJECT_BINARY_DIR}/cppnetlibConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${CPPNETLIB_CMAKE_DIR}/${REL_INCLUDE_DIR}")
set(CONF_INCLUDE_DIRS ${CONF_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
configure_file(cppnetlibConfig.cmake.in
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/cppnetlibConfig.cmake" @ONLY)
# ... for both
configure_file(cppnetlibConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/cppnetlibConfigVersion.cmake" @ONLY)
# Install the cppnetlibConfig.cmake and cppnetlibConfigVersion.cmake
install(FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/cppnetlibConfig.cmake"
    "${PROJECT_BINARY_DIR}/cppnetlibConfigVersion.cmake"
    DESTINATION "${INSTALL_CMAKE_DIR}"
    COMPONENT dev)
# Install the export set for use with the install-tree
install(EXPORT cppnetlibTargets
    DESTINATION "${INSTALL_CMAKE_DIR}"
    COMPONENT dev)
