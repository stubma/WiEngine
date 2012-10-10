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

#include "wyUtils.h"
#include "wyUtils_win.h"
#include "wyLog.h"
#include "png.h"
#include "wyResMap.h"
#include <windows.h>
#include "wySkiaAdapter.h"
#include "wyAndroidStrings.h"
#include "wyEvents.h"
#include "wyDirector.h"
#include "wyWinGLView.h"
#include "wyTargetSelector.h"
#include "wyResourceDecoder.h"

#define PNG_BYTES_TO_CHECK 8

extern wyResourceDecoder* gResDecoder;

#ifdef __cplusplus
extern "C" {
#endif

// libjpeg, need place it in extern C
#include "jpeglib.h"
#include "libnsbmp.h"

static void user_read_fn(png_structp png_ptr, png_bytep data, png_size_t length) {
	memcpy(data, png_ptr->io_ptr, length * sizeof(char));
	png_ptr->io_ptr = ((char*)png_ptr->io_ptr) + length;
}

struct wiengine_error_mgr {
	struct jpeg_error_mgr pub;
	jmp_buf setjmp_buffer;
};
typedef struct wiengine_error_mgr* wiengine_error_ptr;

static void jpeg_error_exit(j_common_ptr cinfo) {
	/* cinfo->err really points to a wiengine_error_mgr struct, so coerce pointer */
	wiengine_error_ptr myerr = (wiengine_error_ptr) cinfo->err;

	/* Always display the message. */
	/* We could postpone this until after returning, if we chose. */
	(*cinfo->err->output_message)(cinfo);

	/* Return control to the setjmp point */
	longjmp(myerr->setjmp_buffer, 1);
}

static void jpeg_output_message(j_common_ptr cinfo) {
	char buffer[JMSG_LENGTH_MAX];

	/* Create the message */
	(*cinfo->err->format_message)(cinfo, buffer);

	// output log
	LOGE("%s", buffer);
}

static void* bitmap_create(int width, int height, unsigned int state) {
	return wyCalloc(width * height, 4);
}

static void invalidate(void* bitmap, void* private_word) {
}

static void bitmap_set_suspendable(void* bitmap, void* private_word, void (*invalidate)(void* bitmap, void* private_word)) {
}

static unsigned char* bitmap_get_buffer(void* bitmap) {
	return (unsigned char*)bitmap;
}

static size_t bitmap_get_bpp(void* bitmap) {
	return 4;
}

static void bitmap_destroy(void* bitmap) {
	// we don't free bitmap here
}

#ifdef __cplusplus
}
#endif

void wyUtils::showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton, const char* negativeButton, wyTargetSelector* onOK, wyTargetSelector* onCancel) {
	// get director
	wyDirector* d = wyDirector::getInstanceNoCreate();
	if(!d)
		return;

	// get surface view
	wyGLSurfaceView glView = d->getGLView();
	if(!glView)
		return;

	// show box
	HWND hWnd = glView->getWindowHandle();
	int ret = MessageBox(hWnd, (LPCSTR)msg, (LPCSTR)title, MB_OKCANCEL | MB_DEFBUTTON1 | MB_ICONQUESTION);

	// check ret
	if(ret == IDOK && onOK) {
		onOK->invoke();
	} else if(ret == IDCANCEL && onCancel) {
		onCancel->invoke();
	}
}

void wyUtils::showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton, wyTargetSelector* onOK) {
	// get director
	wyDirector* d = wyDirector::getInstanceNoCreate();
	if(!d)
		return;

	// get surface view
	wyGLSurfaceView glView = d->getGLView();
	if(!glView)
		return;

	// show box
	HWND hWnd = glView->getWindowHandle();
	int ret = MessageBox(hWnd, (LPCSTR)msg, (LPCSTR)title, MB_OK | MB_ICONWARNING);
	
	// check ret
	if(ret == IDOK && onOK) {
		onOK->invoke();
	}
}

