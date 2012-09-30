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
#include "wyShaky3D.h"
#include "wyNode.h"
#include <stdlib.h>

wyAction* wyShaky3D::copy() {
	return wyShaky3D::make(m_duration, m_gridX, m_gridY, m_range, m_deltaRange, m_shakeZ);
}

void wyShaky3D::update(float t) {
	int i, j;

	wyDimension gridPos = wydZero;
	for(i = 0; i < (m_gridX + 1); i++) {
		for(j = 0; j < (m_gridY + 1); j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D v = getOriginalVertex(gridPos);
			v.x += m_lastRange == 0 ? 0 : ((rand() % (m_lastRange * 2)) - m_lastRange);
			v.y += m_lastRange == 0 ? 0 : ((rand() % (m_lastRange * 2)) - m_lastRange);
			if(m_shakeZ)
				v.z += (rand() % (m_lastRange * 2)) - m_lastRange;

			setVertex(gridPos, v);
		}
	}

	m_lastRange = (int)(m_range + m_deltaRange * t);

	// super only call callback
	wyGrid3DAction::update(t);
}

wyShaky3D::~wyShaky3D() {
}

wyShaky3D::wyShaky3D(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ) :
		wyGrid3DAction(duration, gridX, gridY),
		m_range(range),
		m_deltaRange(deltaRange),
		m_lastRange(0),
		m_shakeZ(shakeZ) {
}

wyShaky3D* wyShaky3D::make(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ) {
	wyShaky3D* a = WYNEW wyShaky3D(duration, gridX, gridY, range, deltaRange, shakeZ);
	return (wyShaky3D*)a->autoRelease();
}
