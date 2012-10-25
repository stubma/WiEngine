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
#include "wySlider.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyProgress.h"

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_ISliderCallback_onSliderValueChanged;
#endif

wySlider::wySlider(wySprite* bg, wySprite* bar, wySprite* thumb, bool vertical) :
		m_min(0),
		m_max(100),
		m_value(0),
		m_vertical(vertical),
		m_data(NULL),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_showFullBar(false),
		m_dragging(false) {
	// init callback
	memset(&m_callback, 0, sizeof(wySliderCallback));

	// assign
	m_bg = bg;
	m_progressTimer = wyProgressTimer::make(bar);
	m_thumb = thumb;

	// decide slider size
	int w = 0, h = 0;
	if(m_bg != NULL) {
		w = m_bg->getWidth();
		h = m_bg->getHeight();
	}
	w = MAX(w, m_progressTimer->getWidth());
	h = MAX(h, m_progressTimer->getHeight());
	if(m_thumb != NULL) {
		if(m_vertical) {
			w = MAX(w, thumb->getWidth());
			h = MAX(h, m_progressTimer->getHeight() + m_thumb->getHeight());
		} else {
			w = MAX(w, m_progressTimer->getWidth() + m_thumb->getWidth());
			h = MAX(h, thumb->getHeight());
		}
	}
	setContentSize(w, h);

	// add bg
	if(m_bg != NULL) {
		m_bg->setAnchor(0.5f, 0.5f);
		m_bg->setPosition(w / 2, h / 2);
		addChildLocked(m_bg);
	}

	// add timer
	m_progressTimer->setAnchor(0.5f, 0.5f);
	m_progressTimer->setPosition(w / 2, h / 2);
	m_progressTimer->setStyle(m_vertical ? wyProgress::VERTICAL_BAR_BT : wyProgress::HORIZONTAL_BAR_LR);
	addChildLocked(m_progressTimer);

	// add thumb
	if(m_thumb != NULL) {
		m_thumb->setAnchor(0.5f, 0.5f);
		if(m_vertical)
			m_thumb->setPosition(w / 2, h / 2 - m_progressTimer->getHeight() / 2);
		else
			m_thumb->setPosition(w / 2 - m_progressTimer->getWidth() / 2, h / 2);
		addChildLocked(m_thumb);
	}

	// enable touch default
	setTouchEnabled(true);
}

wySlider::~wySlider() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
#endif
}

wySlider* wySlider::make(wySprite* bg, wySprite* bar, wySprite* thumb, bool vertical) {
	wySlider* n = WYNEW wySlider(bg, bar, thumb, vertical);
	return (wySlider*)n->autoRelease();
}

void wySlider::invokeOnValueChanged() {
	if(m_callback.onValueChanged != NULL) {
		m_callback.onValueChanged(this, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_ISliderCallback_onSliderValueChanged, (jint)this, m_value);
	}
#endif
}

void wySlider::setMin(float min) {
	if(min < m_max) {
		m_min = min;
		m_value = MAX(m_min, m_value);
		updateUI();
	}
}

void wySlider::setMax(float max) {
	if(max > m_min) {
		m_max = max;
		m_value = MIN(m_max, m_value);
		updateUI();
	}
}

void wySlider::setValue(float value) {
	float newValue = MIN(MAX(value, m_min), m_max);
	if(m_value != newValue) {
		m_value = newValue;
		updateUI();
		invokeOnValueChanged();
	}
}

void wySlider::setShowFullBar(bool flag) {
	m_showFullBar = flag;
	if(m_showFullBar) {
		m_progressTimer->setPercentage(100.0f);
	} else {
		float percent = (float)(m_value - m_min) / (float)(m_max - m_min);
		m_progressTimer->setPercentage(percent);
	}
}

void wySlider::updateUI() {
	float percent = (m_value - m_min) / (m_max - m_min);
	if(!m_showFullBar)
		m_progressTimer->setPercentage(percent * 100.f);
	updateThumbPosition(percent);
}

void wySlider::updateThumbPosition(float percent) {
	if(m_thumb) {
		if(m_vertical)
			m_thumb->setPosition(getWidth() / 2, percent * m_progressTimer->getHeight() + getHeight() / 2 - m_progressTimer->getHeight() / 2);
		else
			m_thumb->setPosition(percent * m_progressTimer->getWidth() + getWidth() / 2 - m_progressTimer->getWidth() / 2, getHeight() / 2);
	}
}

void wySlider::setValueFromLocation(wyPoint loc) {
	float clickLen = m_vertical ? (loc.y - (m_height / 2 - m_progressTimer->getHeight() / 2))
			: (loc.x - (m_width / 2 - m_progressTimer->getWidth() / 2));
	float percent = clickLen / (m_vertical ? m_progressTimer->getHeight() : m_progressTimer->getWidth());
	setValue(percent * (m_max - m_min) + m_min);
}

bool wySlider::touchesBegan(wyMotionEvent& e) {
	// thumb clicked?
	if(m_thumb) {
		m_dragging = m_thumb->hitTest(e.x[0], e.y[0]);
	}

	// if not dragging, means it clicks other parts
	if(!m_dragging) {
		setValueFromLocation(worldToNodeSpace(wyp(e.x[0], e.y[0])));
	}

	return true;
}

bool wySlider::touchesMoved(wyMotionEvent& e) {
	if(m_dragging) {
		setValueFromLocation(worldToNodeSpace(wyp(e.x[0], e.y[0])));
	}
	return true;
}

bool wySlider::touchesEnded(wyMotionEvent& e) {
	if(m_dragging) {
		m_dragging = false;
		setValueFromLocation(worldToNodeSpace(wyp(e.x[0], e.y[0])));
	}

	return true;
}

bool wySlider::touchesCancelled(wyMotionEvent& e) {
	if(m_dragging) {
		m_dragging = false;
		setValueFromLocation(worldToNodeSpace(wyp(e.x[0], e.y[0])));
	}

	return true;
}

void wySlider::setCallback(wySliderCallback* callback, void* data) {
	if(callback == NULL) {
		memset(&m_callback, 0, sizeof(wySliderCallback));
		m_data = NULL;
	} else {
		memcpy(&m_callback, callback, sizeof(wySliderCallback));
		m_data = data;
	}
}

#if ANDROID
void wySlider::setCallback(jobject callback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
	m_jCallback = env->NewGlobalRef(callback);
}
#endif
