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
#ifndef __wyJSONObject_h__
#define __wyJSONObject_h__

#include "wyJSONConfig.h"
#include "wyObject.h"
#include "wyGlobal.h"
#include "wyAssetOutputStream.h"

class wyJSONArray;

/**
 * @class wyJSONObject
 *
 * \if English
 * wyJSONObject means a map of key value pairs.
 * \else
 * 代表json中的一个键值对对象
 * \endif
 */
class JSON_API wyJSONObject : public wyObject {
public:
	/**
	 * \if English
	 * JSON value type
	 * \else
	 * json值类型
	 * \endif
	 */
	enum Type {
		NIL,
		BOOLEAN,
		STRING,
		OBJECT,
		ARRAY
	};

	/**
	 * \if English
	 * Union for a json value reference
	 * \else
	 * json值的联合结构定义
	 * \endif
	 */
	union Value {
		bool b;
		const char* s;
		wyJSONObject* jo;
		wyJSONArray* ja;
	};

	/**
	 * \if English
	 * key value pair of json
	 * \else
	 * 键值对结构
	 * \endif
	 */
	struct KeyValue {
		const char* k;
		Type t;
		Value v;
	};

private:
	/// json key value map
	map<const char*, KeyValue, wyStrPredicate>* m_pairs;

protected:
	wyJSONObject();

	/// cast an object to wyJSONObject, if obj is a wyJSONArray, then
	/// this array will be packed in json object with keyword "array"
	static wyJSONObject* safeCast(wyObject* obj);

	/// release key value
	static void releaseKeyValue(const char* key, KeyValue& kv);

public:
	virtual ~wyJSONObject();

	/**
	 * \if English
	 * Create an empty json object
	 *
	 * @return json object
	 * \else
	 * 创建一个空的json对象
	 *
	 * @return json对象
	 * \endif
	 */
	static wyJSONObject* make();

	/**
	 * \if English
	 * Parse a json memory string
	 *
	 * @param json json string in memory, must be in utf-8 encoding
	 * @param length byte length of \c json string
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 * \else
	 * 解析一段内存中的json字符串
	 *
	 * @param json 内存json字符串, 必须是utf-8编码
	 * @param length \c json字符串的字节长度
	 * @return json对象, 假如json串解析的结果是一个数组, 则这个数组以关键字"array"保存在返回的
	 * 		json对象中
	 * \endif
	 */
	static wyJSONObject* make(const char* json, size_t length);

	/**
	 * \if English
	 * Parse a json file which is saved in res folder
	 *
	 * @param resId resource id of json file
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 * \else
	 * 解析一个保存在res文件夹下的json文件
	 *
	 * @param resId json文件的资源id
	 * @return json对象, 假如json串解析的结果是一个数组, 则这个数组以关键字"array"保存在返回的
	 * 		json对象中
	 * \endif
	 */
	static wyJSONObject* make(int resId);

	/**
	 * \if English
	 * Parse a json file saved in assets or file system
	 *
	 * @param path path of json file
	 * @param isFile true means \c path is an absolute path in file system, or false means
	 * 		\c path is a relative path under assets
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 * \else
	 * 解析一个保存在assets下或文件系统中的json文件
	 *
	 * @param path json文件的路径
	 * @param isFile true表示\c path是一个文件系统的绝对路径, false表示\c path是一个assets下的相对路径
	 * @return json对象, 假如json串解析的结果是一个数组, 则这个数组以关键字"array"保存在返回的
	 * 		json对象中
	 * \endif
	 */
	static wyJSONObject* make(const char* path, bool isFile = false);

	/**
	 * \if English
	 * Parse a json memory file
	 *
	 * @param mfsName memory file name of json file
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 * \else
	 * 解析一个json内存文件
	 *
	 * @param mfsName json文件的内存文件名称
	 * @return json对象, 假如json串解析的结果是一个数组, 则这个数组以关键字"array"保存在返回的
	 * 		json对象中
	 * \endif
	 */
	static wyJSONObject* makeMemory(const char* mfsName);

	/**
	 * \if English
	 * Print json object key value pairs to an output stream
	 *
	 * @param aos output stream
	 * @param level indentation level
	 * \else
	 * 打印json对象中的键值对到一个输出流中
	 *
	 * @param aos 输出流
	 * @param level 缩进等级, 从1开始
	 * \endif
	 */
	void output(wyAssetOutputStream* aos, int level = 1);

	/**
	 * \if English
	 * Add a null value for a key
	 *
	 * @param key key string
	 * \else
	 * 添加一个键值对, 值是null
	 *
	 * @param key 键值
	 * \endif
	 */
	void addNull(const char* key);

	/**
	 * \if English
	 * Add a boolean value for a key
	 *
	 * @param key key string
	 * @param b boolean value
	 * \else
	 * 添加一个键值对, 值是布尔型
	 *
	 * @param key 键值
	 * @param b 布尔值
	 * \endif
	 */
	void addBool(const char* key, bool b);

	/**
	 * \if English
	 * Add a integer value for a key
	 *
	 * @param key key string
	 * @param i integer value
	 * \else
	 * 添加一个键值对, 值是整数
	 *
	 * @param key 键值
	 * @param i 整数值
	 * \endif
	 */
	void addInt(const char* key, int i);

