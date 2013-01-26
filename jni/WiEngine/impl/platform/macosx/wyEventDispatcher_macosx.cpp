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
#if MACOSX

#include "wyEventDispatcher_macosx.h"
#include "wyDirector.h"

// shared instance
wyEventDispatcher_macosx* gEventDispatcher;

// extern global
extern wyDirector* gDirector;

wyEventDispatcher* wyEventDispatcher::getInstance() {
	if(gEventDispatcher == NULL) {
		gEventDispatcher = WYNEW wyEventDispatcher_macosx();
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
		case ET_DOUBLE_TAP:
		case ET_DOUBLE_TAP_EVENT:
		case ET_SINGLE_TAP_CONFIRMED:
			if(e->me.pe != NULL) {
				[e->me.pe release];
				e->me.pe = NULL;
			}
			break;
		case ET_ON_DOWN:
		case ET_ON_FLING:
		case ET_ON_SCROLL:
		case ET_ON_SINGLE_TAP_UP:
		case ET_ON_LONG_PRESS:
		case ET_ON_SHOW_PRESS:
			if(e->ge.pe1 != NULL) {
				[e->ge.pe1 release];
				e->ge.pe1 = NULL;
			}
			if(e->ge.pe2 != NULL) {
				[e->ge.pe2 release];
				e->ge.pe2 = NULL;
			}
			break;
		case ET_KEY_DOWN:
		case ET_KEY_UP:
		case ET_KEY_MULTIPLE:
			if(e->ke.pe != NULL) {
				[e->ke.pe release];
				e->ke.pe = NULL;
			}
			break;
	}
}

wyEventDispatcher_macosx::wyEventDispatcher_macosx() {
}

wyEventDispatcher_macosx::~wyEventDispatcher_macosx() {
	gEventDispatcher = NULL;
}

void wyEventDispatcher_macosx::checkAccelHandlers() {
	// no need in mac os x
}

void wyEventDispatcher_macosx::checkDoubleTapHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	[glView setDetectGesture:(m_doubleTapHandlers.size() + m_gestureHandlers.size() + m_pendingAddDoubleTapHandlers.size() + m_pendingAddGestureHandlers.size()) > 0];
}

void wyEventDispatcher_macosx::checkGestureHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	[glView setDetectGesture:(m_doubleTapHandlers.size() + m_gestureHandlers.size() + m_pendingAddDoubleTapHandlers.size() + m_pendingAddGestureHandlers.size()) > 0];
}

wyEvent* wyEventDispatcher_macosx::buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe) {
	// get pooled event
	wyEvent* e = popEvent();
	e->type = type;
	e->ke.pe = pe;
	[e->ke.pe retain];
	return e;
}

void wyEventDispatcher_macosx::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe) {
	switch(type) {
		case ET_ON_DOWN:
		case ET_ON_SHOW_PRESS:
		case ET_ON_SINGLE_TAP_UP:
		case ET_SINGLE_TAP_CONFIRMED:
		case ET_DOUBLE_TAP:
		case ET_DOUBLE_TAP_EVENT:
		case ET_ON_LONG_PRESS:
		{
			wyEvent* e = popEvent();
			e->type = type;
			e->ge.pe1 = pe;
			[e->ge.pe1 retain];
			m_pendingAddEvents.push_back(e);
			break;
		}
		default:
		{
			wyEvent* e = popEvent();
			e->type = type;
			e->me.pe = pe;
			[e->me.pe retain];
			m_pendingAddEvents.push_back(e);
			break;
		}
	}
	
	// iOS can process the event immediately because thread is same
	processEventsLocked();
}

void wyEventDispatcher_macosx::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) {
	wyEvent* e = popEvent();
	e->type = type;
	e->ge.vx = vx;
	e->ge.vy = vy;
	e->ge.pe1 = pe1;
	e->ge.pe2 = pe2;
	[e->ge.pe1 retain];
	[e->ge.pe2 retain];
	
	m_pendingAddEvents.push_back(e);
}

#endif // #if MACOSX
