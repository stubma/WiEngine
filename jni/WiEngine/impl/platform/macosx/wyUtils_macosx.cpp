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
#if MACOSX

#include "wyUtils_macosx.h"
#include "wyLog.h"
#include "wyDirector_macosx.h"
#import "WYResMap.h"
#import "WYAndroidStrings.h"
#import "FontLabelStringDrawing.h"
#import "FontManager.h"
#import "ZFont.h"
#import "UIKit.h"
#import <Carbon/Carbon.h>
#import <QTKit/QTKit.h>
#import "WYQTMovieView.h"
#import "WYAlertDelegate.h"
#import <fnmatch.h>

// global singleton
extern wyDirector_macosx* gDirector;
extern wyResourceDecoder* gResDecoder;

// count repeat
static int sKeyRepeatCount;

// Carbon keycode to wyKeyCode mapping
static int sKeyCodeMapping[][2] = {
	{ kVK_ANSI_A, KEYCODE_A }, //               = 0x00 
	{ kVK_ANSI_S, KEYCODE_S }, //               = 0x01
	{ kVK_ANSI_D, KEYCODE_D }, //               = 0x02
	{ kVK_ANSI_F, KEYCODE_F }, //               = 0x03
	{ kVK_ANSI_H, KEYCODE_H }, //               = 0x04
	{ kVK_ANSI_G, KEYCODE_G }, //               = 0x05
	{ kVK_ANSI_Z, KEYCODE_Z }, //               = 0x06
	{ kVK_ANSI_X, KEYCODE_X }, //               = 0x07
	{ kVK_ANSI_C, KEYCODE_C }, //               = 0x08
	{ kVK_ANSI_V, KEYCODE_V }, //               = 0x09
	{ kVK_ISO_Section, -1 }, //               = 0x0A
	{ kVK_ANSI_B, KEYCODE_B }, //               = 0x0B
	{ kVK_ANSI_Q, KEYCODE_Q }, //               = 0x0C
	{ kVK_ANSI_W, KEYCODE_W }, //               = 0x0D
	{ kVK_ANSI_E, KEYCODE_E }, //               = 0x0E
	{ kVK_ANSI_R, KEYCODE_R }, //               = 0x0F
	{ kVK_ANSI_Y, KEYCODE_Y }, //               = 0x10
	{ kVK_ANSI_T, KEYCODE_T }, //               = 0x11
	{ kVK_ANSI_1, KEYCODE_1 }, //               = 0x12
	{ kVK_ANSI_2, KEYCODE_2 }, //               = 0x13
	{ kVK_ANSI_3, KEYCODE_3 }, //               = 0x14
	{ kVK_ANSI_4, KEYCODE_4 }, //               = 0x15
	{ kVK_ANSI_6, KEYCODE_6 }, //               = 0x16
	{ kVK_ANSI_5, KEYCODE_5 }, //               = 0x17
	{ kVK_ANSI_Equal, KEYCODE_EQUALS }, //               = 0x18
	{ kVK_ANSI_9, KEYCODE_9 }, //               = 0x19
	{ kVK_ANSI_7, KEYCODE_7 }, //               = 0x1A
	{ kVK_ANSI_Minus, KEYCODE_MINUS }, //               = 0x1B
	{ kVK_ANSI_8, KEYCODE_8 }, //               = 0x1C
	{ kVK_ANSI_0, KEYCODE_0 }, //               = 0x1D
	{ kVK_ANSI_RightBracket, KEYCODE_RIGHT_BRACKET }, //               = 0x1E
	{ kVK_ANSI_O, KEYCODE_O }, //               = 0x1F
	{ kVK_ANSI_U, KEYCODE_U }, //               = 0x20
	{ kVK_ANSI_LeftBracket, KEYCODE_LEFT_BRACKET }, //               = 0x21
	{ kVK_ANSI_I, KEYCODE_I }, //               = 0x22
	{ kVK_ANSI_P, KEYCODE_P }, //               = 0x23
	{ kVK_Return, KEYCODE_ENTER }, //               = 0x24
	{ kVK_ANSI_L, KEYCODE_L }, //               = 0x25
	{ kVK_ANSI_J, KEYCODE_J }, //               = 0x26
	{ kVK_ANSI_Quote, -1 }, //               = 0x27
	{ kVK_ANSI_K, KEYCODE_K }, //               = 0x28
	{ kVK_ANSI_Semicolon, KEYCODE_SEMICOLON }, //               = 0x29
	{ kVK_ANSI_Backslash, KEYCODE_BACKSLASH }, //               = 0x2A
	{ kVK_ANSI_Comma, KEYCODE_COMMA }, //               = 0x2B
	{ kVK_ANSI_Slash, KEYCODE_SLASH }, //               = 0x2C
	{ kVK_ANSI_N, KEYCODE_N }, //               = 0x2D
	{ kVK_ANSI_M, KEYCODE_M }, //               = 0x2E
	{ kVK_ANSI_Period, KEYCODE_PERIOD }, //               = 0x2F
	{ kVK_Tab, KEYCODE_TAB }, //               = 0x30
	{ kVK_Space, KEYCODE_SPACE }, //               = 0x31
	{ kVK_ANSI_Grave, KEYCODE_GRAVE }, //               = 0x32
	{ kVK_Delete, KEYCODE_DEL }, //                 = 0x33,
	{ -1, -1 }, // no keycode in 0x34
	{ kVK_Escape, -1 }, //                    = 0x35,
	{ -1, -1 }, // no keycode in 0x36
	{ kVK_Command, -1 }, //                   = 0x37,
	{ kVK_Shift, KEYCODE_SHIFT_LEFT }, //                     = 0x38,
	{ kVK_CapsLock, -1 }, //                  = 0x39,
	{ kVK_Option, -1 }, //                    = 0x3A,
	{ kVK_Control, -1 }, //                   = 0x3B,
	{ kVK_RightShift, KEYCODE_SHIFT_RIGHT }, //                = 0x3C,
	{ kVK_RightOption, -1 }, //               = 0x3D,
	{ kVK_RightControl, -1 }, //              = 0x3E,
	{ kVK_Function, -1 }, //                  = 0x3F,
	{ kVK_F17, -1 }, //                       = 0x40,
	{ kVK_ANSI_KeypadDecimal, -1 }, //        = 0x41,
	{ -1, -1 }, // no keycode in 0x42
	{ kVK_ANSI_KeypadMultiply, KEYCODE_STAR }, //       = 0x43,
	{ -1, -1 }, // no keycode in 0x44
	{ kVK_ANSI_KeypadPlus, KEYCODE_PLUS }, //           = 0x45,
	{ -1, -1 }, // no keycode in 0x46
	{ kVK_ANSI_KeypadClear, KEYCODE_CLEAR }, //          = 0x47,
	{ kVK_VolumeUp, KEYCODE_VOLUME_UP }, //                  = 0x48,
	{ kVK_VolumeDown, KEYCODE_VOLUME_DOWN }, //                = 0x49,
	{ kVK_Mute, KEYCODE_MUTE }, //                      = 0x4A,
	{ kVK_ANSI_KeypadDivide, KEYCODE_SLASH }, //         = 0x4B,
	{ kVK_ANSI_KeypadEnter, KEYCODE_ENTER }, //          = 0x4C,
	{ -1, -1 }, // no keycode in 0x4D
	{ kVK_ANSI_KeypadMinus, KEYCODE_MINUS }, //          = 0x4E,
	{ kVK_F18, -1 }, //                       = 0x4F,
	{ kVK_F19, -1 }, //                       = 0x50,
	{ kVK_ANSI_KeypadEquals, KEYCODE_EQUALS }, //         = 0x51,
	{ kVK_ANSI_Keypad0, KEYCODE_0 }, //              = 0x52,
	{ kVK_ANSI_Keypad1, KEYCODE_1 }, //              = 0x53,
	{ kVK_ANSI_Keypad2, KEYCODE_2 }, //              = 0x54,
	{ kVK_ANSI_Keypad3, KEYCODE_3 }, //              = 0x55,
	{ kVK_ANSI_Keypad4, KEYCODE_4 }, //              = 0x56,
	{ kVK_ANSI_Keypad5, KEYCODE_5 }, //              = 0x57,
	{ kVK_ANSI_Keypad6, KEYCODE_6 }, //              = 0x58,
	{ kVK_ANSI_Keypad7, KEYCODE_7 }, //              = 0x59,
	{ kVK_F20, -1 }, //                       = 0x5A,
	{ kVK_ANSI_Keypad8, KEYCODE_8 }, //              = 0x5B,
	{ kVK_ANSI_Keypad9, KEYCODE_9 }, //              = 0x5C
	{ kVK_JIS_Yen, -1 }, //                   = 0x5D,
	{ kVK_JIS_Underscore, -1 }, //            = 0x5E,
	{ kVK_JIS_KeypadComma, KEYCODE_COMMA }, //           = 0x5F,
	{ kVK_F5, -1 }, //                        = 0x60,
	{ kVK_F6, -1 }, //                        = 0x61,
	{ kVK_F7, -1 }, //                        = 0x62,
	{ kVK_F3, -1 }, //                        = 0x63,
	{ kVK_F8, -1 }, //                        = 0x64,
	{ kVK_F9, -1 }, //                        = 0x65,
	{ kVK_JIS_Eisu, -1 }, //                  = 0x66,
	{ kVK_F11, -1 }, //                       = 0x67,
	{ kVK_JIS_Kana, -1 }, //                  = 0x68
	{ kVK_F13, -1 }, //                       = 0x69,
	{ kVK_F16, -1 }, //                       = 0x6A,
	{ kVK_F14, -1 }, //                       = 0x6B,
	{ -1, -1 }, // no keycode in 0x6C
	{ kVK_F10, -1 }, //                       = 0x6D,
	{ -1, -1 }, // no keycode in 0x6E
	{ kVK_F12, -1 }, //                       = 0x6F,
	{ -1, -1 }, // no keycode in 0x70
	{ kVK_F15, -1 }, //                       = 0x71,
	{ kVK_Help, -1 }, //                      = 0x72,
	{ kVK_Home, KEYCODE_HOME }, //                      = 0x73,
	{ kVK_PageUp, KEYCODE_PAGE_UP }, //                    = 0x74,
	{ kVK_ForwardDelete, KEYCODE_DEL }, //             = 0x75,
	{ kVK_F4, -1 }, //                        = 0x76,
	{ kVK_End, -1 }, //                       = 0x77,
	{ kVK_F2, -1 }, //                        = 0x78,
	{ kVK_PageDown, KEYCODE_PAGE_DOWN }, //                  = 0x79,
	{ kVK_F1, -1 }, //                        = 0x7A,
	{ kVK_LeftArrow, KEYCODE_DPAD_LEFT }, //                 = 0x7B,
	{ kVK_RightArrow, KEYCODE_DPAD_RIGHT }, //                = 0x7C,
	{ kVK_DownArrow, KEYCODE_DPAD_DOWN }, //                 = 0x7D,
	{ kVK_UpArrow, KEYCODE_DPAD_UP }, //                   = 0x7E
};

