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
#include "wyTexture2D.h"
#include "wyTextureAtlas.h"
#include <stdlib.h>
#include "wyLog.h"

void wyTextureAtlas::initIndices() {
	for(int i = 0; i < m_capacity; i++) {
		m_indices[i * 6] = (GLushort)(i * 4);
		m_indices[i * 6 + 1] = (GLushort)(i * 4 + 1);
		m_indices[i * 6 + 2] = (GLushort)(i * 4 + 2);

		// inverted index.
		m_indices[i * 6 + 5] = (GLushort)(i * 4 + 1);
		m_indices[i * 6 + 4] = (GLushort)(i * 4 + 2);
		m_indices[i * 6 + 3] = (GLushort)(i * 4 + 3);
	}
}

void wyTextureAtlas::initColorArray() {
	if(!m_withColorArray) {
		int count = m_capacity * 4;
		int size = m_capacity * 4 * sizeof(wyColor4B);
		m_colors = (GLubyte*)wyMalloc(size);
		GLubyte* p = m_colors;
		for(int i = 0; i < count; i++, p += sizeof(wyColor4B)) {
			memcpy(p, &m_color, sizeof(wyColor4B));
		}

		m_withColorArray = true;
	}
}

void wyTextureAtlas::putTexCoords(wyQuad2D* quadT, int index) {
	memcpy((GLubyte*)m_texCoords + index * sizeof(wyQuad2D), quadT, sizeof(wyQuad2D));
}

void wyTextureAtlas::putVertex(wyQuad3D* quadV, int index) {
	memcpy((GLubyte*)m_vertices + index * sizeof(wyQuad3D), quadV, sizeof(wyQuad3D));
}

void wyTextureAtlas::putColor(wyColor4B* color, int index) {
	for(int j = 0; j < 4; j++) {
		memcpy(m_colors + index * sizeof(wyColor4B) * 4 + sizeof(wyColor4B) * j, color, sizeof(wyColor4B));
	}
}

void wyTextureAtlas::setColor(wyColor4B color) {
	m_color = color;
	initColorArray();
}

void wyTextureAtlas::setAlpha(int alpha) {
	m_color.a = alpha;
	initColorArray();
}

void wyTextureAtlas::reduceAlpha(float delta) {
	if(m_withColorArray) {
		// reduce alpha
		int count = m_totalQuads * 4;
		GLubyte* p = m_colors;
		for(int i = 0; i < count; i++, p += sizeof(wyColor4B)) {
			int alpha = p[3] & 0xff;
			alpha -= delta * 255;
			alpha = MAX(0, alpha);
			p[3] = alpha & 0xff;
		}

		// purge quads
		int endPurge = 0;
		p = m_colors;
		for(int i = 0; i < count; i++, p += 4 * sizeof(wyColor4B)) {
			if(p[3] <= 0 && p[7] <= 0 && p[11] <= 0 && p[15] <= 0) {
				endPurge++;
			} else {
				break;
			}
		}

		// remove quads
		if(endPurge > 0) {
			removeQuads(0, endPurge);
		}
	}
}

wyTextureAtlas::~wyTextureAtlas() {
	// release members
	wyObjectRelease(m_tex);
	wyFree(m_vertices);
	wyFree(m_texCoords);
	wyFree(m_indices);
	if(m_colors != NULL)
		wyFree(m_colors);
}

wyTextureAtlas* wyTextureAtlas::make(wyTexture2D* tex) {
	return (wyTextureAtlas*)(WYNEW wyTextureAtlas(tex))->autoRelease();
}

wyTextureAtlas::wyTextureAtlas(wyTexture2D* tex, int capacity) :
		m_tex(NULL),
		m_totalQuads(0),
		m_capacity((capacity > 0) ? capacity : ATLAS_DEFAULT_CAPACITY),
		m_withColorArray(false),
		m_colors(NULL),
		m_color(wyc4bWhite) {
	m_vertices = (GLfloat*)wyMalloc(m_capacity * sizeof(wyQuad3D));
	m_texCoords = (GLfloat*)wyMalloc(m_capacity * sizeof(wyQuad2D));
	m_indices = (GLushort*)wyMalloc(m_capacity * 6 * sizeof(GLushort));

	setTexture(tex);
	initIndices();
}

void wyTextureAtlas::setTexture(wyTexture2D* tex) {
	// retain first, since if tex is same as current, it won't be destroyed
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}

