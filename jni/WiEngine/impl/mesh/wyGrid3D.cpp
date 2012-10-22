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
#include "wyGrid3D.h"
#include <stdlib.h>
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyPrimitives.h"

void wyGrid3D::reuse() {
	m_buf->copy(m_backup);
}

void wyGrid3D::calculateVertexPoints() {
	// texture real size
	int width = wyMath::getNextPOT(m_width);
	int height = wyMath::getNextPOT(m_height);

	// ensure capacity of buffers
	int numVertex = (m_gridX + 1) * (m_gridY + 1);
	m_buf->reserve(numVertex);
	m_indices->reserve(m_gridX * m_gridY * 6);

	// get raw buffer
	GLushort* indices = (GLushort*)m_indices->getData();
	Vertex* v = (Vertex*)m_buf->getData();

	for(int x = 0; x < m_gridX; x++) {
		for(int y = 0; y < m_gridY; y++) {
			int idx = (y * m_gridX) + x;

			// get quadratic corners coordinates
			float x1 = x * m_stepWidth;
			float x2 = x1 + m_stepWidth;
			float y1 = y * m_stepHeight;
			float y2 = y1 + m_stepHeight;

			// get corner point indices
			GLushort a = (GLushort)(x * (m_gridY + 1) + y);
			GLushort b = (GLushort)((x + 1) * (m_gridY + 1) + y);
			GLushort c = (GLushort)((x + 1) * (m_gridY + 1) + (y + 1));
			GLushort d = (GLushort)(x * (m_gridY + 1) + (y + 1));

			// set indices
			int start = 6 * idx;
			indices[start++] = a;
			indices[start++] = b;
			indices[start++] = d;
			indices[start++] = b;
			indices[start++] = c;
			indices[start++] = d;

			// corner 1
			kmVec3Fill(&v[a].pos, x1, y1, 0);
			kmVec2Fill(&v[a].tex, x1 / width, y1 / height);
			kmVec4Fill(&v[a].color, 1, 1, 1, 1);

			// corner 2
			kmVec3Fill(&v[b].pos, x2, y1, 0);
			kmVec2Fill(&v[b].tex, x2 / width, y1 / height);
			kmVec4Fill(&v[b].color, 1, 1, 1, 1);

			// corner 3
			kmVec3Fill(&v[c].pos, x2, y2, 0);
			kmVec2Fill(&v[c].tex, x2 / width, y2 / height);
			kmVec4Fill(&v[c].color, 1, 1, 1, 1);

			// corner 4
			kmVec3Fill(&v[d].pos, x1, y2, 0);
			kmVec2Fill(&v[d].tex, x1 / width, y2 / height);
			kmVec4Fill(&v[d].color, 1, 1, 1, 1);
		}
	}

	// manually set element count
	m_buf->setElementCount(numVertex);
	m_indices->setElementCount(m_gridX * m_gridY * 6);

	// copy vertices to original buffer
	m_backup->copy(m_buf);
}

wyGrid3D::~wyGrid3D() {
	m_backup->release();
}

wyGrid3D* wyGrid3D::make(float w, float h, int c, int r) {
	wyGrid3D* g = WYNEW wyGrid3D(w, h, c, r);
	return (wyGrid3D*)g->autoRelease();
}

wyGrid3D::wyGrid3D(float w, float h, int c, int r) : wyBaseGrid(w, h, c, r) {
	// create backup buffer
	m_backup = wyBuffer::makeCustom(sizeof(Vertex));
	m_backup->retain();

	calculateVertexPoints();
}

void wyGrid3D::setVertex(wyDimension pos, wyVertex3D vertex) {
	int index = pos.x * (m_gridY + 1) + pos.y;
	Vertex* v = (Vertex*)m_buf->getData();
	kmVec3Fill(&v[index].pos, vertex.x, vertex.y, vertex.z);
}

wyVertex3D wyGrid3D::getVertex(wyDimension pos) {
	int index = pos.x * (m_gridY + 1) + pos.y;
	Vertex* v = (Vertex*)m_buf->getData();
	wyVertex3D ret;
	memcpy(&ret, &v[index].pos, sizeof(wyVertex3D));
	return ret;
}

wyVertex3D wyGrid3D::getOriginalVertex(wyDimension pos) {
	int index = pos.x * (m_gridY + 1) + pos.y;
	Vertex* v = (Vertex*)m_backup->getData();
	wyVertex3D ret;
	memcpy(&ret, &v[index].pos, sizeof(wyVertex3D));
	return ret;
}
