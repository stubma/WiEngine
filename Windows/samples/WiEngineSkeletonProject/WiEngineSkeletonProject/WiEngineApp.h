#ifndef __WiEngineApp_h__
#define __WiEngineApp_h__

#include "wyWinGLView.h"
#include "wyScene.h"

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

	/// copy string
	const char* copy(const char* src);

public:
	WiEngineApp();
	virtual ~WiEngineApp();

	/**
	 * Start app main loop with first scene specified
	 */
	int runWithScene(wyScene* s);

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
