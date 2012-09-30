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
#include "wyParallaxNode.h"
#include "wyParallaxObject.h"
#include "wyGlobal.h"
#include <stdlib.h>
#include "wyLog.h"

wyParallaxNode* wyParallaxNode::make() {
	wyParallaxNode* n = WYNEW wyParallaxNode();
	return (wyParallaxNode*)n->autoRelease();
}

wyParallaxNode::wyParallaxNode() :
		m_parallaxObjects(wyArrayNew(5)),
		m_xOffset(0),
		m_yOffset(0),
		m_flinging(false),
		m_scroller(WYNEW wyScroller()),
		m_minXOffset(-MAX_FLOAT / 2),
		m_minYOffset(-MAX_FLOAT / 2),
		m_maxXOffset(MAX_FLOAT / 2),
		m_maxYOffset(MAX_FLOAT / 2) {
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

	// schedule fling timer
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyParallaxNode::updateFling));
	wyTimer* timer = wyTimer::make(ts);
	scheduleLocked(timer);
}

wyParallaxNode::~wyParallaxNode() {
	wyArrayEach(m_parallaxObjects, releaseObject, NULL);
	wyArrayDestroy(m_parallaxObjects);

	m_scroller->release();
}

bool wyParallaxNode::releaseObject(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

void wyParallaxNode::setMinX(float x) {
	m_minXOffset = MAX(-MAX_FLOAT / 2, MIN(MAX_FLOAT / 2, x));
}

void wyParallaxNode::setMaxX(float x) {
	m_maxXOffset = MAX(-MAX_FLOAT / 2, MIN(MAX_FLOAT / 2, x));
}

void wyParallaxNode::setMinY(float y) {
	m_minYOffset = MAX(-MAX_FLOAT / 2, MIN(MAX_FLOAT / 2, y));
}

void wyParallaxNode::setMaxY(float y) {
	m_maxYOffset = MAX(-MAX_FLOAT / 2, MIN(MAX_FLOAT / 2, y));
}

void wyParallaxNode::updateFling(wyTargetSelector* ts) {
	if(m_scroller->computeScrollOffset()) {
		float dx = m_scroller->getCurrX() - m_xOffset;
		float dy = m_scroller->getCurrY() - m_yOffset;
		offsetBy(dx, dy);
	} else {
		m_flinging = false;
	}
}

void wyParallaxNode::offsetBy(float dx, float dy) {
	float newXOffset = m_xOffset + dx;
	float newYOffset = m_yOffset + dy;
	newXOffset = MAX(m_minXOffset, MIN(m_maxXOffset, newXOffset));
	newYOffset = MAX(m_minYOffset, MIN(m_maxYOffset, newYOffset));

	dx = newXOffset - m_xOffset;
	dy = newYOffset - m_yOffset;
	m_xOffset = newXOffset;
	m_yOffset = newYOffset;

	for(int i = 0; i < m_parallaxObjects->num; i++) {
		wyParallaxObject* po = (wyParallaxObject*)wyArrayGet(m_parallaxObjects, i);
		po->translate(dx * po->getRatioX(), dy * po->getRatioY());
	}
}

void wyParallaxNode::fling(float velocityX, float velocityY) {
	if(!m_flinging) {
		m_flinging = true;
		m_scroller->fling(m_xOffset, m_yOffset, velocityX, velocityY, m_minXOffset, m_maxXOffset, m_minYOffset, m_maxYOffset);
	}
}

void wyParallaxNode::stopFling() {
	// stop fling
	if(m_flinging) {
		m_scroller->forceFinished(true);
		m_flinging = false;
	}
}

void wyParallaxNode::addChild(wyNode* child, int z, int tag) {
	LOGW("Parallax node doesn't support original addChild");
}

void wyParallaxNode::removeChild(wyNode* child, bool cleanup) {
	for(int i = 0; i < m_parallaxObjects->num; i++) {
		wyParallaxObject* po = (wyParallaxObject*)wyArrayGet(m_parallaxObjects, i);
		if(po->getNode() == child) {
			wyArrayDeleteIndex(m_parallaxObjects, i);
			po->release();
			break;
		}
	}
	wyNode::removeChild(child, cleanup);
}

void wyParallaxNode::removeAllChildren(bool cleanup) {
	if(m_parallaxObjects != NULL) {
		wyArrayEach(m_parallaxObjects, releaseObject, NULL);
		wyArrayClear(m_parallaxObjects);
	}
	wyNode::removeAllChildren(cleanup);
}

void wyParallaxNode::addChild(wyNode* child, int z, float ratioX, float ratioY) {
	// add child
	if(child != NULL) {
		wyParallaxObject* obj = child->createParallaxObject();
		obj->setNode(child);
		obj->setRatioX(ratioX);
		obj->setRatioY(ratioY);
		wyArrayPush(m_parallaxObjects, obj);
		obj->retain();

		// don't call wyNodeAddChildLocked3 because it is overrided by parallax node
		wyNode::addChild(child, z, child->getTag());
	}
}
