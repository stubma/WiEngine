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
#include "wyMoveByPath.h"
#include "wyNode.h"
#include <stdlib.h>

wyMoveByPath::wyMoveByPath() :
		wyIntervalAction(0),
		m_pointCount(0),
		m_capacity(10),
		m_segmentStartTime(0),
		m_currentSegment(0),
		m_pinPoint(wyp(MAX_FLOAT, MAX_FLOAT)),
		m_pinDelta(0),
		m_autoRotate(false),
		m_angleDelta(0) {
	m_points = (float*)wyMalloc(m_capacity * 2 * sizeof(float));
	m_durations = (float*)wyMalloc(m_capacity * sizeof(float));
}

wyMoveByPath::~wyMoveByPath() {
	wyFree(m_points);
	wyFree(m_durations);
}

wyMoveByPath* wyMoveByPath::make() {
	wyMoveByPath* a = WYNEW wyMoveByPath();
	return (wyMoveByPath*)a->autoRelease();
}

void wyMoveByPath::addPoint(float x, float y, float duration) {
	while(m_pointCount >= m_capacity) {
		m_capacity *= 2;
		m_points = (float*)wyRealloc(m_points, m_capacity * 2 * sizeof(float));
		m_durations = (float*)wyRealloc(m_durations, m_capacity * sizeof(float));
	}

	m_points[m_pointCount * 2] = x;
	m_points[m_pointCount * 2 + 1] = y;
	if(m_pointCount > 0) {
		m_duration += duration;
		m_durations[m_pointCount - 1] = duration;
	}
	m_pointCount++;
}

wyAction* wyMoveByPath::copy() {
	wyMoveByPath* ret = wyMoveByPath::make();
	for(int i = 0; i < m_pointCount; i++) {
		ret->addPoint(m_points[i * 2], m_points[i * 2 + 1], i > 0 ? m_durations[i - 1] : 0);
	}
	ret->setAutoRotate(m_autoRotate, m_angleDelta);
	ret->setPinAngleDelta(m_pinDelta);
	ret->setPinPoint(m_pinPoint);
	return ret;
}

wyAction* wyMoveByPath::reverse() {
	wyMoveByPath* ret = wyMoveByPath::make();
	for(int i = m_pointCount - 1; i >= 0; i--) {
		ret->addPoint(m_points[i * 2], m_points[i * 2 + 1], m_durations[i]);
	}
	ret->setAutoRotate(m_autoRotate, 180 - m_angleDelta);
	ret->setPinAngleDelta(m_pinDelta);
	ret->setPinPoint(m_pinPoint);
	return ret;
}

void wyMoveByPath::start(wyNode* target) {
	wyIntervalAction::start(target);
	m_currentSegment = 0;
	m_segmentStartTime = 0;
}

void wyMoveByPath::update(float t) {
	// find current segment
	float curTime = m_duration * t;
	float segmentTime = m_durations[m_currentSegment];
	float dt = curTime - m_segmentStartTime;
	while(dt > segmentTime && m_currentSegment < m_pointCount - 1) {
		m_currentSegment++;
		m_segmentStartTime += segmentTime;
		dt -= segmentTime;
		segmentTime = m_durations[m_currentSegment];
	}

	// update node position
	if(m_currentSegment < m_pointCount - 1) {
		float segPercent = dt / segmentTime;
		float x = m_points[m_currentSegment * 2] * (1 - segPercent) + m_points[(m_currentSegment + 1) * 2] * segPercent;
		float y = m_points[m_currentSegment * 2 + 1] * (1 - segPercent) + m_points[(m_currentSegment + 1) * 2 + 1] * segPercent;
		m_target->setPosition(x, y);
	}
	
	// update rotation
	if(m_autoRotate) {
		wyPoint d;
		d.x = m_points[(m_currentSegment + 1) * 2] - m_points[m_currentSegment * 2];
		d.y = m_points[(m_currentSegment + 1) * 2 + 1] - m_points[m_currentSegment * 2 + 1];
		float angle = -wypToDegree(d);
		angle += m_angleDelta;
		m_target->setRotation(angle);
	} else if(m_pinPoint.x != MAX_FLOAT && m_pinPoint.y != MAX_FLOAT) {
		wyPoint anchor = wyp(m_target->getAnchorPointX(), m_target->getAnchorPointY());
		anchor = m_target->nodeToWorldSpace(anchor);
		float angle = wypToDegree(wypSub(m_pinPoint, anchor));
		m_target->setRotation(-angle + m_pinDelta);
	}

	wyIntervalAction::update(t);
}

void wyMoveByPath::setAutoRotate(bool flag, float angleDelta) {
	m_autoRotate = flag;
	m_angleDelta = angleDelta;
}
