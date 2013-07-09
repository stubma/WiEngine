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

#include "wyTypes.h"
#include "wyUtils_android.h"
#include "wyJNI.h"
#include "wyInit.h"
#include "png.h"
#include "wyDirector.h"
#include "wyLog.h"
#include "wyMD5.h"
#include <errno.h>
#include <unistd.h>
#include <math.h>

// global decoder
extern wyResourceDecoder* gResDecoder;

// for png sig
#define PNG_BYTES_TO_CHECK 8

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

// preload classes
extern jclass gClass_Director;
extern jclass gClass_Utilities;

// WYPoint class fields
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

// WYDimension class fields
extern jfieldID g_fid_WYDimension_x;
extern jfieldID g_fid_WYDimension_y;

// WYRect class fields
extern jfieldID g_fid_WYRect_origin;
extern jfieldID g_fid_WYRect_size;

// WYVertex3D class fields
extern jfieldID g_fid_WYVertex3D_x;
extern jfieldID g_fid_WYVertex3D_y;
extern jfieldID g_fid_WYVertex3D_z;

// WYColor3B class fields
extern jfieldID g_fid_WYColor3B_r;
extern jfieldID g_fid_WYColor3B_g;
extern jfieldID g_fid_WYColor3B_b;

// WYColor4B class fields
extern jfieldID g_fid_WYColor4B_r;
extern jfieldID g_fid_WYColor4B_g;
extern jfieldID g_fid_WYColor4B_b;
extern jfieldID g_fid_WYColor4B_a;

// WYQuad2D class fields
extern jfieldID g_fid_WYQuad2D_bl_x;
extern jfieldID g_fid_WYQuad2D_bl_y;
extern jfieldID g_fid_WYQuad2D_br_x;
extern jfieldID g_fid_WYQuad2D_br_y;
extern jfieldID g_fid_WYQuad2D_tl_x;
extern jfieldID g_fid_WYQuad2D_tl_y;
extern jfieldID g_fid_WYQuad2D_tr_x;
extern jfieldID g_fid_WYQuad2D_tr_y;

// WYQuad3D class fields
extern jfieldID g_fid_WYQuad3D_bl_x;
extern jfieldID g_fid_WYQuad3D_bl_y;
extern jfieldID g_fid_WYQuad3D_bl_z;
extern jfieldID g_fid_WYQuad3D_br_x;
extern jfieldID g_fid_WYQuad3D_br_y;
extern jfieldID g_fid_WYQuad3D_br_z;
extern jfieldID g_fid_WYQuad3D_tl_x;
extern jfieldID g_fid_WYQuad3D_tl_y;
extern jfieldID g_fid_WYQuad3D_tl_z;
extern jfieldID g_fid_WYQuad3D_tr_x;
extern jfieldID g_fid_WYQuad3D_tr_y;
extern jfieldID g_fid_WYQuad3D_tr_z;

// WYBezierConfig class
extern jfieldID g_fid_WYBezierConfig_cubic;
extern jfieldID g_fid_WYBezierConfig_startX;
extern jfieldID g_fid_WYBezierConfig_startY;
extern jfieldID g_fid_WYBezierConfig_endX;
extern jfieldID g_fid_WYBezierConfig_endY;
extern jfieldID g_fid_WYBezierConfig_cp1X;
extern jfieldID g_fid_WYBezierConfig_cp1Y;
extern jfieldID g_fid_WYBezierConfig_cp2X;
extern jfieldID g_fid_WYBezierConfig_cp2Y;

// WYLagrangeConfig class
extern jfieldID g_fid_WYLagrangeConfig_cubic;
extern jfieldID g_fid_WYLagrangeConfig_startX;
extern jfieldID g_fid_WYLagrangeConfig_startY;
extern jfieldID g_fid_WYLagrangeConfig_endX;
extern jfieldID g_fid_WYLagrangeConfig_endY;
extern jfieldID g_fid_WYLagrangeConfig_cp1X;
extern jfieldID g_fid_WYLagrangeConfig_cp1Y;
extern jfieldID g_fid_WYLagrangeConfig_cp2X;
extern jfieldID g_fid_WYLagrangeConfig_cp2Y;
extern jfieldID g_fid_WYLagrangeConfig_t0;
extern jfieldID g_fid_WYLagrangeConfig_t1;
extern jfieldID g_fid_WYLagrangeConfig_t2;
extern jfieldID g_fid_WYLagrangeConfig_t3;

// WYHypotrochoidConfig class
extern jfieldID g_fid_WYHypotrochoidConfig_R;
extern jfieldID g_fid_WYHypotrochoidConfig_r;
extern jfieldID g_fid_WYHypotrochoidConfig_d;
extern jfieldID g_fid_WYHypotrochoidConfig_startAngle;
extern jfieldID g_fid_WYHypotrochoidConfig_endAngle;
extern jfieldID g_fid_WYHypotrochoidConfig_centreX;
extern jfieldID g_fid_WYHypotrochoidConfig_centreY;

// WYAffineTransform
extern jfieldID g_fid_WYAffineTransform_a;
extern jfieldID g_fid_WYAffineTransform_b;
extern jfieldID g_fid_WYAffineTransform_c;
extern jfieldID g_fid_WYAffineTransform_d;
extern jfieldID g_fid_WYAffineTransform_tx;
extern jfieldID g_fid_WYAffineTransform_ty;

// WYSize class fields
extern jfieldID g_fid_WYSize_width;
extern jfieldID g_fid_WYSize_height;

// FileDescriptor class field
extern jfieldID g_fid_FileDescriptor_descriptor;

// Utilities
extern jmethodID g_mid_Utilities_createLabelBitmap_by_fontPath;
extern jmethodID g_mid_Utilities_createLabelBitmap_by_fontStyle;
extern jmethodID g_mid_Utilities_calculateTextSize_by_fontPath;
extern jmethodID g_mid_Utilities_calculateTextSize_by_fontStyle;
extern jmethodID g_mid_Utilities_loadAsset;
extern jmethodID g_mid_Utilities_scaleImage;

