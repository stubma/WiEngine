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

#include <jni.h>
#include "wyInit.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyDevice.h"

// preload class
jclass gClass_Director;
jclass gClass_Accelerometer;
jclass gClass_PrefUtil;
jclass gClass_AudioManager;
jclass gClass_TextBox;
jclass gClass_ImagePicker;

// BaseObject
jfieldID g_fid_BaseObject_mPointer;

// Activity
jmethodID g_mid_Activity_getRequestedOrientation;

// ActivityInfo
int g_enum_ActivityInfo_SCREEN_ORIENTATION_LANDSCAPE;

// PrefUtil
jmethodID g_mid_PrefUtil_getIntPref;
jmethodID g_mid_PrefUtil_setIntPref;
jmethodID g_mid_PrefUtil_getStringPref;
jmethodID g_mid_PrefUtil_setStringPref;
jmethodID g_mid_PrefUtil_getBoolPref;
jmethodID g_mid_PrefUtil_setBoolPref;
jmethodID g_mid_PrefUtil_getLongPref;
jmethodID g_mid_PrefUtil_setLongPref;
jmethodID g_mid_PrefUtil_clear;
jmethodID g_mid_PrefUtil_remove;

// ImagePicker
jmethodID g_mid_ImagePicker_hasCamera;
jmethodID g_mid_ImagePicker_hasFrontCamera;
jmethodID g_mid_ImagePicker_pickFromCamera;
jmethodID g_mid_ImagePicker_pickFromAlbum;

// Accelerometer
jmethodID g_mid_Accelerometer_getInstance;
jmethodID g_mid_Accelerometer_checkAccelHandlers;

// FileDescriptor class field
jfieldID g_fid_FileDescriptor_descriptor;

// Director
jmethodID g_mid_Director_getInstance;
jmethodID g_mid_Director_internalEnd;
jmethodID g_mid_Director_setAccelerometerDelay;
jmethodID g_mid_Director_showConfirmDialog;
jmethodID g_mid_Director_showAlertDialog;
jmethodID g_mid_Director_getLanguage;
jmethodID g_mid_Director_getCountry;
jmethodID g_mid_Director_hasPermission;
jmethodID g_mid_Director_getDeviceUniqueString;
jmethodID g_mid_Director_getDeviceIMEI;
jmethodID g_mid_Director_hasExternalStorage;

// WYGLSurfaceView
jmethodID g_mid_WYGLSurfaceView_onPause;
jmethodID g_mid_WYGLSurfaceView_onResume;

// Context
jmethodID g_mid_Context_getResources;
jmethodID g_mid_Context_getPackageName;
jmethodID g_mid_Context_startActivity;
jmethodID g_mid_Context_sendBroadcast;

// Resources
jmethodID g_mid_Resources_getIdentifier;
jmethodID g_mid_Resources_getDisplayMetrics;
jmethodID g_mid_Resources_getString;

// KeyEvent
jmethodID g_mid_KeyEvent_getKeyCode;
jmethodID g_mid_KeyEvent_getRepeatCount;
jmethodID g_mid_KeyEvent_getDownTime;
jmethodID g_mid_KeyEvent_getEventTime;

// MotionEvent
jmethodID g_mid_MotionEvent_getAction;
jmethodID g_mid_MotionEvent_getPointerCount;
jmethodID g_mid_MotionEvent_getPointerId;
jmethodID g_mid_MotionEvent_getPressure;
jmethodID g_mid_MotionEvent_getDownTime;
jmethodID g_mid_MotionEvent_getEventTime;
jmethodID g_mid_MotionEvent_getX;
jmethodID g_mid_MotionEvent_getX_I;
jmethodID g_mid_MotionEvent_getY;
jmethodID g_mid_MotionEvent_getY_I;
int g_enum_MotionEvent_ACTION_POINTER_ID_MASK;
int g_enum_MotionEvent_ACTION_POINTER_ID_SHIFT;

// DisplayMetrics
jfieldID g_fid_DisplayMetrics_density;
jfieldID g_fid_DisplayMetrics_scaledDensity;
jfieldID g_fid_DisplayMetrics_widthPixels;
jfieldID g_fid_DisplayMetrics_heightPixels;

