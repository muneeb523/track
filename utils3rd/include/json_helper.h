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

#ifndef DEVELOPER_MEDIACONTROL_INCLUDE_JSON_HELPER_H_
#define DEVELOPER_MEDIACONTROL_INCLUDE_JSON_HELPER_H_

#include <string>
#include <typeinfo>
#include <functional>
#include <type_traits>

#include "json/json.h"

template<typename T>  // It's better to auto check type by compiler.
inline void readValueFromNode(const Json::Value& node, T& ret) {
    // int uint8_t int8_t uint16_t int16_t int32_t bool
    ret = static_cast<T>(node.asUInt64());
}

template< >
inline void readValueFromNode(const Json::Value& node, int& ret) {
    ret = node.asInt();
}

template< >
inline void readValueFromNode(const Json::Value& node, uint32_t& ret) {
    ret = node.asUInt();
}

template< >
inline void readValueFromNode(const Json::Value& node, int64_t& ret) {
    ret = node.asInt64();
}

template< >
inline void readValueFromNode(const Json::Value& node, bool& ret) {
    ret = node.asBool();
}

template< >
inline void readValueFromNode(const Json::Value& node, float& ret) {
    ret = node.asFloat();
}

template< >
inline void readValueFromNode(const Json::Value& node, double& ret) {
    ret = node.asDouble();
}

template< >
inline void readValueFromNode(const Json::Value& node, std::string& ret) {
    ret = node.asCString();
}

template<typename T>
void readValueByName(const Json::Value& node, const char* szName, T& ret) {
    Json::Value item = node[szName];
    if (!item.isNull())
        readValueFromNode(item, ret);
}

template<typename T>   // we should not write multi-functions for every array type of camera engine,
void readArrayFromNode(const Json::Value& node, const char* szName, T* array) {
    Json::Value curve = node[szName];
    if (curve.isArray()) {
        int i = 0;
        for (auto& item : curve) {
            readValueFromNode(item, array[i++]);
        }
    }
}

template<typename T>  // can be extend to float/double type.
void printIntArary(T* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

template<typename T>
void writeArrayToNode(const T *array, Json::Value& node, const char *section, int size) {
    for (int i = 0; i < size; i ++) {
        node[section][i] = array[i];
    }
}

#define JH_GET_TYPE(x) std::remove_reference<decltype((x))>::type
#define JH_READ_VAL(x, y, z) readValueByName<JH_GET_TYPE((x))>((y), (z), (x));
#define JH_READ_ARRAY(x, y, z) readArrayFromNode<JH_GET_TYPE((*z))>((x), (y), (z));

#define addArray(x, y, z) writeArrayToNode<JH_GET_TYPE((x)[0])>(x, y, z, sizeof(x)/sizeof((x)[0]));

#endif  // DEVELOPER_MEDIACONTROL_INCLUDE_JSON_HELPER_H_
