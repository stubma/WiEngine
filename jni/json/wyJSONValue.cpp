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
#include "wyJSONValue.h"
#include "wyLog.h"
#include <stdio.h>

// hold tmp value need to be returned
static char s_buf[64 * 1024];

bool wyJSONValue::castToBool(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return false;
		case wyJSONObject::BOOLEAN:
			return kv.v.b;
		case wyJSONObject::STRING:
			return !strcmp("true", kv.v.s);
		case wyJSONObject::OBJECT:
			return kv.v.jo != NULL;
		case wyJSONObject::ARRAY:
			return kv.v.ja != NULL;
		default:
			LOGE("wyJSONValue::castToBool: unexpected json value type: %d", kv.t);
			return false;
	}
}

int wyJSONValue::castToInt(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return 0;
		case wyJSONObject::BOOLEAN:
			return kv.v.b ? 1 : 0;
		case wyJSONObject::STRING:
			return atoi(kv.v.s);
		case wyJSONObject::OBJECT:
			return *((int*)&kv.v.jo);
		case wyJSONObject::ARRAY:
			return *((int*)&kv.v.ja);
		default:
			LOGE("wyJSONValue::castToInt: unexpected json value type: %d", kv.t);
			return 0;
	}
}

long wyJSONValue::castToLong(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return 0;
		case wyJSONObject::BOOLEAN:
			return kv.v.b ? 1 : 0;
		case wyJSONObject::STRING:
			return atoi(kv.v.s);
		case wyJSONObject::OBJECT:
			return (long)kv.v.jo;
		case wyJSONObject::ARRAY:
			return (long)kv.v.ja;
		default:
			LOGE("wyJSONValue::castToLong: unexpected json value type: %d", kv.t);
			return 0;
	}
}

float wyJSONValue::castToFloat(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return 0;
		case wyJSONObject::BOOLEAN:
			return kv.v.b ? 1 : 0;
		case wyJSONObject::STRING:
			return atof(kv.v.s);
		case wyJSONObject::OBJECT:
			return (float)*((int*)&kv.v.jo);
		case wyJSONObject::ARRAY:
			return (float)*((int*)&kv.v.ja);
		default:
			LOGE("wyJSONValue::castToFloat: unexpected json value type: %d", kv.t);
			return 0;
	}
}

double wyJSONValue::castToDouble(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return 0;
		case wyJSONObject::BOOLEAN:
			return kv.v.b ? 1 : 0;
		case wyJSONObject::STRING:
			return atof(kv.v.s);
		case wyJSONObject::OBJECT:
			return (double)*((int*)&kv.v.jo);
		case wyJSONObject::ARRAY:
			return (double)*((int*)&kv.v.ja);
		default:
			LOGE("wyJSONValue::castToDouble: unexpected json value type: %d", kv.t);
			return 0;
	}
}

wyJSONObject* wyJSONValue::castToObject(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
		case wyJSONObject::BOOLEAN:
		case wyJSONObject::STRING:
		case wyJSONObject::ARRAY:
			return NULL;
		case wyJSONObject::OBJECT:
			return kv.v.jo;
		default:
			LOGE("wyJSONValue::castToObject: unexpected json value type: %d", kv.t);
			return 0;
	}
}

wyJSONArray* wyJSONValue::castToArray(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
		case wyJSONObject::BOOLEAN:
		case wyJSONObject::STRING:
		case wyJSONObject::OBJECT:
			return NULL;
		case wyJSONObject::ARRAY:
			return kv.v.ja;
		default:
			LOGE("wyJSONValue::castToArray: unexpected json value type: %d", kv.t);
			return 0;
	}
}

const char* wyJSONValue::castToString(wyJSONObject::KeyValue& kv) {
	switch(kv.t) {
		case wyJSONObject::NIL:
			return NULL;
		case wyJSONObject::BOOLEAN:
			if(kv.v.b) {
				sprintf(s_buf, "true");
			} else {
				sprintf(s_buf, "false");
			}
			return s_buf;
		case wyJSONObject::STRING:
			return kv.v.s;
		case wyJSONObject::OBJECT:
			sprintf(s_buf, "wyJSONObject");
			return s_buf;
		case wyJSONObject::ARRAY:
			sprintf(s_buf, "wyJSONArray");
			return s_buf;
		default:
			LOGE("wyJSONValue::castToString: unexpected json value type: %d", kv.t);
			return NULL;
	}
}

const char* wyJSONValue::copyString(const char* s) {
	if(s) {
		sprintf(s_buf, "%s", s);
		return s_buf;
	} else {
		return NULL;
	}
}