// intent
jmethodID g_mid_Intent_init;
jmethodID g_mid_Intent_init_S;
jmethodID g_mid_Intent_putExtra_Z;
jmethodID g_mid_Intent_putExtra_B;
jmethodID g_mid_Intent_putExtra_C;
jmethodID g_mid_Intent_putExtra_D;
jmethodID g_mid_Intent_putExtra_F;
jmethodID g_mid_Intent_putExtra_I;
jmethodID g_mid_Intent_putExtra_String;
jmethodID g_mid_Intent_putExtra_J;
jmethodID g_mid_Intent_putExtra_S;
jmethodID g_mid_Intent_putExtra_Parcelable;

// TextBox
jmethodID g_mid_TextBox_showInputDialog;

// Gravity
int g_enum_Gravity_BOTTOM;

// Runnable
jmethodID g_mid_Runnable_run;

// Map
jmethodID g_mid_Map_put;

#ifdef __cplusplus
extern "C" {
#endif

void globalInit(JNIEnv* env) {
	// load global class
	jclass c = env->FindClass(CLASS_DIRECTOR);
	gClass_Director = (jclass)env->NewGlobalRef(c);
	c = env->FindClass(CLASS_ACCELEROMETER);
	gClass_Accelerometer = (jclass)env->NewGlobalRef(c);
	c = env->FindClass(CLASS_PREFUTIL);
	gClass_PrefUtil = (jclass)env->NewGlobalRef(c);
	c = env->FindClass(CLASS_AUDIOMANAGER);
	gClass_AudioManager = (jclass)env->NewGlobalRef(c);
	c = env->FindClass(CLASS_TEXTBOX);
	gClass_TextBox = (jclass)env->NewGlobalRef(c);
	c = env->FindClass(CLASS_IMAGEPICKER);
	gClass_ImagePicker = (jclass)env->NewGlobalRef(c);

	jclass clazz = env->FindClass(CLASS_VERSION);
	jfieldID sdkInt = env->GetStaticFieldID(clazz, "SDK_INT", "I");
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
		wyDevice::apiLevel = 3;
	} else {
		wyDevice::apiLevel = env->GetStaticIntField(clazz, sdkInt);
	}
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_BASEOBJECT);
	g_fid_BaseObject_mPointer = env->GetFieldID(clazz, "mPointer", "I");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ACTIVITY);
	g_mid_Activity_getRequestedOrientation = env->GetMethodID(clazz, "getRequestedOrientation", "()I");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ACTIVITYINFO);
	jfieldID fieldID = env->GetStaticFieldID(clazz, "SCREEN_ORIENTATION_LANDSCAPE", "I");
	g_enum_ActivityInfo_SCREEN_ORIENTATION_LANDSCAPE = env->GetStaticIntField(clazz, fieldID);
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ACCELEROMETER);
	g_mid_Accelerometer_getInstance = env->GetStaticMethodID(clazz, "getInstance", "()Lcom/wiyun/engine/events/Accelerometer;");
	g_mid_Accelerometer_checkAccelHandlers = env->GetMethodID(clazz, "checkAccelHandlers", "()V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_FILEDESCRIPTOR);
	g_fid_FileDescriptor_descriptor = env->GetFieldID(clazz, "descriptor", "I");
	env->DeleteLocalRef(clazz);

	g_mid_Director_getInstance = env->GetStaticMethodID(gClass_Director, "getInstance", "()Lcom/wiyun/engine/nodes/Director;");
	g_mid_Director_internalEnd = env->GetMethodID(gClass_Director, "internalEnd", "()V");
	g_mid_Director_setAccelerometerDelay = env->GetMethodID(gClass_Director, "setAccelerometerDelay", "(I)V");
	g_mid_Director_showConfirmDialog = env->GetStaticMethodID(gClass_Director, "showConfirmDialog", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;II)V");
    g_mid_Director_showAlertDialog = env->GetStaticMethodID(gClass_Director, "showAlertDialog", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
	g_mid_Director_getLanguage = env->GetStaticMethodID(gClass_Director, "getLanguage", "()Ljava/lang/String;");
	g_mid_Director_getCountry = env->GetStaticMethodID(gClass_Director, "getCountry", "()Ljava/lang/String;");
	g_mid_Director_hasPermission = env->GetStaticMethodID(gClass_Director, "hasPermission", "(Ljava/lang/String;)Z");
	g_mid_Director_getDeviceIMEI = env->GetStaticMethodID(gClass_Director, "getDeviceIMEI", "()Ljava/lang/String;");
	g_mid_Director_getDeviceUniqueString = env->GetStaticMethodID(gClass_Director, "getDeviceUniqueString", "()Ljava/lang/String;");
	g_mid_Director_hasExternalStorage = env->GetStaticMethodID(gClass_Director, "hasExternalStorage", "()Z");

	clazz = env->FindClass(CLASS_WYGLSURFACEVIEW);
	g_mid_WYGLSurfaceView_onPause = env->GetMethodID(clazz, "onPause", "()V");
	g_mid_WYGLSurfaceView_onResume = env->GetMethodID(clazz, "onResume", "()V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_CONTEXT);
	g_mid_Context_getResources = env->GetMethodID(clazz, "getResources", "()Landroid/content/res/Resources;");
	g_mid_Context_getPackageName = env->GetMethodID(clazz, "getPackageName", "()Ljava/lang/String;");
	g_mid_Context_startActivity = env->GetMethodID(clazz, "startActivity", "(Landroid/content/Intent;)V");
	g_mid_Context_sendBroadcast = env->GetMethodID(clazz, "sendBroadcast", "(Landroid/content/Intent;)V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_RESOURCES);
	g_mid_Resources_getIdentifier = env->GetMethodID(clazz, "getIdentifier", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
	g_mid_Resources_getDisplayMetrics = env->GetMethodID(clazz, "getDisplayMetrics", "()Landroid/util/DisplayMetrics;");
	g_mid_Resources_getString = env->GetMethodID(clazz, "getString", "(I)Ljava/lang/String;");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_KEYEVENT);
	g_mid_KeyEvent_getKeyCode = env->GetMethodID(clazz, "getKeyCode", "()I");
	g_mid_KeyEvent_getRepeatCount = env->GetMethodID(clazz, "getRepeatCount", "()I");
	g_mid_KeyEvent_getDownTime = env->GetMethodID(clazz, "getDownTime", "()J");
	g_mid_KeyEvent_getEventTime = env->GetMethodID(clazz, "getEventTime", "()J");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_MOTIONEVENT);
	g_mid_MotionEvent_getAction = env->GetMethodID(clazz, "getAction", "()I");
	g_mid_MotionEvent_getPointerCount = env->GetMethodID(clazz, "getPointerCount", "()I");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	g_mid_MotionEvent_getPointerId = env->GetMethodID(clazz, "getPointerId", "(I)I");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	g_mid_MotionEvent_getPressure = env->GetMethodID(clazz, "getPressure", "()F");
	g_mid_MotionEvent_getDownTime = env->GetMethodID(clazz, "getDownTime", "()J");
	g_mid_MotionEvent_getEventTime = env->GetMethodID(clazz, "getEventTime", "()J");
	g_mid_MotionEvent_getX = env->GetMethodID(clazz, "getX", "()F");
	g_mid_MotionEvent_getX_I = env->GetMethodID(clazz, "getX", "(I)F");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	g_mid_MotionEvent_getY = env->GetMethodID(clazz, "getY", "()F");
	g_mid_MotionEvent_getY_I = env->GetMethodID(clazz, "getY", "(I)F");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	fieldID = env->GetStaticFieldID(clazz, "ACTION_POINTER_ID_MASK", "I");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	else
		g_enum_MotionEvent_ACTION_POINTER_ID_MASK = env->GetStaticIntField(clazz, fieldID);
	fieldID = env->GetStaticFieldID(clazz, "ACTION_POINTER_ID_SHIFT", "I");
	if(env->ExceptionOccurred() != NULL)
		env->ExceptionClear();
	else
		g_enum_MotionEvent_ACTION_POINTER_ID_SHIFT = env->GetStaticIntField(clazz, fieldID);
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_DISPLAYMETRICS);
	g_fid_DisplayMetrics_density = env->GetFieldID(clazz, "density", "F");
	g_fid_DisplayMetrics_scaledDensity = env->GetFieldID(clazz, "scaledDensity", "F");
	g_fid_DisplayMetrics_widthPixels = env->GetFieldID(clazz, "widthPixels", "I");
	g_fid_DisplayMetrics_heightPixels = env->GetFieldID(clazz, "heightPixels", "I");
	env->DeleteLocalRef(clazz);

	g_mid_ImagePicker_hasCamera = env->GetStaticMethodID(gClass_ImagePicker, "hasCamera", "()Z");
	g_mid_ImagePicker_hasFrontCamera = env->GetStaticMethodID(gClass_ImagePicker, "hasFrontCamera", "()Z");
	g_mid_ImagePicker_pickFromCamera = env->GetStaticMethodID(gClass_ImagePicker, "pickFromCamera", "(IIIIZZ)V");
	g_mid_ImagePicker_pickFromAlbum = env->GetStaticMethodID(gClass_ImagePicker, "pickFromAlbum", "(IIIIZ)V");

	g_mid_PrefUtil_getIntPref = env->GetStaticMethodID(gClass_PrefUtil, "getIntPref", "(Ljava/lang/String;I)I");
	g_mid_PrefUtil_setIntPref = env->GetStaticMethodID(gClass_PrefUtil, "setIntPref", "(Ljava/lang/String;I)V");
	g_mid_PrefUtil_getStringPref = env->GetStaticMethodID(gClass_PrefUtil, "getStringPref", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
	g_mid_PrefUtil_setStringPref = env->GetStaticMethodID(gClass_PrefUtil, "setStringPref", "(Ljava/lang/String;Ljava/lang/String;)V");
	g_mid_PrefUtil_getBoolPref = env->GetStaticMethodID(gClass_PrefUtil, "getBoolPref", "(Ljava/lang/String;Z)Z");
	g_mid_PrefUtil_setBoolPref = env->GetStaticMethodID(gClass_PrefUtil, "setBoolPref", "(Ljava/lang/String;Z)V");
	g_mid_PrefUtil_getLongPref = env->GetStaticMethodID(gClass_PrefUtil, "getLongPref", "(Ljava/lang/String;J)J");
	g_mid_PrefUtil_setLongPref = env->GetStaticMethodID(gClass_PrefUtil, "setLongPref", "(Ljava/lang/String;J)V");
	g_mid_PrefUtil_clear = env->GetStaticMethodID(gClass_PrefUtil, "clear", "()V");
	g_mid_PrefUtil_remove = env->GetStaticMethodID(gClass_PrefUtil, "remove", "(Ljava/lang/String;)V");

	clazz = env->FindClass(CLASS_INTENT);
	g_mid_Intent_init = env->GetMethodID(clazz, "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V");
	g_mid_Intent_init_S = env->GetMethodID(clazz, "<init>", "(Ljava/lang/String;)V");
	g_mid_Intent_putExtra_Z = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;Z)Landroid/content/Intent;");
	g_mid_Intent_putExtra_B = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;B)Landroid/content/Intent;");
	g_mid_Intent_putExtra_C = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;C)Landroid/content/Intent;");
	g_mid_Intent_putExtra_D = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;D)Landroid/content/Intent;");
	g_mid_Intent_putExtra_F = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;F)Landroid/content/Intent;");
	g_mid_Intent_putExtra_I = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;I)Landroid/content/Intent;");
	g_mid_Intent_putExtra_String = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;");
	g_mid_Intent_putExtra_J = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;J)Landroid/content/Intent;");
	g_mid_Intent_putExtra_S = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;S)Landroid/content/Intent;");
	g_mid_Intent_putExtra_Parcelable = env->GetMethodID(clazz, "putExtra", "(Ljava/lang/String;Landroid/os/Parcelable;)Landroid/content/Intent;");
	env->DeleteLocalRef(clazz);

	g_mid_TextBox_showInputDialog = env->GetStaticMethodID(gClass_TextBox, "showInputDialog", "(I)V");

	clazz = env->FindClass(CLASS_GRAVITY);
	fieldID = env->GetStaticFieldID(clazz, "BOTTOM", "I");
	g_enum_Gravity_BOTTOM = env->GetStaticIntField(clazz, fieldID);
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_RUNNABLE);
	g_mid_Runnable_run = env->GetMethodID(clazz, "run", "()V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_MAP);
	g_mid_Map_put = env->GetMethodID(clazz, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	env->DeleteLocalRef(clazz);
}

void globalDeInit(JNIEnv* env) {
	env->DeleteGlobalRef(gClass_Director);
	gClass_Director = NULL;
	env->DeleteGlobalRef(gClass_Accelerometer);
	gClass_Accelerometer = NULL;
	env->DeleteGlobalRef(gClass_PrefUtil);
	gClass_PrefUtil = NULL;
	env->DeleteGlobalRef(gClass_AudioManager);
	gClass_AudioManager = NULL;
	env->DeleteGlobalRef(gClass_TextBox);
	gClass_TextBox = NULL;
	env->DeleteGlobalRef(gClass_ImagePicker);
	gClass_ImagePicker = NULL;
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