void wyUtils::convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event) {
	// mapping of window vkey to wiengine vkey
	static wyKeyCode s_mapping[0xff] = {
		KEYCODE_UNKNOWN, // 0x00, just a placeholder
		KEYCODE_UNKNOWN, // VK_LBUTTON        0x01
		KEYCODE_UNKNOWN, // VK_RBUTTON        0x02
		KEYCODE_UNKNOWN, // VK_CANCEL         0x03
		KEYCODE_UNKNOWN, // VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

		KEYCODE_UNKNOWN, // VK_XBUTTON1       0x05    /* NOT contiguous with L & RBUTTON */
		KEYCODE_UNKNOWN, // VK_XBUTTON2       0x06    /* NOT contiguous with L & RBUTTON */


		KEYCODE_UNKNOWN, // unassigned        0x07

		KEYCODE_UNKNOWN, // VK_BACK           0x08
		KEYCODE_TAB,	 // VK_TAB            0x09

		KEYCODE_UNKNOWN, // reserved  0x0A
		KEYCODE_UNKNOWN, // reserved  0x0B

		KEYCODE_UNKNOWN, // VK_CLEAR          0x0C
		KEYCODE_ENTER, // VK_RETURN         0x0D

		KEYCODE_UNKNOWN, // reserved  0x0E
		KEYCODE_UNKNOWN, // reserved  0x0F

		KEYCODE_SHIFT_LEFT, // VK_SHIFT          0x10
		KEYCODE_UNKNOWN,    // VK_CONTROL        0x11
		KEYCODE_MENU,		// VK_MENU           0x12
		KEYCODE_MEDIA_PLAY_PAUSE, // VK_PAUSE          0x13
		KEYCODE_UNKNOWN,    // VK_CAPITAL        0x14

		KEYCODE_UNKNOWN, // VK_KANA VK_HANGEUL VK_HANGUL  0x15
		KEYCODE_UNKNOWN, // unassigned        0x16
		KEYCODE_UNKNOWN, // VK_JUNJA          0x17
		KEYCODE_UNKNOWN, // VK_FINAL          0x18
		KEYCODE_UNKNOWN, // VK_HANJA          0x19
		KEYCODE_UNKNOWN, // unassigned        0x1A

		KEYCODE_BACK,    // VK_ESCAPE         0x1B

		KEYCODE_UNKNOWN, // VK_CONVERT        0x1C
		KEYCODE_UNKNOWN, // VK_NONCONVERT     0x1D
		KEYCODE_UNKNOWN, // VK_ACCEPT         0x1E
		KEYCODE_UNKNOWN, // VK_MODECHANGE     0x1F

		KEYCODE_SPACE,   // VK_SPACE          0x20
		KEYCODE_UNKNOWN, // VK_PRIOR          0x21
		KEYCODE_UNKNOWN, // VK_NEXT           0x22
		KEYCODE_UNKNOWN, // VK_END            0x23
		KEYCODE_HOME,		// VK_HOME           0x24
		KEYCODE_DPAD_LEFT,	// VK_LEFT           0x25
		KEYCODE_DPAD_UP,	// VK_UP             0x26
		KEYCODE_DPAD_RIGHT, // VK_RIGHT          0x27
		KEYCODE_DPAD_DOWN,	// VK_DOWN           0x28
		KEYCODE_UNKNOWN, // VK_SELECT         0x29
		KEYCODE_UNKNOWN, // VK_PRINT          0x2A
		KEYCODE_UNKNOWN, // VK_EXECUTE        0x2B
		KEYCODE_UNKNOWN, // VK_SNAPSHOT       0x2C
		KEYCODE_UNKNOWN, // VK_INSERT         0x2D
		KEYCODE_DEL,	 // VK_DELETE         0x2E
		KEYCODE_UNKNOWN, // VK_HELP           0x2F

		// VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
		KEYCODE_0, // '0'  0x30
		KEYCODE_1, // '1'  0x31
		KEYCODE_2, // '2'  0x32
		KEYCODE_3, // '3'  0x33
		KEYCODE_4, // '4'  0x34
		KEYCODE_5, // '5'  0x35
		KEYCODE_6, // '6'  0x36
		KEYCODE_7, // '7'  0x37
		KEYCODE_8, // '8'  0x38
		KEYCODE_9, // '9'  0x39

		KEYCODE_UNKNOWN, // unassigned  0x3A
		KEYCODE_UNKNOWN, // unassigned  0x3B
		KEYCODE_UNKNOWN, // unassigned  0x3C
		KEYCODE_UNKNOWN, // unassigned  0x3D
		KEYCODE_UNKNOWN, // unassigned  0x3E
		KEYCODE_UNKNOWN, // unassigned  0x3F
		KEYCODE_UNKNOWN, // unassigned  0x40

		// VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
		KEYCODE_A, // 'A'  0x41
		KEYCODE_B, // 'B'  0x42
		KEYCODE_C, // 'C'  0x43
		KEYCODE_D, // 'D'  0x44
		KEYCODE_E, // 'E'  0x45
		KEYCODE_F, // 'F'  0x46
		KEYCODE_G, // 'G'  0x47
		KEYCODE_H, // 'H'  0x48
		KEYCODE_I, // 'I'  0x49
		KEYCODE_J, // 'J'  0x4A
		KEYCODE_K, // 'K'  0x4B
		KEYCODE_L, // 'L'  0x4C
		KEYCODE_M, // 'M'  0x4D
		KEYCODE_N, // 'N'  0x4E
		KEYCODE_O, // 'O'  0x4F
		KEYCODE_P, // 'P'  0x50
		KEYCODE_Q, // 'Q'  0x51
		KEYCODE_R, // 'R'  0x52
		KEYCODE_S, // 'S'  0x53
		KEYCODE_T, // 'T'  0x54
		KEYCODE_U, // 'U'  0x55
		KEYCODE_V, // 'V'  0x56
		KEYCODE_W, // 'W'  0x57
		KEYCODE_X, // 'X'  0x58
		KEYCODE_Y, // 'Y'  0x59
		KEYCODE_Z, // 'Z'  0x5A

		KEYCODE_UNKNOWN, // VK_LWIN           0x5B
		KEYCODE_UNKNOWN, // VK_RWIN           0x5C
		KEYCODE_UNKNOWN, // VK_APPS           0x5D
		KEYCODE_UNKNOWN, // reserved          0x5E
		KEYCODE_UNKNOWN, // VK_SLEEP          0x5F

		KEYCODE_0, // VK_NUMPAD0        0x60
		KEYCODE_1, // VK_NUMPAD1        0x61
		KEYCODE_2, // VK_NUMPAD2        0x62
		KEYCODE_3, // VK_NUMPAD3        0x63
		KEYCODE_4, // VK_NUMPAD4        0x64
		KEYCODE_5, // VK_NUMPAD5        0x65
		KEYCODE_6, // VK_NUMPAD6        0x66
		KEYCODE_7, // VK_NUMPAD7        0x67
		KEYCODE_8, // VK_NUMPAD8        0x68
		KEYCODE_9, // VK_NUMPAD9        0x69
		KEYCODE_UNKNOWN, // VK_MULTIPLY       0x6A
		KEYCODE_UNKNOWN, // VK_ADD            0x6B
		KEYCODE_UNKNOWN, // VK_SEPARATOR      0x6C
		KEYCODE_MINUS,   // VK_SUBTRACT       0x6D
		KEYCODE_UNKNOWN, // VK_DECIMAL        0x6E
		KEYCODE_UNKNOWN, // VK_DIVIDE         0x6F
		KEYCODE_UNKNOWN, // VK_F1             0x70
		KEYCODE_UNKNOWN, // VK_F2             0x71
		KEYCODE_UNKNOWN, // VK_F3             0x72
		KEYCODE_UNKNOWN, // VK_F4             0x73
		KEYCODE_UNKNOWN, // VK_F5             0x74
		KEYCODE_UNKNOWN, // VK_F6             0x75
		KEYCODE_UNKNOWN, // VK_F7             0x76
		KEYCODE_UNKNOWN, // VK_F8             0x77
		KEYCODE_UNKNOWN, // VK_F9             0x78
		KEYCODE_UNKNOWN, // VK_F10            0x79
		KEYCODE_UNKNOWN, // VK_F11            0x7A
		KEYCODE_UNKNOWN, // VK_F12            0x7B
		KEYCODE_UNKNOWN, // VK_F13            0x7C
		KEYCODE_UNKNOWN, // VK_F14            0x7D
		KEYCODE_UNKNOWN, // VK_F15            0x7E
		KEYCODE_UNKNOWN, // VK_F16            0x7F
		KEYCODE_UNKNOWN, // VK_F17            0x80
		KEYCODE_UNKNOWN, // VK_F18            0x81
		KEYCODE_UNKNOWN, // VK_F19            0x82
		KEYCODE_UNKNOWN, // VK_F20            0x83
		KEYCODE_UNKNOWN, // VK_F21            0x84
		KEYCODE_UNKNOWN, // VK_F22            0x85
		KEYCODE_UNKNOWN, // VK_F23            0x86
		KEYCODE_UNKNOWN, // VK_F24            0x87

		/*
		 * 0x88 - 0x8F : unassigned
		 */
		KEYCODE_UNKNOWN, // unassigned        0x88
		KEYCODE_UNKNOWN, // unassigned        0x89
		KEYCODE_UNKNOWN, // unassigned        0x8A
		KEYCODE_UNKNOWN, // unassigned        0x8B
		KEYCODE_UNKNOWN, // unassigned        0x8C
		KEYCODE_UNKNOWN, // unassigned        0x8D
		KEYCODE_UNKNOWN, // unassigned        0x8E
		KEYCODE_UNKNOWN, // unassigned        0x8F

		KEYCODE_UNKNOWN, // VK_NUMLOCK        0x90
		KEYCODE_UNKNOWN, // VK_SCROLL         0x91

		/*
		 * NEC PC-9800 kbd definitions
		 */
		KEYCODE_UNKNOWN, // VK_OEM_NEC_EQUAL or VK_OEM_FJ_JISHO 0x92

		/*
		 * Fujitsu/OASYS kbd definitions
		 */
		KEYCODE_UNKNOWN, // VK_OEM_FJ_MASSHOU 0x93   // 'Unregister word' key
		KEYCODE_UNKNOWN, // VK_OEM_FJ_TOUROKU 0x94   // 'Register word' key
		KEYCODE_UNKNOWN, // VK_OEM_FJ_LOYA    0x95   // 'Left OYAYUBI' key
		KEYCODE_UNKNOWN, // VK_OEM_FJ_ROYA    0x96   // 'Right OYAYUBI' key

		/*
		 * 0x97 - 0x9F : unassigned
		 */
		KEYCODE_UNKNOWN, // unassigned        0x97
		KEYCODE_UNKNOWN, // unassigned        0x98
		KEYCODE_UNKNOWN, // unassigned        0x99
		KEYCODE_UNKNOWN, // unassigned        0x9A
		KEYCODE_UNKNOWN, // unassigned        0x9B
		KEYCODE_UNKNOWN, // unassigned        0x9C
		KEYCODE_UNKNOWN, // unassigned        0x9D
		KEYCODE_UNKNOWN, // unassigned        0x9E
		KEYCODE_UNKNOWN, // unassigned        0x9F

		/*
		 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
		 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
		 * No other API or message will distinguish left and right keys in this way.
		 */
		KEYCODE_SHIFT_LEFT, // VK_LSHIFT         0xA0
		KEYCODE_SHIFT_RIGHT,// VK_RSHIFT         0xA1
		KEYCODE_UNKNOWN,	// VK_LCONTROL       0xA2
		KEYCODE_UNKNOWN,	// VK_RCONTROL       0xA3
		KEYCODE_UNKNOWN,	// VK_LMENU          0xA4
		KEYCODE_UNKNOWN,	// VK_RMENU          0xA5

		KEYCODE_UNKNOWN, // VK_BROWSER_BACK        0xA6
		KEYCODE_UNKNOWN, // VK_BROWSER_FORWARD     0xA7
		KEYCODE_UNKNOWN, // VK_BROWSER_REFRESH     0xA8
		KEYCODE_UNKNOWN, // VK_BROWSER_STOP        0xA9
		KEYCODE_UNKNOWN, // VK_BROWSER_SEARCH      0xAA
		KEYCODE_UNKNOWN, // VK_BROWSER_FAVORITES   0xAB
		KEYCODE_UNKNOWN, // VK_BROWSER_HOME        0xAC

		KEYCODE_MUTE,		// VK_VOLUME_MUTE         0xAD
		KEYCODE_VOLUME_DOWN,// VK_VOLUME_DOWN         0xAE
		KEYCODE_VOLUME_UP,  // VK_VOLUME_UP           0xAF
		KEYCODE_MEDIA_NEXT, // VK_MEDIA_NEXT_TRACK    0xB0
		KEYCODE_MEDIA_PREVIOUS, // VK_MEDIA_PREV_TRACK    0xB1
		KEYCODE_MEDIA_STOP, // VK_MEDIA_STOP          0xB2
		KEYCODE_MEDIA_PLAY_PAUSE, // VK_MEDIA_PLAY_PAUSE    0xB3
		KEYCODE_UNKNOWN, // VK_LAUNCH_MAIL         0xB4
		KEYCODE_UNKNOWN, // VK_LAUNCH_MEDIA_SELECT 0xB5
		KEYCODE_UNKNOWN, // VK_LAUNCH_APP1         0xB6
		KEYCODE_UNKNOWN, // VK_LAUNCH_APP2         0xB7

		/*
		 * 0xB8 - 0xB9 : reserved
		 */
		KEYCODE_UNKNOWN, // reserved  0xB8
		KEYCODE_UNKNOWN, // reserved  0xB9

		KEYCODE_UNKNOWN, // VK_OEM_1          0xBA   // ';:' for US
		KEYCODE_UNKNOWN, // VK_OEM_PLUS       0xBB   // '+' any country
		KEYCODE_UNKNOWN, // VK_OEM_COMMA      0xBC   // ',' any country
		KEYCODE_UNKNOWN, // VK_OEM_MINUS      0xBD   // '-' any country
		KEYCODE_UNKNOWN, // VK_OEM_PERIOD     0xBE   // '.' any country
		KEYCODE_UNKNOWN, // VK_OEM_2          0xBF   // '/?' for US
		KEYCODE_UNKNOWN, // VK_OEM_3          0xC0   // '`~' for US

		/*
		 * 0xC1 - 0xD7 : reserved
		 */
		KEYCODE_UNKNOWN, // reserved  0xC1
		KEYCODE_UNKNOWN, // reserved  0xC2
		KEYCODE_UNKNOWN, // reserved  0xC3
		KEYCODE_UNKNOWN, // reserved  0xC4
		KEYCODE_UNKNOWN, // reserved  0xC5
		KEYCODE_UNKNOWN, // reserved  0xC6
		KEYCODE_UNKNOWN, // reserved  0xC7
		KEYCODE_UNKNOWN, // reserved  0xC8
		KEYCODE_UNKNOWN, // reserved  0xC9
		KEYCODE_UNKNOWN, // reserved  0xCA
		KEYCODE_UNKNOWN, // reserved  0xCB
		KEYCODE_UNKNOWN, // reserved  0xCC
		KEYCODE_UNKNOWN, // reserved  0xCD
		KEYCODE_UNKNOWN, // reserved  0xCE
		KEYCODE_UNKNOWN, // reserved  0xCF
		KEYCODE_UNKNOWN, // reserved  0xD0
		KEYCODE_UNKNOWN, // reserved  0xD1
		KEYCODE_UNKNOWN, // reserved  0xD2
		KEYCODE_UNKNOWN, // reserved  0xD3
		KEYCODE_UNKNOWN, // reserved  0xD4
		KEYCODE_UNKNOWN, // reserved  0xD5
		KEYCODE_UNKNOWN, // reserved  0xD6
		KEYCODE_UNKNOWN, // reserved  0xD7

		/*
		 * 0xD8 - 0xDA : unassigned
		 */
		KEYCODE_UNKNOWN, // unassigned  0xD8
		KEYCODE_UNKNOWN, // unassigned  0xD9
		KEYCODE_UNKNOWN, // unassigned  0xDA

		KEYCODE_UNKNOWN, // VK_OEM_4          0xDB  //  '[{' for US
		KEYCODE_UNKNOWN, // VK_OEM_5          0xDC  //  '\|' for US
		KEYCODE_UNKNOWN, // VK_OEM_6          0xDD  //  ']}' for US
		KEYCODE_UNKNOWN, // VK_OEM_7          0xDE  //  ''"' for US
		KEYCODE_UNKNOWN, // VK_OEM_8          0xDF

		/*
		 * 0xE0 : reserved
		 */
		KEYCODE_UNKNOWN, // reserved  0xE0

		/*
		 * Various extended or enhanced keyboards
		 */
		KEYCODE_UNKNOWN, // VK_OEM_AX         0xE1  //  'AX' key on Japanese AX kbd
		KEYCODE_UNKNOWN, // VK_OEM_102        0xE2  //  "<>" or "\|" on RT 102-key kbd.
		KEYCODE_UNKNOWN, // VK_ICO_HELP       0xE3  //  Help key on ICO
		KEYCODE_UNKNOWN, // VK_ICO_00         0xE4  //  00 key on ICO
		KEYCODE_UNKNOWN, // VK_PROCESSKEY     0xE5
		KEYCODE_UNKNOWN, // VK_ICO_CLEAR      0xE6
		KEYCODE_UNKNOWN, // VK_PACKET         0xE7

		KEYCODE_UNKNOWN, // unassigned  0xE8

		/*
		 * Nokia/Ericsson definitions
		 */
		KEYCODE_UNKNOWN, // VK_OEM_RESET      0xE9
		KEYCODE_UNKNOWN, // VK_OEM_JUMP       0xEA
		KEYCODE_UNKNOWN, // VK_OEM_PA1        0xEB
		KEYCODE_UNKNOWN, // VK_OEM_PA2        0xEC
		KEYCODE_UNKNOWN, // VK_OEM_PA3        0xED
		KEYCODE_UNKNOWN, // VK_OEM_WSCTRL     0xEE
		KEYCODE_UNKNOWN, // VK_OEM_CUSEL      0xEF
		KEYCODE_UNKNOWN, // VK_OEM_ATTN       0xF0
		KEYCODE_UNKNOWN, // VK_OEM_FINISH     0xF1
		KEYCODE_UNKNOWN, // VK_OEM_COPY       0xF2
		KEYCODE_UNKNOWN, // VK_OEM_AUTO       0xF3
		KEYCODE_UNKNOWN, // VK_OEM_ENLW       0xF4
		KEYCODE_UNKNOWN, // VK_OEM_BACKTAB    0xF5

		KEYCODE_UNKNOWN, // VK_ATTN           0xF6
		KEYCODE_UNKNOWN, // VK_CRSEL          0xF7
		KEYCODE_UNKNOWN, // VK_EXSEL          0xF8
		KEYCODE_UNKNOWN, // VK_EREOF          0xF9
		KEYCODE_UNKNOWN, // VK_PLAY           0xFA
		KEYCODE_UNKNOWN, // VK_ZOOM           0xFB
		KEYCODE_UNKNOWN, // VK_NONAME         0xFC
		KEYCODE_UNKNOWN, // VK_PA1            0xFD
		KEYCODE_UNKNOWN, // VK_OEM_CLEAR      0xFE
	};
	unsigned char vKeyCodeWin = pe->keyCode;
	memcpy(event, pe, sizeof(wyKeyEvent));
	event->keyCode = s_mapping[vKeyCodeWin];
}

