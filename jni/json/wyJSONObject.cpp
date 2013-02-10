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
#include "wyJSONObject.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyJSONArray.h"
#include "wyJSONParser.h"
#include "wyJSONValue.h"

// tmp buffer
static char s_buf[4096];

wyJSONObject::wyJSONObject() {
}

wyJSONObject::~wyJSONObject() {
	for(PairMap::iterator iter = m_pairs.begin(); iter != m_pairs.end(); iter++) {
		releaseKeyValue(iter->first, iter->second);
	}
}

void wyJSONObject::releaseKeyValue(const char* key, KeyValue& kv) {
	switch(kv.t) {
		case STRING:
			wyFree((void*)kv.v.s);
			break;
		case OBJECT:
			wyObjectRelease(kv.v.jo);
			break;
		case ARRAY:
			wyObjectRelease(kv.v.ja);
			break;
	}
	if(kv.k)
		wyFree((void*)kv.k);
}

wyJSONObject* wyJSONObject::safeCast(wyObject* obj) {
	wyJSONObject* jo = dynamic_cast<wyJSONObject*>(obj);
	if(jo) {
		return jo;
	} else {
		wyJSONArray* ja = dynamic_cast<wyJSONArray*>(obj);
		if(ja) {
			wyJSONObject* jo = wyJSONObject::make();
			jo->addArray("array", ja);
			return jo;
		} else {
			return NULL;
		}
	}
}

wyJSONObject* wyJSONObject::make() {
	wyJSONObject* jo = WYNEW wyJSONObject();
	return (wyJSONObject*)jo->autoRelease();
}

wyJSONObject* wyJSONObject::make(int resId) {
	wyObject* obj = wyJSONParser::load(resId);
	return safeCast(obj);
}

wyJSONObject* wyJSONObject::make(const char* path, bool isFile) {
	wyObject* obj = wyJSONParser::load(path, isFile);
	return safeCast(obj);
}

wyJSONObject* wyJSONObject::makeMemory(const char* mfsName) {
	wyObject* obj = wyJSONParser::loadMemory(mfsName);
	return safeCast(obj);
}

wyJSONObject* wyJSONObject::make(const char* json, size_t length) {
	wyObject* obj = wyJSONParser::load(json, length);
	return safeCast(obj);
}

void wyJSONObject::addNull(const char* key) {
	// basic validation
	if(!key)
		return;

	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			NIL,
			{ false }
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addBool(const char* key, bool b) {
	// basic validation
	if(!key)
		return;

	Value v;
	v.b = b;
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			BOOLEAN,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addInt(const char* key, int i) {
	// basic validation
	if(!key)
		return;

	char buf[32];
	sprintf(buf, "%d", i);
	Value v;
	v.s = wyUtils::copy(buf);
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			STRING,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addLong(const char* key, long l) {
	// basic validation
	if(!key)
		return;

	char buf[32];
	sprintf(buf, "%ld", l);
	Value v;
	v.s = wyUtils::copy(buf);
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			STRING,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addFloat(const char* key, float f) {
	// basic validation
	if(!key)
		return;

	char buf[32];
	sprintf(buf, "%f", f);
	Value v;
	v.s = wyUtils::copy(buf);
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			STRING,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addDouble(const char* key, double d) {
	// basic validation
	if(!key)
		return;

	char buf[32];
	sprintf(buf, "%lf", d);
	Value v;
	v.s = wyUtils::copy(buf);
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			STRING,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addString(const char* key, const char* s) {
	// basic validation
	if(!key)
		return;

	Value v;
	v.s = wyUtils::copy(s);
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			STRING,
			v
	};
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addObject(const char* key, wyJSONObject* jo) {
	// basic validation
	if(!key)
		return;

	Value v;
	v.jo = jo;
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			OBJECT,
			v
	};
	wyObjectRetain(jo);
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

void wyJSONObject::addArray(const char* key, wyJSONArray* ja) {
	// basic validation
	if(!key)
		return;

	Value v;
	v.ja = ja;
	const char* k = wyUtils::copy(key);
	KeyValue kv = {
			k,
			ARRAY,
			v
	};
	wyObjectRetain(ja);
	m_pairs[k] = kv;
	m_keyvalues.push_back(kv);
}

bool wyJSONObject::optBool(const char* key, bool def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToBool(iter->second);
	} else {
		return def;
	}
}

int wyJSONObject::optInt(const char* key, int def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToInt(iter->second);
	} else {
		return def;
	}
}

long wyJSONObject::optLong(const char* key, long def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToLong(iter->second);
	} else {
		return def;
	}
}

float wyJSONObject::optFloat(const char* key, float def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToFloat(iter->second);
	} else {
		return def;
	}
}

double wyJSONObject::optDouble(const char* key, double def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToDouble(iter->second);
	} else {
		return def;
	}
}

wyJSONObject* wyJSONObject::optJSONObject(const char* key) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToObject(iter->second);
	} else {
		return NULL;
	}
}

