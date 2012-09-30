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
#if IOS

#include "wyDirector_ios.h"
#include <pthread.h>
#import "WYEAGLView.h"
#import "WYResMap.h"
#import "WYUBEDelegate.h"

/// singleton director
wyDirector_ios* gDirector;

// analyst method
extern void analyst();

wyDirector_ios::wyDirector_ios() {
	// in ios, you need call startRender so it is not running at first
	m_paused = true;

	// get api level
	// in Android, api level is determined at wyInit.cpp, but wyInit.cpp won't be called in iOS
	NSString* systemVersion = [UIDevice currentDevice].systemVersion;
	NSArray* parts = [systemVersion componentsSeparatedByString:@"."];
	wyDevice::apiLevel = [[parts objectAtIndex:0] intValue] * 100 + [[parts objectAtIndex:1] intValue] * 10;
	if([parts count] == 3)
		wyDevice::apiLevel += [[parts objectAtIndex:2] intValue];

	// decide density here, no need wait attachContext
	if(wyDevice::apiLevel >= 400) {
		wyDevice::density = [UIScreen mainScreen].scale;
		wyDevice::scaledDensity = wyDevice::density;
	} else {
		wyDevice::density = 1.0f;
		wyDevice::scaledDensity = 1.0f;
	}

	// init file mapping
	[WYResMap sharedMap];

	/*
	 * iOS上的GL线程和UI线程是同一个线程. 同时, iOS上调用onSurfaceCreated的时机
	 * 较晚, 导致: 一个scene构造时就强行载入贴图, gGLThreadId尚未设置为0, WiEngine
	 * 误以为在非GL线程从而发送一个事件, 然后等待, 这个等待就是等待自己了, 导致没动静了.
	 */
	tagGLThread();
}

wyDirector_ios::~wyDirector_ios() {
	// common for all platforms
	commonDestroy();

	// destroy resource mapping and event pool
	[WYResMap destroy];
	[WYUIEvent releasePools];

	// free my self
	gDirector = NULL;
}

wyDirector* wyDirector::getInstance() {
	if(gDirector == NULL) {
		/*
		 * because we print memory tracking in director deconstructor,
		 * so director will always be the leaked one. then we don't use
		 * WYNEW to track director
		 */
		gDirector = new wyDirector_ios();
	}
	return gDirector;
}

void wyDirector_ios::attachContext(wyGLContext context) {
    if (m_context != context) {
        m_context = context;

    	// set size
    	wyDevice::realWidth = m_context.frame.size.width * wyDevice::density;
    	wyDevice::realHeight = m_context.frame.size.height * wyDevice::density;
    	if(SCALE_MODE_BY_DENSITY == wyDevice::scaleMode) {
    		wyDevice::winWidth = wyDevice::realWidth;
    		wyDevice::winHeight = wyDevice::realHeight;
    	}

		// send ube
		analyst();
    }
}

void wyDirector_ios::attachInView(wyGLSurfaceView glView) {
	if(m_glView != glView) {
		m_glView = glView;
	}
}

void wyDirector_ios::stopRender() {
	if(m_glView != NULL) {
		[m_glView stopRender];
	}
}

void wyDirector_ios::startRender() {
	if(m_glView != NULL) {
		[m_glView startRender];
	}
}

void wyDirector_ios::setAccelerometerDelay(wySensorDelay delay) {
	switch(delay) {
		case DELAY_FASTEST:
			m_glView.accelerometerDelay = 0.037f;
			break;
		case DELAY_GAME:
			m_glView.accelerometerDelay = 0.062f;
			break;
		case DELAY_UI:
			m_glView.accelerometerDelay = 0.104f;
			break;
		case DELAY_NORMAL:
			m_glView.accelerometerDelay = 0.254;
			break;
	}
}

void wyDirector_ios::end() {
	[m_glView performSelectorOnMainThread:@selector(end) withObject:nil waitUntilDone:NO];
}

#endif // #if IOS
