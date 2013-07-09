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
jclass gClass_Utilities;

// BaseObject
jfieldID g_fid_BaseObject_mPointer;

// BaseWYObject
jmethodID g_mid_BaseWYObject_onTargetSelectorInvoked;

// WYPoint class fields
jfieldID g_fid_WYPoint_x;
jfieldID g_fid_WYPoint_y;

// WYPointList
jmethodID g_mid_WYPointList_addPoint_xy;
jmethodID g_mid_WYPointList_addPoint_p;

// WYDimension class fields
jfieldID g_fid_WYDimension_x;
jfieldID g_fid_WYDimension_y;

// WYRect class fields
jfieldID g_fid_WYRect_origin;
jfieldID g_fid_WYRect_size;

// WYVertex3D class fields
jfieldID g_fid_WYVertex3D_x;
jfieldID g_fid_WYVertex3D_y;
jfieldID g_fid_WYVertex3D_z;

// WYColor3B class fields
jfieldID g_fid_WYColor3B_r;
jfieldID g_fid_WYColor3B_g;
jfieldID g_fid_WYColor3B_b;

// WYColor3F class fields
jfieldID g_fid_WYColor3F_r;
jfieldID g_fid_WYColor3F_g;
jfieldID g_fid_WYColor3F_b;

// WYColor4B class fields
jfieldID g_fid_WYColor4B_r;
jfieldID g_fid_WYColor4B_g;
jfieldID g_fid_WYColor4B_b;
jfieldID g_fid_WYColor4B_a;

// WYColor4F class fields
jfieldID g_fid_WYColor4F_r;
jfieldID g_fid_WYColor4F_g;
jfieldID g_fid_WYColor4F_b;
jfieldID g_fid_WYColor4F_a;

// WYQuad2D class fields
jfieldID g_fid_WYQuad2D_bl_x;
jfieldID g_fid_WYQuad2D_bl_y;
jfieldID g_fid_WYQuad2D_br_x;
jfieldID g_fid_WYQuad2D_br_y;
jfieldID g_fid_WYQuad2D_tl_x;
jfieldID g_fid_WYQuad2D_tl_y;
jfieldID g_fid_WYQuad2D_tr_x;
jfieldID g_fid_WYQuad2D_tr_y;

// WYQuad3D class fields
jfieldID g_fid_WYQuad3D_bl_x;
jfieldID g_fid_WYQuad3D_bl_y;
jfieldID g_fid_WYQuad3D_bl_z;
jfieldID g_fid_WYQuad3D_br_x;
jfieldID g_fid_WYQuad3D_br_y;
jfieldID g_fid_WYQuad3D_br_z;
jfieldID g_fid_WYQuad3D_tl_x;
jfieldID g_fid_WYQuad3D_tl_y;
jfieldID g_fid_WYQuad3D_tl_z;
jfieldID g_fid_WYQuad3D_tr_x;
jfieldID g_fid_WYQuad3D_tr_y;
jfieldID g_fid_WYQuad3D_tr_z;

// WYBezierConfig class
jfieldID g_fid_WYBezierConfig_cubic;
jfieldID g_fid_WYBezierConfig_startX;
jfieldID g_fid_WYBezierConfig_startY;
jfieldID g_fid_WYBezierConfig_endX;
jfieldID g_fid_WYBezierConfig_endY;
jfieldID g_fid_WYBezierConfig_cp1X;
jfieldID g_fid_WYBezierConfig_cp1Y;
jfieldID g_fid_WYBezierConfig_cp2X;
jfieldID g_fid_WYBezierConfig_cp2Y;

// WYLagrangeConfig class
jfieldID g_fid_WYLagrangeConfig_cubic;
jfieldID g_fid_WYLagrangeConfig_startX;
jfieldID g_fid_WYLagrangeConfig_startY;
jfieldID g_fid_WYLagrangeConfig_endX;
jfieldID g_fid_WYLagrangeConfig_endY;
jfieldID g_fid_WYLagrangeConfig_cp1X;
jfieldID g_fid_WYLagrangeConfig_cp1Y;
jfieldID g_fid_WYLagrangeConfig_cp2X;
jfieldID g_fid_WYLagrangeConfig_cp2Y;
jfieldID g_fid_WYLagrangeConfig_t0;
jfieldID g_fid_WYLagrangeConfig_t1;
jfieldID g_fid_WYLagrangeConfig_t2;
jfieldID g_fid_WYLagrangeConfig_t3;