wyJSONArray* wyJSONObject::optJSONArray(const char* key) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToArray(iter->second);
	} else {
		return NULL;
	}
}

const char* wyJSONObject::optString(const char* key, const char* def) {
	PairMap::iterator iter = m_pairs.find(key);
	if(iter != m_pairs.end()) {
		return wyJSONValue::castToString(iter->second);
	} else {
		return wyJSONValue::copyString(def);
	}
}

bool wyJSONObject::optBool(int index, bool def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return def;
	}

	return wyJSONValue::castToBool(m_keyvalues.at(index));
}

int wyJSONObject::optInt(int index, int def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return def;
	}

	return wyJSONValue::castToInt(m_keyvalues.at(index));
}

long wyJSONObject::optLong(int index, long def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return def;
	}

	return wyJSONValue::castToLong(m_keyvalues.at(index));
}

float wyJSONObject::optFloat(int index, float def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return def;
	}

	return wyJSONValue::castToFloat(m_keyvalues.at(index));
}

double wyJSONObject::optDouble(int index, double def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return def;
	}

	return wyJSONValue::castToDouble(m_keyvalues.at(index));
}

wyJSONObject* wyJSONObject::optJSONObject(int index) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return NULL;
	}

	return wyJSONValue::castToObject(m_keyvalues.at(index));
}

wyJSONArray* wyJSONObject::optJSONArray(int index) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return NULL;
	}

	return wyJSONValue::castToArray(m_keyvalues.at(index));
}

const char* wyJSONObject::optString(int index, const char* def) {
	if(index < 0 || index >= m_keyvalues.size()) {
		return wyJSONValue::copyString(def);
	}

	return wyJSONValue::castToString(m_keyvalues.at(index));
}

void wyJSONObject::output(wyAssetOutputStream* aos, int level) {
	// bracket of object
	s_buf[0] = '{';
	s_buf[1] = '\n';
	aos->write(s_buf, 2);

	int count = 0;
	for(PairMap::iterator iter = m_pairs.begin(); iter != m_pairs.end(); iter++) {
		// output key indentation
		for(int i = 0; i < level; i++) {
			s_buf[i] = '\t';
		}
		aos->write(s_buf, level);

		// output key
		sprintf(s_buf, "\"%s\" : ", iter->second.k);
		aos->write(s_buf, strlen(s_buf));

		switch(iter->second.t) {
			case OBJECT:
				// output object
				iter->second.v.jo->output(aos, level + 1);

				// comma
				if(count != m_pairs.size() - 1)
					aos->write(",", 1);

				break;
			case ARRAY:
				// output array
				iter->second.v.ja->output(aos, level + 1);

				// comma
				if(count != m_pairs.size() - 1)
					aos->write(",", 1);

				break;
			case BOOLEAN:
				// output value
				if(count == m_pairs.size() - 1)
					sprintf(s_buf, "%s\n", iter->second.v.b ? "true" : "false");
				else
					sprintf(s_buf, "%s,\n", iter->second.v.b ? "true" : "false");
				aos->write(s_buf, strlen(s_buf));
				break;
			default:
				// output value
				if(count == m_pairs.size() - 1)
					sprintf(s_buf, "\"%s\"\n", wyJSONValue::castToString(iter->second));
				else
					sprintf(s_buf, "\"%s\",\n", wyJSONValue::castToString(iter->second));
				aos->write(s_buf, strlen(s_buf));
				break;
		}

		count++;
	}

	// end bracket indentation
	for(int i = 0; i < level - 1; i++) {
		s_buf[i] = '\t';
	}
	aos->write(s_buf, level - 1);

	// end bracket
	s_buf[0] = '}';
	s_buf[1] = '\n';
	aos->write(s_buf, 2);
}
