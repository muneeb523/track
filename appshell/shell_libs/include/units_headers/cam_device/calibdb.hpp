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
 * @file    calibtreewidget.h
 *
 *
 *****************************************************************************/
#pragma once

#include <cam_calibdb/cam_calibdb_api.h>
#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

class CalibDb {
public:
  ~CalibDb();

  CamCalibDbHandle_t GetCalibDbHandle(void) { return (hCalibDb); }

  int32_t install(std::string &);
  int32_t uninstall();

private:
  typedef int32_t (CalibDb::*parseCellContent)(const XMLElement *, void *);

  // parse helper
  int32_t parseEntryCell(const XMLElement *, int32_t, parseCellContent,
                         void * = NULL);

  // parse Header
  int32_t parseEntryHeader(const XMLElement *, void * = NULL);
  int32_t parseEntryResolution(const XMLElement *, void * = NULL);

  // parse Sensor
  int32_t parseEntrySensor(const XMLElement *, void * = NULL);

  // parse Sensor-AWB
  int32_t parseEntryAwb(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbGlobals(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIllumination(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIlluminationAlsc(const XMLElement *, void * = NULL);
  int32_t parseEntryAwbIlluminationAcc(const XMLElement *, void * = NULL);

  // parse Sensor-AEC
  int32_t parseEntryAec(const XMLElement *, void * = NULL);
  int32_t parseEntryAecEcm(const XMLElement *, void * = NULL);
  int32_t parseEntryAecEcmPriorityScheme(const XMLElement *, void * = NULL);

  // parse Sensor-LSC
  int32_t parseEntryLsc(const XMLElement *, void * = NULL);

  // parse Sensor-CC
  int32_t parseEntryCc(const XMLElement *, void * = NULL);

  // parse Sensor-BLS
  int32_t parseEntryBls(const XMLElement *, void * = NULL);

  // parse Sensor-CAC
  int32_t parseEntryCac(const XMLElement *, void * = NULL);

  // parse Sensor-DPF
  int32_t parseEntryDpf(const XMLElement *, void * = NULL);

  // parse Sensor-DPCC
  int32_t parseEntryDpcc(const XMLElement *, void * = NULL);
  int32_t parseEntryDpccRegisters(const XMLElement *, void * = NULL);

  int32_t parseEntryHdr(const XMLElement *, void * = NULL);

  // parse System
  int32_t parseEntrySystem(const XMLElement *, void * = NULL);

private:
  CamCalibDbHandle_t hCalibDb = 0;
};
