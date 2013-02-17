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
#include "wyBone.h"
#include "wyLog.h"
#include "wySkeletalSprite.h"

wyBone::wyBone() :
		m_parent(NULL),
		m_length(0),
        m_flags(0) {
	m_originalState.x = 0;
	m_originalState.y = 0;
	m_originalState.rotation = 0;
	m_originalState.scaleX = 1;
	m_originalState.scaleY = 1;
	m_originalState.node = NULL;
}

wyBone::~wyBone() {
	for(BonePtrList::iterator iter = m_children.begin(); iter != m_children.end(); iter++) {
		wyObjectRelease(*iter);
	}
}

wyBone* wyBone::make() {
	wyBone* b = WYNEW wyBone();
	return (wyBone*)b->autoRelease();
}

void wyBone::addChild(wyBone* bone) {
	m_children.push_back(bone);
	wyObjectRetain(bone);
	bone->setParent(this);
}

wyBone::State& wyBone::getState(wySkeletalSprite* owner) {
	StateMap::iterator iter = m_stateMap.find(owner);
	if(iter != m_stateMap.end()) {
		return iter->second;
	} else {
		m_stateMap[owner] = m_originalState;
		iter = m_stateMap.find(owner);
		return iter->second;
	}
}

void wyBone::clearState(wySkeletalSprite* owner) {
	StateMap::iterator iter = m_stateMap.find(owner);
	if(iter != m_stateMap.end())
		m_stateMap.erase(iter);
}