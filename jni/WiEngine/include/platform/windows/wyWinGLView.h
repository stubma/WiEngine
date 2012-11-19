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

#ifndef __wyWinGLView_h__
#define __wyWinGLView_h__

#include "wyObject.h"
#include <windows.h>
#include <tchar.h>
#include "wyEvents.h"
#include "wyTypes.h"
#include "EGL/egl.h"
#include "wyGestureRecognizerListener.h"

/**
 * @class wyWinGLView
 *
 * GL encapsulation for windows platform
 */
class WIENGINE_API wyWinGLView : public wyObject, public wyGestureRecognizerListener {
private:
	/// window instance
	HWND m_hWnd;

	/// accelerator table
	HACCEL m_hAccelTable;

	/// egl display
	EGLDisplay m_eglDisplay;

	/// egl surface
	EGLSurface m_eglSurface;

	/// true means should detect gesture
	bool m_detectGesture;

	/// motion event to save mouse event info
	wyMotionEvent m_event;

	/// flag indicating mouse is pressed
	bool m_pressed;

	/// flag indicating stop rendering or not
	bool m_stopRender;

protected:
	wyWinGLView();

	/// deinit EGL
	void deinitEgl();

	/// draw one frame
	void doDrawFrame();

public:
	virtual ~wyWinGLView();
	static wyWinGLView* make();

	/// window procedure
	static LRESULT CALLBACK glViewWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/// @see wyGestureRecognizerListener::onWYGesture
	virtual void onWYGesture(wyGestureRecognizer* gr);

	/// prepare before run
	void prepare();

	/**
	 * Create a window and start main loop, this method blocks until user ends app
	 */
	int run();

	/**
	 * Set detect gesture or not
	 */
	void setDetectGesture(bool flag) { m_detectGesture = flag; }

	/**
	 * Should detect gesture or not
	 */
	bool isDetectGesture() { return m_detectGesture; }

	/**
	 * Get window handle
	 */
	HWND getWindowHandle() { return m_hWnd; }

	/**
	 * Set window handle
	 */
	void setWindowHandle(HWND hWnd) { m_hWnd = hWnd; }

	/**
	 * Set handle of accelerator table
	 */
	void setAccelTable(HACCEL h) { m_hAccelTable = h; }

	/**
	 * Get handle of accelerator table
	 */
	HACCEL getAccelTable() { return m_hAccelTable; }

	/**
	 * Stop render or not
	 */
	void setStopRender(bool flag) { m_stopRender = flag; }

	/**
	 * Is rendering stopped?
	 */
	bool shouldStopRender() { return m_stopRender; }
};

#endif // __wyWinGLView_h__

#endif // #if WINDOWS
