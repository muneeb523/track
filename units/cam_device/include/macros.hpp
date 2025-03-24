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

#ifdef USE_STANDARD_ASSERT
#include "assert.hpp"
#undef DCT_ASSERT
#define DCT_ASSERT(_X_) assert(_X_)
#else
#include <ebase/dct_assert.h>
#endif

#define REPORT(_X_)                                                            \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING) {                            \
      printf("[ERR] %s:%d: %s() = %d(%s) \n", __FILE__, __LINE__,              \
             __FUNCTION__, _X_, #_X_);                                         \
      return _X_;                                                              \
    }                                                                          \
  } while (0);

#define REPORT_WORET(_X_)                                                      \
  do {                                                                         \
    if (_X_ != RET_SUCCESS && _X_ != RET_PENDING) {                            \
      printf("[ERR] %s:%d: %s() = %d(%s) \n", __FILE__, __LINE__,              \
             __FUNCTION__, _X_, #_X_);                                         \
    }                                                                          \
  } while (0);


#include <ebase/builtins.h>

#define REFCPY(_DST_REF_, _SRC_) MEMCPY(&_DST_REF_, _SRC_, sizeof(_DST_REF_))
#define REFSET(_DST_REF_, _VAL_) MEMSET(&_DST_REF_, _VAL_, sizeof(_DST_REF_))
