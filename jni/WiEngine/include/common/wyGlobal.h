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
#ifndef __wyGlobal_h__
#define __wyGlobal_h__

#include "wyBuildConfig.h"
#include "WiEngine-Classes.h"

// WiEngine version
#define WIENGINE_VERSION "3.10.1"

// export definition
#if WINDOWS
	#if LIBWIENGINE_EXPORTS
		#define WIENGINE_API __declspec(dllexport)
	#else
		#define WIENGINE_API __declspec(dllimport)
	#endif
#else
	#define WIENGINE_API
#endif

// opengl headers
#if ANDROID
	#include <GLES2/gl2.h>
	#include <GLES2/gl2ext.h>
#elif IOS
	#import <OpenGLES/ES1/gl.h>
	#import <OpenGLES/ES1/glext.h>
	#import <OpenGLES/ES2/gl.h>
	#import <OpenGLES/ES2/glext.h>
#elif MACOSX
	#import <OpenGL/gl.h>
	#import <OpenGL/glext.h>
#elif WINDOWS
	#include <GLES2/gl2.h>
	#include <GLES2/gl2ext.h>
#endif

// common header
#include <unistd.h>

// we use kazmath as math library
#include "kazmath/kazmath.h"

// jni
#if ANDROID
	#include <jni.h>
#endif

// mapping between OpenGLES and OpenGL
#if MACOSX
	#define GL_FRAMEBUFFER_BINDING_OES GL_FRAMEBUFFER_BINDING
	#define GL_FRAMEBUFFER_OES GL_FRAMEBUFFER
	#define GL_COLOR_ATTACHMENT0_OES GL_COLOR_ATTACHMENT0
	#define GL_FRAMEBUFFER_UNSUPPORTED_OES GL_FRAMEBUFFER_UNSUPPORTED
	#define glGenFramebuffersOES glGenFramebuffers
	#define glBindFramebufferOES glBindFramebuffer
	#define glFramebufferTexture2DOES glFramebufferTexture2D
	#define GL_POINT_SPRITE_OES GL_POINT_SPRITE
	#define GL_COORD_REPLACE_OES GL_COORD_REPLACE
	#define GL_POINT_SIZE_ARRAY_OES GL_POINT_SIZE_ARRAY_APPLE
	#define glPointSizePointerOES glPointSizePointerAPPLE
	#define glCheckFramebufferStatusOES glCheckFramebufferStatus
	#define glDeleteFramebuffersOES glDeleteFramebuffers
	#define glTexParameterx glTexParameteri
	#define glOrthof glOrtho
	#define glDepthRangef glDepthRange
	#define glClearDepthf glClearDepth
	#define glFrustumf glFrustum
#endif

// blend func
#define DEFAULT_BLEND_SRC GL_SRC_ALPHA
#define DEFAULT_BLEND_DST GL_ONE_MINUS_SRC_ALPHA

// map endian methods
#if ANDROID
	#include <endian.h>
#elif IOS || MACOSX
	#import <CoreFoundation/CoreFoundation.h>
	#define letoh64 CFSwapInt64LittleToHost
	#define letoh32 CFSwapInt32LittleToHost
	#define letoh16 CFSwapInt16LittleToHost
	#define htole64 CFSwapInt64HostToLittle
	#define htole32 CFSwapInt32HostToLittle
	#define htole16 CFSwapInt16HostToLittle
	#define betoh64	CFSwapInt64BigToHost
	#define betoh32	CFSwapInt32BigToHost
	#define betoh16 CFSwapInt16BigToHost
	#define htobe64 CFSwapInt64HostToBig
	#define htobe32 CFSwapInt32HostToBig
	#define htobe16 CFSwapInt16HostToBig
#elif WINDOWS
	#include <io.h>
	#define ___my_swap16(x) \
		((uint16_t)( \
		(((uint16_t)(x) & (uint16_t)0x00ffU) << 8) | \
		(((uint16_t)(x) & (uint16_t)0xff00U) >> 8) ))
	#define ___my_swap32(x) \
		((uint32_t)( \
		(((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) | \
		(((uint32_t)(x) & (uint32_t)0x0000ff00UL) <<  8) | \
		(((uint32_t)(x) & (uint32_t)0x00ff0000UL) >>  8) | \
		(((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24) ))
    #define ___my_swap64(x) \
		((uint64_t)( \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00000000000000ffULL) << 56) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x000000000000ff00ULL) << 40) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x0000000000ff0000ULL) << 24) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00000000ff000000ULL) <<  8) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x000000ff00000000ULL) >>  8) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x0000ff0000000000ULL) >> 24) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00ff000000000000ULL) >> 40) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0xff00000000000000ULL) >> 56) ))
	#define letoh64(x) (x)
	#define letoh32(x) (x)
	#define letoh16(x) (x)
	#define htole64(x) (x)
	#define htole32(x) (x)
	#define htole16(x) (x)
	#define betoh64(x) ___my_swap64(x)
	#define betoh32(x) ___my_swap32(x)
	#define betoh16(x) ___my_swap16(x)
	#define htobe64(x) ___my_swap64(x)
	#define htobe32(x) ___my_swap32(x)
	#define htobe16(x) ___my_swap16(x)
