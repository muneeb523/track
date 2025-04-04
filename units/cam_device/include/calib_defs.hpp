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


#define NAME_AE "ae"
#define NAME_AF "af"
#define NAME_AVS "avs"
#define NAME_AWB "awb"
#define NAME_BLS "bls"
#define NAME_DEGAMMA "degamma"
#define NAME_CAC "cac"
#define NAME_CLI "tuning"
#define NAME_CNR "cnr"
#define NAME_CPROC "cproc"
#define NAME_DMS "demosaic"
#define NAME_DNR3 "nr3d"
#define NAME_DPCC "dpcc"
#define NAME_DPF "dpf"
#define NAME_EE "ee"
#define NAME_GC "gc"
#define NAME_HDR "hdr"
#define NAME_IE "ie"
#define NAME_IMAGES "images"
#define NAME_INPUTS "inputs"
#define NAME_JPE "jpe"
#define NAME_LSC "lsc"
#define NAME_PATHS "paths"
#define NAME_SENSORS "sensors"
#define NAME_SIMP "simp"
#define NAME_WB "wb"
#define NAME_WDR "wdr"
#define NAME_DEHAZE "dehaze"
#define NAME_DEWARP "dewarp"
#define NAME_DNR2 "dnr2"
#define NAME_FILTER "filter"
#define NAME_EC "ec"


//Calibration related defs
#define ENABLE "enable"
#define ALGORITHM "algorithm"
#define ONESHOT "oneshot"
#define LENGTH  "length"

#define BYPASS "bypass"

#define AUTO "auto"
#define TABLE "table"
#define ADAPTIVE "adaptive"

#define USE_PARAMS "use.params"

#define DAMP_NUMBER_OF_INTERPOLATION_POINTS   "damp.number.of.interpolation.points"
#define DAMP_ACCELERATION "damp.acceleration"
#define DAMP_BASE_GAIN "damp.base.gain"
#define DAMP_FALL_OFF "damp.fall.off"
#define DAMP_THETA "damp.theta"

#define DAMPING "damping"
#define INDEX "index"
#define MODE "mode"

#define KEY_RED "red"
#define KEY_GREEN_B "green.b"
#define KEY_GREEN_R "green.r"
#define KEY_BLUE "blue"

#define CONFIG "config"
#define AFPS "afps"


#define FLICKER_PERIOD "flicker.period"
#define SCENE_EVALUATION_MODE "scene.evaluation.mode"
#define SCENE_ADAPTIVE "scene.adaptive"
#define SCENE_DISABLED "scene.disabled"
#define SCENE_FIX "scene.fix"
#define DAMPING_OVER "damping.over"
#define DAMPING_UNDER "damping.under"
#define SET_POINT "set.point"
#define TOLERANCE "tolerance"
#define WEIGHT "weight"

#define THRESHOLD_CHANNEL "threshold.tc"

#define MODE "mode"
#define THRESHOLD "threshold"
#define DIVISION_FACTOR "division.factor"

#define GRADIENT "gradient"
#define MINIMUM_BOUND "minimum.bound"
#define OFFSET "offset"
#define SIGMA_GREEN "sigma.green"
#define SIGMA_RED_BLUE "sigma.red.blue"

#define GAIN "gain"
#define HDR_RATIO "hdr.ratio"
#define INTEGRATION_TIME "integration.time"
#define CURVE "curve"

#define EXPOSURE_RATIO "exposure.ratio"
#define EXTENSION_BIT "extension.bit"
//#define RANGE_START_VALUE "range.start.value"
//#define VERY_SHORT_WEIGHT "very.short.weight"

#define MODE_CONFIG "mode.config"
#define RANGE "range"

//#define FILE "file"
#define IMAGE "image"

#define INDEX "index"
#define INPUT "input"
#define TYPE "type"

#define WIDTH "width"
#define HEIGHT "height"

#define STRENGTH "strength"
#define SIGMA "sigma"
#define DENOISE_PREGAMA_STRENGTH "denoise.pregama.strength"
#define DENOISE_STRENGTH "denoise.strength"

#define DELTA_FACTOR "delta.factor"
#define MOTION_FACTOR "motion.factor"

#define SHARPEN "sharpen"
#define DENOISE "denoise"
#define PREGAMMA "pregamma"
#define SPATIAL_DENOISE "spatial.denoise"
#define TEMPORA_DENOISE "temporal.denoise"

#define EDGE_GAIN "edge.gain"
#define UV_GAIN "uv.gain"
#define Y_GAIN_DOWN "ydown.gain"
#define Y_GAIN_UP "yup.gain"

#define HEIGHT "height"
#define INDEX "index"
#define LAYOUT "layout"
#define MODE "mode"
#define PATH "path"
#define WIDTH "width"

#define CALIB_FILE "calib.file"
#define DRV_FILE "driver.file"
#define EC "ec"
#define ENABLE "enable"
#define SENSOR "sensor"
#define TEST_PATTERN "test.pattern"

#define CC_MATRIX "cc.matrix"
#define CC_OFFSET "cc.offset"
#define WB_GAINS "wb.gains"

#define RED "red"
#define GREEN "green"
#define GREEN_B "green.b"
#define GREEN_R "green.r"
#define BLUE "blue"

#define MAX_GAIN "gain.max"
#define STRENGTH "strength"
#define STRENGTH_GLOBAL "strength.global"
#define ROWS "rows"

#define V1 "v1"
#define V2 "v2"
#define V3 "v3"

#define DY "d.y"
#define YM "y.m"

#define KEY_PX  "px"
#define KEY_X   "x"
#define KEY_Y   "y"

#define WDR3_DEFAULT_STRENGTH 128
#define WDR3_DEFAULT_GAIN_MAX 64
#define WDR3_DEFAULT_STRENGTH_GLOBAL 0
