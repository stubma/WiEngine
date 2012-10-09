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
#ifndef __wyUtils_android_h__
#define __wyUtils_android_h__

#if ANDROID

#include "wyTypes.h"
#include "wyUtils.h"
#include <jni.h>

/**
 * @class wyUtils_android
 *
 * \if English
 * Utilities only used in Android platform
 * \else
 * 仅面向于android平台的工具方法
 * \endif
 */
class wyUtils_android : public wyUtils {
public:
	/*
	 * type helper
	 */

	/**
	 * \if English
	 * Convert java WYBezierConfig object to native \link wyBezierConfig wyBezierConfig\endlink structure
	 *
	 * @param config java side WYBezierConfig object
	 * @return \link wyBezierConfig wyBezierConfig\endlink structure
	 * \else
	 * 把java的WYBeizerConfig对象转换成native端的\link wyBezierConfig wyBezierConfig\endlink结构
	 *
	 * @param config java的WYBeizerConfig对象
	 * @return \link wyBezierConfig wyBezierConfig结构\endlink
	 * \endif
	 */
	static wyBezierConfig to_wyBezierConfig(jobject config);

	/**
	 * \if English
	 * Convert java WYLagrangeConfig object to native \link wyLagrangeConfig wyLagrangeConfig\endlink structure
	 *
	 * @param config java side WYLagrangeConfig object
	 * @return \link wyLagrangeConfig wyLagrangeConfig\endlink structure
	 * \else
	 * 把java的WYLagrangeConfig对象转换成native端的\link wyLagrangeConfig wyLagrangeConfig\endlink结构
	 *
	 * @param config java的WYLagrangeConfig对象
	 * @return \link wyLagrangeConfig wyLagrangeConfig结构\endlink
	 * \endif
	 */
	static wyLagrangeConfig to_wyLagrangeConfig(jobject config);

	/**
	 * \if English
	 * Convert java WYHypotrochoidConfig object to native \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink structure
	 *
	 * @param config java side WYHypotrochoidConfig object
	 * @return \link wyHypotrochoidConfig wyHypotrochoidConfig\endlink structure
	 * \else
	 * 把java的WYHypotrochoidConfig对象转换成native端的\link wyHypotrochoidConfig wyHypotrochoidConfig\endlink结构
	 *
	 * @param config java的WYBeizerConfig对象
	 * @return \link wyBezierConfig wyBezierConfig结构\endlink
	 * \endif
	 */
	static wyHypotrochoidConfig to_wyHypotrochoidConfig(jobject config);

	/**
	 * \if English
	 * Convert java WYQuad2D object to native \link wyQuad2D wyQuad2D\endlink structure
	 *
	 * @param quad java side WYQuad2D object
	 * @return \link wyQuad2D wyQuad2D\endlink structure
	 * \else
	 * 把java的WYQuad2D对象转换成native端的\link wyQuad2D wyQuad2D\endlink结构
	 *
	 * @param quad java的WYQuad2D对象
	 * @return \link wyQuad2D wyQuad2D结构\endlink
	 * \endif
	 */
	static wyQuad2D to_wyQuad2D(jobject quad);

	/**
	 * \if English
	 * Convert java WYQuad3D object to native \link wyQuad3D wyQuad3D\endlink structure
	 *
	 * @param quad java side WYQuad3D object
	 * @return \link wyQuad3D wyQuad3D\endlink structure
	 * \else
	 * 把java的WYQuad3D对象转换成native端的\link wyQuad3D wyQuad3D\endlink结构
	 *
	 * @param quad java的WYQuad3D对象
	 * @return \link wyQuad3D wyQuad3D结构\endlink
	 * \endif
	 */
	static wyQuad3D to_wyQuad3D(jobject quad);

	/**
	 * \if English
	 * Convert java WYColor4B object to native \link wyColor4B wyColor4B\endlink structure
	 *
	 * @param color java side WYColor4B object
	 * @return \link wyColor4B wyColor4B\endlink structure
	 * \else
	 * 把java的WYColor4B对象转换成native端的\link wyColor4B wyColor4B\endlink结构
	 *
	 * @param color java的WYColor4B对象
	 * @return \link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	static wyColor4B to_wyColor4B(jobject color);

	/**
	 * \if English
	 * Convert java WYColor3B object to native \link wyColor3B wyColor3B\endlink structure
	 *
	 * @param color java side WYColor3B object
	 * @return \link wyColor3B wyColor3B\endlink structure
	 * \else
	 * 把java的WYColor3B对象转换成native端的\link wyColor3B wyColor3B\endlink结构
	 *
	 * @param color java的WYColor3B对象
	 * @return \link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	static wyColor3B to_wyColor3B(jobject color);

	/**
	 * \if English
	 * Convert java WYRect object to native \link wyRect wyRect\endlink structure
	 *
	 * @param rect java side WYRect object
	 * @return \link wyRect wyRect\endlink structure
	 * \else
	 * 把java的WYRect对象转换成native端的\link wyRect wyRect\endlink结构
	 *
	 * @param rect java的WYRect对象
	 * @return \link wyRect wyRect结构\endlink
	 * \endif
	 */
	static wyRect to_wyRect(jobject rect);

