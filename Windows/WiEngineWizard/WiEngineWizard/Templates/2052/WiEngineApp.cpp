#include "WiEngineApp.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyDirector.h"
#include "stdafx.h"
#include "resource.h"
#include "FirstScene.h"

// is already started?
static bool s_started = false;

static void onSurfaceChanged(int w, int h, void* data) {
	// ensure it is not started multiple times
	if(!s_started) {
		s_started = true;

		// run with first scene
		wyDirector* director = wyDirector::getInstance();
		wyScene* scene = new FirstScene();
		director->runWithScene(scene);
		scene->release();
	}
}

// life cycle listener
static const wyDirectorLifecycleListener s_surfaceLifeCycleListener = {
	NULL,
	onSurfaceChanged,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	// if you want to test against different screen, set screen config here
//	wyScreenConfig c = { 1.5f, 1.0f, 1200, 600 };
//	wyDirector::setScreenConfig(c);

	// create app instance and set window title
	WiEngineApp* app = new WiEngineApp();
	app->setTitle("WiEngineSkeletonProject");

	// you can show menu if you want
//	app->setHasMenu(true);

	// show fps or not?
	wyDirector* director = wyDirector::getInstance();
	director->setShowFPS(true);

	// add life cycle listener
    director->addLifecycleListener(&s_surfaceLifeCycleListener, NULL);

	/*
	 * If you want to run demo in base size mode, uncomment
	 * following code. To understand what is base size mode, view
	 * WiYun blog: http://blog.wiyun.com/?p=949
	 */
//	wyDirector::getInstance()->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//	wyDirector::getInstance()->setBaseSize(320, 480);

	// start event loop
	int ret = app->run();

	// when event loop returns, delete app instance
	delete app;

	// return
	return ret;
}

WiEngineApp::WiEngineApp() :
		m_hasMenu(false),
		m_borderless(false),
		m_resizable(false),
		m_hWnd(NULL),
		m_title(NULL) {
	// create GL View
	// it is not necessary to retain gl view because it will be holden by wiengine
	m_glView = wyWinGLView::make();

	// get desktop size
	m_desktopWidth = GetSystemMetrics(SM_CXSCREEN);
    m_desktopHeight = GetSystemMetrics(SM_CYSCREEN);
}

WiEngineApp::~WiEngineApp() {
	if(m_title) {
		wyFree((void*)m_title);
	}
}

void WiEngineApp::registerWindowClass() {
	// first query WiEngine window class
	WNDCLASS wc;
    m_module = GetModuleHandle(NULL);
    ATOM atom = GetClassInfo(m_module, _T("WiEngine"), &wc);

	// check class info is ready or not, if not ready, register it
	if(atom == 0) {
		// clear WINCLASS
        ZeroMemory( &wc, sizeof(WNDCLASS) );

        // init window class structure
        wc.lpfnWndProc = appWindowProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = m_module;
        wc.hIcon = LoadIcon(m_module, MAKEINTRESOURCE(IDI_WIENGINE));
        wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszMenuName = m_hasMenu ? MAKEINTRESOURCE(IDC_WIENGINESKELETONPROJECT) : NULL;
        wc.lpszClassName = _T("WiEngine");

        /* Register the window class */
        atom = RegisterClass(&wc);
		if(!atom) {
			LOGE("WiEngineApp::registerWindowClass: Register WiEngine window class failed");
		}
    }
}