// Director
extern jmethodID g_mid_Director_getInstance;
extern jmethodID g_mid_Director_showConfirmDialog;
extern jmethodID g_mid_Director_showAlertDialog;
extern jmethodID g_mid_Director_hasPermission;

// Context
extern jmethodID g_mid_Context_getResources;
extern jmethodID g_mid_Context_getPackageName;
extern jmethodID g_mid_Context_startActivity;
extern jmethodID g_mid_Context_sendBroadcast;

// Resources
extern jmethodID g_mid_Resources_getIdentifier;
extern jmethodID g_mid_Resources_getString;

// KeyEvent
extern jmethodID g_mid_KeyEvent_getKeyCode;
extern jmethodID g_mid_KeyEvent_getRepeatCount;
extern jmethodID g_mid_KeyEvent_getDownTime;
extern jmethodID g_mid_KeyEvent_getEventTime;

// MotionEvent
extern jmethodID g_mid_MotionEvent_getAction;
extern jmethodID g_mid_MotionEvent_getPointerCount;
extern jmethodID g_mid_MotionEvent_getPointerId;
extern jmethodID g_mid_MotionEvent_getPressure;
extern jmethodID g_mid_MotionEvent_getDownTime;
extern jmethodID g_mid_MotionEvent_getEventTime;
extern jmethodID g_mid_MotionEvent_getX;
extern jmethodID g_mid_MotionEvent_getX_I;
extern jmethodID g_mid_MotionEvent_getY;
extern jmethodID g_mid_MotionEvent_getY_I;
extern int g_enum_MotionEvent_ACTION_POINTER_ID_MASK;
extern int g_enum_MotionEvent_ACTION_POINTER_ID_SHIFT;

// intent
extern jmethodID g_mid_Intent_init;
extern jmethodID g_mid_Intent_init_S;
extern jmethodID g_mid_Intent_putExtra_Z;
extern jmethodID g_mid_Intent_putExtra_B;
extern jmethodID g_mid_Intent_putExtra_C;
extern jmethodID g_mid_Intent_putExtra_D;
extern jmethodID g_mid_Intent_putExtra_F;
extern jmethodID g_mid_Intent_putExtra_I;
extern jmethodID g_mid_Intent_putExtra_String;
extern jmethodID g_mid_Intent_putExtra_J;
extern jmethodID g_mid_Intent_putExtra_S;
extern jmethodID g_mid_Intent_putExtra_Parcelable;

// Map
extern jmethodID g_mid_Map_put;

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

void wyUtils_android::to_WYQuad2D(wyQuad2D& q, jobject jq) {
	JNIEnv* env = getJNIEnv();
	env->SetFloatField(jq, g_fid_WYQuad2D_bl_x, q.bl_x);
	env->SetFloatField(jq, g_fid_WYQuad2D_bl_y, q.bl_y);
	env->SetFloatField(jq, g_fid_WYQuad2D_br_x, q.br_x);
	env->SetFloatField(jq, g_fid_WYQuad2D_br_y, q.br_y);
	env->SetFloatField(jq, g_fid_WYQuad2D_tl_x, q.tl_x);
	env->SetFloatField(jq, g_fid_WYQuad2D_tl_y, q.tl_y);
	env->SetFloatField(jq, g_fid_WYQuad2D_tr_x, q.tr_x);
	env->SetFloatField(jq, g_fid_WYQuad2D_tr_y, q.tr_y);
}

void wyUtils_android::to_WYQuad3D(wyQuad3D& q, jobject jq) {
	JNIEnv* env = getJNIEnv();
	env->SetFloatField(jq, g_fid_WYQuad3D_bl_x, q.bl_x);
	env->SetFloatField(jq, g_fid_WYQuad3D_bl_y, q.bl_y);
	env->SetFloatField(jq, g_fid_WYQuad3D_bl_z, q.bl_z);
	env->SetFloatField(jq, g_fid_WYQuad3D_br_x, q.br_x);
	env->SetFloatField(jq, g_fid_WYQuad3D_br_y, q.br_y);
	env->SetFloatField(jq, g_fid_WYQuad3D_br_z, q.br_z);
	env->SetFloatField(jq, g_fid_WYQuad3D_tl_x, q.tl_x);
	env->SetFloatField(jq, g_fid_WYQuad3D_tl_y, q.tl_y);
	env->SetFloatField(jq, g_fid_WYQuad3D_tl_z, q.tl_z);
	env->SetFloatField(jq, g_fid_WYQuad3D_tr_x, q.tr_x);
	env->SetFloatField(jq, g_fid_WYQuad3D_tr_y, q.tr_y);
	env->SetFloatField(jq, g_fid_WYQuad3D_tr_z, q.tr_z);
}

void wyUtils_android::to_WYRect(wyRect r, jobject jr) {
	JNIEnv* env = getJNIEnv();
	jobject origin = env->GetObjectField(jr, g_fid_WYRect_origin);
	jobject size = env->GetObjectField(jr, g_fid_WYRect_size);
	env->SetFloatField(origin, g_fid_WYPoint_x, r.x);
	env->SetFloatField(origin, g_fid_WYPoint_y, r.y);
	env->SetFloatField(size, g_fid_WYSize_width, r.width);
	env->SetFloatField(size, g_fid_WYSize_height, r.height);
	env->DeleteLocalRef(origin);
	env->DeleteLocalRef(size);
}

void wyUtils_android::to_WYPoint(wyPoint p, jobject jp) {
	JNIEnv* env = getJNIEnv();
	env->SetFloatField(jp, g_fid_WYPoint_x, p.x);
	env->SetFloatField(jp, g_fid_WYPoint_y, p.y);
}

