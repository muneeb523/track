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

#ifndef _CAMERA_DEVICE_METADATA_H_
#define _CAMERA_DEVICE_METADATA_H_

#include <stdint.h>

typedef struct isp_rect {
    int x, y, w, h;
} isp_rect;

typedef struct isp_metadata {
    struct {
        bool enable;
        uint8_t mode;
        isp_rect rc;
        uint8_t mean[25];
        uint8_t sem[25];
    } exp;

    struct {
        bool enable;
        uint8_t mode;
        uint16_t gain_r, gain_gr, gain_gb, gain_b;
        isp_rect rc;
        uint32_t r, g, b;
        uint32_t no_white_count;
    } awb;

    struct {
        bool enable;
        int type; // 16, 256
        uint8_t mode;
        isp_rect rc;
        uint32_t mean[16];
    } hist;

    struct {
        bool enable;
        isp_rect rc;
        uint32_t h_seg, v_seg;
        uint32_t x, y;
    } vsm;

    struct {
        bool enable;
        uint32_t thresh;
        isp_rect rc[3];
        uint32_t sum_a, sum_b, sum_c;
        uint32_t lum_a, lum_b, lum_c;
    } afm;

    struct {
        bool enable;
        isp_rect rc;
        uint8_t r, gr, gb, b;
        uint8_t mean[4096];
    } exp2;

    int id;
    bool filled;  // 0-free, 1-filled
} isp_metadata;


#define SECTION_NAME_EXP "exp"
#define SECTION_NAME_EXP2 "exp2"
#define SECTION_NAME_HIST "hist"
#define SECTION_NAME_VSM "vsm"
#define SECTION_NAME_AFM "afm"
#define SECTION_NAME_AWB "awb"

enum {
    VIV_METADATA_EXP_MODE_LUMA = 0,
    VIV_METADATA_EXP_MODE_RGB,
};

enum {
    VIV_METADATA_HIST_MODE_NONE = 0,
    VIV_METADATA_HIST_MODE_RGB,
    VIV_METADATA_HIST_MODE_R,
    VIV_METADATA_HIST_MODE_G,
    VIV_METADATA_HIST_MODE_B,
    VIV_METADATA_HIST_MODE_LUM,
};

enum {
    VIV_METADATA_AWB_MODE_MANUAL = 0,
    VIV_METADATA_AWB_MODE_AUTO = 2,
};

#ifdef __cplusplus
#include <unordered_map>
typedef std::unordered_map<std::string, int> viv_metadata_tag;
static viv_metadata_tag VIV_METADATA_EXP_MODE = {
    {"VIV_METADATA_EXP_MODE_LUMA", VIV_METADATA_EXP_MODE_LUMA},
    {"VIV_METADATA_EXP_MODE_RGB",  VIV_METADATA_EXP_MODE_RGB},
};

static viv_metadata_tag VIV_METADATA_EXP2_MODE = {
};

static viv_metadata_tag VIV_METADATA_AWB_MODE = {
    {"VIV_METADATA_AWB_MODE_MANUAL", VIV_METADATA_AWB_MODE_MANUAL},
    {"VIV_METADATA_AWB_MODE_AUTO",  VIV_METADATA_AWB_MODE_AUTO},
};

static viv_metadata_tag VIV_METADATA_HIST_MODE = {
    {"VIV_METADATA_HIST_MODE_NONE", VIV_METADATA_HIST_MODE_NONE},
    {"VIV_METADATA_HIST_MODE_RGB",  VIV_METADATA_HIST_MODE_RGB},
    {"VIV_METADATA_HIST_MODE_R",    VIV_METADATA_HIST_MODE_R},
    {"VIV_METADATA_HIST_MODE_G",    VIV_METADATA_HIST_MODE_G},
    {"VIV_METADATA_HIST_MODE_B",    VIV_METADATA_HIST_MODE_B},
    {"VIV_METADATA_HIST_MODE_LUM",  VIV_METADATA_HIST_MODE_LUM},
};

static viv_metadata_tag VIV_METADATA_VSM_MODE = {
};

#endif

#endif
