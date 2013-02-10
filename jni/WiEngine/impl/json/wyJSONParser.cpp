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
#include "wyJSONParser.h"
#include "wyJSONObject.h"
#include "yajl_parse.h"
#include "yajl_gen.h"
#include "wyMemoryInputStream.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyJSONArray.h"

// context for json parsing
typedef struct {
	yajl_gen g;
	char* key;
	size_t keyLen;
	wyObject* root;
	vector<wyObject*>* objStack;
	vector<bool>* flagStack;
} wyJSONContext;

static int reformat_null(void* ctx) {
	wyJSONContext* jc = (wyJSONContext*)ctx;

	bool array = *(jc->flagStack->rbegin());
	if(array) {
		wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
		p->addNull();
	} else {
		wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
		char old = jc->key[jc->keyLen];
		jc->key[jc->keyLen] = 0;
		p->addNull(jc->key);
		jc->key[jc->keyLen] = old;
	}

    return yajl_gen_status_ok == yajl_gen_null(jc->g);
}

static int reformat_boolean(void* ctx, int boolean) {
	wyJSONContext* jc = (wyJSONContext*)ctx;

	bool array = *(jc->flagStack->rbegin());
	if(array) {
		wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
		p->addBool(boolean);
	} else {
		wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
		char old = jc->key[jc->keyLen];
		jc->key[jc->keyLen] = 0;
		p->addBool(jc->key, boolean);
		jc->key[jc->keyLen] = old;
	}

    return yajl_gen_status_ok == yajl_gen_bool(jc->g, boolean);
}

static int reformat_number(void* ctx, const char * stringVal, size_t stringLen) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	char* s = (char*)stringVal;
	char oldChar = s[stringLen];
	s[stringLen] = 0;

	bool array = *(jc->flagStack->rbegin());
	if(array) {
		wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
		p->addString((const char*)stringVal);
	} else {
		wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
		char old = jc->key[jc->keyLen];
		jc->key[jc->keyLen] = 0;
		p->addString(jc->key, s);
		jc->key[jc->keyLen] = old;
	}

	s[stringLen] = oldChar;

    return yajl_gen_status_ok == yajl_gen_number(jc->g, stringVal, stringLen);
}

static int reformat_string(void* ctx, const unsigned char* stringVal, size_t stringLen) {
	wyJSONContext* jc = (wyJSONContext*)ctx;

	char* s = (char*)stringVal;
	char oldChar = s[stringLen];
	s[stringLen] = 0;

	bool array = *(jc->flagStack->rbegin());
	if(array) {
		wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
		p->addString(s);
	} else {
		wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
		char old = jc->key[jc->keyLen];
		jc->key[jc->keyLen] = 0;
		p->addString(jc->key, s);
		jc->key[jc->keyLen] = old;
	}

	s[stringLen] = oldChar;

    return yajl_gen_status_ok == yajl_gen_string(jc->g, stringVal, stringLen);
}

static int reformat_map_key(void* ctx, const unsigned char* stringVal, size_t stringLen) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	jc->key = (char*)stringVal;
	jc->keyLen = stringLen;

    return yajl_gen_status_ok == yajl_gen_string(jc->g, stringVal, stringLen);
}

static int reformat_start_map(void* ctx) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	if(jc->root) {
		wyJSONObject* jo = wyJSONObject::make();
		bool array = *(jc->flagStack->rbegin());
		if(array) {
			wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
			p->addObject(jo);
		} else {
			wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
			char old = jc->key[jc->keyLen];
			jc->key[jc->keyLen] = 0;
			p->addObject(jc->key, jo);
			jc->key[jc->keyLen] = old;
		}

		jc->objStack->push_back(jo);
		jc->flagStack->push_back(false);
	} else {
		jc->root = wyJSONObject::make();
		jc->objStack->push_back(jc->root);
		jc->flagStack->push_back(false);
	}

	return yajl_gen_status_ok == yajl_gen_map_open(jc->g);
}