void wyUtils_android::to_WYDimension(wyDimension d, jobject jd) {
	JNIEnv* env = getJNIEnv();
	env->SetIntField(jd, g_fid_WYDimension_x, d.x);
	env->SetIntField(jd, g_fid_WYDimension_y, d.y);
}

void wyUtils_android::to_WYSize(wySize s, jobject js) {
	JNIEnv* env = getJNIEnv();
	env->SetFloatField(js, g_fid_WYSize_width, s.width);
	env->SetFloatField(js, g_fid_WYSize_height, s.height);
}

void wyUtils_android::to_WYAffineTransform(wyAffineTransform t, jobject jt) {
	JNIEnv* env = getJNIEnv();
	env->SetDoubleField(jt, g_fid_WYAffineTransform_a, t.a);
	env->SetDoubleField(jt, g_fid_WYAffineTransform_b, t.b);
	env->SetDoubleField(jt, g_fid_WYAffineTransform_c, t.c);
	env->SetDoubleField(jt, g_fid_WYAffineTransform_d, t.d);
	env->SetDoubleField(jt, g_fid_WYAffineTransform_tx, t.tx);
	env->SetDoubleField(jt, g_fid_WYAffineTransform_ty, t.ty);
}

wyBezierConfig wyUtils_android::to_wyBezierConfig(jobject config) {
	JNIEnv* env = getJNIEnv();
	bool cubic = env->GetBooleanField(config, g_fid_WYBezierConfig_cubic);
	if(cubic) {
		return wybcCubic(env->GetFloatField(config, g_fid_WYBezierConfig_startX),
				env->GetFloatField(config, g_fid_WYBezierConfig_startY),
				env->GetFloatField(config, g_fid_WYBezierConfig_endX),
				env->GetFloatField(config, g_fid_WYBezierConfig_endY),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp1X),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp1Y),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp2X),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp2Y));
	} else {
		return wybcQuad(env->GetFloatField(config, g_fid_WYBezierConfig_startX),
				env->GetFloatField(config, g_fid_WYBezierConfig_startY),
				env->GetFloatField(config, g_fid_WYBezierConfig_endX),
				env->GetFloatField(config, g_fid_WYBezierConfig_endY),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp1X),
				env->GetFloatField(config, g_fid_WYBezierConfig_cp1Y));
	}
}

wyLagrangeConfig wyUtils_android::to_wyLagrangeConfig(jobject config) {
	JNIEnv* env = getJNIEnv();
	bool cubic = env->GetBooleanField(config, g_fid_WYLagrangeConfig_cubic);
	if(cubic) {
		wyLagrangeConfig c = wylcCubic(env->GetFloatField(config, g_fid_WYLagrangeConfig_startX),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_startY),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_endX),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_endY),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp1X),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp1Y),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp2X),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp2Y));
		c.t0 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t0);
		c.t1 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t1);
		c.t2 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t2);
		c.t3 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t3);
		return c;
	} else {
		wyLagrangeConfig c = wylcQuad(env->GetFloatField(config, g_fid_WYLagrangeConfig_startX),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_startY),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_endX),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_endY),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp1X),
				env->GetFloatField(config, g_fid_WYLagrangeConfig_cp1Y));
		c.t0 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t0);
		c.t1 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t1);
		c.t2 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t2);
		c.t3 = env->GetFloatField(config, g_fid_WYLagrangeConfig_t3);
		return c;
	}
}

wyHypotrochoidConfig wyUtils_android::to_wyHypotrochoidConfig(jobject config) {
	JNIEnv* env = getJNIEnv();
	return wyhcQuad(env->GetFloatField(config, g_fid_WYHypotrochoidConfig_R),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_r),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_d),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_startAngle),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_endAngle),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_centreX),
			env->GetFloatField(config, g_fid_WYHypotrochoidConfig_centreY));
}

wyColor4B wyUtils_android::to_wyColor4B(jobject color) {
	JNIEnv* env = getJNIEnv();
	wyColor4B c4;
	c4.r = env->GetIntField(color, g_fid_WYColor4B_r);
	c4.g = env->GetIntField(color, g_fid_WYColor4B_g);
	c4.b = env->GetIntField(color, g_fid_WYColor4B_b);
	c4.a = env->GetIntField(color, g_fid_WYColor4B_a);
	return c4;
}

wyColor3B wyUtils_android::to_wyColor3B(jobject color) {
	JNIEnv* env = getJNIEnv();
	wyColor3B c3;
	c3.r = env->GetIntField(color, g_fid_WYColor3B_r);
	c3.g = env->GetIntField(color, g_fid_WYColor3B_g);
	c3.b = env->GetIntField(color, g_fid_WYColor3B_b);
	return c3;
}

void wyUtils_android::to_WYColor3B(wyColor3B color, jobject jColor) {
	JNIEnv* env = getJNIEnv();
	env->SetIntField(jColor, g_fid_WYColor3B_r, color.r);
	env->SetIntField(jColor, g_fid_WYColor3B_g, color.g);
	env->SetIntField(jColor, g_fid_WYColor3B_b, color.b);
}

void wyUtils_android::to_WYColor4B(wyColor4B color, jobject jColor) {
	JNIEnv* env = getJNIEnv();
	env->SetIntField(jColor, g_fid_WYColor4B_r, color.r);
	env->SetIntField(jColor, g_fid_WYColor4B_g, color.g);
	env->SetIntField(jColor, g_fid_WYColor4B_b, color.b);
	env->SetIntField(jColor, g_fid_WYColor4B_a, color.a);
}

bool wyUtils_android::putIntoMap(void* elt, void* data) {
	jobject map = (jobject)data;
	JNIEnv* env = getJNIEnv();
	wyKeyValueHash* hash = (wyKeyValueHash*)elt;
	jstring k = env->NewStringUTF(hash->key);
	jstring v = env->NewStringUTF(hash->value);
	env->CallObjectMethod(map, g_mid_Map_put, k, v);
	return true;
}

