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