// WYHypotrochoidConfig class
jfieldID g_fid_WYHypotrochoidConfig_R;
jfieldID g_fid_WYHypotrochoidConfig_r;
jfieldID g_fid_WYHypotrochoidConfig_d;
jfieldID g_fid_WYHypotrochoidConfig_startAngle;
jfieldID g_fid_WYHypotrochoidConfig_endAngle;
jfieldID g_fid_WYHypotrochoidConfig_centreX;
jfieldID g_fid_WYHypotrochoidConfig_centreY;

// WYAffineTransform
jfieldID g_fid_WYAffineTransform_a;
jfieldID g_fid_WYAffineTransform_b;
jfieldID g_fid_WYAffineTransform_c;
jfieldID g_fid_WYAffineTransform_d;
jfieldID g_fid_WYAffineTransform_tx;
jfieldID g_fid_WYAffineTransform_ty;

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

// BitmapRawData
jfieldID g_fid_BitmapRawData_width;
jfieldID g_fid_BitmapRawData_height;
jfieldID g_fid_BitmapRawData_data;

// action callback
jmethodID g_mid_Action_Callback_onStart;
jmethodID g_mid_Action_Callback_onStop;
jmethodID g_mid_Action_Callback_onUpdate;

// TargetSelector
jmethodID g_mid_TargetSelector_setDelta;
jmethodID g_mid_TargetSelector_invoke;

// WYSize class fields
jfieldID g_fid_WYSize_width;
jfieldID g_fid_WYSize_height;

// Accelerometer
jmethodID g_mid_Accelerometer_getInstance;
jmethodID g_mid_Accelerometer_checkAccelHandlers;

// FileDescriptor class field
jfieldID g_fid_FileDescriptor_descriptor;

// Utilities
jmethodID g_mid_Utilities_createLabelBitmap_by_fontPath;
jmethodID g_mid_Utilities_createLabelBitmap_by_fontStyle;
jmethodID g_mid_Utilities_calculateTextSize_by_fontPath;
jmethodID g_mid_Utilities_calculateTextSize_by_fontStyle;
jmethodID g_mid_Utilities_loadAsset;
jmethodID g_mid_Utilities_scaleImage;

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

// IDirectorLifecycleListener
jmethodID g_mid_IDirectorLifecycleListener_onSurfaceCreated;
jmethodID g_mid_IDirectorLifecycleListener_onSurfaceChanged;
jmethodID g_mid_IDirectorLifecycleListener_onSurfaceDestroyed;
jmethodID g_mid_IDirectorLifecycleListener_onDirectorPaused;
jmethodID g_mid_IDirectorLifecycleListener_onDirectorResumed;
jmethodID g_mid_IDirectorLifecycleListener_onDirectorEnded;
jmethodID g_mid_IDirectorLifecycleListener_onDirectorScreenCaptured;

// WYGLSurfaceView
jmethodID g_mid_WYGLSurfaceView_onPause;
jmethodID g_mid_WYGLSurfaceView_onResume;

// INodeVirtualMethods
jmethodID g_mid_INodeVirtualMethods_jOnEnter;
jmethodID g_mid_INodeVirtualMethods_jOnExit;
jmethodID g_mid_INodeVirtualMethods_jOnEnterTransitionDidFinish;
jmethodID g_mid_INodeVirtualMethods_jDraw;

// IMWSpriteCallback
jmethodID g_mid_IMWSpriteCallback_onMWAnimationFrameChanged;
jmethodID g_mid_IMWSpriteCallback_onMWAnimationEnded;

// IAFCSpriteCallback
jmethodID g_mid_IAFCSpriteCallback_onAFCAnimationFrameChanged;
jmethodID g_mid_IAFCSpriteCallback_onAFCAnimationEnded;

// ISPXSpriteCallback
jmethodID g_mid_ISPXSpriteCallback_onSPXActionFrameChanged;
jmethodID g_mid_ISPXSpriteCallback_onSPXActionEnded;

