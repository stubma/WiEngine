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
#if WINDOWS

#include "wyEventDispatcher_win.h"
#include "wyLog.h"
#include "wyRunnable.h"
#include "wyDirector.h"
#include "wyWinGLView.h"

// shared instance
wyEventDispatcher* gEventDispatcher = NULL;

// extern global
extern wyDirector* gDirector;

wyEventDispatcher* wyEventDispatcher::getInstance() {
	if(gEventDispatcher == NULL) {
		gEventDispatcher = WYNEW wyEventDispatcher_win();
	}
	return gEventDispatcher;
}

wyEventDispatcher* wyEventDispatcher::getInstanceNoCreate() {
	return gEventDispatcher;
}

void wyEventDispatcher::recycleEvent(wyEvent* e) {
	switch(e->type) {
		case ET_TOUCH_BEGAN:
		case ET_TOUCH_MOVED:
		case ET_TOUCH_ENDED:
		case ET_TOUCH_CANCELLED:
		case ET_TOUCH_POINTER_BEGAN:
		case ET_TOUCH_POINTER_END:
			if(e->me.pe) {
				wyFree(e->me.pe);
				e->me.pe = NULL;
			}
			break;
		case ET_ON_DOWN:
		case ET_ON_FLING:
		case ET_ON_SCROLL:
		case ET_ON_SINGLE_TAP_UP:
		case ET_ON_LONG_PRESS:
		case ET_ON_SHOW_PRESS:
		case ET_DOUBLE_TAP:
		case ET_DOUBLE_TAP_EVENT:
		case ET_SINGLE_TAP_CONFIRMED:
			if(e->ge.pe1 != NULL) {
				wyFree(e->ge.pe1);
				e->ge.pe1 = NULL;
			}
			if(e->ge.pe2 != NULL) {
				wyFree(e->ge.pe2);
				e->ge.pe2 = NULL;
			}
			break;
		case ET_KEY_DOWN:
		case ET_KEY_UP:
		case ET_KEY_MULTIPLE:
			if(e->ke.pe != NULL) {
				wyFree(e->ke.pe);
				e->ke.pe = NULL;
			}
			break;
		case ET_RUNNABLE:
			wyObjectRelease(e->r.runnable);
			e->r.runnable = NULL;
			break;
	}
}

wyEventDispatcher_win::wyEventDispatcher_win() {
}

wyEventDispatcher_win::~wyEventDispatcher_win() {
	gEventDispatcher = NULL;
}

void wyEventDispatcher_win::checkAccelHandlers() {
	// no need in windows
}

void wyEventDispatcher_win::checkDoubleTapHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	glView->setDetectGesture((m_doubleTapHandlers->num + m_gestureHandlers->num + m_pendingDoubleTapHandlers->num + m_pendingGestureHandlers->num) > 0);
}

void wyEventDispatcher_win::checkGestureHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	glView->setDetectGesture((m_doubleTapHandlers->num + m_gestureHandlers->num + m_pendingDoubleTapHandlers->num + m_pendingGestureHandlers->num) > 0);
}

wyEvent* wyEventDispatcher_win::buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe) {
	// get pooled event
	wyEvent* e = popEvent();
	e->type = type;
	e->ke.pe = (wyKeyEvent*)wyMalloc(sizeof(wyKeyEvent));
	memcpy(e->ke.pe, pe, sizeof(wyKeyEvent));
	return e;
}

void wyEventDispatcher_win::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe) {
	wyEvent* e = popEvent();
	e->type = type;
	e->me.pe = (wyMotionEvent*)wyMalloc(sizeof(wyMotionEvent));
	memcpy(e->me.pe, pe, sizeof(wyMotionEvent));
	wyArrayPush(m_pendingAddList, e);
}

void wyEventDispatcher_win::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) {
	wyEvent* e = popEvent();
	e->type = type;
	e->ge.vx = vx;
	e->ge.vy = vy;
	e->ge.pe1 = (wyMotionEvent*)wyMalloc(sizeof(wyMotionEvent));
	memcpy(e->ge.pe1, pe1, sizeof(wyMotionEvent));
	e->ge.pe2 = (wyMotionEvent*)wyMalloc(sizeof(wyMotionEvent));
	memcpy(e->ge.pe2, pe2, sizeof(wyMotionEvent));
	
	wyArrayPush(m_pendingAddList, e);
}

#endif // #if WINDOWS
