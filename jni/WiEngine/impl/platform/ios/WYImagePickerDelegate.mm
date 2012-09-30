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

#import "WYImagePickerDelegate.h"

@implementation WYImagePickerDelegate

- (id)initWithCallback:(wyImagePickerCallback*)callback data:(void*)data parent:(UIViewController*)parent width:(int)width height:(int)height keepRatio:(BOOL)keepRatio {
	if(self = [super init]) {
		memset(&m_callback, 0, sizeof(wyImagePickerCallback));
		memcpy(&m_callback, callback, sizeof(wyImagePickerCallback));
		m_parent = parent;
		m_data = data;
		m_width = width;
		m_height = height;
		m_keepRatio = keepRatio;
	}
	return self;
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
	// callback
	if(m_callback.onImagePicked) {
		// get image
		UIImage* image = [info objectForKey:UIImagePickerControllerOriginalImage];
		
		// get CGImage info
		CGImageRef CGImage = image.CGImage;
		CGImageAlphaInfo alphaInfo = CGImageGetAlphaInfo(CGImage);
		BOOL hasAlpha = (alphaInfo == kCGImageAlphaPremultipliedLast || alphaInfo == kCGImageAlphaPremultipliedFirst || alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaFirst) ? YES : NO;
		
		/*
		 * WORKAROUND
		 * set hasAlpha to YES. It is a workaround for iPad. JPG image is abnormal after loading in
		 * iPad, but not in iPhone. Maybe a bug of iPad and force setting hasAlpha to YES solve this.
		 */
		hasAlpha = YES;
		
		// get image original size
		int bW = CGImageGetWidth(CGImage);
		int bH = CGImageGetHeight(CGImage);
		
		// need swap width and height for left/right orientation
		UIImageOrientation orientation = image.imageOrientation;
		BOOL swapWH = orientation == UIImageOrientationLeft || 
		orientation == UIImageOrientationRight ||
		orientation == UIImageOrientationLeftMirrored ||
		orientation == UIImageOrientationRightMirrored;
		
		// calculate real context size
		int w, h;
		if(m_keepRatio) {
			float scaleW = m_width / (float)(swapWH ? bH : bW);
			float scaleH = m_height / (float)(swapWH ? bW : bH);
			float scale = MIN(scaleW, scaleH);
			w = (swapWH ? bH : bW) * scale;
			h = (swapWH ? bW : bH) * scale;
		} else {
			w = m_width;
			h = m_height;
		}
		
		// now build transform for orientation
		float scaleX = 1;
		float scaleY = 1;
		CGAffineTransform transform = CGAffineTransformIdentity;
		switch(orientation) {
			case UIImageOrientationDown:
				transform = CGAffineTransformTranslate(transform, w, h);
				transform = CGAffineTransformRotate(transform, -M_PI);
				break;
			case UIImageOrientationLeft:
				transform = CGAffineTransformTranslate(transform, w, 0);
				transform = CGAffineTransformRotate(transform, M_PI_2);
				break;
			case UIImageOrientationRight:
				transform = CGAffineTransformTranslate(transform, 0, h);
				transform = CGAffineTransformRotate(transform, -M_PI_2);
				break;
			default:
				// do nothing
				break;
		}
		
		// calculate real drawing dest rect
		CGRect imageRect = CGRectMake(0,
									  0, 
									  swapWH ? h : w, 
									  swapWH ? w : h);
		
		// create a bitmap
		CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
		void* data = wyMalloc(w * h * 4 * sizeof(char));
		alphaInfo = hasAlpha ? kCGImageAlphaPremultipliedLast : kCGImageAlphaNoneSkipLast; 
		CGContextRef context = CGBitmapContextCreate(data, w, h, 8, 4 * w, colorSpace, alphaInfo | kCGBitmapByteOrder32Big);
		CGContextScaleCTM(context, scaleX, scaleY);	
		CGContextTranslateCTM(context, scaleX == -1 ? (swapWH ? h : w) : 0, scaleY == -1 ? (swapWH ? w : h) : 0);
		CGContextConcatCTM(context, transform);
		
		// draw original image to bitmap
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
		for(int y = 0; y < h; y++) {
			for(int x = 0; x < w; x++) {
				if(p[3] != 0) {
					p[0] = p[0] * 255 / p[3];
					p[1] = p[1] * 255 / p[3];
					p[2] = p[2] * 255 / p[3];
				}
				p += 4;
			}
		}
		
		// call
		m_callback.onImagePicked((const char*)data, w, h, m_data);
	}
	
	// hide picker view
	[m_parent dismissModalViewControllerAnimated:YES];
	
	// release self
	[self autorelease];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
	// hide picker view
	[m_parent dismissModalViewControllerAnimated:YES];
	
	// notify callback
	if(m_callback.onImagePickCancelled) {
		m_callback.onImagePickCancelled(m_data);
	}
	
	// release self
	[self autorelease];
}

@end

#endif // #if IOS