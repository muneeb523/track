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

#include <cameric_reg_drv/cameric_reg_description.h>

#include <cam_engine/cam_engine_api.h>

#include <cam_engine/cam_engine_aaa_api.h>
#include <cam_engine/cam_engine_cproc_api.h>
#include <cam_engine/cam_engine_imgeffects_api.h>
#include <cam_engine/cam_engine_isp_api.h>
#include <cam_engine/cam_engine_jpe_api.h>
#include <cam_engine/cam_engine_mi_api.h>
#include <cam_engine/cam_engine_simp_api.h>

#include "commitf_citf.hpp"
#include <json/json.h>
#include "cam_device_api.hpp"

#define DECLARE_SUB_DEVICE_OPS\
    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;\
    RESULT configGet(Json::Value &jRequest, Json::Value &jResponse);\
    RESULT configSet(Json::Value &jRequest, Json::Value &jResponse);\
    RESULT enableGet(Json::Value &jRequest, Json::Value &jResponse);\
    RESULT enableSet(Json::Value &jRequest, Json::Value &jResponse)\

namespace camdev {

class CitfDevice : virtual public Citf {
public:
    CitfDevice(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
      subId_Begin = ISPCORE_MODULE_DEVICE_BEGIN;
      subId_End   = ISPCORE_MODULE_DEVICE_END;
    }

    ~CitfDevice() {
        if(pCitfHandle->pOperation != nullptr) {
          delete pCitfHandle->pOperation;
        }

        if(pCitfHandle->pCalibration != nullptr) {
          delete pCitfHandle->pCalibration;
        }
    }

    Json::Value jModuledata;
    bool ispCfg = false;

    RESULT process( int ctrlId, Json::Value &jRequest, Json::Value &jResponse) override;
    RESULT calibrationSave(Json::Value &jRequest, Json::Value &jResponse);
    RESULT calibrationLoadandInit(Json::Value &jRequest, Json::Value &jResponse);
    RESULT calibrationLoad(Json::Value &jRequest, Json::Value &jResponse);
    RESULT initEngineOperation(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSetsSensorAndIsp(Json::Value &jRequest, Json::Value &jResponse);
    RESULT cameraConnect(Json::Value &jRequest, Json::Value &jResponse);
    RESULT cameraDisconnect(Json::Value &jRequest, Json::Value &jResponse);
    RESULT captureDma(Json::Value &jRequest, Json::Value &jResponse);
    RESULT captureSensor(Json::Value &jRequest, Json::Value &jResponse);

    RESULT inputInfo(Json::Value &jRequest, Json::Value &jResponse);
    RESULT inputSwitch(Json::Value &jRequest, Json::Value &jResponse);

    RESULT preview(Json::Value &jRequest, Json::Value &jResponse);

    RESULT bitstreamId(Json::Value &jRequest, Json::Value &jResponse);
    RESULT camerIcId(Json::Value &jRequest, Json::Value &jResponse);
    RESULT inputConnect(Json::Value &jRequest, Json::Value &jResponse);
    RESULT inputDisconnect(Json::Value &jRequest, Json::Value &jResponse);
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT resolutionSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT streamingStart(Json::Value &jRequest, Json::Value &jResponse);
    RESULT streamingStop(Json::Value &jRequest, Json::Value &jResponse);
    RESULT streamingStandby(Json::Value &jRequest, Json::Value &jResponse);

    RESULT cameraReset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT previewStart(Json::Value &jRequest, Json::Value &jResponse);
    RESULT previewStop(Json::Value &jRequest, Json::Value &jResponse);
    RESULT getHalHandle(Json::Value &jRequest, Json::Value &jResponse);
    RESULT getMetadata(Json::Value &jRequest, Json::Value &jResponse);

    RESULT getModuledata(Json::Value &jRequest, Json::Value &jResponse);
    RESULT parseModuledata(Json::Value &jRequest, Json::Value &jResponse);
private:
    RESULT setModuledata();
};

class CitfAe : virtual public Citf {
public:
    CitfAe(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
      subId_Begin = ISPCORE_MODULE_AE_BEGIN;
      subId_End = ISPCORE_MODULE_AE_END;
    }

