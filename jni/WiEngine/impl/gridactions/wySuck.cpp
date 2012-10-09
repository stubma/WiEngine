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
#include "wySuck.h"
#include "wyNode.h"
#include "wyLog.h"
#include "wyGlobal.h"

wySuck::~wySuck() {
}

wySuck::wySuck(float duration, int gridX, int gridY, float positionX, float positionY) :
		wyGrid3DAction(duration, gridX, gridY),
		m_positionX(positionX),
		m_positionY(positionY),
		m_maxDistance(0) {
}

wySuck* wySuck::make(float duration, int gridX, int gridY, float positionX, float positionY) {
	wySuck* a = WYNEW wySuck(duration, gridX, gridY, positionX, positionY);
	return (wySuck*)a->autoRelease();
}

wyAction* wySuck::copy() {
	return wySuck::make(m_duration, m_gridX, m_gridY, m_positionX, m_positionY);
}

void wySuck::start(wyNode* target) {
	wyGrid3DAction::start(target);

	wyPoint suck = wyp(m_positionX, m_positionY);
	m_maxDistance = MAX(m_maxDistance, wypDistance(suck, wyp(0, 0)));
	m_maxDistance = MAX(m_maxDistance, wypDistance(suck, wyp(m_target->getWidth(), 0)));
	m_maxDistance = MAX(m_maxDistance, wypDistance(suck, wyp(m_target->getWidth(), m_target->getHeight())));
	m_maxDistance = MAX(m_maxDistance, wypDistance(suck, wyp(0, m_target->getHeight())));
}

void wySuck::update(float t) {
	// suck position
	wyPoint suck = wyp(m_positionX, m_positionY);
	
	wyDimension gridPos = wydZero;
	for(int i = 0; i <= m_gridX; i++) {
		for(int j = 0; j <= m_gridY; j++) {
			// Get original vertex
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D v = getOriginalVertex(gridPos);
			
			// get distance between grid position and suck position
			float dx = fabs(v.x - suck.x);
			float dy = fabs(v.y - suck.y);
			float d = wyMath::sqrt(dx * dx + dy * dy);

			if(d > 0) {
				// calculate offset
				float s = m_maxDistance / d;
				float valx = dx * t * s;
				float valy = dy * t * s;

				// offset vertex and make sure it is valid
				if(v.x < suck.x) {
					v.x += valx;
					v.x = MIN(suck.x, v.x);
				} else {
					v.x -= valx;
					v.x = MAX(suck.x, v.x);
				}
				if(v.y < suck.y) {
					v.y += valy;
					v.y = MIN(suck.y, v.y);
				} else {
					v.y -= valy;
					v.y = MAX(suck.y, v.y);
				}
			}

			// set new position
			setVertex(gridPos, v);
		}
	}

	// super only call callback
	wyGrid3DAction::update(t);
}
