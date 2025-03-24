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
 * @file isi_common.h
 *
 * @brief the common MARCO & Structure description for isi.
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup isi_iss CamerIc Driver API
 * @{
 *
 */
#ifndef __ISI_COMMON_H__
#define __ISI_COMMON_H__
#ifdef ISI_LITE
#include "vsi_type.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/*!
 * interface version
 * =================
 * please increment the version if you add something new to the interface.
 * This helps upper layer software to deal with different interface versions.
 */
/*****************************************************************************/
#define ISI_INTERFACE_VERSION               0x00050000      /**< V5.0.0*/

#define ISI_EXPO_PARAS_FIX_FRACBITS         10              /**<q10 time/ration/integeration time/gain/framerate */
/**< Mode, operating mode of the image sensor in terms of output data format and timing data transmission */
#define ISI_MODE_BT601                      0x00000001      /**< YUV-Data with separate h/v sync lines (ITU-R BT.601) */
#define ISI_MODE_BT656                      0x00000002      /**< YUV-Data with sync words inside the datastream (ITU-R BT.656) */
#define ISI_MODE_BAYER                      0x00000004      /**< Bayer data with separate h/v sync lines */
#define ISI_MODE_DATA                       0x00000008      /**< Any binary data without line/column-structure, (e.g. already JPEG encoded) h/v sync lines act as data valid signals */
#define ISI_MODE_PICT                       0x00000010      /**< RAW picture data with separate h/v sync lines */
#define ISI_MODE_RGB565                     0x00000020      /**< RGB565 data with separate h/v sync lines */
#define ISI_MODE_SMIA                       0x00000040      /**< SMIA conform data stream (see SmiaMode for details) */
#define ISI_MODE_MIPI                       0x00000080      /**< MIPI conform data stream (see MipiMode for details) */
#define ISI_MIPI_LANES                      0x00000060
#define ISI_MODE_BAY_BT656                  0x00000100      /**< Bayer data with sync words inside the datastream (similar to ITU-R BT.656) */
#define ISI_MODE_RAW_BT656                  0x00000200      /**< Raw picture data with sync words inside the datastream (similar to ITU-R BT.656) */

/**< SmiaMode */
#define ISI_SMIA_MODE_COMPRESSED            0x00000001      //!< compression mode
#define ISI_SMIA_MODE_RAW_8_TO_10_DECOMP    0x00000002      //!< 8bit to 10 bit decompression
#define ISI_SMIA_MODE_RAW_12                0x00000004      //!< 12 bit RAW Bayer Data
#define ISI_SMIA_MODE_RAW_10                0x00000008      //!< 10 bit RAW Bayer Data
#define ISI_SMIA_MODE_RAW_8                 0x00000010      //!< 8 bit RAW Bayer Data
#define ISI_SMIA_MODE_RAW_7                 0x00000020      //!< 7 bit RAW Bayer Data
#define ISI_SMIA_MODE_RAW_6                 0x00000040      //!< 6 bit RAW Bayer Data
#define ISI_SMIA_MODE_RGB_888               0x00000080      //!< RGB 888 Display ready Data
#define ISI_SMIA_MODE_RGB_565               0x00000100      //!< RGB 565 Display ready Data
#define ISI_SMIA_MODE_RGB_444               0x00000200      //!< RGB 444 Display ready Data
#define ISI_SMIA_MODE_YUV_420               0x00000400      //!< YUV420 Data
#define ISI_SMIA_MODE_YUV_422               0x00000800      //!< YUV422 Data
#define ISI_SMIA_OFF                        0x80000000      //!< SMIA is disabled

/**< MipiMode */
#define ISI_MIPI_MODE_YUV420_8              0x00000001      //!< YUV 420  8-bit
#define ISI_MIPI_MODE_YUV420_10             0x00000002      //!< YUV 420 10-bit
#define ISI_MIPI_MODE_LEGACY_YUV420_8       0x00000004      //!< Legacy YUV 420 8-bit
#define ISI_MIPI_MODE_YUV420_CSPS_8         0x00000008      //!< YUV 420 8-bit (CSPS)
#define ISI_MIPI_MODE_YUV420_CSPS_10        0x00000010      //!< YUV 420 10-bit (CSPS)
#define ISI_MIPI_MODE_YUV422_8              0x00000020      //!< YUV 422 8-bit
#define ISI_MIPI_MODE_YUV422_10             0x00000040      //!< YUV 422 10-bit
#define ISI_MIPI_MODE_RGB444                0x00000080      //!< RGB 444
#define ISI_MIPI_MODE_RGB555                0x00000100      //!< RGB 555
#define ISI_MIPI_MODE_RGB565                0x00000200      //!< RGB 565
#define ISI_MIPI_MODE_RGB666                0x00000400      //!< RGB 666
#define ISI_MIPI_MODE_RGB888                0x00000800      //!< RGB 888
#define ISI_MIPI_MODE_RAW_6                 0x00001000      //!< RAW_6
#define ISI_MIPI_MODE_RAW_7                 0x00002000      //!< RAW_7
#define ISI_MIPI_MODE_RAW_8                 0x00004000      //!< RAW_8
#define ISI_MIPI_MODE_RAW_10                0x00008000      //!< RAW_10
#define ISI_MIPI_MODE_RAW_12                0x00010000      //!< RAW_12
#define ISI_MIPI_OFF                        0x80000000      //!< MIPI is disabled
#define ISI_MIPI_4LANES                     0x00000004
#define ISI_MIPI_2LANES                     0x00000002

/**< FieldSelection */
#define ISI_FIELDSEL_BOTH                   0x00000001      /**< sample all field (don't care about fields */
#define ISI_FIELDSEL_EVEN                   0x00000002      /**< sample only even fields */
#define ISI_FIELDSEL_ODD                    0x00000004      /**< sample only odd fields */

/**< YCSeq */
#define ISI_YCSEQ_YCBYCR                    0x00000001
#define ISI_YCSEQ_YCRYCB                    0x00000002
#define ISI_YCSEQ_CBYCRY                    0x00000004
#define ISI_YCSEQ_CRYCBY                    0x00000008

/**< Conv422 */
#define ISI_CONV422_COSITED                 0x00000001
#define ISI_CONV422_INTER                   0x00000002
#define ISI_CONV422_NOCOSITED               0x00000004

/**< BayerPatttern */
#define ISI_BPAT_RGRGGBGB                   0x00000001
#define ISI_BPAT_GRGRBGBG                   0x00000002
#define ISI_BPAT_GBGBRGRG                   0x00000004
#define ISI_BPAT_BGBGGRGR                   0x00000008

/**< HPolarity */
#define ISI_HPOL_SYNCPOS                    0x00000001      /**< sync signal pulses high between lines */
#define ISI_HPOL_SYNCNEG                    0x00000002      /**< sync signal pulses low between lines */
#define ISI_HPOL_REFPOS                     0x00000004      /**< reference signal is high as long as sensor puts out line data */
#define ISI_HPOL_REFNEG                     0x00000008      /**< reference signal is low as long as sensor puts out line data */

/**< VPolarity */
#define ISI_VPOL_POS                        0x00000001
#define ISI_VPOL_NEG                        0x00000002

/**< Edge */
#define ISI_EDGE_RISING                     0x00000001
#define ISI_EDGE_FALLING                    0x00000002

/**< frame rate **/
#define ISI_FPS_MAX                         60
#define ISI_FPS_MIN                         1

/**< HDR */
#define ISI_HDR_DISABLED                    BOOL_FALSE      /**< hdr disabled */
#define ISI_HDR_ENABLED                     BOOL_TRUE       /**< hdr enabled */

/*****************************************************************************/
/**
 *          IsiSensorAwbMode_t
 *
 * @brief   mode of awb control to handle whitebalance during integration of AR082x
 */
/*****************************************************************************/
typedef enum IsiSensorAwbMode_e
{
    ISI_SENSOR_AWB_MODE_NORMAL  = 0,
    ISI_SENSOR_AWB_MODE_SENSOR,
} IsiSensorAwbMode_t;

/*****************************************************************************/
/**
 *          IsiColorComponent_t
 *
 * @brief   color components
 */
/*****************************************************************************/
typedef enum IsiColorComponent_e
{
    ISI_COLOR_COMPONENT_RED     = 0,
    ISI_COLOR_COMPONENT_GREENR  = 1,
    ISI_COLOR_COMPONENT_GREENB  = 2,
    ISI_COLOR_COMPONENT_BLUE    = 3,
    ISI_COLOR_COMPONENT_MAX     = 4
} IsiColorComponent_t;

typedef enum IsiExpoFrmType_enum {
    ISI_EXPO_FRAME_TYPE_1FRAME  = 0,
    ISI_EXPO_FRAME_TYPE_2FRAMES = 1,
    ISI_EXPO_FRAME_TYPE_3FRAMES = 2,
    ISI_EXPO_FRAME_TYPE_4FRAMES = 3,
    ISI_EXPO_FRAME_TYPE_MAX
} IsiExpoFrmType_e;

typedef enum IsiStitchingMode_enum {
    ISI_STITCHING_DUAL_DCG        = 0,   /**< dual DCG mode 3x12-bit */
    ISI_STITCHING_3DOL            = 1,   /**< dol3 frame 3x12-bit */
    ISI_STITCHING_LINEBYLINE      = 2,   /**< 3x12-bit line by line without waiting */
    ISI_STITCHING_16BIT_COMPRESS  = 3,   /**< 16-bit compressed data + 12-bit RAW */
    ISI_STITCHING_DUAL_DCG_NOWAIT = 4,   /**< 2x12-bit dual DCG without waiting */
    ISI_STITCHING_2DOL            = 5,   /**< dol2 frame or 1 CG+VS sx12-bit RAW */
    ISI_STITCHING_L_AND_S         = 6,   /**< L+S 2x12-bit RAW */
    ISI_STITCHING_MAX
} IsiStitchingMode_e;

typedef enum IsiHdrMode_enum
{
    ISI_MODE_LINEAR         = 0,
    ISI_MODE_HDR_STITCH     = 1,
    ISI_MODE_HDR_NATIVE     = 2,
    ISI_MODE_HDR_MAX
}IsiHdrMode_e;

typedef enum IsiBayerPattern_enum
{
    ISI_BAYER_RGGB    = 0,
    ISI_BAYER_GRBG    = 1,
    ISI_BAYER_GBRG    = 2,
    ISI_BAYER_BGGR    = 3,
    ISI_BAYER_MAX
}IsiBayerPattern_e;


typedef enum IsiConfigType_enum
{
    ISI_CONFIG_TYPE_SW_REG      = 0,
    ISI_CONFIG_TYPE_HW_PIN      = 1,
    ISI_CONFIG_TYPE_NUM
}IsiConfigType_e;

typedef enum IsiSensorTestPatternMode_enum
{
    ISI_TPG_DISABLE     = 0,
    ISI_TPG_MODE_0      = 1,
    ISI_TPG_MODE_1      = 2,
    ISI_TPG_MODE_2      = 3,
    ISI_TPG_MODE_3      = 4,
    ISI_TPG_MODE_4      = 5,
    ISI_TPG_MODE_5      = 6,
    ISI_TPG_MAX
}IsiSensorTpgMode_e;

typedef enum IsiFocus_enum {
    ISI_FOUCUS_MODE_ABSOLUTE  = 0,
    ISI_FOUCUS_MODE_RELATIVE = 1,
    ISI_FOUCUS_MODE_MAX
} IsiFocus_e;

/*****************************************************************************/
/*!
 *  *  Sensor-specific information structure for MIPI. Is filled in by sensor
 *   *  specific code. Features not supported by the sensor driver code will be
 *   set
 *    *  to NULL.
 *     */
/*****************************************************************************/
typedef struct
{
    uint8_t  ucMipiLanes;             // number of used MIPI lanes by sensor
} IsiSensorMipiInfo;

#ifdef __cplusplus
}
#endif

#endif /* __ISI_COMMON_H__ */
