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
#include "wyFollow.h"
#include "wyNode.h"
#include "wyGlobal.h"
#include "wyLog.h"

wyFollow* wyFollow::make(wyNode* fNode, wyRect worldBoundary) {
	wyFollow* a = WYNEW wyFollow(fNode, worldBoundary);
	return (wyFollow*)a->autoRelease();
}

wyFollow::wyFollow(wyNode* fNode, wyRect rect) {
	m_followedNode = fNode;
	fNode->retain();

	m_fullScreenSize = wyp(wyDevice::winWidth, wyDevice::winHeight);
	m_halfScreenSize = wypMul2(m_fullScreenSize, 0.5f);
	m_boundaryFullyCovered = false;

	wyRect zeroRect = wyrZero;
	if (wyrEquals(zeroRect, rect)) {
		m_boundarySet = false;
	} else {
		m_boundarySet = true;

		m_leftBoundary = -((rect.x + rect.width) - m_fullScreenSize.x);
		m_rightBoundary = -rect.x ;
		m_topBoundary = -rect.y;
		m_bottomBoundary = -((rect.y + rect.height) - m_fullScreenSize.y);

		if (m_rightBoundary < m_leftBoundary) {
			// screen width is larger than world's boundary width
			//set both in the middle of the world
			m_rightBoundary = m_leftBoundary = (m_leftBoundary + m_rightBoundary) / 2;
		}
		if (m_topBoundary < m_bottomBoundary) {
			// screen width is larger than world's boundary width
			//set both in the middle of the world
			m_topBoundary = m_bottomBoundary = (m_topBoundary + m_bottomBoundary) / 2;
		}

		if( (m_topBoundary == m_bottomBoundary) && (m_leftBoundary == m_rightBoundary) )
			m_boundaryFullyCovered = true;
	}
}

wyFollow::~wyFollow() {
	m_followedNode->release();
}

void wyFollow::step(float t) {
	if (m_boundarySet) {
		if(m_boundaryFullyCovered)
			return;

		float tempx = m_halfScreenSize.x - m_followedNode->getPositionX();
		float tempy = m_halfScreenSize.y - m_followedNode->getPositionY();

		if (m_leftBoundary > m_rightBoundary) {
			tempx = tempx < m_rightBoundary ? m_rightBoundary : tempx < m_leftBoundary? tempx : m_leftBoundary;
		} else {
			tempx = tempx < m_leftBoundary ? m_leftBoundary : tempx < m_rightBoundary? tempx : m_rightBoundary;
		}

		if (m_bottomBoundary > m_topBoundary) {
			tempy = tempy < m_topBoundary ? m_topBoundary : tempy < m_bottomBoundary? tempy : m_bottomBoundary;
		} else {
			tempy = tempy < m_bottomBoundary ? m_bottomBoundary : tempy < m_topBoundary? tempy : m_topBoundary;
		}

		m_target->setPosition(tempx, tempy);
	} else {
		m_target->setPosition(m_halfScreenSize.x - m_followedNode->getPositionX(), m_halfScreenSize.y - m_followedNode->getPositionY());
	}
}

bool wyFollow::isDone() {
	return !m_followedNode->isRunning();
}