void WiEngineApp::createWindow() {
	WNDCLASS wc;
    DWORD flags = 0;
    DWORD exFlags = 0;
    ATOM atom;

    // Grab the window class we have registered on constructor
    atom = GetClassInfo(m_module, _T("WiEngine"), &wc);
	if(!atom) {
		LOGW("WiEngineApp::createWindow: No window class info found, register window class failed?");
		return;
	}

	// basic flags
	flags = WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	// if has menu
	if(m_hasMenu) {
		flags |= WS_POPUP;
		exFlags |= WS_EX_TOOLWINDOW;
	}

	// check border
	if(!m_borderless) {
		flags |= WS_OVERLAPPEDWINDOW;
	}

	// check resizable
	if(m_resizable) {
		flags |= WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	} else {
		flags ^= WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	}

	// windows rect
	wyScreenConfig& sc = wyDirector::getScreenConfig();
	wyRect winRect = wyr((m_desktopWidth - sc.winWidth) / 2, 
		(m_desktopHeight - sc.winHeight) / 2, 
		sc.winWidth, 
		sc.winHeight);
	computeWindowRectFromClientArea(flags, &winRect);

	// create window
	m_hWnd = CreateWindowEx(
        exFlags,
        _T("WiEngine"),
        m_title,
        flags,
		winRect.x,
		winRect.y,
		winRect.width,
		winRect.height,
        NULL,
        NULL,
        m_module,
        NULL);
	if(!m_hWnd) {
		LOGE("WiEngineApp::createWindow: failed to create window");
		return;
	}

	// Need to set requested style again, apparently Windows doesn't listen when requesting windows without title bar or borders
	SetWindowLong(m_hWnd, GWL_STYLE, flags);
    SetWindowPos(m_hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    // Make a menu window always on top
    if(m_hasMenu) {
		SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
}

void WiEngineApp::showWindow() {
	// show window
	ShowWindow(m_hWnd, SW_SHOW);

	// update window
	UpdateWindow(m_hWnd);
    ShowCursor(TRUE); 
}

LRESULT CALLBACK WiEngineApp::appWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int wmId, wmEvent;

	switch(uMsg) {
		case WM_COMMAND:
			wmId = LOWORD(wParam);
			wmEvent = HIWORD(wParam);

			// ����˵�ѡ��:
			switch(wmId) {
				case IDM_ABOUT:
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
					break;
				case IDM_EXIT:
					PostMessage(hWnd, WM_CLOSE, 0, 0);
					break;
				default:
					return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
			break;
		default:
			return wyWinGLView::glViewWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

INT_PTR CALLBACK WiEngineApp::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			break;
	}
	return (INT_PTR)FALSE;
}

void WiEngineApp::setTitle(const char* title) {
	if(m_title) {
		wyFree((void*)m_title);
		m_title = NULL;
	}
	m_title = wyUtils::copy(title);
}

void WiEngineApp::getWindowFrameMetrics(const DWORD windowStyle, int* xBorderWidth, int* yBorderWidth) {
    if (windowStyle & WS_THICKFRAME) {
        *xBorderWidth = GetSystemMetrics(SM_CXSIZEFRAME);
        *yBorderWidth = GetSystemMetrics(SM_CYSIZEFRAME);
    } else if (windowStyle & WS_DLGFRAME) {
        *xBorderWidth = GetSystemMetrics(SM_CXFIXEDFRAME);
        *yBorderWidth = GetSystemMetrics(SM_CYFIXEDFRAME);
    } else {
        *xBorderWidth = 0;
        *yBorderWidth = 0;
    }
}

void WiEngineApp::computeWindowRectFromClientArea(const DWORD windowStyle, wyRect* clientRect) {
    // If window has title bar, correct rect for it
    if (windowStyle & WS_CAPTION) {
		clientRect->height += GetSystemMetrics(SM_CYCAPTION);
	}

    /* 
	 * get width of window's borders (frame), correct rect for it.
     * Note, borders can be of zero width if style does not specify borders
     */
	if(!m_borderless) {
		int xBorderWidth = 0, yBorderWidth = 0;
		getWindowFrameMetrics(windowStyle, &xBorderWidth, &yBorderWidth);
		clientRect->width += xBorderWidth * 2;
		clientRect->height += yBorderWidth * 2;
		clientRect->x = (m_desktopWidth - clientRect->width) / 2;
		clientRect->y = (m_desktopHeight - clientRect->height) / 2;
	}
}

int WiEngineApp::run() {
	// load accelerator table
	HACCEL hAccelTable = LoadAccelerators(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_WIENGINESKELETONPROJECT));

	// register window class
	registerWindowClass();

	// create window
	createWindow();

	// set window and accelerator to gl view
	m_glView->setWindowHandle(m_hWnd);
	m_glView->setAccelTable(hAccelTable);

	// show window
	showWindow();

	// prepare
	m_glView->prepare();

	// run
	return m_glView->run();
}
