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

void wyEventDispatcher::releaseEvents(EventPtrList& list) {
	for(EventPtrList::iterator iter = list.begin(); iter != list.end(); iter++) {
		recycleEvent(*iter);
		wyFree(*iter);
	}
}

int wyEventDispatcher::findHandler(HandlerList& list, wyNode* node) {
	for(HandlerList::iterator iter = list.begin(); iter != list.end(); iter++) {
		if(iter->node == node)
			return iter - list.begin();
	}

	return -1;
}

int wyEventDispatcher::findNode(NodePtrList& list, wyNode* node) {
	for(NodePtrList::iterator iter = list.begin(); iter != list.end(); iter++) {
		if(*iter == node)
			return iter - list.begin();
	}

	return -1;
}

void wyEventDispatcher::processEvent(wyEvent* e) {
	switch(e->type) {
		case ET_ACCELEROMETER:
			wyAccelerometerChanged(e->ae.accelX, e->ae.accelY, e->ae.accelZ);
			break;
		case ET_TOUCH_BEGAN:
			wyTouchesBegan(e->me.pe);
			break;
		case ET_TOUCH_MOVED:
			wyTouchesMoved(e->me.pe);
			break;
		case ET_TOUCH_ENDED:
			wyTouchesEnded(e->me.pe);
			break;
		case ET_TOUCH_CANCELLED:
			wyTouchesCancelled(e->me.pe);
			break;
		case ET_TOUCH_POINTER_BEGAN:
			wyTouchesPointerBegan(e->me.pe);
			break;
		case ET_TOUCH_POINTER_END:
			wyTouchesPointerEnded(e->me.pe);
			break;
		case ET_DOUBLE_TAP:
			wyOnDoubleTap(e->me.pe);
			break;
		case ET_DOUBLE_TAP_EVENT:
			wyOnDoubleTapEvent(e->me.pe);
			break;
		case ET_SINGLE_TAP_CONFIRMED:
			wyOnSingleTapConfirmed(e->me.pe);
			break;
		case ET_KEY_DOWN:
			wyKeyDown(e->ke.pe);
			break;
		case ET_KEY_UP:
			wyKeyUp(e->ke.pe);
			break;
		case ET_KEY_MULTIPLE:
			wyKeyMultiple(e->ke.pe);
			break;
		case ET_ON_DOWN:
			wyOnDown(e->ge.pe1);
			break;
		case ET_ON_FLING:
			wyOnFling(e->ge.pe1, e->ge.pe2, e->ge.vx, -e->ge.vy);
			break;
		case ET_ON_SCROLL:
			wyOnScroll(e->ge.pe1, e->ge.pe2, e->ge.vx, -e->ge.vy);
			break;
		case ET_ON_LONG_PRESS:
			wyOnLongPress(e->ge.pe1);
			break;
		case ET_ON_SHOW_PRESS:
			wyOnShowPress(e->ge.pe1);
			break;
		case ET_ON_SINGLE_TAP_UP:
			wyOnSingleTapUp(e->ge.pe1);
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
			processUncommonEvent(e);
			break;
	}

	poolEvent(e);
}

wyEventDispatcher::wyEventDispatcher() :
		m_dispatchEvents(true) {
}

wyEventDispatcher::~wyEventDispatcher() {
	removeAllHandlersLocked();
	releaseEvents(m_eventQueue);
	releaseEvents(m_pendingAddEvents);
	releaseEvents(m_eventPool);
}