static const void* getBytePointerCallback(void* info) {
	return info;
}

NSSize wyUtils_macosx::measureText(NSString* text, NSFont* font, float lineWidth) {
	NSMutableParagraphStyle* mps = [[[NSMutableParagraphStyle alloc] init] autorelease];
	[mps setParagraphStyle:[NSParagraphStyle defaultParagraphStyle]];
	[mps setLineBreakMode:NSLineBreakByWordWrapping];
	return [text boundingRectWithSize:NSMakeSize(lineWidth, 100000)
							  options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading
						   attributes:[NSDictionary dictionaryWithObjectsAndKeys:font, NSFontAttributeName, 
									   mps, NSParagraphStyleAttributeName, nil]].size;
}

CGImageRef wyUtils_macosx::to_CGImage(NSImage* image) {
	NSData* cocoaData = [image TIFFRepresentation];
	CFDataRef carbonData = (CFDataRef)cocoaData;
	CGImageSourceRef imageSourceRef = CGImageSourceCreateWithData(carbonData, NULL);
	return CGImageSourceCreateImageAtIndex(imageSourceRef, 0, NULL);
}

char* wyUtils_macosx::loadNSImage(NSImage* image, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// check nil
	if(image == nil) {
		LOGW("loadPNG: NSImage is nil, can't load it");
		return NULL;
	}
	
	// calculate desired size
	// we must use image rep because NSImage always sample image in 72 dpi
	NSBitmapImageRep* rep = [[image representations] objectAtIndex:0];
	float width = [rep pixelsWide] * scaleX;
	float height = [rep pixelsHigh] * scaleY;
	if(w != NULL)
		*w = width;
	if(h != NULL)
		*h = height;
	
	// if size only, can return now
	if(sizeOnly) {
		return NULL;
	}
	
	CGImageRef CGImage = to_CGImage(image);
	CGImageAlphaInfo info = CGImageGetAlphaInfo(CGImage);
	BOOL hasAlpha = (info == kCGImageAlphaPremultipliedLast || info == kCGImageAlphaPremultipliedFirst || info == kCGImageAlphaLast || info == kCGImageAlphaFirst) ? YES : NO;
	
	/*
	 * WORKAROUND
	 * set hasAlpha to YES. It is a workaround for iPad. JPG image is abnormal after loading in
	 * iPad, but not in iPhone. Maybe a bug of iPad and force setting hasAlpha to YES solve this.
	 */
	hasAlpha = YES;
	
	// create a bitmap
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	void* data = wyMalloc(width * height * 4 * sizeof(char));
	info = hasAlpha ? kCGImageAlphaPremultipliedLast : kCGImageAlphaNoneSkipLast;
	CGContextRef context = CGBitmapContextCreate(data, width, height, 8, 4 * width, colorSpace, info | kCGBitmapByteOrder32Big);
	
	// draw original image to bitmap
	CGRect imageRect = CGRectMake(0, 0, width, height);
	CGContextClearRect(context, imageRect);
	CGContextDrawImage(context, imageRect, CGImage);
	
	// release
	CGContextRelease(context);
	CGColorSpaceRelease(colorSpace);
	CGImageRelease(CGImage);
	
	/*
	 * un-premultiplied because info is set to kCGImageAlphaPremultipliedLast
	 * if set kCGImageAlphaLast, CGBitmapContextCreate will fail so we choose
	 * un-premultiplied manually
	 */
	unsigned char* p = (unsigned char*)data;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			if(p[3] != 0) {
				p[0] = p[0] * 255 / p[3];
				p[1] = p[1] * 255 / p[3];
				p[2] = p[2] * 255 / p[3];
			}
			p += 4;
		}
	}
	
	// return
	return (char*)data;
}