void wyUtils::convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type) {
	memcpy(event, pe, sizeof(wyMotionEvent));

	// if not density scale mode, must convert coordinates relative to base size
	if(wyDevice::scaleMode != SCALE_MODE_BY_DENSITY) {
		event->x[0] = event->x[0] / wyDevice::baseScaleX;
		event->y[0] = event->y[0] / wyDevice::baseScaleY;
	}
}

void wyUtils::makeScreenshotPNG(const char* path, wyRect rect) {
	// read gl buffer
	size_t length = rect.width * rect.height * sizeof(int);
	GLubyte* buffer = (GLubyte*)wyMalloc(length);
	glReadPixels(rect.x, rect.y, rect.width, rect.height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    int width = rect.width;
    int height = rect.height;

	// ensure intermediate folder is created
	createIntermediateFolders(path);

	// open file
	const char* mappedPath = mapLocalPath(path);
	FILE* f = fopen(mappedPath, "wb");
	wyFree((void*)mappedPath);
	if(f == NULL) {
		LOGW("open png file failed: %s", strerror(errno));
		return;
	}

	// create necessary struct
	png_structp png_ptr;
	png_infop info_ptr;
	if ((png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL)) == NULL) {
		LOGW("create png struct failed");
		fclose(f);
		return;
	}
	if ((info_ptr = png_create_info_struct(png_ptr)) == NULL) {
		LOGW("create png info struct failed");
		png_destroy_write_struct(&png_ptr, NULL);
		fclose(f);
		return;
	}

	// set error handler
	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		fclose(f);
		return;
	}

	/* Set up the output control if you are using standard C streams */
	png_init_io(png_ptr, f);

	// set header
	png_set_IHDR(png_ptr, info_ptr, width, height, 8,
				 PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
				 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// gamma chunk
	png_set_gAMA(png_ptr, info_ptr, 0.45455f);

	// Write the file header information
	png_write_info(png_ptr, info_ptr);

	// build row pointers
	// gl renders "upside down" so swap top to bottom
	int rowbytes = width * 4;
	png_bytep* row_pointers = (png_bytep*)malloc(height * sizeof(png_bytep));
	for (int k = 0; k < height; k++)
		row_pointers[height - k - 1] = buffer + k * rowbytes;

	// write out the entire image data in one call
	png_write_image(png_ptr, row_pointers);

	// it is REQUIRED to call this to finish writing the rest of the file
	png_write_end(png_ptr, info_ptr);

	// clean up after the write, and free any memory allocated
	png_destroy_write_struct(&png_ptr, &info_ptr);

	// close the file
	fclose(f);

	// free buffer
	wyFree(buffer);
	free(row_pointers);
}

