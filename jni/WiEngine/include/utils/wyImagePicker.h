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
 * \if English
 * callback of \link wyImagePicker wyImagePicker\endlink
 * \else
 * \link wyImagePicker wyImagePicker\endlink的回调定义
 * \endif
 */
typedef struct WIENGINE_API wyImagePickerCallback {
	/**
	 * \if English
	 * Invoked when image is picked
	 *
	 * @param raw raw data of image, in RBGA8888 format and its size should be w * h * 4, you
	 * 		should release this pointer
	 * @param w image width in pixel
	 * @param h image height in pixel
	 * @param data extra data pointer
	 * \else
	 * 当图片被选定时被调用
	 *
	 * @param raw 图片的RGBA8888数据, 它的长度应该是w * h * 4字节, 您需要负责释放该内存
	 * @param w 最终生成的图片的像素宽度, 应该等于之前传入的宽度，但是不一定，因为可能缩放时存在误差
	 * @param h 最终生成的图片的像素高度, 应该等于之前传入的高度，但是不一定，因为可能缩放时存在误差
	 * @param data 额外数据指针
	 * \endif
	 */
	void (*onImagePicked)(const char* raw, int w, int h, void* data);

	/**
	 * \if English
	 * invoked when image picking cancelled
	 *
	 * @param data extra data pointer
	 * \else
	 * 当选择图片操作取消时被调用
	 *
	 * @param data 额外数据指针
	 * \endif
	 */
	void (*onImagePickCancelled)(void* data);
} wyImagePickerCallback;

/**
 * @class wyImagePicker
 *
 * \if English
 * helper class to provide cross-platform image picking functionality. Image
 * can be picked from camera, or album, in RGBA8888 format. \link wyTexture2D wyTexture2D\endlink
 * can generate texture from the returned raw data.
 * \else
 * 工具类，用来封装跨平台的选择图片接口。图片可以从摄像头或相册中选取，返回
 * RGBA8888的图片数据，\link wyTexture2D wyTexture2D\endlink有makeRaw方法
 * 可以直接从RGBA8888数据中生成贴图
 * \endif
 */
class WIENGINE_API wyImagePicker {
	/**
	 * \if English
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
	 * \else
	 * 从摄像头拍摄一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放. 如果设备没有摄像头，则不做任何事.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 * @param front true表示从前置摄像头中获取
	 * \endif
	 */
	static void pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio, bool front);

public:
	/**
	 * \if English
	 * does device have camera
	 *
	 * @return true means device has at least one camera
	 * \else
	 * 设备是否有摄像头
	 *
	 * @return true表示设备至少有一个摄像头
	 * \endif
	 */
	static bool hasCamera();

	/**
	 * \if English
	 * does device have front camera
	 *
	 * @return true means device has front camera
	 * \else
	 * 设备是否有前置摄像头
	 *
	 * @return true表示设备有前置摄像头
	 * \endif
	 */
	static bool hasFrontCamera();

	/**
	 * \if English
	 * pick a image from camera and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched. Do nothing if device doesn't have
	 * camera
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 * \else
	 * 从摄像头拍摄一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放. 如果设备没有摄像头，则不做任何事.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 * \endif
	 */
	static void pickFromCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);

	/**
	 * \if English
	 * pick a image from front camera and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched. Do nothing if device doesn't have
	 * front camera
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 * \else
	 * 从前置摄像头拍摄一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放. 如果设备没有前置摄像头，则不做任何事.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 * \endif
	 */
	static void pickFromFrontCamera(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);

	/**
	 * \if English
	 * pick a image from album and return it as RGBA8888. You can specify an expected
	 * image size and image will be scaled if not matched.
	 *
	 * @param callback callback
	 * @param data extra data pointer, will be passed to callback and can be NULL
	 * @param w expected image width
	 * @param h expected image height
	 * @param keepRatio true means keep image width-height ratio, false means not. default is true
	 * \else
	 * 从相册中选择一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 * \endif
	 */
	static void pickFromAlbum(wyImagePickerCallback* callback, void* data, int w, int h, bool keepRatio = true);
};

#endif // __wyImagePicker_h__
