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
#include "wyColorLayer.h"
#include "wyLog.h"
#include <stdlib.h>
#include "wyGlobal.h"

wyColorLayer* wyColorLayer::make(wyColor4B color) {
	wyColorLayer* n = WYNEW wyColorLayer(color);
	return (wyColorLayer*)n->autoRelease();
}

void wyColorLayer::updateColor() {
	for (int i = 0; i < 4 * 4 * sizeof(GLubyte); i++) {
		switch (i % 4) {
			case 0:
				m_colors[i] = m_color.r;
				break;
			case 1:
				m_colors[i] = m_color.g;
				break;
			case 2:
				m_colors[i] = m_color.b;
				break;
			default:
				m_colors[i] = m_color.a;
				break;
		}
	}
}

void wyColorLayer::setAlpha(int alpha) {
	m_color.a = alpha;
	updateColor();
}

wyColor3B wyColorLayer::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyColorLayer::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	updateColor();
}

void wyColorLayer::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	updateColor();
}

wyColorLayer::~wyColorLayer() {
	wyFree(m_vertices);
	wyFree(m_colors);
}

void wyColorLayer::draw() {
	// TODO gles2
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//
//    glVertexPointer(2, GL_FLOAT, 0, m_vertices);
//    glColorPointer(4, GL_UNSIGNED_BYTE, 0, m_colors);
//
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//
//    // Clear the vertex and color arrays
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
}

void wyColorLayer::setContentSize(float w, float h) {
    // Layer default ctor calls setContentSize priot to nio alloc
    if (m_vertices != NULL) {
    	m_vertices[2] = w;
    	m_vertices[5] = h;
    	m_vertices[6] = w;
    	m_vertices[7] = h;
    }

    wyLayer::setContentSize(w, h);
}

wyColorLayer::wyColorLayer(wyColor4B color) :
		m_vertices((GLfloat*)wyCalloc(4 * 2, sizeof(GLfloat))),
		m_colors((GLubyte*)wyMalloc(4 * 4 * sizeof(GLubyte))),
		m_color(color) {
    updateColor();
    setContentSize(wyDevice::winWidth, wyDevice::winHeight);
}
