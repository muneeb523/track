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

#ifndef _CAMERA_DEVICE_BUF_DEFS_COMMON_H_
#define _CAMERA_DEVICE_BUF_DEFS_COMMON_H_

enum {
	CAMERA_PIX_FMT_YUV422SP = 0,
	CAMERA_PIX_FMT_YUV422I,
	CAMERA_PIX_FMT_YUV420SP,
	CAMERA_PIX_FMT_YUV444,
	CAMERA_PIX_FMT_RGB888,
	CAMERA_PIX_FMT_RGB888P,
	CAMERA_PIX_FMT_RAW8,
	CAMERA_PIX_FMT_RAW10,
	CAMERA_PIX_FMT_RAW12,
	CAMERA_PIX_FMT_MAX,
};


typedef enum _ISPCORE_BUFIO_ID_ {
	ISPCORE_BUFIO_MP        = 0,
	ISPCORE_BUFIO_SP1       = 1,
	ISPCORE_BUFIO_SP2       = 2,
	ISPCORE_BUFIO_RDI       = 3,  // RAW dump interface
	ISPCORE_BUFIO_META      = 4,  // meta sw delivery port
	ISPCORE_BUFIO_WRITEMAX  = 5,
	ISPCORE_BUFIO_READ      = 6,
	ISPCORE_BUFIO_MAX       = 7,
} ISPCORE_BUFIO_ID;

typedef struct __BufIdentity__ {
	uint64_t address_usr;     // address in V4l2 application space
	uint64_t address_daemon;  // address in native stack space
	uint64_t address_kernel;  // address in kernel space
	uint32_t address_reg;     // address set to ispcore register
	uint32_t buffer_idx;      // buffer index
	uint32_t buff_size;       // biffer size
	uint32_t filled;
	void     *ctx;            // memory handle
	int width;
	int height;
	int format;
} BufIdentity;

typedef struct ispcore_meta_kernel_s {
	unsigned int data_kernel;
} ispcore_meta_kernel_t;

typedef struct ispcore_meta_kernel_dma_s {
	unsigned int data_kernel_dma;
} ispcore_meta_kernel_dma_t;

typedef struct ispcore_meta_user_s {
	unsigned int data_user;
} ispcore_meta_user_t;

typedef struct ispcore_meta_s {
	ispcore_meta_kernel_t     kernel_meta;
	ispcore_meta_kernel_dma_t kernel_meta_dma;
	ispcore_meta_user_t       user_meta;
} ispcore_meta_t;

#endif  // _CAMERA_DEVICE_BUF_DEFS_COMMON_H_