const char* wyUtils_macosx::to_CString(NSString* s) {
	size_t len = [s lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
	char* buf = (char*)wyCalloc(len, sizeof(char));
	[s getCString:buf maxLength:len encoding:NSUTF8StringEncoding];
	return (const char*)buf;
}

void wyUtils_macosx::to_CString(char* buf, NSString* s) {
	size_t len = [s lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
	[s getCString:buf maxLength:len encoding:NSUTF8StringEncoding];
}

NSString* wyUtils_macosx::to_NSString(const char* text) {
	if(text == NULL)
		return nil;
	return [NSString stringWithCString:text encoding:NSUTF8StringEncoding];
}

void wyUtils_macosx::playVideo(NSString* path) {
	// get window thru gl view
	WYOpenGLView* glView = wyDirector::getInstance()->getGLView();
	NSWindow* window = [glView window];
	
	// create movie
	QTMovie* movie = [QTMovie movieWithFile:path error:nil];
	[movie setAttribute:[NSNumber numberWithBool:NO] forKey:QTMovieEditableAttribute];
	[movie setAttribute:[NSNumber numberWithBool:YES] forKey:QTMovieOpenForPlaybackAttribute];
	
	// create movie view
	WYQTMovieView* movieView = [[WYQTMovieView alloc] initWithFrame:[glView frame]];
	[movieView setMovie:movie];
	[movieView setShowsResizeIndicator:NO];
	[movieView setControllerVisible:NO];
	[window.contentView addSubview:movieView];
	
	// play
	[movieView play:nil];
}

void wyUtils::showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton, const char* negativeButton, wyTargetSelector* onOK, wyTargetSelector* onCancel) {
	// precondition checking
	if(gDirector == NULL || gDirector->getGLView() == NULL)
		return;
	
	// get button title
	NSString* cancelButtonTitle = wyUtils_macosx::to_NSString(negativeButton);
	NSString* okButtonTitle = wyUtils_macosx::to_NSString(positiveButton);
	const char* lan = wyDevice::getLanguage();
	if(cancelButtonTitle == nil) {
		if(!strcmp("zh", lan))
			cancelButtonTitle = @WY_CANCEL_ZH;
		else
			cancelButtonTitle = @WY_CANCEL_EN;
	}
	if(okButtonTitle == nil) {
		if(!strcmp("zh", lan))
			okButtonTitle = @WY_OK_ZH;
		else
			okButtonTitle = @WY_OK_EN;
	}
	
	// create alert
	NSAlert* alert = [NSAlert alertWithMessageText:wyUtils_macosx::to_NSString(title)
									 defaultButton:okButtonTitle
								   alternateButton:cancelButtonTitle
									   otherButton:nil
						 informativeTextWithFormat:wyUtils_macosx::to_NSString(msg)];
	
	// show alert
	[alert beginSheetModalForWindow:[gDirector->getGLView() window]
					  modalDelegate:[[WYAlertDelegate alloc] initWithOKTargetSelector:onOK andCancel:onCancel]
					 didEndSelector:@selector(alertDidEnd:returnCode:contextInfo:) 
						contextInfo:nil];
}

void wyUtils::showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton, wyTargetSelector* onOK) {
	// precondition checking
	if(gDirector == NULL || gDirector->getGLView() == NULL)
		return;
	
	// get button title
	NSString* okButtonTitle = wyUtils_macosx::to_NSString(positiveButton);
	const char* lan = wyDevice::getLanguage();
	if(okButtonTitle == nil) {
		if(!strcmp("zh", lan))
			okButtonTitle = @WY_OK_ZH;
		else
			okButtonTitle = @WY_OK_EN;
	}
	
	// create alert
	NSAlert* alert = [NSAlert alertWithMessageText:wyUtils_macosx::to_NSString(title)
									 defaultButton:okButtonTitle
								   alternateButton:nil
									   otherButton:nil
						 informativeTextWithFormat:wyUtils_macosx::to_NSString(msg)];
	
	// show alert
	[alert beginSheetModalForWindow:[gDirector->getGLView() window]
					  modalDelegate:[[WYAlertDelegate alloc] initWithOKTargetSelector:onOK andCancel:nil]
					 didEndSelector:@selector(alertDidEnd:returnCode:contextInfo:) 
						contextInfo:nil];
}

