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

#include "wyWinGLView.h"
#include "wyDirector.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyEventDispatcher.h"
#include "wyGestureRecognizer.h"

// dump event debug flag
//#define DUMP_EVENT

// global staff
extern wyDirector* gDirector;
extern wyEventDispatcher* gEventDispatcher;

// state of windows
enum State {
	INIT,
	RUNNING,
	STOP
};

// data of window
typedef struct Record {
	// machine state
	State state;
} Record;

// window data
static Record s_record = {
	INIT
};

wyWinGLView::wyWinGLView() :
		m_pressed(false),
		m_detectGesture(false),
		m_stopRender(false),
		m_hAccelTable(NULL),
		m_hWnd(NULL) {
	// create director andd attach it
	wyDirector* director = wyDirector::getInstance();
	director->attachContext(this);
	director->attachInView(this);

	// Set the timer granularity to 1 ms
    timeBeginPeriod(1);

	// clear help event member
	memset(&m_event, 0, sizeof(wyMotionEvent));

	// set self as gesture event listener
	wyGestureRecognizer::getInstance()->setListener(this);
}

wyWinGLView::~wyWinGLView() {
	// free gesture recognizer
	wyGestureRecognizer* gr = wyGestureRecognizer::getInstanceNoCreate();
	if(gr)
		gr->release();
}

wyWinGLView* wyWinGLView::make() {
	wyWinGLView* v = WYNEW wyWinGLView();
	return (wyWinGLView*)v->autoRelease();
}

LRESULT CALLBACK wyWinGLView::glViewWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	// if window is null and message is not create, fallback to default proc
    if(hWnd == NULL && uMsg != WM_CREATE)
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

	// process message
	LRESULT lRet = 1;
	int64_t keyDownTime = 0;
	PAINTSTRUCT ps;
	switch(uMsg) {
		case WM_DESTROY: 
			PostQuitMessage(0); 
			break; 
		case WM_SIZE:
			wyDirector::getInstance()->onSurfaceChanged(LOWORD(lParam), HIWORD(lParam));
			break;
		case WM_CLOSE:
			s_record.state = STOP;
			DestroyWindow(hWnd);
			break;
		case WM_PAINT:
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		case WM_KEYDOWN: 
		{
			// convert to key event
			keyDownTime = wyUtils::currentTimeMillis();
			wyKeyEvent e;
			e.downTime = keyDownTime;
			e.eventTime = keyDownTime;
			*((int*)(&e.keyCode)) = wParam;
			e.modifierFlags = 0;
			e.repeatCount = LOWORD(lParam);

			// push key down event
			wyEventDispatcher::getInstance()->queueKeyEventLocked(ET_KEY_DOWN, &e); 
			break;
		}
		case WM_KEYUP:
		{
			// convert to key event
			wyKeyEvent e;
			e.downTime = keyDownTime;
			e.eventTime = wyUtils::currentTimeMillis();
			*((int*)(&e.keyCode)) = wParam;
			e.modifierFlags = 0;
			e.repeatCount = LOWORD(lParam);

			// push key up event
			wyEventDispatcher::getInstance()->queueKeyEventLocked(ET_KEY_UP, &e); 
			break;
		}
		case WM_LBUTTONDBLCLK: 
		{
			// get GLView 
			wyGLSurfaceView glView = gDirector->getGLView();
			wyMotionEvent& e = glView->m_event;
			bool& pressed = glView->m_pressed;

			if(!pressed) {
				pressed = true;

				// convert to motion event
				e.eventTime = wyUtils::currentTimeMillis();
				e.x[0] = LOWORD(lParam);
				e.y[0] = wyDevice::realHeight - HIWORD(lParam);
				e.tap[0] = 2;

				// for gesture
				if(gDirector->getGLView()->isDetectGesture())
					wyGestureRecognizer::getInstance()->mouseDown(&e); 

				// push touch began event
				wyEventDispatcher::getInstance()->queueEventLocked(ET_TOUCH_BEGAN, &e); 
			}

			break;
		}
		case WM_LBUTTONDOWN:
		{
			// get GLView 
			wyGLSurfaceView glView = gDirector->getGLView();
			wyMotionEvent& e = glView->m_event;
			bool& pressed = glView->m_pressed;

			if(!pressed) {
				pressed = true;

				// convert to motion event
				e.pointerCount = 1;
				e.eventTime = wyUtils::currentTimeMillis();
				e.pid[0] = 0;
				e.x[0] = LOWORD(lParam);
				e.y[0] = wyDevice::realHeight - HIWORD(lParam);
				e.tap[0] = 1;

				// for gesture
				if(glView->isDetectGesture())
					wyGestureRecognizer::getInstance()->mouseDown(&e);

				// push touch began event
				wyEventDispatcher::getInstance()->queueEventLocked(ET_TOUCH_BEGAN, &e); 
			}
			break;
		}
		case WM_MOUSEMOVE:
		{
			// get GLView 
			wyGLSurfaceView glView = gDirector->getGLView();
			wyMotionEvent& e = glView->m_event;
			bool& pressed = glView->m_pressed;

			if(pressed) {
				// convert to motion event
				e.eventTime = wyUtils::currentTimeMillis();
				e.x[0] = LOWORD(lParam);
				e.y[0] = wyDevice::realHeight - HIWORD(lParam);

				// for gesture
				if(gDirector->getGLView()->isDetectGesture())
					wyGestureRecognizer::getInstance()->mouseDragged(&e);

				// push touch move event
				wyEventDispatcher::getInstance()->queueEventLocked(ET_TOUCH_MOVED, &e); 
			}

			break;
		}
		case WM_LBUTTONUP:
		{
			// get GLView 
			wyGLSurfaceView glView = gDirector->getGLView();
			wyMotionEvent& e = glView->m_event;
			bool& pressed = glView->m_pressed;

			if(pressed) {
				pressed = false;

				// convert to motion event
				e.eventTime = wyUtils::currentTimeMillis();
				e.x[0] = LOWORD(lParam);
				e.y[0] = wyDevice::realHeight - HIWORD(lParam);

				// for gesture
				if(gDirector->getGLView()->isDetectGesture())
					wyGestureRecognizer::getInstance()->mouseUp(&e);

				// push touch end event
				wyEventDispatcher::getInstance()->queueEventLocked(ET_TOUCH_ENDED, &e); 
			}

			break;
		}
		case WM_ACTIVATE:
			// when somebody show a dialog in touch began, we must clear press flag
			// wParam == 0 means deactivated
			if(wParam == 0) {
				wyGLSurfaceView glView = gDirector->getGLView();
				bool& pressed = glView->m_pressed;
				pressed = false;
			}
			break;
		default:
			lRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
	}

	return lRet;
}

