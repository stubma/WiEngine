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
#include "wyTurnOffTiles.h"
#include <stdlib.h>
#include "wyNode.h"
#include "wyLog.h"

void wyTurnOffTiles::shuffle(int* array) {
	int len = m_gridX * m_gridY;
	for(int i = len - 1; i >= 0; i--) {
		int j = rand() % (i + 1);
		int v = array[i];
		array[i] = array[j];
		array[j] = v;
	}
}

void wyTurnOffTiles::turnOnTile(wyDimension pos) {
	setTile(pos, getOriginalTile(pos));
}

void wyTurnOffTiles::turnOffTile(wyDimension pos) {
	wyQuad3D quad = wyq3Zero;
	setTile(pos, quad);
}

wyTurnOffTiles::~wyTurnOffTiles() {
	wyFree(m_tilesOrder);
}

wyAction* wyTurnOffTiles::copy() {
	return wyTurnOffTiles::make(m_duration, m_gridX, m_gridY);
}

void wyTurnOffTiles::start(wyNode* target) {
	wyTiledGrid3DAction::start(target);

	int tilesCount = m_gridX * m_gridY;
	m_tilesOrder = (int*)wyMalloc(tilesCount * sizeof(int));
	for(int i = 0; i < tilesCount; i++)
		m_tilesOrder[i] = i;

	shuffle(m_tilesOrder);
}

void wyTurnOffTiles::update(float t) {
	int tilesCount = m_gridX * m_gridY;
	int l = (int)(t * tilesCount);

	for(int i = 0; i < tilesCount; i++) {
		int t = m_tilesOrder[i];
		wyDimension tilePos = wyd(t / m_gridY, t % m_gridY);

		if(i < l)
			turnOffTile(tilePos);
		else
			turnOnTile(tilePos);
	}

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyTurnOffTiles::wyTurnOffTiles(float duration, int gridX, int gridY) :
		wyTiledGrid3DAction(duration, gridX, gridY),
		m_tilesOrder(NULL) {
}

wyTurnOffTiles* wyTurnOffTiles::make(float duration, int gridX, int gridY) {
	wyTurnOffTiles* a = WYNEW wyTurnOffTiles(duration, gridX, gridY);
	return (wyTurnOffTiles*)a->autoRelease();
}
