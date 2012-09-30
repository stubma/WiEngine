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

#if MACOSX

#include "wyDirector_macosx.h"
#import "WYResMap.h"

/// singleton director
wyDirector_macosx* gDirector;
	
/// Default screen config
wyScreenConfig gScreenConfig = {
	1.0f, 1.0f, 480, 800
};

wyDirector* wyDirector::getInstance() {
	if(gDirector == NULL) {
		/*
		 * because we print memory tracking in director deconstructor,
		 * so director will always be the leaked one. then we don't use
		 * WYNEW to track director
		 */
		gDirector = new wyDirector_macosx();
	}
	return gDirector;
}

void wyDirector::setScreenConfig(wyScreenConfig c) {
	gScreenConfig = c;
}

wyScreenConfig& wyDirector::getScreenConfig() {
	return gScreenConfig;
}

wyDirector_macosx::wyDirector_macosx() {
	// get api level
	SInt32 versionMajor = 0;
	SInt32 versionMinor = 0;
	SInt32 versionBugFix = 0;
	Gestalt(gestaltSystemVersionMajor, &versionMajor);
	Gestalt(gestaltSystemVersionMinor, &versionMinor);
	Gestalt(gestaltSystemVersionBugFix, &versionBugFix);
	wyDevice::apiLevel = versionMajor * 100 + versionMinor * 10 + versionBugFix;
	
	// for Mac OS X, just use mdpi density by default
	wyDevice::density = gScreenConfig.density;
	wyDevice::scaledDensity = gScreenConfig.scaledDensity;
	
	// init file mapping
	[WYResMap sharedMap];
	
	/*
	 * Mac OS X上的GL线程和UI线程是同一个线程. 同时, Mac OS X上调用onSurfaceCreated的时机
	 * 较晚, 导致: 一个scene构造时就强行载入贴图, gGLThreadId尚未设置为0, WiEngine
	 * 误以为在非GL线程从而发送一个事件, 然后等待, 这个等待就是等待自己了, 导致没动静了.
	 */
	tagGLThread();
}

wyDirector_macosx::~wyDirector_macosx() {
	// common for all platforms
	commonDestroy();
	
	// destroy resource mapping and event pool
	[WYResMap destroy];
	
	gDirector = NULL;
}

void wyDirector_macosx::stopRender() {
	if(m_glView != NULL) {
		[m_glView stopRender];
	}
}

void wyDirector_macosx::startRender() {
	if(m_glView != NULL) {
		[m_glView startRender];
	}
}

void wyDirector_macosx::end() {
	[m_glView performSelectorOnMainThread:@selector(end) withObject:nil waitUntilDone:NO];
}

void wyDirector_macosx::attachContext(wyGLContext context) {
	if (m_context != context) {
        m_context = context;
		
    	// set size
    	wyDevice::realWidth = gScreenConfig.winWidth;
    	wyDevice::realHeight = gScreenConfig.winHeight;
    	if(SCALE_MODE_BY_DENSITY == wyDevice::scaleMode) {
    		wyDevice::winWidth = wyDevice::realWidth;
    		wyDevice::winHeight = wyDevice::realHeight;
    	}
    }
}

void wyDirector_macosx::attachInView(wyGLSurfaceView glView) {
	if(m_glView != glView) {
		m_glView = glView;
	}
}

void wyDirector_macosx::setAccelerometerDelay(wySensorDelay delay) {
	// do nothing in Mac OS X
}

#endif // #if MACOSX
