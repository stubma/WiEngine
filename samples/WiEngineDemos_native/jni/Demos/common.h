/*
 * Copyright (c) 2010 WiYun Inc.
 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __common_h__
#define __common_h__

#include "WiEngine-Classes.h"

#if ANDROID
	#define DEMO_ENTRY(PKG, CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_##PKG##_##CLASSNAME##_nativeStart(JNIEnv *, jobject);
#else
	#define DEMO_ENTRY_NAME(PKG, CLASSNAME) _##PKG##_##CLASSNAME##Launcher
	#define DEMO_ENTRY(PKG, CLASSNAME) void DEMO_ENTRY_NAME(PKG, CLASSNAME)();
	typedef void (*demoEntryFunc)();
#endif

#if ANDROID
	#define DEMO_ENTRY_IMPL(PKG, CLASSNAME) \
		static bool _##PKG##_##CLASSNAME##_started; \
		\
		static void _##PKG##_##CLASSNAME##_onSurfaceChanged(int w, int h, void* data) { \
			if(!_##PKG##_##CLASSNAME##_started) { \
				_##PKG##_##CLASSNAME##_started = true; \
				\
				wyLayer* layer = new wy##CLASSNAME##Layer(); \
				wyScene* scene = new wyScene(); \
				scene->addChildLocked(layer); \
				\
				wyDirector* director = wyDirector::getInstance(); \
				director->runWithScene(scene); \
				\
				wyObjectRelease(scene); \
				wyObjectRelease(layer); \
			} \
		} \
		\
		static const wyDirectorLifecycleListener _##PKG##_##CLASSNAME##_surfaceLifeCycleListener = { \
			NULL, \
			_##PKG##_##CLASSNAME##_onSurfaceChanged, \
			NULL, \
			NULL, \
			NULL, \
			NULL, \
			NULL \
		}; \
		\
		JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_##PKG##_##CLASSNAME##_nativeStart(JNIEnv *env, jobject thiz) { \
			_##PKG##_##CLASSNAME##_started = false; \
			\
			wyDirector* director = wyDirector::getInstance(); \
			director->setShowFPS(true); \
			director->addLifecycleListener(&_##PKG##_##CLASSNAME##_surfaceLifeCycleListener, NULL); \
		}
#else
	#define DEMO_ENTRY_IMPL(PKG, CLASSNAME) \
		static bool _##PKG##_##CLASSNAME##_started; \
		\
		static void _##PKG##_##CLASSNAME##_onSurfaceChanged(int w, int h, void* data) { \
			if(!_##PKG##_##CLASSNAME##_started) { \
				_##PKG##_##CLASSNAME##_started = true; \
				\
				wyLayer* layer = new wy##CLASSNAME##Layer(); \
				wyScene* scene = new wyScene(); \
				scene->addChildLocked(layer); \
				\
				wyDirector* director = wyDirector::getInstance(); \
				director->runWithScene(scene); \
				\
				wyObjectRelease(scene); \
				wyObjectRelease(layer); \
			} \
		} \
		\
		static const wyDirectorLifecycleListener _##PKG##_##CLASSNAME##_surfaceLifeCycleListener = { \
			NULL, \
			_##PKG##_##CLASSNAME##_onSurfaceChanged, \
			NULL, \
			NULL, \
			NULL, \
			NULL, \
			NULL \
		}; \
		\
		void _##PKG##_##CLASSNAME##Launcher() { \
			_##PKG##_##CLASSNAME##_started = false; \
			\
			wyDirector* director = wyDirector::getInstance(); \
			director->setShowFPS(true); \
			director->addLifecycleListener(&_##PKG##_##CLASSNAME##_surfaceLifeCycleListener, NULL); \
		}
#endif

#endif // __common_h__
