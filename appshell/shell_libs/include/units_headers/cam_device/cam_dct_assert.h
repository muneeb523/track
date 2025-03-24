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

#ifndef _CAM_DCT_ASSERT_H_
#define _CAM_DCT_ASSERT_H_

/**
 *          Compile time assert. Use e.g. to check the size of certain data
 *           types. As this is evaluated at compile time, it will neither cause
 *           size nor speed overhead, and thus is does not need to be inside
 *           the NDEBUG.
 *
 *****************************************************************************/
/* we need several levels of indirection to make unique enum names working
 * we need unique enum names to be able to use DCT_ASSERT_STATIC more than
 * one time per compilation unit
 */
#define UNIQUE_ENUM_NAME(u)     assert_static__ ## u
#define GET_ENUM_NAME(x)        UNIQUE_ENUM_NAME(x)
#define DCT_ASSERT_STATIC(e)    enum { GET_ENUM_NAME(__LINE__) = 1/(e) }


#endif  // _CAM_DCT_ASSERT_H_
