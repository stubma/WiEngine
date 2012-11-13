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
#include "wyShape.h"
#include "wyAttribute.h"
#include "wyLog.h"

wyShape::wyShape() {
	// the mode should be line strip
	m_mode = LINE_STRIP;

	// create buffer
	m_buf = wyBuffer::makeCustom(sizeof(Vertex));

	// connect attribute
	connectAttribute(wyAttribute::NAME[wyAttribute::POSITION], m_buf, 0, 3);
	connectAttribute(wyAttribute::NAME[wyAttribute::TEXTURE], m_buf, sizeof(kmVec3), 2);
	connectAttribute(wyAttribute::NAME[wyAttribute::COLOR], m_buf, sizeof(kmVec3) + sizeof(kmVec2), 4);
}

wyShape::~wyShape() {
}

wyShape* wyShape::make() {
	wyShape* l = WYNEW wyShape();
	return (wyShape*)l->autoRelease();
}

void wyShape::buildPoint(float x, float y) {
	// clear
	m_buf->clear();

	// add
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);
	kmVec3Fill(&v.pos, x, y, 0);
	m_buf->append(&v, 1);

	// the mode should be changed to points
	m_mode = POINTS;
}

void wyShape::buildPoints(float* p, size_t length) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill every vertex
	for(int i = 0; i < length; i += 2) {
		kmVec3Fill(&v.pos, p[i], p[i + 1], 0);
		m_buf->append(&v, 1);
	}

	// the mode should be changed to points
	m_mode = POINTS;
}

void wyShape::buildLine(float x1, float y1, float x2, float y2) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);
	kmVec3Fill(&v.pos, x1, y1, 0);
	m_buf->append(&v, 1);

	// end
	kmVec3Fill(&v.pos, x2, y2, 0);
	m_buf->append(&v, 1);

	// the mode should be line strip
	m_mode = LINE_STRIP;
}

void wyShape::buildBezier(wyBezierConfig& c, int segments) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill every vertex
	float step = 1.f / segments;
	float t = 0;
	for(int i = 0; i <= segments; i++) {
		wyPoint p = wybcPointAt(c, t);
		kmVec3Fill(&v.pos, p.x, p.y, 0);
		m_buf->append(&v, 1);
		t += step;
	}

	// the mode should be line strip
	m_mode = LINE_STRIP;
}

void wyShape::buildLagrange(wyLagrangeConfig& c, int segments) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill every vertex
	float step = 1.f / segments;
	float t = 0;
	for(int i = 0; i <= segments; i++) {
		wyPoint p = wylcPointAt(c, t);
		kmVec3Fill(&v.pos, p.x, p.y, 0);
		m_buf->append(&v, 1);
		t += step;
	}

	// the mode should be line strip
	m_mode = LINE_STRIP;
}

void wyShape::buildHypotrochoid(wyHypotrochoidConfig& c, int segments) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill every vertex
	float step = 1.f / segments;
	float t = 0;
	for (int i = 0; i <= segments; i++) {
		wyPoint p = wyhcPointAt(c, t);
		kmVec3Fill(&v.pos, p.x, p.y, 0);
		m_buf->append(&v, 1);
		t += step;
	}

	// the mode should be line strip
	m_mode = LINE_STRIP;
}

void wyShape::buildPath(float* points, int vertexCount) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill every vertex
	for(size_t i = 0; i < vertexCount; i++) {
		kmVec3Fill(&v.pos, points[i * 2], points[i * 2 + 1], 0);
		m_buf->append(&v, 1);
	}

	// the mode should be line strip
	m_mode = LINE_STRIP;
}

void wyShape::buildDashLine(float x1, float y1, float x2, float y2, float dashLength) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// how many segments
	float dx = x2 - x1;
	float dy = y2 - y1;
	float dist = wyMath::sqrt(dx * dx + dy * dy);
	float x = dx / dist * dashLength;
	float y = dy / dist * dashLength;
	wyPoint p1 = wyp(x1, y1);
	int segments = (int)(dist / dashLength);
	int lines = (int)((float)segments / 2.0f);

	// fill every vertex
	for(int i = 0; i < lines; i++) {
		kmVec3Fill(&v.pos, x1, y1, 0);
		m_buf->append(&v, 1);
		x1 += x;
		y1 += y;
		kmVec3Fill(&v.pos, x1, y1, 0);
		m_buf->append(&v, 1);
		x1 += x;
		y1 += y;
	}

	// the mode should be changed to lines
	m_mode = LINES;
}

