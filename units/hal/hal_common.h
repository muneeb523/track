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
 * @file hal_common.h
 *
 * @brief
 *
 *
 * @note
 *
 *****************************************************************************/

#ifndef __HAL_COMMON_H__
#define __HAL_COMMON_H__

#include <ebase/trace.h>
#include <ebase/dct_assert.h>
#include <oslayer/oslayer.h>


/** Interrupt handling mode switch.
  * If set to zero (0), the interrupt facilities built into the kernel driver
  * will not be used. Instead, the user-space application will poll for
  * interrupts by reading the masked interrupt status register repeatedly.
  * If set to one (1), the kernel driver will handle the interrupt requests by
  * the hardware. This is much more efficient, but requires the IRQ logic in the
  * hardware to work correctly. */
#define FPGA_USE_KERNEL_IRQ_HANDLING 0

/******************************************************************************
 * local macro definitions
 *****************************************************************************/
typedef enum HalIsrSrc_e
{
    eHalIsrSrcIspIrq         = 0x0000,
    eHalIsrSrcJpeStatusIrq,
    eHalIsrSrcJpeErrorIrq,
    eHalIsrSrcCamIcMiIrq,
    eHalIsrSrcCamIcMipiIrq,
    eHalIsrMax,
} HalIsrSrc_t;


typedef enum HalChId_s
{
    HAL_CH_ID0 = 0, //!<isp channel id 0.
    HAL_CH_ID1 = 1, //!<isp channel id 1.
    HAL_CH_NUM      //!<isp channel numbers.
}HalChId_e;



/******************************************************************************
 * local type definitions
 *****************************************************************************/
 #if defined ( HAL_ALTERA )

/* IRQ handle type. */
typedef struct _fpga_irq_handle {
#if FPGA_USE_KERNEL_IRQ_HANDLING
        int __dummy;
#else
        uint32_t mis_addr;
        uint32_t cis_addr;
        uint32_t timeout;
        volatile int cancel;
        osMutex poll_mutex;
#endif
} fpga_irq_handle_t;


#endif

/*****************************************************************************/
/**
 * @brief   handle to hal instance
 *****************************************************************************/
typedef void * HalHandle_t;

/*****************************************************************************/
/**
 * @brief   hal irq context
 *****************************************************************************/
struct HalIrqCtx_s                                  // note: a forward declaration was given in this file before!
{
    HalHandle_t         HalHandle;                  /**< hal handle this context belongs to; must be set by callee prior connection of irq! */
    uint32_t            misRegAddress;              /**< address of the masked interrupt status register (MIS); must be set by callee prior connection of irq! */
    uint32_t            icrRegAddress;              /**< address of the interrupt clear register (ICR); must be set by callee prior connection of irq! */

    osInterrupt         OsIrq;                      /**< os layer abstraction for the interrupt */
    uint32_t            misValue;                   /**< value of the MIS-Register */

#if defined ( HAL_ALTERA )
    fpga_irq_handle_t   AlteraIrqHandle;            /**< handle for multiple interrupt handler */
#endif

    HalIsrSrc_t   irq_src;

};

/*****************************************************************************/
/**
 * @brief   hal irq context
 *****************************************************************************/
typedef struct HalIrqCtx_s HalIrqCtx_t; // implicit forward declaration of struct HalIrqCtx_s


#endif /* __HAL_COMMON_H__ */
