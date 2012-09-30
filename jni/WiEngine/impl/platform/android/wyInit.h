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

#ifndef __wyInit_h__
#define __wyInit_h__

#if ANDROID

#include "wyTypes.h"

#define CLASS_AUDIOMANAGER "com/wiyun/engine/sound/AudioManager"
#define CLASS_BASEOBJECT "com/wiyun/engine/BaseObject"
#define CLASS_BASEWYOBJECT "com/wiyun/engine/BaseWYObject"
#define CLASS_DIRECTOR "com/wiyun/engine/nodes/Director"
#define CLASS_IDIRECTORLIFECYCLELISTENER "com/wiyun/engine/nodes/Director$IDirectorLifecycleListener"
#define CLASS_TEXTBOX "com/wiyun/engine/nodes/TextBox"
#define CLASS_ITEXTBOXCALLBACK "com/wiyun/engine/nodes/TextBox$ITextBoxCallback"
#define CLASS_ITOUCHHANDLER "com/wiyun/engine/events/ITouchHandler"
#define CLASS_IMULTITOUCHHANDLER "com/wiyun/engine/events/IMultiTouchHandler"
#define CLASS_IKEYHANDLER "com/wiyun/engine/events/IKeyHandler"
#define CLASS_IACCELEROMETERHANDLER "com/wiyun/engine/events/IAccelerometerHandler"
#define CLASS_ACCELEROMETER "com/wiyun/engine/events/Accelerometer"
#define CLASS_WYGLSURFACEVIEW "com/wiyun/engine/opengl/WYGLSurfaceView"
#define CLASS_INODEVIRTUALMETHODS "com/wiyun/engine/nodes/INodeVirtualMethods"
#define CLASS_IAFCSPRITECALLBACK "com/wiyun/engine/afcanim/AFCSprite$IAFCSpriteCallback"
#define CLASS_IMWSPRITECALLBACK "com/wiyun/engine/motionwelder/MWSprite$IMWSpriteCallback"
#define CLASS_ISPXSPRITECALLBACK "com/wiyun/engine/spritex/SPXSprite$ISPXSpriteCallback"
#define CLASS_IPAGECONTROLCALLBACK "com/wiyun/engine/nodes/PageControl$IPageControlCallback"
#define CLASS_ISLIDERCALLBACK "com/wiyun/engine/nodes/Slider$ISliderCallback"
#define CLASS_ISCROLLABLELAYERCALLBACK "com/wiyun/engine/nodes/ScrollableLayer$IScrollableLayerCallback"
#define CLASS_IANIMATIONCALLBACK "com/wiyun/engine/nodes/Animation$IAnimationCallback"
#define CLASS_IPOSITIONLISTENER "com/wiyun/engine/nodes/Node$IPositionListener"
#define CLASS_IVIRTUALJOYSTICKCALLBACK "com/wiyun/engine/nodes/VirtualJoystick$IVirtualJoystickCallback"
#define CLASS_ICOLORFILTERDELEGATE "com/wiyun/engine/filters/CustomColorFilter$IColorFilterDelegate"
#define CLASS_WYSIZE "com/wiyun/engine/types/WYSize"
#define CLASS_WYDIMENSION "com/wiyun/engine/types/WYDimension"
#define CLASS_PREFUTIL "com/wiyun/engine/utils/PrefUtil"
#define CLASS_BITMAPRAWDATA "com/wiyun/engine/utils/BitmapRawData"
#define CLASS_ONDOUBLETAPLISTENER "android/view/GestureDetector$OnDoubleTapListener"
#define CLASS_ONGESTURELISTENER "android/view/GestureDetector$OnGestureListener"
#define CLASS_FILEDESCRIPTOR "java/io/FileDescriptor"
#define CLASS_CONTEXT "android/content/Context"
#define CLASS_RESOURCES "android/content/res/Resources"
#define CLASS_KEYEVENT "android/view/KeyEvent"
#define CLASS_MOTIONEVENT "android/view/MotionEvent"
#define CLASS_VIEW "android/view/View"
#define CLASS_VIEWGROUP "android/view/ViewGroup"
#define CLASS_TEXTVIEW "android/widget/TextView"
#define CLASS_EDITTEXT "android/widget/EditText"
#define CLASS_DISPLAYMETRICS "android/util/DisplayMetrics"
#define CLASS_VERSION "android/os/Build$VERSION"
#define CLASS_INTENT "android/content/Intent"
#define CLASS_GRAVITY "android/view/Gravity"
#define CLASS_RUNNABLE "java/lang/Runnable"

