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
#include "wyGradientColorLayer.h"
#include "wyDirector.h"
#include "wyLog.h"
#include <stdlib.h>
#include <math.h>
#include "wyGlobal.h"

wyGradientColorLayer* wyGradientColorLayer::make(wyColor4B fromColor, wyColor4B toColor, int degree) {
	wyGradientColorLayer* n = WYNEW wyGradientColorLayer(fromColor, toColor, degree);
	return (wyGradientColorLayer*)n->autoRelease();
}

void wyGradientColorLayer::updateColor() {
	int i = 0;
	m_colors[i++] = m_fromColor.r;
	m_colors[i++] = m_fromColor.g;
	m_colors[i++] = m_fromColor.b;
	m_colors[i++] = m_fromColor.a;

	m_colors[i++] = m_fromColor.r;
	m_colors[i++] = m_fromColor.g;
	m_colors[i++] = m_fromColor.b;
	m_colors[i++] = m_fromColor.a;

	m_colors[i++] = m_toColor.r;
	m_colors[i++] = m_toColor.g;
	m_colors[i++] = m_toColor.b;
	m_colors[i++] = m_toColor.a;

	m_colors[i++] = m_toColor.r;
	m_colors[i++] = m_toColor.g;
	m_colors[i++] = m_toColor.b;
	m_colors[i++] = m_toColor.a;
}

void wyGradientColorLayer::updateVertices() {
	int degree = m_degree % 360;
	if (degree < 0) {
		degree = 360 + degree;
	}

	int index = degree / 90;
	degree = degree % 90;

	switch (index) {
		case 0:
			for (int i = 0; i < 8; i++) {
				m_vertices[i] = m_originalVertices[i];
			}
			break;
		case 1:
			m_vertices[0] = m_originalVertices[4];
			m_vertices[1] = m_originalVertices[5];
			m_vertices[2] = m_originalVertices[0];
			m_vertices[3] = m_originalVertices[1];
			m_vertices[4] = m_originalVertices[6];
			m_vertices[5] = m_originalVertices[7];
			m_vertices[6] = m_originalVertices[2];
			m_vertices[7] = m_originalVertices[3];
			break;
		case 2:
			m_vertices[0] = m_originalVertices[6];
			m_vertices[1] = m_originalVertices[7];
			m_vertices[2] = m_originalVertices[4];
			m_vertices[3] = m_originalVertices[5];
			m_vertices[4] = m_originalVertices[2];
			m_vertices[5] = m_originalVertices[3];
			m_vertices[6] = m_originalVertices[0];
			m_vertices[7] = m_originalVertices[1];
			break;
		case 3:
			m_vertices[0] = m_originalVertices[2];
			m_vertices[1] = m_originalVertices[3];
			m_vertices[2] = m_originalVertices[6];
			m_vertices[3] = m_originalVertices[7];
			m_vertices[4] = m_originalVertices[0];
			m_vertices[5] = m_originalVertices[1];
			m_vertices[6] = m_originalVertices[4];
			m_vertices[7] = m_originalVertices[5];
			break;
		default:
			break;
	}

	if (degree != 0) {
		float radian = wyMath::d2r(degree);
		float cosRadian = cos(radian);
		float sinRadian = sin(radian);

		float tmp = m_width * cosRadian;
		float x1 = m_width - tmp * cosRadian;
		float y1 = tmp * sinRadian;

		tmp = m_height * cosRadian;
		float y2 = m_height - tmp * cosRadian;
		float x2 = tmp * sinRadian;

		switch (index) {
			case 0:
				m_vertices[0] += x1;
				m_vertices[1] += y1;
				m_vertices[2] -= x2;
				m_vertices[3] += y2;
				m_vertices[4] += x2;
				m_vertices[5] -= y2;
				m_vertices[6] -= x1;
				m_vertices[7] -= y1;
				break;
			case 1:
				m_vertices[0] += x2;
				m_vertices[1] -= y2;
				m_vertices[2] += x1;
				m_vertices[3] += y1;
				m_vertices[4] -= x1;
				m_vertices[5] -= y1;
				m_vertices[6] -= x2;
				m_vertices[7] += y2;
				break;
			case 2:
				m_vertices[0] -= x1;
				m_vertices[1] -= y1;
				m_vertices[2] += x2;
				m_vertices[3] -= y2;
				m_vertices[4] -= x2;
				m_vertices[5] += y2;
				m_vertices[6] += x1;
				m_vertices[7] += y1;
				break;
			case 3:
				m_vertices[0] -= x2;
				m_vertices[1] += y2;
				m_vertices[2] -= x1;
				m_vertices[3] -= y1;
				m_vertices[4] += x1;
				m_vertices[5] += y1;
				m_vertices[6] += x2;
				m_vertices[7] -= y2;
				break;
			default:
				break;
		}
	}
}

wyColor3B wyGradientColorLayer::getFromColor() {
	wyColor3B c = {
		m_fromColor.r,
		m_fromColor.g,
		m_fromColor.b
	};
	return c;
}

void wyGradientColorLayer::setFromColor(wyColor3B color) {
	m_fromColor.r = color.r;
	m_fromColor.g = color.g;
	m_fromColor.b = color.b;
	updateColor();
}

wyColor3B wyGradientColorLayer::getToColor() {
	wyColor3B c = {
		m_toColor.r,
		m_toColor.g,
		m_toColor.b
	};
	return c;
}

void wyGradientColorLayer::setToColor(wyColor3B color) {
	m_toColor.r = color.r;
	m_toColor.g = color.g;
	m_toColor.b = color.b;
	updateColor();
}

wyGradientColorLayer::~wyGradientColorLayer() {
	wyFree(m_originalVertices);
	wyFree(m_vertices);
	wyFree(m_colors);
}

void wyGradientColorLayer::setDegree(int degree) {
	m_degree = degree;
	updateVertices();
}

int wyGradientColorLayer::getDegree() {
	return m_degree;
}

void wyGradientColorLayer::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if (m_noDraw) {
		wyNode::draw();
		return;
	}

	glEnable(GL_DITHER);
	glShadeModel( GL_SMOOTH);

	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, m_vertices);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, m_colors);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	// Clear the vertex and color arrays
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glShadeModel(GL_FLAT);
	glDisable(GL_DITHER);
}

void wyGradientColorLayer::setContentSize(float w, float h) {
	// 原始位置opengl顶点，依次为左上，左下，右上，右下
	if (m_originalVertices != NULL) {
		m_originalVertices[1] = h;
		m_originalVertices[4] = w;
		m_originalVertices[5] = h;
		m_originalVertices[6] = w;
	}

	wyLayer::setContentSize(w, h);
	updateVertices();
}

wyGradientColorLayer::wyGradientColorLayer(wyColor4B fromColor, wyColor4B toColor, int degree) :
		m_vertices((GLfloat*)wyCalloc(4 * 2, sizeof(GLfloat))),
		m_originalVertices((GLfloat*) wyCalloc(4 * 2, sizeof(GLfloat))),
		m_colors((GLubyte*) wyMalloc(4 * 4 * sizeof(GLubyte))),
		m_fromColor(fromColor),
		m_toColor(toColor),
		m_degree(degree) {
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	updateColor();
}