void wyUtils_android::to_Map(wyHashSet* set, jobject map) {
	if(set) {
		wyHashSetEach(set, putIntoMap, map);
	}
}

const char* wyUtils_android::to_CString(jstring js) {
	if(js) {
		JNIEnv* env = wyUtils::getJNIEnv();
		const char* utfChars = env->GetStringUTFChars(js, NULL);
		const char* ret = wyUtils::copy(utfChars);
		env->ReleaseStringUTFChars(js, utfChars);
		return ret;
	} else {
		return NULL;
	}
}

wyQuad2D wyUtils_android::to_wyQuad2D(jobject quad) {
	JNIEnv* env = getJNIEnv();
	wyQuad2D q2;
	q2.bl_x = env->GetFloatField(quad, g_fid_WYQuad2D_bl_x);
	q2.bl_y = env->GetFloatField(quad, g_fid_WYQuad2D_bl_y);
	q2.br_x = env->GetFloatField(quad, g_fid_WYQuad2D_br_x);
	q2.br_y = env->GetFloatField(quad, g_fid_WYQuad2D_br_y);
	q2.tl_x = env->GetFloatField(quad, g_fid_WYQuad2D_tl_x);
	q2.tl_y = env->GetFloatField(quad, g_fid_WYQuad2D_tl_y);
	q2.tr_x = env->GetFloatField(quad, g_fid_WYQuad2D_tr_x);
	q2.tr_y = env->GetFloatField(quad, g_fid_WYQuad2D_tr_y);
	return q2;
}

wyQuad3D wyUtils_android::to_wyQuad3D(jobject quad) {
	JNIEnv* env = getJNIEnv();
	wyQuad3D q3;
	q3.bl_x = env->GetFloatField(quad, g_fid_WYQuad3D_bl_x);
	q3.bl_y = env->GetFloatField(quad, g_fid_WYQuad3D_bl_y);
	q3.bl_z = env->GetFloatField(quad, g_fid_WYQuad3D_bl_z);
	q3.br_x = env->GetFloatField(quad, g_fid_WYQuad3D_br_x);
	q3.br_y = env->GetFloatField(quad, g_fid_WYQuad3D_br_y);
	q3.br_z = env->GetFloatField(quad, g_fid_WYQuad3D_br_z);
	q3.tl_x = env->GetFloatField(quad, g_fid_WYQuad3D_tl_x);
	q3.tl_y = env->GetFloatField(quad, g_fid_WYQuad3D_tl_y);
	q3.tl_z = env->GetFloatField(quad, g_fid_WYQuad3D_tl_z);
	q3.tr_x = env->GetFloatField(quad, g_fid_WYQuad3D_tr_x);
	q3.tr_y = env->GetFloatField(quad, g_fid_WYQuad3D_tr_y);
	q3.tr_z = env->GetFloatField(quad, g_fid_WYQuad3D_tr_z);
	return q3;
}

wyRect wyUtils_android::to_wyRect(jobject rect) {
	JNIEnv* env = getJNIEnv();
	wyRect r;
	jobject origin = env->GetObjectField(rect, g_fid_WYRect_origin);
	jobject size = env->GetObjectField(rect, g_fid_WYRect_size);
	r.x = env->GetFloatField(origin, g_fid_WYPoint_x);
	r.y = env->GetFloatField(origin, g_fid_WYPoint_y);
	r.width = env->GetFloatField(size, g_fid_WYSize_width);
	r.height = env->GetFloatField(size, g_fid_WYSize_height);
	env->DeleteLocalRef(origin);
	env->DeleteLocalRef(size);
	return r;
}

wyPoint wyUtils_android::to_wyPoint(jobject p) {
	JNIEnv* env = getJNIEnv();
	wyPoint ret;
	ret.x = env->GetFloatField(p, g_fid_WYPoint_x);
	ret.y = env->GetFloatField(p, g_fid_WYPoint_y);
	return ret;
}

wySize wyUtils_android::to_wySize(jobject s) {
	JNIEnv* env = getJNIEnv();
	wySize ret;
	ret.width = env->GetFloatField(s, g_fid_WYSize_width);
	ret.height = env->GetFloatField(s, g_fid_WYSize_height);
	return ret;
}

jobject wyUtils_android::newIntent(const char* activityName) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return NULL;

	// get context
	jobject context = wyDirector::getInstance()->getContext();

	// create activity name
	jclass clazz = env->FindClass(CLASS_INTENT);
	size_t len = strlen(activityName);
	char* jniName = (char*)wyCalloc(len + 1, sizeof(char));
	for(int i = 0; i < len; i++) {
		if(activityName[i] == '.')
			jniName[i] = '/';
		else
			jniName[i] = activityName[i];
	}
	jclass actClass = env->FindClass(jniName);
	jobject intent = env->NewObject(clazz, g_mid_Intent_init, context, actClass);
	env->DeleteLocalRef(clazz);
	env->DeleteLocalRef(actClass);
	wyFree(jniName);

	return intent;
}

jobject wyUtils_android::newIntentByAction(const char* action) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return NULL;

	// get context
	jobject context = wyDirector::getInstance()->getContext();

	// get intent class
	jclass clazz = env->FindClass(CLASS_INTENT);

	// create intent
	jstring a = env->NewStringUTF(action);
	jobject intent = env->NewObject(clazz, g_mid_Intent_init_S, a);
	env->DeleteLocalRef(a);
	env->DeleteLocalRef(clazz);

	return intent;
}

