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
#include "wyZwoptex.h"
#include "wyUtils.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "wyLog.h"
#include "wyGlobal.h"
#include <libxml/parser.h>
#if ANDROID
	#include "wyJNI.h"
#endif

// parsing state
#define READY 0
#define PARSING_FRAMES 1
#define PARSING_FRAME 2
#define PARSING_METADATA 3
#define PARSING_TEXTURE 4

typedef struct wyParseState {
	wyZwoptex* zwoptex;

	// last key name
	const char* lastKey;

	// tag stack
	int* tags;
	int num;
	int max;

	// state
	int state;

	// res scale, only used for plist resource
	float resScale;

	// pending frame
	wyZwoptexFrame* lastFrame;
} wyParseState;

#ifdef __cplusplus
extern "C" {
#endif

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

wyPListTag getPListTag(const char* name) {
	if(!strcmp(name, "plist"))
		return TAG_PLIST;
	else if(!strcmp(name, "dict"))
		return TAG_DICT;
	else if(!strcmp(name, "key"))
		return TAG_KEY;
	else if(!strcmp(name, "real"))
		return TAG_REAL;
	else if(!strcmp(name, "string"))
		return TAG_STRING;
	else if(!strcmp(name, "integer"))
		return TAG_INTEGER;
	else if(!strcmp(name, "true"))
		return TAG_TRUE;
	else if(!strcmp(name, "false"))
		return TAG_FALSE;
	else
		return UNKNOWN_PLIST_TAG;
}

#ifdef __cplusplus
}
#endif

wyZwoptexFrame::wyZwoptexFrame() :
		key(NULL),
		rect(wyrZero),
		offset(wypZero),
		sourceSize(wysZero),
		rotated(false) {
}

wyZwoptexFrame::~wyZwoptexFrame() {
	if(key != NULL)
		wyFree((void*)key);
}

wyPoint wyZwoptex::parsePoint(const char* v, float resScale) {
	int len = strlen(v);
	char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
	for(int i = 0, j = 0; i < len; i++) {
		if(!isspace(v[i])) {
			tmp[j++] = v[i];
		}
	}

	float w, h;
	sscanf(tmp, "{%f,%f}", &w, &h);
	wyFree(tmp);
	return wyp(w * resScale, h * resScale);
}

wySize wyZwoptex::parseSize(const char* v, float resScale) {
	int len = strlen(v);
	char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
	for(int i = 0, j = 0; i < len; i++) {
		if(!isspace(v[i])) {
			tmp[j++] = v[i];
		}
	}

	float w, h;
	sscanf(tmp, "{%f,%f}", &w, &h);
	wyFree(tmp);
	return wys(w * resScale, h * resScale);
}

wyRect wyZwoptex::parseRect(const char* v, float resScale) {
	int len = strlen(v);
	char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
	for(int i = 0, j = 0; i < len; i++) {
		if(!isspace(v[i])) {
			tmp[j++] = v[i];
		}
	}

	float x, y, w, h;
	sscanf(tmp, "{{%f,%f},{%f,%f}}", &x, &y, &w, &h);
	wyFree(tmp);
	return wyr(x * resScale, y * resScale, w * resScale, h * resScale);
}

void wyZwoptex::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// set tag
	pushTag(state, getPListTag((const char*)name));

	switch(topTag(state)) {
		case TAG_DICT:
			if(state->lastKey == NULL)
				break;

			switch(state->state) {
				case READY:
					if(!strcmp(state->lastKey, "frames"))
						state->state = PARSING_FRAMES;
					else if(!strcmp(state->lastKey, "metadata")) // XML generic or XML cocos2d format
						state->state = PARSING_METADATA;
					else if(!strcmp(state->lastKey, "texture")) { // XML Legacy format
						state->state = PARSING_TEXTURE;

						// XML Legacy format doesn't have format attribute, we just set it to 1
						state->zwoptex->setFormat(1);
					}
					break;
				case PARSING_FRAMES:
					state->state = PARSING_FRAME;
					wyZwoptexFrame* frame = WYNEW wyZwoptexFrame();
					frame->key = state->lastKey;
					state->lastKey = NULL;
					state->lastFrame = frame;
					break;
			}
			break;
		case TAG_TRUE:
			if(state->state == PARSING_FRAME) {
				if(!strcmp(state->lastKey, "rotated") || !strcmp(state->lastKey, "textureRotated") ) {
					state->lastFrame->rotated = true;
				}
			}
			break;
		case TAG_FALSE:
			if(state->state == PARSING_FRAME) {
				if(!strcmp(state->lastKey, "rotated") || !strcmp(state->lastKey, "textureRotated") ) {
					state->lastFrame->rotated = false;
				}
			}
			break;
	}
}

void wyZwoptex::endElement(void* ctx, const xmlChar *name) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	switch(topTag(state)) {
		case TAG_DICT:
			switch(state->state) {
				case PARSING_FRAME:
					// append frame
					state->zwoptex->addFrame(state->lastFrame);
					state->lastFrame->release();
					state->lastFrame = NULL;
					state->state = PARSING_FRAMES;
					break;
				case PARSING_FRAMES:
				case PARSING_METADATA:
				case PARSING_TEXTURE:
					state->state = READY;
					break;
			}
			break;
	}

	// pop
	popTag(state);
}

