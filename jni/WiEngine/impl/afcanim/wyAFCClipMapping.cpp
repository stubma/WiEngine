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
#include "wyAFCClipMapping.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wySpriteBatchNode.h"
#include "wyGlobal.h"

/// data is in parsing
static const char* s_data;

/// position of read
static int s_pos;

static short readShort() {
	short ret = *(short*)(s_data + s_pos);
	ret = letoh16(ret);
	s_pos += sizeof(short);
	return ret;
}

wyAFCClipMapping::wyAFCClipMapping(int tag) :
		m_tag(tag),
		m_count(0),
		m_capacity(10),
		m_rules((wyAFCClipMappingRule*)wyMalloc(sizeof(wyAFCClipMappingRule) * m_capacity)),
		m_sourceClipIndices((int*)wyMalloc(sizeof(int) * m_capacity)) {
}

wyAFCClipMapping::~wyAFCClipMapping() {
	// release batch node in rules
	wyAFCClipMappingRule* r = m_rules;
	for(int i = 0; i < m_count; i++, r++) {
		switch(r->type) {
			case AFC_CMR_EXTERNAL_CLIP:
				wyObjectRelease(r->ecr.sheet);
				break;
			case AFC_CMR_EXTERNAL_ATLAS:
				wyObjectRelease(r->ear.sheet);
				break;
		}
	}

	// free buffer
	wyFree(m_rules);
	wyFree(m_sourceClipIndices);
}

wyAFCClipMapping* wyAFCClipMapping::make(int tag) {
	wyAFCClipMapping* m = WYNEW wyAFCClipMapping(tag);
	return (wyAFCClipMapping*)m->autoRelease();
}

wyAFCClipMapping* wyAFCClipMapping::makeAurora(int tag, const char* data, size_t length) {
	// create empty mapping
	wyAFCClipMapping* m = make(tag);

	/*
	 * parse module mapping data, its format is simple
	 * 1. [SRC CLIP INDEX][DEST CLIP INDEX]
	 * 2. [SRC CLIP INDEX][DEST CLIP INDEX]
	 * 3. [SRC CLIP INDEX][DEST CLIP INDEX]
	 * ...
	 *
	 * index are 2 bytes and in little endian
	 */
	s_data = data;
	s_pos = 0;
	while(s_pos + 4 <= length) {
		/*
		 * Don't use m->mapClip(readShort(), readShort()), it looks ok
		 * at first glance, but the readShort invocation order depends on argument
		 * push priority. If right argument is pushed first, then right readShort
		 * will be called first and it is definitely not what we expect
		 */
		short from = readShort();
		short to = readShort();
		m->mapClip(from, to);
	}

	return m;
}

wyAFCClipMapping* wyAFCClipMapping::makeAurora(int tag, int ammId) {
	size_t len;
	char* data = wyUtils::loadRaw(ammId, &len, NULL);
	wyAFCClipMapping* m = makeAurora(tag, data, len);
	wyFree(data);
	return m;
}

wyAFCClipMapping* wyAFCClipMapping::makeAurora(int tag, const char* ammPath, bool isFile) {
	size_t len;
	char* data = wyUtils::loadRaw(ammPath, isFile, &len);
	wyAFCClipMapping* m = makeAurora(tag, data, len);
	wyFree(data);
	return m;
}

wyAFCClipMapping* wyAFCClipMapping::makeMemoryAurora(int tag, const char* mfsName) {
	size_t len;
	char* data = wyUtils::loadRaw(mfsName, &len);
	wyAFCClipMapping* m = makeAurora(tag, data, len);
	wyFree(data);
	return m;
}