void wyUtils::makeScreenshotJPG(const char* path, wyRect rect) {
	size_t length = rect.width * rect.height * sizeof(int);
	GLubyte* buffer = (GLubyte*)wyMalloc(length);
	glReadPixels(rect.x, rect.y, rect.width, rect.height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

	int width = rect.width;
    int height = rect.height;

	// ensure intermediate folder is created
	createIntermediateFolders(path);

    int compress = 80;
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	/* Now we can initialize the JPEG compression object. */
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);
	const char* mappedPath = mapLocalPath(path);
	FILE* outfile = fopen(mappedPath, "wb");
	wyFree((void*)mappedPath);
	if (outfile == NULL) {
		return;
	}

	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = width;    /* image width and height, in pixels */
	cinfo.image_height = height;
	cinfo.input_components = 3;   /* # of color components per pixel */
	cinfo.in_color_space = JCS_RGB;     /* colorspace of input image */

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, compress, TRUE /* limit to baseline-JPEG values */ );
	jpeg_start_compress(&cinfo, TRUE);

    unsigned char* data_buffer = WYNEWARR(unsigned char, width * height * 3);
    for(int i = 0, j = 0; i < width * height * 4; i += 4, j += 3) {
        data_buffer[j + 0] = buffer[i + 0];
        data_buffer[j + 1] = buffer[i + 1];
        data_buffer[j + 2] = buffer[i + 2];
    }

	int row_stride = width * 3;
    while(cinfo.next_scanline < cinfo.image_height) {
        JSAMPROW row_pointer;
        row_pointer = &data_buffer[(cinfo.image_height - cinfo.next_scanline - 1) * row_stride];
        jpeg_write_scanlines(&cinfo, &row_pointer, 1);
    }

	jpeg_finish_compress(&cinfo);
	jpeg_destroy_compress(&cinfo);
    fclose(outfile);
	WYDELETEARR(data_buffer);

	wyFree(buffer);
}

