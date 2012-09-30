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
#ifndef __wyTypes_h__
#define __wyTypes_h__

#include "wyGlobal.h"
#include <stdint.h>
#if ANDROID
	#include <jni.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// basic types
typedef struct wyPoint { float x, y; } wyPoint;
typedef struct wyDimension { int x, y; } wyDimension;
typedef struct wySize { float width, height; } wySize;
typedef struct wyRect { float x, y, width, height; } wyRect;
typedef struct wyVertex3D { float x, y, z; } wyVertex3D;
typedef struct wyQuad3D {
	float bl_x, bl_y, bl_z;
	float br_x, br_y, br_z;
	float tl_x, tl_y, tl_z;
	float tr_x, tr_y, tr_z;
} wyQuad3D;
typedef struct wyQuad2D {
	// bottom left
	float bl_x, bl_y;

	// bottom right
	float br_x, br_y;

	// top left
	float tl_x, tl_y;

	// top right
	float tr_x, tr_y;
} wyQuad2D;
typedef struct wyAffineTransform { float a, b, c, d, tx, ty; } wyAffineTransform;
typedef struct wyBlendFunc { int src, dst; } wyBlendFunc;
typedef struct wyColor3B { unsigned char r, g, b; } wyColor3B;
typedef struct wyColor4B { unsigned char r, g, b, a; } wyColor4B;
typedef struct wyColor4F { float r, g, b, a; } wyColor4F;
typedef struct wyColorHSV { float h, s, v; } wyColorHSV;
typedef struct wyBezierConfig {
	// cubic or quadratic
	bool cubic;

	// start and end
	float startX, startY, endX, endY;

	// control point
	float cp1X, cp1Y, cp2X, cp2Y;
} wyBezierConfig;
typedef struct wyLagrangeConfig {
	// cubic or quadratic
	bool cubic;

	// start and end
	float startX, startY, endX, endY;

	// control point
	float cp1X, cp1Y, cp2X, cp2Y;

	// knot
	float t0, t1, t2, t3;
} wyLagrangeConfig;
typedef struct wyHypotrochoidConfig {
	// A hypotrochoid is a roulette traced by a point attached to a circle of radius r rolling around the inside of a fixed circle of radius R,
	// where the point is a distance d from the center of the interior circle.
	float R, r, d;

	// angle
	float startAngle, endAngle;

	// centre postion
	float centreX, centreY;

	// temp
	float deltaAngle, temp1, temp2;
} wyHypotrochoidConfig;

/**
 * @union wyUserData
 *
 * \if English
 * Represent a custom data which can be any type
 * \else
 * 一个可以代表任意类型的数据联合定义
 * \endif
 */
typedef union {
	bool b;
	char c;
	short s;
	int i;
	float f;
	double d;
	void* p;
#if ANDROID
	jobject jo;
#endif
} wyUserData;

/**
 * @typedef wyKeyValueHash
 *
 * \if English
 * Common hash object for a key value pair. Key and value are all C string.
 * \else
 * 通用的键值对哈希对象, 键和值都是C字符串
 * \endif
 */
typedef struct wyKeyValueHash {
	char* key;
	char* value;
} wyKeyValueHash;

/**
 * @typedef wyFontStyle
 *
 * 字体类型
 */
typedef enum {
	/// 正常字体
    NORMAL = 0,

    /// 粗体类型
    BOLD   = 0x01,

    /// 斜体类型
    ITALIC = 0x02,

    /// 粗斜体类型
    BOLD_ITALIC = 0x03
} wyFontStyle;

/**
 * @typedef wyPListTag
 *
 * plist文件的标签
 */
typedef enum {
	UNKNOWN_PLIST_TAG,
	DOCUMENT,
	TAG_PLIST,
	TAG_DICT,
	TAG_KEY,
	TAG_REAL,
	TAG_STRING,
	TAG_INTEGER,
	TAG_TRUE,
	TAG_FALSE,
	TAG_ARRAY
} wyPListTag;

// matrix
typedef float Matrix44[4][4];
typedef float Matrix14[1][4];

// string type
typedef unsigned short char16_t;
typedef unsigned int char32_t;

#ifdef __cplusplus
}
#endif

// other includes
#include "wyPVR.h"
#include "wyPoint.h"
#include "wyDimension.h"
#include "wySize.h"
#include "wyVertex3D.h"
#include "wyRect.h"
#include "wyQuad2D.h"
#include "wyQuad3D.h"
#include "wyColor4F.h"
#include "wyColor3B.h"
#include "wyColor4B.h"
#include "wyColorHSV.h"
#include "wyAffineTransform.h"
#include "wyBlendFunc.h"
#include "wyBezierConfig.h"
#include "wyLagrangeConfig.h"
#include "wyHypotrochoidConfig.h"
#include "wyPointList.h"

#endif // __wyTypes_h__
