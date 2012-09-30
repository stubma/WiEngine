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
#include "wyArrayTileMapAtlas.h"
#include <stdlib.h>
#include "wyLog.h"

wyArrayTileMapAtlas::wyArrayTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles) :
		m_xTiles(xTiles),
		m_yTiles(yTiles),
		wyTileMapAtlas(tex, tileWidth, tileHeight),
		m_tiles((int*)wyCalloc(xTiles * yTiles, sizeof(int))) {
	if(tiles != NULL)
		memcpy(m_tiles, tiles, xTiles * yTiles * sizeof(int));
	m_atlasIndices = (int*)wyRealloc(m_atlasIndices, xTiles * yTiles * sizeof(int));
	initTileValues();

    // set content size
	setContentSize(xTiles * tileWidth, yTiles * tileHeight);
}

wyArrayTileMapAtlas::~wyArrayTileMapAtlas() {
	wyFree(m_tiles);
}

wyArrayTileMapAtlas* wyArrayTileMapAtlas::make(wyTexture2D* tex, int tileWidth, int tileHeight, int xTiles, int yTiles, int* tiles) {
	wyArrayTileMapAtlas* n = WYNEW wyArrayTileMapAtlas(tex, tileWidth, tileHeight, xTiles, yTiles, tiles);
	return (wyArrayTileMapAtlas*)n->autoRelease();
}

bool wyArrayTileMapAtlas::hasTileAt(int x, int y){
	return m_tiles[x + y * m_xTiles] != 0;
}

int wyArrayTileMapAtlas::tileValueAt(int x, int y) {
	return m_tiles[x + y * m_xTiles];
}

void wyArrayTileMapAtlas::refreshTileValues() {
	initTileValues();
}