	/**
	 * \if English
	 * Convert java WYPoint object to native \link wyPoint wyPoint\endlink structure
	 *
	 * @param p java side WYPoint object
	 * @return \link wyPoint wyPoint\endlink structure
	 * \else
	 * 把java的WYPoint对象转换成native端的\link wyPoint wyPoint\endlink结构
	 *
	 * @param p java的WYPoint对象
	 * @return \link wyPoint wyPoint结构\endlink
	 * \endif
	 */
	static wyPoint to_wyPoint(jobject p);

	/**
	 * \if English
	 * Convert java WYSize object to native \link wySize wySize\endlink structure
	 *
	 * @param s java side WYSize object
	 * @return \link wySize wySize\endlink structure
	 * \else
	 * 把java的WYSize对象转换成native端的\link wySize wySize\endlink结构
	 *
	 * @param s java的WYSize对象
	 * @return \link wySize wySize结构\endlink
	 * \endif
	 */
	static wySize to_wySize(jobject s);

	/**
	 * \if English
	 * Copy info of native \link wyQuad2D wyQuad2D\endlink structure to java WYQuad2D object
	 *
	 * @param q native \link wyQuad2D wyQuad2D\endlink structure
	 * @param jq java side WYQuad2D object
	 * \else
	 * 把native端的\link wyQuad2D wyQuad2D\endlink结构内容复制到java端的WYQuad2D对象中
	 *
	 * @param q native端的\link wyQuad2D wyQuad2D结构\endlink
	 * @param jq java端的WYQuad2D对象
	 * \endif
	 */
	static void to_WYQuad2D(wyQuad2D& q, jobject jq);

	/**
	 * \if English
	 * Copy info of native \link wyQuad3D wyQuad3D\endlink structure to java WYQuad3D object
	 *
	 * @param q native \link wyQuad3D wyQuad3D\endlink structure
	 * @param jq java side WYQuad3D object
	 * \else
	 * 把native端的\link wyQuad3D wyQuad3D\endlink结构内容复制到java端的WYQuad3D对象中
	 *
	 * @param q native端的\link wyQuad3D wyQuad3D结构\endlink
	 * @param jq java端的WYQuad3D对象
	 * \endif
	 */
	static void to_WYQuad3D(wyQuad3D& q, jobject jq);

	/**
	 * \if English
	 * Copy info of native \link wyRect wyRect\endlink structure to java WYRect object
	 *
	 * @param r native \link wyRect wyRect\endlink structure
	 * @param jr java side WYRect object
	 * \else
	 * 把native端的\link wyRect wyRect\endlink结构内容复制到java端的WYRect对象中
	 *
	 * @param r native端的\link wyRect wyRect结构\endlink
	 * @param jr java端的WYRect对象
	 * \endif
	 */
	static void to_WYRect(wyRect r, jobject jr);

	/**
	 * \if English
	 * Copy info of native \link wyPoint wyPoint\endlink structure to java WYPoint object
	 *
	 * @param p native \link wyPoint wyPoint\endlink structure
	 * @param jp java side WYPoint object
	 * \else
	 * 把native端的\link wyPoint wyPoint\endlink结构内容复制到java端的WYPoint对象中
	 *
	 * @param p native端的\link wyPoint wyPoint结构\endlink
	 * @param jp java端的WYPoint对象
	 * \endif
	 */
	static void to_WYPoint(wyPoint p, jobject jp);

	/**
	 * \if English
	 * Copy info of native \link wyDimension wyDimension\endlink structure to java WYDimension object
	 *
	 * @param d native \link wyDimension wyDimension\endlink structure
	 * @param jd java side WYDimension object
	 * \else
	 * 把native端的\link wyDimension wyDimension\endlink结构内容复制到java端的WYDimension对象中
	 *
	 * @param d native端的\link wyDimension wyDimension结构\endlink
	 * @param jd java端的WYDimension对象
	 * \endif
	 */
	static void to_WYDimension(wyDimension d, jobject jd);

