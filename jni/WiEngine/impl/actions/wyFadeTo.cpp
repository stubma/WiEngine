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
#include "wyFadeTo.h"
#include "wyNode.h"

wyAction* wyFadeTo::copy() {
	return wyFadeTo::make(m_duration, m_fromAlpha, m_toAlpha, m_includeChildren);
}

wyAction* wyFadeTo::reverse() {
	return wyFadeTo::make(m_duration, m_toAlpha, m_fromAlpha, m_includeChildren);
}

void wyFadeTo::start(wyNode* target) {
	wyIntervalAction::start(target);

	if(m_includeChildren)
		updateAlpha(m_target, m_fromAlpha);
	else
		target->setAlpha(m_fromAlpha);
}

void wyFadeTo::update(float t) {
	if(m_includeChildren)
		updateAlpha(m_target, (int)(m_fromAlpha + (m_toAlpha - m_fromAlpha) * t));
	else
		m_target->setAlpha((int)(m_fromAlpha + (m_toAlpha - m_fromAlpha) * t));

	// super only call callback
	wyIntervalAction::update(t);
}

wyFadeTo::wyFadeTo(float duration, int fromAlpha, int toAlpha, bool includeChildren) :
		wyIntervalAction(duration),
		m_toAlpha(toAlpha),
		m_fromAlpha(fromAlpha),
		m_includeChildren(includeChildren) {
}

wyFadeTo::~wyFadeTo() {
}

wyFadeTo* wyFadeTo::make(float duration, int fromAlpha, int toAlpha, bool includeChildren) {
	wyFadeTo* a = WYNEW wyFadeTo(duration, fromAlpha, toAlpha, includeChildren);
	return (wyFadeTo*)a->autoRelease();
}

void wyFadeTo::updateAlpha(wyNode* node, int alpha) {
	node->setAlpha(alpha);

	wyArray* children = node->getChildren();
	for(int i = 0; i < children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(children, i);
		updateAlpha(child, alpha);
	}
}