void wyUtils_android::putBooleanExtra(jobject intent, const char* name, bool value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_Z, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putByteExtra(jobject intent, const char* name, unsigned char value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_B, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putCharExtra(jobject intent, const char* name, unsigned short value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_C, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putDoubleExtra(jobject intent, const char* name, double value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_D, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putFloatExtra(jobject intent, const char* name, float value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_F, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putIntExtra(jobject intent, const char* name, int value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_I, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putStringExtra(jobject intent, const char* name, const char* value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	jstring v = env->NewStringUTF(value);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_B, s, v);
	env->DeleteLocalRef(s);
	env->DeleteLocalRef(v);
}

void wyUtils_android::putLongExtra(jobject intent, const char* name, long value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_J, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putShortExtra(jobject intent, const char* name, short value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_S, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::putParcelableExtra(jobject intent, const char* name, jobject value) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	jstring s = env->NewStringUTF(name);
	env->CallObjectMethod(intent, g_mid_Intent_putExtra_Parcelable, s, value);
	env->DeleteLocalRef(s);
}

void wyUtils_android::startActivity(jobject intent) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	// get context
	jobject context = wyDirector::getInstance()->getContext();

	env->CallVoidMethod(context, g_mid_Context_startActivity, intent);
	env->DeleteLocalRef(intent);
}

void wyUtils_android::sendBroadcast(jobject intent) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	// get context
	jobject context = wyDirector::getInstance()->getContext();

	env->CallVoidMethod(context, g_mid_Context_sendBroadcast, intent);
	env->DeleteLocalRef(intent);
}

bool wyUtils_android::hasPermission(const char* perm) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return false;

	jstring jPerm = env->NewStringUTF(perm);
	bool ret = env->CallStaticBooleanMethod(gClass_Director, g_mid_Director_hasPermission, jPerm);
	env->DeleteLocalRef(jPerm);

	return ret;
}

void wyUtils::showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton, const char* negativeButton, wyTargetSelector* onOK, wyTargetSelector* onCancel) {
	JNIEnv* env = getEnv();
	if(env == NULL)
		return;

	// hold target selector
	wyObjectRetain(onOK);
	wyObjectRetain(onCancel);

	// ensure positive button and negative button not null
	const char* posBtn = positiveButton;
	const char* negBtn = negativeButton;
	const char* lan = wyDevice::getLanguage();
	if(!posBtn) {
		if(!strcmp("zh", lan))
			posBtn = WY_OK_ZH;
		else
			posBtn = WY_OK_EN;
	}
	if(!negBtn) {
		if(!strcmp("zh", lan))
			negBtn = WY_CANCEL_ZH;
		else
			negBtn = WY_CANCEL_EN;
	}

	// create jstring
	jstring jTitle = title == NULL ? NULL : env->NewStringUTF(title);
	jstring jMsg = msg == NULL ? NULL : env->NewStringUTF(msg);
	jstring jPositiveButton = env->NewStringUTF(posBtn);
	jstring jNegativeButton = env->NewStringUTF(negBtn);

	// call java side
	env->CallStaticVoidMethod(gClass_Director, g_mid_Director_showConfirmDialog, jTitle, jMsg, jPositiveButton, jNegativeButton, onOK, onCancel);

	// delete reference
	if(jTitle)
		env->DeleteLocalRef(jTitle);
	if(jMsg)
		env->DeleteLocalRef(jMsg);
	if(jPositiveButton)
		env->DeleteLocalRef(jPositiveButton);
	if(jNegativeButton)
		env->DeleteLocalRef(jNegativeButton);
}

void wyUtils::showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton, wyTargetSelector* onOK) {
    JNIEnv* env = getEnv();
	if(env == NULL)
		return;
    
	// hold target selector
	wyObjectRetain(onOK);
    
	// ensure positive button and negative button not null
	const char* posBtn = positiveButton;
	const char* lan = wyDevice::getLanguage();
	if(!posBtn) {
		if(!strcmp("zh", lan))
			posBtn = WY_OK_ZH;
		else
			posBtn = WY_OK_EN;
	}
    
	// create jstring
	jstring jTitle = title == NULL ? NULL : env->NewStringUTF(title);
	jstring jMsg = msg == NULL ? NULL : env->NewStringUTF(msg);
	jstring jPositiveButton = env->NewStringUTF(posBtn);
    
	// call java side
	env->CallStaticVoidMethod(gClass_Director, g_mid_Director_showAlertDialog, jTitle, jMsg, jPositiveButton, onOK);
    
	// delete reference
	if(jTitle)
		env->DeleteLocalRef(jTitle);
	if(jMsg)
		env->DeleteLocalRef(jMsg);
	if(jPositiveButton)
		env->DeleteLocalRef(jPositiveButton);

}

void wyUtils::convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event) {
	JNIEnv* env = wyUtils::getJNIEnv();
	event->keyCode = (wyKeyCode)env->CallIntMethod(pe, g_mid_KeyEvent_getKeyCode);
	event->repeatCount = env->CallIntMethod(pe, g_mid_KeyEvent_getRepeatCount);
	event->downTime = (int64_t)env->CallLongMethod(pe, g_mid_KeyEvent_getDownTime);
	event->eventTime = (int64_t)env->CallLongMethod(pe, g_mid_KeyEvent_getEventTime);
}

