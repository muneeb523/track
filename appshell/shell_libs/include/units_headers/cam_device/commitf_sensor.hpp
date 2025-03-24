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

#include "commitf_citf.hpp"

namespace camdev {

class CitfSensor : public Citf {
public:
    CitfSensor(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
        subId_Begin = ISPCORE_MODULE_SENSOR_BEGIN;
        subId_End = ISPCORE_MODULE_SENSOR_END;
    }

    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;

    RESULT caps(Json::Value &jRequest, Json::Value &jResponse);
    RESULT configGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT configSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT nameGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT revisionGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT sensorOpen(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isConnected(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isTestPattern(Json::Value &jRequest, Json::Value &jResponse);
    RESULT driverChange(Json::Value &jRequest, Json::Value &jResponse);
    RESULT driverList(Json::Value &jRequest, Json::Value &jResponse);
    RESULT info(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionListGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT isiGetResolutionName(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerDescription(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerDump2File(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT registerTable(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSetSensor(Json::Value &jRequest, Json::Value &jResponse);
    RESULT testPatternSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSupportListGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT frameRateGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT frameRateSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT modeGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT modeSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resWGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resHGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT queryCaps(Json::Value &jRequest, Json::Value &jResponse);
    RESULT setCapsMode(Json::Value &jRequest, Json::Value &jResponse);
    RESULT setCapsModeLock(Json::Value &jRequest, Json::Value &jResponse);
    RESULT getStartExposureConfig(Json::Value &jRequest, Json::Value &jResponse);
    RESULT setStartExposureConfig(Json::Value &jRequest, Json::Value &jResponse);
};

} // namespace camdev
