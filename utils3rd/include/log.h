/****************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020-2024 VeriSilicon Holdings Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/

#ifndef _VSI_3RDLIBS_INCLUDE_LOG_H_
#define _VSI_3RDLIBS_INCLUDE_LOG_H_

#include <stdio.h>
#include <stdlib.h>

enum {
    ISP_LOG_LEVEL_NONE = 0, //No debug information is output.
    ISP_LOG_LEVEL_ERROR ,   //Logs all fatal errors.
    ISP_LOG_LEVEL_WARNING,  //Logs all warnings.
    ISP_LOG_LEVEL_FIXME,    //Logs all "fixme" messages. (Reserved)
    ISP_LOG_LEVEL_INFO,     //Logs all informational messages.
    ISP_LOG_LEVEL_DEBUG,    //Logs all debug messages.
    ISP_LOG_LEVEL_LOG,      //Logs all log messages.     (Reserved)
    ISP_LOG_LEVEL_TRACE,    //Logs all trace messages.   (Reserved)
    ISP_LOG_LEVEL_VERBOSE,  //Logs all level messages.
};

inline int isp_log_level() {
    char* szLogLevel = getenv("ISP_LOG_LEVEL");
    if (szLogLevel)
        return atoi(szLogLevel);
    else
        return ISP_LOG_LEVEL_WARNING;
}

// c++11 workaround empty variadic macro
#define __ALOG_INT(format, ...) "[%s] " format "\033[0m%s", LOGTAG, __VA_ARGS__

#ifdef ANDROID

#include <android/log.h>
#define ISP_INFO "VSI_ISP"

#define ALOGV(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_VERBOSE) __android_log_print(ANDROID_LOG_INFO, ISP_INFO, "\033[1;30;37mVERBOSE : " __ALOG_INT(__VA_ARGS__, "\n"))  // white

#define ALOGD(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_DEBUG) __android_log_print(ANDROID_LOG_INFO, ISP_INFO, "\033[1;30;37mDEBUG  : " __ALOG_INT(__VA_ARGS__, "\n"))  // white

#define ALOGI(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_INFO) __android_log_print(ANDROID_LOG_INFO, ISP_INFO, "\033[1;30;32mINFO   : " __ALOG_INT(__VA_ARGS__, "\n"))  // green

#define ALOGW(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_WARNING) __android_log_print(ANDROID_LOG_INFO, ISP_INFO, "\033[1;30;33mWARN   : " __ALOG_INT(__VA_ARGS__, "\n"))  // yellow

#define ALOGE(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_ERROR) __android_log_print(ANDROID_LOG_INFO, ISP_INFO, "\033[1;30;31mERROR  : " __ALOG_INT(__VA_ARGS__, "\n"))  // red

#else

#define ALOGV(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_VERBOSE) printf("\033[1;30;37mVERBOSE : " __ALOG_INT(__VA_ARGS__, "\n"))  // white

#define ALOGD(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_DEBUG) printf("\033[1;30;37mDEBUG  : " __ALOG_INT(__VA_ARGS__, "\n"))  // white

#define ALOGI(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_INFO) printf("\033[1;30;32mINFO   : " __ALOG_INT(__VA_ARGS__, "\n"))  // green

#define ALOGW(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_WARNING) printf("\033[1;30;33mWARN   : " __ALOG_INT(__VA_ARGS__, "\n"))  // yellow

#define ALOGE(...)\
    if (isp_log_level() >= ISP_LOG_LEVEL_ERROR) printf("\033[1;30;31mERROR  : " __ALOG_INT(__VA_ARGS__, "\n"))  // red

#endif

//#define TRACE_IN  ALOGI("enter %s", __PRETTY_FUNCTION__)
//#define TRACE_OUT ALOGI("leave %s", __PRETTY_FUNCTION__)

#endif  // _VSI_3RDLIBS_INCLUDE_LOG_H_
