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
#include "wyTMXObject.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"

// for code simple and maintenance, SS means string to string
#define SS_MAP map<const char*, const char*, wyStrPredicate>
#define SS_ITER SS_MAP::iterator
#define SS_P pair<const char*, const char*>

wyTMXObject::wyTMXObject() :
		m_type(NORMAL) {
	m_pairs = WYNEW SS_MAP();
}

wyTMXObject::~wyTMXObject() {
	// release pairs
	for(SS_ITER iter = m_pairs->begin(); iter != m_pairs->end(); iter++) {
		wyFree((void*)iter->first);
		wyFree((void*)iter->second);
	}
	WYDELETE(m_pairs);
}

wyTMXObject* wyTMXObject::make() {
	wyTMXObject* o = WYNEW wyTMXObject();
	return (wyTMXObject*)o->autoRelease();
}

const char* wyTMXObject::getProperty(const char* key) {
	SS_ITER iter = m_pairs->find(key);
	if(iter != m_pairs->end()) {
		return iter->second;
	} else {
		return NULL;
	}
}

wyPoint wyTMXObject::getPosition() {
	const char* xs = getProperty("x");
	const char* ys = getProperty("y");
	wyPoint p = wypZero;
	if(xs)
		sscanf(xs, "%f", &p.x);
	if(ys)
		sscanf(ys, "%f", &p.y);
	return p;
}

wySize wyTMXObject::getSize() {
	const char* ws = getProperty("width");
	const char* hs = getProperty("height");
	wySize s = wysZero;
	if(ws)
		sscanf(ws, "%f", &s.width);
	if(hs)
		sscanf(hs, "%f", &s.height);
	return s;
}

void wyTMXObject::addProperty(const char* key, const char* value) {
	// if has this key, release it
	SS_ITER iter = m_pairs->find(key);
	if(iter != m_pairs->end()) {
		wyFree((void*)iter->first);
		wyFree((void*)iter->second);
		m_pairs->erase(iter);
	}

	// insert new key value
	(*m_pairs)[wyUtils::copy(key)] = wyUtils::copy(value);
}