void wyUtils::convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event) {
	// key code
	event->carbonKeyCode = [pe keyCode];
	event->keyCode = (wyKeyCode)sKeyCodeMapping[event->carbonKeyCode][1];
	
	// repeat count
	if([pe isARepeat]) {
		sKeyRepeatCount++;
	} else {
		sKeyRepeatCount = 0;
	}
	event->repeatCount = sKeyRepeatCount;
	
	// down time
	event->downTime = [pe timestamp];
	event->eventTime = [pe timestamp];
	
	// modifier flags
	NSUInteger flags = [pe modifierFlags];
	if(flags & NSAlphaShiftKeyMask)
		event->modifierFlags |= WY_CAPSLOCK;
	if(flags & NSShiftKeyMask)
		event->modifierFlags |= WY_SHIFT;
	if(flags & NSControlKeyMask)
		event->modifierFlags |= WY_CTRL;
	if(flags & NSAlternateKeyMask)
		event->modifierFlags |= WY_ALT;
	if(flags & NSCommandKeyMask)
		event->modifierFlags |= WY_COMMAND;
}

void wyUtils::convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type) {
	// pointer count always 1
	event->pointerCount = 1;
	
	// index always 0
	event->index = 0;
	
	// pid always 0
	event->pid[0] = 0;
	
	// position
	wyGLSurfaceView v = wyDirector::getInstance()->getGLView();
	NSPoint loc = [pe locationInWindow];
	loc = [v convertPoint:loc fromView:nil];
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY) {
		event->x[0] = loc.x;
		event->y[0] = loc.y;
	} else {
        event->x[0] = loc.x * wyDevice::density / wyDevice::baseScaleX;
        event->y[0] = loc.y * wyDevice::density / wyDevice::baseScaleY;
	}
	
	// modifier flags
	NSUInteger flags = [pe modifierFlags];
	if(flags & NSAlphaShiftKeyMask)
		event->modifierFlags |= WY_CAPSLOCK;
	if(flags & NSShiftKeyMask)
		event->modifierFlags |= WY_SHIFT;
	if(flags & NSControlKeyMask)
		event->modifierFlags |= WY_CTRL;
	if(flags & NSAlternateKeyMask)
		event->modifierFlags |= WY_ALT;
	if(flags & NSCommandKeyMask)
		event->modifierFlags |= WY_COMMAND;
}

void wyUtils::makeScreenshotPNG(const char* path, wyRect rect) {
	// read gl buffer
	size_t length = rect.width * rect.height * sizeof(int);
	GLubyte* buffer = (GLubyte*)wyMalloc(length);
	glReadPixels(rect.x, rect.y, rect.width, rect.height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	
    int width = rect.width;
    int height = rect.height;
	
	// gl renders "upside down" so swap top to bottom into new array.
    // there's gotta be a better way, but this works.
    GLubyte* buffer2 = (GLubyte*)wyMalloc(length);
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width * 4; x++) {
            buffer2[(height - 1 - y) * width * 4 + x] = buffer[y * 4 * width + x];
        }
    }
	
    // make data provider with data.
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer2, length, NULL);
	
    // prep the ingredients
    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = 4 * width;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
	
    // make the cgimage
    CGImageRef imageRef = CGImageCreate(width,
										height,
										bitsPerComponent,
										bitsPerPixel,
										bytesPerRow,
										colorSpaceRef,
										bitmapInfo,
										provider,
										NULL,
										NO,
										renderingIntent);
	
    // then create a bitmap representation from CGImage
	NSBitmapImageRep* rep = [[[NSBitmapImageRep alloc] initWithCGImage:imageRef] autorelease];
	
	// save to path
	const char* mappedPath = mapLocalPath(path);
	NSData* data = [rep representationUsingType:NSPNGFileType 
									 properties:[NSDictionary dictionary]];
	NSString* p = [NSString stringWithCString:mappedPath encoding:NSUTF8StringEncoding];
	NSFileManager* fm = [NSFileManager defaultManager];
	[fm createDirectoryAtPath:[p stringByDeletingLastPathComponent]
  withIntermediateDirectories:YES
				   attributes:nil
						error:NULL];
	[data writeToFile:p atomically:YES];
	
	// release
	wyFree((void*)mappedPath);
	wyFree(buffer2);
	CGColorSpaceRelease(colorSpaceRef);
	CGDataProviderRelease(provider);
	CGImageRelease(imageRef);
	
	// free buffer
	wyFree(buffer);
}

