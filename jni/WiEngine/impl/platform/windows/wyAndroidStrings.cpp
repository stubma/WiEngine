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
#ifdef WINDOWS

#include "wyAndroidStrings.h"
#include "wyLog.h"
#include "wyUtils.h"
#include <stdio.h>
#include <Windows.h>
#include <libxml/parser.h>

#define FILE_MAP map<unsigned int, WY_STRING_MAP*>
#define FILE_ITER FILE_MAP::iterator

// singleton
static wyAndroidStrings* s_instance = NULL;

typedef enum {
	UNKNOWN,
	RESOURCES,
	STRING
} wyStringsTag;

typedef enum {
	ATTR_UNKNOWN,
	ATTR_NAME
} wyStringsAttr;

typedef struct wyParseState {
	// last key name
	char name[512];

	// string map
	WY_STRING_MAP* entry;

	// key list
	vector<const char*>* keyList;

	// tag stack
	int* tags;
	int num;
	int max;

	// resource original scale
	float resScale;
} wyParseState;

static wyStringsTag getTag(const char* name) {
	if(!strcmp(name, "resources"))
		return RESOURCES;
	else if(!strcmp(name, "string"))
		return STRING;
	else
		return UNKNOWN;
}

static wyStringsAttr getAttr(const char* name) {
	if(!strcmp(name, "name"))
		return ATTR_NAME;
	else
		return ATTR_UNKNOWN;
}

static void pushTag(wyParseState* state, int tag) {
	while(state->num >= state->max) {
		state->max *= 2;
		state->tags = (int*)wyRealloc(state->tags, state->max);
	}

	state->tags[state->num++] = tag;
}

static inline void popTag(wyParseState* state) {
	state->num--;
}

static inline int topTag(wyParseState* state) {
	return state->tags[state->num - 1];
}

static inline int parentTag(wyParseState* state) {
	return state->tags[state->num - 2];
}

static inline int grandpaTag(wyParseState* state) {
	return state->tags[state->num - 3];
}

static const char* getAttrValue(const char** atts, const char* name) {
	for(int i = 0; atts[i] != NULL; i += 2) {
		if(!strcmp(atts[i], name))
			return atts[i + 1];
	}
	return NULL;
}

wyAndroidStrings::wyAndroidStrings() {
	m_files = WYNEW FILE_MAP();
	m_keyList = WYNEW vector<const char*>();
}

wyAndroidStrings::~wyAndroidStrings() {
	for(FILE_ITER iter = m_files->begin(); iter != m_files->end(); iter++) {
		 WY_STRING_MAP* temp = iter->second;
		 for(WY_STRING_ITER iter2 = temp->begin(); iter2 != temp->end(); iter2++) {
			 wyFree((void*)iter2->first);
			 wyFree((void*)iter2->second);
		 }

		 WYDELETE(temp);
	}

	for(vector<const char*>::iterator iter = m_keyList->begin(); iter != m_keyList->end(); iter++) {
		wyFree((void*)*iter);
	}

	WYDELETE(m_files);
	WYDELETE(m_keyList);
	s_instance = NULL;
}

void wyAndroidStrings::addStrings(const char* fileName, const char* langId) {
	// is already added?
	unsigned int hash = wyUtils::strHash(langId);
	FILE_ITER iter = m_files->find(hash);
	if(iter != m_files->end()) {
		LOGW("the language: %s is already added", langId);
		return;
	}

	// put new file entry in to file map
	WY_STRING_MAP* entry = WYNEW WY_STRING_MAP();
	(*m_files)[hash] = entry;

	// open file
	FILE* f = NULL;
	if((f = fopen(fileName, "rb")) == NULL) {
		LOGW("open strings file failed: %s", strerror(errno));
		return;
	}

	// load data
	size_t len;
	char* data = wyUtils::loadRaw(f, &len, true);

	// parse strings xml
	xmlSAXHandlerV1 sSAXHandler = {
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		startElement,
		endElement,
		NULL,
		characters,
		NULL,
		NULL,
		NULL,
		warning,
		error,
		NULL,
		NULL,
		NULL,
		NULL,
		0
	};

	// create map object
	wyParseState* state = (wyParseState*)wyCalloc(1, sizeof(wyParseState));
	state->entry = entry;
	state->keyList = m_keyList;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = -1;
	state->num = 1;
	state->max = 10;

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&sSAXHandler, state, data, len);

	// clean parser
	xmlCleanupParser();

	// release helper struct
	wyFree(state->tags);
	wyFree(state);
	wyFree(data);
}

