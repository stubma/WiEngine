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

#include "wyDirector.h"
#include "wyLayer.h"
#include "wyAction.h"

#if ANDROID
	#define DEMO_ENTRY(pkg, CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_##pkg##_##CLASSNAME##_nativeStart(JNIEnv *, jobject);
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_NAME(pkg, CLASSNAME) _##pkg##_##CLASSNAME##Launcher
	#define DEMO_ENTRY(pkg, CLASSNAME) void DEMO_ENTRY_NAME(pkg, CLASSNAME)();
	typedef void (*demoEntryFunc)();
#endif

/*
 * Method:    Common Scene Start 
 * Parameter:
 *      scene: the scene will be run
 *      action: the action added to scene before run
 */
void runDemo(wyLayer*, wyAction* action);

#endif // __common_h__