void wyUtils::makeScreenshotJPG(const char* path, wyRect rect) {
	size_t length = rect.width * rect.height * sizeof(int);
	GLubyte* buffer = (GLubyte*)wyMalloc(length);
	glReadPixels(rect.x, rect.y, rect.width, rect.height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	
	int width = rect.width;
    int height = rect.height;
	
	// gl renders "upside down" so swap top to bottom into new array.
    // there's gotta be a better way, but this works.
    GLubyte* buffer2 = (GLubyte*)wyMalloc(length);
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width * 4; x++) {
            buffer2[(height - 1 - y) * width * 4 + x] = buffer[y * 4 * width + x];
        }
    }
	
    // make data provider with data.
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer2, length, NULL);
	
    // prep the ingredients
    int bitsPerComponent = 8;
    int bitsPerPixel = 32;
    int bytesPerRow = 4 * width;
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
	
    // make the cgimage
    CGImageRef imageRef = CGImageCreate(width,
										height,
										bitsPerComponent,
										bitsPerPixel,
										bytesPerRow,
										colorSpaceRef,
										bitmapInfo,
										provider,
										NULL,
										NO,
										renderingIntent);
	
    // then create a bitmap representation from CGImage
	NSBitmapImageRep* rep = [[[NSBitmapImageRep alloc] initWithCGImage:imageRef] autorelease];
	
	// save to path
	const char* mappedPath = mapLocalPath(path);
	NSData* data = [rep representationUsingType:NSJPEGFileType 
									 properties:[NSDictionary dictionaryWithObject:[NSNumber numberWithFloat:0.8f] forKey:NSImageCompressionFactor]];
	NSString* p = [NSString stringWithCString:mappedPath encoding:NSUTF8StringEncoding];
	NSFileManager* fm = [NSFileManager defaultManager];
	[fm createDirectoryAtPath:[p stringByDeletingLastPathComponent]
  withIntermediateDirectories:YES
				   attributes:nil
						error:NULL];
	[data writeToFile:p atomically:YES];
	
	// release
	wyFree((void*)mappedPath);
    wyFree(buffer2);
	CGColorSpaceRelease(colorSpaceRef);
	CGDataProviderRelease(provider);
	CGImageRelease(imageRef);
	
	wyFree(buffer);
}

int wyUtils::getResId(const char* fullName) {
	NSString* name = [NSString stringWithCString:fullName encoding:NSUTF8StringEncoding];
	return [[WYResMap sharedMap] getResId:name];
}

int wyUtils::getResId(const char* name, const char* type, const char* type2) {
	// process name, remove ext and replace slash
	char* p = strrchr(name, '.');
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
	NSString* s = [NSString stringWithCString:buf encoding:NSUTF8StringEncoding];
	resId = [[WYResMap sharedMap] getResId:s];
	if(resId == -1 && type2 != NULL) {
		sprintf(buf, "R.%s.%s", type2, tmp);
		s = [NSString stringWithCString:buf encoding:NSUTF8StringEncoding];
		resId = [[WYResMap sharedMap] getResId:s];
	}
	
	// free
	wyFree(tmp);
	
	return resId;
}

const char* wyUtils::getString(int resId) {
	NSString* key = [[WYAndroidStrings sharedInstance] getKey:resId];
	NSString* str = [[WYAndroidStrings sharedInstance] getString:key];
	if(str == nil)
		return NULL;
	else
		return wyUtils_macosx::to_CString(str);
}

const char16_t* wyUtils::getString16(int resId) {
	NSString* key = [[WYAndroidStrings sharedInstance] getKey:resId];
	NSString* str = [[WYAndroidStrings sharedInstance] getString:key];
	if(str == nil)
		return NULL;
	else {
		size_t len = [str length] + 1;
		char16_t* buf = (char16_t*)wyMalloc(len * sizeof(char16_t));
		[str getCharacters:buf range:NSMakeRange(0, len - 1)];
		buf[len - 1] = 0;
		return buf;
	}
}

const char* wyUtils::utf16toutf8(const char16_t* s16) {
	char* s8 = NULL;
	
	if(s16 == NULL) {
		s8 = (char*)wyCalloc(1, sizeof(char));
	} else {
		size_t len = strlen16(s16);
		CFStringRef s = CFStringCreateWithBytes(kCFAllocatorDefault,
												(const UInt8*)s16,
												len * 2,
												kCFStringEncodingUTF16,
												NO);
		s8 = (char*)wyCalloc(len * 4 + 1, sizeof(char));
		CFStringGetCString(s, s8, len * 4 + 1, kCFStringEncodingUTF8);
		CFRelease(s);
	}
	
	return (const char*)s8;
}

const char16_t* wyUtils::toUTF16(const char* s8) {
	char16_t* s16 = NULL;
	if(s8 == NULL) {
		s16 = (char16_t*)wyCalloc(1, sizeof(char16_t));
	} else {
		CFStringRef s = CFStringCreateWithBytes(kCFAllocatorDefault,
												(const UInt8*)s8,
												strlen(s8),
												kCFStringEncodingUTF8,
												NO);
		CFIndex len = CFStringGetLength(s);
		s16 = (char16_t*)wyCalloc(len + 1, sizeof(char16_t));
		CFStringGetCharacters(s, CFRangeMake(0, len), (UniChar*)s16);
		CFRelease(s);
	}
	
	return s16;
}