void wyUtils::convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type) {
	JNIEnv* env = wyUtils::getJNIEnv();
	event->pointerCount = wyDevice::apiLevel > 4 ? env->CallIntMethod(pe, g_mid_MotionEvent_getPointerCount) : 1;
	event->pressure = env->CallFloatMethod(pe, g_mid_MotionEvent_getPressure);
	event->downTime = (int64_t)env->CallLongMethod(pe, g_mid_MotionEvent_getDownTime);
	event->eventTime = (int64_t)env->CallLongMethod(pe, g_mid_MotionEvent_getEventTime);

	if(wyDevice::apiLevel > 4) {
		// read event index
		int action = env->CallIntMethod(pe, g_mid_MotionEvent_getAction);
		event->index = (action & g_enum_MotionEvent_ACTION_POINTER_ID_MASK) >> g_enum_MotionEvent_ACTION_POINTER_ID_SHIFT;

		// read pointer info
		for(int i = 0; i < event->pointerCount; i++) {
			/*
			 * XXX: in some rom, may get a pointer index out of range error,
			 * currently the reason is not clear, so we make a error catch to
			 * avoid app crash
			 */
			event->pid[i] = env->CallIntMethod(pe, g_mid_MotionEvent_getPointerId, i);
			event->x[i] = env->CallFloatMethod(pe, g_mid_MotionEvent_getX_I, i);
			if(env->ExceptionOccurred() != NULL) {
				env->ExceptionClear();
				event->x[i] = 0;
			}
			event->y[i] = wyDevice::realHeight - env->CallFloatMethod(pe, g_mid_MotionEvent_getY_I, i);
			if(env->ExceptionOccurred() != NULL) {
				env->ExceptionClear();
				event->y[i] = 0;
			}

			// if not density scale mode, must convert coordinates relative to base size
			if(wyDevice::scaleMode != SCALE_MODE_BY_DENSITY) {
				event->x[i] = event->x[i] / wyDevice::baseScaleX;
				event->y[i] = event->y[i] / wyDevice::baseScaleY;
			}
		}
	} else {
		event->index = 0;
		event->pid[0] = 0;
		event->x[0] = env->CallFloatMethod(pe, g_mid_MotionEvent_getX);
		event->y[0] = wyDevice::realHeight - env->CallFloatMethod(pe, g_mid_MotionEvent_getY);

		// if not density scale mode, must convert coordinates relative to base size
		if(wyDevice::scaleMode != SCALE_MODE_BY_DENSITY) {
			event->x[0] = event->x[0] / wyDevice::baseScaleX;
			event->y[0] = event->y[0] / wyDevice::baseScaleY;
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

	// ensure intermediate folder is created
	createIntermediateFolders(path);

	// open file
	FILE* f = NULL;
	if((f = fopen(path, "wb")) == NULL) {
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
	png_bytep row_pointers[height];
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
	FILE* outfile;                      /* target file */

	/* Now we can initialize the JPEG compression object. */
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

	if ((outfile = fopen(path, "wb")) == NULL) {
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
	// get env
	JNIEnv* env = getEnv();

	// check null
	if(fullName == NULL) {
		LOGW("getResId: can't resolve empty name");
		return 0;
	}

	// check length, minimum is 5 because R.a.b is the simplest name
	size_t len = strlen(fullName);
	if(len < 5) {
		LOGW("getResId: not a valid res full name");
		return 0;
	}

	// if not start with R., return 0
	if(fullName[0] != 'R' || fullName[1] != '.') {
		LOGW("getResId: need pass in a full name such as R.drawable.abc");
		return 0;
	}

	// find second dot
	char* dot = strchr(fullName + 2, '.');
	if(dot == NULL) {
		LOGW("getResId: not a valid res full name");
		return 0;
	}

	// copy type
	int typeLen = dot - fullName - 2;
	char* type = (char*)wyCalloc(typeLen + 1, sizeof(char));
	memcpy(type, fullName + 2, typeLen * sizeof(char));
	const char* name = (const char*)(dot + 1);

	// get res id
	int id = getResId(name, (const char*)type, NULL);

	// free type
	wyFree(type);

	return id;
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

	// get env
	JNIEnv* env = getEnv();

	// generate name string
	jstring n = env->NewStringUTF(tmp);
	jstring t = env->NewStringUTF(type);
	jstring t2 = type2 != NULL ? env->NewStringUTF(type2) : NULL;

	// get context
	jobject context = wyDirector::getInstance()->getContext();

	// get resources and package name
	jobject res = env->CallObjectMethod(context, g_mid_Context_getResources);
	jstring pkg = (jstring)env->CallObjectMethod(context, g_mid_Context_getPackageName);

	// get id
	resId = env->CallIntMethod(res, g_mid_Resources_getIdentifier, n, t, pkg);
	if(resId == 0 && t2 != NULL)
		resId = env->CallIntMethod(res, g_mid_Resources_getIdentifier, n, t2, pkg);

	// delete ref
	env->DeleteLocalRef(res);
	env->DeleteLocalRef(pkg);
	env->DeleteLocalRef(n);
	env->DeleteLocalRef(t);
	if(t2 != NULL)
		env->DeleteLocalRef(t2);

	// free
	wyFree(tmp);

	return resId;
}

const char* wyUtils::getString(int resId) {
	if(resId == 0)
		return NULL;
	else {
		// get env
		JNIEnv* env = getEnv();

		// get context
		jobject context = wyDirector::getInstance()->getContext();

		// get resources
		jobject res = env->CallObjectMethod(context, g_mid_Context_getResources);

		// get string
		jstring s = (jstring)env->CallObjectMethod(res, g_mid_Resources_getString, resId);

		// get c string
		const char* cs = (const char*)env->GetStringUTFChars(s, NULL);

		// copy
		const char* ret = copy(cs);

		// delete reference
		env->DeleteLocalRef(res);
		env->ReleaseStringUTFChars(s, cs);

		return ret;
	}
}

const char16_t* wyUtils::getString16(int resId) {
	if(resId == 0)
		return NULL;
	else {
		// get env
		JNIEnv* env = getEnv();

		// get context
		jobject context = wyDirector::getInstance()->getContext();

		// get resources
		jobject res = env->CallObjectMethod(context, g_mid_Context_getResources);

		// get string
		jstring s = (jstring)env->CallObjectMethod(res, g_mid_Resources_getString, resId);

		// get c string
		const char16_t* cs = (const char16_t*)env->GetStringChars(s, NULL);

		// copy
		size_t len = env->GetStringLength(s);
	    char16_t* ret = (char16_t*)wyCalloc(len + 1, sizeof(char16_t));
	    memcpy(ret, cs, len * sizeof(char16_t));
        ret[len] = 0;

		// delete reference
		env->DeleteLocalRef(res);
		env->ReleaseStringChars(s, cs);

		return ret;
	}
}

const char* wyUtils::utf16toutf8(const char16_t* s16) {
	JNIEnv* env = getJNIEnv();
	int len = strlen16(s16);
	jstring s = env->NewString(s16, len);
	jsize len8 = env->GetStringUTFLength(s);
	const char* b = (const char*)env->GetStringUTFChars(s, NULL);
	char* ret = (char*)wyCalloc(len8 + 1, sizeof(char));
	memcpy(ret, b, len8 * sizeof(char));
	env->ReleaseStringUTFChars(s, b);
	env->DeleteLocalRef(s);

	return ret;
}

const char* wyUtils::wctoutf8(const wchar_t* ws) {
	return NULL;
}

const char16_t* wyUtils::toUTF16(const char* s8) {
	return NULL;
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile, float width) {
	// call jni
	JNIEnv* env = getJNIEnv();
	jstring jText = env->NewStringUTF(text);
	jstring jFontPath = env->NewStringUTF(fontPath);
	jobject jSize = env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_calculateTextSize_by_fontPath,
			jText,
			fontSize,
			jFontPath,
			isFile,
			width);

	// create size
	wySize s = wyUtils_android::to_wySize(jSize);

	// release
	env->DeleteLocalRef(jText);
	env->DeleteLocalRef(jFontPath);
	env->DeleteLocalRef(jSize);

	return s;
}

wySize wyUtils::calculateTextSize(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width) {
	// call jni
	JNIEnv* env = getJNIEnv();
	jstring jText = env->NewStringUTF(text);
	jstring jFontName = env->NewStringUTF(fontName);
	jobject jSize = env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_calculateTextSize_by_fontStyle,
			jText,
			fontSize,
			(int)style,
			jFontName,
			width);

	// create size
	wySize s = wyUtils_android::to_wySize(jSize);

	// release
	env->DeleteLocalRef(jText);
	env->DeleteLocalRef(jFontName);
	env->DeleteLocalRef(jSize);

	return s;
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	// call jni
	JNIEnv* env = getJNIEnv();
	jstring jText = env->NewStringUTF(text);
	jstring jFontPath = env->NewStringUTF(fontPath == NULL ? "DroidSans" : fontPath);
	jbyteArray jBytes = (jbyteArray)env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_createLabelBitmap_by_fontPath,
			jText,
			fontSize,
			jFontPath,
			isFile,
			width,
			(int)alignment);

	// copy data
	jsize len = env->GetArrayLength(jBytes);
	char* data = (char*)malloc(len * sizeof(char));
	jbyte* bytes = env->GetByteArrayElements(jBytes, NULL);
	memcpy(data, bytes, sizeof(char) * len);

	// release
	env->ReleaseByteArrayElements(jBytes, bytes, 0);
	env->DeleteLocalRef(jText);
	env->DeleteLocalRef(jFontPath);
	env->DeleteLocalRef(jBytes);

	return data;
}

const char* wyUtils::createLabelBitmap(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	// call jni
	JNIEnv* env = getJNIEnv();
	jstring jText = env->NewStringUTF(text);
	jstring jFontName = env->NewStringUTF(fontName);
	jbyteArray jBytes = (jbyteArray)env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_createLabelBitmap_by_fontStyle,
			jText,
			fontSize,
			(int)style,
			jFontName,
			width,
			(int)alignment);

	// copy data
	jsize len = env->GetArrayLength(jBytes);
	char* data = (char*)malloc(len * sizeof(char));
	jbyte* bytes = env->GetByteArrayElements(jBytes, NULL);
	memcpy(data, bytes, sizeof(char) * len);

	// release
	env->ReleaseByteArrayElements(jBytes, bytes, 0);
	env->DeleteLocalRef(jText);
	env->DeleteLocalRef(jFontName);
	env->DeleteLocalRef(jBytes);

	return data;
}

