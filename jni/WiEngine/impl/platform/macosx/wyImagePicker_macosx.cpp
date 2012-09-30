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

#include "wyImagePicker.h"
#include "wyUtils_macosx.h"
#include "wyDirector_macosx.h"
#import <Quartz/Quartz.h>
#import "WYIKPictureTakerDelegate.h"
#import "WYIKImageBrowser.h"

extern wyDirector_macosx* gDirector;

bool wyImagePicker::hasCamera() {
	// always false for Mac OS X
	return false;
}

bool wyImagePicker::hasFrontCamera() {
	// always return true
	return true;
}

void wyImagePicker::pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio, bool front) {
	if(gDirector == NULL || gDirector->getGLView() == NULL)
		return;
	
	// create delegate
	WYIKPictureTakerDelegate* delegate = [[WYIKPictureTakerDelegate alloc] initWithCallback:callback
																					   data:data
																					  width:w
																					 height:h
																				  keepRatio:keepRatio];
	
	// create picture taker and start
	IKPictureTaker* sharedPictureTaker = [IKPictureTaker pictureTaker];
    [sharedPictureTaker setValue:[NSNumber numberWithBool:YES] forKey:IKPictureTakerShowEffectsKey];
	[sharedPictureTaker setValue:[NSNumber numberWithBool:NO] forKey:IKPictureTakerAllowsFileChoosingKey];
	[sharedPictureTaker setValue:[NSValue valueWithSize:NSMakeSize(w, h)] forKey:IKPictureTakerOutputImageMaxSizeKey];
	[sharedPictureTaker setValue:[NSValue valueWithSize:NSMakeSize(w, h)] forKey:IKPictureTakerCropAreaSizeKey];
    [sharedPictureTaker beginPictureTakerSheetForWindow:[gDirector->getGLView() window] 
										   withDelegate:delegate
										 didEndSelector:@selector(pictureTakerDidEnd:returnCode:contextInfo:) 
											contextInfo:nil];
}

void wyImagePicker::pickFromAlbum(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio) {
	WYIKImageBrowser* browser = [[WYIKImageBrowser alloc] initWithCallback:callback
																	  data:data
																	 width:w
																	height:h
																 keepRatio:keepRatio];
	[browser beginSheet];
}

#endif // #if MACOSX
