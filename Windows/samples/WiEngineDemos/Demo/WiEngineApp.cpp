#include "WiEngineApp.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyDirector.h"

WiEngineApp::WiEngineApp() :
		m_hasMenu(false),
		m_borderless(false),
		m_resizable(false),
		m_title(NULL) {
	// create GL View
	// it is not necessary to retain gl view because it will be holden by wiengine
	m_glView = wyWinGLView::make();

	// get desktop size
	m_desktopWidth = GetSystemMetrics(SM_CXSCREEN);
    m_desktopHeight = GetSystemMetrics(SM_CYSCREEN);

	// register window class
	registerWindowClass();
}

WiEngineApp::~WiEngineApp() {
	if(m_title) {
		free((void*)m_title);
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
        wc.hIcon = LoadIcon(m_module, _T("GLUT_ICON"));
        wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
        if(!wc.hIcon)
			wc.hIcon = LoadIcon( NULL, IDI_WINLOGO);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = NULL;
        wc.lpszMenuName = NULL;
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
		LOGW("wyWinGLView::run: No window class info found, register window class failed?");
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
		LOGE("wyWinGLView::run: failed to create window");
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
	switch(uMsg) {
		default:
			return wyWinGLView::glViewWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

void WiEngineApp::setTitle(const char* title) {
	if(m_title) {
		free((void*)m_title);
		m_title = NULL;
	}
	m_title = copy(title);
}

const char* WiEngineApp::copy(const char* src) {
	if(src == NULL)
		return NULL;

	size_t len = strlen(src);
	char* c = (char*)calloc(len + 1, sizeof(char));
	memcpy(c, src, len);
	return c;
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

void WiEngineApp::runWithEntry(demoEntryFunc func) {
	// create window
	createWindow();

	// set window handle to gl view
	m_glView->setWindowHandle(m_hWnd);

	// show window
	showWindow();

	// prepare
	m_glView->prepare();

	// call entry
	func();

	// run
	m_glView->run();
}