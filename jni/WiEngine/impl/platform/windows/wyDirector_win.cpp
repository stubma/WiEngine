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
#if WINDOWS

#include "wyDirector_win.h"
#include "wyUtils_win.h"
#include "wyResMap.h"
#include "wyAndroidStrings.h"
#include "wyLog.h"

/// singleton director
wyDirector* gDirector;
	
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
		gDirector = new wyDirector_win();
	}
	return gDirector;
}

void wyDirector::setScreenConfig(wyScreenConfig c) {
	gScreenConfig = c;
}

wyScreenConfig& wyDirector::getScreenConfig() {
	return gScreenConfig;
}

wyDirector_win::wyDirector_win() {
	// get api level
	wyDevice::apiLevel = 1; // todo
	
	// for windows, just use mdpi density by default
	wyDevice::density = gScreenConfig.density;
	wyDevice::scaledDensity = gScreenConfig.scaledDensity;

	// ensure resource mapping is setup
	wyResMap::getInstance();
}

wyDirector_win::~wyDirector_win() {
	// release android strings
	wyAndroidStrings::destroyInstance();

	// common for all platforms
	commonDestroy();

	// release windows gl view because it is hold by windows director
	m_glView->release();
	m_context->release();

	// release res map instance, must be placed after commonDestroy
	delete wyResMap::getInstance();

	// nullify singleton
	gDirector = NULL;
}

void wyDirector_win::stopRender() {
	if(m_glView != NULL) {
		m_glView->setStopRender(true);
	}
}

void wyDirector_win::startRender() {
	if(m_glView != NULL) {
		m_glView->setStopRender(false);
	}
}

void wyDirector_win::end() {
	// just post a close message
	PostMessage(m_glView->getWindowHandle(), WM_CLOSE, 0, 0);
}

void wyDirector_win::attachContext(wyGLContext context) {
	if (m_context != context) {
		// retain context
		wyObjectRetain(context);
		wyObjectRelease(m_context);
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

void wyDirector_win::attachInView(wyGLSurfaceView glView) {
	if(m_glView != glView) {
		wyObjectRetain(glView);
		wyObjectRelease(m_glView);
		m_glView = glView;
	}
}

void wyDirector_win::setAccelerometerDelay(wySensorDelay delay) {
	// do nothing in windows
}

#endif // #if WINDOWS