#define CLASS_ACTION_CALLBACK "com/wiyun/engine/actions/Action$Callback"
#define CLASS_WYPOINT "com/wiyun/engine/types/WYPoint"
#define CLASS_WYPOINTLIST "com/wiyun/engine/types/WYPointList"
#define CLASS_WYRECT "com/wiyun/engine/types/WYRect"
#define CLASS_WYVERTEX3D "com/wiyun/engine/types/WYVertex3D"
#define CLASS_WYCOLOR3B "com/wiyun/engine/types/WYColor3B"
#define CLASS_WYCOLOR3F "com/wiyun/engine/types/WYColor3F"
#define CLASS_WYCOLOR4B "com/wiyun/engine/types/WYColor4B"
#define CLASS_WYCOLOR4F "com/wiyun/engine/types/WYColor4F"
#define CLASS_WYQUAD2D "com/wiyun/engine/types/WYQuad2D"
#define CLASS_WYQUAD3D "com/wiyun/engine/types/WYQuad3D"
#define CLASS_WYBEZIERCONFIG "com/wiyun/engine/types/WYBezierConfig"
#define CLASS_WYLAGRANGECONFIG "com/wiyun/engine/types/WYLagrangeConfig"
#define CLASS_WYHYPOTROCHOIDCONFIG "com/wiyun/engine/types/WYHypotrochoidConfig"
#define CLASS_WYAFFINETRANSFORM "com/wiyun/engine/types/WYAffineTransform"
#define CLASS_IMAGEPICKER "com/wiyun/engine/utils/ImagePicker"
#define CLASS_RESOURCEDECODER "com/wiyun/engine/utils/ResourceDecoder"
#define CLASS_TARGETSELECTOR "com/wiyun/engine/utils/TargetSelector"
#define CLASS_MAP "java/util/Map"

// sal definition
typedef char* (*scaleImageFunc)(int config, char* originData, int originWidth, int originHeight, float scaleX, float scaleY);
typedef char* (*scalePVRFunc)(int format, char* originData, int originWidth, int originHeight, float scale);
typedef void (*calculateTextSizeWithFontFunc)(const char* text, float fontSize, bool bold, bool italic, const char* fontName, float width, size_t* w, size_t* h);
typedef void (*calculateTextSizeWithCustomFontFunc)(const char* text, float fontSize, const char* fontData, int dataLength, float width, size_t* w, size_t* h);
typedef const char* (*createLabelBitmapWithFontFunc)(const char* text, float fontSize, bool bold, bool italic, const char* fontName, float width, int alignment);
typedef const char* (*createLabelBitmapWithCustomFontFunc)(const char* text, float fontSize, const char* fontData, int dataLength, float width, int alignment);
typedef void (*deinitFunc)();
typedef void (*setEnvFunc)(void* env);
typedef void (*setContextFunc)(void* context);
typedef void (*setDensityFunc)(float density);
typedef void (*setScaleModeFunc)(int mode);
typedef void* (*getAssetFunc)(const char* path);
typedef void* (*getAssetByResIdFunc)(int id, float* scale);
typedef void* (*getAssetBufferFunc)(void* asset);
typedef int (*getAssetLengthFunc)(void* asset);
typedef int (*getAssetRemainingLengthFunc)(void* asset);
typedef int (*readAssetFunc)(void* asset, char* buffer, size_t length);
typedef int (*seekAssetFunc)(void* asset, int offset, int mode);
typedef void (*closeAssetFunc)(void* asset);
typedef void (*getResFDFunc)(int resId, size_t* outFD, size_t* outOffset, size_t* outLength, float* outScale);
typedef void (*getAssetFDFunc)(const char* path, size_t* outFD, size_t* outOffset, size_t* outLength);
typedef const char* (*utf16toutf8Func)(const char16_t* s16);
typedef const char16_t* (*toUTF16Func)(const char* s8);
typedef const char* (*wctoutf8Func)(const wchar_t* ws);
typedef struct wyAAL {
	scaleImageFunc scaleImage;
	scalePVRFunc scalePVR;
	calculateTextSizeWithFontFunc calculateTextSizeWithFont;
	calculateTextSizeWithCustomFontFunc calculateTextSizeWithCustomFont;
	createLabelBitmapWithFontFunc createLabelBitmapWithFont;
	createLabelBitmapWithCustomFontFunc createLabelBitmapWithCustomFont;

	deinitFunc deinit;
	setEnvFunc setEnv;
	setContextFunc setContext;
	setDensityFunc setDensity;
	setScaleModeFunc setScaleMode;
	getAssetFunc getAsset;
	getAssetByResIdFunc getAssetByResId;
	getAssetBufferFunc getAssetBuffer;
	getAssetLengthFunc getAssetLength;
	getAssetRemainingLengthFunc getAssetRemainingLength;
	readAssetFunc readAsset;
	seekAssetFunc seekAsset;
	closeAssetFunc closeAsset;
	getResFDFunc getResFD;
	getAssetFDFunc getAssetFD;
	utf16toutf8Func utf16toutf8;
	toUTF16Func toUTF16;
	wctoutf8Func wctoutf8;
} wyAAL;

#endif // #if ANDROID

#endif // __wyInit_h__
