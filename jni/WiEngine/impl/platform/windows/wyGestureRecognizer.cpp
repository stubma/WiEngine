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
#ifdef WINDOWS

#include "wyGestureRecognizer.h"
#include "wyLog.h"

// timers
#define TIMER_LONG_PRESS 1000
#define TIMER_SHOW_PRESS 1001
#define TIMER_SINGLE_TAP 1002

static wyGestureRecognizer* s_instance = NULL;

VOID CALLBACK wyGestureRecognizer::onLongPress(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	// stop timer
	wyGestureRecognizer* gr = wyGestureRecognizer::getInstanceNoCreate();
	if(gr)
		KillTimer(gr->getWindowHandle(), TIMER_LONG_PRESS);

	// change state
	gr->m_subState = wyGestureRecognizer::LONG_PRESS;
	gr->changeState(wyGestureRecognizer::CHANGED);
}

VOID CALLBACK wyGestureRecognizer::onShowPress(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	// stop timer
	wyGestureRecognizer* gr = wyGestureRecognizer::getInstanceNoCreate();
	if(gr)
		KillTimer(gr->getWindowHandle(), TIMER_SHOW_PRESS);

	// change state
	gr->m_subState = wyGestureRecognizer::SHOW_PRESS;
	gr->changeState(wyGestureRecognizer::CHANGED);
}

VOID CALLBACK wyGestureRecognizer::onSingleTap(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	// stop timer
	wyGestureRecognizer* gr = wyGestureRecognizer::getInstanceNoCreate();
	if(gr)
		KillTimer(gr->getWindowHandle(), TIMER_SINGLE_TAP);

	// change state
	gr->m_subState = wyGestureRecognizer::SINGLE_TAP_CONFIRM;
	gr->changeState(wyGestureRecognizer::ENDED);
}

wyGestureRecognizer::wyGestureRecognizer() :
		m_allowableMovement(10) {
}

wyGestureRecognizer::~wyGestureRecognizer() {
	endAllTimers();
	s_instance = NULL;
}

wyGestureRecognizer* wyGestureRecognizer::getInstance() {
	if(!s_instance) {
		s_instance = WYNEW wyGestureRecognizer();
	}
	return s_instance;
}

wyGestureRecognizer* wyGestureRecognizer::getInstanceNoCreate() {
	return s_instance;
}

void wyGestureRecognizer::reset() {
	endAllTimers();
	m_subState = NONE;
	m_state = FAILED;
	m_inDoubleTap = false;
}

void wyGestureRecognizer::mouseDown(wyMotionEvent* e) {
	switch(e->tap[0]) {
		case 1:
			// set as first event
			memcpy(&m_firstEvent, e, sizeof(wyMotionEvent));
			
			// set as current event
			memcpy(&m_event, e, sizeof(wyMotionEvent));
			
			// schedule timer to detect show press and long press
			SetTimer(m_hWnd, TIMER_SHOW_PRESS, 100, onShowPress);
			SetTimer(m_hWnd, TIMER_LONG_PRESS, 500, onLongPress);
			
			// set state
			m_subState = DOWN;
			changeState(BEGAN);
			break;
		case 2:
			switch(m_state) {
				case CHANGED:
					switch(m_subState) {
						case SINGLE_TAP_UP:
							endAllTimers();
							
							// set as first event
							memcpy(&m_firstEvent, e, sizeof(wyMotionEvent));
							
							// set as current event
							memcpy(&m_event, e, sizeof(wyMotionEvent));
							
							// for long press
							SetTimer(m_hWnd, TIMER_LONG_PRESS, 500, onLongPress);
							
							// this is a double tap event
							m_inDoubleTap = true;
							m_subState = DOUBLE_TAP;
							changeState(CHANGED);
							break;
						default:
							fail();
							break;
					}
					break;
				default:
					fail();
					break;
			}
			break;
		default:
			fail();
			break;
	}
}

