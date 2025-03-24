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
 * @file xmltags.h
 *
 *****************************************************************************/
#pragma once

#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

class XmlTag {
public:
  enum TagType_e {
    TAG_TYPE_INVALID = 0,
    TAG_TYPE_CHAR,
    TAG_TYPE_DOUBLE,
    TAG_TYPE_STRUCT,
    TAG_TYPE_CELL,
    TAG_TYPE_MAX
  };

  XmlTag(const XMLElement *);

  int32_t size();
  const char *value();
  const char *valueToUpper();
  uint32_t valueToUInt();

  TagType_e type();
  bool isType(const TagType_e);

protected:
  const XMLElement *_pElement;
};

class XmlCellTag : public XmlTag {
public:
  XmlCellTag(const XMLElement *);

  int32_t Index();
};