int wyUtils::getResId(const char* fullName) {
	return wyResMap::getInstance()->getResId(fullName);
}

int wyUtils::getResId(const char* name, const char* type, const char* type2) {
	// process name, remove ext and replace slash
	const char* p = strrchr(name, '.');
	size_t len = p == NULL ? strlen(name) : (p - name);
	char* tmp = (char*)wyCalloc(len + 1, sizeof(char));
	strncpy(tmp, name, len);
	for(int i = 0; i < len; i++) {
		if(tmp[i] == '-')
			tmp[i] = '_';
	}

	int resId = 0;
	char buf[128];
	sprintf(buf, "R.%s.%s", type, tmp);
	resId =  wyResMap::getInstance()->getResId(buf);
	if(resId == -1 && type2 != NULL) {
		sprintf(buf, "R.%s.%s", type2, tmp);
		resId = wyResMap::getInstance()->getResId(buf);
	}

	// free
	wyFree(tmp);

	return resId;
}

const char* wyUtils::getString(int resId) {
	return wyUtils::copy(wyAndroidStrings::getInstance()->getString(resId));
}

const char16_t* wyUtils::getString16(int resId) {
	const char* s8 = wyAndroidStrings::getInstance()->getString(resId);
	return wyUtils::toUTF16(s8);
}