const char* wyUtils::wctoutf8(const wchar_t* ws) {
	char* s8 = NULL;

	if(ws == NULL) {
		s8 = (char*)wyCalloc(1, sizeof(char));
	} else {
		size_t len = strlenW(ws);
		CFStringRef s = CFStringCreateWithBytes(kCFAllocatorDefault,
												(const UInt8*)ws,
												len * sizeof(wchar_t),
#if BYTE_ORDER == BIG_ENDIAN
                                                kCFStringEncodingUTF32BE,
#else
												kCFStringEncodingUTF32LE,
#endif
												NO);
		s8 = (char*)wyCalloc(len * 4 + 1, sizeof(char));
		CFStringGetCString(s, s8, len * 4 + 1, kCFStringEncodingUTF8);
		CFRelease(s);
	}

	return (const char*)s8;
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile, float width) {
	if(fontPath == NULL) {
		return calculateTextSize(text, fontSize, NORMAL, NULL, width);
	} else {
		// load ttf
		const char* path = NULL;
		if(isFile)
			path = mapLocalPath(fontPath);
		else
			path = mapAssetsPath(fontPath);
		NSString* fp = wyUtils_macosx::to_NSString(path);
		free((void*)path);
		ZFont* font = [[FontManager sharedManager] zFontWithURL:[NSURL fileURLWithPath:fp] 
													  pointSize:fontSize];
		
		// measure the string
		NSString* s = [NSString stringWithUTF8String:text];
		if(width <= 0)
			width = MAX_FLOAT;
		CGSize size = [s sizeWithZFont:font
					 constrainedToSize:CGSizeMake(width, MAX_FLOAT)
						 lineBreakMode:UILineBreakModeWordWrap];
		return wys(size.width, size.height);
	}
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width) {
	// create font
	NSString* fn = nil;
	if(fontName == NULL)
		fontName = WY_DEFAULT_FONT;
	switch(style) {
		case NORMAL:
			fn = [NSString stringWithFormat:@"%s", fontName];
			break;
		case BOLD:
			fn = [NSString stringWithFormat:@"%s-Bold", fontName];
			break;
		case ITALIC:
			fn = [NSString stringWithFormat:@"%s-Italic", fontName];
			break;
		case BOLD_ITALIC:
			fn = [NSString stringWithFormat:@"%s-BoldItalic", fontName];
			break;
	}
	NSFont* font = [NSFont fontWithName:fn size:fontSize];
	if(font == nil) {
		LOGW("calculateTextSize: Can't create font for name: %s", fontName);
		return wysZero;
	}
	
	// measure the string
	NSString* s = [NSString stringWithUTF8String:text];
	if(width <= 0)
		width = MAX_FLOAT;
	CGSize size = [s sizeWithZFont:[ZFont fontWithNSFont:font]
				 constrainedToSize:CGSizeMake(width, MAX_FLOAT)
					 lineBreakMode:UILineBreakModeWordWrap];
	return wys(size.width, size.height);
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	if(fontPath == NULL) {
		return createLabelBitmap(text, fontSize, NORMAL, NULL, width, alignment);
	} else {
		// load ttf
		const char* path = NULL;
		if(isFile)
			path = mapLocalPath(fontPath);
		else
			path = mapAssetsPath(fontPath);
		NSString* fp = wyUtils_macosx::to_NSString(path);
		free((void*)path);
		ZFont* font = [[FontManager sharedManager] zFontWithURL:[NSURL fileURLWithPath:fp] 
													  pointSize:fontSize];
		
		// measure the string
		NSString* s = [NSString stringWithUTF8String:text];
		if(width <= 0)
			width = MAX_FLOAT;
		CGSize size = [s sizeWithZFont:font
					 constrainedToSize:CGSizeMake(width, MAX_FLOAT)
						 lineBreakMode:UILineBreakModeWordWrap];
		
		// get POT size
		int potWidth = wyMath::getNextPOT(size.width);
		int potHeight = wyMath::getNextPOT(size.height);
		
		// create context
		CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
		void* data = wyCalloc(potHeight, potWidth * 4 * sizeof(char));
		CGContextRef context = CGBitmapContextCreate(data,
													 potWidth,
													 potHeight,
													 8,
													 4 * potWidth,
													 colorSpace,
													 kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
		
		// check nil
		if(!context) {
			wyFree(data);
			CGColorSpaceRelease(colorSpace);
			return NULL;
		}
		
		// NSString draws in UIKit referential i.e. renders upside-down compared to CGBitmapContext referential, so need translate with height and inverse y axis
		CGContextSetGrayFillColor(context, 1.0f, 1.0f);
		CGContextTranslateCTM(context, 0.0f, potHeight);
		CGContextScaleCTM(context, 1.0f, -1.0f);
		
		// alignment
		UITextAlignment align = UITextAlignmentLeft;
		switch(alignment) {
			case wyTexture2D::LEFT:
				align = UITextAlignmentLeft;
				break;
			case wyTexture2D::CENTER:
				align = UITextAlignmentCenter;
				break;
			case wyTexture2D::RIGHT:
				align = UITextAlignmentRight;
				break;
		}
		
		// draw
		[s drawInRect:CGRectMake(0, 0, size.width, size.height)
			withZFont:font
		lineBreakMode:UILineBreakModeWordWrap
			alignment:align
			  context:context];
		
		// release
		CGColorSpaceRelease(colorSpace);
		CGContextRelease(context);
		
		// return
		return (char*)data;
	}
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	// create font
	NSString* fn = nil;
	if(fontName == NULL)
		fontName = "Verdana";
	switch(style) {
		case NORMAL:
			fn = [NSString stringWithFormat:@"%s", fontName];
			break;
		case BOLD:
			fn = [NSString stringWithFormat:@"%s-Bold", fontName];
			break;
		case ITALIC:
			fn = [NSString stringWithFormat:@"%s-Italic", fontName];
			break;
		case BOLD_ITALIC:
			fn = [NSString stringWithFormat:@"%s-BoldItalic", fontName];
			break;
	}
	NSFont* f = [NSFont fontWithName:fn size:fontSize];
	if(f == nil) {
		LOGW("createLabelBitmap: Can't create font for name: %s", fontName);
		return NULL;
	}
	
	// measure the string
	ZFont* font = [ZFont fontWithNSFont:f];
	NSString* s = [NSString stringWithUTF8String:text];
	if(width <= 0)
		width = MAX_FLOAT;
	CGSize size = [s sizeWithZFont:font
				 constrainedToSize:CGSizeMake(width, MAX_FLOAT)
					 lineBreakMode:UILineBreakModeWordWrap];
	
	// get POT size
	int potWidth = wyMath::getNextPOT(size.width);
	int potHeight = wyMath::getNextPOT(size.height);
	
	// create context
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	void* data = wyCalloc(potHeight, potWidth * 4 * sizeof(char));
	CGContextRef context = CGBitmapContextCreate(data,
												 potWidth,
												 potHeight,
												 8,
												 4 * potWidth,
												 colorSpace,
												 kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
	
	// check nil
	if(!context) {
		wyFree(data);
		CGColorSpaceRelease(colorSpace);
		return NULL;
	}
	
	// NSString draws in UIKit referential i.e. renders upside-down compared to CGBitmapContext referential, so need translate with height and inverse y axis
	CGContextSetGrayFillColor(context, 1.0f, 1.0f);
	CGContextTranslateCTM(context, 0.0f, potHeight);
	CGContextScaleCTM(context, 1.0f, -1.0f);
	
	// alignment
	UITextAlignment align = UITextAlignmentLeft;
	switch(alignment) {
		case wyTexture2D::LEFT:
			align = UITextAlignmentLeft;
			break;
		case wyTexture2D::CENTER:
			align = UITextAlignmentCenter;
			break;
		case wyTexture2D::RIGHT:
			align = UITextAlignmentRight;
			break;
	}
	
	// draw
	[s drawInRect:CGRectMake(0, 0, size.width, size.height)
		withZFont:font
	lineBreakMode:UILineBreakModeWordWrap
		alignment:align
		  context:context];
	
	// release
	CGColorSpaceRelease(colorSpace);
	CGContextRelease(context);
	
	// return
	return (char*)data;
}

bool wyUtils::deleteFile(const char* path) {
	const char* mappedPath = mapLocalPath(path);
	NSString* p = wyUtils_macosx::to_NSString(mappedPath);
	NSFileManager* fm = [NSFileManager defaultManager];
	NSError* error = nil;
	[fm removeItemAtPath:p error:&error];
	wyFree((void*)mappedPath);
	return error == nil;
}

bool wyUtils::createFolder(const char* path) {
	const char* mappedPath = mapLocalPath(path);
	bool ret = mkdir(path) == 0;
	wyFree((void*)mappedPath);
	return ret;
}

char* wyUtils::loadBMP(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	NSImage* image = [[[NSImage alloc] initWithData:[NSData dataWithBytes:data length:length]] autorelease];
	if(image == nil) {
		LOGW("loadBMP: failed to create NSImage from data");
		return NULL;
	}
	
	return wyUtils_macosx::loadNSImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadPNG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	NSImage* image = [[[NSImage alloc] initWithData:[NSData dataWithBytes:data length:length]] autorelease];
	if(image == nil) {
		LOGW("loadPNG: failed to create NSImage from data");
		return NULL;
	}
	
	return wyUtils_macosx::loadNSImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadJPG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	NSImage* image = [[[NSImage alloc] initWithData:[NSData dataWithBytes:data length:length]] autorelease];
	if(image == nil) {
		LOGW("loadJPG: failed to create NSImage from data");
		return NULL;
	}
	
	return wyUtils_macosx::loadNSImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadRaw(int resId, size_t* outLen, float* outScale, bool noDecode) {
	// get file path, if nil, return NULL
	NSString* path = [[WYResMap sharedMap] getResFilePath:resId];
	if(path == nil) {
		LOGW("loadRaw: Failed to map res id: %d", resId);
		return NULL;
	}

	NSData* data = [NSData dataWithContentsOfFile:path];
	if(outLen != NULL) {
		*outLen = [data length];
	}
	if(outScale != NULL) {
		if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
			*outScale = wyDevice::density / wyDevice::defaultInDensity;
		else
			*outScale = 1;
	}
	char* ret = (char*)wyMalloc([data length] * sizeof(char));
	[data getBytes:ret length:[data length]];
	
	// check decoder flag
	if(!noDecode) {
		if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_RES))
			noDecode = true;
	}

	// decode data
	if(!noDecode) {
		const char* decoded = decodeObfuscatedData(ret, [data length], outLen);
		if(decoded != ret) {
			wyFree(ret);
			ret = (char*)decoded;
		}	
	}
	
	return ret;
}

char* wyUtils::loadRaw(const char* path, bool isFile, size_t* outLen, bool noDecode) {
	// get mapped path
	NSString* mappedPath = nil;
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
	if(isFile) {
		// check decoder flag
		if(!noDecode) {
			if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_FILE))
				noDecode = true;
		}

		mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath];
	} else {
		// check decoder flag
		if(!noDecode) {
			if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_ASSETS))
				noDecode = true;
		}

		mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
	}
	
	// is nil?
	if(mappedPath == nil) {
		LOGW("loadRaw: can't map android path %s", path);
		return NULL;
	}
	
	// load data from file path
	NSData* data = [NSData dataWithContentsOfFile:mappedPath];
	if(outLen != NULL) {
		*outLen = [data length];
	}
	char* ret = (char*)wyMalloc([data length] * sizeof(char));
	[data getBytes:ret length:[data length]];
	
	// decode data
	if(!noDecode) {
		const char* decoded = decodeObfuscatedData(ret, [data length], outLen);
		if(decoded != ret) {
			wyFree(ret);
			ret = (char*)decoded;
		}	
	}
	
	return ret;
}

