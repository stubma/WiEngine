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
#include "wyVirtualJoystick.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_IVirtualJoystickCallback_onVJNavigationStarted;
extern jmethodID g_mid_IVirtualJoystickCallback_onVJNavigationEnded;
extern jmethodID g_mid_IVirtualJoystickCallback_onVJDirectionChanged;
#endif

wyVirtualJoystick::wyVirtualJoystick(wyNode* bg, wyNode* rocker) :
		m_eventStyle(VJS_FIVE_DIRECTIONS),
		m_autoReset(true),
		m_navigating(false),
		m_pid(0),
		m_rockerRangeRadius(0),
		m_degree(VJD_CENTER),
		m_direction(VJD_CENTER),
		m_rockerX(0),
		m_rockerY(0),
		m_data(NULL),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_bg(bg),
		m_rocker(rocker) {
	// init callback
	memset(&m_callback, 0, sizeof(wyVirtualJoystickCallback));

	// add bg and rocker
	if(m_bg)
		addChildLocked(m_bg);
	if(m_rocker)
		addChildLocked(m_rocker);
	wySize s = getFitSize();
	setContentSize(s.width, s.height);

	// set rocker range radius
	m_rockerRangeRadius = MIN(s.width, s.height) / 2;

	// adjust position
	if(m_bg) {
		m_bg->setAnchor(0.5f, 0.5f);
		m_bg->setRelativeAnchorPoint(true);
		m_bg->setPosition(m_width / 2, m_height / 2);
	}
	if(m_rocker) {
		m_rocker->setAnchor(0.5f, 0.5f);
		m_rocker->setRelativeAnchorPoint(true);
		m_rocker->setPosition(m_width / 2, m_height / 2);
	}

	// enable touch
	setTouchEnabled(true);
}

wyVirtualJoystick::~wyVirtualJoystick() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
#endif
}

wyVirtualJoystick* wyVirtualJoystick::make(wyNode* bg, wyNode* rocker) {
	wyVirtualJoystick* vj = WYNEW wyVirtualJoystick(bg, rocker);
	return (wyVirtualJoystick*)vj->autoRelease();
}

void wyVirtualJoystick::adjustRockerPosition(float x, float y) {
	// to node space
	wyPoint p = wyp(x, y);
	p = worldToNodeSpace(p);
	wyPoint center = wyp(m_width / 2, m_height / 2);

	// check position, if in rocker radius, just set it
	// if not, connect position to center and pick the intersect point
	float distance = wypDistance(p, center);
	if(distance > m_rockerRangeRadius) {
		float ratio = m_rockerRangeRadius / distance;
		float rX = p.x - m_width / 2;
		float rY = p.y - m_height / 2;
		p.x = m_width / 2 + rX * ratio;
		p.y = m_height / 2 + rY * ratio;
	}

	// save position
	m_rockerX = p.x;
	m_rockerY = p.y;

	// set rocker position
	if(m_rocker) {
		m_rocker->setPosition(p.x, p.y);
	}

	// change degree
	m_degree = wypToDegree(wypSub(p, center));
	if(m_degree < 0)
		m_degree += 360;
}

bool wyVirtualJoystick::touchesBegan(wyMotionEvent& e) {
	if(!m_navigating) {
		m_navigating = true;

		// save pid and position
		m_pid = e.pid[0];

		// set rocker position
		adjustRockerPosition(e.x[0], e.y[0]);

		// notify callback
		invokeOnVJNavigationStarted();
		invokeOnVJDirectionChanged(m_direction);
	}

	return wyNode::touchesBegan(e);
}

bool wyVirtualJoystick::touchesMoved(wyMotionEvent& e) {
	if(m_navigating) {
		for(int i = 0; i < e.pointerCount; i++) {
			if(e.pid[i] == m_pid) {
				adjustRockerPosition(e.x[i], e.y[i]);
				invokeOnVJDirectionChanged();
			}
		}
	}

	return wyNode::touchesMoved(e);
}

bool wyVirtualJoystick::touchesEnded(wyMotionEvent& e) {
	if(m_navigating) {
		if(m_autoReset) {
			if(m_rocker)
				m_rocker->setPosition(m_width / 2, m_height / 2);
			m_degree = VJD_CENTER;
			m_direction = VJD_CENTER;
			invokeOnVJDirectionChanged(VJD_CENTER);
		} else {
			for(int i = 0; i < e.pointerCount; i++) {
				if(e.pid[i] == m_pid) {
					adjustRockerPosition(e.x[i], e.y[i]);
					invokeOnVJDirectionChanged();
				}
			}
		}

		// notify
		invokeOnVJNavigationEnded();

		// reset flag
		m_navigating = false;
	}

	return wyNode::touchesEnded(e);
}