void wyShape::buildDashPath(float* points, size_t length, float dashLength) {
	// clear
	m_buf->clear();

	// help variable
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	for(int i = 0; i < length - 2; i += 2) {
		float x1 = points[i];
		float y1 = points[i + 1];
		float x2 = points[i + 2];
		float y2 = points[i + 3];

		// how many segments
		float dx = x2 - x1;
		float dy = y2 - y1;
		float dist = wyMath::sqrt(dx * dx + dy * dy);
		float x = dx / dist * dashLength;
		float y = dy / dist * dashLength;
		wyPoint p1 = wyp(x1, y1);
		int segments = (int)(dist / dashLength);
		int lines = (int)((float)segments / 2.0f);

		// fill every vertex
		for(int i = 0; i < lines; i++) {
			kmVec3Fill(&v.pos, x1, y1, 0);
			m_buf->append(&v, 1);
			x1 += x;
			y1 += y;
			kmVec3Fill(&v.pos, x1, y1, 0);
			m_buf->append(&v, 1);
			x1 += x;
			y1 += y;
		}
	}

	// the mode should be changed to lines
	m_mode = LINES;
}

void wyShape::buildRect(float* p) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// four vertices
	for(int i = 0; i < 8; i += 2) {
		kmVec3Fill(&v.pos, p[i], p[i + 1], 0);
		m_buf->append(&v, 1);
	}

	// last
	kmVec3Fill(&v.pos, p[0], p[1], 0);
	m_buf->append(&v, 1);

	// mode
	m_mode = LINE_STRIP;
}

void wyShape::buildRect(float x, float y, float w, float h) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// left bottom
	kmVec3Fill(&v.pos, x, y, 0);
	m_buf->append(&v, 1);

	// right bottom
	kmVec3Fill(&v.pos, x + w, y, 0);
	m_buf->append(&v, 1);

	// right top
	kmVec3Fill(&v.pos, x + w, y + h, 0);
	m_buf->append(&v, 1);

	// left top
	kmVec3Fill(&v.pos, x, y + h, 0);
	m_buf->append(&v, 1);

	// last, left bottom
	kmVec3Fill(&v.pos, x, y, 0);
	m_buf->append(&v, 1);

	// mode
	m_mode = LINE_STRIP;
}

void wyShape::buildSolidRect(float* p) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// four vertices
	for(int i = 0; i < 8; i += 2) {
		kmVec3Fill(&v.pos, p[i], p[i + 1], 0);
		m_buf->append(&v, 1);
	}

	// mode
	m_mode = TRIANGLE_FAN;
}

void wyShape::buildSolidRect(float x, float y, float w, float h) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// left bottom
	kmVec3Fill(&v.pos, x, y, 0);
	m_buf->append(&v, 1);

	// right bottom
	kmVec3Fill(&v.pos, x + w, y, 0);
	m_buf->append(&v, 1);

	// right top
	kmVec3Fill(&v.pos, x + w, y + h, 0);
	m_buf->append(&v, 1);

	// left top
	kmVec3Fill(&v.pos, x, y + h, 0);
	m_buf->append(&v, 1);

	// mode
	m_mode = TRIANGLE_FAN;
}