char* wyUtils::loadCString(const char* path, bool isFile) {
	size_t len;
	char* data = loadRaw(path, isFile, &len);
	
	// create buffer
	char* ret = NULL;
	if ((ret = (char*)wyMalloc(len + 1)) == NULL) {
		LOGW("allocate data buffer failed");
		return NULL;
	}
	
	// copy
	memcpy(ret, data, len);
	ret[len] = 0;
	
	// free raw
	wyFree(data);
	
	// return c string
	return ret;
}

char* wyUtils::loadCString(int resId) {
	size_t len;
	char* data = loadRaw(resId, &len);
	
	// create buffer
	char* ret = NULL;
	if ((ret = (char*)wyMalloc(len + 1)) == NULL) {
		LOGW("allocate data buffer failed");
		return NULL;
	}
	
	// copy
	memcpy(ret, data, len);
	ret[len] = 0;
	
	// free raw
	wyFree(data);
	
	// return c string
	return ret;
}

char* wyUtils::scaleImage(char* originData, int originWidth, int originHeight, float scaleX, float scaleY) {
	// no scale? just return
	if(scaleX == 1.0f && scaleY == 1.0f)
		return originData;
	
	// calculate desired size
	int width = originWidth * scaleX;
	int height = originHeight * scaleY;
	
	// get CGImage info
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	static CGDataProviderDirectCallbacks callback = {
		0,
		getBytePointerCallback,
		NULL,
		NULL,
		NULL,
	};
	CGDataProviderRef provider = CGDataProviderCreateDirect(originData, 4 * originHeight * originWidth, &callback);
	CGImageRef CGImage = CGImageCreate(originWidth,
									   originHeight,
									   8,
									   32,
									   4 * originWidth, colorSpace,
									   kCGImageAlphaLast | kCGBitmapByteOrder32Big,
									   provider,
									   NULL,
									   NO,
									   kCGRenderingIntentDefault);
	
	// create a bitmap
	void* data = wyMalloc(width * height * 4 * sizeof(char));
	CGContextRef context = CGBitmapContextCreate(data, width, height, 8, 4 * width, colorSpace, kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
	
	// draw original image to bitmap
	CGRect imageRect = CGRectMake(0, 0, width, height);
	CGContextClearRect(context, imageRect);
	CGContextDrawImage(context, imageRect, CGImage);
	
	// release
	CGContextRelease(context);
	CGColorSpaceRelease(colorSpace);
	CGDataProviderRelease(provider);
	CGImageRelease(CGImage);
	
	/*
	 * un-premultiplied because info is set to kCGImageAlphaPremultipliedLast
	 * if set kCGImageAlphaLast, CGBitmapContextCreate will fail so we choose
	 * un-premultiplied manually
	 */
	unsigned char* p = (unsigned char*)data;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			if(p[3] != 0) {
				p[0] = p[0] * 255 / p[3];
				p[1] = p[1] * 255 / p[3];
				p[2] = p[2] * 255 / p[3];
			}
			p += 4;
		}
	}
	
	// return
	return (char*)data;
}