int wyWinGLView::run() {
	// set to gesture recognizer
	wyGestureRecognizer::getInstance()->setWindowHandle(m_hWnd);

	// control frame rate, get start time
	// we control frame rate at 60 fps
	LARGE_INTEGER frequency;
	LARGE_INTEGER last;
    LARGE_INTEGER now;
	LARGE_INTEGER _60fps;
	double interval = 1.0 / 60.0;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&last);
	_60fps.QuadPart = (LONGLONG)(frequency.QuadPart * interval);

	// message loop
	s_record.state = RUNNING;
	MSG stMsg;
	while(s_record.state == RUNNING) {
		while(1) {
			if(!PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
				QueryPerformanceCounter(&now);
				if(now.QuadPart - last.QuadPart >= _60fps.QuadPart) {
					last.QuadPart = now.QuadPart;
					if(!m_stopRender)
						doDrawFrame();
				} else {
					Sleep(0);
					continue;
				}
			} else {
				if(WM_QUIT == stMsg.message) {
					break;
				} else if(!m_hAccelTable || !TranslateAccelerator(stMsg.hwnd, m_hAccelTable, &stMsg)) {
					TranslateMessage(&stMsg);
					DispatchMessage(&stMsg);
				}
			}
		}
	}

	// destroy EGL
	deinitEgl();

	// let director end
	if(gDirector)
		gDirector->release();

	return (int)stMsg.wParam;
}

void wyWinGLView::prepare() {
	// create egl display
	EGLBoolean eRet = 0;
	EGLint nMajor, nMinor;
	m_eglDisplay = eglGetDisplay(GetDC(m_hWnd));
	eRet = eglInitialize(m_eglDisplay, &nMajor, &nMinor);

	// check init  result
	if(eRet == EGL_FALSE) {
		LOGE("wyWinGLView::initEgl: failed to init EGL");
		return;
	}

	// choose config, rgba 8888 with depth
	const EGLint aConfigAttribs[] = {
		EGL_LEVEL,				0,
		EGL_SURFACE_TYPE,		EGL_WINDOW_BIT,
		EGL_RENDERABLE_TYPE,	EGL_OPENGL_ES2_BIT,
		EGL_NATIVE_RENDERABLE,	EGL_FALSE,
		EGL_DEPTH_SIZE,			16,
		EGL_NONE,
	};
	EGLint iConfigs;
	EGLConfig eglConfig;
	eRet = eglChooseConfig(m_eglDisplay, aConfigAttribs, &eglConfig, 1, &iConfigs);
	if(eRet == EGL_FALSE) {
		LOGE("wyWinGLView::initEgl: failed to config EGL");
		return;
	}

	// create context
	EGLContext eglContext;
	eglContext = eglCreateContext(m_eglDisplay, eglConfig, NULL, NULL);

	// create surface
	m_eglSurface = eglCreateWindowSurface(m_eglDisplay, eglConfig, m_hWnd, NULL);

	// enable surface
	eglMakeCurrent(m_eglDisplay, m_eglSurface, m_eglSurface, eglContext);

	// init deirector
	gDirector->onSurfaceCreated();
	gDirector->onSurfaceChanged(wyDevice::realWidth, wyDevice::realHeight);
}

