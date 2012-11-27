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
#include "wyGridController.h"
#include "wyFrameBuffer.h"
#include "wyDirector.h"
#include "wyNode.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyGrid3D.h"
#include "wyTiledGrid3D.h"
#include "wyRenderManager.h"

extern wyDirector* gDirector;

wyGridController::~wyGridController() {
	wyObjectRelease(m_fb);
	wyObjectRelease(m_mesh);
}

wyGridController::wyGridController(float w, float h, int c, int r) :
		m_active(false),
		m_fb(NULL),
		m_mesh(NULL),
		m_reuseGrid(0) {
	m_fb = wyFrameBuffer::make(w, h);
	m_fb->retain();
}

wyGridController* wyGridController::make3D(float w, float h, int c, int r) {
    // the grid need to be flipped in y axis because framebuffer texture is upside-down
	wyGridController* g = WYNEW wyGridController(w, h, c, r);
	g->m_mesh = wyGrid3D::make(w, h, c, r);
	g->m_mesh->retain();
    g->m_mesh->setFlipY(true);
	g->m_mesh->update();
	return (wyGridController*)g->autoRelease();
}

wyGridController* wyGridController::makeTiled3D(float w, float h, int c, int r) {
    // the grid need to be flipped in y axis because framebuffer texture is upside-down
	wyGridController* g = WYNEW wyGridController(w, h, c, r);
	g->m_mesh = wyTiledGrid3D::make(w, h, c, r);
	g->m_mesh->retain();
    g->m_mesh->setFlipY(true);
	g->m_mesh->update();
	return (wyGridController*)g->autoRelease();
}

void wyGridController::beforeDraw() {
	m_fb->beforeRender();
}

void wyGridController::afterDraw(wyNode* node) {
	m_fb->afterRender();

	// render texture of frame buffer
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();
	rm->renderMaterial(m_fb->getMaterial(), m_mesh);
}

void wyGridController::setActive(bool flag) {
	m_active = flag;
}

void wyGridController::reuse() {
	if(m_reuseGrid > 0) {
		m_mesh->reuse();
		m_reuseGrid--;
	}
}