const char* wyUtils::mapLocalPath(const char* path) {
	// get mapped path
	NSString* mappedPath = nil;
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
	mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath checkExistence:NO];
	
	// is nil?
	if(mappedPath == nil) {
		LOGW("mapLocalPath: can't map path %s", path);
		return NULL;
	} else {
		return wyUtils_macosx::to_CString(mappedPath);
	}
}

const char* wyUtils::mapAssetsPath(const char* path) {
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
	NSString* mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
	
	// is nil?
	if(mappedPath == nil) {
		LOGW("mapAssetsPath: can't map path %s", path);
		return NULL;
	} else {
		return wyUtils_macosx::to_CString(mappedPath);
	}
}

void wyUtils::playVideo(int resId) {
	// get file path, if nil, return NULL
	NSString* fullPath = [[WYResMap sharedMap] getResFilePath:resId];
	if(fullPath == nil) {
		LOGW("playVideo: Failed to map res id: %d", resId);
		return;
	}
	
	// get video full path and play
	wyUtils_macosx::playVideo(fullPath);
}

void wyUtils::playVideo(const char* path, bool isFile) {
	// get mapped path
	NSString* mappedPath = nil;
	NSString* nsPath = [NSString stringWithCString:path encoding:NSUTF8StringEncoding];
	if(isFile) {
		mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath];
	} else {
		mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
	}
	
	// is nil?
	if(mappedPath == nil) {
		LOGW("playVideo: can't map mac path %s", path);
		return;
	}
	
	// play
	wyUtils_macosx::playVideo(mappedPath);
}

void wyUtils::openUrl(const char* url) {
	[NSApp openURL:[NSURL URLWithString:wyUtils_macosx::to_NSString(url)]];
}

bool wyUtils::isPathExistent(const char* path) {
	if(path == NULL)
		return true;
	const char* mappedPath = mapLocalPath(path);
	bool ret = [[NSFileManager defaultManager] fileExistsAtPath:wyUtils_macosx::to_NSString(mappedPath)];
	wyFree((void*)mappedPath);
	return ret;
}

bool wyUtils::isResExistent(const char* path, bool isFile) {
	if(isFile) {
		return isPathExistent(path);
	} else {
		const char* mappedPath = mapAssetsPath(path);
		bool ret = [[NSFileManager defaultManager] fileExistsAtPath:wyUtils_macosx::to_NSString(mappedPath)];
		wyFree((void*)mappedPath);
		return ret;
	}
}

void wyUtils::addAndroidStrings(const char* fileName, const char* langId) {
    NSString* nsFileName = wyUtils_macosx::to_NSString(fileName);
    NSString* nsLangId = wyUtils_macosx::to_NSString(langId);
    [[WYAndroidStrings sharedInstance] addStrings:nsFileName forLanguage:nsLangId];
}

const char** wyUtils::listAssetFiles(const char* path, size_t* outLen, const char* pattern) {
    // get subpaths
    NSFileManager* fm = [NSFileManager defaultManager];
    const char* mappedPath = mapAssetsPath(path);
    NSString* nsPath = wyUtils_macosx::to_NSString(mappedPath);
    wyFree((void*)mappedPath);
    NSArray* subpaths = [fm contentsOfDirectoryAtPath:nsPath error:nil];
    
    // allocate returned array
    int maxSize = subpaths == nil ? 0 : (int)[subpaths count];
    char** files = (char**)malloc(sizeof(char*) * maxSize);
    int count = 0;
    
    // check every path
    if(subpaths != nil) {
        for(NSString* path in subpaths) {
            const char* cPath = [path cStringUsingEncoding:NSUTF8StringEncoding];
            if(!pattern || fnmatch(pattern, cPath, 0) == 0) {
                int len = (int)[path lengthOfBytesUsingEncoding:NSUTF8StringEncoding];
                files[count] = (char*)calloc(sizeof(char), len + 1);
                memcpy(files[count], cPath, len);
                count++;
            }
        }
    }
    
    // save count
    if(outLen)
        *outLen = count;
    
    return (const char**)files;
}

#endif // #if MACOSX