	/**
	 * \if English
	 * Copy info of native \link wySize wySize\endlink structure to java WYSize object
	 *
	 * @param s native \link wySize wySize\endlink structure
	 * @param js java side WYSize object
	 * \else
	 * 把native端的\link wySize wySize\endlink结构内容复制到java端的WYSize对象中
	 *
	 * @param s native端的\link wySize wySize结构\endlink
	 * @param js java端的WYSize对象
	 * \endif
	 */
	static void to_WYSize(wySize s, jobject js);

	/**
	 * \if English
	 * Copy info of native \link wyAffineTransform wyAffineTransform\endlink structure to java WYAffineTransform object
	 *
	 * @param t native \link wyAffineTransform wyAffineTransform\endlink structure
	 * @param jt java side WYAffineTransform object
	 * \else
	 * 把native端的\link wyAffineTransform wyAffineTransform\endlink结构内容复制到java端的WYAffineTransform对象中
	 *
	 * @param t \link wyAffineTransform wyAffineTransform结构\endlink
	 * @param jt WYAffineTransform对象
	 * \endif
	 */
	static void to_WYAffineTransform(wyAffineTransform t, jobject jt);

	/**
	 * \if English
	 * Copy info of native \link wyColor3B wyColor3B\endlink structure to java WYColor3B object
	 *
	 * @param color native \link wyColor3B wyColor3B\endlink structure
	 * @param jColor java side WYColor3B object
	 * \else
	 * 把native端的native \link wyColor3B wyColor3B\endlink结构内容复制到java端的WYColor3B对象中
	 *
	 * @param color native端的\link wyColor3B wyColor3B\endlink
	 * @param jColor java端的WYColor3B对象
	 * \endif
	 */
	static void to_WYColor3B(wyColor3B color, jobject jColor);

	/**
	 * \if English
	 * Copy info of native \link wyColor4B wyColor4B\endlink structure to java WYColor4B object
	 *
	 * @param color native \link wyColor4B wyColor4B\endlink structure
	 * @param jColor java side WYColor4B object
	 * \else
	 * 把native端的wyColor4B结构内容复制到java端的WYColor4B对象中
	 *
	 * @param color native端的\link wyColor4B wyColor4B\endlink
	 * @param jColor java端的WYColor4B对象
	 * \endif
	 */
	static void to_WYColor4B(wyColor4B color, jobject jColor);

	/**
	 * \if English
	 * Put all entries in a \link wyHashSet wyHashSet\endlink into a java Map object.
	 * The hash object in \link wyHashSet wyHashSet\endlink must be \link wyKeyValueHash wyKeyValueHash\endlink
	 *
	 * @param set \link wyHashSet wyHashSet\endlink
	 * @param map java side map object, must be subclass of Map
	 * \else
	 * 把一个\link wyHashSet wyHashSet\endlink里的所有项放到一个java的Map子类对象中.
	 * \link wyHashSet wyHashSet\endlink中项目的哈希对象必须是\link wyKeyValueHash wyKeyValueHash\endlink对象
	 *
	 * @param set \link wyHashSet wyHashSet\endlink
	 * @param map java端的Map子类对象
	 * \endif
	 */
	static void to_Map(wyHashSet* set, jobject map);

	/**
	 * Convert java string to C string, caller must release returned string.
	 * If convert failed, returns NULL
	 */
	static const char* to_CString(jstring js);

	/**
	 * \if English
	 * Iteration function of to_Map
	 * \else
	 * to_Map方法的枚举方法
	 * \endif
	 */
	static bool putIntoMap(void* elt, void* data);

	/*
	 * interoperation with java layer
	 */

	// for activity starting
	static jobject newIntent(const char* activityName);
	static jobject newIntentByAction(const char* action);
	static void putBooleanExtra(jobject intent, const char* name, bool value);
	static void putByteExtra(jobject intent, const char* name, unsigned char value);
	static void putCharExtra(jobject intent, const char* name, unsigned short value);
	static void putDoubleExtra(jobject intent, const char* name, double value);
	static void putFloatExtra(jobject intent, const char* name, float value);
	static void putIntExtra(jobject intent, const char* name, int value);
	static void putStringExtra(jobject intent, const char* name, const char* value);
	static void putLongExtra(jobject intent, const char* name, long value);
	static void putShortExtra(jobject intent, const char* name, short value);
	static void putParcelableExtra(jobject intent, const char* name, jobject value);
	static void startActivity(jobject intent);
	static void sendBroadcast(jobject intent);

	/**
	 * \if English
	 * Check whether application has an explicit permission
	 *
	 * @param perm permission name
	 * @return true if it has
	 * \else
	 * 检查应用是否具有某个权限
	 *
	 * @param perm 权限名称
	 * @return true表示具有该权限
	 * \endif
	 */
	static bool hasPermission(const char* perm);
};

#endif // #if ANDROID

#endif // __wyUtils_android_h__
