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
 * wyJSONObject means a map of key value pairs.
 */
class JSON_API wyJSONObject : public wyObject {
public:
	/**
	 * JSON value type
	 */
	enum Type {
		NIL,
		BOOLEAN,
		STRING,
		OBJECT,
		ARRAY
	};

	/**
	 * Union for a json value reference
	 */
	union Value {
		bool b;
		const char* s;
		wyJSONObject* jo;
		wyJSONArray* ja;
	};

	/**
	 * key value pair of json
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
	 * Create an empty json object
	 *
	 * @return json object
	 */
	static wyJSONObject* make();

	/**
	 * Parse a json memory string
	 *
	 * @param json json string in memory, must be in utf-8 encoding
	 * @param length byte length of \c json string
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 */
	static wyJSONObject* make(const char* json, size_t length);

	/**
	 * Parse a json file which is saved in res folder
	 *
	 * @param resId resource id of json file
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 */
	static wyJSONObject* make(int resId);

	/**
	 * Parse a json file saved in assets or file system
	 *
	 * @param path path of json file
	 * @param isFile true means \c path is an absolute path in file system, or false means
	 * 		\c path is a relative path under assets
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 */
	static wyJSONObject* make(const char* path, bool isFile = false);

	/**
	 * Parse a json memory file
	 *
	 * @param mfsName memory file name of json file
	 * @return json object, if \c json is actually an array then this array will be added
	 * 		with "array" key in returned json object
	 */
	static wyJSONObject* makeMemory(const char* mfsName);

	/**
	 * Print json object key value pairs to an output stream
	 *
	 * @param aos output stream
	 * @param level indentation level
	 */
	void output(wyAssetOutputStream* aos, int level = 1);

	/**
	 * Add a null value for a key
	 *
	 * @param key key string
	 */
	void addNull(const char* key);

	/**
	 * Add a boolean value for a key
	 *
	 * @param key key string
	 * @param b boolean value
	 */
	void addBool(const char* key, bool b);

	/**
	 * Add a integer value for a key
	 *
	 * @param key key string
	 * @param i integer value
	 */
	void addInt(const char* key, int i);

	/**
	 * Add a long value for a key
	 *
	 * @param key key string
	 * @param l long value
	 */
	void addLong(const char* key, long l);

	/**
	 * Add a float value for a key
	 *
	 * @param key key string
	 * @param f float value
	 */
	void addFloat(const char* key, float f);

	/**
	 * Add a double value for a key
	 *
	 * @param key key string
	 * @param d double value
	 */
	void addDouble(const char* key, double d);

	/**
	 * Add a string value for a key
	 *
	 * @param key key string
	 * @param s string
	 */
	void addString(const char* key, const char* s);

	/**
	 * Add a json object value for a key
	 *
	 * @param key key string
	 * @param jo json object
	 */
	void addObject(const char* key, wyJSONObject* jo);

	/**
	 * Add a json array value for a key
	 *
	 * @param key key string
	 * @param ja json array object
	 */
	void addArray(const char* key, wyJSONArray* ja);

	/**
	 * Get boolean value of a key
	 *
	 * @param key key string
	 * @param def default boolean value to be returned if key is not found
	 * @return boolean value
	 */
	bool optBool(const char* key, bool def = false);

	/**
	 * Get integer value of a key
	 *
	 * @param key key string
	 * @param def default integer value to be returned if key is not found
	 * @return integer value
	 */
	int optInt(const char* key, int def = 0);

	/**
	 * Get long value of a key
	 *
	 * @param key key string
	 * @param def default long value to be returned if key is not found
	 * @return long value
	 */
	long optLong(const char* key, long def = 0);

	/**
	 * Get float value of a key
	 *
	 * @param key key string
	 * @param def default float value to be returned if key is not found
	 * @return float value
	 */
	float optFloat(const char* key, float def = 0);

	/**
	 * Get double value of a key
	 *
	 * @param key key string
	 * @param def default double value to be returned if key is not found
	 * @return double value
	 */
	double optDouble(const char* key, double def = 0);

	/**
	 * Get json object of a key
	 *
	 * @param key key string
	 * @return json object, or NULL if key is not found
	 */
	wyJSONObject* optJSONObject(const char* key);

	/**
	 * Get json array of a key
	 *
	 * @param key key string
	 * @return json array, or NULL if key is not found
	 */
	wyJSONArray* optJSONArray(const char* key);

	/**
	 * Get string value of a key
	 *
	 * @param key key string
	 * @param def default string to be returned
	 * @return value string, this string should not released by caller, it is managed by json object and you must
	 * 		copy it if you want to save it
	 */
	const char* optString(const char* key, const char* def = NULL);
};

#endif // __wyJSONObject_h__
