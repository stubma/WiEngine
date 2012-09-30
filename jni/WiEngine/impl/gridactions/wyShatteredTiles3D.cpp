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
#include "wyShatteredTiles3D.h"
#include "wyNode.h"
#include <stdlib.h>

wyAction* wyShatteredTiles3D::copy() {
	return wyShatteredTiles3D::make(m_duration, m_gridX, m_gridY, m_range, m_shatterZ);
}

void wyShatteredTiles3D::update(float t) {
	if(!m_once) {
		wyDimension gridPos = wydZero;
		for(int i = 0; i < m_gridX; i++) {
			for(int j = 0; j < m_gridY; j++) {
				gridPos.x = i;
				gridPos.y = j;
				wyQuad3D coords = getOriginalTile(gridPos);

				// X
				coords.bl_x += (rand() % (m_range * 2)) - m_range;
				coords.br_x += (rand() % (m_range * 2)) - m_range;
				coords.tl_x += (rand() % (m_range * 2)) - m_range;
				coords.tr_x += (rand() % (m_range * 2)) - m_range;

				// Y
				coords.bl_y += (rand() % (m_range * 2)) - m_range;
				coords.br_y += (rand() % (m_range * 2)) - m_range;
				coords.tl_y += (rand() % (m_range * 2)) - m_range;
				coords.tr_y += (rand() % (m_range * 2)) - m_range;

				if(m_shatterZ) {
					coords.bl_z += (rand() % (m_range * 2)) - m_range;
					coords.br_z += (rand() % (m_range * 2)) - m_range;
					coords.tl_z += (rand() % (m_range * 2)) - m_range;
					coords.tr_z += (rand() % (m_range * 2)) - m_range;
				}

				setTile(gridPos, coords);
			}
		}

		m_once = true;
	}

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyShatteredTiles3D::~wyShatteredTiles3D() {
}

wyShatteredTiles3D::wyShatteredTiles3D(float duration, int gridX, int gridY, int range, bool shatterZ) :
		wyTiledGrid3DAction(duration, gridX, gridY),
		m_range(range),
		m_shatterZ(shatterZ),
		m_once(false) {
}

wyShatteredTiles3D* wyShatteredTiles3D::make(float duration, int gridX, int gridY, int range, bool shatterZ) {
	wyShatteredTiles3D* a = WYNEW wyShatteredTiles3D(duration, gridX, gridY, range, shatterZ);
	return (wyShatteredTiles3D*)a->autoRelease();
}
