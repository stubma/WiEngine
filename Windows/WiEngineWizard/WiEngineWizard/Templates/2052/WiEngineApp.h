/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __WiEngineApp_h__
#define __WiEngineApp_h__

#include "wyWinGLView.h"

/**
 * @class WiEngineApp
 *
 * Application object for an app based on WiEngine, this is top
 * class and entry point of WiEngine-based app
 */
class WiEngineApp {
private:
	/// gl view
	wyWinGLView* m_glView;

	/// screen width
	float m_desktopWidth;

	/// screen height
	float m_desktopHeight;

	/// module instance
	HMODULE m_module;

	/// window instance
	HWND m_hWnd;

	/// true means windows should have menu bar
	bool m_hasMenu;

	/// true means window has no border
	bool m_borderless;

	/// true means window can be resized
	bool m_resizable;

	/// window title
	const char* m_title;

private:
	/// register window class
	void registerWindowClass();

	/// create window
	void createWindow();

	/// show window
	void showWindow();

	/// window procedure
	static LRESULT CALLBACK appWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/// dialog procedure
	static INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	/// get metrics of system window frame
	void getWindowFrameMetrics(const DWORD windowStyle, int* xBorderWidth, int* yBorderWidth);

	/// compute window rect before place window to desktop
	void computeWindowRectFromClientArea(const DWORD windowStyle, wyRect* clientRect);

public:
	WiEngineApp();
	virtual ~WiEngineApp();

	/**
	 * Start app main loop
	 */
	int run();

	/**
	 * Set windows has menu or not, this method must be called before \c run
	 */
	void setHasMenu(bool flag) { m_hasMenu = flag; }

	/**
	 * Is window has menu?
	 */
	bool hasMenu() { return m_hasMenu; }

	/**
	 * Set window has border nor not, true means no border. This method must be called
	 * before \c run
	 */
	void setBorderless(bool flag) { m_borderless = flag; }

	/**
	 * Does window have border? true means no boreder
	 */
	bool isBorderless() { return m_borderless; }

	/**
	 * Set window is resizable or not
	 */
	void setResizable(bool flag) { m_resizable = flag; }
	
	/**
	 * Is window resizable
	 */
	bool isResizable() { return m_resizable; }

	/**
	 * Set window title, this method should be called before \c run
	 */
	void setTitle(const char* title);

	/**
	 * Get window title, caller should NOT release it
	 */
	const char* getTitle() { return m_title; }
};

#endif // __WiEngineApp_h__
