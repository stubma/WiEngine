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
#ifndef __wyJSONArray_h__
#define __wyJSONArray_h__

#include "wyJSONConfig.h"
#include "wyObject.h"
#include "wyGlobal.h"
#include "wyJSONObject.h"
#include "wyAssetOutputStream.h"

/**
 * @class wyJSONArray
 *
 * \if English
 * JSON object array
 * \else
 * json对象数组
 * \endif
 */
class JSON_API wyJSONArray : public wyObject {
private:
	/// value array
	vector<wyJSONObject::KeyValue>* m_array;

protected:
	wyJSONArray();

	/// cast an object to wyJSONArray, if obj is a wyJSONObject, then the
	/// object will be saved as first element in returned array
	static wyJSONArray* safeCast(wyObject* obj);

	/// release key value
	static void releaseKeyValue(wyJSONObject::KeyValue& kv);

public:
	virtual ~wyJSONArray();

	/**
	 * \if English
	 * Create an empty json array object
	 *
	 * @return json array object
	 * \else
	 * 创建一个空的json数组对象
	 *
	 * @return json数组对象
	 * \endif
	 */
	static wyJSONArray* make();

	/**
	 * \if English
	 * Parse a json memory string
	 *
	 * @param json json string in memory, must be in utf-8 encoding
	 * @param length byte length of \c json string
	 * @return json array object, if \c json is actually a json object then this json object is saved
	 *  	in the first element of array.
	 * \else
	 * 解析一段内存中的json字符串
	 *
	 * @param json 内存json字符串, 必须是utf-8编码
	 * @param length \c json字符串的字节长度
	 * @return json数组对象, 假如json串解析的结果是一个json对象, 则这个对象保存在数组的第一个也是唯一一个元素中
	 * \endif
	 */
	static wyJSONArray* make(const char* json, size_t length);

	/**
	 * \if English
	 * Parse a json file which is saved in res folder
	 *
	 * @param resId resource id of json file
	 * @return json array object, if \c json is actually a json object then this json object is saved
	 *  	in the first element of array.
	 * \else
	 * 解析一个保存在res文件夹下的json文件
	 *
	 * @param resId json文件的资源id
	 * @return json数组对象, 假如json串解析的结果是一个json对象, 则这个对象保存在数组的第一个也是唯一一个元素中
	 * \endif
	 */
	static wyJSONArray* make(int resId);

	/**
	 * \if English
	 * Parse a json file saved in assets or file system
	 *
	 * @param path path of json file
	 * @param isFile true means \c path is an absolute path in file system, or false means
	 * 		\c path is a relative path under assets
	 * @return json array object, if \c json is actually a json object then this json object is saved
	 *  	in the first element of array.
	 * \else
	 * 解析一个保存在assets下或文件系统中的json文件
	 *
	 * @param path json文件的路径
	 * @param isFile true表示\c path是一个文件系统的绝对路径, false表示\c path是一个assets下的相对路径
	 * @return json数组对象, 假如json串解析的结果是一个json对象, 则这个对象保存在数组的第一个也是唯一一个元素中
	 * \endif
	 */
	static wyJSONArray* make(const char* path, bool isFile = false);

	/**
	 * \if English
	 * Parse a json memory file
	 *
	 * @param mfsName memory file name of json file
	 * @return json array object, if \c json is actually a json object then this json object is saved
	 *  	in the first element of array.
	 * \else
	 * 解析一个json内存文件
	 *
	 * @param mfsName json文件的内存文件名称
	 * @return json数组对象, 假如json串解析的结果是一个json对象, 则这个对象保存在数组的第一个也是唯一一个元素中
	 * \endif
	 */
	static wyJSONArray* makeMemory(const char* mfsName);

	/**
	 * \if English
	 * Get count of elements in json array
	 *
	 * @return count of elements in json array
	 * \else
	 * 得到json数组中的元素个数
	 *
	 * @return 元素个数
	 * \endif
	 */
	int getLength() { return m_array->size(); }

	/**
	 * \if English
	 * Add a null value to an array
	 * \else
	 * 添加一个null值到数组中
	 * \endif
	 */
	void addNull();

	/**
	 * \if English
	 * Add a boolean value to array
	 *
	 * @param b boolean value
	 * \else
	 * 添加一个布尔型值到数组中
	 *
	 * @param b 布尔型值
	 * \endif
	 */
	void addBool(bool b);

	/**
	 * \if English
	 * Add an integer value to array
	 *
	 * @param i integer value
	 * \else
	 * 添加一个整型值到数组中
	 *
	 * @param i 整型值
	 * \endif
	 */
	void addInt(int i);

