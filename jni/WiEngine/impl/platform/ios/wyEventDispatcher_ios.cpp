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
#if IOS

#include "wyEventDispatcher_ios.h"
#import "WYUIEvent.h"
#import "WYUITouch.h"

// shared instance
wyEventDispatcher_ios* gEventDispatcher;

// extern global
extern wyDirector* gDirector;

/*
 * the motion event in iOS will carry all touches but it may not be sorted
 * by time occurs. So we need track touch object to emulate android getPointerId method
 */
static int sUITouches[5] = { 0, 0, 0, 0, 0 };

wyEventDispatcher* wyEventDispatcher::getInstance() {
	if(gEventDispatcher == NULL) {
		gEventDispatcher = WYNEW wyEventDispatcher_ios();
	}
	return gEventDispatcher;
}

wyEventDispatcher* wyEventDispatcher::getInstanceNoCreate() {
	return gEventDispatcher;
}

void wyEventDispatcher::recycleEvent(wyEvent* e) {
	// unindex touches
	switch(e->type) {
		case ET_TOUCH_ENDED:
		case ET_TOUCH_CANCELLED:
		case ET_TOUCH_POINTER_END:
			NSArray* touches = [e->me.pe allTouches];
			for(WYUITouch* touch in touches) {
				if(touch.phase == UITouchPhaseEnded || touch.phase == UITouchPhaseCancelled)
					gEventDispatcher->unindexUITouch(touch.hash);
			}
			break;
	}

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
				[WYUIEvent poolEvent:e->me.pe];
				[e->me.pe release];
				e->me.pe = NULL;
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
		case ET_ON_DOWN:
		case ET_ON_FLING:
		case ET_ON_SCROLL:
		case ET_ON_SINGLE_TAP_UP:
		case ET_ON_LONG_PRESS:
		case ET_ON_SHOW_PRESS:
			if(e->ge.pe1 != NULL) {
				[WYUIEvent poolEvent:e->ge.pe1];
				[e->ge.pe1 release];
				e->ge.pe1 = NULL;
			}
			if(e->ge.pe2 != NULL) {
				[WYUIEvent poolEvent:e->ge.pe2];
				[e->ge.pe2 release];
				e->ge.pe2 = NULL;
			}
			break;
		case ET_RUNNABLE:
			wyObjectRelease(e->r.runnable);
			e->r.runnable = NULL;
			break;
	}
}

wyEventDispatcher_ios::wyEventDispatcher_ios() {
}

wyEventDispatcher_ios::~wyEventDispatcher_ios() {
	gEventDispatcher = NULL;
}

void wyEventDispatcher_ios::indexUITouch(int pointer) {
	for(int i = 0; i < 5; i++) {
		if(sUITouches[i] == 0) {
			sUITouches[i] = pointer;
			break;
		} else if(sUITouches[i] == pointer) {
			break;
		}
	}
}

void wyEventDispatcher_ios::unindexUITouch(int pointer) {
	for(int i = 0; i < 5; i++) {
		if(sUITouches[i] == pointer) {
			sUITouches[i] = NULL;
			break;
		}
	}
}

int wyEventDispatcher_ios::indexOfUITouch(int pointer) {
	for(int i = 0; i < 5; i++) {
		if(sUITouches[i] == pointer) {
			return i;
		}
	}
	return -1;
}

void wyEventDispatcher_ios::checkAccelHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	[glView setDetectAcceleration:(m_accelHandlers->num + m_pendingAccelHandlers->num > 0)];
}

void wyEventDispatcher_ios::checkDoubleTapHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	[glView setDetectGesture:(m_doubleTapHandlers->num + m_gestureHandlers->num + m_pendingDoubleTapHandlers->num + m_pendingGestureHandlers->num) > 0];
}

void wyEventDispatcher_ios::checkGestureHandlers() {
	wyGLSurfaceView glView = gDirector->getGLView();
	[glView setDetectGesture:(m_doubleTapHandlers->num + m_gestureHandlers->num + m_pendingDoubleTapHandlers->num + m_pendingGestureHandlers->num) > 0];
}

wyEvent* wyEventDispatcher_ios::buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe) {
	// get pooled event
	wyEvent* e = popEvent();
	e->type = type;
	e->ke.pe = pe;
	return e;
}

void wyEventDispatcher_ios::simulateKeyDown(wyKeyCode keyCode) {
	wyKeyEvent* ke = (wyKeyEvent*)wyCalloc(1, sizeof(wyKeyEvent));
	ke->keyCode = keyCode;
	ke->repeatCount = 1;
	ke->eventTime = wyUtils::currentTimeMillis();
	ke->downTime = ke->eventTime;
	queueKeyEventLocked(ET_KEY_DOWN, ke);
}

void wyEventDispatcher_ios::simulateKeyUp(wyKeyCode keyCode) {
	wyKeyEvent* ke = (wyKeyEvent*)wyCalloc(1, sizeof(wyKeyEvent));
	ke->keyCode = keyCode;
	ke->repeatCount = 1;
	ke->eventTime = wyUtils::currentTimeMillis();
	ke->downTime = ke->eventTime;
	queueKeyEventLocked(ET_KEY_UP, ke);
}

void wyEventDispatcher_ios::simulateKeyMultiple(wyKeyCode keyCode, int repeatCount) {
	wyKeyEvent* ke = (wyKeyEvent*)wyCalloc(1, sizeof(wyKeyEvent));
	ke->keyCode = keyCode;
	ke->repeatCount = repeatCount;
	ke->eventTime = wyUtils::currentTimeMillis();
	ke->downTime = ke->eventTime;
	queueKeyEventLocked(ET_KEY_MULTIPLE, ke);
}

