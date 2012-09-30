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
#include "wyHexagonAStarMap.h"
#include "wyAStarMap.h"
#include "wyAStarTile.h"

wyHexagonAStarMap::wyHexagonAStarMap(int width, int height) :
	wyAStarMap(), m_width(width), m_height(height) {

	m_tiles = wyArrayNew(m_width * m_height);
	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			wyArrayPush(m_tiles, WYNEW wyAStarTile(TILE_FREE, x, y));
		}
	}

	// auto clilds
	for (int i = 0; i < m_tiles->num; i++) {
		wyAStarTile* tile = (wyAStarTile*) wyArrayGet(m_tiles, i);
		int y_max = (tile->getX() % 2) ? 2 : 1;
		int y_min = (tile->getX() % 2) ? 0 : -1;
		int child_y = (tile->getX() % 2) ? -1 : 1;

		wyAStarTile* neighbor = getTileAt(tile->getX(), tile->getY() + child_y);
		if (neighbor != tile && neighbor != NULL) {
			tile->pushChild(neighbor);
		}

		for (int x = -1; x < 2; x++) {
			for (int y = y_min; y < y_max; y++) {
				neighbor = getTileAt(tile->getX() + x, tile->getY() + y);
				if (neighbor != tile && neighbor != NULL) {
					tile->pushChild(neighbor);
				}
			}
		}
	}
}

wyHexagonAStarMap::~wyHexagonAStarMap() {

}

bool wyHexagonAStarMap::isValidTile(int x, int y) {
	if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
		return false;
	}
	return true;
}

float wyHexagonAStarMap::getStepG(wyAStarTile* t1, wyAStarTile* t2) {
	float cost = 0.0f;
	cost = t1->getGRate() + t2->getGRate();
	return cost;
}
