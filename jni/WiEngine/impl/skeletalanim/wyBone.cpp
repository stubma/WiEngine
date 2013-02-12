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

wyBone::wyBone() :
		m_parent(NULL),
		m_length(0) {
	m_curState.x = 0;
	m_curState.y = 0;
	m_curState.rotation = 0;
	m_curState.scaleX = 1;
	m_curState.scaleY = 1;
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

void wyBone::pushSnapshot() {
	m_stateStack.push_back(m_curState);
}

void wyBone::popSnapshot() {
	if(!m_stateStack.empty()) {
		m_curState = m_stateStack.back();
		m_stateStack.pop_back();
	}
}

void wyBone::addChild(wyBone* bone) {
	m_children.push_back(bone);
	wyObjectRetain(bone);
	bone->setParent(this);
}

void wyBone::setRotationRelativeToTop(float dr) {
	if(!m_stateStack.empty()) {
		State& top = m_stateStack.back();
		m_curState.rotation = top.rotation + dr;
	}
}

void wyBone::setXRelativeToTop(float dx) {
	if(!m_stateStack.empty()) {
		State& top = m_stateStack.back();
		m_curState.x = top.x + dx;
	}
}

void wyBone::setYRelativeToTop(float dy) {
	if(!m_stateStack.empty()) {
		State& top = m_stateStack.back();
		m_curState.y = top.y + dy;
	}
}

void wyBone::setScaleXRelativeToTop(float dx) {
	if(!m_stateStack.empty()) {
		State& top = m_stateStack.back();
		m_curState.scaleX = top.scaleX + dx;
	}
}

void wyBone::setScaleYRelativeToTop(float dy) {
	if(!m_stateStack.empty()) {
		State& top = m_stateStack.back();
		m_curState.scaleY = top.scaleY + dy;
	}
}