const char* wyUtils::utf16toutf8(const char16_t* s16) {
	char* ret = NULL;
	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)s16, -1, NULL, 0, NULL, NULL);
	if(sizeNeeded > 0) {
		ret = (char*)wyCalloc(1, sizeNeeded);
		WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)s16, -1, ret, sizeNeeded, NULL, NULL);
	}
	return ret;
}

const char* wyUtils::wctoutf8(const wchar_t* ws) {
	char* ret = NULL;
	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)ws, -1, NULL, 0, NULL, NULL);
	if(sizeNeeded > 0) {
		ret = (char*)wyCalloc(1, sizeNeeded);
		WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)ws, -1, ret, sizeNeeded, NULL, NULL);
	}
	return ret;
}

const char16_t* wyUtils::toUTF16(const char* s8) {
	char16_t* ret = NULL;
	int sizeNeeded = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, s8, strlen(s8), NULL, 0);
	if(sizeNeeded > 0) {
		ret = (char16_t*)wyCalloc(1, sizeNeeded);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, s8, strlen(s8), (LPWSTR)ret, sizeNeeded);
	}
	return ret;
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile, float width) {
	// get font file data
	size_t length;
	char* data = loadRaw(fontPath, isFile, &length);

	// call sal
	size_t w, h;
	calculateTextSizeWithCustomFont(text, fontSize, data, length, width, &w, &h);

	// free
	wyFree(data);

	// create size
	return wys(w, h);
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width) {
	size_t w, h;
	calculateTextSizeWithFont(text, fontSize, (style & BOLD) != 0, (style & ITALIC) != 0, fontName, width, &w, &h);
	return wys(w, h);
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	// get font file data
	size_t length;
	char* data = loadRaw(fontPath, isFile, &length);

	// create by sal layer
	const char* bitmap = createLabelBitmapWithCustomFont(text, fontSize, data, length, width, alignment);

	// free
	wyFree(data);

	return bitmap;
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	const char* bitmap = createLabelBitmapWithFont(text, fontSize, (style & BOLD) != 0, (style & ITALIC) != 0, fontName, width, alignment);
	return bitmap;
}

bool wyUtils::deleteFile(const char* path) {
	const char* mappedPath = wyUtils::mapLocalPath(path);
	bool ret = DeleteFile(mappedPath) != 0;
	wyFree((void*)mappedPath);
	return ret;
}

bool wyUtils::createFolder(const char* path) {
	const char* mappedPath = wyUtils::mapLocalPath(path);
	bool ret = CreateDirectory(mappedPath, NULL) != 0;
	wyFree((void*)mappedPath);
	return ret;
}

char* wyUtils::loadBMP(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// necessary variables, callbacks
	bmp_bitmap_callback_vt bitmap_callbacks = {
		bitmap_create,
		bitmap_destroy,
		bitmap_set_suspendable,
		bitmap_get_buffer,
		bitmap_get_bpp
	};
	bmp_result code;
	bmp_image bmp;
	char* image_data = NULL;

	// create our bmp image
	bmp_create(&bmp, &bitmap_callbacks);

	// analyse the BMP
	code = bmp_analyse(&bmp, length, (uint8_t*)data);
	if (code != BMP_OK) {
		LOGW("wyUtils::loadBMP: failed to analyse bmp file, error code: %d", code);
		bmp_finalise(&bmp);
		return NULL;
	}

	// save size
	int width = bmp.width;
	int height = bmp.height;
	if(w != NULL)
		*w = width * scaleX;
	if(h != NULL)
		*h = height * scaleY;

	// scale or not
	if(!sizeOnly) {
		// decode the image
		code = bmp_decode(&bmp);
		if (code != BMP_OK) {
			LOGW("wyUtils::loadBMP: failed to decode bmp file, error code: %d", code);
			bmp_finalise(&bmp);
			return NULL;
		}

		// decoded image is not released by callback, so we don't allocate memory to hold it
		image_data = (char*)bmp.bitmap;
		if(scaleX != 1.0f || scaleY != 1.f) {
			char* scaled = scaleImage(image_data, width, height, scaleX, scaleY);
			if(scaled != image_data) {
				wyFree(image_data);
				image_data = scaled;
			}
		}
	} else {
		/*
		 * We don't release allocated memory in bitmap_destroy callback because wyGLTexture2D
		 * will release it in loadBMP. However, the memory is allocated when bmp_analyse is called,
		 * so even sizeOnly is true, the memory is allocated and we need check this situation
		 */
		wyFree(bmp.bitmap);
	}

	// release bmp
	bmp_finalise(&bmp);

	return image_data;
}

