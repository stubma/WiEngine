/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyAssetAdapter_h__
#define __wyAssetAdapter_h__

#include <stddef.h>
#include <sys/types.h>

typedef unsigned short char16_t;
typedef unsigned int char32_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 释放资源
 */
void deinit();

/**
 * 设置java环境对象
 *
 * @param env JNIEnv类型的指针
 */
void setEnv(void* env);

/**
 * 设置一个jobject的context
 *
 * @param context java端的context对象
 */
void setContext(void* context);

/**
 * 设置屏幕的density
 *
 * @param density 屏幕密度
 */
void setDensity(float density);

/**
 * 设置缩放模式
 *
 * @param mode 缩放模式
 */
void setScaleMode(int mode);

/**
 * 根据路径得到Asset对象
 *
 * @param path 资源在assets目录下的路径
 * @return Asset对象指针
 */
void* getAsset(const char* path);

/**
 * 根据资源id获得Asset对象指针
 *
 * @param id 资源id
 * @param scale 用于返回缩放比例，这个比例从资源的density中获得，如果资源的density
 * 		是160, 而当前屏幕是hdpi(即240)，则scale会等于1.5. 这个参数一般只对图片有用，
 * 		如果不需要，可以传NULL
 * @return Asset对象指针，这是android内部的对象
 */
void* getAssetByResId(int id, float* scale);

/**
 * 得到asset的数据缓冲区
 *
 * @param asset Asset对象指针
 * @return 缓冲区数据指针
 */
void* getAssetBuffer(void* asset);

/**
 * 得到asset的数据长度
 *
 * @param asset Asset对象指针
 * @return 数据长度
 */
int getAssetLength(void* asset);

/**
 * 得到asset的未读数据长度
 *
 * @param asset Asset对象指针
 * @return 未读数据长度
 */
int getAssetRemainingLength(void* asset);

/**
 * 读取Asset数据
 *
 * @param asset Asset对象指针
 * @param buffer 存放数据的缓冲区
 * @param length 缓冲区长度
 * @return 实际读取的字节数
 */
ssize_t readAsset(void* asset, char* buffer, size_t length);

/**
 * 在Asset中定位
 *
 * @param asset Asset对象指针
 * @param offset 偏移
 * @param mode 定位模式
 * @return 定位后的绝对位置
 */
int seekAsset(void* asset, int offset, int mode);

/**
 * 关闭Asset, 关闭之后, 该asset将被释放
 *
 * @param asset Asset对象指针
 */
void closeAsset(void* asset);

/**
 * 获得某个资源文件的文件描述符, 偏移以及长度等数据
 *
 * @param resId 资源文件id
 * @param outFD 用来返回文件描述符
 * @param outOffset 用来返回文件偏移
 * @param outLength 用来返回文件长度
 * @param outScale 用于返回缩放比例，这个比例从资源的density中获得，如果资源的density
 * 		是160, 而当前屏幕是hdpi(即240)，则scale会等于1.5. 这个参数一般只对图片有用，
 * 		如果不需要，可以传NULL
 */
void getResFD(int resId, size_t* outFD, size_t* outOffset, size_t* outLength, float* outScale);

/**
 * 获得某个asset的文件描述符
 *
 * @param path asset文件路径
 * @param outFD 用来返回文件描述符
 * @param outOffset 用来返回文件偏移
 * @param outLength 用来返回文件长度
 */
void getAssetFD(const char* path, size_t* outFD, size_t* outOffset, size_t* outLength);

/**
 * 把一个utf-16字符串转换为utf-8字符串
 *
 * @param s16 utf-16编码的字符串
 * @return utf-8编码的字符串
 */
const char* utf16toutf8(const char16_t* s16);

/**
 * 把一个utf-8字符串转换为utf-16字符串
 *
 * @param s16 utf-8编码的字符串
 * @return utf-16编码的字符串
 */
const char16_t* toUTF16(const char* s8);

/**
 * Convert a wide char string to utf-8 encoded string. However, wchar_t
 * doesn't have same size in different platform.
 *
 * @param ws wide char string
 * @return utf-8 encoded string, caller should release it
 */
const char* wctoutf8(const wchar_t* ws);

/**
 * List all files, no matter file or directory, in an assets folder
 *
 * @param path relative path in assets folder
 * @param outLen it returns the size of returned string array
 * @param pattern file name pattern, or NULL if no pattern
 * @return a file name array which should be released by caller
 */
const char** listAssetFiles(const char* path, size_t* outLen, const char* pattern);

#ifdef __cplusplus
}
#endif

#endif // __wyAssetAdapter_h__