void wyTextureAtlas::resizeCapacity(int newCapacity) {
	if(newCapacity <= m_capacity)
		return;

	// set new capacity
	int oldCapacity = m_capacity;
	m_capacity = newCapacity;

	GLfloat* newVertices = (GLfloat*)wyMalloc(newCapacity * sizeof(wyQuad3D));
	memcpy(newVertices, m_vertices, oldCapacity * sizeof(wyQuad3D));
	wyFree(m_vertices);
	m_vertices = newVertices;

	GLfloat* newTexCoords = (GLfloat*)wyMalloc(newCapacity * sizeof(wyQuad2D));
	memcpy(newTexCoords, m_texCoords, oldCapacity * sizeof(wyQuad2D));
	wyFree(m_texCoords);
	m_texCoords = newTexCoords;

	GLushort* newIndices = (GLushort*)wyMalloc(newCapacity * 6 * sizeof(GLushort));
	memcpy(newIndices, m_indices, oldCapacity * 6 * sizeof(GLushort));
	wyFree(m_indices);
	m_indices = newIndices;

	initIndices();

	if(m_withColorArray) {
		GLubyte* newColors = (GLubyte*)wyMalloc(newCapacity * 4 * sizeof(wyColor4B));
		memcpy(newColors, m_colors, oldCapacity * 4 * sizeof(wyColor4B));
		wyFree(m_colors);
		m_colors = newColors;
	}
}

int wyTextureAtlas::getNextAvailableIndex() {
	if(m_totalQuads >= m_capacity)
		resizeCapacity(m_capacity * 2);
	return m_totalQuads;
}

void wyTextureAtlas::updateQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index) {
	if(index >= 0 && index < m_capacity) {
		m_totalQuads = MAX(index + 1, m_totalQuads);
		putTexCoords(&quadT, index);
		putVertex(&quadV, index);
	}
}

void wyTextureAtlas::updateColor(wyColor4B color) {
	if(!m_withColorArray)
		initColorArray();

	if(m_withColorArray) {
		wyColor4B* c = (wyColor4B*)m_colors;
		for(int i = 0; i < m_capacity * 4; i++) {
			c[i].r = color.r;
			c[i].g = color.g;
			c[i].b = color.b;
			c[i].a = color.a;
		}
	}
}

void wyTextureAtlas::updateColor(wyColor4B color, int index) {
	if(index >= 0 && index < m_capacity) {
		m_totalQuads = MAX(index + 1, m_totalQuads);

		if(!m_withColorArray)
			initColorArray();

		if(m_withColorArray)
			putColor(&color, index);
	}
}

int wyTextureAtlas::appendQuad(wyQuad2D& quadT, wyQuad3D& quadV) {
	int index = getNextAvailableIndex();
	insertQuad(quadT, quadV, index);
	return index;
}

void wyTextureAtlas::insertQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index) {
	// ensure capacity is ok
	if(m_totalQuads >= m_capacity)
		resizeCapacity(m_capacity * 2);

	if(index >= 0 && index < m_capacity) {
		m_totalQuads++;

		int remaining = (m_totalQuads - 1) - index;

		// last object doesn't need to be moved
		if(remaining > 0) {
			// tex coordinates
			memmove((GLubyte*)m_texCoords + (index + 1) * sizeof(wyQuad2D), (GLubyte*)m_texCoords + index * sizeof(wyQuad2D), remaining * sizeof(wyQuad2D));

			// vertexCoordinates
			memmove((GLubyte*)m_vertices + (index + 1) * sizeof(wyQuad3D), (GLubyte*)m_vertices + index * sizeof(wyQuad3D), remaining * sizeof(wyQuad3D));

			// colors
			if(m_withColorArray) {
				memmove(m_colors + (index + 1) * sizeof(wyColor4B) * 4, m_colors + index * sizeof(wyColor4B) * 4, remaining * sizeof(wyColor4B) * 4);
			}
		}

		putTexCoords(&quadT, index);
		putVertex(&quadV, index);
		if(m_withColorArray) {
			putColor(&m_color, index);
		}
	}
}

void wyTextureAtlas::removeQuad(int index) {
	if(index >= 0 && index < m_totalQuads) {
		int remaining = (m_totalQuads - 1) - index;

		// last object doesn't need to be moved
		if(remaining > 0) {
			// tex coordinates
			memmove((GLubyte*)m_texCoords + index * sizeof(wyQuad2D), (GLubyte*)m_texCoords + (index + 1) * sizeof(wyQuad2D), remaining * sizeof(wyQuad2D));

			// vertexCoordinates
			memmove((GLubyte*)m_vertices + index * sizeof(wyQuad3D), (GLubyte*)m_vertices + (index + 1) * sizeof(wyQuad3D), remaining * sizeof(wyQuad3D));

			// colors
			if(m_withColorArray) {
				memmove(m_colors + index * sizeof(wyColor4B) * 4, m_colors + (index + 1) * sizeof(wyColor4B) * 4, remaining * sizeof(wyColor4B) * 4);
			}
		}

		m_totalQuads--;
	}
}

