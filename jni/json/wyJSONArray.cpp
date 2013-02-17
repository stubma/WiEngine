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
#include "wyJSONArray.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyJSONValue.h"
#include "wyJSONParser.h"

// tmp buffer
static char s_buf[4096];

wyJSONArray::wyJSONArray() {
}

wyJSONArray::~wyJSONArray() {
	for(vector<wyJSONObject::KeyValue>::iterator iter = m_array.begin(); iter != m_array.end(); iter++) {
		releaseKeyValue(*iter);
	}
}

wyJSONArray* wyJSONArray::make() {
	wyJSONArray* a = WYNEW wyJSONArray();
	return (wyJSONArray*)a->autoRelease();
}

wyJSONArray* wyJSONArray::make(int resId) {
	wyObject* obj = wyJSONParser::load(resId);
	return safeCast(obj);
}

wyJSONArray* wyJSONArray::make(const char* path, bool isFile) {
	wyObject* obj = wyJSONParser::load(path, isFile);
	return safeCast(obj);
}

wyJSONArray* wyJSONArray::makeMemory(const char* mfsName) {
	wyObject* obj = wyJSONParser::loadMemory(mfsName);
	return safeCast(obj);
}

wyJSONArray* wyJSONArray::make(const char* json, size_t length) {
	wyObject* obj = wyJSONParser::load(json, length);
	return safeCast(obj);
}

wyJSONArray* wyJSONArray::safeCast(wyObject* obj) {
	wyJSONArray* ja = dynamic_cast<wyJSONArray*>(obj);
	if(ja) {
		return ja;
	} else {
		wyJSONObject* jo = dynamic_cast<wyJSONObject*>(obj);
		if(jo) {
			wyJSONArray* ja = wyJSONArray::make();
			ja->addObject(jo);
			return ja;
		} else {
			return NULL;
		}
	}
}

void wyJSONArray::releaseKeyValue(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::STRING:
			wyFree((void*)kv.v.s);
			break;
		case wyJSONObject::OBJECT:
			wyObjectRelease(kv.v.jo);
			break;
		case wyJSONObject::ARRAY:
			wyObjectRelease(kv.v.ja);
			break;
	}
	if(kv.k)
		wyFree((void*)kv.k);
}

void wyJSONArray::addNull() {
	wyJSONObject::Value v;
	memset(&v, 0, sizeof(wyJSONObject::Value));
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::NIL,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addBool(bool b) {
	wyJSONObject::Value v;
	v.b = b;
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::BOOLEAN,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addInt(int i) {
	char buf[32];
	sprintf(buf, "%d", i);
	wyJSONObject::Value v;
	v.s = wyUtils::copy(buf);
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::STRING,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addLong(long l) {
	char buf[32];
	sprintf(buf, "%ld", l);
	wyJSONObject::Value v;
	v.s = wyUtils::copy(buf);
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::STRING,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addFloat(float f) {
	char buf[32];
	sprintf(buf, "%f", f);
	wyJSONObject::Value v;
	v.s = wyUtils::copy(buf);
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::STRING,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addDouble(double d) {
	char buf[32];
	sprintf(buf, "%lf", d);
	wyJSONObject::Value v;
	v.s = wyUtils::copy(buf);
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::STRING,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addString(const char* s) {
	wyJSONObject::Value v;
	v.s = wyUtils::copy(s);
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::STRING,
			v
	};
	m_array.push_back(kv);
}

void wyJSONArray::addObject(wyJSONObject* jo) {
	wyJSONObject::Value v;
	v.jo = jo;
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::OBJECT,
			v
	};
	wyObjectRetain(jo);
	m_array.push_back(kv);
}

void wyJSONArray::addArray(wyJSONArray* ja) {
	wyJSONObject::Value v;
	v.ja = ja;
	wyJSONObject::KeyValue kv = {
			NULL,
			wyJSONObject::ARRAY,
			v
	};
	wyObjectRetain(ja);
	m_array.push_back(kv);
}

bool wyJSONArray::optBool(int index, bool def) {
	if(index < 0 || index >= m_array.size()) {
		return def;
	}

	return wyJSONValue::castToBool(m_array.at(index));
}

int wyJSONArray::optInt(int index, int def) {
	if(index < 0 || index >= m_array.size()) {
		return def;
	}

	return wyJSONValue::castToInt(m_array.at(index));
}

long wyJSONArray::optLong(int index, long def) {
	if(index < 0 || index >= m_array.size()) {
		return def;
	}

	return wyJSONValue::castToLong(m_array.at(index));
}

float wyJSONArray::optFloat(int index, float def) {
	if(index < 0 || index >= m_array.size()) {
		return def;
	}

	return wyJSONValue::castToFloat(m_array.at(index));
}

double wyJSONArray::optDouble(int index, double def) {
	if(index < 0 || index >= m_array.size()) {
		return def;
	}

	return wyJSONValue::castToDouble(m_array.at(index));
}

wyJSONObject* wyJSONArray::optJSONObject(int index) {
	if(index < 0 || index >= m_array.size()) {
		return NULL;
	}

	return wyJSONValue::castToObject(m_array.at(index));
}

wyJSONArray* wyJSONArray::optJSONArray(int index) {
	if(index < 0 || index >= m_array.size()) {
		return NULL;
	}

	return wyJSONValue::castToArray(m_array.at(index));
}

const char* wyJSONArray::optString(int index, const char* def) {
	if(index < 0 || index >= m_array.size()) {
		return wyJSONValue::copyString(def);
	}

	return wyJSONValue::castToString(m_array.at(index));
}

void wyJSONArray::output(wyAssetOutputStream* aos, int level) {
	// bracket of array
	s_buf[0] = '[';
	s_buf[1] = '\n';
	aos->write(s_buf, 2);

	for(vector<wyJSONObject::KeyValue>::iterator iter = m_array.begin(); iter != m_array.end(); iter++) {
		// output key indentation
		for(int i = 0; i < level; i++) {
			s_buf[i] = '\t';
		}
		aos->write(s_buf, level);

		switch(iter->t) {
			case wyJSONObject::OBJECT:
				iter->v.jo->output(aos, level + 1);

				// comma
				if(m_array.end() - iter != 1)
					aos->write(",", 1);

				break;
			case wyJSONObject::ARRAY:
				iter->v.ja->output(aos, level + 1);

				// comma
				if(m_array.end() - iter != 1)
					aos->write(",", 1);

				break;
			case wyJSONObject::BOOLEAN:
				// output value
				if(m_array.end() - iter == 1)
					sprintf(s_buf, "%s\n", iter->v.b ? "true" : "false");
				else
					sprintf(s_buf, "%s,\n", iter->v.b ? "true" : "false");
				aos->write(s_buf, strlen(s_buf));
				break;
			default:
				// output value
				if(m_array.end() - iter == 1)
					sprintf(s_buf, "\"%s\"\n", wyJSONValue::castToString(*iter));
				else
					sprintf(s_buf, "\"%s\",\n", wyJSONValue::castToString(*iter));
				aos->write(s_buf, strlen(s_buf));
				break;
		}
	}

	// end bracket indentation
	for(int i = 0; i < level - 1; i++) {
		s_buf[i] = '\t';
	}
	aos->write(s_buf, level - 1);

	// end bracket
	s_buf[0] = ']';
	s_buf[1] = '\n';
	aos->write(s_buf, 2);
}
