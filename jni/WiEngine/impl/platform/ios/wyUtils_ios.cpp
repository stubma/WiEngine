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
#if IOS

#include "wyDevice.h"
#include "wyUtils_ios.h"
#include "wyEventDispatcher_ios.h"
#include "wyTargetSelector.h"
#import <UIKit/UIKit.h>
#import "WYResMap.h"
#import "WYAndroidStrings.h"
#import "FontLabelStringDrawing.h"
#import "FontManager.h"
#import "ZFont.h"
#import "WYMoviePlayerWrapper.h"
#import "WYConfirmDialogDelegate.h"
#import "WYUIEvent.h"
#import "WYUITouch.h"

// global decoder
extern wyResourceDecoder* gResDecoder;

static const void* getBytePointerCallback(void* info) {
	return info;
}

float wyUtils_ios::getScaleModifier(NSString* path) {
	path = [path stringByDeletingPathExtension];
	size_t len = [path length];
	if([path characterAtIndex:len - 1] == 'x') {
		NSRange range = [path rangeOfString:path options:NSBackwardsSearch];
		if(range.location != NSNotFound) {
			NSString* value = [path substringWithRange:NSMakeRange(range.location + 1, len - range.location + 1)];
			return [value floatValue];
		}
	}

	return 1;
}

float wyUtils_ios::getDensity(NSString* fileName) {
    float inDensity = 1.0f;
    NSString* pureName = [fileName stringByDeletingPathExtension];
    NSString* nameWithoutDeviceModifier = pureName;

    // remove device modifier
    if([pureName hasSuffix:@"~ipad"]) {
        nameWithoutDeviceModifier = [pureName substringToIndex:([pureName rangeOfString:@"~ipad" options:(NSBackwardsSearch)].location)];
    } else if([pureName hasSuffix:@"~iphone"]) {
        nameWithoutDeviceModifier = [pureName substringToIndex:([pureName rangeOfString:@"~iphone" options:(NSBackwardsSearch)].location)];
    }

    for(int i = 2; i < 10; ++i ) {
        NSString* scaleModifier = [NSString stringWithFormat:@"@%dx", i];
        if([nameWithoutDeviceModifier hasSuffix:scaleModifier]) {
            inDensity = i;
            break;
        }
    }

    return inDensity;
}

char* wyUtils_ios::loadUIImage(UIImage* image, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY) {
	// check nil
	if(image == nil) {
		LOGW("loadPNG: UIImage is nil, can't load it");
		return NULL;
	}

	// calculate desired size
	int width = image.size.width * (wyDevice::apiLevel >= 400 ? image.scale : 1.f) * scaleX;
	int height = image.size.height * (wyDevice::apiLevel >= 400 ? image.scale : 1.f) * scaleY;
	if(w != NULL)
		*w = width;
	if(h != NULL)
		*h = height;

	// if size only, can return now
	if(sizeOnly) {
		return NULL;
	}

	// get CGImage info
	CGImageRef CGImage = image.CGImage;
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

const char* wyUtils_ios::to_CString(NSString* s) {
    if(!s)
        return NULL;
    
	size_t len = [s lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
	char* buf = (char*)wyCalloc(len, sizeof(char));
	[s getCString:buf maxLength:len encoding:NSUTF8StringEncoding];
	return (const char*)buf;
}

void wyUtils_ios::to_CString(char* buf, NSString* s) {
    if(!s) {
        buf[0] = 0;
        return;
    }
    
	size_t len = [s lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
	[s getCString:buf maxLength:len encoding:NSUTF8StringEncoding];
}

NSString* wyUtils_ios::to_NSString(const char* text) {
	if(text == NULL)
		return nil;
	return [NSString stringWithCString:text encoding:NSUTF8StringEncoding];
}

UIViewController* wyUtils_ios::findViewController(UIView* view) {
	for (UIView* next = [view superview]; next; next = next.superview) {
		UIResponder* nextResponder = [next nextResponder];
		if ([nextResponder isKindOfClass:[UIViewController class]]) {
			return (UIViewController*)nextResponder;
		}
	}
	return nil;
}

void wyUtils::showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton, const char* negativeButton, wyTargetSelector* onOK, wyTargetSelector* onCancel) {
	NSString* cancelButtonTitle = wyUtils_ios::to_NSString(negativeButton);
	NSString* okButtonTitle = wyUtils_ios::to_NSString(positiveButton);
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
	
	// create alert view
	UIAlertView* alert = [[UIAlertView alloc] initWithTitle:wyUtils_ios::to_NSString(title)
													message:wyUtils_ios::to_NSString(msg)
												   delegate:[[WYConfirmDialogDelegate alloc] initWithTargetSelector:onOK cancel:onCancel]
										  cancelButtonTitle:cancelButtonTitle
										  otherButtonTitles:okButtonTitle, nil];
	
	/*
	 * we didn't call [alert show] because it will bring up a cancel touch event. That will
	 * cause a concurrent access to event queue and a warning printed. So we schedule it in
	 * next loop
	 */
	[alert performSelectorOnMainThread:@selector(show)
							withObject:nil
						 waitUntilDone:NO];
}

void wyUtils::showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton, wyTargetSelector* onOK) {
	NSString* okButtonTitle = wyUtils_ios::to_NSString(positiveButton);
	const char* lan = wyDevice::getLanguage();
	if(okButtonTitle == nil) {
		if(!strcmp("zh", lan))
			okButtonTitle = @WY_OK_ZH;
		else
			okButtonTitle = @WY_OK_EN;
	}
	
	// create alert view
	UIAlertView* alert = [[UIAlertView alloc] initWithTitle:wyUtils_ios::to_NSString(title)
													message:wyUtils_ios::to_NSString(msg)
												   delegate:[[WYConfirmDialogDelegate alloc] initWithTargetSelector:onOK cancel:nil]
										  cancelButtonTitle:nil
										  otherButtonTitles:okButtonTitle, nil];
	
	/*
	 * we didn't call [alert show] because it will bring up a cancel touch event. That will
	 * cause a concurrent access to event queue and a warning printed. So we schedule it in
	 * next loop
	 */
	[alert performSelectorOnMainThread:@selector(show)
							withObject:nil
						 waitUntilDone:NO];
}

void wyUtils::convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event) {
	memcpy(event, pe, sizeof(wyKeyEvent));
}

