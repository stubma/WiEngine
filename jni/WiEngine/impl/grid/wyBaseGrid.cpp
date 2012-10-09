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
#include "wyBaseGrid.h"
#include "wyDirector.h"
#include "wyNode.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGlobal.h"

extern wyDirector* gDirector;

wyBaseGrid::~wyBaseGrid() {
	wyObjectRelease(m_grabber);
	wyFree(m_vertices);
	wyFree(m_originalVertices);
	wyFree(m_texCoords);
	wyFree(m_indices);
}

wyBaseGrid::wyBaseGrid(float w, float h, int c, int r) :
		m_gridX(c),
		m_gridY(r),
		m_width(w),
		m_height(h),
		m_stepWidth(w / c),
		m_stepHeight(h / r),
		m_active(false),
		m_reuseGrid(0),
		m_vertices(NULL),
		m_texCoords(NULL),
		m_originalVertices(NULL),
		m_indices(NULL) {
	m_grabber = wyGrabber::make(w, h);
	m_grabber->retain();
}

void wyBaseGrid::beforeDraw() {
	m_grabber->beforeRender();
}

void wyBaseGrid::afterDraw(wyNode* node) {
	// TODO gles2
//	m_grabber->afterRender();
//
//	// need to recover matrix for blit operation
//	gDirector->set3DProjection();
//
//	if(node->hasCamera()) {
//		wyCamera* camera = node->getCamera();
//		if(camera->isDirty()) {
//			glTranslatef(node->getAnchorPointX(), node->getAnchorPointY(), 0);
//			camera->locate();
//			glTranslatef(-node->getAnchorPointX(), -node->getAnchorPointY(), 0);
//		}
//	}
//
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, m_grabber->getTexture());
//
//    blit();
//    glDisable(GL_TEXTURE_2D);
}

void wyBaseGrid::setActive(bool flag) {
	// TODO gles2
//	m_active = flag;
//	if(!m_active) {
//		gDirector->setProjection(gDirector->getProjection());
//	}
}
