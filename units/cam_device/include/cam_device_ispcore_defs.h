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

#ifndef _CAMERA_DEVICE_ISPCORE_DEFS_H_
#define _CAMERA_DEVICE_ISPCORE_DEFS_H_

#include "types.h"

/*****************************************************************************/
/**
 * @brief Lock types for the auto algorithms. Can be OR combined.
 *
 *****************************************************************************/
typedef enum CamEngineLockType_e {
    CAM_ENGINE_LOCK_NO      = 0x00,
    CAM_ENGINE_LOCK_AF      = 0x01,
    CAM_ENGINE_LOCK_AEC     = 0x02,
    CAM_ENGINE_LOCK_AWB     = 0x04,

    CAM_ENGINE_LOCK_ALL     = (CAM_ENGINE_LOCK_AF | CAM_ENGINE_LOCK_AEC | CAM_ENGINE_LOCK_AWB)
} CamEngineLockType_t;

/*****************************************************************************/
/**
 * @brief   Auto-focus lock status.
 *
 *****************************************************************************/
typedef enum CamEngineAfLockStatus_e
{
    CAM_ENGINE_AF_UNLOCK = 0,          /* af unlock */
    CAM_ENGINE_AF_LOCK,                /* af lock */
} CamEngineAfLockStatus_t;

/*****************************************************************************/
/**
 * @brief   Auto-Focus-Control search algorithm.
 *
 *****************************************************************************/
typedef enum CamEngineAfSearchAlgorithm_e {
    CAM_ENGINE_AUTOFOCUS_SEARCH_ALGORITHM_INVALID           = 0,    /**< invalid search algorithm */
    CAM_ENGINE_AUTOFOCUS_SEARCH_ALGORITHM_FULL_RANGE        = 1,    /**< full range */
    CAM_ENGINE_AUTOFOCUS_SEARCH_ALGORITHM_ADAPTIVE_RANGE    = 2,    /**< adaptive range */
    CAM_ENGINE_AUTOFOCUS_SEARCH_ALGORITHM_HILL_CLIMBING     = 3,    /**< hill climbing */
    CAM_ENGINE_AUTOFOCUS_SEARCH_ALGORITHM_MAX
} CamEngineAfSearchAlgorithm_t;


/*****************************************************************************/
/**
 * @brief   Auto-Focus-Control working mode.
 *
 *****************************************************************************/
typedef enum CamEngineAfWorkMode_e {
    CAM_ENGINE_AF_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_AF_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_AF_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_AF_MODE_MAX
} CamEngineAfWorkMode_t;


/*****************************************************************************/
/**
 * @brief   Auto-Exposure-Control scene evaluation mode.
 *
 *****************************************************************************/
typedef enum CamEngineAecSemMode_e {
    CAM_ENGINE_AEC_SCENE_EVALUATION_INVALID       = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_AEC_SCENE_EVALUATION_DISABLED      = 1,    /**< scene evaluation disabled (fix setpoint) */
    CAM_ENGINE_AEC_SCENE_EVALUATION_FIX           = 2,    /**< scene evaluation fix (static ROI) */
    CAM_ENGINE_AEC_SCENE_EVALUATION_ADAPTIVE      = 3,    /**< scene evaluation adaptive (adaptive ROI) */
    CAM_ENGINE_AEC_SCENE_EVALUATION_MAX
} CamEngineAecSemMode_t;

/*****************************************************************************/
/**
 * @brief   Auto-Exposure-Control lock status.
 *
 *****************************************************************************/
typedef enum CamEngineAecLockStatus_e {
    CAM_ENGINE_AEC_UNLOCK = 0,                   /* ae unlock */
    CAM_ENGINE_AEC_LOCK                          /* ae lock */
} CamEngineAecLockStatus_t;

/*****************************************************************************/
/**
 * @brief   Auto-Exposure-Control sensitivity(ISO) value.
 *
 *****************************************************************************/