void wyZwoptex::characters(void* ctx, const xmlChar *ch, int len) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// check tag
	switch(topTag(state)) {
		case TAG_KEY:
		{
			char* key = (char*)wyCalloc(len + 1, sizeof(char));
			strncpy(key, (const char*)ch, len);
			wyUtils::trim(key);

			// save the last key
			if(state->lastKey != NULL) {
				wyFree((void*)state->lastKey);
				state->lastKey = NULL;
			}
			state->lastKey = key;
			break;
		}
		case TAG_INTEGER:
		{
			switch(state->state) {
				case PARSING_METADATA:
				{
					if(!strcmp(state->lastKey, "format")) {
						char* v = (char*)wyCalloc(len + 1, sizeof(char));
						strncpy(v, (const char*)ch, len);
						wyUtils::trim(v);

						int format = atoi(v);
						state->zwoptex->setFormat(format);

						wyFree(v);
					}
					break;
				}
				case PARSING_TEXTURE:
				{
					if(!strcmp(state->lastKey, "width")) {
						char* v = (char*)wyCalloc(len + 1, sizeof(char));
						strncpy(v, (const char*)ch, len);
						wyUtils::trim(v);
						float width = (float)atof(v);
						wyFree(v);

						wySize size = state->zwoptex->getSize();
						state->zwoptex->setSize(wys(width, size.height));
					} else if(!strcmp(state->lastKey, "height")) {
						char* v = (char*)wyCalloc(len + 1, sizeof(char));
						strncpy(v, (const char*)ch, len);
						wyUtils::trim(v);
						float height = (float)atof(v);
						wyFree(v);

						wySize size = state->zwoptex->getSize();
						state->zwoptex->setSize(wys(size.width, height));
					}
					break;
				}
				case PARSING_FRAME:
				{
					char* v = (char*)wyCalloc(len + 1, sizeof(char));
					strncpy(v, (const char*)ch, len);
					wyUtils::trim(v);

					if(!strcmp(state->lastKey, "x")) {
						state->lastFrame->rect.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "y")) {
						state->lastFrame->rect.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "width")) {
						state->lastFrame->rect.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "height")) {
						state->lastFrame->rect.height = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetX")) {
						state->lastFrame->offset.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetY")) {
						state->lastFrame->offset.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalWidth")) {
						state->lastFrame->sourceSize.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalHeight")) {
						state->lastFrame->sourceSize.height = (float)atof(v) * state->resScale;
					}

					wyFree(v);
					break;
				}
			}
			break;
		}
		case TAG_REAL:
		{
			switch(state->state) {
				case PARSING_FRAME:
				{
					char* v = (char*)wyCalloc(len + 1, sizeof(char));
					strncpy(v, (const char*)ch, len);
					wyUtils::trim(v);

					if(!strcmp(state->lastKey, "x")) {
						state->lastFrame->rect.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "y")) {
						state->lastFrame->rect.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "width")) {
						state->lastFrame->rect.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "height")) {
						state->lastFrame->rect.height = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetX")) {
						state->lastFrame->offset.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetY")) {
						state->lastFrame->offset.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalWidth")) {
						state->lastFrame->sourceSize.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalHeight")) {
						state->lastFrame->sourceSize.height = (float)atof(v) * state->resScale;
					}

					wyFree(v);
					break;
				}
			}
			break;
		}
		case TAG_STRING:
		{
			switch(state->state) {
				case PARSING_METADATA:
					if(!strcmp(state->lastKey, "size")) {
						char* v = (char*)wyCalloc(len + 1, sizeof(char));
						strncpy(v, (const char*)ch, len);
						wyUtils::trim(v);

						wySize size = parseSize(v);
						state->zwoptex->setSize(size);

						wyFree(v);
					}
					break;
				case PARSING_FRAME:
				{
					char* v = (char*)wyCalloc(len + 1, sizeof(char));
					strncpy(v, (const char*)ch, len);
					wyUtils::trim(v);

					if(!strcmp(state->lastKey, "frame") || !strcmp(state->lastKey, "textureRect") ) {
						state->lastFrame->rect = parseRect(v, state->resScale);
					} else if(!strcmp(state->lastKey, "offset") || !strcmp(state->lastKey, "spriteOffset")) {
						state->lastFrame->offset = parsePoint(v, state->resScale);
					} else if(!strcmp(state->lastKey, "sourceSize") || !strcmp(state->lastKey, "spriteSourceSize")) {
						state->lastFrame->sourceSize = parseSize(v, state->resScale);
					} else if(!strcmp(state->lastKey, "sourceColorRect") || !strcmp(state->lastKey, "spriteColorRect")) {
						state->lastFrame->sourceColorRect = parseRect(v, state->resScale);
					} else if(!strcmp(state->lastKey, "x")) {
						state->lastFrame->rect.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "y")) {
						state->lastFrame->rect.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "width")) {
						state->lastFrame->rect.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "height")) {
						state->lastFrame->rect.height = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetX")) {
						state->lastFrame->offset.x = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "offsetY")) {
						state->lastFrame->offset.y = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalWidth")) {
						state->lastFrame->sourceSize.width = (float)atof(v) * state->resScale;
					} else if(!strcmp(state->lastKey, "originalHeight")) {
						state->lastFrame->sourceSize.height = (float)atof(v) * state->resScale;
					}

					wyFree(v);
					break;
				}
			}
		}
	}
}

