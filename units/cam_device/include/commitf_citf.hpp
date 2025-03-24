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

#include "cam_operations.hpp"
#include "exception.hpp"
#include "macros.hpp"
#include <base64/base64.hpp>
#include <json/json.h>


#define CITF_CID "cmdId"
#define CITF_MID "moduleId"
#define CITF_RET "result"
#define CITF_MSG "message"
#define ERR_CTRLID "errctrlId"
#define JSON_STR_BUF_LENGTH 64

#ifdef TRACE_CMD
#undef TRACE_CMD
#endif

#define TRACE_CMD TRACE(CITF_INF, " %s\n", __PRETTY_FUNCTION__)
USE_TRACER(CITF_INF);
USE_TRACER(CITF_ERR);
namespace camdev {

struct Citf_Handle{
    HalHolder *pHalHolder = nullptr;
    Calibration *pCalibration = nullptr;
    Operation *pOperation = nullptr;
};


class Citf {
public:
    Citf(Citf_Handle * pCitfHandle_in);
    virtual ~Citf();

public:
    Citf_Handle * pCitfHandle = nullptr;
    std::string calibrationFile;

    template <typename T> RESULT binDecode(Json::Value &jValue, T &object) {
        uint32_t sizeT = sizeof(T);
        uint32_t size = jValue[CITF_SIZE_PARAMS].asUInt();

        if (sizeT != size) {
            std::string message("T size(%d) != size(%d)", sizeT, size);
            throw exc::LogicError(RET_INVALID_PARM, message.c_str());
            return RET_INVALID_PARM;
        }

        std::string decodedString = base64_decode(jValue[CITF_BIN_PARAMS].asString());
        std::copy(decodedString.begin(), decodedString.end(), (char *)&object);

        return RET_SUCCESS;
    }

    template <typename T> RESULT binEncode(T &object, Json::Value &jValue) {
        uint32_t size = sizeof(T);

        jValue[CITF_SIZE_PARAMS] = size;
        jValue[CITF_BIN_PARAMS] = base64_encode((u_char *)&object, size);

        return RET_SUCCESS;
    }

    virtual RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse);
    virtual RESULT getModuleVersion(Json::Value &jRequest, Json::Value &jResponse);

    RESULT setSubId(int32_t inputId_Begin, int32_t inputId_End);
    RESULT checkIsSubId(int32_t inputId);

    camdev::SensorOps &sensor();

public:
    int32_t subId_Begin;
    int32_t subId_End;

    int32_t idBegin;
    int32_t idEnd;
};

} // namespace camdev