typedef enum CamEngineAecSensitivityIso_e {
    CAM_ENGINE_AEC_SENSITIVITY_ISO_INVALID,
    CAM_ENGINE_AEC_SENSITIVITY_100_ISO    = 100,    /* ISO 100 */
    CAM_ENGINE_AEC_SENSITIVITY_200_ISO    = 200,    /* ISO 200 */
    CAM_ENGINE_AEC_SENSITIVITY_400_ISO    = 400,    /* ISO 400 */
    CAM_ENGINE_AEC_SENSITIVITY_800_ISO    = 800,    /* ISO 800 */
    CAM_ENGINE_AEC_SENSITIVITY_1600_ISO   = 1600,   /* ISO 1600 */
    CAM_ENGINE_AEC_SENSITIVITY_ISO_MAX
} CamEngineAecSensitivityIso_t;


/*****************************************************************************/
/**
 * @brief   Auto-Exposure-Control histogram.
 *
 *****************************************************************************/
#define CAM_ENGINE_AEC_HIST_NUM_BINS           16  /**< number of bins */
typedef uint32_t CamEngineAecHistBins_t[CAM_ENGINE_AEC_HIST_NUM_BINS];


/*****************************************************************************/
/**
 * @brief   Auto-Exposure-Control luminance grid.
 *
 *****************************************************************************/
#define CAM_ENGINE_AEC_EXP_GRID_ITEMS          25  /**< number of grid items (see @ref CamerIcMeanLuma_t) */
typedef uint8_t CamEngineAecMeanLuma_t[CAM_ENGINE_AEC_EXP_GRID_ITEMS];

/*****************************************************************************/
/**
 * @brief   Auto-White-Balance lock status.
 *
 *****************************************************************************/
typedef enum CamEngineAwbLockStatus_e
{
    CAM_ENGINE_AWB_UNLOCK = 0,          /* awb unlock */
    CAM_ENGINE_AWB_LOCK,                /* awb lock */
} CamEngineAwbLockStatus_t;

/*****************************************************************************/
/**
 * @brief   Auto-White-Balance mode.
 *
 *****************************************************************************/
typedef enum CamEngineAwbMode_e {
    CAM_ENGINE_AWB_MODE_INVALID = 0,    /**< invalid mode (only for initialization) */
    CAM_ENGINE_AWB_MODE_MANUAL  = 1,    /**< manual mode */
    CAM_ENGINE_AWB_MODE_AUTO    = 2,    /**< run auto mode */
    CAM_ENGINE_AWB_MODE_MAX
} CamEngineAwbMode_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the chrominace output range in the
 *          CamerIC color processing unit.
 *
 *****************************************************************************/
typedef enum CamerIcCprocChrominanceRangeOut_e {
    CAMERIC_CPROC_CHROM_RANGE_OUT_INVALID       = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_CPROC_CHROM_RANGE_OUT_BT601_LIMIT   = 1,    /**< CbCr_out clipping range 16..240 according to ITU-R BT.601 standard */
    CAMERIC_CPROC_CHROM_RANGE_OUT_BT601_FULL    = 2,    /**< full UV_out clipping range 0..255 according to ITU-R BT.601 standard */
    CAMERIC_CPROC_CHROM_RANGE_OUT_REC709_LIMIT  = 3,    /**< CbCr_out clipping range 16..240 according to ITU-R REC.709 standard */
    CAMERIC_CPROC_CHROM_RANGE_OUT_REC709_FULL   = 4,    /**< full UV_out clipping range 0..255 according to ITU-R REC.709 standard */
    CAMERIC_CPROC_CHROM_RANGE_OUT_MAX                   /**< upper border (only for an internal evaluation) */
} CamerIcCprocChrominaceRangeOut_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the luminance output range in the
 *          CamerIC color processing unit.
 *
 *****************************************************************************/