void wyEventDispatcher::processEventsLocked() {
	pthread_mutex_lock(&gMutex);

	// add pending events to queue
	for(EventPtrList::iterator iter = m_pendingAddEvents.begin(); iter != m_pendingAddEvents.end(); iter++) {
		m_eventQueue.push_back(*iter);
	}
	m_pendingAddEvents.clear();

	// remove pending handlers from queue
	for(NodePtrList::iterator iter = m_pendingRemoveAccelHandlerNodes.begin(); iter != m_pendingRemoveAccelHandlerNodes.end(); iter++) {
		int index = findHandler(m_accelHandlers, *iter);
		if(index != -1)
			m_accelHandlers.erase(m_accelHandlers.begin() + index);
	}
	for(NodePtrList::iterator iter = m_pendingRemoveTouchHandlerNodes.begin(); iter != m_pendingRemoveTouchHandlerNodes.end(); iter++) {
		int index = findHandler(m_touchHandlers, *iter);
		if(index != -1)
			m_touchHandlers.erase(m_touchHandlers.begin() + index);
	}
	for(NodePtrList::iterator iter = m_pendingRemoveKeyHandlerNodes.begin(); iter != m_pendingRemoveKeyHandlerNodes.end(); iter++) {
		int index = findHandler(m_keyHandlers, *iter);
		if(index != -1)
			m_keyHandlers.erase(m_keyHandlers.begin() + index);
	}
	for(NodePtrList::iterator iter = m_pendingRemoveDoubleTapHandlerNodes.begin(); iter != m_pendingRemoveDoubleTapHandlerNodes.end(); iter++) {
		int index = findHandler(m_doubleTapHandlers, *iter);
		if(index != -1)
			m_doubleTapHandlers.erase(m_doubleTapHandlers.begin() + index);
	}
	for(NodePtrList::iterator iter = m_pendingRemoveGestureHandlerNodes.begin(); iter != m_pendingRemoveGestureHandlerNodes.end(); iter++) {
		int index = findHandler(m_gestureHandlers, *iter);
		if(index != -1)
			m_gestureHandlers.erase(m_gestureHandlers.begin() + index);
	}
	m_pendingRemoveAccelHandlerNodes.clear();
	m_pendingRemoveTouchHandlerNodes.clear();
	m_pendingRemoveKeyHandlerNodes.clear();
	m_pendingRemoveDoubleTapHandlerNodes.clear();
	m_pendingRemoveGestureHandlerNodes.clear();

	// add pending handlers to queue
	for(HandlerList::iterator iter = m_pendingAddAccelHandlers.begin(); iter != m_pendingAddAccelHandlers.end(); iter++) {
		addAccelHandler(*iter);
	}
	for(HandlerList::iterator iter = m_pendingAddTouchHandlers.begin(); iter != m_pendingAddTouchHandlers.end(); iter++) {
		addTouchHandler(*iter);
	}
	for(HandlerList::iterator iter = m_pendingAddKeyHandlers.begin(); iter != m_pendingAddKeyHandlers.end(); iter++) {
		addKeyHandler(*iter);
	}
	for(HandlerList::iterator iter = m_pendingAddDoubleTapHandlers.begin(); iter != m_pendingAddDoubleTapHandlers.end(); iter++) {
		addDoubleTapHandler(*iter);
	}
	for(HandlerList::iterator iter = m_pendingAddGestureHandlers.begin(); iter != m_pendingAddGestureHandlers.end(); iter++) {
		addGestureHandler(*iter);
	}
	m_pendingAddAccelHandlers.clear();
	m_pendingAddTouchHandlers.clear();
	m_pendingAddKeyHandlers.clear();
	m_pendingAddDoubleTapHandlers.clear();
	m_pendingAddGestureHandlers.clear();

	pthread_mutex_unlock(&gMutex);

	// process events in queue
	for(EventPtrList::iterator iter = m_eventQueue.begin(); iter != m_eventQueue.end(); iter++) {
		processEvent(*iter);
	}
	m_eventQueue.clear();
}

wyEvent* wyEventDispatcher::popEvent() {
	wyEvent* e = NULL;
	if(m_eventPool.empty()) {
		e = (wyEvent*)wyCalloc(1, sizeof(wyEvent));
	} else {
		EventPtrList::reverse_iterator iter = m_eventPool.rbegin();
		e = *iter;
		m_eventPool.pop_back();
		memset(e, 0, sizeof(wyEvent));
	}

	return e;
}

void wyEventDispatcher::poolEvent(wyEvent* e) {
	recycleEvent(e);
	m_eventPool.push_back(e);
}

bool wyEventDispatcher::hasAccelHandlers() {
	return !m_accelHandlers.empty() || !m_pendingAddAccelHandlers.empty();
}

void wyEventDispatcher::setDispatchEvent(bool flag) {
	m_dispatchEvents = flag;
}

bool wyEventDispatcher::getDispatchEvent() {
	return m_dispatchEvents;
}

