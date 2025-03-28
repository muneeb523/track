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
 * @file    cea_861.h
 *
 * @brief   Defines CEA 861 style video format stuff.
 *
 *****************************************************************************/
#ifndef __CEA_861_H__
#define __CEA_861_H__

#include <ebase/types.h>

#if defined (__cplusplus)
extern "C" {
#endif

typedef enum Cea861VideoFormat_e
{
    CEA_861_VIDEOFORMAT_INVALID        = 0,

    // CEA 861 formats below
    CEA_861_VIDEOFORMAT_640x480p60     = 1,
    CEA_861_VIDEOFORMAT_1280x720p60    = 4,
    CEA_861_VIDEOFORMAT_1920x1080p60   = 16,
    CEA_861_VIDEOFORMAT_1920x1080p50   = 31,
    CEA_861_VIDEOFORMAT_1920x1080p24   = 32,
    CEA_861_VIDEOFORMAT_1920x1080p25   = 33,
    CEA_861_VIDEOFORMAT_1920x1080p30   = 34,

    // user defined formats below
    CEA_861_VIDEOFORMAT_CUSTOM_BASE    = 256
} Cea861VideoFormat_t; //!< @note The names and numbers intentionally match the CEA 861 Specification; Version D

typedef struct Cea861VideoFormatDetails_s   //!< All counting in CEA spec starts at 1 (not 0) and so do we!
{
    Cea861VideoFormat_t FormatID;           //!< CEA 861 format ID.
    Cea861VideoFormat_t FormatIDInfoFrame;  //!< Format ID to be used in HDMI info frame; required for 3D support; same as FormatID for all CEA 861 formats and most HDMI 3D formats.
    char                *szName;            //!< Format description.
    uint16_t            Hactive;            //!< Active width in pixel.
    uint16_t            Vactive;            //!< Active height in lines.
    bool_t              Progressive;        //!< Progressive/Interlaced (true/false) scanning.
    uint32_t            PixClk;             //!< Pixel clock.
    uint16_t            PixRep;             //!< Clocks per pixel (used for pixel repetition).
    uint16_t            Htotal;             //!< Total width in pixel.
    uint16_t            HsyncStart;         //!< HSync start position.
    uint16_t            HsyncStop;          //!< HSync stop position.
    uint16_t            HactStart;          //!< First active pixel.
    uint16_t            HfieldPos;          //!< Horizontal position of field sync change.
    uint16_t            Vtotal;             //!< Total height in lines (for interlaced: of full frame).
    uint16_t            VsyncStart;         //!< VSync start position.
    uint16_t            VsyncStop;          //!< VSync stop position.
    uint16_t            VactStart;          //!< First active line.
    uint16_t            VactStartDelay;     //!< Delay between VactStart and first line containing active image data; required for 3D support only; set to 0 (null) for CEA 861 formats.
    bool_t              HsyncPolarity;      //!< Hsync polarity high-active/low-active (true/false).
    bool_t              VsyncPolarity;      //!< Vsync polarity high-active/low-active (true/false).
    bool_t              FsyncPolarity;      //!< Field sync polarity high-active/low-active (true/false).
    bool_t              EnPolarity;         //!< Pixel enable polarity high-active/low-active (true/false).
} Cea861VideoFormatDetails_t;

extern const Cea861VideoFormatDetails_t* Cea861GetVideoFormatDetails
(
    Cea861VideoFormat_t FormatID
);

extern bool_t Cea861AlignVideoFormatDetails
(
    Cea861VideoFormatDetails_t *pVideoFormatDetails
);


#if defined (__cplusplus)
}
#endif

#endif /* __CEA_861_H__*/