typedef enum CamerIcCprocLuminanceRangeOut_e {
    CAMERIC_CPROC_LUM_RANGE_OUT_INVALID         = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_CPROC_LUM_RANGE_OUT_BT601_LIMIT     = 1,    /**< Y_out clipping range 16..235; offset of 16 is added to Y_out according to ITU-R BT.601 standard */
    CAMERIC_CPROC_LUM_RANGE_OUT_BT601_FULL      = 2,    /**< Y_out clipping range 0..255; no offset is added to Y_out according to ITU-R BT.601 standard */
    CAMERIC_CPROC_LUM_RANGE_OUT_REC709_LIMIT    = 3,    /**< Y_out clipping range 16..235; offset of 16 is added to Y_out according to ITU-R REC.709 standard */
    CAMERIC_CPROC_LUM_RANGE_OUT_REC709_FULL     = 4,    /**< Y_out clipping range 0..255; no offset is added to Y_out according to ITU-R REC.709 standard */
    CAMERIC_CPROC_LUM_RANGE_OUT_MAX                     /**< upper border (only for an internal evaluation) */
} CamerIcCprocLuminanceRangeOut_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the luminance input range in the
 *          CamerIC color processing unit.
 *
 *****************************************************************************/
typedef enum CamerIcCprocLuminanceRangeIn_e {
    CAMERIC_CPROC_LUM_RANGE_IN_INVALID          = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_CPROC_LUM_RANGE_IN_BT601_LIMIT      = 1,    /**< Y_in range 64..940 according to ITU-R BT.601 standard; offset of 64 will be subtracted from Y_in */
    CAMERIC_CPROC_LUM_RANGE_IN_BT601_FULL       = 2,    /**< Y_in full range 0..1023 according to ITU-R BT.601 standard; no offset will be subtracted from Y_in */
    CAMERIC_CPROC_LUM_RANGE_IN_REC709_LIMIT     = 3,    /**< Y_in range 64..940 according to ITU-R REC.709 standard; offset of 64 will be subtracted from Y_in */
    CAMERIC_CPROC_LUM_RANGE_IN_REC709_FULL      = 4,    /**< Y_in full range 0..1023 according to ITU-R REC.709 standard; no offset will be subtracted from Y_in */
    CAMERIC_CPROC_LUM_RANGE_IN_MAX                      /**< upper border (only for an internal evaluation) */
} CamerIcCprocLuminanceRangeIn_t;

/*****************************************************************************/
/**
 * @brief   chrominace output brightness range.
 *
 *****************************************************************************/
#define CAMERIC_CPROC_BRIGHTNESS_MAX          127.0f
#define CAMERIC_CPROC_BRIGHTNESS_MIN          -127.0f

/*****************************************************************************/
/**
 * @brief   chrominace output hue range.
 *
 *****************************************************************************/
#define CAMERIC_CPROC_HUE_MAX                 89.0f
#define CAMERIC_CPROC_HUE_MIN                 -90.0f

/******************************************************************************/
/**
 * @brief   Structure to configure the color processing module
 *
 * @note    This structure needs to be converted to driver structure
 *
 *****************************************************************************/
typedef struct CamEngineCprocConfig_s {
    CamerIcCprocChrominaceRangeOut_t    ChromaOut;      /**< configuration of color processing chrominance pixel clipping range at output */
    CamerIcCprocLuminanceRangeOut_t     LumaOut;        /**< configuration of color processing luminance input range (offset processing) */
    CamerIcCprocLuminanceRangeIn_t      LumaIn;         /**< configuration of color processing luminance output clipping range */

    float                               contrast;       /**< contrast value to initially set */
    int8_t                              brightness;     /**< brightness value to initially set */
    float                               saturation;     /**< saturation value to initially set */
    float                               hue;            /**< hue value to initially set */
} CamEngineCprocConfig_t;


/******************************************************************************/
/**
 * @brief   Enumeration type to configure the IE working mode.
 *
 *****************************************************************************/