    DECLARE_SUB_DEVICE_OPS;
    RESULT ecmGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT ecmSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT sensitivityGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT sensitivitySet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT measWinSet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfAwb : virtual public Citf {
public:
    CitfAwb(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_AWB_BEGIN;
      subId_End = ISPCORE_MODULE_AWB_END;
    };
    DECLARE_SUB_DEVICE_OPS;
    RESULT illuminanceProfilesGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT measWinSet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT convergenceGet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfWb : virtual public Citf {
public:
    CitfWb(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_WB_BEGIN;
      subId_End = ISPCORE_MODULE_WB_END;
    }
    DECLARE_SUB_DEVICE_OPS;
};

class CitfAf : virtual public Citf {
public:
    CitfAf(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_AF_BEGIN;
      subId_End = ISPCORE_MODULE_AF_END;
    }

    RESULT availableGet(Json::Value &jRequest, Json::Value &jResponse);
    DECLARE_SUB_DEVICE_OPS;
};

class CitfAvs : virtual public Citf {
public:
    CitfAvs(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_AVS_BEGIN;
      subId_End = ISPCORE_MODULE_AVS_END;
    }

    DECLARE_SUB_DEVICE_OPS;
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfCproc : virtual public Citf {
public:
    CitfCproc(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_CPROC_BEGIN;
      subId_End = ISPCORE_MODULE_CPROC_END;
    }
    RESULT coefficientSet(Json::Value &jRequest, Json::Value &jResponse);

    DECLARE_SUB_DEVICE_OPS;
};

class CitfBls : virtual public Citf {
public:
    CitfBls(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_BLS_BEGIN;
      subId_End = ISPCORE_MODULE_BLS_END;
    }

    DECLARE_SUB_DEVICE_OPS;
};

class CitfDeGamma : virtual public Citf {
public:
    CitfDeGamma(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_DEGAMMA_BEGIN;
      subId_End   = ISPCORE_MODULE_DEGAMMA_END;
    }

    DECLARE_SUB_DEVICE_OPS;
};

class CitfCac : virtual public Citf {
public:
    CitfCac(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_CAC_BEGIN;
      subId_End = ISPCORE_MODULE_CAC_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfCnr : virtual public Citf {
public:
    CitfCnr(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_CNR_BEGIN;
      subId_End = ISPCORE_MODULE_CNR_END;
    }
    DECLARE_SUB_DEVICE_OPS;
};

class CitfDpcc : virtual public Citf {
public:
    CitfDpcc(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_DPCC_BEGIN;
      subId_End = ISPCORE_MODULE_DPCC_END;
    }

    DECLARE_SUB_DEVICE_OPS;
};

class CitfDemosaic : virtual public Citf {
public:

    CitfDemosaic(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_DEMOSAIC_BEGIN;
      subId_End = ISPCORE_MODULE_DEMOSAIC_END;
    }
    DECLARE_SUB_DEVICE_OPS;
};

class CitfEc : virtual public Citf {
public:
    CitfEc(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_EC_BEGIN;
      subId_End = ISPCORE_MODULE_EC_END;
    }
    DECLARE_SUB_DEVICE_OPS;

    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfDpf : virtual public Citf {
public:
    CitfDpf(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_DPF_BEGIN;
      subId_End = ISPCORE_MODULE_DPF_END;
    };

    DECLARE_SUB_DEVICE_OPS;
};

class CitfGc : virtual public Citf {
public:
    CitfGc(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_GC_BEGIN;
      subId_End = ISPCORE_MODULE_GC_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT curveGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT curveSet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfEe : virtual public Citf {
public:
    CitfEe(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_EE_BEGIN;
      subId_End = ISPCORE_MODULE_EE_END;
    }

    struct Config {
      int32_t strength;
      int32_t sharpen;
      int32_t depurple;
    };

    DECLARE_SUB_DEVICE_OPS;
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableSet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfFileSystem : public Citf {
public:
    CitfFileSystem(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_FILESYSTEM_BEGIN;
      subId_End = ISPCORE_MODULE_FILESYSTEM_END;
    }

    DECLARE_SUB_DEVICE_OPS;
    RESULT remove(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfFilter : virtual public Citf {
public:
    CitfFilter(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_FILTER_BEGIN;
      subId_End = ISPCORE_MODULE_FILTER_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableSet(Json::Value &jRequest, Json::Value &jResponse);
};

class Citf2Dnr : virtual public Citf {
public:
    Citf2Dnr(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_2DNR_BEGIN;
      subId_End = ISPCORE_MODULE_2DNR_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableSet(Json::Value &jRequest, Json::Value &jResponse);
};

class Citf3Dnr : virtual public Citf {
public:
    Citf3Dnr(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_3DNR_BEGIN;
      subId_End = ISPCORE_MODULE_3DNR_END;
    }

    DECLARE_SUB_DEVICE_OPS;
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableSet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfReg : virtual public Citf {
public:
    CitfReg(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_REG_BEGIN;
      subId_End = ISPCORE_MODULE_REG_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT description(Json::Value &jRequest, Json::Value &jResponse);
    RESULT get(Json::Value &jRequest, Json::Value &jResponse);
    RESULT set(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfHdr : virtual public Citf {
public:
    CitfHdr(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_HDR_BEGIN;
      subId_End = ISPCORE_MODULE_HDR_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfIe : virtual public Citf {
public:
    CitfIe(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_IE_BEGIN;
      subId_End = ISPCORE_MODULE_IE_END;
    }
    DECLARE_SUB_DEVICE_OPS;
};

class CitfLsc : virtual public Citf {
public:
    CitfLsc(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_LSC_BEGIN;
      subId_End = ISPCORE_MODULE_LSC_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfWdr : virtual public Citf {
public:
    CitfWdr(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input)  {
      subId_Begin = ISPCORE_MODULE_WDR_BEGIN;
      subId_End = ISPCORE_MODULE_WDR_END;
    }
    DECLARE_SUB_DEVICE_OPS;
    RESULT reset(Json::Value &jRequest, Json::Value &jResponse);
    RESULT statusGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableGet(Json::Value &jRequest, Json::Value &jResponse);
    RESULT tableSet(Json::Value &jRequest, Json::Value &jResponse);
};

class CitfSimp : virtual public Citf {
public:
    CitfSimp(Citf_Handle * pCitfHandle_input) :Citf(pCitfHandle_input) {
      subId_Begin = ISPCORE_MODULE_SIMP_BEGIN;
      subId_End = ISPCORE_MODULE_SIMP_END;
    }
    DECLARE_SUB_DEVICE_OPS;
};

} // namespace camdev
