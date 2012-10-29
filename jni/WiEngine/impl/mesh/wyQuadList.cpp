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
#include "wyQuadList.h"
#include "wyBuffer.h"
#include "wyAttribute.h"
#include "wyLog.h"

wyQuadList::wyQuadList() :
		m_color(wyc4bWhite) {
	// make indices buffer
	m_indices = wyBuffer::makeShort();
	initIndices();

	// set indices buffer as first LOD level
	setLodLevels(&m_indices, 1);

	// create buffer
	m_buf = wyBuffer::makeCustom(sizeof(Vertex));

	// connect attribute
	connectAttribute(wyAttribute::NAME[wyAttribute::POSITION], m_buf, 0, 3);
	connectAttribute(wyAttribute::NAME[wyAttribute::TEXTURE], m_buf, sizeof(kmVec3), 2);
	connectAttribute(wyAttribute::NAME[wyAttribute::COLOR], m_buf, sizeof(kmVec3) + sizeof(kmVec2), 4);
}

wyQuadList::~wyQuadList() {
}

wyQuadList* wyQuadList::make() {
	wyQuadList* ql = WYNEW wyQuadList();
	return (wyQuadList*)ql->autoRelease();
}

int wyQuadList::getElementCount() {
	return getTotalQuads();
}

void wyQuadList::initIndices() {
	int quads = m_indices->getCapacity() / 6;
	GLushort* p = (GLushort*)m_indices->getData();
	for(int i = 0; i < quads; i++) {
		p[i * 6] = (GLushort)(i * 4);
		p[i * 6 + 1] = (GLushort)(i * 4 + 1);
		p[i * 6 + 2] = (GLushort)(i * 4 + 2);

		// inverted index.
		p[i * 6 + 5] = (GLushort)(i * 4 + 1);
		p[i * 6 + 4] = (GLushort)(i * 4 + 2);
		p[i * 6 + 3] = (GLushort)(i * 4 + 3);
	}
}

void wyQuadList::ensureIndicesCapacity() {
	// ensure indices
	int oldCapacity = m_indices->getCapacity();
	while(getTotalQuads() * 6 >= m_indices->getCapacity()) {
		m_indices->enlarge();
	}

	// init indices
	if(m_indices->getCapacity() > oldCapacity) {
		initIndices();
	}

	// set right element count
	m_indices->setElementCount(getTotalQuads() * 6);
}

int wyQuadList::appendQuad(wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c) {
	int index = getTotalQuads();
	insertQuad(index, quadT, quadV, c);
	return index;
}

void wyQuadList::putQuad(int index, const wyQuad2D& quadT, const wyQuad3D& quadV, wyColor4B c, bool update) {
	Vertex va[4];

	// default color
	float r = c.r / 255.0f;
	float g = c.g / 255.0f;
	float b = c.b / 255.0f;
	float a = c.a / 255.0f;

	// bottom left
	Vertex* v = va;
	kmVec3Fill(&v->pos, quadV.bl_x, quadV.bl_y, quadV.bl_z);
	kmVec2Fill(&v->tex, quadT.bl_x, quadT.bl_y);
	kmVec4Fill(&v->color, r, g, b, a);

	// bottom right
	v++;
	kmVec3Fill(&v->pos, quadV.br_x, quadV.br_y, quadV.br_z);
	kmVec2Fill(&v->tex, quadT.br_x, quadT.br_y);
	kmVec4Fill(&v->color, r, g, b, a);

	// top left
	v++;
	kmVec3Fill(&v->pos, quadV.tl_x, quadV.tl_y, quadV.tl_z);
	kmVec2Fill(&v->tex, quadT.tl_x, quadT.tl_y);
	kmVec4Fill(&v->color, r, g, b, a);

	// top right
	v++;
	kmVec3Fill(&v->pos, quadV.tr_x, quadV.tr_y, quadV.tr_z);
	kmVec2Fill(&v->tex, quadT.tr_x, quadT.tr_y);
	kmVec4Fill(&v->color, r, g, b, a);

	// insert
	if(update)
		m_buf->update(va, 4, index * 4);
	else
		m_buf->insert(va, 4, index * 4);
}

