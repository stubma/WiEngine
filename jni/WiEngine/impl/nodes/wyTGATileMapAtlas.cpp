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
#include "wyTGATileMapAtlas.h"
#include <stdlib.h>

wyTGATileMapAtlas::wyTGATileMapAtlas(wyTexture2D* tex, int mapResId, int tileWidth, int tileHeight) :
		wyTileMapAtlas(tex, tileWidth, tileHeight),
		m_tga(wyTGALoader::load(mapResId)),
		m_rowBytes(m_tga->bytesPerPixel * m_tga->width) {
	// resize index array
	m_atlasIndices = (int*)wyRealloc(m_atlasIndices, m_tga->width * m_tga->height * sizeof(int));

    // set content size
	setContentSize(m_tga->width * m_itemWidth, m_tga->height * m_itemHeight);

    // init map
	initTileValues();
}

wyTGATileMapAtlas::~wyTGATileMapAtlas() {
    if (m_tga != NULL) {
    	wyTGALoader::destroyTGA(m_tga);
    	m_tga = NULL;
    }
}

wyTGATileMapAtlas* wyTGATileMapAtlas::make(wyTexture2D* tex, int mapResId, int tileWidth, int tileHeight) {
	wyTGATileMapAtlas* n = WYNEW wyTGATileMapAtlas(tex, mapResId, tileWidth, tileHeight);
	return (wyTGATileMapAtlas*)n->autoRelease();
}

bool wyTGATileMapAtlas::hasTileAt(int x, int y){
	return tileValueAt(x, y) != 0;
}

int wyTGATileMapAtlas::tileValueAt(int x, int y) {
	// map red component as tile value
	return m_tga->imageData[x * m_tga->bytesPerPixel + y * m_rowBytes] & 0xff;
}
