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
#if WINDOWS

#ifndef __wyAndroidStrings_H__
#define __wyAndroidStrings_H__

#include "wyObject.h"

typedef unsigned char xmlChar;

/**
 * 解析Android的strings.xml文件, 用来支持将Android中的字符串资源id映射到一个字符串.
 * 这个类是为了方便重用Android原始文件而设计的
 */
class wyAndroidStrings {
private:
	/// android strings file map
	map<unsigned int, WY_STRING_MAP*>* m_files;

	/// string key list
	vector<const char*>* m_keyList;

private:
	/// get string map of a strings file
	WY_STRING_MAP* getEntry();

	// for xml parsing
	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);

protected:
	wyAndroidStrings();

public:
	virtual ~wyAndroidStrings();

	/// get singleton instance
	static wyAndroidStrings* getInstance();

	/// destroy singleton instance
	static void destroyInstance();

	/// get key index, i.e., the string resource id in windows
	int getKeyIndex(const char* key);

	/**
	 * add an android strings xml file
	 *
	 * @param fileName file relative path
	 * @param langId language code in ISO 639-1 standard
	 */
	void addStrings(const char* fileName, const char* langId);

	/**
	 * get a string by a key
	 *
	 * @param key string key
	 * @return string value
	 */
	const char* getString(const char* key);

	/**
	 * get a string by resource id, the resource id is actually an index in key list
	 *
	 * @param resId resource id
	 * @return string value
	 */
	const char* getString(int resId);
};

#endif

#endif // #if WINDOWS