	/**
	 * \if English
	 * Add a long value for a key
	 *
	 * @param key key string
	 * @param l long value
	 * \else
	 * 添加一个键值对, 值是长整型
	 *
	 * @param key 键值
	 * @param l 长整型
	 * \endif
	 */
	void addLong(const char* key, long l);

	/**
	 * \if English
	 * Add a float value for a key
	 *
	 * @param key key string
	 * @param f float value
	 * \else
	 * 添加一个键值对, 值是浮点型
	 *
	 * @param key 键值
	 * @param f 浮点值
	 * \endif
	 */
	void addFloat(const char* key, float f);

	/**
	 * \if English
	 * Add a double value for a key
	 *
	 * @param key key string
	 * @param d double value
	 * \else
	 * 添加一个键值对, 值是双精度浮点型
	 *
	 * @param key 键值
	 * @param d 双精度浮点值
	 * \endif
	 */
	void addDouble(const char* key, double d);

	/**
	 * \if English
	 * Add a string value for a key
	 *
	 * @param key key string
	 * @param s string
	 * \else
	 * 添加一个键值对, 值是字符串型
	 *
	 * @param key 键值
	 * @param s 字符串
	 * \endif
	 */
	void addString(const char* key, const char* s);

	/**
	 * \if English
	 * Add a json object value for a key
	 *
	 * @param key key string
	 * @param jo json object
	 * \else
	 * 添加一个键值对, 值是json对象
	 *
	 * @param key 键值
	 * @param jo json对象
	 * \endif
	 */
	void addObject(const char* key, wyJSONObject* jo);

	/**
	 * \if English
	 * Add a json array value for a key
	 *
	 * @param key key string
	 * @param ja json array object
	 * \else
	 * 添加一个键值对, 值是json对象数组
	 *
	 * @param key 键值
	 * @param ja json对象数组
	 * \endif
	 */
	void addArray(const char* key, wyJSONArray* ja);

	/**
	 * \if English
	 * Get boolean value of a key
	 *
	 * @param key key string
	 * @param def default boolean value to be returned if key is not found
	 * @return boolean value
	 * \else
	 * 得到一个布尔值
	 *
	 * @param key 键值
	 * @param def 如果键没有找到则返回的缺省布尔值
	 * @return 布尔值
	 * \endif
	 */
	bool optBool(const char* key, bool def = false);

	/**
	 * \if English
	 * Get integer value of a key
	 *
	 * @param key key string
	 * @param def default integer value to be returned if key is not found
	 * @return integer value
	 * \else
	 * 得到一个整型值
	 *
	 * @param key 键值
	 * @param def 如果键没有找到则返回的缺省整数值
	 * @return 整数值
	 * \endif
	 */
	int optInt(const char* key, int def = 0);

	/**
	 * \if English
	 * Get long value of a key
	 *
	 * @param key key string
	 * @param def default long value to be returned if key is not found
	 * @return long value
	 * \else
	 * 得到一个长整型值
	 *
	 * @param key 键值
	 * @param def 如果键没有找到则返回的缺省长整数值
	 * @return 长整数值
	 * \endif
	 */
	long optLong(const char* key, long def = 0);

	/**
	 * \if English
	 * Get float value of a key
	 *
	 * @param key key string
	 * @param def default float value to be returned if key is not found
	 * @return float value
	 * \else
	 * 得到一个浮点值
	 *
	 * @param key 键值
	 * @param def 如果键没有找到则返回的缺省浮点值
	 * @return 浮点值
	 * \endif
	 */
	float optFloat(const char* key, float def = 0);

	/**
	 * \if English
	 * Get double value of a key
	 *
	 * @param key key string
	 * @param def default double value to be returned if key is not found
	 * @return double value
	 * \else
	 * 得到一个双精度浮点值
	 *
	 * @param key 键值
	 * @param def 如果键没有找到则返回的缺省双精度浮点值
	 * @return 双精度浮点值
	 * \endif
	 */
	double optDouble(const char* key, double def = 0);

	/**
	 * \if English
	 * Get json object of a key
	 *
	 * @param key key string
	 * @return json object, or NULL if key is not found
	 * \else
	 * 得到一个json对象
	 *
	 * @param key 键值
	 * @return json对象, 如果键值没有找到, 返回NULL
	 * \endif
	 */
	wyJSONObject* optJSONObject(const char* key);

	/**
	 * \if English
	 * Get json array of a key
	 *
	 * @param key key string
	 * @return json array, or NULL if key is not found
	 * \else
	 * 得到一个json数组
	 *
	 * @param key 键值
	 * @return json数组, 如果键值没有找到, 返回NULL
	 * \endif
	 */
	wyJSONArray* optJSONArray(const char* key);

	/**
	 * \if English
	 * Get string value of a key
	 *
	 * @param key key string
	 * @param def default string to be returned
	 * @return value string, this string should not released by caller, it is managed by json object and you must
	 * 		copy it if you want to save it
	 * \else
	 * 得到一个字符串值
	 *
	 * @param key 键值
	 * @param def 找不到键值时返回的缺省值
	 * @return 字符串, 调用者不需要释放字符串. 返回的字符串是被json对象托管的, 如果你想要保存字符串必须拷贝一份
	 * \endif
	 */
	const char* optString(const char* key, const char* def = NULL);
};

#endif // __wyJSONObject_h__