// IPageControlCallback
jmethodID g_mid_IPageControlCallback_onPageClicked;
jmethodID g_mid_IPageControlCallback_onPageChanged;
jmethodID g_mid_IPageControlCallback_onPagePositionChanged;

// ISliderCallback
jmethodID g_mid_ISliderCallback_onSliderValueChanged;

// IScrollableLayerCallback
jmethodID g_mid_IScrollableLayerCallback_onScrollOffsetChanged;
jmethodID g_mid_IScrollableLayerCallback_onStartFling;
jmethodID g_mid_IScrollableLayerCallback_onEndFling;
jmethodID g_mid_IScrollableLayerCallback_onScrollableChildNotVisible;

// IAnimationCallback
jmethodID g_mid_IAnimationCallback_onAnimationFrameChanged;
jmethodID g_mid_IAnimationCallback_onAnimationEnded;

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

// ITouchHandler/IMultiTouchHandler
jmethodID g_mid_ITouchHandler_wyTouchesBegan;
jmethodID g_mid_ITouchHandler_wyTouchesMoved;
jmethodID g_mid_ITouchHandler_wyTouchesEnded;
jmethodID g_mid_ITouchHandler_wyTouchesCancelled;
jmethodID g_mid_IMultiTouchHandler_wyTouchesPointerBegan;
jmethodID g_mid_IMultiTouchHandler_wyTouchesPointerEnded;

// IKeyHandler
jmethodID g_mid_IKeyHandler_wyKeyDown;
jmethodID g_mid_IKeyHandler_wyKeyUp;
jmethodID g_mid_IKeyHandler_wyKeyMultiple;

// IAccelerometerHandler
jmethodID g_mid_IAccelerometerHandler_wyAccelerometerChanged;

// IPositionListener
jmethodID g_mid_IPositionListener_onPositionChanged;

// IVirtualJoystickCallback
jmethodID g_mid_IVirtualJoystickCallback_onVJNavigationStarted;
jmethodID g_mid_IVirtualJoystickCallback_onVJNavigationEnded;
jmethodID g_mid_IVirtualJoystickCallback_onVJDirectionChanged;

// GestureDetector$OnDoubleTapListener
jmethodID g_mid_OnDoubleTapListener_onDoubleTap;
jmethodID g_mid_OnDoubleTapListener_onDoubleTapEvent;
jmethodID g_mid_OnDoubleTapListener_onSingleTapConfirmed;

// GestureDetector$OnGestureListener
jmethodID g_mid_OnGestureListener_onDown;
jmethodID g_mid_OnGestureListener_onFling;
jmethodID g_mid_OnGestureListener_onLongPress;
jmethodID g_mid_OnGestureListener_onScroll;
jmethodID g_mid_OnGestureListener_onShowPress;
jmethodID g_mid_OnGestureListener_onSingleTapUp;

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

// ITextBoxCallback
jmethodID g_mid_ITextBoxCallback_onBeginEditing;
jmethodID g_mid_ITextBoxCallback_onEndEditing;
jmethodID g_mid_ITextBoxCallback_onTextChanged;

// IColorFilterDelegate
jmethodID g_mid_IColorFilterDelegate_apply;

// Gravity
int g_enum_Gravity_BOTTOM;

// Runnable
jmethodID g_mid_Runnable_run;

// Map
jmethodID g_mid_Map_put;

