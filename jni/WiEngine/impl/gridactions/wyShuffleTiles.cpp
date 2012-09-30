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
#include "wyShuffleTiles.h"
#include <stdlib.h>
#include "wyNode.h"
#include "wyLog.h"

void wyShuffleTiles::shuffle(int* array) {
	int len = m_gridX * m_gridY;
	for(int i = len - 1; i >= 0; i--) {
		int j = rand() % (i + 1);
		int v = array[i];
		array[i] = array[j];
		array[j] = v;
	}
}

wyDimension wyShuffleTiles::getDelta(wyDimension pos) {
	wyDimension pos2 = wydZero;
	int idx = pos.x * m_gridY + pos.y;
	pos2.x = m_tilesOrder[idx] / m_gridY;
	pos2.y = m_tilesOrder[idx] % m_gridY;

	return wyd(pos2.x - pos.x, pos2.y - pos.y);
}

void wyShuffleTiles::placeTile(wyDimension pos, wyTile* t) {
	wyQuad3D coords = getOriginalTile(pos);

	wyPoint step = wyp(m_target->getGrid()->getStepWidth(), m_target->getGrid()->getStepHeight());
	coords.bl_x += (int)(t->position.x * step.x);
	coords.bl_y += (int)(t->position.y * step.y);

	coords.br_x += (int)(t->position.x * step.x);
	coords.br_y += (int)(t->position.y * step.y);

	coords.tl_x += (int)(t->position.x * step.x);
	coords.tl_y += (int)(t->position.y * step.y);

	coords.tr_x += (int)(t->position.x * step.x);
	coords.tr_y += (int)(t->position.y * step.y);

	setTile(pos, coords);
}

wyShuffleTiles::~wyShuffleTiles() {
	wyFree(m_tilesOrder);
	wyFree(m_tiles);
}

wyAction* wyShuffleTiles::copy() {
	return wyShuffleTiles::make(m_duration, m_gridX, m_gridY);
}

void wyShuffleTiles::start(wyNode* target) {
	wyTiledGrid3DAction::start(target);

	// get tile order array
	int tileCount = m_gridX * m_gridY;
	m_tilesOrder = (int*)wyMalloc(tileCount * sizeof(int));
	for(int i = 0; i < tileCount; i++)
		m_tilesOrder[i] = i;

	// shuffle tiles
	shuffle(m_tilesOrder);

	// get tile object array
	m_tiles = (wyTile*)wyCalloc(tileCount, sizeof(wyTile));

	// initial every tile object
	int index = 0;
	wyDimension gridPos = wydZero;
	for(int i = 0; i < m_gridX; i++) {
		for(int j = 0; j < m_gridY; j++) {
			m_tiles[index].position = wyp(i, j);
			m_tiles[index].startPosition = wyp(i, j);
			gridPos.x = i;
			gridPos.y = j;
			m_tiles[index++].delta = getDelta(gridPos);
		}
	}
}

void wyShuffleTiles::update(float t) {
	int index = 0;
	wyDimension gridPos = wydZero;
	for(int i = 0; i < m_gridX; i++) {
		for(int j = 0; j < m_gridY; j++) {
			m_tiles[index].position = wyp(m_tiles[index].delta.x * t, m_tiles[index].delta.y * t);
			gridPos.x = i;
			gridPos.y = j;
			placeTile(gridPos, m_tiles + index);
			index++;
		}
	}

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyShuffleTiles::wyShuffleTiles(float duration, int gridX, int gridY) :
		wyTiledGrid3DAction(duration, gridX, gridY),
		m_tilesOrder(NULL),
		m_tiles(NULL) {
}

wyShuffleTiles* wyShuffleTiles::make(float duration, int gridX, int gridY) {
	wyShuffleTiles* a = WYNEW wyShuffleTiles(duration, gridX, gridY);
	return (wyShuffleTiles*)a->autoRelease();
}
