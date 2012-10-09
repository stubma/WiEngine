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
#include "wyLeftBottomTilesShrinkOut.h"
#include "wyNode.h"

float wyLeftBottomTilesShrinkOut::tileTest(wyDimension pos, float time) {
	wyPoint n = wyp(m_gridX * time, m_gridY * time);
	if((n.x + n.y) == 0.0f)
		return 1.0f;
	return pow((pos.x + pos.y) / (n.x + n.y), 6);
}

void wyLeftBottomTilesShrinkOut::turnOnTile(wyDimension pos) {
	setTile(pos, getOriginalTile(pos));
}

void wyLeftBottomTilesShrinkOut::turnOffTile(wyDimension pos) {
	wyQuad3D quad = wyq3Zero;
	setTile(pos, quad);
}

void wyLeftBottomTilesShrinkOut::transformTile(wyDimension pos, float distance) {
	wyQuad3D coords = getOriginalTile(pos);
	wyPoint step = wyp(m_target->getGrid()->getStepWidth(), m_target->getGrid()->getStepHeight());

	coords.bl_x += (step.x / 2) * (1.0f - distance);
	coords.bl_y += (step.y / 2) * (1.0f - distance);

	coords.br_x -= (step.x / 2) * (1.0f - distance);
	coords.br_y += (step.y / 2) * (1.0f - distance);

	coords.tl_x += (step.x / 2) * (1.0f - distance);
	coords.tl_y -= (step.y / 2) * (1.0f - distance);

	coords.tr_x -= (step.x / 2) * (1.0f - distance);
	coords.tr_y -= (step.y / 2) * (1.0f - distance);

	setTile(pos, coords);
}

wyAction* wyLeftBottomTilesShrinkOut::copy() {
	return wyLeftBottomTilesShrinkOut::make(m_duration, m_gridX, m_gridY);
}

void wyLeftBottomTilesShrinkOut::update(float t) {
	wyDimension gridPos = wydZero;
	for(int i = 0; i < m_gridX; i++) {
		for(int j = 0; j < m_gridY; j++) {
			gridPos.x = i;
			gridPos.y = j;
			float distance = tileTest(gridPos, t);
			if(distance == 0)
				turnOffTile(gridPos);
			else if(distance < 1)
				transformTile(gridPos, distance);
			else
				turnOnTile(gridPos);
		}
	}

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyLeftBottomTilesShrinkOut::~wyLeftBottomTilesShrinkOut() {
}

wyLeftBottomTilesShrinkOut::wyLeftBottomTilesShrinkOut(float duration, int gridX, int gridY) : wyTiledGrid3DAction(duration, gridX, gridY) {
}

wyLeftBottomTilesShrinkOut* wyLeftBottomTilesShrinkOut::make(float duration, int gridX, int gridY) {
	wyLeftBottomTilesShrinkOut* a = WYNEW wyLeftBottomTilesShrinkOut(duration, gridX, gridY);
	return (wyLeftBottomTilesShrinkOut*)a->autoRelease();
}
