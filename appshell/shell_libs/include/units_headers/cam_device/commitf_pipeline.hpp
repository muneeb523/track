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

class CitfPipeline : public Citf {
public:
    CitfPipeline(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
        subId_Begin = ISPCORE_MODULE_PIPELINE_BEGIN;
        subId_End = ISPCORE_MODULE_PIPELINE_END;
    }

    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;
    RESULT warmUp(Json::Value &jRequest, Json::Value &jResponse);
    RESULT lock3ASet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT lock3AGet(Json::Value &jRequest, Json::Value &jResponse);
};

} // namespace camdev
