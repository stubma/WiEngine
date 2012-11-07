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
#include "wyNode.h"
#include "wyAction.h"

wyAction::wyAction() :
		m_target(NULL),
		m_running(false),
		m_paused(false),
		m_tag(WY_ACTION_INVALID_TAG),
		m_parent(NULL),
		m_data(NULL) {
	memset(&m_callback, 0, sizeof(wyActionCallback));
}

wyAction::~wyAction() {
	wyObjectRelease(m_target);
}

wyAction* wyAction::copy() {
	return NULL;
}

wyAction* wyAction::reverse() {
	return NULL;
}

void wyAction::start(wyNode* target) {
	if(!m_running) {
		wyObjectRetain(target);
		wyObjectRelease(m_target);
		m_target = target;

		// set flag
		m_running = true;

		// callback
		invokeOnStart();
	}
}

void wyAction::stop() {
	if(m_running) {
		// set flag
		m_running = false;

		// callback
		invokeOnStop();
	}
}

void wyAction::step(float t) {
}

void wyAction::update(float t) {
	invokeOnUpdate(t);
}

bool wyAction::isDone() {
	return true;
}

void wyAction::setCallback(wyActionCallback* callback, void* data) {
	if(callback == NULL) {
		memset(&m_callback, 0, sizeof(wyActionCallback));
		m_data = NULL;
	} else {
		memcpy(&m_callback, callback, sizeof(wyActionCallback));
		m_data = data;
	}
}

void wyAction::setTag(int tag) {
	m_tag = tag;
}

int wyAction::getTag() {
	return m_tag;
}

wyNode* wyAction::getTarget() {
	return m_target;
}

void wyAction::invokeOnStart() {
	if(m_callback.onStart != NULL) {
		m_callback.onStart(this, m_data);
	}
}

void wyAction::invokeOnStop() {
	if(m_callback.onStop != NULL) {
		m_callback.onStop(this, m_data);
	}
}

void wyAction::invokeOnUpdate(float t) {
	if(m_callback.onUpdate != NULL) {
		m_callback.onUpdate(this, t, m_data);
	}
}
