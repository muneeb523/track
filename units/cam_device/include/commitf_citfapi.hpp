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
#include "commitf_citf.hpp"
#include "calib_features.hpp"
#include "commitf_features.hpp"
#include "commitf_pipeline.hpp"
#include "commitf_sensor.hpp"
#include "commitf_event.hpp"
#include "cam_operations.hpp"
#include "buf_io.hpp"

using namespace camdev;
#include <vector>

namespace camdev {


class CitfApi {
public:
    CitfApi(int ispID);
    ~CitfApi();

    Citf_Handle ctifHandle;

    static RESULT CitfGetHwResources(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetHwStatus(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetIspFeature(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetFeatureVersion(Json::Value &jRequest, Json::Value &jResponse);
    static RESULT CitfGetVersions(Json::Value &jRequest, Json::Value &jResponse);

    RESULT CitfGetSensorInfo(Json::Value &jRequest, Json::Value &jResopnse);
    RESULT CitfIoctl(int32_t ctrlId, Json::Value &jRequest, Json::Value &jResponse);

    Bitf &CitfCreateBuffItf();
    RESULT CitfDelBuffItf();
    CitfEvent &CitfCreateEvent();
    RESULT CitfDelEvent();

    /*output buffer controls*/
    RESULT CitfInitOutChain(ISPCORE_BUFIO_ID chain, uint8_t skip_interval);
    RESULT CitfDeinitOutChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfStartOutChain(ISPCORE_BUFIO_ID chain);
    RESULT CitfStopOutChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfAttachChain(ISPCORE_BUFIO_ID chain);
    RESULT CitfDetachChain(ISPCORE_BUFIO_ID chain);

    RESULT CitfWaitForBufferEvent(ISPCORE_BUFIO_ID chain, buffCtrlEvent_t * xomCtrlEvent, int timeout);

    RESULT CitfDQBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t ** pBuf);
    RESULT CitfQBUF(ISPCORE_BUFIO_ID chain, MediaBuffer_t * pBuf);

    RESULT CitfInitBufferPoolCtrl(ISPCORE_BUFIO_ID chain);
    RESULT CitfDeInitBufferPoolCtrl(ISPCORE_BUFIO_ID chain);

    RESULT CitfSetBufferParameters(BUFF_MODE buff_mode);
    RESULT CitfBufferPoolAddEntity(ISPCORE_BUFIO_ID chain, BufIdentity* buf);

    RESULT CitfBufferPoolClearBufList(ISPCORE_BUFIO_ID chain);
    RESULT CitfBufferPoolSetBufToEngine(ISPCORE_BUFIO_ID chain);

    RESULT CitfBufferPoolKernelAddrMap(ISPCORE_BUFIO_ID chain, uint32_t needRemap);
    RESULT CitfBufferPoolGetBufIdList(ISPCORE_BUFIO_ID chain, std::list<BufIdentity *> * poolList);

public:
    std::vector<Citf *> list;
    Bitf * pBitf = nullptr;
    CitfEvent * pEvent = nullptr;

};

} // namespace camdev
