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

void wyTiledGrid3D::blit() {
	// TODO gles2
//    int n = m_gridX * m_gridY;
//
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//
//    glVertexPointer(3, GL_FLOAT, 0, m_vertices);
//    glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);
//    glDrawElements(GL_TRIANGLES, n * 6, GL_UNSIGNED_SHORT, m_indices);
//
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void wyTiledGrid3D::reuse() {
	if(m_reuseGrid > 0) {
		memcpy(m_vertices, m_originalVertices, sizeof(wyQuad3D) * m_gridX * m_gridY);
		m_reuseGrid--;
	}
}

void wyTiledGrid3D::calculateVertexPoints() {
	// get best width and height
	int width = wyMath::getNextPOT(m_width);
	int height = wyMath::getNextPOT(m_height);

	// allocate buffers
	int numQuads = m_gridX * m_gridY;
	m_vertices = (GLfloat*)wyCalloc(numQuads, sizeof(wyQuad3D));
	m_originalVertices = (GLfloat*)wyCalloc(numQuads, sizeof(wyQuad3D));
	m_texCoords = (GLfloat*)wyCalloc(numQuads, sizeof(wyQuad2D));
	m_indices = (GLushort*)wyCalloc(numQuads * 6, sizeof(GLushort));

	int vStart = 0;
	int tStart = 0;
    for (int x = 0; x < m_gridX; x++) {
        for (int y = 0; y < m_gridY; y++) {
            float x1 = x * m_stepWidth;
            float x2 = x1 + m_stepWidth;
            float y1 = y * m_stepHeight;
            float y2 = y1 + m_stepHeight;

            m_vertices[vStart++] = x1;
            m_vertices[vStart++] = y1;
            m_vertices[vStart++] = 0;
            m_vertices[vStart++] = x2;
            m_vertices[vStart++] = y1;
            m_vertices[vStart++] = 0;
            m_vertices[vStart++] = x1;
            m_vertices[vStart++] = y2;
            m_vertices[vStart++] = 0;
            m_vertices[vStart++] = x2;
            m_vertices[vStart++] = y2;
            m_vertices[vStart++] = 0;		
			
            m_texCoords[tStart++] = x1 / width;
            m_texCoords[tStart++] = y1 / height;
            m_texCoords[tStart++] = x2 / width;
            m_texCoords[tStart++] = y1 / height;
            m_texCoords[tStart++] = x1 / width;
            m_texCoords[tStart++] = y2 / height;
            m_texCoords[tStart++] = x2 / width;
            m_texCoords[tStart++] = y2 / height;
        }
    }

    // set indices
    for (int x = 0; x < numQuads; x++) {
    	m_indices[x * 6] = (GLushort)(x * 4);
    	m_indices[x * 6 + 1] = (GLushort)(x * 4 + 1);
    	m_indices[x * 6 + 2] = (GLushort)(x * 4 + 2);

    	m_indices[x * 6 + 3] = (GLushort)(x * 4 + 1);
    	m_indices[x * 6 + 4] = (GLushort)(x * 4 + 2);
    	m_indices[x * 6 + 5] = (GLushort)(x * 4 + 3);
    }

    // copy vertices to original buffer
    memcpy(m_originalVertices, m_vertices, sizeof(wyQuad3D) * numQuads);
}

wyTiledGrid3D::~wyTiledGrid3D() {
}

wyTiledGrid3D* wyTiledGrid3D::make(float w, float h, int c, int r) {
	wyTiledGrid3D* g = WYNEW wyTiledGrid3D(w, h, c, r);
	return (wyTiledGrid3D*)g->autoRelease();
}

wyTiledGrid3D::wyTiledGrid3D(float w, float h, int c, int r) : wyBaseGrid(w, h, c, r) {
	calculateVertexPoints();
}

void wyTiledGrid3D::setTile(wyDimension pos, wyQuad3D coords) {
    int idx = (m_gridY * pos.x + pos.y) * sizeof(wyQuad3D) / sizeof(float);
    memcpy(m_vertices + idx, &coords, sizeof(wyQuad3D));
}

wyQuad3D wyTiledGrid3D::getTile(wyDimension pos) {
    int idx = (m_gridY * pos.x + pos.y) * sizeof(wyQuad3D) / sizeof(float);
    wyQuad3D tile;
    memcpy(&tile, m_vertices + idx, sizeof(wyQuad3D));
    return tile;
}

wyQuad3D wyTiledGrid3D::getOriginalTile(wyDimension pos) {
    int idx = (m_gridY * pos.x + pos.y) * sizeof(wyQuad3D) / sizeof(float);
    wyQuad3D tile;
    memcpy(&tile, m_originalVertices + idx, sizeof(wyQuad3D));
    return tile;
}
