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
 * @file hal_mockup.h
 *
 * @brief   MockedUp variant of Hardware Abstraction Layer
 *
 *          Exports the mockup version of the HAL API's inline functions. You could
 *          use it for your PC implementation to check general interaction of your
 *          code with the HAL.
 * @note    Do not include directly! Include hal_api.h instead with HAL_MOCKUP defined.
 *
 *****************************************************************************/

#ifndef __HAL_MOCKUP_H__
#define __HAL_MOCKUP_H__

#ifdef __cplusplus
extern "C"
{
#endif


/******************************************************************************
 * HAL device IDs
 *****************************************************************************/
#define HAL_DEVID_OCP       0x00000001  //!< HAL internal use only
#define HAL_DEVID_MARVIN    0x00000002  //!< MARVIN.*
#define HAL_DEVID_VDU       0x00000004  //!< VDU.clk + VDU.ocpclk
#define HAL_DEVID_PCLK      0x00000008  //!< VDU.pclk
#define HAL_DEVID_I2C_0     0x00000010  //!< HAL internal use only
#define HAL_DEVID_I2C_1     0x00000020  //!< HAL internal use only
#define HAL_DEVID_I2C_2     0x00000040  //!< HAL internal use only
#define HAL_DEVID_CAMREC_1  0x00000080  //!< CAMREC1, not neccessarily the REC that CAM1 is hooked up to; see @ref HAL_DEVID_CAM_1_REC instead
#define HAL_DEVID_INTERNAL  0x000000ff  //!< just internal devices included

#define HAL_DEVID_CAM_1     0x10000000  //!< CAM1
#define HAL_DEVID_CAMPHY_1  0x20000000  //!< CAMPHY1, not neccessarily the PHY that CAM1 is hooked up to; see @ref HAL_DEVID_CAM_1_PHY instead
#define HAL_DEVID_EXTERNAL  0x30000000  //!< just external devices included

#define HAL_DEVID_ALL       (HAL_DEVID_INTERNAL | HAL_DEVID_EXTERNAL) //!< all devices included


/******************************************************************************
 * HAL device base addresses
 *****************************************************************************/
// HalRegs:
#define HAL_BASEADDR_MARVIN    0x00000000 //!< Base address of MARVIN module.
#define HAL_BASEADDR_MARVIN_2  0x00010000 //!< Base address of MARVIN module of 2nd channel.
#define HAL_BASEADDR_MIPI_1    0x00000000 //!< Base address of MIPI module.
#define HAL_BASEADDR_MIPI_2    0x00010000 //!< Base address of MIPI module of 2nd channel.
#define HAL_BASEADDR_VDU       0x00008000 //!< Base address of VDU module.

// HalSysRegs:
#define HAL_BASEADDR_SYSCTRL   0x00000000 //!< HAL internal use only
#define HAL_BASEADDR_I2C_0     0x00001000 //!< HAL internal use only
#define HAL_BASEADDR_I2C_1     0x00001800 //!< HAL internal use only
#define HAL_BASEADDR_I2C_2     0x00000800 //!< HAL internal use only


/******************************************************************************
 * HAL device base region
 *****************************************************************************/
// HalRegs:
#define HAL_BASEREGION_MARVIN    0 //!< Base region of MARVIN module(s).
#define HAL_BASEREGION_MIPI      0 //!< Base region of MIPI module(s).
#define HAL_BASEREGION_VDU       0 //!< Base region of VDU module.

// HalSysRegs:
#define HAL_BASEREGION_SYSCTRL   2 //!< HAL internal use only
#define HAL_BASEREGION_I2C       2 //!< HAL internal use only


/******************************************************************************
 * HAL I2C bus location
 *****************************************************************************/
#define HAL_I2C_BUS_CAM_1       0 //!< Num of I2C bus CAM1 is connected to
#define HAL_I2C_BUS_CAM_2       1 //!< Num of I2C bus CAM2 is connected to
#define HAL_I2C_BUS_HDMI_TX     2 //!< Num of I2C bus HDMI TX is connected to
#define HAL_I2C_BUS_CAMPHY_1    0 //!< Num of I2C bus CAMPHY1 is connected to
#define HAL_I2C_BUS_CAMPHY_2    1 //!< Num of I2C bus CAMPHY1 is connected to


/******************************************************************************
 * HAL CAM to PHY/REC mapping
 *****************************************************************************/
#define HAL_DEVID_CAM_1_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM1 is connected to
#define HAL_DEVID_CAM_2_PHY     HAL_DEVID_CAMPHY_1 //!< DEVID of CAMPHY CAM2 is connected to
#define HAL_DEVID_CAM_1_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM1 is connected to
#define HAL_DEVID_CAM_2_REC     HAL_DEVID_CAMREC_1 //!< DEVID of CAMREC CAM2 is connected to


/******************************************************************************
 * HalReadReg()
 *****************************************************************************/
INLINE uint32_t HalReadReg( HalHandle_t HalHandle, uint32_t reg_address )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    return 0x12345678;
}


/******************************************************************************
 * HalWriteReg()
 *****************************************************************************/
INLINE void HalWriteReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    (void) reg_address;
    (void) value;
}


/******************************************************************************
 * HalReadMaskedReg()
 *****************************************************************************/
INLINE uint32_t HalReadMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    uint32_t tmp_value = HalReadReg( HalHandle, reg_address );
    return HalGetMaskedValue( tmp_value, reg_mask, shift_mask );
}


/******************************************************************************
 * HalWriteMaskedReg()
 *****************************************************************************/
INLINE void HalWriteMaskedReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t reg_mask, uint32_t shift_mask, uint32_t value )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    uint32_t tmp_value = HalReadReg( HalHandle, reg_address );
    tmp_value = HalSetMaskedValue( tmp_value, reg_mask, shift_mask, value );
    HalWriteReg( HalHandle, reg_address, tmp_value );
}


/******************************************************************************
 * HalReadSysReg()
 *****************************************************************************/
INLINE uint32_t HalReadSysReg( HalHandle_t HalHandle, uint32_t reg_address )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    return 0x12345678;
}


/******************************************************************************
 * HalWriteSysReg()
 *****************************************************************************/
INLINE void HalWriteSysReg( HalHandle_t HalHandle, uint32_t reg_address, uint32_t value )
{
    (void) HalHandle;
    DCT_ASSERT(HalHandle != NULL);

    (void) reg_address;
    (void) value;
}


#ifdef __cplusplus
}
#endif

#endif /* __HAL_MOCKUP_H__ */