bool wyVirtualJoystick::touchesCancelled(wyMotionEvent& e) {
	if(m_navigating) {
		if(m_autoReset) {
			if(m_rocker)
				m_rocker->setPosition(m_width / 2, m_height / 2);
			m_degree = VJD_CENTER;
			m_direction = VJD_CENTER;
			invokeOnVJDirectionChanged(VJD_CENTER);
		} else {
			for(int i = 0; i < e.pointerCount; i++) {
				if(e.pid[i] == m_pid) {
					adjustRockerPosition(e.x[i], e.y[i]);
					invokeOnVJDirectionChanged();
				}
			}
		}

		// callback
		invokeOnVJNavigationEnded();

		// reset flag
		m_navigating = false;
	}

	return wyNode::touchesCancelled(e);
}

bool wyVirtualJoystick::touchesPointerBegan(wyMotionEvent& e) {
	if(!m_navigating) {
		m_navigating = true;

		// save pid and position
		m_pid = e.pid[e.index];

		// set rocker position
		adjustRockerPosition(e.x[e.index], e.y[e.index]);

		// notify callback
		invokeOnVJNavigationStarted();
		invokeOnVJDirectionChanged(m_direction);
	}

	return wyNode::touchesPointerBegan(e);
}

bool wyVirtualJoystick::touchesPointerEnded(wyMotionEvent& e) {
	if(m_navigating) {
		if(m_pid == e.pid[e.index]) {
			if(m_autoReset) {
				if(m_rocker)
					m_rocker->setPosition(m_width / 2, m_height / 2);
				m_degree = VJD_CENTER;
				m_direction = VJD_CENTER;
				invokeOnVJDirectionChanged(VJD_CENTER);
			} else {
				adjustRockerPosition(e.x[e.index], e.y[e.index]);
				invokeOnVJDirectionChanged();
			}

			// notify
			invokeOnVJNavigationEnded();

			// reset flag
			m_navigating = false;
		}
	}

	return wyNode::touchesPointerEnded(e);
}

void wyVirtualJoystick::setCallback(wyVirtualJoystickCallback* callback, void* data) {
	if(callback == NULL) {
		memset(&m_callback, 0, sizeof(wyVirtualJoystickCallback));
		m_data = NULL;
	} else {
		memcpy(&m_callback, callback, sizeof(wyVirtualJoystickCallback));
		m_data = data;
	}
}

#if ANDROID
void wyVirtualJoystick::setCallback(jobject callback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
	m_jCallback = env->NewGlobalRef(callback);
}
#endif

int wyVirtualJoystick::degree2Direction() {
	// for five direction
	static int fiveArray[] = {
			VJD_EAST,
			VJD_NORTH,
			VJD_WEST,
			VJD_SOUTH,
			VJD_EAST
	};

	// for nine directions
	static int nineArray[] = {
			VJD_EAST,
			VJD_NORTH_EAST,
			VJD_NORTH,
			VJD_NORTH_WEST,
			VJD_WEST,
			VJD_SOUTH_WEST,
			VJD_SOUTH,
			VJD_SOUTH_EAST,
			VJD_EAST
	};

	/*
	 * first we need check distance between rocker position and center, if
	 * distance is smaller than one third of rocker range radius, then neglect
	 */
	float distance = wypDistance(wyp(m_rockerX, m_rockerY), wyp(m_width / 2, m_height / 2));
	if(distance < m_rockerRangeRadius / 3.f)
		return VJD_CENTER;
	else {
		switch(m_eventStyle) {
			case VJS_FIVE_DIRECTIONS:
				return fiveArray[(m_degree + 45) / 90];
			case VJS_NINE_DIRECTIONS:
				return nineArray[(int)((m_degree + 22.5f) / 45)];
			default:
				return m_degree;
		}
	}
}

void wyVirtualJoystick::invokeOnVJNavigationStarted() {
	if(m_callback.onVJNavigationStarted != NULL) {
		m_callback.onVJNavigationStarted(this, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IVirtualJoystickCallback_onVJNavigationStarted, (jint)this);
	}
#endif
}

void wyVirtualJoystick::invokeOnVJNavigationEnded() {
	if(m_callback.onVJNavigationEnded != NULL) {
		m_callback.onVJNavigationEnded(this, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IVirtualJoystickCallback_onVJNavigationEnded, (jint)this);
	}
#endif
}

void wyVirtualJoystick::invokeOnVJDirectionChanged() {
	int newDirection = degree2Direction();
	if(m_direction != newDirection) {
		m_direction = newDirection;
		invokeOnVJDirectionChanged(newDirection);
	}
}

void wyVirtualJoystick::invokeOnVJDirectionChanged(int newDirection) {
	if(m_callback.onVJDirectionChanged != NULL) {
		m_callback.onVJDirectionChanged(this, newDirection, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IVirtualJoystickCallback_onVJDirectionChanged, (jint)this, newDirection);
	}
#endif
}
