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
#include "wyViewport.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyRenderQueue.h"
#include "wyTransitionScene.h"

wyViewport::wyViewport(const char* name, wyCamera* camera) :
		m_name(wyUtils::copy(name)),
		m_color(wyc4bTransparent),
		m_enabled(true),
		m_leftLeaf(NULL),
		m_rightLeaf(NULL),
		m_root(NULL),
		m_clearColor(false),
		m_clearDepth(false),
		m_clearStencil(false) {
	m_camera = camera;
	wyObjectRetain(m_camera);

	m_queue = wyRenderQueue::make();
	m_queue->retain();
}

wyViewport::~wyViewport() {
	// free members
	wyObjectRelease(m_camera);
	m_queue->release();

	// free name
	if(m_name)
		wyFree((void*)m_name);
}

wyViewport* wyViewport::make(wyCamera* camera) {
	return make(NULL, camera);
}

wyViewport* wyViewport::make(const char* name, wyCamera* camera) {
	wyViewport* v = WYNEW wyViewport(name, camera);
	return (wyViewport*)v->autoRelease();
}

void wyViewport::attachRoot(wyNode* root) {
	m_root = root;
	m_leftLeaf = NULL;
	m_rightLeaf = NULL;
}

void wyViewport::attachScene(wyScene* s) {
	// set root
	m_root = s;

	// if scene is a transition, we can set leaf nodes
	if(s) {
		if(s->isTransition()) {
			wyTransitionScene* ts = (wyTransitionScene*)s;
			if(ts->shouldInSceneOnTop()) {
				m_leftLeaf = ts->getOutScene();
				m_rightLeaf = ts->getInScene();
			} else {
				m_leftLeaf = ts->getInScene();
				m_rightLeaf = ts->getOutScene();
			}
		} else {
			m_leftLeaf = NULL;
			m_rightLeaf = NULL;
		}
	} else {
		m_leftLeaf = NULL;
		m_rightLeaf = NULL;
	}
}

void wyViewport::setClearFlag(bool clearColor, bool clearDepth, bool clearStencil) {
	m_clearColor = clearColor;
	m_clearDepth = clearDepth;
	m_clearStencil = clearStencil;
}

void wyViewport::setBackgroundColor(wyColor4B color) {
	m_color = color;
}
