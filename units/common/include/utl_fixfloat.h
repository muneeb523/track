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


/*!
 *  @file        utl_fixfloat.h
 *  @version     1.0
 *  @author      Neugebauer
 *  @brief       Floatingpoint to Fixpoint and vice versa conversion
 *               routines.
 */


#ifndef __UTL_FIXFLOAT_H__
#define __UTL_FIXFLOAT_H__

/*****************************************************************************
 * Prototypes
 *****************************************************************************/

uint32_t UtlFloatToFix_U0107( float fFloat );
float  UtlFixToFloat_U0107( uint32_t ulFix );

uint32_t UtlFloatToFix_U0208( float fFloat );
float  UtlFixToFloat_U0208( uint32_t ulFix );

uint32_t UtlFloatToFix_U0408( float fFloat );
float  UtlFixToFloat_U0408( uint32_t ulFix );

uint32_t UtlFloatToFix_U0800( float fFloat );
float  UtlFixToFloat_U0800( uint32_t ulFix );

uint32_t UtlFloatToFix_U1000( float fFloat );
float  UtlFixToFloat_U1000( uint32_t ulFix );

uint32_t UtlFloatToFix_U1200( float fFloat );
float  UtlFixToFloat_U1200( uint32_t ulFix );

uint32_t UtlFloatToFix_U0010( float fFloat );
float  UtlFixToFloat_U0010( uint32_t ulFix );

uint32_t UtlFloatToFix_S0207( float fFloat );
float  UtlFixToFloat_S0207( uint32_t ulFix );

uint32_t UtlFloatToFix_S0307( float fFloat );
float  UtlFixToFloat_S0307( uint32_t ulFix );

uint32_t UtlFloatToFix_S0407( float fFloat );
float  UtlFixToFloat_S0407( uint32_t ulFix );

uint32_t UtlFloatToFix_S0504( float fFloat );
float  UtlFixToFloat_S0504( uint32_t ulFix );

uint32_t UtlFloatToFix_S0808( float fFloat );
float  UtlFixToFloat_S0808( uint32_t ulFix );

uint32_t UtlFloatToFix_S0800( float fFloat );
float  UtlFixToFloat_S0800( uint32_t ulFix );

uint32_t UtlFloatToFix_S0900( float fFloat );
float  UtlFixToFloat_S0900( uint32_t ulFix );

uint32_t UtlFloatToFix_S1200( float fFloat );
float  UtlFixToFloat_S1200( uint32_t ulFix );

uint32_t UtlFloatToFix_S0109( float fFloat );
float UtlFixToFloat_S0109( uint32_t ulFix );

uint32_t UtlFloatToFix_S0408( float fFloat );
float UtlFixToFloat_S0408( uint32_t ulFix );

uint32_t UtlFloatToFix_S0108( float fFloat );
float UtlFixToFloat_S0108( uint32_t ulFix );

uint32_t UtlFloatToFix_S0110( float fFloat );
float UtlFixToFloat_S0110( uint32_t ulFix );

#endif /* __UTL_FIXfloat_H__ */

