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
 * @file isi_priv.h
 *
 * @brief
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup isi_priv
 * @{
 *
 */
#ifndef __ISI_PRIV_H__
#define __ISI_PRIV_H__

#ifdef ISI_LITE
#include "vsi_type.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "isi_iss.h"

/******************************************************************************
* TYPEDEFS
******************************************************************************/

/*****************************************************************************/
/**
 *          IsiSensorContext_t
 *
 * @brief   abstract class of a sensor context
 *
 */
/*****************************************************************************/
typedef struct IsiSensorContext_s
{
    uint8_t         SensorId;
#ifdef ISI_LITE
    uint8_t         I2cBusNum;           /**< The I2C bus the sensor is connected to. */
    uint16_t        SlaveAddress;        /**< The I2C slave addr the sensor is configured to. */
    uint32_t        SensorInitAddr;
    uint16_t        SensorInitSize;
    uint8_t         NrOfAddressBytes;    /**< Number of Address-Bytes */
    uint8_t         NrOfDataBytes;       /**< Number of Data-Bytes */
#else
    int             fd;                  /**< /dev/v4l-subdev file description */
    HalHandle_t     HalHandle;           /**< Handle of HAL session to use. */
#endif

    IsiSensor_t     *pSensor;            /**< points to the sensor device */
} IsiSensorContext_t;

/******************************************************************************
* FUNCTIONS
******************************************************************************/


/*****************************************************************************/
/**
 *          IsiWriteRegister
 *
 * @brief   writes a given number of bytes to the image sensor device
 *
 * @param   handle              Handle to image sensor device
 * @param   RegAddress          register address
 * @param   data                data-bytes
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiWriteRegister
(
    IsiSensorHandle_t   handle,
    const uint32_t      RegAddress,
    const uint32_t      RegValue
);

/*****************************************************************************/
/**
 *          IsiI2cReadSensorRegister
 *
 * @brief   reads a given number of bytes from the image sensor device
 *
 * @param   handle              Handle to image sensor device
 * @param   RegAddress          register address
 * @param   data                pointer to data-bytes
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS
 * @retval  RET_WRONG_HANDLE
 * @retval  RET_NULL_POINTER
 *
 *****************************************************************************/
RESULT IsiI2cReadSensorRegister
(
    IsiSensorHandle_t   handle,
    const uint32_t      RegAddress,
    uint8_t             *pData
);

#ifdef __cplusplus
}
#endif

#endif /* __ISI_PRIV_H__ */
