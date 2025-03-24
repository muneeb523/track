/****************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 VeriSilicon Holdings Co., Ltd.
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
#include "FBDisplay.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <sched.h>
#include <assert.h>
#include <memory.h>

#include "log.h"
#define LOGTAG "FBDisplay"

#include <linux/videodev2.h>

FBDisplay::FBDisplay() {
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;

    fbfd = ::open("/dev/fb0", O_RDWR);
    if (!fbfd) {
        ALOGE("Error: cannot open framebuffer device");
        exit(1);
    }

    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo))  {
        ALOGE("Error：reading fixed information");
        exit(2);
    }

    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo))   {
        ALOGE("Error: reading variable information");
        exit(3);
    }

    ALOGW("[offset,length,msb_right]: R[%u,%u,%u],G[%u,%u,%u],B[%u,%u,%u]",
           vinfo.red.offset, vinfo.red.length, vinfo.red.msb_right,
           vinfo.green.offset, vinfo.green.length, vinfo.green.msb_right,
           vinfo.blue.offset, vinfo.blue.length, vinfo.blue.msb_right);

    ALOGW("%dx%d, %dbpp", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel );
    xres = vinfo.xres;
    yres = vinfo.yres;
    bits_per_pixel = vinfo.bits_per_pixel;

    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
    ALOGW("screensize=%ld byte",screensize);

    mData = (unsigned char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (mData == MAP_FAILED)   {
        ALOGE("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    back_buffer = (unsigned char *)mmap(NULL, screensize, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (back_buffer == MAP_FAILED){
        ALOGE("Error: failed to map back_buffer to memory");
        exit(5);
    }
    memset(mData,0,screensize);
    memset(back_buffer,0,screensize);
}

FBDisplay::~FBDisplay() {
    munmap(mData,xres*yres*bits_per_pixel/8);
    munmap(back_buffer,xres*yres*bits_per_pixel/8);
    ::close(fbfd);
}

void FBDisplay::showBuffer(unsigned char* data, int width, int height, int format, int size) {
    if (!data || !mData)
        return;

    switch (format) {
    case V4L2_PIX_FMT_NV16:
        convert422spToBGRX(data, back_buffer,  width, height, xres, yres);
        break;
    case V4L2_PIX_FMT_YUYV:
        convertYUYVToBGRX(data, back_buffer,  width, height, xres, yres);
        break;
    case V4L2_PIX_FMT_NV12:
        convertNV12ToBGRX(data, back_buffer,  width, height, xres, yres);
        break;
    case V4L2_PIX_FMT_SBGGR8:
    case V4L2_PIX_FMT_SGBRG8:
    case V4L2_PIX_FMT_SGRBG8:
    case V4L2_PIX_FMT_SRGGB8:
    case V4L2_PIX_FMT_SBGGR10:
    case V4L2_PIX_FMT_SGBRG10:
    case V4L2_PIX_FMT_SGRBG10:
    case V4L2_PIX_FMT_SRGGB10:
    case V4L2_PIX_FMT_SBGGR12:
    case V4L2_PIX_FMT_SGBRG12:
    case V4L2_PIX_FMT_SGRBG12:
    case V4L2_PIX_FMT_SRGGB12:
        convertRawToBGRX(data, back_buffer,  width, height, xres, yres, format);
        break;
    default:
        return;
}

    memcpy(mData,back_buffer,xres*yres*bits_per_pixel/8);
    memset(back_buffer,0,xres*yres*bits_per_pixel/8);
}