void wyTextureAtlas::removeQuads(int start, int count) {
	// basic validation
	if(start >= m_totalQuads)
		return;
	if(start < 0)
		start = 0;
	if(start + count > m_totalQuads) {
		count = m_totalQuads - start;
	}

	int remaining = m_totalQuads - start - count;
	if(remaining > 0) {
		// tex coordinates
		memmove((GLubyte*)m_texCoords + start * sizeof(wyQuad2D), (GLubyte*)m_texCoords + (start + count) * sizeof(wyQuad2D), remaining * sizeof(wyQuad2D));

		// vertexCoordinates
		memmove((GLubyte*)m_vertices + start * sizeof(wyQuad3D), (GLubyte*)m_vertices + (start + count) * sizeof(wyQuad3D), remaining * sizeof(wyQuad3D));

		// colors
		if(m_withColorArray) {
			memmove(m_colors + start * sizeof(wyColor4B) * 4, m_colors + (start + count) * sizeof(wyColor4B) * 4, remaining * sizeof(wyColor4B) * 4);
		}
	}

	m_totalQuads -= count;
}

void wyTextureAtlas::copyTo(int from, wyTextureAtlas* destAtlas) {
	if(from >= 0 && from < m_totalQuads) {
		GLubyte* tp = (GLubyte*)m_texCoords + from * sizeof(wyQuad2D);
		GLubyte* vp = (GLubyte*)m_vertices + from * sizeof(wyQuad3D);
		destAtlas->appendQuad(*(wyQuad2D*)tp, *(wyQuad3D*)vp);
	}
}

void wyTextureAtlas::copyTo(int from, wyQuad2D* quadT, wyQuad3D* quadV) {
	if(from >= 0 && from < m_totalQuads) {
		if(quadT != NULL) {
			memcpy((GLubyte*)quadT, (GLubyte*)m_texCoords + from * sizeof(wyQuad2D), sizeof(wyQuad2D));
		}
		if(quadV != NULL) {
			memcpy((GLubyte*)quadV, (GLubyte*)m_vertices + from * sizeof(wyQuad3D), sizeof(wyQuad3D));
		}
	}
}

void wyTextureAtlas::drawOne(int index) {
	if(index < 0 || index >= m_totalQuads || m_tex == NULL)
		return;

	m_tex->load();

	if(m_withColorArray) {
		glEnableClientState(GL_COLOR_ARRAY);
	}

	glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());

	m_tex->applyParameters();

	glVertexPointer(3, GL_FLOAT, 0, m_vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);

	if(m_withColorArray) {
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, m_colors);
	}

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, m_indices + index * 6);

	if(m_withColorArray)
		glDisableClientState(GL_COLOR_ARRAY);
}

bool wyTextureAtlas::drawRange(int start, int numOfQuads) {
	if(start < 0 || start >= m_totalQuads || start + numOfQuads > m_totalQuads || m_tex == NULL) {
		return false;
	}

	m_tex->load();

	if(m_withColorArray) {
		glEnableClientState(GL_COLOR_ARRAY);
	}

	glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());

	m_tex->applyParameters();

	glVertexPointer(3, GL_FLOAT, 0, m_vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);

	if(m_withColorArray) {
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, m_colors);
	}

	glDrawElements(GL_TRIANGLES, numOfQuads * 6, GL_UNSIGNED_SHORT, m_indices + start * 6);

	if(m_withColorArray)
		glDisableClientState(GL_COLOR_ARRAY);

	return true;
}

void wyTextureAtlas::draw(int numOfQuads) {
	if(m_tex == NULL)
		return;

	m_tex->load();

	if(m_withColorArray) {
		glEnableClientState(GL_COLOR_ARRAY);
	}

	glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());

	m_tex->applyParameters();

	glVertexPointer(3, GL_FLOAT, 0, m_vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);

	if(m_withColorArray) {
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, m_colors);
	}

	glDrawElements(GL_TRIANGLES, numOfQuads * 6, GL_UNSIGNED_SHORT, m_indices);

	if(m_withColorArray)
		glDisableClientState(GL_COLOR_ARRAY);
}

void wyTextureAtlas::drawAll() {
	draw(m_totalQuads);
}

void wyTextureAtlas::iterateQuad3D(iterateQuad3DFunc func, void* data) {
	if(func != NULL) {
		GLubyte* v = (GLubyte*)m_vertices;
		for(int i = 0; i < m_totalQuads; i++) {
			if(func(this, (wyQuad3D*)v, data))
				v += sizeof(wyQuad3D);
			else
				break;
		}
	}
}