void wyQuadList::insertQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c) {
	// put quad into buffer
	putQuad(index, quadT, quadV, c);

	// ensure capacity is ok
	ensureIndicesCapacity();
}

void wyQuadList::updateQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV) {
	if(index >= 0) {
		putQuad(index, quadT, quadV, m_color, true);

		// ensure capacity is ok
		ensureIndicesCapacity();
	}
}

void wyQuadList::updateQuad(int index, wyQuad2D& quadT, wyQuad3D& quadV, wyColor4B c) {
	if(index >= 0) {
		putQuad(index, quadT, quadV, c, true);

		// ensure capacity is ok
		ensureIndicesCapacity();
	}
}

void wyQuadList::removeQuad(int index) {
	m_buf->remove(index * 4, 4);

	// set right element count
	m_indices->setElementCount(getTotalQuads() * 6);
}

void wyQuadList::removeQuads(int start, int count) {
	m_buf->remove(start * 4, count * 4);

	// set right element count
	m_indices->setElementCount(getTotalQuads() * 6);
}

void wyQuadList::updateColor(int index, wyColor4B color) {
	Vertex* v = (Vertex*)m_buf->getData();
	v += index * 4;
	float r = color.r / 255.0f;
	float g = color.g / 255.0f;
	float b = color.b / 255.0f;
	float a = color.a / 255.0f;
	for(int i = 0; i < 4; i++, v++) {
		kmVec4Fill(&v->color, r, g, b, a);
	}
}

void wyQuadList::updateColor(wyColor4B color) {
	// save default color
	m_color = color;

	// fill every vertex
	Vertex* v = (Vertex*)m_buf->getData();
	int count = m_buf->getElementCount();
	float r = color.r / 255.0f;
	float g = color.g / 255.0f;
	float b = color.b / 255.0f;
	float a = color.a / 255.0f;
	for(int i = 0; i < count; i++, v++) {
		kmVec4Fill(&v->color, r, g, b, a);
	}
}

void wyQuadList::translate(float x, float y, float z) {
	Vertex* v = (Vertex*)m_buf->getData();
	int count = m_buf->getElementCount();
	for(int i = 0; i < count; i++, v++) {
		v->pos.x += x;
		v->pos.y += y;
		v->pos.z += z;
	}
}

void wyQuadList::scale(float x, float y, float z) {
	Vertex* v = (Vertex*)m_buf->getData();
	int count = m_buf->getElementCount();
	for(int i = 0; i < count; i++, v++) {
		v->pos.x *= x;
		v->pos.y *= y;
		v->pos.z *= z;
	}
}

void wyQuadList::replaceTexCoord(wyQuad2D& t) {
	Vertex* v = (Vertex*)m_buf->getData();
	int count = m_buf->getElementCount();
	for(int i = 0; i < count; i += 4, v += 4) {
		v[0].tex.x = t.bl_x;
		v[0].tex.y = t.bl_y;
		v[1].tex.x = t.br_x;
		v[1].tex.y = t.br_y;
		v[2].tex.x = t.tl_x;
		v[2].tex.y = t.tl_y;
		v[3].tex.x = t.tr_x;
		v[3].tex.y = t.tr_y;
	}
}

void wyQuadList::reduceAlpha(float delta) {
	Vertex* v = (Vertex*)m_buf->getData();
	int count = m_buf->getElementCount();
	for(int i = 0; i < count; i++, v++) {
		v->color.w = MAX(0, v->color.w - delta);
	}

	// purge quads
	int endPurge = 0;
	v = (Vertex*)m_buf->getData();
	for(int i = 0; i < count; i++, v++) {
		// check four vertices for one quad
		if(v->color.w > 0)
			break;
		v++;
		if(v->color.w > 0)
			break;
		v++;
		if(v->color.w > 0)
			break;
		v++;
		if(v->color.w > 0)
			break;

		// all passed, add purge end range
		endPurge++;
	}

	// remove quads
	if(endPurge > 0) {
		removeQuads(0, endPurge);
	}
}