char* wyUtils::loadPNG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// check sig
	if(png_sig_cmp((png_bytep)data, (png_size_t)0, PNG_BYTES_TO_CHECK)) {
		LOGW("verify png sig failed");
		return NULL;
	}

	// create necessary struct
	png_structp png_ptr;
	png_infop info_ptr;
	if ((png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL)) == NULL) {
		LOGW("create png struct failed");
		return NULL;
	}
	if ((info_ptr = png_create_info_struct(png_ptr)) == NULL) {
		LOGW("create png info struct failed");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return NULL;
	}

	// set error handler
	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		return NULL;
	}

	// set custom read function to read png from byte array
	// need to skip sig
	png_set_read_fn(png_ptr, (void*)(data + PNG_BYTES_TO_CHECK), user_read_fn);

	// set sig read
	png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK);

	// read info
	int bit_depth;
	int color_type;
	png_uint_32 width;
	png_uint_32 height;
	png_read_info(png_ptr, info_ptr);
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);
	if(w != NULL)
		*w = width * scaleX;
	if(h != NULL)
		*h = height * scaleY;

	if(!sizeOnly) {
		// control png options
		if (!(color_type & PNG_COLOR_MASK_ALPHA))
			png_set_add_alpha(png_ptr, 0xff, PNG_FILLER_AFTER);
		if (bit_depth > 8)
			png_set_strip_16(png_ptr);
		if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
			png_set_gray_to_rgb(png_ptr);
		if (color_type == PNG_COLOR_TYPE_PALETTE)
			png_set_palette_to_rgb(png_ptr);
		png_read_update_info(png_ptr, info_ptr);

		// allocate memory for rows
		png_uint_32 rowbytes = png_get_rowbytes(png_ptr, info_ptr);
		char* image_data = NULL;
		if ((image_data = (char*)wyCalloc(1, height * rowbytes)) == NULL) {
			LOGW("allocate png data buffer failed");
			png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
			return NULL;
		}

		// allocate memory for row pointers
		png_bytepp row_pointers;
		if ((row_pointers = (png_bytepp)wyCalloc(1, height * sizeof(png_bytep))) == NULL) {
			LOGW("allocate png row pointer buffer failed");
			png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
			wyFree(image_data);
			return NULL;
		}

		// read all rows
		for (int i = 0; i < height; i++)
			row_pointers[i] = (png_bytep)(image_data + i * rowbytes);
		png_read_image(png_ptr, row_pointers);
		wyFree(row_pointers);
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

		// scale or not
		if(scaleX != 1.0f || scaleY != 1.f) {
			char* scaled = scaleImage(image_data, width, height, scaleX, scaleY);
			if(scaled != image_data) {
				wyFree(image_data);
				image_data = scaled;
			}
		}

		return image_data;
	} else {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		return NULL;
	}
}

char* wyUtils::loadJPG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// necessary variables
	struct jpeg_decompress_struct cinfo;
	struct wiengine_error_mgr jerr;
	JSAMPARRAY buffer;
	int row_stride;

	// use custom error handler
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = jpeg_error_exit;
	jerr.pub.output_message = jpeg_output_message;
	if (setjmp(jerr.setjmp_buffer)) {
		// This is an important step since it will release a good deal of memory
		jpeg_destroy_decompress(&cinfo);

		return 0;
	}

	// init decompress struct
	jpeg_create_decompress(&cinfo);

	// specify data source
	jpeg_stdio_buffer_src(&cinfo, data, length);

	// read header
	jpeg_read_header(&cinfo, TRUE);

	// save size
	int width = cinfo.image_width;
	int height = cinfo.image_height;
	if(w != NULL)
		*w = width * scaleX;
	if(h != NULL)
		*h = height * scaleY;

	// if size only, we can return
	if(sizeOnly) {
		// This is an important step since it will release a good deal of memory
		jpeg_destroy_decompress(&cinfo);

		return NULL;
	} else {
		// set out color space
		cinfo.out_color_space = JCS_RGBA_8888;

		// start decompress
		jpeg_start_decompress(&cinfo);

		/* JSAMPLEs per row in output buffer */
		row_stride = cinfo.output_width * cinfo.output_components;

		/* Make a one-row-high sample array that will go away when done with image */
		buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
											JPOOL_IMAGE, row_stride, 1);

		// allocate returned buffer
		char* image_data = (char*)wyMalloc(height * row_stride * sizeof(char));
		char* tmp = image_data;

		/*
		 * Here we use the library's state variable cinfo.output_scanline as the
		 * loop counter, so that we don't have to keep track ourselves.
		 */
		while (cinfo.output_scanline < cinfo.output_height) {
			/*
			 * jpeg_read_scanlines expects an array of pointers to scanlines.
			 * Here the array is only one element long, but you could ask for
			 * more than one scanline at a time if that's more convenient.
			 */
			jpeg_read_scanlines(&cinfo, buffer, 1);

			// put to returned buffer
			memcpy(tmp, buffer[0], row_stride * sizeof(char));
			tmp += row_stride;
		}

		// Finish decompression
		jpeg_finish_decompress(&cinfo);

		// This is an important step since it will release a good deal of memory
		jpeg_destroy_decompress(&cinfo);

		// scale or not
		if(scaleX != 1.0f || scaleY != 1.f) {
			char* scaled = scaleImage(image_data, width, height, scaleX, scaleY);
			if(scaled != image_data) {
				wyFree(image_data);
				image_data = scaled;
			}
		}

		return image_data;
	}
	return NULL;
}

