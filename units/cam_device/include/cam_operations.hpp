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
#include "cam_engine_interface.hpp"
#include "cam_sensor.hpp"
#include <vector>
#include "buf_io.hpp"
#include <cam_engine/cam_engine_api.h>
#include <string>

#include <deque>
#include <mutex>

namespace camdev {

typedef void(AfpsResChangeCb_t)(const void *);
const int CAM_METADATA_CHANNEL = 3;
const int CAM_METADATA_NUMBER = 1;

struct Operation : CamStatus {
    Operation(Operation_Handle * pOperationHandle_in);
    ~Operation();

  enum SnapshotType { RAW8, RAW10, RAW12, RAW16, RGB, YUV, JPEG };

    static int32_t afpsResChangeRequestCb(uint16_t, uint16_t, const void *);

    uint bitstreamId() const;

    int32_t bufferMap(const MediaBuffer_t *, PicBufMetaData_t *);
    int32_t bufferUnmap(PicBufMetaData_t *);

    uint camerIcId() const;

  int32_t dehazeEnableGet(bool &);
  int32_t dehazeEnableSet(bool);

    int32_t ecmSet(bool = false);

    Image &image() {
        return *images[pOperationHandle->pCalibration->module<camdev::CalibInputs>().config.index];
    }

    int32_t inputConnect();
    int32_t inputDisconnect();
    int32_t inputSwitch(int32_t);

    int32_t reset();

    int32_t resolutionGet(uint16_t &, uint16_t &);
    int32_t resolutionSet(uint16_t , uint16_t );

    SensorOps &sensor() {
        return *sensors[pOperationHandle->pCalibration->module<camdev::CalibInputs>().config.index];
    };

  std::string softwareVersion() const;

    int32_t streamingStart(uint frames = 0);
    int32_t streamingStop();

    std::vector<Image *> images;
    std::vector<SensorOps *> sensors;

    AfpsResChangeCb_t *pAfpsResChangeCb = nullptr;

    Engine *pEngine = nullptr;

    const void *pUserCbCtx = nullptr;

    // device operations
    static void bufferCb(CamEnginePathType_t path, MediaBuffer_t *pMediaBuffer, void *pCtx);

    typedef struct ImageSize_s {
      uint32_t bounds_width;
      uint32_t bounds_height;
      uint32_t top;
      uint32_t left;
      uint32_t width;
      uint32_t height;
      ImageSize_s& operator=(const ImageSize_s& size) {
        bounds_width  = size.bounds_width;
        bounds_height = size.bounds_height;
        top    = size.top;
        left   = size.left;
        width  = size.width;
        height = size.height;
        return *this;
      }
    } ImageSize_t;

    typedef struct ConnectInfo {
        ImageSize_t CameraSize;
        ImageSize_t CropSize;
        ImageSize_t ScaleSize;
        uint32_t  fps;
        uint32_t  format;
        uint32_t colorspace;
        uint32_t colorrange;

        ConnectInfo& operator=(const ConnectInfo& info) {
            CameraSize = info.CameraSize;
            CropSize   = info.CropSize;
            ScaleSize  = info.ScaleSize;
            format     = info.format;
            fps        = info.fps;
            colorspace = info.colorspace;
            colorrange = info.colorrange;
            return *this;
        }
    } ConnectInfo;

    int32_t cameraConnect(bool preview, ItfBufferCb * bufferCb, const ConnectInfo& connectInfo);
    int32_t cameraDisconnect();
    int32_t cameraReset();

    int32_t captureDma(std::string, CAMDEV_SnapshotType);
    int32_t captureSensor(std::string, CAMDEV_SnapshotType, uint32_t, CamEngineLockType_t = CAM_ENGINE_LOCK_ALL);

    int32_t previewStart();
    int32_t previewStop();

    int32_t streamingStandby(bool enable);

    // friend class PfidItf;

    struct BufferCbContext {
        std::list<ItfBufferCb *> mainPath;
        std::list<ItfBufferCb *> selfPath1;
        std::list<ItfBufferCb *> selfPath2;
        std::list<ItfBufferCb *> rdiPath;
        std::list<ItfBufferCb *> metaPath;
    };

    BufferCbContext *pBufferCbContext = nullptr;
    Operation_Handle * pOperationHandle = nullptr;

    void *pSampleCbContext = nullptr;
    uint8_t sampleSkip = 0;

    int miMode, miLayout, miAlign;
    ConnectInfo mConnectInfo;

    int updateMetadata(CamEnginePathType_t path);
    struct isp_metadata* getMetadata(int path);
    void freeMetadata(struct isp_metadata* meta, int path);
    std::list<isp_metadata *> mMetaList[CAM_METADATA_CHANNEL]; // main, self, self2
    std::mutex mMetaLock;
    bool bStandby = false;
};

}
