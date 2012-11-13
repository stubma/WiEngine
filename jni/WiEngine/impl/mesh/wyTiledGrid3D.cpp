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
#include "wyTiledGrid3D.h"
#include <stdlib.h>
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"

void wyTiledGrid3D::reuse() {
	m_buf->copy(m_backup);
}

void wyTiledGrid3D::update() {
	// clear old data
	m_buf->clear();
	m_indices->clear();

	// ensure capacity of buffers
	int numQuads = m_gridX * m_gridY;
	m_buf->reserve(numQuads * 4);
	m_indices->reserve(numQuads * 6);

	// get raw buffer
	GLushort* indices = (GLushort*)m_indices->getData();
	Vertex* v = (Vertex*)m_buf->getData();

	// texture step in normal setting, which means not flipped
	float texStepX = m_stepWidth / m_texPOTWidth;
	float texStepY = -m_stepHeight / m_texPOTHeight;
	float texStartX = 0;
	float texStartY = m_texSourceHeight / m_texPOTHeight;

	// need reverse step if flip flag is set
	if(m_flipX) {
		texStepX = -texStepX;
		texStartX = m_texSourceWidth / m_texPOTWidth;
	}
	if(m_flipY) {
		texStepY = -texStepY;
		texStartY = 0;
	}

	// fill
	int index = 0;
    for (int x = 0; x < m_gridX; x++) {
        for (int y = 0; y < m_gridY; y++) {
            float x1 = x * m_stepWidth;
            float x2 = x1 + m_stepWidth;
            float y1 = y * m_stepHeight;
            float y2 = y1 + m_stepHeight;

            kmVec3Fill(&v[index].pos, x1, y1, 0);
            kmVec2Fill(&v[index].tex, texStartX + x * texStepX, texStartY + y * texStepY);
            kmVec4Fill(&v[index++].color, 1, 1, 1, 1);

            kmVec3Fill(&v[index].pos, x2, y1, 0);
            kmVec2Fill(&v[index].tex, texStartX + (x + 1) * texStepX, texStartY + y * texStepY);
            kmVec4Fill(&v[index++].color, 1, 1, 1, 1);

            kmVec3Fill(&v[index].pos, x1, y2, 0);
            kmVec2Fill(&v[index].tex, texStartX + x * texStepX, texStartY + (y + 1) * texStepY);
            kmVec4Fill(&v[index++].color, 1, 1, 1, 1);

            kmVec3Fill(&v[index].pos, x2, y2, 0);
            kmVec2Fill(&v[index].tex, texStartX + (x + 1) * texStepX, texStartY + (y + 1) * texStepY);
            kmVec4Fill(&v[index++].color, 1, 1, 1, 1);
        }
    }

    // set indices
    for (int x = 0; x < numQuads; x++) {
    	indices[x * 6] = (GLushort)(x * 4);
    	indices[x * 6 + 1] = (GLushort)(x * 4 + 1);
    	indices[x * 6 + 2] = (GLushort)(x * 4 + 2);

    	indices[x * 6 + 3] = (GLushort)(x * 4 + 1);
    	indices[x * 6 + 4] = (GLushort)(x * 4 + 2);
    	indices[x * 6 + 5] = (GLushort)(x * 4 + 3);
    }

	// manually set element count
	m_buf->setElementCount(numQuads * 4);
	m_indices->setElementCount(numQuads * 6);

	// copy vertices to original buffer
	m_backup->copy(m_buf);
}

wyTiledGrid3D::~wyTiledGrid3D() {
	m_backup->release();
}

wyTiledGrid3D* wyTiledGrid3D::make(float w, float h, int c, int r) {
	wyTiledGrid3D* g = WYNEW wyTiledGrid3D(w, h, c, r);
	return (wyTiledGrid3D*)g->autoRelease();
}

wyTiledGrid3D::wyTiledGrid3D(float w, float h, int c, int r) : wyBaseGrid(w, h, c, r) {
	// create backup buffer
	m_backup = wyBuffer::makeCustom(sizeof(Vertex));
	m_backup->retain();
}

void wyTiledGrid3D::setTile(wyDimension pos, wyQuad3D coords) {
	Vertex* v = (Vertex*)m_buf->getData();
    int idx = (m_gridY * pos.x + pos.y) * 4;
    kmVec3Fill(&v[idx++].pos, coords.bl_x, coords.bl_y, coords.bl_z);
    kmVec3Fill(&v[idx++].pos, coords.br_x, coords.br_y, coords.br_z);
    kmVec3Fill(&v[idx++].pos, coords.tl_x, coords.tl_y, coords.tl_z);
    kmVec3Fill(&v[idx].pos, coords.tr_x, coords.tr_y, coords.tr_z);
}

wyQuad3D wyTiledGrid3D::getTile(wyDimension pos) {
	Vertex* v = (Vertex*)m_buf->getData();
    int idx = (m_gridY * pos.x + pos.y) * 4;

    wyQuad3D tile;
    tile.bl_x = v[idx].pos.x;
    tile.bl_y = v[idx].pos.y;
    tile.bl_z = v[idx++].pos.z;
    tile.br_x = v[idx].pos.x;
    tile.br_y = v[idx].pos.y;
    tile.br_z = v[idx++].pos.z;
    tile.tl_x = v[idx].pos.x;
    tile.tl_y = v[idx].pos.y;
    tile.tl_z = v[idx++].pos.z;
    tile.tr_x = v[idx].pos.x;
    tile.tr_y = v[idx].pos.y;
    tile.tr_z = v[idx].pos.z;

    return tile;
}

wyQuad3D wyTiledGrid3D::getOriginalTile(wyDimension pos) {
	Vertex* v = (Vertex*)m_backup->getData();
    int idx = (m_gridY * pos.x + pos.y) * 4;

    wyQuad3D tile;
    tile.bl_x = v[idx].pos.x;
    tile.bl_y = v[idx].pos.y;
    tile.bl_z = v[idx++].pos.z;
    tile.br_x = v[idx].pos.x;
    tile.br_y = v[idx].pos.y;
    tile.br_z = v[idx++].pos.z;
    tile.tl_x = v[idx].pos.x;
    tile.tl_y = v[idx].pos.y;
    tile.tl_z = v[idx++].pos.z;
    tile.tr_x = v[idx].pos.x;
    tile.tr_y = v[idx].pos.y;
    tile.tr_z = v[idx].pos.z;

    return tile;
}

void wyTiledGrid3D::updateColor4B(wyColor4B color) {
	float r = color.r / 255.0f;
	float g = color.g / 255.0f;
	float b = color.b / 255.0f;
	float a = color.a / 255.0f;
	int c = m_buf->getElementCount();
	Vertex* v = (Vertex*)m_buf->getData();
	for(int i = 0; i < c; i++, v++) {
		kmVec4Fill(&v[0].color, r, g, b, a);
	}
}
