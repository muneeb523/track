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
 * @file hw_version.h
 *
 * @brief
 *   This header files contains hardware module version define informations.
 *
 *****************************************************************************/
#ifndef __HW_VERSION_H__
#define __HW_VERSION_H__


/*****************************************************************************/
/**
 * @brief   HDR module version type
 */
/*****************************************************************************/
#define VSI_ISP_HDR_NOTSUPPORT  0   //!< Not support HDR
#define VSI_ISP_HDR_V10         1   //!< Version V10
#define VSI_ISP_HDR_V11         2   //!< Version V11
#define VSI_ISP_HDR_V12         3   //!< Version V12
#define VSI_ISP_HDR_V13         4   //!< Version V13




/////////////////////////////////////////
//add Version defines
/////////////////////////////////////////
#ifdef ISP8000NANO_V1801

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_NOTSUPPORT

#elif defined ISP8000NANO_V1802

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000_V1901

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000L_V1901

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_NOTSUPPORT

#elif defined ISP8000L_V1902

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000L_V1903

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V1905

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2001

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2002

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000_V2003

#define VSI_ISP_HDR_VERSION VSI_ISP_HDR_V13

#elif defined ISP8000L_V2007

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2008

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#endif





#endif /* __HW_VERSION_H__ */