// ResourceDecoder
jmethodID g_mid_ResourceDecoder_decode;

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
	c = env->FindClass(CLASS_UTILITIES);
	gClass_Utilities = (jclass)env->NewGlobalRef(c);

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

	clazz = env->FindClass(CLASS_BASEWYOBJECT);
	g_mid_BaseWYObject_onTargetSelectorInvoked = env->GetMethodID(clazz, "onTargetSelectorInvoked", "(IF)V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ITOUCHHANDLER);
	g_mid_ITouchHandler_wyTouchesBegan = env->GetMethodID(clazz, "wyTouchesBegan", "(Landroid/view/MotionEvent;)Z");
	g_mid_ITouchHandler_wyTouchesMoved = env->GetMethodID(clazz, "wyTouchesMoved", "(Landroid/view/MotionEvent;)Z");
	g_mid_ITouchHandler_wyTouchesEnded = env->GetMethodID(clazz, "wyTouchesEnded", "(Landroid/view/MotionEvent;)Z");
	g_mid_ITouchHandler_wyTouchesCancelled = env->GetMethodID(clazz, "wyTouchesCancelled", "(Landroid/view/MotionEvent;)Z");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_IMULTITOUCHHANDLER);
	g_mid_IMultiTouchHandler_wyTouchesPointerBegan = env->GetMethodID(clazz, "wyTouchesPointerBegan", "(Landroid/view/MotionEvent;)Z");
	g_mid_IMultiTouchHandler_wyTouchesPointerEnded = env->GetMethodID(clazz, "wyTouchesPointerEnded", "(Landroid/view/MotionEvent;)Z");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_IKEYHANDLER);
	g_mid_IKeyHandler_wyKeyDown = env->GetMethodID(clazz, "wyKeyDown", "(Landroid/view/KeyEvent;)Z");
	g_mid_IKeyHandler_wyKeyUp = env->GetMethodID(clazz, "wyKeyUp", "(Landroid/view/KeyEvent;)Z");
	g_mid_IKeyHandler_wyKeyMultiple = env->GetMethodID(clazz, "wyKeyMultiple", "(Landroid/view/KeyEvent;)Z");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_IACCELEROMETERHANDLER);
	g_mid_IAccelerometerHandler_wyAccelerometerChanged = env->GetMethodID(clazz, "wyAccelerometerChanged", "(FFF)V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ONDOUBLETAPLISTENER);
	g_mid_OnDoubleTapListener_onDoubleTap = env->GetMethodID(clazz, "onDoubleTap", "(Landroid/view/MotionEvent;)Z");
	g_mid_OnDoubleTapListener_onDoubleTapEvent = env->GetMethodID(clazz, "onDoubleTapEvent", "(Landroid/view/MotionEvent;)Z");
	g_mid_OnDoubleTapListener_onSingleTapConfirmed = env->GetMethodID(clazz, "onSingleTapConfirmed", "(Landroid/view/MotionEvent;)Z");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ONGESTURELISTENER);
	g_mid_OnGestureListener_onDown = env->GetMethodID(clazz, "onDown", "(Landroid/view/MotionEvent;)Z");
	g_mid_OnGestureListener_onFling = env->GetMethodID(clazz, "onFling", "(Landroid/view/MotionEvent;Landroid/view/MotionEvent;FF)Z");
	g_mid_OnGestureListener_onLongPress = env->GetMethodID(clazz, "onLongPress", "(Landroid/view/MotionEvent;)V");
	g_mid_OnGestureListener_onScroll = env->GetMethodID(clazz, "onScroll", "(Landroid/view/MotionEvent;Landroid/view/MotionEvent;FF)Z");
	g_mid_OnGestureListener_onShowPress = env->GetMethodID(clazz, "onShowPress", "(Landroid/view/MotionEvent;)V");
	g_mid_OnGestureListener_onSingleTapUp = env->GetMethodID(clazz, "onSingleTapUp", "(Landroid/view/MotionEvent;)Z");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ACCELEROMETER);
	g_mid_Accelerometer_getInstance = env->GetStaticMethodID(clazz, "getInstance", "()Lcom/wiyun/engine/events/Accelerometer;");
	g_mid_Accelerometer_checkAccelHandlers = env->GetMethodID(clazz, "checkAccelHandlers", "()V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_FILEDESCRIPTOR);
	g_fid_FileDescriptor_descriptor = env->GetFieldID(clazz, "descriptor", "I");
	env->DeleteLocalRef(clazz);

	g_mid_Utilities_createLabelBitmap_by_fontPath = env->GetStaticMethodID(gClass_Utilities, "createLabelBitmap", "(Ljava/lang/String;FLjava/lang/String;ZFI)[B");
	g_mid_Utilities_createLabelBitmap_by_fontStyle = env->GetStaticMethodID(gClass_Utilities, "createLabelBitmap", "(Ljava/lang/String;FILjava/lang/String;FI)[B");
	g_mid_Utilities_calculateTextSize_by_fontPath = env->GetStaticMethodID(gClass_Utilities, "calculateTextSize", "(Ljava/lang/String;FLjava/lang/String;ZF)Lcom/wiyun/engine/types/WYSize;");
	g_mid_Utilities_calculateTextSize_by_fontStyle = env->GetStaticMethodID(gClass_Utilities, "calculateTextSize", "(Ljava/lang/String;FILjava/lang/String;F)Lcom/wiyun/engine/types/WYSize;");
	g_mid_Utilities_loadAsset = env->GetStaticMethodID(gClass_Utilities, "loadAsset", "(Ljava/lang/String;Z)[B");
	g_mid_Utilities_scaleImage = env->GetStaticMethodID(gClass_Utilities, "scaleImage", "([BIIFF)[B");

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

	clazz = env->FindClass(CLASS_IDIRECTORLIFECYCLELISTENER);
	g_mid_IDirectorLifecycleListener_onSurfaceCreated = env->GetMethodID(clazz, "onSurfaceCreated", "()V");
	g_mid_IDirectorLifecycleListener_onSurfaceChanged = env->GetMethodID(clazz, "onSurfaceChanged", "(II)V");
	g_mid_IDirectorLifecycleListener_onSurfaceDestroyed = env->GetMethodID(clazz, "onSurfaceDestroyed", "()V");
	g_mid_IDirectorLifecycleListener_onDirectorPaused = env->GetMethodID(clazz, "onDirectorPaused", "()V");
	g_mid_IDirectorLifecycleListener_onDirectorResumed = env->GetMethodID(clazz, "onDirectorResumed", "()V");
	g_mid_IDirectorLifecycleListener_onDirectorEnded = env->GetMethodID(clazz, "onDirectorEnded", "()V");
	g_mid_IDirectorLifecycleListener_onDirectorScreenCaptured = env->GetMethodID(clazz, "onDirectorScreenCaptured", "(Ljava/lang/String;)V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_IPOSITIONLISTENER);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IPositionListener_onPositionChanged = env->GetMethodID(clazz, "onPositionChanged", "(I)V");
	}
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_IVIRTUALJOYSTICKCALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IVirtualJoystickCallback_onVJNavigationStarted = env->GetMethodID(clazz, "onVJNavigationStarted", "(I)V");
		g_mid_IVirtualJoystickCallback_onVJNavigationEnded = env->GetMethodID(clazz, "onVJNavigationEnded", "(I)V");
		g_mid_IVirtualJoystickCallback_onVJDirectionChanged = env->GetMethodID(clazz, "onVJDirectionChanged", "(II)V");
	}
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_WYGLSURFACEVIEW);
	g_mid_WYGLSurfaceView_onPause = env->GetMethodID(clazz, "onPause", "()V");
	g_mid_WYGLSurfaceView_onResume = env->GetMethodID(clazz, "onResume", "()V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_INODEVIRTUALMETHODS);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_INodeVirtualMethods_jOnEnter = env->GetMethodID(clazz, "jOnEnter", "()V");
		g_mid_INodeVirtualMethods_jOnExit = env->GetMethodID(clazz, "jOnExit", "()V");
		g_mid_INodeVirtualMethods_jOnEnterTransitionDidFinish = env->GetMethodID(clazz, "jOnEnterTransitionDidFinish", "()V");
		g_mid_INodeVirtualMethods_jDraw = env->GetMethodID(clazz, "jDraw", "()V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_IMWSPRITECALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IMWSpriteCallback_onMWAnimationFrameChanged = env->GetMethodID(clazz, "onMWAnimationFrameChanged", "(II)V");
		g_mid_IMWSpriteCallback_onMWAnimationEnded = env->GetMethodID(clazz, "onMWAnimationEnded", "(II)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_IAFCSPRITECALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IAFCSpriteCallback_onAFCAnimationFrameChanged = env->GetMethodID(clazz, "onAFCAnimationFrameChanged", "(I)V");
		g_mid_IAFCSpriteCallback_onAFCAnimationEnded = env->GetMethodID(clazz, "onAFCAnimationEnded", "(I)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_ISPXSPRITECALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_ISPXSpriteCallback_onSPXActionFrameChanged = env->GetMethodID(clazz, "onSPXActionFrameChanged", "(II)V");
		g_mid_ISPXSpriteCallback_onSPXActionEnded = env->GetMethodID(clazz, "onSPXActionEnded", "(II)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_IPAGECONTROLCALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IPageControlCallback_onPageClicked = env->GetMethodID(clazz, "onPageClicked", "(II)V");
		g_mid_IPageControlCallback_onPageChanged = env->GetMethodID(clazz, "onPageChanged", "(II)V");
		g_mid_IPageControlCallback_onPagePositionChanged = env->GetMethodID(clazz, "onPagePositionChanged", "(IIF)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_ISLIDERCALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_ISliderCallback_onSliderValueChanged = env->GetMethodID(clazz, "onSliderValueChanged", "(IF)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_ISCROLLABLELAYERCALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IScrollableLayerCallback_onScrollOffsetChanged = env->GetMethodID(clazz, "onScrollOffsetChanged", "(I)V");
		g_mid_IScrollableLayerCallback_onStartFling = env->GetMethodID(clazz, "onStartFling", "(I)V");
		g_mid_IScrollableLayerCallback_onEndFling = env->GetMethodID(clazz, "onEndFling", "(I)V");
		g_mid_IScrollableLayerCallback_onScrollableChildNotVisible = env->GetMethodID(clazz, "onScrollableChildNotVisible", "(II)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_IANIMATIONCALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IAnimationCallback_onAnimationFrameChanged = env->GetMethodID(clazz, "onAnimationFrameChanged", "(II)V");
		g_mid_IAnimationCallback_onAnimationEnded = env->GetMethodID(clazz, "onAnimationEnded", "(I)V");
		env->DeleteLocalRef(clazz);
	}

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
	jfieldID fieldID = env->GetStaticFieldID(clazz, "ACTION_POINTER_ID_MASK", "I");
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

	clazz = env->FindClass(CLASS_ACTION_CALLBACK);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_Action_Callback_onStart = env->GetMethodID(clazz, "onStart", "(I)V");
		g_mid_Action_Callback_onStop = env->GetMethodID(clazz, "onStop", "(I)V");
		g_mid_Action_Callback_onUpdate = env->GetMethodID(clazz, "onUpdate", "(IF)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYPOINT);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYPoint_x = env->GetFieldID(clazz, "x", "F");
		g_fid_WYPoint_y = env->GetFieldID(clazz, "y", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYPOINTLIST);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_WYPointList_addPoint_xy = env->GetMethodID(clazz, "addPoint", "(FF)V");
		g_mid_WYPointList_addPoint_p = env->GetMethodID(clazz, "addPoint", "(Lcom/wiyun/engine/types/WYPoint;)V");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYDIMENSION);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYDimension_x = env->GetFieldID(clazz, "x", "I");
		g_fid_WYDimension_y = env->GetFieldID(clazz, "y", "I");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYSIZE);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYSize_width = env->GetFieldID(clazz, "width", "F");
		g_fid_WYSize_height = env->GetFieldID(clazz, "height", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYRECT);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYRect_origin = env->GetFieldID(clazz, "origin", "Lcom/wiyun/engine/types/WYPoint;");
		g_fid_WYRect_size = env->GetFieldID(clazz, "size", "Lcom/wiyun/engine/types/WYSize;");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYVERTEX3D);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYVertex3D_x = env->GetFieldID(clazz, "x", "F");
		g_fid_WYVertex3D_y = env->GetFieldID(clazz, "y", "F");
		g_fid_WYVertex3D_z = env->GetFieldID(clazz, "z", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYCOLOR3B);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYColor3B_r = env->GetFieldID(clazz, "r", "I");
		g_fid_WYColor3B_g = env->GetFieldID(clazz, "g", "I");
		g_fid_WYColor3B_b = env->GetFieldID(clazz, "b", "I");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYCOLOR3F);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYColor3F_r = env->GetFieldID(clazz, "r", "F");
		g_fid_WYColor3F_g = env->GetFieldID(clazz, "g", "F");
		g_fid_WYColor3F_b = env->GetFieldID(clazz, "b", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYCOLOR4B);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYColor4B_r = env->GetFieldID(clazz, "r", "I");
		g_fid_WYColor4B_g = env->GetFieldID(clazz, "g", "I");
		g_fid_WYColor4B_b = env->GetFieldID(clazz, "b", "I");
		g_fid_WYColor4B_a = env->GetFieldID(clazz, "a", "I");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYCOLOR4F);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYColor4F_r = env->GetFieldID(clazz, "r", "F");
		g_fid_WYColor4F_g = env->GetFieldID(clazz, "g", "F");
		g_fid_WYColor4F_b = env->GetFieldID(clazz, "b", "F");
		g_fid_WYColor4F_a = env->GetFieldID(clazz, "a", "F");
		env->DeleteLocalRef(clazz);
	}
	clazz = env->FindClass(CLASS_WYQUAD2D);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYQuad2D_bl_x = env->GetFieldID(clazz, "bl_x", "F");
		g_fid_WYQuad2D_bl_y = env->GetFieldID(clazz, "bl_y", "F");
		g_fid_WYQuad2D_br_x = env->GetFieldID(clazz, "br_x", "F");
		g_fid_WYQuad2D_br_y = env->GetFieldID(clazz, "br_y", "F");
		g_fid_WYQuad2D_tl_x = env->GetFieldID(clazz, "tl_x", "F");
		g_fid_WYQuad2D_tl_y = env->GetFieldID(clazz, "tl_y", "F");
		g_fid_WYQuad2D_tr_x = env->GetFieldID(clazz, "tr_x", "F");
		g_fid_WYQuad2D_tr_y = env->GetFieldID(clazz, "tr_y", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYQUAD3D);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYQuad3D_bl_x = env->GetFieldID(clazz, "bl_x", "F");
		g_fid_WYQuad3D_bl_y = env->GetFieldID(clazz, "bl_y", "F");
		g_fid_WYQuad3D_bl_z = env->GetFieldID(clazz, "bl_z", "F");
		g_fid_WYQuad3D_br_x = env->GetFieldID(clazz, "br_x", "F");
		g_fid_WYQuad3D_br_y = env->GetFieldID(clazz, "br_y", "F");
		g_fid_WYQuad3D_br_z = env->GetFieldID(clazz, "br_z", "F");
		g_fid_WYQuad3D_tl_x = env->GetFieldID(clazz, "tl_x", "F");
		g_fid_WYQuad3D_tl_y = env->GetFieldID(clazz, "tl_y", "F");
		g_fid_WYQuad3D_tl_z = env->GetFieldID(clazz, "tl_z", "F");
		g_fid_WYQuad3D_tr_x = env->GetFieldID(clazz, "tr_x", "F");
		g_fid_WYQuad3D_tr_y = env->GetFieldID(clazz, "tr_y", "F");
		g_fid_WYQuad3D_tr_z = env->GetFieldID(clazz, "tr_z", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYBEZIERCONFIG);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYBezierConfig_cubic = env->GetFieldID(clazz, "cubic", "Z");
		g_fid_WYBezierConfig_startX = env->GetFieldID(clazz, "startX", "F");
		g_fid_WYBezierConfig_startY = env->GetFieldID(clazz, "startY", "F");
		g_fid_WYBezierConfig_endX = env->GetFieldID(clazz, "endX", "F");
		g_fid_WYBezierConfig_endY = env->GetFieldID(clazz, "endY", "F");
		g_fid_WYBezierConfig_cp1X = env->GetFieldID(clazz, "cp1X", "F");
		g_fid_WYBezierConfig_cp1Y = env->GetFieldID(clazz, "cp1Y", "F");
		g_fid_WYBezierConfig_cp2X = env->GetFieldID(clazz, "cp2X", "F");
		g_fid_WYBezierConfig_cp2Y = env->GetFieldID(clazz, "cp2Y", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYHYPOTROCHOIDCONFIG);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYHypotrochoidConfig_R = env->GetFieldID(clazz, "R", "F");
		g_fid_WYHypotrochoidConfig_r = env->GetFieldID(clazz, "r", "F");
		g_fid_WYHypotrochoidConfig_d = env->GetFieldID(clazz, "d", "F");
		g_fid_WYHypotrochoidConfig_startAngle = env->GetFieldID(clazz, "startAngle", "F");
		g_fid_WYHypotrochoidConfig_endAngle = env->GetFieldID(clazz, "endAngle", "F");
		g_fid_WYHypotrochoidConfig_centreX = env->GetFieldID(clazz, "centreX", "F");
		g_fid_WYHypotrochoidConfig_centreY = env->GetFieldID(clazz, "centreY", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYLAGRANGECONFIG);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYLagrangeConfig_cubic = env->GetFieldID(clazz, "cubic", "Z");
		g_fid_WYLagrangeConfig_startX = env->GetFieldID(clazz, "startX", "F");
		g_fid_WYLagrangeConfig_startY = env->GetFieldID(clazz, "startY", "F");
		g_fid_WYLagrangeConfig_endX = env->GetFieldID(clazz, "endX", "F");
		g_fid_WYLagrangeConfig_endY = env->GetFieldID(clazz, "endY", "F");
		g_fid_WYLagrangeConfig_cp1X = env->GetFieldID(clazz, "cp1X", "F");
		g_fid_WYLagrangeConfig_cp1Y = env->GetFieldID(clazz, "cp1Y", "F");
		g_fid_WYLagrangeConfig_cp2X = env->GetFieldID(clazz, "cp2X", "F");
		g_fid_WYLagrangeConfig_cp2Y = env->GetFieldID(clazz, "cp2Y", "F");
		g_fid_WYLagrangeConfig_t0 = env->GetFieldID(clazz, "t0", "F");
		g_fid_WYLagrangeConfig_t1 = env->GetFieldID(clazz, "t1", "F");
		g_fid_WYLagrangeConfig_t2 = env->GetFieldID(clazz, "t2", "F");
		g_fid_WYLagrangeConfig_t3 = env->GetFieldID(clazz, "t3", "F");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_WYAFFINETRANSFORM);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_WYAffineTransform_a = env->GetFieldID(clazz, "a", "D");
		g_fid_WYAffineTransform_b = env->GetFieldID(clazz, "b", "D");
		g_fid_WYAffineTransform_c = env->GetFieldID(clazz, "c", "D");
		g_fid_WYAffineTransform_d = env->GetFieldID(clazz, "d", "D");
		g_fid_WYAffineTransform_tx = env->GetFieldID(clazz, "tx", "D");
		g_fid_WYAffineTransform_ty = env->GetFieldID(clazz, "ty", "D");
		env->DeleteLocalRef(clazz);
	}

	clazz = env->FindClass(CLASS_TARGETSELECTOR);
	g_mid_TargetSelector_setDelta = env->GetMethodID(clazz, "setDelta", "(F)V");
	g_mid_TargetSelector_invoke = env->GetMethodID(clazz, "invoke", "()V");
	env->DeleteLocalRef(clazz);

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

	clazz = env->FindClass(CLASS_BITMAPRAWDATA);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_fid_BitmapRawData_width = env->GetFieldID(clazz, "width", "I");
		g_fid_BitmapRawData_height = env->GetFieldID(clazz, "height", "I");
		g_fid_BitmapRawData_data = env->GetFieldID(clazz, "data", "[B");
	}
	env->DeleteLocalRef(clazz);

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

	clazz = env->FindClass(CLASS_ITEXTBOXCALLBACK);
	g_mid_ITextBoxCallback_onBeginEditing = env->GetMethodID(clazz, "onBeginEditing", "(I)V");
	g_mid_ITextBoxCallback_onEndEditing = env->GetMethodID(clazz, "onEndEditing", "(I)V");
	g_mid_ITextBoxCallback_onTextChanged = env->GetMethodID(clazz, "onTextChanged", "(I)V");
	env->DeleteLocalRef(clazz);

	clazz = env->FindClass(CLASS_ICOLORFILTERDELEGATE);
	if(env->ExceptionOccurred() != NULL) {
		env->ExceptionClear();
	} else {
		g_mid_IColorFilterDelegate_apply = env->GetMethodID(clazz, "apply", "([BII)V");
	}
	env->DeleteLocalRef(clazz);

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

	clazz = env->FindClass(CLASS_RESOURCEDECODER);
	g_mid_ResourceDecoder_decode = env->GetMethodID(clazz, "decode", "([B)[B");
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
}

#ifdef __cplusplus
}
#endif

#endif // #if ANDROID
