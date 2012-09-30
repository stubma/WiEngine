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

void wyGrid3D::blit() {
	int n = m_gridX * m_gridY;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, m_vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);
	glDrawElements(GL_TRIANGLES, n * 6, GL_UNSIGNED_SHORT, m_indices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void wyGrid3D::reuse() {
	if(m_reuseGrid > 0) {
		memcpy(m_vertices, m_originalVertices, sizeof(wyVertex3D) * (m_gridX + 1) * (m_gridY + 1));
		m_reuseGrid--;
	}
}

void wyGrid3D::calculateVertexPoints() {
	// texture real size
	int width = wyMath::getNextPOT(m_width);
	int height = wyMath::getNextPOT(m_height);

	// allocate buffers
	int numVertex = (m_gridX + 1) * (m_gridY + 1);
	m_vertices = (GLfloat*)wyCalloc(numVertex, sizeof(wyVertex3D));
	m_originalVertices = (GLfloat*)wyCalloc(numVertex, sizeof(wyVertex3D));
	m_texCoords = (GLfloat*)wyCalloc(numVertex * 2, sizeof(GLfloat));
	m_indices = (GLushort*)wyCalloc(m_gridX * m_gridY * 6, sizeof(GLushort));

	// temp buffer
	int* vIndex = (int*)wyCalloc(4, sizeof(int));
	wyVertex3D* v = (wyVertex3D*)wyCalloc(4, sizeof(wyVertex3D));
	int* tIndex = (int*)wyCalloc(4, sizeof(int));
	wyPoint* t = (wyPoint*)wyCalloc(4, sizeof(wyPoint));

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
			m_indices[start++] = a;
			m_indices[start++] = b;
			m_indices[start++] = d;
			m_indices[start++] = b;
			m_indices[start++] = c;
			m_indices[start++] = d;

			// get vertex of four corners
			vIndex[0] = a * 3;
			vIndex[1] = b * 3;
			vIndex[2] = c * 3;
			vIndex[3] = d * 3;
			v[0].x = x1;
			v[0].y = y1;
			v[1].x = x2;
			v[1].y = y1;
			v[2].x = x2;
			v[2].y = y2;
			v[3].x = x1;
			v[3].y = y2;

			// get texture coordinates
			tIndex[0] = a * 2;
			tIndex[1] = b * 2;
			tIndex[2] = c * 2;
			tIndex[3] = d * 2;
			t[0].x = x1;
			t[0].y = y1;
			t[1].x = x2;
			t[1].y = y1;
			t[2].x = x2;
			t[2].y = y2;
			t[3].x = x1;
			t[3].y = y2;

			// write vertices and text coordinates to buffer
			for(int i = 0; i < 4; i++) {
				m_vertices[vIndex[i]] = v[i].x;
				m_vertices[vIndex[i] + 1] = v[i].y;
				m_vertices[vIndex[i] + 2] = v[i].z;

				float x = t[i].x;
				float y = t[i].y;

				m_texCoords[tIndex[i]] = x / width;
				m_texCoords[tIndex[i] + 1] = y / height;
			}
		}
	}

	// free temp buffers
	wyFree(vIndex);
	wyFree(v);
	wyFree(tIndex);
	wyFree(t);

	// copy vertices to original buffer
	memcpy(m_originalVertices, m_vertices, sizeof(wyVertex3D) * numVertex);
}

wyGrid3D::~wyGrid3D() {
}

wyGrid3D* wyGrid3D::make(float w, float h, int c, int r) {
	wyGrid3D* g = WYNEW wyGrid3D(w, h, c, r);
	return (wyGrid3D*)g->autoRelease();
}

wyGrid3D::wyGrid3D(float w, float h, int c, int r) : wyBaseGrid(w, h, c, r) {
	calculateVertexPoints();
}

void wyGrid3D::setVertex(wyDimension pos, wyVertex3D vertex) {
	int index = (pos.x * (m_gridY + 1) + pos.y) * 3;
	memcpy(m_vertices + index, &vertex, sizeof(wyVertex3D));
}

wyVertex3D wyGrid3D::getVertex(wyDimension pos) {
	int index = (pos.x * (m_gridY + 1) + pos.y) * 3;
	wyVertex3D v;
	memcpy(&v, m_vertices + index, sizeof(wyVertex3D));
	return v;
}

wyVertex3D wyGrid3D::getOriginalVertex(wyDimension pos) {
	int index = (pos.x * (m_gridY + 1) + pos.y) * 3;
	wyVertex3D v;
	memcpy(&v, m_originalVertices + index, sizeof(wyVertex3D));
	return v;
}
