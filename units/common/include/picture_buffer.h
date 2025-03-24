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


/**
 * @file    picture_buffer.h
 *
 * @brief   Defines picture buffer meta data structure including its components
 *          and helper functions around that structure.
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup picture_buffer Picture buffer descriptor
 * @{
 *
 */
#ifndef __PICTURE_BUFFER_H__
#define __PICTURE_BUFFER_H__

#include <ebase/types.h>
#include <scmi/scmi_types.h>
#include <common/return_codes.h>
#include <cam_device/cam_device_buf_defs.h>

#if defined (__cplusplus)
extern "C" {
#endif

/* input and output buffer macro define, default disable. */
#define ENABLE_BUFFER_DUMP 0



/*****************************************************************************/
/**
 *          PicBufIsConfigValid()
 *
 * @brief   Check the given picture buffer meta data structure for valid
 *          type & layout combination.
 *
 * @param   Reference to picture buffer meta data structure.
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS     type & layout combination is valid
 * @retval  RET_NOTSUPP     type & layout combination is invalid
 * @retval  RET_OUTOFRANGE  invalid type and/or layout
 *
 *****************************************************************************/
extern RESULT PicBufIsConfigValid
(
    PicBufMetaData_t *pPicBufMetaData
);

extern RESULT PicBufDump
(
    PicBufMetaData_t *pPicBuffer,
    const uint8_t *logical,
    bool_t inputSource
);

/* @} picture_buffer */

#if defined (__cplusplus)
}
#endif

#endif /* __PICTURE_BUFFER_H__ */