bool wyUtils::deleteFile(const char* path) {
	return unlink(path) == 0;
}

bool wyUtils::createFolder(const char* path) {
	return mkdir(path) == 0;
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
		if ((image_data = (char*)wyMalloc(height * rowbytes)) == NULL) {
			LOGW("allocate png data buffer failed");
			png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
			return NULL;
		}

		// allocate memory for row pointers
		png_bytepp row_pointers;
		if ((row_pointers = (png_bytepp)wyMalloc(height * sizeof(png_bytep))) == NULL) {
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
}

char* wyUtils::loadRaw(int resId, size_t* outLen, float* outScale, bool noDecode) {
	return NULL;
}

char* wyUtils::loadRaw(const char* path, bool isFile, size_t* outLen, bool noDecode) {
	JNIEnv* env = getJNIEnv();
	jstring jPath = env->NewStringUTF(path);
	jbyteArray jBytes = (jbyteArray)env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_loadAsset,
			jPath,
			isFile);

	// copy data
	jsize len = env->GetArrayLength(jBytes);
	char* data = (char*)malloc(len * sizeof(char));
	jbyte* bytes = env->GetByteArrayElements(jBytes, NULL);
	memcpy(data, bytes, sizeof(char) * len);

	// len
	if(outLen) {
		*outLen = len;
	}

	// release
	env->ReleaseByteArrayElements(jBytes, bytes, 0);
	env->DeleteLocalRef(jPath);
	env->DeleteLocalRef(jBytes);

	// decode
	const char* decoded = decodeObfuscatedData(data, *outLen, outLen);
	if(decoded != data) {
		wyFree(data);
		data = (char*)decoded;
	}

	return data;
}

char* wyUtils::loadCString(const char* path, bool isFile) {
	return NULL;
}

char* wyUtils::loadCString(int resId) {
	return NULL;
}

