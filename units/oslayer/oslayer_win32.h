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
 * Module    : Operating System Abstraction Layer
 *
 * Hierarchy :
 *
 * Purpose   : Encapsulates and abstracts services from different operating
 *             system, including user-mode as well as kernel-mode services.
 ******************************************************************************/
#ifdef WIN32

#include <windows.h>
#include <ebase/types.h>


#ifdef __cplusplus
extern "C"
{
#endif



#ifdef WIN32_KERNEL
#define OSLAYER_KERNEL
#endif


typedef int32_t (*osThreadFunc)(void *);
typedef int32_t (*osIsrFunc)(void *);
typedef int32_t (*osDpcFunc)(void *);


#ifdef OSLAYER_EVENT
/*****************************************************************************/
/*  @brief  Event object (Win32 Version) of OS Abstraction Layer */
typedef struct _osEvent
{
#ifdef OSLAYER_KERNEL
    KEVENT event;
#else
    HANDLE handle;
#endif
} osEvent;
#endif /* OSLAYER_EVENT */


#ifdef OSLAYER_MUTEX
/*****************************************************************************/
/*  @brief  Mutex object (Win32 Version) of OS Abstraction Layer */
typedef struct _osMutex
{
#ifdef OSLAYER_KERNEL
    KMUTEX mutex;
#else
    CRITICAL_SECTION sCritSection;
#endif
} osMutex;
#endif /* OSLAYER_MUTEX */


#ifdef OSLAYER_SEMAPHORE
/*****************************************************************************/
/*  @brief  Semaphore object (Win32 Version) of OS Abstraction Layer */
typedef struct _osSemaphore
{
#ifdef OSLAYER_KERNEL
    KSEMAPHORE sem;
#else
    HANDLE handle;
#endif
} osSemaphore;
#endif /* OSLAYER_SEMAPHORE */


#ifdef OSLAYER_THREAD
/*****************************************************************************/
/*  @brief  Thread object (Win32 Version) of OS Abstraction Layer */
typedef struct _osThread
{
#ifdef OSLAYER_KERNEL
    KTHREAD handle;
#else
    HANDLE handle;
    osMutex access_mut;
    int32_t wait_count;
#endif
} osThread;
#endif /* OSLAYER_THREAD */


#ifdef OSLAYER_MISC
#ifdef OSLAYER_KERNEL
/*****************************************************************************/
/*  @brief  Spin Lock object (Win32 Kernel Version only) of OS Abstraction */
/*          Layer */
typedef struct _osSpinLock
{
    KSPIN_LOCK lock;
} osSpinLock;
#endif /* OSLAYER_KERNEL */
#endif /* OSLAYER_MISC   */


#ifdef __cplusplus
}
#endif



#endif /* WIN32 */