void wyEventDispatcher_ios::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe) {
	// need transform event type if multi touch
	switch(type) {
		case ET_TOUCH_BEGAN:
		{
			/*
			 * iOS的touch began可能存在多个处于began阶段的touch, 因此需要检查began个数,
			 * 进行分拆, 不然可能会出现没有touch began而直接产生touch pointer began的bug
			 */

			// if only 1, no extra logic
			// if more than 1, must split events
			int count = [pe beganTouchCount];
			if(count <= 1) {
				// index touches
				for(WYUITouch* touch in [pe allTouches]) {
					if(touch.phase == UITouchPhaseBegan)
						indexUITouch(touch.hash);
				}

				// pop event
				wyEvent* e = popEvent();
				e->type = type;

				// if count is more than 1, need simulate pointer began event
				int count = [pe touchCount];
				if(count > 1)
					e->type = ET_TOUCH_POINTER_BEGAN;

				// to queue
				e->me.pe = pe;
				[e->me.pe retain];
				wyArrayPush(m_pendingAddList, e);
			} else {
				// collect began touches
				NSMutableArray* beganTouches = [NSMutableArray array];
				for(WYUITouch* touch in [pe allTouches]) {
					if(touch.phase == UITouchPhaseBegan)
						[beganTouches addObject:touch];
				}

				// index began touches and remove them from original event
				for(WYUITouch* touch in beganTouches) {
					indexUITouch(touch.hash);
					[pe removeTouch:touch];
				}

				// create event array
				NSMutableArray* events = [NSMutableArray array];

				// build serial events
				int count = [beganTouches count];
				for(int i = 0; i < count; i++) {
					// get event copy
					WYUIEvent* e = [WYUIEvent popCopy:pe];

					// make stationary touch
					for(int j = 0; j < i; j++) {
						WYUITouch* t = [WYUIEvent popTouchCopy:[beganTouches objectAtIndex:j]];
						t.phase = UITouchPhaseStationary;
						[e addTouch:t];
					}

					// add began touch
					[e addTouch:[WYUIEvent popTouchCopy:[beganTouches objectAtIndex:i]]];

					// add event to buffer
					[events addObject:e];
				}

				// now add all event to queue
				for(WYUIEvent* wyuie in events) {
					wyEvent* e = popEvent();
					e->type = type;
					if([wyuie touchCount] > 1)
						e->type = ET_TOUCH_POINTER_BEGAN;
					e->me.pe = wyuie;
					[e->me.pe retain];
					wyArrayPush(m_pendingAddList, e);
				}

				// recycle event and touch
				[WYUIEvent poolEvent:pe];
				for(WYUITouch* touch in beganTouches) {
					[WYUIEvent poolTouch:touch];
				}
				[beganTouches removeAllObjects];
			}

			break;
		}
		case ET_TOUCH_ENDED:
		case ET_TOUCH_CANCELLED:
		{
			// if only 1, no extra logic
			// if more than 1, must split events
			int count = [pe endedTouchCount];
			if(count <= 1) {
				// pop event
				wyEvent* e = popEvent();
				e->type = type;

				// if count is more than 1, need simulate pointer ended event
				int count = [pe touchCount];
				if(count > 1)
					e->type = ET_TOUCH_POINTER_END;

				// to queue
				e->me.pe = pe;
				[e->me.pe retain];
				wyArrayPush(m_pendingAddList, e);
			} else {
				// collect end touches
				NSMutableArray* endTouches = [NSMutableArray array];
				for(WYUITouch* touch in [pe allTouches]) {
					if(touch.phase == UITouchPhaseEnded)
						[endTouches addObject:touch];
				}

				// remove end touches from original event
				for(WYUITouch* touch in endTouches)
					[pe removeTouch:touch];

				// create event array
				NSMutableArray* events = [NSMutableArray array];

				// split event
				int count = [endTouches count];
				for(int i = count - 1; i >= 0; i--) {
					// get event copy
					WYUIEvent* e = [WYUIEvent popCopy:pe];

					// add stationary event
					for(int j = 0; j < i; j++) {
						WYUITouch* t = [WYUIEvent popTouchCopy:[endTouches objectAtIndex:j]];
						t.phase = UITouchPhaseStationary;
						[e addTouch:t];
					}

					// add end touch
					[e addTouch:[WYUIEvent popTouchCopy:[endTouches objectAtIndex:i]]];

					// add event to buffer
					[events addObject:e];
				}

				// now add all event to queue
				for(WYUIEvent* wyuie in events) {
					wyEvent* e = popEvent();
					e->type = type;
					if([wyuie touchCount] > 1)
						e->type = ET_TOUCH_POINTER_END;
					e->me.pe = wyuie;
					[e->me.pe retain];
					wyArrayPush(m_pendingAddList, e);
				}

				// recycle event and touch
				[WYUIEvent poolEvent:pe];
				for(WYUITouch* touch in endTouches) {
					[WYUIEvent poolTouch:touch];
				}
				[endTouches removeAllObjects];
			}

			break;
		}
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
			wyArrayPush(m_pendingAddList, e);
			break;
		}
		default:
		{
			wyEvent* e = popEvent();
			e->type = type;
			e->me.pe = pe;
			[e->me.pe retain];
			wyArrayPush(m_pendingAddList, e);
			break;
		}
	}

	// iOS can process the event immediately because thread is same
	processEventsLocked();
}

void wyEventDispatcher_ios::queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) {
	wyEvent* e = popEvent();
	e->type = type;
	e->ge.vx = vx;
	e->ge.vy = vy;
	e->ge.pe1 = pe1;
	e->ge.pe2 = pe2;
	[e->ge.pe1 retain];
	[e->ge.pe2 retain];

	wyArrayPush(m_pendingAddList, e);
}

#endif // #if IOS