char* wyUtils::scaleImage(char* originData, int originWidth, int originHeight, float scaleX, float scaleY) {
	JNIEnv* env = getJNIEnv();

	// java array
	jsize len = originWidth * originHeight * 4;
	jbyteArray jArray = env->NewByteArray(len);
	env->SetByteArrayRegion(jArray, 0, len, (const jbyte*)originData);

	// call
	jbyteArray jBytes = (jbyteArray)env->CallStaticObjectMethod(gClass_Utilities,
			g_mid_Utilities_scaleImage,
			jArray,
			originWidth,
			originHeight,
			scaleX,
			scaleY);

	// copy data
	len = env->GetArrayLength(jBytes);
	char* data = (char*)malloc(len * sizeof(char));
	jbyte* bytes = env->GetByteArrayElements(jBytes, NULL);
	memcpy(data, bytes, sizeof(char) * len);

	// release
	env->ReleaseByteArrayElements(jBytes, bytes, 0);
	env->DeleteLocalRef(jArray);
	env->DeleteLocalRef(jBytes);

	return data;
}

const char* wyUtils::mapLocalPath(const char* path) {
	return copy(path);
}

const char* wyUtils::mapAssetsPath(const char* path) {
	return copy(path);
}

void wyUtils::playVideo(int resId) {
	jobject i = wyUtils_android::newIntent("com.wiyun.engine.utils.VideoPlayingActivity");
	wyUtils_android::putIntExtra(i, "EXTRA_IN_VIDEO_RES_ID", resId);
	wyUtils_android::putBooleanExtra(i, "EXTRA_IN_END_ON_TOUCH", true);
	wyUtils_android::putBooleanExtra(i, "EXTRA_IN_NO_COMPLETION_DIALOG", true);
	wyUtils_android::startActivity(i);
}

void wyUtils::playVideo(const char* path, bool isFile) {
	jobject i = wyUtils_android::newIntent("com.wiyun.engine.utils.VideoPlayingActivity");
	wyUtils_android::putStringExtra(i, "EXTRA_IN_VIDEO_ASSET_PATH", path);
	wyUtils_android::putBooleanExtra(i, "EXTRA_IN_VIDEO_IS_FILE", isFile);
	wyUtils_android::putBooleanExtra(i, "EXTRA_IN_END_ON_TOUCH", true);
	wyUtils_android::putBooleanExtra(i, "EXTRA_IN_NO_COMPLETION_DIALOG", true);
	wyUtils_android::startActivity(i);
}

void wyUtils::openUrl(const char* url) {
	JNIEnv* env = wyUtils::getJNIEnv();
	jstring s = env->NewStringUTF(url);
	jmethodID mid = env->GetStaticMethodID(gClass_Director, "openUrl", "(Ljava/lang/String;)V");
	env->CallStaticVoidMethod(gClass_Director, mid, s);
	env->DeleteLocalRef(s);
}

bool wyUtils::isPathExistent(const char* path) {
	if(path == NULL)
		return true;
	const char* mappedPath = mapLocalPath(path);
	bool ret = access(mappedPath, 0) == 0;
	wyFree((void*)mappedPath);
	return ret;
}

bool wyUtils::isResExistent(const char* path, bool isFile) {
	return true;
}

JNIEnv* wyUtils::getJNIEnv() {
	return getEnv();
}

void wyUtils::addAndroidStrings(const char* fileName, const char* langId) {
	// no need to add android strings in android platform
}

bool wyUtils::verifySignature(void* validSign, size_t len) {
	// basic check
	if(!validSign)
		return true;

	// get env
	JNIEnv* env = getJNIEnv();

	// get package manager
	wyGLContext ctx = wyDirector::getInstance()->getContext();
	jclass klazz = env->GetObjectClass(ctx);
	jmethodID mid = env->GetMethodID(klazz, "getPackageManager", "()Landroid/content/pm/PackageManager;");
	jobject packageManager = env->CallObjectMethod(ctx, mid);

	// get package name
	mid = env->GetMethodID(klazz, "getPackageName", "()Ljava/lang/String;");
	jstring packageName = (jstring) env->CallObjectMethod(ctx, mid);

	// release context class reference
	env->DeleteLocalRef(klazz);

	// get package info
	klazz = env->GetObjectClass(packageManager);
	mid = env->GetMethodID(klazz, "getPackageInfo", "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
	jint flags = env->GetStaticIntField(klazz, env->GetStaticFieldID(klazz, "GET_SIGNATURES", "I"));
	jobject packageInfo = env->CallObjectMethod(packageManager, mid, packageName, flags);

	// clea reference
	env->DeleteLocalRef(klazz);
	env->DeleteLocalRef(packageName);

	// get first signature java object
	klazz = env->GetObjectClass(packageInfo);
	jobjectArray signatures = (jobjectArray)env->GetObjectField(packageInfo,
			env->GetFieldID(klazz, "signatures", "[Landroid/content/pm/Signature;"));
	jobject signature = env->GetObjectArrayElement(signatures, 0);

	// clear reference
	env->DeleteLocalRef(klazz);

	// get byte array of signature
	klazz = env->GetObjectClass(signature);
	mid = env->GetMethodID(klazz, "toByteArray", "()[B");
	jbyteArray certificate = (jbyteArray)env->CallObjectMethod(signature, mid);

	// clear reference
	env->DeleteLocalRef(klazz);
	env->DeleteLocalRef(signature);

	// md5
	bool valid = true;
	jsize cLen = env->GetArrayLength(certificate);
	jbyte* cData = env->GetByteArrayElements(certificate, JNI_FALSE);
	if (cLen > 0) {
		const char* md5 = wyMD5::md5(cData, cLen);
		size_t md5Len = strlen(md5);
		if(md5Len != len) {
			valid = false;
		} else {
			char* p = (char*)validSign;
			for(size_t i = 0; i < md5Len; i++) {
				if(md5[i] != p[i]) {
					valid = false;
					break;
				}
			}
		}
	}

	// release
	env->ReleaseByteArrayElements(certificate, cData, 0);
	env->DeleteLocalRef(certificate);

	// return
	return valid;
}

#endif // #if ANDROID
