cmake_minimum_required(VERSION 2.6)

project(ISP_V4L_DRM_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-Wall)
add_definitions(-fPIC)
add_definitions(-DPRINT_LOG)
add_definitions(-DISP_VIDEO_TEST)

include_directories(
    ../../vvcam/common
    ../../units/cam_device/include
    ../../utils3rd/include
    ../../mediacontrol/include_api
    ../../units/cam_device/utils/base64
    ${JSONCPP_INCLUDE_DIR}
)
file(GLOB pub_headers *.h )

add_executable(vvext
    vvext.cpp
    ../../units/cam_device/utils/base64/base64.cpp
)

if (NOT ANDROID)
    target_link_libraries (vvext ${LIB_PTHREAD_NAME} ${TOOLCHAIN_LIB_DIR}/libjsoncpp.so ${LIB_LOG_NAME})
else (NOT ANDROID)
    target_link_libraries (vvext ${LIB_PTHREAD_NAME} jsoncpp_lib ${LIB_LOG_NAME})
endif (NOT ANDROID)