void wyEventDispatcher::queueKeyEventLocked(wyEventType type, wyPlatformKeyEvent pe) {
	pthread_mutex_lock(&gMutex);

	// convert key event
	wyEvent* e = buildKeyEvent(type, pe);

	// push to pending list
	if(e) {
		m_pendingAddEvents.push_back(e);
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
	m_pendingAddEvents.push_back(e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(wyEventType type, wyObject* obj) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = type;
	e->oe.obj = obj;
	m_pendingAddEvents.push_back(e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueEventLocked(float accelX, float accelY, float accelZ) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = ET_ACCELEROMETER;
	e->ae.accelX = accelX;
	e->ae.accelY = accelY;
	e->ae.accelZ = accelZ;
	m_pendingAddEvents.push_back(e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::queueRunnableLocked(wyRunnable* runnable) {
	pthread_mutex_lock(&gMutex);

	wyEvent* e = popEvent();
	e->type = ET_RUNNABLE;
	e->r.runnable = runnable;
	wyObjectRetain(runnable);
	m_pendingAddEvents.push_back(e);

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addKeyHandler(PriorityHandler& h) {
	HandlerList::iterator iter = m_keyHandlers.begin();
	for(; iter != m_keyHandlers.end(); iter++) {
		if(iter->priority <= h.priority) {
			break;
		}
	}
	m_keyHandlers.insert(iter, h);
}

void wyEventDispatcher::addKeyHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

	if(findHandler(m_pendingAddKeyHandlers, node) == -1) {
    	PriorityHandler h;
    	h.priority = priority;
    	h.node = node;
    	m_pendingAddKeyHandlers.push_back(h);
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addAccelHandler(PriorityHandler& h) {
	HandlerList::iterator iter = m_accelHandlers.begin();
	for(; iter != m_accelHandlers.end(); iter++) {
		if(iter->priority <= h.priority) {
			break;
		}
	}
	m_accelHandlers.insert(iter, h);
}

void wyEventDispatcher::addAccelHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

	if(findHandler(m_pendingAddAccelHandlers, node) == -1) {
    	PriorityHandler h;
    	h.priority = priority;
    	h.node = node;
    	m_pendingAddAccelHandlers.push_back(h);

    	// check accelerometer listener
    	checkAccelHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addTouchHandler(PriorityHandler& h) {
	HandlerList::iterator iter = m_touchHandlers.begin();
	for(; iter != m_touchHandlers.end(); iter++) {
		if(iter->priority <= h.priority) {
			break;
		}
	}
	m_touchHandlers.insert(iter, h);
}

void wyEventDispatcher::addTouchHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

	if(findHandler(m_pendingAddTouchHandlers, node) == -1) {
    	PriorityHandler h;
    	h.priority = priority;
    	h.node = node;
    	m_pendingAddTouchHandlers.push_back(h);
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addDoubleTapHandler(PriorityHandler& h) {
	HandlerList::iterator iter = m_doubleTapHandlers.begin();
	for(; iter != m_doubleTapHandlers.end(); iter++) {
		if(iter->priority <= h.priority) {
			break;
		}
	}
	m_doubleTapHandlers.insert(iter, h);
}

void wyEventDispatcher::addDoubleTapHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

	if(findHandler(m_pendingAddDoubleTapHandlers, node) == -1) {
    	PriorityHandler h;
    	h.priority = priority;
    	h.node = node;
    	m_pendingAddDoubleTapHandlers.push_back(h);

    	checkDoubleTapHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::addGestureHandler(PriorityHandler& h) {
	HandlerList::iterator iter = m_gestureHandlers.begin();
	for(; iter != m_gestureHandlers.end(); iter++) {
		if(iter->priority <= h.priority) {
			break;
		}
	}
	m_gestureHandlers.insert(iter, h);
}

void wyEventDispatcher::addGestureHandlerLocked(wyNode* node, int priority) {
	pthread_mutex_lock(&gMutex);

	if(findHandler(m_pendingAddGestureHandlers, node) == -1) {
    	PriorityHandler h;
    	h.priority = priority;
    	h.node = node;
    	m_pendingAddGestureHandlers.push_back(h);

    	checkGestureHandlers();
    }

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeAllHandlersLocked() {
	pthread_mutex_lock(&gMutex);

	// clear all handlers
	m_accelHandlers.clear();
	m_keyHandlers.clear();
	m_touchHandlers.clear();
	m_doubleTapHandlers.clear();
	m_gestureHandlers.clear();
	m_pendingAddAccelHandlers.clear();
	m_pendingAddTouchHandlers.clear();
	m_pendingAddKeyHandlers.clear();
	m_pendingAddDoubleTapHandlers.clear();
	m_pendingAddGestureHandlers.clear();

	// check accelerometer listener
	checkAccelHandlers();

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeKeyHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = findHandler(m_pendingAddKeyHandlers, node);
	if(index != -1) {
		m_pendingAddKeyHandlers.erase(m_pendingAddKeyHandlers.begin() + index);
	} else {
		index = findNode(m_pendingRemoveKeyHandlerNodes, node);
		if(index == -1)
			m_pendingRemoveKeyHandlerNodes.push_back(node);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeAccelHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = findHandler(m_pendingAddAccelHandlers, node);
	if(index != -1) {
		m_pendingAddAccelHandlers.erase(m_pendingAddAccelHandlers.begin() + index);

		// check accelerometer listener
		checkAccelHandlers();
	} else {
		index = findNode(m_pendingRemoveAccelHandlerNodes, node);
		if(index == -1)
			m_pendingRemoveAccelHandlerNodes.push_back(node);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeTouchHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = findHandler(m_pendingAddTouchHandlers, node);
	if(index != -1) {
		m_pendingAddTouchHandlers.erase(m_pendingAddTouchHandlers.begin() + index);
	} else {
		index = findNode(m_pendingRemoveTouchHandlerNodes, node);
		if(index == -1)
			m_pendingRemoveTouchHandlerNodes.push_back(node);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeDoubleTapHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = findHandler(m_pendingAddDoubleTapHandlers, node);
	if(index != -1) {
		m_pendingAddDoubleTapHandlers.erase(m_pendingAddDoubleTapHandlers.begin() + index);

		// becuase pending add list changed, need re-check
		checkDoubleTapHandlers();
	} else {
		index = findNode(m_pendingRemoveDoubleTapHandlerNodes, node);
		if(index == -1)
			m_pendingRemoveDoubleTapHandlerNodes.push_back(node);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyEventDispatcher::removeGestureHandlerLocked(wyNode* node) {
	pthread_mutex_lock(&gMutex);

	int index = findHandler(m_pendingAddGestureHandlers, node);
	if(index != -1) {
		m_pendingAddGestureHandlers.erase(m_pendingAddGestureHandlers.begin() + index);

		// becuase pending add list changed, need re-check
		checkGestureHandlers();
	} else {
		index = findNode(m_pendingRemoveGestureHandlerNodes, node);
		if(index == -1)
			m_pendingRemoveGestureHandlerNodes.push_back(node);
	}

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
		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
			if(node->hasTouch() && parent->isAncestor(node)) {
				node->clearTouch();
				node->touchesCancelled(e);
			}
		}
	}
}

void wyEventDispatcher::cancelTouchExcept(wyMotionEvent& e, wyNode* excludeNode) {
	if(m_dispatchEvents) {
		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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
		for(HandlerList::iterator iter = m_accelHandlers.begin(); iter != m_accelHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_keyHandlers.begin(); iter != m_keyHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_keyHandlers.begin(); iter != m_keyHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_keyHandlers.begin(); iter != m_keyHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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
		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;

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
		for(HandlerList::iterator iter = m_touchHandlers.begin(); iter != m_touchHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_doubleTapHandlers.begin(); iter != m_doubleTapHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_doubleTapHandlers.begin(); iter != m_doubleTapHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_doubleTapHandlers.begin(); iter != m_doubleTapHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
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

		for(HandlerList::iterator iter = m_gestureHandlers.begin(); iter != m_gestureHandlers.end(); iter++) {
			PriorityHandler& h = *iter;
			wyNode* node = h.node;
			bool zeroSize = node->getWidth() == 0 || node->getHeight() == 0;
			if(node->isRunning() && node->isVisibleFromRoot() && node->isEnabledFromRoot() && (zeroSize || node->hitTest(me.x[0], me.y[0]))) {
				if(dispatchOnSingleTapUp(node, event, me))
					return true;
			}
		}
	}
	return false;
}
