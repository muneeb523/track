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

#include <json/json.h>
#include <string>

#ifdef ANDROID
#include "../utils/tinyxml2/tinyxml2.h"
#else
#include <tinyxml2.h>
#endif

using namespace tinyxml2;

namespace camdev {

struct Element {
  Element(XMLDocument &document, std::string name = std::string());
  virtual ~Element();

  virtual void compose(XMLElement &);

  virtual void composeAttributes(XMLElement &);
  virtual void composeSubElements(XMLElement &);

  virtual void parse(XMLElement &);

  virtual void parseAttributes(XMLElement &);
  virtual void parseSubElements(XMLElement &);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            int16_t &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            int32_t &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            uint8_t &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            uint16_t &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            uint32_t &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            double &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            float &value);

  XMLElement &subElementGet(XMLElement &element, const char *pKey,
                            Json::Value &value);

  template <typename Func>
  XMLElement &subElementProc(XMLElement &element, const char *pKey, Func f) {
    XMLElement *pSubElement = nullptr;

    if (!(pSubElement = element.FirstChildElement(pKey))) {
      element.InsertEndChild(pSubElement = document.NewElement(pKey));
    }

    f(*pSubElement);

    return *pSubElement;
  }

  template <typename T>
  XMLElement &subElementSet(XMLElement &element, const char *pKey, T value) {
    XMLElement *pSubElement = nullptr;

    if (!(pSubElement = element.FirstChildElement(pKey))) {
      element.InsertEndChild(pSubElement = document.NewElement(pKey));
    }

    pSubElement->SetText(value);

    return *pSubElement;
  }

  XMLElement &subElementSetJson(XMLElement &element, const char *pKey,
                                Json::Value &value);

  XMLDocument &document;
  std::string name;
  int32_t level = 0;
};

} // namespace camdev