void wyShape::buildGradientRect(float x, float y, float w, float h, wyColor4B from, wyColor4B to, int degree) {
	// clear
	m_buf->clear();

	// variables
	Vertex v;
	float vertices[8];

	// find degree direction
	degree %= 360;
	if (degree < 0) {
		degree += 360;
	}
	int index = degree / 90;
	degree %= 90;

	// fill vertices based on coarse direction
	switch (index) {
		case 0:
			vertices[0] = x;
			vertices[1] = y + h;
			vertices[2] = x;
			vertices[3] = y;
			vertices[4] = x + w;
			vertices[5] = y + h;
			vertices[6] = x + w;
			vertices[7] = y;
			break;
		case 1:
			vertices[0] = x + w;
			vertices[1] = y + h;
			vertices[2] = x;
			vertices[3] = y + h;
			vertices[4] = x + w;
			vertices[5] = y;
			vertices[6] = x;
			vertices[7] = y;
			break;
		case 2:
			vertices[0] = x + w;
			vertices[1] = y;
			vertices[2] = x + w;
			vertices[3] = y + h;
			vertices[4] = x;
			vertices[5] = y;
			vertices[6] = x;
			vertices[7] = y + h;
			break;
		case 3:
			vertices[0] = x;
			vertices[1] = y;
			vertices[2] = x + w;
			vertices[3] = x;
			vertices[4] = y;
			vertices[5] = y + h;
			vertices[6] = x + w;
			vertices[7] = y + h;
			break;
		default:
			break;
	}

	// adjust by degree
	if (degree != 0) {
		float radian = wyMath::d2r(degree);
		float cosRadian = cos(radian);
		float sinRadian = sin(radian);

		float tmp = w * cosRadian;
		float x1 = w - tmp * cosRadian;
		float y1 = tmp * sinRadian;

		tmp = h * cosRadian;
		float y2 = h - tmp * cosRadian;
		float x2 = tmp * sinRadian;

		switch (index) {
			case 0:
				vertices[0] += x1;
				vertices[1] += y1;
				vertices[2] -= x2;
				vertices[3] += y2;
				vertices[4] += x2;
				vertices[5] -= y2;
				vertices[6] -= x1;
				vertices[7] -= y1;
				break;
			case 1:
				vertices[0] += x2;
				vertices[1] -= y2;
				vertices[2] += x1;
				vertices[3] += y1;
				vertices[4] -= x1;
				vertices[5] -= y1;
				vertices[6] -= x2;
				vertices[7] += y2;
				break;
			case 2:
				vertices[0] -= x1;
				vertices[1] -= y1;
				vertices[2] += x2;
				vertices[3] -= y2;
				vertices[4] -= x2;
				vertices[5] += y2;
				vertices[6] += x1;
				vertices[7] += y1;
				break;
			case 3:
				vertices[0] -= x2;
				vertices[1] += y2;
				vertices[2] -= x1;
				vertices[3] -= y1;
				vertices[4] += x1;
				vertices[5] += y1;
				vertices[6] += x2;
				vertices[7] -= y2;
				break;
			default:
				break;
		}
	}

	// first
	kmVec3Fill(&v.pos, vertices[0], vertices[1], 0);
	kmVec4Fill(&v.color, from.r / 255.0f, from.g / 255.0f, from.b / 255.0f, from.a / 255.0f);
	m_buf->append(&v, 1);

	// second
	kmVec3Fill(&v.pos, vertices[2], vertices[3], 0);
	m_buf->append(&v, 1);

	// third
	kmVec3Fill(&v.pos, vertices[4], vertices[5], 0);
	kmVec4Fill(&v.color, to.r / 255.0f, to.g / 255.0f, to.b / 255.0f, to.a / 255.0f);
	m_buf->append(&v, 1);

	// fourth
	kmVec3Fill(&v.pos, vertices[6], vertices[7], 0);
	m_buf->append(&v, 1);

	// mode
	m_mode = TRIANGLE_STRIP;
}

void wyShape::buildPoly(float* p, size_t length, bool close) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// append point
	for(int i = 0; i < length; i += 2) {
		kmVec3Fill(&v.pos, p[i], p[i + 1], 0);
		m_buf->append(&v, 1);
	}

	// GL_LINE_LOOP is very slow in desire HD, so we still use LINE_STRIP
	// append start point again because we use LINE_STRIP
	if(close && length >= 2) {
		kmVec3Fill(&v.pos, p[0], p[1], 0);
		m_buf->append(&v, 1);
	}

	// set mode
	m_mode = LINE_STRIP;
}

void wyShape::buildSolidPoly(float* p, size_t length) {
	// clear
	m_buf->clear();

	// start
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// append point
	for(int i = 0; i < length; i += 2) {
		kmVec3Fill(&v.pos, p[i], p[i + 1], 0);
		m_buf->append(&v, 1);
	}

	// set mode
	m_mode = TRIANGLE_FAN;
}

