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
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyEventDispatcher.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGLTexture2D.h"
#include "wyRunnable.h"

// mutex
extern pthread_mutex_t gMutex;
extern pthread_mutex_t gCondMutex;

bool wyEventDispatcher::releaseHandler(wyArray* arr, void* ptr, int index, void* data) {
	wyFree(ptr);
	return true;
}

bool wyEventDispatcher::releaseEvent(wyArray* arr, void* ptr, int index, void* data) {
	wyEvent* e = (wyEvent*)ptr;
	recycleEvent(e);
	wyFree(ptr);
	return true;
}

bool wyEventDispatcher::releaseRunnable(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

bool wyEventDispatcher::findHandler(void* elementPtr, void* ptr, void* data) {
	wyPriorityHandler* h = (wyPriorityHandler*)elementPtr;
	return h->node == ptr;
}

bool wyEventDispatcher::processEvent(wyArray* arr, void* ptr, int index, void* data) {
	wyEvent* e = (wyEvent*)ptr;
	wyEventDispatcher* d = (wyEventDispatcher*)data;

	switch(e->type) {
		case ET_ACCELEROMETER:
			d->wyAccelerometerChanged(e->ae.accelX, e->ae.accelY, e->ae.accelZ);
			break;
		case ET_TOUCH_BEGAN:
			d->wyTouchesBegan(e->me.pe);
			break;
		case ET_TOUCH_MOVED:
			d->wyTouchesMoved(e->me.pe);
			break;
		case ET_TOUCH_ENDED:
			d->wyTouchesEnded(e->me.pe);
			break;
		case ET_TOUCH_CANCELLED:
			d->wyTouchesCancelled(e->me.pe);
			break;
		case ET_TOUCH_POINTER_BEGAN:
			d->wyTouchesPointerBegan(e->me.pe);
			break;
		case ET_TOUCH_POINTER_END:
			d->wyTouchesPointerEnded(e->me.pe);
			break;
		case ET_DOUBLE_TAP:
			d->wyOnDoubleTap(e->me.pe);
			break;
		case ET_DOUBLE_TAP_EVENT:
			d->wyOnDoubleTapEvent(e->me.pe);
			break;
		case ET_SINGLE_TAP_CONFIRMED:
			d->wyOnSingleTapConfirmed(e->me.pe);
			break;
		case ET_KEY_DOWN:
			d->wyKeyDown(e->ke.pe);
			break;
		case ET_KEY_UP:
			d->wyKeyUp(e->ke.pe);
			break;
		case ET_KEY_MULTIPLE:
			d->wyKeyMultiple(e->ke.pe);
			break;
		case ET_ON_DOWN:
			d->wyOnDown(e->ge.pe1);
			break;
		case ET_ON_FLING:
			d->wyOnFling(e->ge.pe1, e->ge.pe2, e->ge.vx, -e->ge.vy);
			break;
		case ET_ON_SCROLL:
			d->wyOnScroll(e->ge.pe1, e->ge.pe2, e->ge.vx, -e->ge.vy);
			break;
		case ET_ON_LONG_PRESS:
			d->wyOnLongPress(e->ge.pe1);
			break;
		case ET_ON_SHOW_PRESS:
			d->wyOnShowPress(e->ge.pe1);
			break;
		case ET_ON_SINGLE_TAP_UP:
			d->wyOnSingleTapUp(e->ge.pe1);
			break;
		case ET_LOAD_TEXTURE:
			pthread_mutex_lock(&gCondMutex);
			e->lte.tex->load();
			pthread_cond_signal(e->lte.cond);
			pthread_mutex_unlock(&gCondMutex);
			break;
		case ET_DELETE_TEXTURE:
			pthread_mutex_lock(&gCondMutex);
			e->lte.tex->deleteTexture(false);
			pthread_cond_signal(e->lte.cond);
			pthread_mutex_unlock(&gCondMutex);
			break;
		case ET_UPDATE_TEXTURE:
			pthread_mutex_lock(&gCondMutex);
			e->lte.tex->doUpdateRaw();
			pthread_cond_signal(e->lte.cond);
			pthread_mutex_unlock(&gCondMutex);
			break;
		case ET_APPLY_COLOR_FILTER:
			pthread_mutex_lock(&gCondMutex);
			e->lte.tex->doApplyFilter();
			pthread_cond_signal(e->lte.cond);
			pthread_mutex_unlock(&gCondMutex);
			break;
		case ET_RUNNABLE:
			e->r.runnable->run();
			break;
		case ET_DRAIN_AUTO_RELEASE_POOL:
			wyObjectRelease(e->oe.obj);
			break;
		default:
			d->processUncommonEvent(e);
			break;
	}

	d->poolEvent(e);
	return true;
}

wyEventDispatcher::wyEventDispatcher() :
		m_dispatchEvents(true),
		m_pendingAccelHandlers(wyArrayNew(5)),
		m_pendingTouchHandlers(wyArrayNew(5)),
		m_pendingKeyHandlers(wyArrayNew(5)),
		m_pendingDoubleTapHandlers(wyArrayNew(5)),
		m_pendingGestureHandlers(wyArrayNew(5)),
		m_accelHandlers(wyArrayNew(5)),
		m_keyHandlers(wyArrayNew(5)),
		m_touchHandlers(wyArrayNew(5)),
		m_doubleTapHandlers(wyArrayNew(5)),
		m_gestureHandlers(wyArrayNew(5)),
		m_eventQueue(wyArrayNew(50)),
		m_pendingAddList(wyArrayNew(10)),
		m_eventPool(wyArrayNew(50)),
		m_runnables(wyArrayNew(10)) {
}

wyEventDispatcher::~wyEventDispatcher() {
	removeAllHandlersLocked();
	wyArrayDestroy(m_accelHandlers);
	wyArrayDestroy(m_keyHandlers);
	wyArrayDestroy(m_touchHandlers);
	wyArrayDestroy(m_doubleTapHandlers);
	wyArrayDestroy(m_gestureHandlers);
	wyArrayDestroy(m_pendingAccelHandlers);
	wyArrayDestroy(m_pendingTouchHandlers);
	wyArrayDestroy(m_pendingKeyHandlers);
	wyArrayDestroy(m_pendingDoubleTapHandlers);
	wyArrayDestroy(m_pendingGestureHandlers);
	wyArrayEach(m_eventQueue, releaseEvent, NULL);
	wyArrayDestroy(m_eventQueue);
	wyArrayEach(m_pendingAddList, releaseEvent, NULL);
	wyArrayDestroy(m_pendingAddList);
	wyArrayEach(m_runnables, releaseRunnable, NULL);
	wyArrayDestroy(m_runnables);
	wyArrayEach(m_eventPool, releaseEvent, NULL);
	wyArrayDestroy(m_eventPool);
}

void wyEventDispatcher::processEventsLocked() {
	pthread_mutex_lock(&gMutex);

	// add pending events to queue
	wyArrayPushAll(m_pendingAddList, m_eventQueue);
	wyArrayClear(m_pendingAddList);

	// add pending handlers to queue
	for(int i = 0; i < m_pendingAccelHandlers->num; i++)
		addAccelHandler((wyPriorityHandler*)wyArrayGet(m_pendingAccelHandlers, i));
	wyArrayClear(m_pendingAccelHandlers);
	for(int i = 0; i < m_pendingTouchHandlers->num; i++)
		addTouchHandler((wyPriorityHandler*)wyArrayGet(m_pendingTouchHandlers, i));
	wyArrayClear(m_pendingTouchHandlers);
	for(int i = 0; i < m_pendingKeyHandlers->num; i++)
		addKeyHandler((wyPriorityHandler*)wyArrayGet(m_pendingKeyHandlers, i));
	wyArrayClear(m_pendingKeyHandlers);
	for(int i = 0; i < m_pendingDoubleTapHandlers->num; i++)
		addDoubleTapHandler((wyPriorityHandler*)wyArrayGet(m_pendingDoubleTapHandlers, i));
	wyArrayClear(m_pendingDoubleTapHandlers);
	for(int i = 0; i < m_pendingGestureHandlers->num; i++)
		addGestureHandler((wyPriorityHandler*)wyArrayGet(m_pendingGestureHandlers, i));
	wyArrayClear(m_pendingGestureHandlers);

	pthread_mutex_unlock(&gMutex);

	// process events in queue
	wyArrayEach(m_eventQueue, processEvent, this);
	wyArrayClear(m_eventQueue);
}

wyEvent* wyEventDispatcher::popEvent() {
	wyEvent* e = (wyEvent*)wyArrayPop(m_eventPool);
	if(e == NULL)
		e = (wyEvent*)wyCalloc(1, sizeof(wyEvent));
	else
		memset(e, 0, sizeof(wyEvent));
	return e;
}

void wyEventDispatcher::poolEvent(wyEvent* e) {
	recycleEvent(e);
	wyArrayPush(m_eventPool, e);
}

void wyEventDispatcher::queueKeyEventLocked(wyEventType type, wyPlatformKeyEvent pe) {
	pthread_mutex_lock(&gMutex);

	// convert key event
	wyEvent* e = buildKeyEvent(type, pe);

	// push to pending list
	if(e) {
		wyArrayPush(m_pendingAddList, e);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(wyEventType type, wyPlatformMotionEvent pe) {
	pthread_mutex_lock(&gMutex);
	
	// push event to queue
	queueMotionEvent(type, pe);
	
	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) {
	pthread_mutex_lock(&gMutex);
	queueMotionEvent(type, pe1, pe2, vx, vy);
	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(wyEventType type, wyGLTexture2D* tex, pthread_cond_t* cond) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = type;
	e->lte.tex = tex;
	e->lte.cond = cond;
	wyArrayPush(m_pendingAddList, e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(wyEventType type, wyObject* obj) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = type;
	e->oe.obj = obj;
	wyArrayPush(m_pendingAddList, e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(float accelX, float accelY, float accelZ) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = ET_ACCELEROMETER;
	e->ae.accelX = accelX;
	e->ae.accelY = accelY;
	e->ae.accelZ = accelZ;
	wyArrayPush(m_pendingAddList, e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueRunnableLocked(wyRunnable* runnable) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = ET_RUNNABLE;
	e->r.runnable = runnable;
	wyObjectRetain(runnable);
	wyArrayPush(m_pendingAddList, e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addKeyHandler(wyPriorityHandler* h) {
    int i = 0;
    for(; i < m_keyHandlers->num; i++) {
    	wyPriorityHandler* p = (wyPriorityHandler*)wyArrayGet(m_keyHandlers, i);
    	if(p->priority <= h->priority) {
    		break;
    	}
    }
    wyArrayInsert(m_keyHandlers, h, i);
}

void wyEventDispatcher::addKeyHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

    if(wyArrayIndexOf(m_keyHandlers, node, findHandler, NULL) == -1 &&
		wyArrayIndexOf(m_pendingKeyHandlers, node, findHandler, NULL) == -1) {
    	wyPriorityHandler* h = (wyPriorityHandler*)wyCalloc(1, sizeof(wyPriorityHandler));
    	h->priority = priority;
    	h->node = node;
		wyArrayPush(m_pendingKeyHandlers, h);
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addAccelHandler(wyPriorityHandler* h) {
    int i = 0;
    for(; i < m_accelHandlers->num; i++) {
    	wyPriorityHandler* p = (wyPriorityHandler*)wyArrayGet(m_accelHandlers, i);
    	if(p->priority <= h->priority) {
    		break;
    	}
    }
    wyArrayInsert(m_accelHandlers, h, i);
}

void wyEventDispatcher::addAccelHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

    if(wyArrayIndexOf(m_accelHandlers, node, findHandler, NULL) == -1 &&
		wyArrayIndexOf(m_pendingAccelHandlers, node, findHandler, NULL) == -1) {
    	wyPriorityHandler* h = (wyPriorityHandler*)wyCalloc(1, sizeof(wyPriorityHandler));
    	h->priority = priority;
    	h->node = node;
		wyArrayPush(m_pendingAccelHandlers, h);

    	// check accelerometer listener
    	checkAccelHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addTouchHandler(wyPriorityHandler* h) {
    int i = 0;
    for(; i < m_touchHandlers->num; i++) {
    	wyPriorityHandler* p = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
    	if(p->priority <= h->priority) {
    		break;
    	}
    }
    wyArrayInsert(m_touchHandlers, h, i);
}

void wyEventDispatcher::addTouchHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

    if(wyArrayIndexOf(m_touchHandlers, node, findHandler, NULL) == -1 &&
		wyArrayIndexOf(m_pendingTouchHandlers, node, findHandler, NULL) == -1) {
    	wyPriorityHandler* h = (wyPriorityHandler*)wyCalloc(1, sizeof(wyPriorityHandler));
    	h->priority = priority;
    	h->node = node;
		wyArrayPush(m_pendingTouchHandlers, h);
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addDoubleTapHandler(wyPriorityHandler* h) {
    int i = 0;
    for(; i < m_doubleTapHandlers->num; i++) {
    	wyPriorityHandler* p = (wyPriorityHandler*)wyArrayGet(m_doubleTapHandlers, i);
    	if(p->priority <= h->priority) {
    		break;
    	}
    }
    wyArrayInsert(m_doubleTapHandlers, h, i);
}

void wyEventDispatcher::addDoubleTapHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

    if(wyArrayIndexOf(m_doubleTapHandlers, node, findHandler, NULL) == -1 &&
		wyArrayIndexOf(m_pendingDoubleTapHandlers, node, findHandler, NULL) == -1) {
    	wyPriorityHandler* h = (wyPriorityHandler*)wyCalloc(1, sizeof(wyPriorityHandler));
    	h->priority = priority;
    	h->node = node;
		wyArrayPush(m_pendingDoubleTapHandlers, h);

    	checkDoubleTapHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addGestureHandler(wyPriorityHandler* h) {
    int i = 0;
    for(; i < m_gestureHandlers->num; i++) {
    	wyPriorityHandler* p = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
    	if(p->priority <= h->priority) {
    		break;
    	}
    }
    wyArrayInsert(m_gestureHandlers, h, i);
}

void wyEventDispatcher::addGestureHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

    if(wyArrayIndexOf(m_gestureHandlers, node, findHandler, NULL) == -1 && 
		wyArrayIndexOf(m_pendingGestureHandlers, node, findHandler, NULL) == -1) {
    	wyPriorityHandler* h = (wyPriorityHandler*)wyCalloc(1, sizeof(wyPriorityHandler));
    	h->priority = priority;
    	h->node = node;
		wyArrayPush(m_pendingGestureHandlers, h);

    	checkGestureHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeAllHandlersLocked() {
	pthread_mutex_lock(&gMutex);

	wyArrayEach(m_accelHandlers, releaseHandler, NULL);
	wyArrayClear(m_accelHandlers);
	wyArrayEach(m_keyHandlers, releaseHandler, NULL);
	wyArrayClear(m_keyHandlers);
	wyArrayEach(m_touchHandlers, releaseHandler, NULL);
	wyArrayClear(m_touchHandlers);
	wyArrayEach(m_doubleTapHandlers, releaseHandler, NULL);
	wyArrayClear(m_doubleTapHandlers);
	wyArrayEach(m_gestureHandlers, releaseHandler, NULL);
	wyArrayClear(m_gestureHandlers);
	wyArrayEach(m_pendingAccelHandlers, releaseHandler, NULL);
	wyArrayClear(m_pendingAccelHandlers);
	wyArrayEach(m_pendingTouchHandlers, releaseHandler, NULL);
	wyArrayClear(m_pendingTouchHandlers);
	wyArrayEach(m_pendingKeyHandlers, releaseHandler, NULL);
	wyArrayClear(m_pendingKeyHandlers);
	wyArrayEach(m_pendingDoubleTapHandlers, releaseHandler, NULL);
	wyArrayClear(m_pendingDoubleTapHandlers);
	wyArrayEach(m_pendingGestureHandlers, releaseHandler, NULL);
	wyArrayClear(m_pendingGestureHandlers);

	// check accelerometer listener
	checkAccelHandlers();

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeKeyHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = wyArrayIndexOf(m_keyHandlers, node, findHandler, NULL);
	if(index != -1)
		wyFree(wyArrayDeleteIndex(m_keyHandlers, index));
	else {
		index = wyArrayIndexOf(m_pendingKeyHandlers, node, findHandler, NULL);
		if(index != -1)
			wyFree(wyArrayDeleteIndex(m_pendingKeyHandlers, index));
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeAccelHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = wyArrayIndexOf(m_accelHandlers, node, findHandler, NULL);
	if(index != -1) {
		wyFree(wyArrayDeleteIndex(m_accelHandlers, index));
	} else {
		index = wyArrayIndexOf(m_pendingAccelHandlers, node, findHandler, NULL);
		if(index != -1)
			wyFree(wyArrayDeleteIndex(m_pendingAccelHandlers, index));
	}

	// check accelerometer listener
	checkAccelHandlers();

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeTouchHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = wyArrayIndexOf(m_touchHandlers, node, findHandler, NULL);
	if(index != -1) {
		wyFree(wyArrayDeleteIndex(m_touchHandlers, index));
	} else {
		index = wyArrayIndexOf(m_pendingTouchHandlers, node, findHandler, NULL);
		if(index != -1)
			wyFree(wyArrayDeleteIndex(m_pendingTouchHandlers, index));
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeDoubleTapHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = wyArrayIndexOf(m_doubleTapHandlers, node, findHandler, NULL);
	if(index != -1) {
		wyFree(wyArrayDeleteIndex(m_doubleTapHandlers, index));
	} else {
		index = wyArrayIndexOf(m_pendingDoubleTapHandlers, node, findHandler, NULL);
		if(index != -1)
			wyFree(wyArrayDeleteIndex(m_pendingDoubleTapHandlers, index));
	}

	checkDoubleTapHandlers();

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeGestureHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = wyArrayIndexOf(m_gestureHandlers, node, findHandler, NULL);
	if(index != -1) {
		wyFree(wyArrayDeleteIndex(m_gestureHandlers, index));
	} else {
		index = wyArrayIndexOf(m_pendingGestureHandlers, node, findHandler, NULL);
		if(index != -1)
			wyFree(wyArrayDeleteIndex(m_pendingGestureHandlers, index));
	}

	checkGestureHandlers();

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::setKeyHandlerPriorityLocked(wyNode* node, int priority) {
	removeKeyHandlerLocked(node);
	addKeyHandlerLocked(node, priority);
}

void wyEventDispatcher::setAccelHandlerPriorityLocked(wyNode* node, int priority) {
	removeAccelHandlerLocked(node);
	addAccelHandlerLocked(node, priority);
}

void wyEventDispatcher::setTouchHandlerPriorityLocked(wyNode* node, int priority) {
	removeTouchHandlerLocked(node);
	addTouchHandlerLocked(node, priority);
}

void wyEventDispatcher::setDoubleTapHandlerPriorityLocked(wyNode* node, int priority) {
	removeDoubleTapHandlerLocked(node);
	addDoubleTapHandlerLocked(node, priority);
}

void wyEventDispatcher::setGestureHandlerPriorityLocked(wyNode* node, int priority) {
	removeGestureHandlerLocked(node);
	addGestureHandlerLocked(node, priority);
}

void wyEventDispatcher::cancelTouch(wyMotionEvent& e, wyNode* parent) {
	if(m_dispatchEvents) {
		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(node->hasTouch() && parent->isAncestor(node)) {
				node->clearTouch();
				node->touchesCancelled(e);
			}
		}
	}
}

void wyEventDispatcher::cancelTouchExcept(wyMotionEvent& e, wyNode* excludeNode) {
	if(m_dispatchEvents) {
		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(excludeNode != node && node->hasTouch()) {
				node->clearTouch();
				node->touchesCancelled(e);
			}
		}
	}
}

void wyEventDispatcher::dispatchAccelerometerChanged(wyNode* node, float accelX, float accelY, float accelZ) {
	node->accelerometerChanged(accelX, accelY, accelZ);
}

void wyEventDispatcher::wyAccelerometerChanged(float accelX, float accelY, float accelZ) {
	if(m_dispatchEvents) {
		for(int i = 0; i < m_accelHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_accelHandlers, i);
			wyNode* node = h->node;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
				dispatchAccelerometerChanged(node, accelX, accelY, accelZ);
			}
		}
	}
}

bool wyEventDispatcher::dispatchKeyDown(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke) {
	return node->keyDown(ke);
}

bool wyEventDispatcher::wyKeyDown(wyPlatformKeyEvent event) {
	if(m_dispatchEvents) {
		wyKeyEvent ke;
		wyUtils::convertKeyEvent(event, &ke);

		for(int i = 0; i < m_keyHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_keyHandlers, i);
			wyNode* node = h->node;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
				if(dispatchKeyDown(node, event, ke))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchKeyUp(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke) {
	return node->keyUp(ke);
}

bool wyEventDispatcher::wyKeyUp(wyPlatformKeyEvent event) {
	if(m_dispatchEvents) {
		wyKeyEvent ke;
		wyUtils::convertKeyEvent(event, &ke);

		for(int i = 0; i < m_keyHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_keyHandlers, i);
			wyNode* node = h->node;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
				if(dispatchKeyUp(node, event, ke))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchKeyMultiple(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke) {
	return node->keyMultiple(ke);
}

bool wyEventDispatcher::wyKeyMultiple(wyPlatformKeyEvent event) {
	if(m_dispatchEvents) {
		wyKeyEvent ke;
		wyUtils::convertKeyEvent(event, &ke);

		for(int i = 0; i < m_keyHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_keyHandlers, i);
			wyNode* node = h->node;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
				if(dispatchKeyMultiple(node, event, ke))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchTouchesBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->touchesBegan(me);
}

bool wyEventDispatcher::wyTouchesBegan(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				node->trackTouch(me.pid[0]);
				if(dispatchTouchesBegan(node, event, me)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchTouchesMoved(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->touchesMoved(me);
}

bool wyEventDispatcher::wyTouchesMoved(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(node->hasTouch()) {
				if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
					if(dispatchTouchesMoved(node, event, me)) {
						return true;
					}
				} else {
					node->clearTouch();
				}
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchTouchesEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
	if(zeroSize || node->hitTest(me.x[0], me.y[0])) {
		if(node->touchesEnded(me))
			return true;
	} else {
		if(node->touchesCancelled(me))
			return true;
	}

	return false;
}

bool wyEventDispatcher::wyTouchesEnded(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		bool end = false;
		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(node->hasPid(me.pid[0])) {
				node->clearTouch();
				node->setSelected(false);

				if(!end) {
					if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot())
						end = dispatchTouchesEnded(node, event, me);
				}
			}
		}

		return end;
	}

	return false;
}

bool wyEventDispatcher::dispatchTouchesCancelled(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->touchesCancelled(me);
}

bool wyEventDispatcher::wyTouchesCancelled(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(node->hasPid(me.pid[0])) {
				node->clearTouch();

				if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot()) {
					if(dispatchTouchesCancelled(node, event, me))
						return true;
				}
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchTouchesPointerBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->touchesPointerBegan(me);
}

bool wyEventDispatcher::wyTouchesPointerBegan(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me, (int)ET_TOUCH_POINTER_BEGAN);

		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;

			// decide whether node can receive this event
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[me.index], me.y[me.index]))) {
				node->trackTouch(me.pid[me.index]);
				if(dispatchTouchesPointerBegan(node, event, me))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchTouchesPointerEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->touchesPointerEnded(me);
}

bool wyEventDispatcher::wyTouchesPointerEnded(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me, (int)ET_TOUCH_POINTER_END);

		bool end = false;
		for(int i = 0; i < m_touchHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_touchHandlers, i);
			wyNode* node = h->node;
			if(node->hasPid(me.pid[me.index])) {
				// place clearPid before deliver event in case node is released in touchesPointerEnded
				node->clearPid(me.pid[me.index]);

				if(!end) {
					if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot())
						end = dispatchTouchesPointerEnded(node, event, me);
				}
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchOnDoubleTap(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->onDoubleTap(me);
}

bool wyEventDispatcher::wyOnDoubleTap(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_doubleTapHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_doubleTapHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnDoubleTap(node, event, me))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchOnDoubleTapEvent(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->onDoubleTapEvent(me);
}

bool wyEventDispatcher::wyOnDoubleTapEvent(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_doubleTapHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_doubleTapHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnDoubleTapEvent(node, event, me))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchOnSingleTapConfirmed(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->onSingleTapConfirmed(me);
}

bool wyEventDispatcher::wyOnSingleTapConfirmed(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_doubleTapHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_doubleTapHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnSingleTapConfirmed(node, event, me))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchOnDown(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->onDown(me);
}

bool wyEventDispatcher::wyOnDown(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnDown(node, event, me))
					return true;
			}
		}
	}
	return false;
}

bool wyEventDispatcher::dispatchOnFling(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float velocityX, float velocityY) {
	return node->onFling(me1, me2, velocityX, velocityY);
}

bool wyEventDispatcher::wyOnFling(wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, float velocityX, float velocityY) {
	if(m_dispatchEvents) {
		wyMotionEvent me1;
		wyUtils::convertMotionEvent(e1, &me1);
		wyMotionEvent me2;
		wyUtils::convertMotionEvent(e2, &me2);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
            bool hit = zeroSize || node->hitTest(me1.x[0], me1.y[0]) && node->hitTest(me2.x[0], me2.y[0]);
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (hit || node->hasTouch())) {
				if(dispatchOnFling(node, e1, e2, me1, me2, velocityX, velocityY))
					return true;
			}
		}
	}
	return false;
}

void wyEventDispatcher::dispatchOnLongPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	node->onLongPress(me);
}

void wyEventDispatcher::wyOnLongPress(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				dispatchOnLongPress(node, event, me);
			}
		}
	}
}

bool wyEventDispatcher::dispatchOnScroll(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float distanceX, float distanceY) {
	return node->onScroll(me1, me2, distanceX, distanceY);
}

bool wyEventDispatcher::wyOnScroll(wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, float distanceX, float distanceY) {
	if(m_dispatchEvents) {
		wyMotionEvent me1;
		wyUtils::convertMotionEvent(e1, &me1);
		wyMotionEvent me2;
		wyUtils::convertMotionEvent(e2, &me2);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me1.x[0], me1.y[0]) && node->hitTest(me2.x[0], me2.y[0]))) {
				if(dispatchOnScroll(node, e1, e2, me1, me2, distanceX, distanceY))
					return true;
			}
		}
	}
	return false;
}

void wyEventDispatcher::dispatchOnShowPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	node->onShowPress(me);
}

void wyEventDispatcher::wyOnShowPress(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				dispatchOnShowPress(node, event, me);
			}
		}
	}
}

bool wyEventDispatcher::dispatchOnSingleTapUp(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me) {
	return node->onSingleTapUp(me);
}

bool wyEventDispatcher::wyOnSingleTapUp(wyPlatformMotionEvent event) {
	if(m_dispatchEvents) {
		wyMotionEvent me;
		wyUtils::convertMotionEvent(event, &me);

		for(int i = 0; i < m_gestureHandlers->num; i++) {
			wyPriorityHandler* h = (wyPriorityHandler*)wyArrayGet(m_gestureHandlers, i);
			wyNode* node = h->node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnSingleTapUp(node, event, me))
					return true;
			}
		}
	}
	return false;
}
