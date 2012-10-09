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
#include "wyShakyTiles3D.h"
#include "wyNode.h"
#include <stdlib.h>
#include "wyLog.h"

wyAction* wyShakyTiles3D::copy() {
	return wyShakyTiles3D::make(m_duration, m_gridX, m_gridY, m_range, m_deltaRange, m_shakeZ);
}

void wyShakyTiles3D::update(float t) {
	wyDimension gridPos = wydZero;
	for(int i = 0; i < m_gridX; i++) {
		for(int j = 0; j < m_gridY; j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyQuad3D coords = getOriginalTile(gridPos);

			if(m_lastRange != 0) {
				// X
				coords.bl_x += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.br_x += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.tl_x += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.tr_x += (rand() % (m_lastRange * 2)) - m_lastRange;
				
				// Y
				coords.bl_y += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.br_y += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.tl_y += (rand() % (m_lastRange * 2)) - m_lastRange;
				coords.tr_y += (rand() % (m_lastRange * 2)) - m_lastRange;
				
				if(m_shakeZ) {
					coords.bl_z += (rand() % (m_lastRange * 2)) - m_lastRange;
					coords.br_z += (rand() % (m_lastRange * 2)) - m_lastRange;
					coords.tl_z += (rand() % (m_lastRange * 2)) - m_lastRange;
					coords.tr_z += (rand() % (m_lastRange * 2)) - m_lastRange;
				}	
			}

			setTile(gridPos, coords);
		}
	}

	m_lastRange = (int)(m_range + m_deltaRange * t);

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyShakyTiles3D::~wyShakyTiles3D() {
}

wyShakyTiles3D::wyShakyTiles3D(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ) :
		wyTiledGrid3DAction(duration, gridX, gridY),
		m_range(range),
		m_deltaRange(deltaRange),
		m_lastRange(0),
		m_shakeZ(shakeZ) {
}

wyShakyTiles3D* wyShakyTiles3D::make(float duration, int gridX, int gridY, int range, int deltaRange, bool shakeZ) {
	wyShakyTiles3D* a = WYNEW wyShakyTiles3D(duration, gridX, gridY, range, deltaRange, shakeZ);
	return (wyShakyTiles3D*)a->autoRelease();
}
