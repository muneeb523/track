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

#pragma once

#include "cam_device_api.hpp"
#include <common/return_codes.h>
#include <oslayer/oslayer.h>
#include <string>


#include <sys/stat.h>
#include <ebase/trace.h>
#include <hal/hal_api.h>

namespace fs {

inline bool isExists(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

}

USE_TRACER(CITF_INF);
USE_TRACER(CITF_WAN);
USE_TRACER(CITF_ERR);
#define TRACE_IN TRACE(CITF_INF, "%s (enter)\n", __PRETTY_FUNCTION__)
#define TRACE_OUT TRACE(CITF_INF, "%s (exit)\n", __PRETTY_FUNCTION__)


#define ISP_MAX 2
#define ISP_INPUT_MAX 4

#define CTRL_2DNR
#define CTRL_3DNR1
#define CTRL_AVS
#define CTRL_CAC
#define CTRL_CNR
#define CTRL_DEMOSAIC
#define CTRL_EE
#define CTRL_GC
#define CTRL_HDR
#define CTRL_LSC
#define CTRL_SI
#define CTRL_WDR2
#define CTRL_WDR3


/* BufferCallback functions */
struct ItfBufferCb {
    virtual void bufferCb(MediaBuffer_t *) = 0;
#ifdef ANDROID
    virtual ~ItfBufferCb() {}
#endif
};


struct Ctrl : CamStatus {
    Ctrl();
    virtual ~Ctrl();

    virtual int32_t start(void *) = 0;
    virtual int32_t stop() = 0;

    osEvent eventStarted;
    osEvent eventStopped;
};


class HalHolder {
public:
    HalHolder(int ispID);
    ~HalHolder();

public:
    HalHandle_t hHal = NULL;
};