#endif

// default font
#if ANDROID
	#define WY_DEFAULT_FONT "DroidSans"
#elif IOS || MACOSX
	#define WY_DEFAULT_FONT "Verdana"
#elif WINDOWS
	#define WY_DEFAULT_FONT "Verdana"
#endif

// path separator
#if WINDOWS
	#define WY_PATH_SEPARATOR '\\'
#else
	#define WY_PATH_SEPARATOR '/'
#endif

// built-in strings
#define WY_OK_EN "OK"
#define WY_OK_ZH "确定"
#define WY_CANCEL_EN "Cancel"
#define WY_CANCEL_ZH "取消"

// GL context and GL view definition
#if ANDROID
	#define wyGLSurfaceView jobject
	#define wyGLContext jobject
#elif IOS
	@class WYEAGLView;
	#define wyGLSurfaceView WYEAGLView*
	#define wyGLContext WYEAGLView*
#elif MACOSX
	@class WYOpenGLView;
	#define wyGLSurfaceView WYOpenGLView*
	#define wyGLContext WYOpenGLView*
#elif WINDOWS
	class wyWinGLView;
	#define wyGLSurfaceView wyWinGLView*
	#define wyGLContext wyWinGLView*
#endif

// platform event universal type
#if ANDROID
	#define wyPlatformMotionEvent jobject
	#define wyPlatformKeyEvent jobject
#elif IOS
	@class WYUIEvent;
	@class WYUITouch;
	#define wyPlatformMotionEvent WYUIEvent*
	#define wyPlatformKeyEvent wyKeyEvent*
#elif MACOSX
	#import <AppKit/AppKit.h>
	#define wyPlatformKeyEvent NSEvent*
	#define wyPlatformMotionEvent NSEvent*
#elif WINDOWS
	#define wyPlatformKeyEvent wyKeyEvent*
	#define wyPlatformMotionEvent wyMotionEvent*
#endif

// use stl
#include <stack>
#include <vector>
#include <map>
using namespace std;

// char* compare function
#include <string.h>
class wyStrPredicate : public binary_function<const char*, const char*, bool> {
public:
	bool operator()(const char* str1, const char* str2) const {
		// true means str1 is less than str2
		// false means str1 is not less than str2
		return strcmp(str1, str2) < 0;
	}
};
#define WY_STRING_MAP map<const char*, const char*, wyStrPredicate>
#define WY_STRING_ITER WY_STRING_MAP::iterator
#define WY_UNIFORM_MAP map<const char*, wyUniform*, wyStrPredicate>
#define WY_UNIFORM_ITER WY_UNIFORM_MAP::iterator
#define WY_ATTRIBUTE_MAP map<const char*, wyAttribute*, wyStrPredicate>
#define WY_ATTRIBUTE_ITER WY_ATTRIBUTE_MAP::iterator

// thread method
extern WIENGINE_API bool isGLThread();
extern WIENGINE_API void tagGLThread();
extern WIENGINE_API ssize_t currentThreadId();

// time method
#if WINDOWS
	#include <time.h>
	extern int gettimeofday(struct timeval *tp, void *tzp);
	extern void usleep(int waitTime);
#else
	#include <time.h>
	#include <sys/time.h>
#endif

// file operation
#if WINDOWS
	#include <direct.h>
	#define mkdir _mkdir
#else
	#include <sys/stat.h>
	#define mkdir(x) mkdir(x, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
#endif

// math operation
#if WINDOWS
	// for M_PI definition
	#define _USE_MATH_DEFINES
	#include <cmath>

	// windows doesn't have round method
	extern double round(double r);
#endif

// byte order
#if WINDOWS
	#define _LITTLE_ENDIAN 1234
	#define _BIG_ENDIAN 4321

	#define LITTLE_ENDIAN _LITTLE_ENDIAN
	#define BIG_ENDIAN _BIG_ENDIAN
	#define _BYTE_ORDER LITTLE_ENDIAN
	#define BYTE_ORDER _BYTE_ORDER
#endif

#endif // __wyGlobal_h__
