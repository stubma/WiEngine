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
#if ANDROID

#include "com_wiyun_engine_utils_ImagePickerActivity.h"
#include "wyImagePicker.h"
#include "wyLog.h"
#include "wyInit.h"
#include "wyTypes.h"
#include <setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "jpeglib.h"

extern wyAAL gAAL;

typedef enum {
    kNo_Config,         //!< bitmap has not been configured
    kA1_Config,         //!< 1-bit per pixel, (0 is transparent, 1 is opaque)
    kA8_Config,         //!< 8-bits per pixel, with only alpha specified (0 is transparent, 0xFF is opaque)
    kIndex8_Config,     //!< 8-bits per pixel, using SkColorTable to specify the colors
    kRGB_565_Config,    //!< 16-bits per pixel, (see SkColorPriv.h for packing)
    kARGB_4444_Config,  //!< 16-bits per pixel, (see SkColorPriv.h for packing)
    kARGB_8888_Config,  //!< 32-bits per pixel, (see SkColorPriv.h for packing)
    kRLE_Index8_Config,
    kConfigCount
} SkBitmapConfig;

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

#ifdef __cplusplus
}
#endif

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ImagePickerActivity_onImagePicked
  (JNIEnv * env, jobject thiz, jint callback, jint data, jbyteArray jpgData, jint w, jint h, jboolean keepRatio) {
	wyImagePickerCallback* cb = (wyImagePickerCallback*)callback;
	void* d = (void*)data;

	// get native array and length
	const char* jpg = (const char*)env->GetByteArrayElements(jpgData, NULL);
	size_t length = env->GetArrayLength(jpgData);

	// start decompress jpg data
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
		env->ReleaseByteArrayElements(jpgData, (jbyte*)jpg, 0);
		return;
	}

	// init decompress struct
	jpeg_create_decompress(&cinfo);

	// specify data source
	jpeg_stdio_buffer_src(&cinfo, jpg, length);

	// read header
	jpeg_read_header(&cinfo, TRUE);

	// save size
	int width = cinfo.image_width;
	int height = cinfo.image_height;

	// decide final size
	float scaleX, scaleY;
	if(keepRatio) {
		float scaleW = w / (float)width;
		float scaleH = h / (float)height;
		scaleX = scaleY = MIN(scaleW, scaleH);
		w = width * scaleX;
		h = height * scaleY;
	} else {
		scaleX = w / (float)width;
		scaleY = h / (float)height;
	}

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
		char* scaled = gAAL.scaleImage(kARGB_8888_Config, image_data, width, height, scaleX, scaleY);
		if(scaled != image_data) {
			wyFree(image_data);
			image_data = scaled;
		}
	}

	// callback
	if(cb->onImagePicked)
		cb->onImagePicked(image_data, w, h, d);

	// release native data
	env->ReleaseByteArrayElements(jpgData, (jbyte*)jpg, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ImagePickerActivity_onImagePickCancelled
  (JNIEnv * env, jobject thiz, jint callback, jint data) {
	wyImagePickerCallback* cb = (wyImagePickerCallback*)callback;
	void* d = (void*)data;
	if(cb->onImagePickCancelled)
		cb->onImagePickCancelled(d);
}

#endif // #if ANDROID
