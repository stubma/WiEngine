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
#include "wyTileMapAtlas.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyQuadList.h"

void wyTileMapAtlas::calculateItemsToRender() {
	int width = getHorizontalTileCount();
	int height = getVerticalTileCount();
	m_itemsToRender = 0;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (hasTileAt(x, y))
				m_itemsToRender++;
		}
	}
}

float wyTileMapAtlas::mapTileTexY(int value) {
	return (value / m_itemsPerRow) * m_texStepY;
}

float wyTileMapAtlas::mapTileTexX(int value) {
	return (value % m_itemsPerRow) * m_texStepX;
}

void wyTileMapAtlas::updateAtlas(wyPoint pos, int tileValue, int idx) {
	wyQuad2D texCoord;
	wyQuad3D vertex;
	int x = pos.x;
	int y = pos.y;
	float row = mapTileTexX(tileValue);
	float col = mapTileTexY(tileValue);

	float left = row;
	float right = row + m_texStepX;
	float top = col;
	float bottom = col + m_texStepY;
	texCoord.bl_x = left;
	texCoord.bl_y = bottom;
	texCoord.br_x = right;
	texCoord.br_y = bottom;
	texCoord.tl_x = left;
	texCoord.tl_y = top;
	texCoord.tr_x = right;
	texCoord.tr_y = top;

	vertex.bl_x = x * m_itemWidth;
	vertex.bl_y = y * m_itemHeight;
	vertex.bl_z = 0.0f;
	vertex.br_x = x * m_itemWidth + m_itemWidth;
	vertex.br_y = y * m_itemHeight;
	vertex.br_z = 0.0f;
	vertex.tl_x = x * m_itemWidth;
	vertex.tl_y = y * m_itemHeight + m_itemHeight;
	vertex.tl_z = 0.0f;
	vertex.tr_x = x * m_itemWidth + m_itemWidth;
	vertex.tr_y = y * m_itemHeight + m_itemHeight;
	vertex.tr_z = 0.0f;

	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->updateQuad(texCoord, vertex, idx);
}

void wyTileMapAtlas::updateAtlasValues() {
	int width = getHorizontalTileCount();
	int height = getVerticalTileCount();
	int total = 0;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (total < m_itemsToRender) {
				int value = tileValueAt(x, y);
				if (value != 0) {
					updateAtlas(wyp(x, y), value, total);

					// save atlas in map
					m_atlasIndices[x + y * width] = total;

					total++;
				}
			}
		}
	}
}

wyTileMapAtlas::~wyTileMapAtlas() {
	if(m_atlasIndices != NULL) {
		wyFree(m_atlasIndices);
		m_atlasIndices = NULL;
	}
}

wyTileMapAtlas::wyTileMapAtlas(wyTexture2D* tex, int tileWidth, int tileHeight) :
		wyAtlasNode(tex, tileWidth, tileHeight, 0),
		m_atlasIndices((int*)wyCalloc(1, sizeof(int))),
		m_itemsToRender(0) {
}

void wyTileMapAtlas::initTileValues() {
    // find how many items
    calculateItemsToRender();

    // update atlas
    updateAtlasValues();
}

int wyTileMapAtlas::getTile(int x, int y) {
	int width = getHorizontalTileCount();
	int height = getVerticalTileCount();
	if(x < 0 || x >= width)
		return 0;
	if(y < 0 || y >= height)
		return 0;

	return tileValueAt(x, y);
}

void wyTileMapAtlas::setTile(int tileValue, int x, int y) {
	// find atlas index and update atlas
	int width = getHorizontalTileCount();
	int num = m_atlasIndices[x + y * width];
	updateAtlas(wyp(x, y), tileValue, num);
}