WY_STRING_MAP* wyAndroidStrings::getEntry() {
	LANGID langId = GetSystemDefaultUILanguage();
	char primaryLangId = langId & 0x00FF;
	FILE_ITER iter = m_files->end();
	WY_STRING_MAP* entryUsed = NULL;
	switch(primaryLangId) {
		case 0x09: // english
			iter = m_files->find(wyUtils::strHash("en"));
			break;
		case 0x04: // chinese
			iter = m_files->find(wyUtils::strHash("zh"));
			break;
		default:
			break;
	}

	if(iter != m_files->end()) {
		entryUsed = iter->second;
	} else {
		if(m_files->begin() != m_files->end()) {
			entryUsed = m_files->begin()->second;
		}
	}

	return entryUsed;
}

const char* wyAndroidStrings::getString(const char* key) {
	const char* ret = NULL;
	WY_STRING_MAP* entryUsed = getEntry();
	if(entryUsed)
		ret = (*entryUsed)[key];

	return ret;
}

const char* wyAndroidStrings::getString(int resId) {
	if(resId < 0 || resId >= m_keyList->size())
		return NULL;

	const char* key = m_keyList->at(resId);
	return getString(key);
}

int wyAndroidStrings::getKeyIndex(const char* key) {
	int i = 0;
	for(vector<const char*>::iterator iter = m_keyList->begin(); iter != m_keyList->end(); iter++, i++) {
		if(!strcmp(*iter, key))
			return i;
	}
	
	return -1;
}

wyAndroidStrings* wyAndroidStrings::getInstance() {
	if(s_instance == NULL) {
		s_instance = WYNEW wyAndroidStrings();
	}
	return s_instance;
}

void wyAndroidStrings::destroyInstance() {
	if(s_instance) {
		WYDELETE(s_instance);
	}
}

void wyAndroidStrings::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;
	
	// set tag
	pushTag(state, getTag((const char*)name));

	switch(topTag(state)) {
		case STRING:
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wyStringsAttr attr = getAttr(key);

				// check attr
				switch(attr) {
					case ATTR_NAME:
						sprintf(state->name, "%s", value);
						break;
				}
			}
			break;
	}
}

void wyAndroidStrings::endElement(void* ctx, const xmlChar *name) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;
	
	// pop
	popTag(state);
}

void wyAndroidStrings::characters(void* ctx, const xmlChar *ch, int len) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// check tag
	switch(topTag(state)) {
		case STRING:
		{
			// the character may not read out one time, so we must check
			WY_STRING_ITER iter = state->entry->find(state->name);
			if(iter != state->entry->end()) {
				// get new string
				size_t oldLen = strlen(iter->second);
				char* buf = (char*)wyCalloc(oldLen + len + 1, sizeof(char));
				const char* v = wyUtils::copy((const char*)ch, 0, len);
				strcat(buf, iter->second);
				strcat(buf, v);
				wyFree((void*)v);

				// remove old entry
				wyFree((void*)iter->first);
				wyFree((void*)iter->second);
				state->entry->erase(iter);

				// push a new entry
				(*state->entry)[wyUtils::copy(state->name)] = buf;
			} else {
				(*state->entry)[wyUtils::copy(state->name)] = wyUtils::copy((const char*)ch, 0, len);
				state->keyList->push_back(wyUtils::copy(state->name));
			}
			break;
		}
	}
}

void wyAndroidStrings::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyAndroidStrings::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

#endif // #ifdef WINDOWS