char* wyUtils::loadRaw(int resId, size_t* outLen, float* outScale, bool noDecode) {
	// get file path of this resource
	const char* fullPath = wyResMap::getInstance()->getResFilePath(resId);
	if(!fullPath)
		return NULL;

	// return scale
	if(outScale != NULL) {
		if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
			*outScale = wyDevice::density / wyDevice::defaultInDensity;
		else
			*outScale = 1;
	}

	// call internal method
	size_t retLen;
	char* ret = wyUtils_win::loadRaw(fullPath, &retLen);

	// decode or not?
	if(NULL != ret) {
		// check decoder flag
		if(!noDecode) {
			if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_RES))
				noDecode = true;
		}

		if(!noDecode) {
			const char* decoded = decodeObfuscatedData(ret, retLen, outLen);
			if(decoded != ret) {
				wyFree(ret);
				ret = (char*)decoded;
			}	
		} else {
			if(outLen)
				*outLen = retLen;
		}
	}

	return ret;
}

char* wyUtils::loadRaw(const char* path, bool isFile, size_t* outLen, bool noDecode) {
	// get full path
	const char* fullPath = NULL;
	if(isFile) {
		// check decoder flag
		if(!noDecode) {
			if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_FILE))
				noDecode = true;
		}

		fullPath = wyResMap::getInstance()->getLocalFilePath(path);
	} else {
		// check decoder flag
		if(!noDecode) {
			if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_ASSETS))
				noDecode = true;
		}

		fullPath = wyResMap::getInstance()->getAssetFilePath(path);
	}

	// check
	if(!fullPath)
		return NULL;

	// call internal method
	size_t retLen;
	char* ret = wyUtils_win::loadRaw(fullPath, &retLen);

	// decode or not?
	if(NULL != ret) {
		if(!noDecode) {
			const char* decoded = decodeObfuscatedData(ret, retLen, outLen);
			if(decoded != ret) {
				wyFree(ret);
				ret = (char*)decoded;
			}	
		} else {
			if(outLen)
				*outLen = retLen;
		}
	}

	return ret;
}

char* wyUtils_win::loadRaw(const char* path, size_t* outLen) {
	// open file
	FILE* f = NULL;
	if((f = fopen(path, "rb")) == NULL) {
		LOGW("open file %s failed: %s", path, strerror(errno));
		return NULL;
	}

	// get readable length
	size_t length = getFileSize(f);
	if(outLen)
		*outLen = length;

	// create buffer
	char* data = NULL;
	if ((data = (char*)wyMalloc(length)) == NULL) {
		LOGW("allocate data buffer failed");
		fclose(f);
		return NULL;
	}

	// read data
	if(fread(data, sizeof(char), length, f) != length) {
		LOGW("read data failed");
		fclose(f);
		wyFree(data);
		return NULL;
	}

	// close file
	fclose(f);

	return data;
}

char* wyUtils::loadCString(const char* path, bool isFile) {
	// get string
	size_t len;
	char* raw = loadRaw(path, isFile, &len);

	// append null terminator
	char* ret = (char*)wyMalloc(len + 1);
	memcpy(ret, raw, len);
	ret[len] = 0;

	// release old
	wyFree(raw);

	// return
	return ret;
}

char* wyUtils::loadCString(int resId) {
	// get string
	size_t len;
	char* raw = loadRaw(resId, &len);

	// append null terminator
	char* ret = (char*)wyMalloc(len + 1);
	memcpy(ret, raw, len);
	ret[len] = 0;

	// release old
	wyFree(raw);

	// return
	return ret;
}

char* wyUtils::scalePVR(wyPVRFormat format, char* originData, int originWidth, int originHeight, float scale) {
	return NULL;
}

char* wyUtils::scaleImage(char* originData, int originWidth, int originHeight, float scaleX, float scaleY) {
	// no scale? just return
	if(scaleX == 1.0f && scaleY == 1.0f)
		return originData;

	return ::scaleImage(SkBitmap::kARGB_8888_Config, originData, originWidth, originHeight, scaleX, scaleY);
}

const char* wyUtils::mapLocalPath(const char* path) {
	return copy(wyResMap::getInstance()->getLocalFilePath(path));
}

const char* wyUtils::mapAssetsPath(const char* path) {
	return copy(wyResMap::getInstance()->getAssetFilePath(path));
}

void wyUtils::playVideo(int resId) {

}

void wyUtils::playVideo(const char* path, bool isFile) {

}

void wyUtils::openUrl(const char* url) {
	ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
}

bool wyUtils::isPathExistent(const char* path) {
	if(path == NULL)
		return true;
	const char* mappedPath = mapLocalPath(path);
	DWORD dwAttrib = GetFileAttributes((LPCTSTR)mappedPath);
	bool ret = dwAttrib != INVALID_FILE_ATTRIBUTES;
	wyFree((void*)mappedPath);
	return ret;
}

bool wyUtils::isResExistent(const char* path, bool isFile) {
	if(isFile) {
		return isPathExistent(path);
	} else {
		const char* mappedPath = mapAssetsPath(path);
		DWORD dwAttrib = GetFileAttributes((LPCTSTR)mappedPath);
		bool ret = dwAttrib != INVALID_FILE_ATTRIBUTES;
		wyFree((void*)mappedPath);
		return ret;
	}
}

void wyUtils::addAndroidStrings(const char* fileName, const char* langId) {
	wyAndroidStrings::getInstance()->addStrings(fileName, langId);
}

#endif // #if WINDOWS