void wyZwoptex::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyZwoptex::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

wyZwoptex::wyZwoptex(int resId) :
		m_format(0),
		m_size(wysZero),
		m_tex(NULL),
		m_frames(WYNEW WY_ZWOPTEXFRAME_MAP()) {
	load(resId);
}

wyZwoptex::wyZwoptex(const char* path, bool isFile, float inDensity) :
		m_format(0),
		m_size(wysZero),
		m_tex(NULL),
		m_frames(WYNEW WY_ZWOPTEXFRAME_MAP()) {
	load(path, isFile, inDensity);
}

wyZwoptex::~wyZwoptex() {
	wyObjectRelease(m_tex);

	for(WY_ZWOPTEXFRAME_ITER iter = m_frames->begin(); iter != m_frames->end(); iter++) {
		iter->second->release();
	}
	WYDELETE(m_frames);
}

void wyZwoptex::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}

void wyZwoptex::load(const char* data, size_t length, float resScale) {
	// declare handler
	xmlSAXHandlerV1 saxHandler = {
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
	state->zwoptex = this;
	state->tags = (int*)wyMalloc(10 * sizeof(int));
	state->tags[0] = DOCUMENT;
	state->num = 1;
	state->max = 10;
	state->resScale = resScale;

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&saxHandler, state, data, length);

	// clean parser
	xmlCleanupParser();

	/*
	 * 对rotated属性进行特别处理，这个和zwoptex格式有关
	 * 格式为1时，不支持rotate，所以没关系
	 * 格式为2时，frame的rect还是没有旋转过的rect
	 * 格式为3时，frame的rect是旋转过的rect
	 *
	 * 因此我们对格式2进行宽高对换
	 */
	switch(getFormat()) {
		case 2:
			for(WY_ZWOPTEXFRAME_ITER iter = m_frames->begin(); iter != m_frames->end(); iter++) {
				if(iter->second->rotated) {
					float width = iter->second->rect.width;
					iter->second->rect.width = iter->second->rect.height;
					iter->second->rect.height = width;
				}
			}
			break;
	}

	// release helper struct
	if(state->lastKey != NULL)
		wyFree((void*)state->lastKey);
	wyFree(state->tags);
	wyFree(state);
}

void wyZwoptex::load(int resId) {
	size_t len;
	float scale;
	char* data = wyUtils::loadRaw(resId, &len, &scale);
	load(data, len, scale);
	wyFree(data);
}

void wyZwoptex::load(const char* path, bool isFile, float inDensity) {
	if(inDensity == 0)
		inDensity = wyDevice::defaultInDensity;
	size_t len;
	char* data = wyUtils::loadRaw(path, isFile, &len);
	load(data, len, wyDevice::density / inDensity);
	wyFree(data);
}

void wyZwoptex::addFrame(wyZwoptexFrame* frame) {
	(*m_frames)[frame->key] = frame;
	frame->retain();
}

wyZwoptexFrame* wyZwoptex::getFrame(const char* key) {
	WY_ZWOPTEXFRAME_ITER iter = m_frames->find(key);
	return iter == m_frames->end() ? NULL : iter->second;
}

wySpriteFrame* wyZwoptex::getSpriteFrame(const char* key) {
	wyZwoptexFrame* frame = getFrame(key);
	if(frame) {
		wySpriteFrame* sf = wySpriteFrame::make(0, m_tex, frame->rect, frame->offset, frame->sourceSize, frame->rotated);
		return sf;
	} else {
		return NULL;
	}
}

wyRect wyZwoptex::getFrameRect(const char* key) {
	wyZwoptexFrame* frame = getFrame(key);
	return frame == NULL ? wyrZero : frame->rect;
}

wyRect* wyZwoptex::getFrameRects(size_t* count) {
	// copy all rects
	int i = 0;
	wyRect* buf = (wyRect*)wyMalloc(m_frames->size() * sizeof(wyRect));
	for(WY_ZWOPTEXFRAME_ITER iter = m_frames->begin(); iter != m_frames->end(); iter++, i++) {
		memcpy(buf + i, &iter->second->rect, sizeof(wyRect));
	}

	// save count
	if(count)
		*count = m_frames->size();

	// return
	return buf;
}

const char** wyZwoptex::getFrameNames(size_t* count) {
	*count = m_frames->size();
	char** names = (char**)wyCalloc(m_frames->size(), sizeof(char*));
	int i = 0;
	for(WY_ZWOPTEXFRAME_ITER iter = m_frames->begin(); iter != m_frames->end(); iter++, i++) {
		names[i] = (char*)wyUtils::copy(iter->first);
	}
	return (const char**)names;
}