void wyGestureRecognizer::mouseDragged(wyMotionEvent* e) {
	switch(m_state) {
		case BEGAN:
		case CHANGED:
			switch(m_subState) {
				case LONG_PRESS:
				case LONG_PRESS_REPEAT:
					m_subState = LONG_PRESS_REPEAT;
					break;
				case SCROLL:
				{
					// set as current event
					memcpy(&m_event, e, sizeof(wyMotionEvent));
					
					// calculate distance, cocoa coordinates is same as opengl
					m_dx = m_lastX - e->x[0];
					m_dy = e->y[0] - m_lastY;
					m_lastX = e->x[0];
					m_lastY = e->y[0];
					
					// compute fling velocity
					float delta = (float)(e->eventTime - m_lastTimestamp) / 1000.0f;
					m_lastTimestamp = e->eventTime;
					m_lastFlingVelocity.x = -m_dx / delta;
					m_lastFlingVelocity.y = -m_dy / delta;
					
					// trigger a scroll event
					m_subState = SCROLL;
					changeState(CHANGED);
					break;
				}
				default:
				{ 
					if(e->tap[0] == 1) {
						// set as current event
						memcpy(&m_event, e, sizeof(wyMotionEvent));
						
						// check distance
						wyPoint loc = wyp(m_event.x[0], m_event.y[0]);
						wyPoint firstLoc = wyp(m_firstEvent.x[0], m_firstEvent.y[0]);
						float distance = wyMath::sqrt(powf(loc.x - firstLoc.x, 2) + powf(loc.y - firstLoc.y, 2));
						if(distance > m_allowableMovement) {
							// ensure timer is ended
							endAllTimers();
							
							// calculate distance, cocoa coordinates is same as opengl
							m_dx = firstLoc.x - loc.x;
							m_dy = loc.y - firstLoc.y;
							m_lastX = loc.x;
							m_lastY = loc.y;
							
							// save timestamp
							m_lastTimestamp = e->eventTime;
							
							// trigger a scroll event
							m_subState = SCROLL;
							changeState(CHANGED);
						}						
					}

					break;
				}
			}
			break;
	}
}

void wyGestureRecognizer::mouseUp(wyMotionEvent* e) {
	endAllTimers();
	
	switch(m_state) {
		case BEGAN:
		case CHANGED:
		{
			// set as current event
			memcpy(&m_event, e, sizeof(wyMotionEvent));
			
			switch(m_subState) {
				case DOWN:
					SetTimer(m_hWnd, TIMER_SINGLE_TAP, 200, onSingleTap);
					
					m_subState = SINGLE_TAP_UP;
					changeState(CHANGED);
					break;
				case SHOW_PRESS:
					m_subState = SINGLE_TAP_UP;
					changeState(ENDED);
					break;
				case SCROLL:
				{
					// set as current event
					memcpy(&m_event, e, sizeof(wyMotionEvent));
					
					/*
					 * ʹ�����һ��move�¼��е������ٶ�, ��Ϊ������end�¼������������ٶȲ��ȶ�, ��Ҫ����Ϊʱ��
					 * �䶯����0.016��, ������end�¼���, �ƶ��ľ�����ܺ�С.
					 */
					m_dx = m_lastFlingVelocity.x;
					m_dy = m_lastFlingVelocity.y;
					
					// trigger fling
					m_subState = FLING;
					changeState(ENDED);
					break;
				}
				default:
					if(m_inDoubleTap) {
						m_subState = DOUBLE_TAP_EVENT;
						changeState(ENDED);
					} else {
						m_subState = NONE;
						changeState(ENDED);
					}
					break;
			}
			
			break;
		}
		default:
			fail();
			break;
	}
}

void wyGestureRecognizer::fail() {
	endAllTimers();
	reset();
}

void wyGestureRecognizer::endAllTimers() {
	KillTimer(m_hWnd, TIMER_LONG_PRESS);
	KillTimer(m_hWnd, TIMER_SHOW_PRESS);
	KillTimer(m_hWnd, TIMER_SINGLE_TAP);
}

void wyGestureRecognizer::changeState(State state) {
	m_state = state;
	switch(m_state) {
		case BEGAN:
		case CHANGED:
		case ENDED:
			if(m_listener)
				m_listener->onWYGesture(this);
			break;
	}
}

#endif // #ifdef WINDOWS
