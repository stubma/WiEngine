/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyLayerInfo_h__
#define __wyLayerInfo_h__

#include <stdbool.h>
#include "wyHashSet.h"
#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WIENGINE_API wyLayerInfo {
	/**
	 * 层的名字
	 */
	char* name;

	/**
	 * 层的瓦片宽度
	 */
	int layerWidth;

	/**
	 * 层的瓦片高度
	 */
	int layerHeight;

	/**
	 * 网格数组
	 */
	int* tiles;

	/**
	 * 层是否可见
	 */
	bool visible;

	/**
	 * 层的透明度
	 */
	int alpha;

	/**
	 * 最小的网格id
	 */
	int minGid;

	/**
	 * 最大的网格id
	 */
	int maxGid;

	/**
	 * 层附加属性
	 */
	wyHashSet* properties;

	/**
	 * 层x偏移
	 */
	float offsetX;

	/**
	 * 层y偏移
	 */
	float offsetY;
} wyLayerInfo;

// create/destroy
WIENGINE_API wyLayerInfo* wyLayerInfoNew();
WIENGINE_API void wyLayerInfoDestroy(wyLayerInfo* info);

// property
WIENGINE_API void wyLayerInfoAddProperty(wyLayerInfo* info, const char* key, const char* value);
WIENGINE_API char* wyLayerInfoGetProperty(wyLayerInfo* info, const char* name);

#ifdef __cplusplus
}
#endif

#endif // __wyLayerInfo_h__