void wyWinGLView::deinitEgl() {
	eglMakeCurrent(m_eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	eglTerminate(m_eglDisplay);
	eglReleaseThread();

	gDirector->onSurfaceDestroyed();
}

void wyWinGLView::doDrawFrame() {
	if(gDirector) {
		gDirector->drawFrame();
		eglSwapBuffers(m_eglDisplay, m_eglSurface);
	}
}

void wyWinGLView::onWYGesture(wyGestureRecognizer* gr) {
	switch(gr->getState()) {
		case wyGestureRecognizer::BEGAN:
		case wyGestureRecognizer::CHANGED:
		case wyGestureRecognizer::ENDED:
#ifdef DUMP_EVENT
			switch(gr->getSubState()) {
				case wyGestureRecognizer::DOUBLE_TAP:
					LOGD("WYGestureRecognizerSubStateDoubleTap");
					break;
				case wyGestureRecognizer::DOUBLE_TAP_EVENT:
					LOGD("WYGestureRecognizerSubStateDoubleTapEvent");
					break;
				case wyGestureRecognizer::DOWN:
					LOGD("WYGestureRecognizerSubStateDown");
					break;
				case wyGestureRecognizer::FLING:
					LOGD("WYGestureRecognizerSubStateFling");
					break;
				case wyGestureRecognizer::LONG_PRESS:
					LOGD("WYGestureRecognizerSubStateLongPress");
					break;
				case wyGestureRecognizer::LONG_PRESS_REPEAT:
					LOGD("WYGestureRecognizerSubStateLongPressRepeat");
					break;
				case wyGestureRecognizer::NONE:
					LOGD("WYGestureRecognizerSubStateLongPress");
					break;
				case wyGestureRecognizer::SCROLL:
					LOGD("WYGestureRecognizerSubStateScroll");
					break;
				case wyGestureRecognizer::SHOW_PRESS:
					LOGD("WYGestureRecognizerSubStateShowPress");
					break;
				case wyGestureRecognizer::SINGLE_TAP_CONFIRM:
					LOGD("WYGestureRecognizerSubStateSingleTapConfirm");
					break;
				case wyGestureRecognizer::SINGLE_TAP_UP:
					LOGD("WYGestureRecognizerSubStateSingleTapUp");
					break;
			}
#endif
			
			switch(gr->getSubState()) {
				case wyGestureRecognizer::DOWN:
					gEventDispatcher->queueEventLocked(ET_ON_DOWN, &gr->getEvent());
					break;
				case wyGestureRecognizer::SHOW_PRESS:
					gEventDispatcher->queueEventLocked(ET_ON_SHOW_PRESS, &gr->getEvent());
					break;
				case wyGestureRecognizer::SINGLE_TAP_UP:
					gEventDispatcher->queueEventLocked(ET_ON_SINGLE_TAP_UP, &gr->getEvent());
					break;
				case wyGestureRecognizer::SINGLE_TAP_CONFIRM:
					gEventDispatcher->queueEventLocked(ET_SINGLE_TAP_CONFIRMED, &gr->getEvent());
					break;
				case wyGestureRecognizer::DOUBLE_TAP:
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP, &gr->getEvent());
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, &gr->getEvent());
					break;
				case wyGestureRecognizer::DOUBLE_TAP_EVENT:
					gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, &gr->getEvent());
					break;
				case wyGestureRecognizer::LONG_PRESS:
					gEventDispatcher->queueEventLocked(ET_ON_LONG_PRESS, &gr->getEvent());
					break;
				case wyGestureRecognizer::SCROLL:
					gEventDispatcher->queueEventLocked(ET_ON_SCROLL, &gr->getFirstEvent(), &gr->getEvent(), gr->getDx(), gr->getDy());
					break;
				case wyGestureRecognizer::FLING:
					gEventDispatcher->queueEventLocked(ET_ON_FLING, &gr->getFirstEvent(), &gr->getEvent(), gr->getDx(), gr->getDy());
					break;
			}
			
			break;
	}
	
	// reset detector if ended
	if(gr->getState() == wyGestureRecognizer::ENDED)
		gr->reset();
}

#endif // #if WINDOWS
