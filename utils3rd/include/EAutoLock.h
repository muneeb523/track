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

#ifndef _VSI_3RDLIBS_INCLUDE_EAUTOLOCK_H_
#define _VSI_3RDLIBS_INCLUDE_EAUTOLOCK_H_

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

class ILock {
 public:
    virtual ~ILock() {}
    virtual void lock()  const = 0;
    virtual void unlock() const = 0;
};

class EMutex : public ILock {
 public:
    inline EMutex();
    inline virtual ~EMutex();
    inline virtual void lock() const;
    inline virtual void unlock() const;

 private:
    mutable pthread_mutex_t mMutex;
};

class EAutoLock {
 public:
    inline EAutoLock(ILock* lock);
    inline ~EAutoLock();

 private:
    ILock* mLock = NULL;
};

class ESignal {
 public:
    inline ESignal();
    inline virtual ~ESignal();
    inline void wait();
    inline bool waitMillSeconds(int ms);
    inline void post();

 private:
    sem_t sem;
};

EMutex::EMutex() {
    pthread_mutex_init(&mMutex, NULL);
}

EMutex::~EMutex() {
    pthread_mutex_destroy(&mMutex);
}

void EMutex::lock() const {
    pthread_mutex_lock(&mMutex);
}

void EMutex::unlock() const {
    pthread_mutex_unlock(&mMutex);
}

EAutoLock::EAutoLock(ILock* lock) : mLock(lock) {
    if (mLock != NULL) mLock->lock();
}

EAutoLock::~EAutoLock() {
    if (mLock != NULL) mLock->unlock();
}

ESignal::ESignal() {
    sem_init(&sem, 0, 0);
}

ESignal::~ESignal() {
    sem_destroy(&sem);
}

void ESignal::wait() {
    sem_wait(&sem);
}

bool ESignal::waitMillSeconds(int ms) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_nsec += ms*1000000;
    ts.tv_sec += ts.tv_nsec / 1000000000;
    ts.tv_nsec %= 1000000000;
    int ret = sem_timedwait(&sem, &ts);
    return ret == 0;
}

void ESignal::post() {
    sem_post(&sem);
}

#endif  // _VSI_3RDLIBS_INCLUDE_EAUTOLOCK_H_