void wyUtils::convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type) {
	NSArray* touches = [pe allTouches];
	event->pointerCount = MIN(5, [touches count]);
	event->eventTime = pe.timestamp * 1000;
	event->index = 0;
	for(int i = 0; i < event->pointerCount; i++) {
		WYUITouch* touch = [touches objectAtIndex:i];
		CGPoint loc = touch.location;
		int pid = wyEventDispatcher_ios::indexOfUITouch(touch.hash);
		event->pid[i] = pid;
		event->x[i] = loc.x;
		event->y[i] = loc.y;
		event->tap[i] = touch.tapCount;

		// set changed index
		if(type == ET_TOUCH_POINTER_BEGAN) {
			if(touch.phase == UITouchPhaseBegan)
				event->index = i;
		} else if(type == ET_TOUCH_POINTER_END) {
			if(touch.phase == UITouchPhaseEnded || touch.phase == UITouchPhaseCancelled)
				event->index = i;
		}
	}
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

    // then make the uiimage from that
    UIImage* myImage = [UIImage imageWithCGImage:imageRef];

	// save to path
    const char* mappedPath = mapLocalPath(path);
	NSData* data = UIImagePNGRepresentation(myImage);
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

    // then make the uiimage from that
    UIImage* myImage = [UIImage imageWithCGImage:imageRef];

	// save to path
    const char* mappedPath = mapLocalPath(path);
	NSData* data = UIImageJPEGRepresentation(myImage, 0.8);
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
		return wyUtils_ios::to_CString(str);
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
		size_t len = CFStringGetLength(s);
		s16 = (char16_t*)wyCalloc(len + 1, sizeof(char16_t));
		CFStringGetCharacters(s, CFRangeMake(0, len), (char16_t*)s16);
		CFRelease(s);
	}

	return s16;
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile, float width) {
	if(fontPath == NULL) {
		return calculateTextSize(text, fontSize, NORMAL, NULL, width);
	} else {
		// load ttf
		NSString* mappedPath = nil;
		NSString* nsPath = [NSString stringWithCString:fontPath encoding:NSUTF8StringEncoding];
		if(isFile) {
			mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath];
		} else {
			mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
		}
		ZFont* font = [[FontManager sharedManager] zFontWithURL:[NSURL fileURLWithPath:mappedPath] 
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
	UIFont* font = [UIFont fontWithName:fn size:fontSize];
	if(font == nil) {
		LOGW("calculateTextSize: Can't create font for name: %s", fontName);
		return wysZero;
	}

	// measure the string
	NSString* s = [NSString stringWithUTF8String:text];
	if(width <= 0)
		width = MAX_FLOAT;
	CGSize size = [s sizeWithFont:font
				constrainedToSize:CGSizeMake(width, MAX_FLOAT)
					lineBreakMode:UILineBreakModeWordWrap];
	return wys(size.width, size.height);
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	if(fontPath == NULL) {
		return createLabelBitmap(text, fontSize, NORMAL, NULL, width, alignment);
	} else {
		// load ttf
		NSString* mappedPath = nil;
		NSString* nsPath = [NSString stringWithCString:fontPath encoding:NSUTF8StringEncoding];
		if(isFile) {
			mappedPath = [[WYResMap sharedMap] getLocalFilePath:nsPath];
		} else {
			mappedPath = [[WYResMap sharedMap] getAssetFilePath:nsPath];
		}
		ZFont* font = [[FontManager sharedManager] zFontWithURL:[NSURL fileURLWithPath:mappedPath] 
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

		// push context
		UIGraphicsPushContext(context);

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
			alignment:align];

		// pop context
		UIGraphicsPopContext();

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
	UIFont* font = [UIFont fontWithName:fn size:fontSize];
	if(font == nil) {
		LOGW("createLabelBitmap: Can't create font for name: %s", fontName);
		return NULL;
	}

	// measure the string
	NSString* s = [NSString stringWithUTF8String:text];
	if(width <= 0)
		width = MAX_FLOAT;
	CGSize size = [s sizeWithFont:font
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

	// push context
	UIGraphicsPushContext(context);

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
		 withFont:font
	lineBreakMode:UILineBreakModeWordWrap
		alignment:align];

	// pop context
	UIGraphicsPopContext();

	// release
	CGColorSpaceRelease(colorSpace);
	CGContextRelease(context);

	// return
	return (char*)data;
}

bool wyUtils::deleteFile(const char* path) {
	const char* mappedPath = mapLocalPath(path);
	NSString* p = wyUtils_ios::to_NSString(mappedPath);
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

char* wyUtils::loadBMP(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY) {
	UIImage* image = [UIImage imageWithData:[NSData dataWithBytes:data length:length]];
	if(image == nil) {
		LOGW("loadBMP: failed to create UIImage from data");
		return NULL;
	}

	return wyUtils_ios::loadUIImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadPNG(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY) {
	UIImage* image = [UIImage imageWithData:[NSData dataWithBytes:data length:length]];
	if(image == nil) {
		LOGW("loadPNG: failed to create UIImage from data");
		return NULL;
	}

	return wyUtils_ios::loadUIImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadJPG(const char* data, size_t length, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY) {
	UIImage* image = [UIImage imageWithData:[NSData dataWithBytes:data length:length]];
	if(image == nil) {
		LOGW("loadJPG: failed to create UIImage from data");
		return NULL;
	}

	return wyUtils_ios::loadUIImage(image, w, h, sizeOnly, scaleX, scaleY);
}

char* wyUtils::loadRaw(int resId, size_t* outLen, float* outScale, bool noDecode) {
	// get file path, if nil, return NULL
	NSString* path = [[WYResMap sharedMap] getResFilePath:resId];
	if(path == nil) {
		LOGW("loadRaw: Failed to map res id: %d", resId);
		return NULL;
	}

    float inDensity = wyUtils_ios::getDensity(path);
	NSData* data = [NSData dataWithContentsOfFile:path];
	if(outLen != NULL) {
		*outLen = [data length];
	}
	if(outScale != NULL) {
		if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
			*outScale = wyDevice::density / inDensity;
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

char* wyUtils::scalePVR(wyPVRFormat format, char* originData, int originWidth, int originHeight, float scale) {
	// no need implement it in iOS
	return NULL;
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
		return wyUtils_ios::to_CString(mappedPath);
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
		return wyUtils_ios::to_CString(mappedPath);
	}
}

void wyUtils::playVideo(int resId) {
	// get file path, if nil, return NULL
	NSString* fullPath = [[WYResMap sharedMap] getResFilePath:resId];
	if(fullPath == nil) {
		LOGW("playVideo: Failed to map res id: %d", resId);
		return;
	}

	NSURL* url = [NSURL fileURLWithPath:fullPath];
	WYMoviePlayerWrapper* wrapper = [[WYMoviePlayerWrapper alloc] init];
	[wrapper playVideo:url];
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
		LOGW("playVideo: can't map android path %s", path);
		return;
	}
	
	// create url
	NSURL* url = [NSURL fileURLWithPath:mappedPath];
	
	// start play
	WYMoviePlayerWrapper* wrapper = [[WYMoviePlayerWrapper alloc] init];
	[wrapper playVideo:url];
}

void wyUtils::openUrl(const char* url) {
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:wyUtils_ios::to_NSString(url)]];
}

bool wyUtils::isPathExistent(const char* path) {
	if(path == NULL)
		return true;
	const char* mappedPath = mapLocalPath(path);
	bool ret = [[NSFileManager defaultManager] fileExistsAtPath:wyUtils_ios::to_NSString(mappedPath)];
	wyFree((void*)mappedPath);
	return ret;
}

bool wyUtils::isResExistent(const char* path, bool isFile) {
	if(isFile) {
		return isPathExistent(path);
	} else {
		const char* mappedPath = mapAssetsPath(path);
		bool ret = [[NSFileManager defaultManager] fileExistsAtPath:wyUtils_ios::to_NSString(mappedPath)];
		wyFree((void*)mappedPath);
		return ret;
	}
}

void wyUtils::addAndroidStrings(const char* fileName, const char* langId) {
    NSString* nsFileName = wyUtils_ios::to_NSString(fileName);
    NSString* nsLangId = wyUtils_ios::to_NSString(langId);
    [[WYAndroidStrings sharedInstance] addStrings:nsFileName forLanguage:nsLangId];
}

#endif // #if IOS
