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
#ifndef __wyImagePicker_h__
#define __wyImagePicker_h__

#include "wyGlobal.h"

/**
 * @typedef wyImagePickerCallback
 *
 * callback of \link wyImagePicker wyImagePicker\endlink
 */
typedef struct WIENGINE_API wyImagePickerCallback {
	/**
	 * Invoked when image is picked
	 *
	 * @param raw raw data of image, in RBGA8888 format and its size should be w * h * 4, you
	 * 		should release this pointer
	 * @param w image width in pixel
	 * @param h image height in pixel
	 * @param data extra data pointer
	 */
	void (*onImagePicked)(const char* raw, int w, int h, void* data);

	/**
	 * invoked when image picking cancelled
	 *
	 * @param data extra data pointer
	 */
	void (*onImagePickCancelled)(void* data);
} wyImagePickerCallback;

/**
 * @class wyImagePicker
 *
 * helper class to provide cross-platform image picking functionality. Image
 * can be picked from camera, or album, in RGBA8888 format. \link wyTexture2D wyTexture2D\endlink
 * can generate texture from the returned raw data.
 */
class WIENGINE_API wyImagePicker {
	/**
	 * pick a image from camera and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched. Do nothing if device doesn't have
	 * camera
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not
	 * @param front true means use front camera
	 */
	static void pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio, bool front);

public:
	/**
	 * does device have camera
	 *
	 * @return true means device has at least one camera
	 */
	static bool hasCamera();

	/**
	 * does device have front camera
	 *
	 * @return true means device has front camera
	 */
	static bool hasFrontCamera();

	/**
	 * pick a image from camera and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched. Do nothing if device doesn't have
	 * camera
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 */
	static void pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);

	/**
	 * pick a image from front camera and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched. Do nothing if device doesn't have
	 * front camera
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 */
	static void pickFromFrontCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);

	/**
	 * pick a image from album and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched.
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 */
	static void pickFromAlbum(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);
};

#endif // __wyImagePicker_h__
