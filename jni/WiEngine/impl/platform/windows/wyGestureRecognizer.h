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

#ifndef __wyGestureRecognizer_h__
#define __wyGestureRecognizer_h__

#include "wyObject.h"
#include "wyGestureRecognizerListener.h"
#include <Windows.h>
#include "wyEvents.h"
#include "wyTypes.h"

/**
 * @class wyGestureRecognizer
 *
 * Gesture recognizer implementation for windows
 */
class wyGestureRecognizer : public wyObject {
public:
	/// state of gesture recognizing
	enum State {
		/// a gesture event recognizing process is started
		BEGAN,

		/// a gesture event is recognized, but it may change later
		CHANGED,

		/// a gesture event is recognized, and no more gesture event for this session
		ENDED,

		/// gesture is not detected
		FAILED
	};

	/// sub state of gesture recognizing
	enum SubState {
		/// none state
		NONE,
	
		/// first touch point is down
		DOWN,
	
		/// it means long press may coming
		SHOW_PRESS,
	
		/// after show press, but before long press
		SINGLE_TAP_UP,
	
		/// before show press event. If it happens, then show press won't come out
		SINGLE_TAP_CONFIRM,
	
		/// double tap
		DOUBLE_TAP,
	
		/// double tap event
		DOUBLE_TAP_EVENT,
	
		/// long press
		LONG_PRESS,
	
		/// repeat long press
		LONG_PRESS_REPEAT,
	
		/// in scrolling
		SCROLL,
	
		/// fling 
		FLING
	};

private:
	/// listener of gesture event
	wyGestureRecognizerListener* m_listener;

	/// state
	State m_state;

	/// sub state
	SubState m_subState;

	/// window handle
	HWND m_hWnd;

	/// first event
	wyMotionEvent m_firstEvent;

	/// event
	wyMotionEvent m_event;

	/// max allowed movement before long press can be determinated
	float m_allowableMovement;
	
	/// x position of last mouse event
	float m_lastX;
	
	/// y position of last mouse event
	float m_lastY;
	
	/// x delta for scroll or x velocity for fling
	float m_dx;
	
	/// y delta for scroll or y velocity for fling
	float m_dy;
	
	/// true means current event is in a double click phase
	bool m_inDoubleTap;
	
	/// timestamp of last event
	int64_t m_lastTimestamp;
	
	/// fling velocity of last move event
	wyPoint m_lastFlingVelocity;

private:
	/// timer procedure for long press
	static VOID CALLBACK onLongPress(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	/// timer procedure for show press
	static VOID CALLBACK onShowPress(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	/// timer procedure for single tap
	static VOID CALLBACK onSingleTap(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	/// failed to recognize a gesture
	void fail();

	/// dismiss all timers
	void endAllTimers();

	/// recognizing state is changed
	void changeState(State state);

protected:
	wyGestureRecognizer();

public:
	virtual ~wyGestureRecognizer();
	static wyGestureRecognizer* getInstance();
	static wyGestureRecognizer* getInstanceNoCreate();

	/// get state
	State getState() { return m_state; }

	/// get sub state
	SubState getSubState() { return m_subState; }

	/// set gesture event listener
	void setListener(wyGestureRecognizerListener* l) { m_listener = l; }

	/// set window handle
	void setWindowHandle(HWND h) { m_hWnd = h; }

	/// get window handle
	HWND getWindowHandle() { return m_hWnd; }

	/// get first event reference
	wyMotionEvent& getFirstEvent() { return m_firstEvent; }

	/// get event reference
	wyMotionEvent& getEvent() { return m_event; }

	/// get delta x offset or speed
	float getDx() { return m_dx; }

	/// get delta y offset or speed
	float getDy() { return m_dy; }

	/// reset state of recognizer
	void reset();

	/// call this to pass mouse down event to recognizer
	void mouseDown(wyMotionEvent* e);

	/// call this to pass mouse move event to recognizer
	void mouseDragged(wyMotionEvent* e);

	/// call this to pass mouse up event to recognizer
	void mouseUp(wyMotionEvent* e);
};

#endif // __wyGestureRecognizer_h__

#endif // #ifdef WINDOWS