typedef enum CamerIcIeMode_e {
    CAMERIC_IE_MODE_INVALID                 = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_IE_MODE_GRAYSCALE               = 1,        /**< Set a fixed chrominance of 128 (neutral grey) */
    CAMERIC_IE_MODE_NEGATIVE                = 2,        /**< Luminance and chrominance data is being inverted */
    CAMERIC_IE_MODE_SEPIA                   = 3,        /**< Chrominance is changed to produce a historical like brownish image color */
    CAMERIC_IE_MODE_COLOR                   = 4,        /**< Converting picture to grayscale while maintaining one color component. */
    CAMERIC_IE_MODE_EMBOSS                  = 5,        /**< Edge detection, will look like an relief made of metal */
    CAMERIC_IE_MODE_SKETCH                  = 6,        /**< Edge detection, will look like a pencil drawing */
    CAMERIC_IE_MODE_SHARPEN                 = 7,        /**< Edge detection, will look like a sharper drawing */
    CAMERIC_IE_MODE_MAX                                 /**< upper border (only for an internal evaluation) */
} CamerIcIeMode_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the IE working range.
 *
 *****************************************************************************/
typedef enum CamerIcIeRange_e {
    CAMERIC_IE_RANGE_INVALID                = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_IE_RANGE_BT601                  = 1,        /**< pixel value range accoring to BT.601 */
    CAMERIC_IE_RANGE_FULL_RANGE             = 2,        /**< YCbCr full range 0..255 */
    CAMERIC_IE_RANG_MAX                                 /**< upper border (only for an internal evaluation) */
} CamerIcIeRange_t;

/******************************************************************************/
/**
 * @brief   Enumeration type to configure the color selection effect
 *
 *****************************************************************************/
typedef enum CamerIcIeColorSelection_e {
    CAMERIC_IE_COLOR_SELECTION_INVALID      = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_IE_COLOR_SELECTION_RGB          = 1,        /**< red, green and blue */
    CAMERIC_IE_COLOR_SELECTION_B            = 2,        /**< blue */
    CAMERIC_IE_COLOR_SELECTION_G            = 3,        /**< green */
    CAMERIC_IE_COLOR_SELECTION_GB           = 4,        /**< green and blue */
    CAMERIC_IE_COLOR_SELECTION_R            = 5,        /**< red */
    CAMERIC_IE_COLOR_SELECTION_RB           = 6,        /**< red and blue */
    CAMERIC_IE_COLOR_SELECTION_RG           = 7,        /**< red and green */
    CAMERIC_IE_COLOR_SELECTION_MAX                      /**< upper border (only for an internal evaluation) */
} CamerIcIeColorSelection_t;

/******************************************************************************/
/**
 * @brief   Structure to configure the Image Effects module
 *
 *****************************************************************************/
typedef struct CamerIcIeConfig_s {
    CamerIcIeMode_t                     mode;           /**< working mode (see @ref CamerIcIeMode_e) */
    CamerIcIeRange_t                    range;          /**< working range (see @ref CamerIcIeRange_e) */

    union ModeConfig_u {
        struct Sepia_s {                                /**< active when sepia effect */
            uint8_t                     TintCb;
            uint8_t                     TintCr;
        } Sepia;

        struct ColorSelection_s {                       /**< active when color selection effect */
            CamerIcIeColorSelection_t   col_selection;
            uint8_t                     col_threshold;
        } ColorSelection;

        struct Emboss_s {                               /**< active when emboss effect */
            int8_t                      coeff[9];
        } Emboss;

        struct Sketch_s {                               /**< active when sketch effect */
            int8_t                      coeff[9];
        } Sketch;

        struct Sharpen_s {                              /**< active when sharpen */
            uint8_t                     factor;         /**< sharpen factor */
            uint8_t                     threshold;      /**< corring threshold */
            int8_t                      coeff[9];       /**< convolution coefficients */
        } Sharpen;
    } ModeConfig;
} CamerIcIeConfig_t;

#endif  // _CAMERA_DEVICE_SENSOR_DEFS_H_