void wyShape::buildCircle(float centerX, float centerY, float r, float radiusLineAngle, int segments, bool drawLineToCenter) {
	// clear
	m_buf->clear();

	// split coefficient
	float coef = 2.0f * M_PI / segments;
	float a = radiusLineAngle / 180.0f * M_PI;

	// first point
	float fx, fy;

	// fill
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);
	for(int i = 0; i <= segments; i++) {
		float rads = i * coef;
		float j = r * cos(rads + a) + centerX;
		float k = r * sin(rads + a) + centerY;
		if(i == 0) {
			fx = j;
			fy = k;
		}
		kmVec3Fill(&v.pos, j, k, 0);
		m_buf->append(&v, 1);
	}

	// last, because we use line strip
	kmVec3Fill(&v.pos, fx, fy, 0);
	m_buf->append(&v, 1);

	// radius line
	if(drawLineToCenter) {
		kmVec3Fill(&v.pos, centerX, centerY, 0);
		m_buf->append(&v, 1);
	}

	// set mode
	m_mode = LINE_STRIP;
}

void wyShape::buildSolidCircle(float centerX, float centerY, float r, int segments) {
	// clear
	m_buf->clear();

	// split coefficient
	float coef = 2.0f * M_PI / segments;

	// first point
	float fx, fy;

	// center first
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);
	kmVec3Fill(&v.pos, centerX, centerY, 0);
	m_buf->append(&v, 1);

	// fill
	for(int i = 0; i <= segments; i++) {
		float rads = i * coef;
		float j = r * cos(rads) + centerX;
		float k = r * sin(rads) + centerY;
		if(i == 0) {
			fx = j;
			fy = k;
		}
		kmVec3Fill(&v.pos, j, k, 0);
		m_buf->append(&v, 1);
	}

	// last
	kmVec3Fill(&v.pos, fx, fy, 0);
	m_buf->append(&v, 1);

	// set mode
	m_mode = TRIANGLE_FAN;
}

void wyShape::buildCustom2D(float* vertices, float* texCoords, int vertexCount, Mode mode) {
	// clear
	m_buf->clear();

	// vertex
	Vertex v;
	kmVec4Fill(&v.color, 1, 1, 1, 1);

	// fill
	for(int i = 0; i < vertexCount; i++) {
		kmVec3Fill(&v.pos, vertices[i * 2], vertices[i * 2 + 1], 0);
		if(texCoords)
			kmVec2Fill(&v.tex, texCoords[i * 2], texCoords[i * 2 + 1]);
		m_buf->append(&v, 1);
	}

	// set mode
	m_mode = mode;
}

void wyShape::updateVertices(float* vertices, int vertexCount, int updateStart) {
	Vertex* v = (Vertex*)m_buf->getData();
	int currentCount = m_buf->getElementCount();
	int min = MIN(currentCount, updateStart + vertexCount);
	v += updateStart;
	for(int i = updateStart; i < min; i++, v++) {
		kmVec3Fill(&v[0].pos, vertices[i * 2], vertices[i * 2 + 1], 0);
	}
}

void wyShape::updateColor4B(wyColor4B color) {
	// color
	float r = color.r / 255.0f;
	float g = color.g / 255.0f;
	float b = color.b / 255.0f;
	float a = color.a / 255.0f;

	// update every vertex
	Vertex* v = (Vertex*)m_buf->getData();
	int c = m_buf->getElementCount();
	for(int i = 0; i < c; i++) {
		kmVec4Fill(&v[i].color, r, g, b, a);
	}
}

int wyShape::getElementCount() {
	return m_buf->getElementCount();
}

void wyShape::updateVertex(int index, float x, float y, float z) {
	if(index < 0 || index >= m_buf->getElementCount())
		return;

	Vertex* v = (Vertex*)m_buf->getData();
	kmVec3Fill(&v[index].pos, x, y, z);
}

void wyShape::addPoint(float x, float y, float z, wyColor4B c) {
	Vertex v;
	kmVec4Fill(&v.color, c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
	kmVec3Fill(&v.pos, x, y, z);
	m_buf->append(&v, 1);
}

void wyShape::clear() {
	m_buf->clear();
}