	/**
	 * \if English
	 * Add a long value to array
	 *
	 * @param l long value
	 * \else
	 * 添加一个长整型值到数组中
	 *
	 * @param l 长整型值
	 * \endif
	 */
	void addLong(long l);

	/**
	 * \if English
	 * Add a float value to array
	 *
	 * @param f float value
	 * \else
	 * 添加一个浮点型值到数组中
	 *
	 * @param f 浮点型值
	 * \endif
	 */
	void addFloat(float f);

	/**
	 * \if English
	 * Add a double value to array
	 *
	 * @param d double value
	 * \else
	 * 添加一个双精度浮点型值到数组中
	 *
	 * @param d 双精度浮点型值
	 * \endif
	 */
	void addDouble(double d);

	/**
	 * \if English
	 * Add a string value to array
	 *
	 * @param s string value
	 * \else
	 * 添加一个字符串值到数组中
	 *
	 * @param s 字符串
	 * \endif
	 */
	void addString(const char* s);

	/**
	 * \if English
	 * Add json object to array
	 *
	 * @param jo json object
	 * \else
	 * 添加一个json对象型值到数组中
	 *
	 * @param jo json对象
	 * \endif
	 */
	void addObject(wyJSONObject* jo);

	/**
	 * \if English
	 * Add json array to array
	 *
	 * @param ja json数组
	 * \else
	 * 添加一个json数组到数组中
	 *
	 * @param ja json数组对象
	 * \endif
	 */
	void addArray(wyJSONArray* ja);

	/**
	 * \if English
	 * Print json array values to an output stream
	 *
	 * @param aos output stream
	 * @param level indentation level
	 * \else
	 * 打印json数组中的对象值到一个输出流中
	 *
	 * @param aos 输出流
	 * @param level 缩进等级, 从1开始
	 * \endif
	 */
	void output(wyAssetOutputStream* aos, int level = 1);

	/**
	 * \if English
	 * Get boolean value at given index
	 *
	 * @param index index of element
	 * @param def default boolean to be returned
	 * @return boolean value
	 * \else
	 * 得到指定位置的布尔串值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省值
	 * @return 布尔值
	 * \endif
	 */
	bool optBool(int index, bool def = false);

	/**
	 * \if English
	 * Get integer value at given index
	 *
	 * @param index index of element
	 * @param def default integer to be returned
	 * @return integer value
	 * \else
	 * 得到指定位置的整数值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省整数值
	 * @return 整数值
	 * \endif
	 */
	int optInt(int index, int def = 0);

	/**
	 * \if English
	 * Get long value at given index
	 *
	 * @param index index of element
	 * @param def default long to be returned
	 * @return long value
	 * \else
	 * 得到指定位置的长整数值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省长整数值
	 * @return 长整数值
	 * \endif
	 */
	long optLong(int index, long def = 0);

	/**
	 * \if English
	 * Get float value at given index
	 *
	 * @param index index of element
	 * @param def default float to be returned
	 * @return float value
	 * \else
	 * 得到指定位置的浮点值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省浮点值
	 * @return 浮点值
	 * \endif
	 */
	float optFloat(int index, float def = 0);

	/**
	 * \if English
	 * Get double value at given index
	 *
	 * @param index index of element
	 * @param def default double to be returned
	 * @return double value
	 * \else
	 * 得到指定位置的双精度浮点值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省双精度浮点值
	 * @return 双精度浮点值
	 * \endif
	 */
	double optDouble(int index, double def = 0);

	/**
	 * \if English
	 * Get json object at given index
	 *
	 * @param index index of element
	 * @return json object value
	 * \else
	 * 得到指定位置的json对象
	 *
	 * @param index 元素索引
	 * @return json对象, 或者返回NULL如果\c index不合法
	 * \endif
	 */
	wyJSONObject* optJSONObject(int index);

	/**
	 * \if English
	 * Get json array at given index
	 *
	 * @param index index of element
	 * @return json array
	 * \else
	 * 得到指定位置的json数组
	 *
	 * @param index 元素索引
	 * @return json数组, 或者返回NULL如果\c index不合法
	 * \endif
	 */
	wyJSONArray* optJSONArray(int index);

	/**
	 * \if English
	 * Get string value at given index
	 *
	 * @param index index of element
	 * @param def default string to be returned
	 * @return value string, this string should not released by caller, it is managed by json object and you must
	 * 		copy it if you want to save it
	 * \else
	 * 得到指定位置的字符串值
	 *
	 * @param index 元素索引
	 * @param def 找不到键值时返回的缺省值
	 * @return 字符串, 调用者不需要释放字符串. 返回的字符串是被json对象托管的, 如果你想要保存字符串必须拷贝一份
	 * \endif
	 */
	const char* optString(int index, const char* def = NULL);
};

#endif // __wyJSONArray_h__
