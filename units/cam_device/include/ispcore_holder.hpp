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
#include "cam_common.hpp"

#include "cam_device_api.hpp"
#include "commitf_citfapi.hpp"


namespace camdev {

class Ispcore_Holder {
    struct IspCoreCtx {
        CitfApi * ctx;
        CAM_DEVICE * handle;
    };

public:
    static Ispcore_Holder * getInstance() {
        static Ispcore_Holder instance;
        return &instance;
    }

    IspCoreCtx ispcore[CAM_ISPCORE_ID_MAX];

protected:
    struct Inst_Creator {
        Inst_Creator() {
            Ispcore_Holder::getInstance();
        }
    };

    static Inst_Creator inst_creator;

    Ispcore_Holder();
    ~Ispcore_Holder();
};

}  // namespace camdev