static int reformat_end_map(void* ctx) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	jc->objStack->pop_back();
	jc->flagStack->pop_back();

    return yajl_gen_status_ok == yajl_gen_map_close(jc->g);
}

static int reformat_start_array(void* ctx) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	if(jc->root) {
		wyJSONArray* ja = wyJSONArray::make();
		bool array = *(jc->flagStack->rbegin());
		if(array) {
			wyJSONArray* p = (wyJSONArray*)(*(jc->objStack->rbegin()));
			p->addArray(ja);
		} else {
			wyJSONObject* p = (wyJSONObject*)(*(jc->objStack->rbegin()));
			char old = jc->key[jc->keyLen];
			jc->key[jc->keyLen] = 0;
			p->addArray(jc->key, ja);
			jc->key[jc->keyLen] = old;
		}

		jc->objStack->push_back(ja);
		jc->flagStack->push_back(true);
	} else {
		jc->root = wyJSONArray::make();
		jc->objStack->push_back(jc->root);
		jc->flagStack->push_back(true);
	}

    return yajl_gen_status_ok == yajl_gen_array_open(jc->g);
}

static int reformat_end_array(void* ctx) {
	wyJSONContext* jc = (wyJSONContext*)ctx;
	jc->objStack->pop_back();
	jc->flagStack->pop_back();

    return yajl_gen_status_ok == yajl_gen_array_close(jc->g);
}

static yajl_callbacks callbacks = {
    reformat_null,
    reformat_boolean,
    NULL,
    NULL,
    reformat_number,
    reformat_string,
    reformat_start_map,
    reformat_map_key,
    reformat_end_map,
    reformat_start_array,
    reformat_end_array
};

wyObject* wyJSONParser::load(const char* json, size_t length) {
	// use memory input stream
	wyMemoryInputStream* mis = wyMemoryInputStream::make((char*)json, length);

	// status of yajl
	yajl_status stat;

	// get gen instance
	yajl_gen g = yajl_gen_alloc(NULL);

	// register callback
	wyJSONContext ctx = {
			g,
			NULL,
			0,
			NULL,
			WYNEW vector<wyObject*>(),
			WYNEW vector<bool>()
	};
	yajl_handle hand = yajl_alloc(&callbacks, NULL, (void*)&ctx);

	// config yajl
	yajl_gen_config(g, yajl_gen_beautify, 1);
	yajl_gen_config(g, yajl_gen_validate_utf8, 1);
	yajl_config(hand, yajl_allow_comments, 1);

	// parse
	char buf[4096];
	while(true) {
		// read data
		int rd = mis->read(buf, 4096);
		if (rd == 0)
			break;

		// parese data
		stat = yajl_parse(hand, (const unsigned char*)buf, rd);

		// if parse error, break
		if (stat != yajl_status_ok)
			break;
	}

	// complete parse
	stat = yajl_complete_parse(hand);

	// check error
	if (stat != yajl_status_ok) {
		unsigned char* str = yajl_get_error(hand, 1, (const unsigned char*)json, length);
		LOGW("parse json error: %s", str);
		yajl_free_error(hand, str);

		// when error, doesn't return anything
		ctx.root = NULL;
	}

	// free
	yajl_gen_free(g);
	yajl_free(hand);
	WYDELETE(ctx.objStack);
	WYDELETE(ctx.flagStack);

	// return
	return ctx.root;
}

wyObject* wyJSONParser::load(int resId) {
	size_t len;
	char* data = wyUtils::loadRaw(resId, &len);
	wyObject* ret = load(data, len);
	wyFree(data);
	return ret;
}

wyObject* wyJSONParser::load(const char* path, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(path, isFile, &len);
	wyObject* ret = load(data, len);
	wyFree(data);
	return ret;
}

wyObject* wyJSONParser::loadMemory(const char* mfsName) {
	size_t len;
	char* data = wyUtils::loadRaw(mfsName, &len);
	wyObject* ret = load(data, len);
	wyFree(data);
	return ret;
}