void wyAFCClipMapping::mapClip(int fromClipIndex, int toClipIndex) {
	ensureCapacity();

	int insertion = wyUtils::binarySearch(m_sourceClipIndices, m_count, fromClipIndex);
	if(insertion < 0) {
		// get insertion point
		insertion = -insertion - 1;

		// if need move, move it
		if(insertion < m_count) {
			memmove(m_sourceClipIndices + insertion + 1, m_sourceClipIndices + insertion, sizeof(int) * (m_count - insertion));
			memmove(m_rules + insertion + 1, m_rules + insertion, sizeof(wyAFCClipMappingRule) * (m_count - insertion));
		}

		// set source index
		m_sourceClipIndices[insertion] = fromClipIndex;

		// set rule
		m_rules[insertion].type = AFC_CMR_INTERNAL_CLIP;
		m_rules[insertion].sourceClipIndex = fromClipIndex;
		m_rules[insertion].icr.destClipIndex = toClipIndex;
		
		// increase count
		m_count++;
	}
}

void wyAFCClipMapping::mapClip(int fromClipIndex, int externalFileDataId, int toClipIndex) {
	ensureCapacity();

	int insertion = wyUtils::binarySearch(m_sourceClipIndices, m_count, fromClipIndex);
	if(insertion < 0) {
		// get insertion point
		insertion = -insertion - 1;

		// if need move, move it
		if(insertion < m_count) {
			memmove(m_sourceClipIndices + insertion + 1, m_sourceClipIndices + insertion, sizeof(int) * (m_count - insertion));
			memmove(m_rules + insertion + 1, m_rules + insertion, sizeof(wyAFCClipMappingRule) * (m_count - insertion));
		}

		// set source index
		m_sourceClipIndices[insertion] = fromClipIndex;

		// set rule
		m_rules[insertion].type = AFC_CMR_EXTERNAL_CLIP;
		m_rules[insertion].sourceClipIndex = fromClipIndex;
		m_rules[insertion].ecr.dataId = externalFileDataId;
		m_rules[insertion].ecr.destClipIndex = toClipIndex;

		// increase count
		m_count++;
	}
}

void wyAFCClipMapping::mapClip(int fromClipIndex, wyTexture2D* tex, wyPoint pos, wyRect texRect, bool flipX, float rotation) {
	ensureCapacity();

	int insertion = wyUtils::binarySearch(m_sourceClipIndices, m_count, fromClipIndex);
	if(insertion < 0) {
		// get insertion point
		insertion = abs(insertion) - 1;

		// if need move, move it
		if(insertion < m_count) {
			memmove(m_sourceClipIndices + insertion + 1, m_sourceClipIndices + insertion, sizeof(int) * (m_count - insertion));
			memmove(m_rules + insertion + 1, m_rules + insertion, sizeof(wyAFCClipMappingRule) * (m_count - insertion));
		}

		// set source index
		m_sourceClipIndices[insertion] = fromClipIndex;

		// set rule
		m_rules[insertion].type = AFC_CMR_EXTERNAL_ATLAS;
		m_rules[insertion].sourceClipIndex = fromClipIndex;
		m_rules[insertion].ear.sheet = wySpriteBatchNode::make(tex);
		m_rules[insertion].ear.sheet->retain();
		if(texRect.width == 0 || texRect.height == 0)
			m_rules[insertion].ear.texRect = wyr(0, 0, tex->getWidth(), tex->getHeight());
		else
			m_rules[insertion].ear.texRect = texRect;
		m_rules[insertion].ear.pos = pos;
		m_rules[insertion].ear.flipX = flipX;
		m_rules[insertion].ear.rotation = rotation;

		// increase count
		m_count++;
	}
}

void wyAFCClipMapping::ensureCapacity() {
	while(m_count >= m_capacity) {
		m_capacity *= 2;
		m_rules = (wyAFCClipMappingRule*)wyRealloc(m_rules, sizeof(wyAFCClipMappingRule) * m_capacity);
		m_sourceClipIndices = (int*)wyRealloc(m_sourceClipIndices, sizeof(int) * m_capacity);
	}
}

wyAFCClipMappingRule* wyAFCClipMapping::findRule(int sourceClipIndex) {
	int index = wyUtils::binarySearch(m_sourceClipIndices, m_count, sourceClipIndex);
	if(index >= 0)
		return m_rules + index;
	else
		return NULL;
}
