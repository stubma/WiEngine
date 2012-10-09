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
#include "wyScroller.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"

/**
 * values returned by the accelerometer in earth.
 * all values are in SI units (m/s^2)
 */
#define GRAVITY_EARTH 9.80665f

/// 缺省持续时间, 毫秒
#define DEFAULT_DURATION 250

/// 滚动模式
#define SCROLL_MODE 0

/// fling模式
#define FLING_MODE 1

wyScroller::wyScroller() :
		m_scrollFriction(0.015f),
		m_coeffX(0.0f),
		m_coeffY(1.0f),
		m_finished(true),
		m_deceleration(GRAVITY_EARTH * 39.37f * wyDevice::density * 160.f * 0.015f) {
}

wyScroller::~wyScroller() {
}

wyScroller* wyScroller::make() {
	wyScroller* s = WYNEW wyScroller();
	return (wyScroller*)s->autoRelease();
}

int wyScroller::timePassed() const {
	return (int)(wyUtils::currentTimeMillis() - m_startTime);
}

bool wyScroller::computeScrollOffset() {
	if(m_finished) {
		return false;
	}

	int timePassed = (int) (wyUtils::currentTimeMillis() - m_startTime);

	if(timePassed < m_duration) {
		switch(m_mode) {
			case SCROLL_MODE:
			{
				float x = (float) timePassed * m_durationReciprocal;
				x = viscousFluid(x);

				m_currX = m_startX + round(x * m_deltaX);
				m_currY = m_startY + round(x * m_deltaY);
				break;
			}
			case FLING_MODE:
			{
				float timePassedSeconds = timePassed / 1000.0f;
				float distance = (m_velocity * timePassedSeconds) - (m_deceleration * timePassedSeconds
						* timePassedSeconds / 2.0f);

				// Pin to mMinX <= mCurrX <= mMaxX
				m_currX = m_startX + round(distance * m_coeffX);
				m_currX = MIN(m_currX, m_maxX);
				m_currX = MAX(m_currX, m_minX);

				// Pin to mMinY <= mCurrY <= mMaxY
				m_currY = m_startY + round(distance * m_coeffY);
				m_currY = MIN(m_currY, m_maxY);
				m_currY = MAX(m_currY, m_minY);

				break;
			}
		}
	} else {
		m_currX = m_finalX;
		m_currY = m_finalY;
		m_finished = true;
	}
	return true;
}

void wyScroller::startScroll(float startX, float startY, float dx, float dy) {
    startScroll(startX, startY, dx, dy, DEFAULT_DURATION);
}

void wyScroller::startScroll(float startX, float startY, float dx, float dy, int duration) {
    m_mode = SCROLL_MODE;
    m_finished = false;
    m_duration = duration;
    m_startTime = (int)wyUtils::currentTimeMillis();
    m_startX = startX;
    m_startY = startY;
    m_finalX = startX + dx;
    m_finalY = startY + dy;
    m_deltaX = dx;
    m_deltaY = dy;
    m_durationReciprocal = 1.0f / (float) m_duration;

    // This controls the viscous fluid effect (how much of it)
    m_viscousFluidScale = 8.0f;

    // must be set to 1.0 (used in viscousFluid())
    m_viscousFluidNormalize = 1.0f;
    m_viscousFluidNormalize = 1.0f / viscousFluid(1.0f);
}

void wyScroller::fling(float startX, float startY, float velocityX, float velocityY,
		float minX, float maxX, float minY, float maxY) {
    m_mode = FLING_MODE;
    m_finished = false;

    float velocity = (float)hypot(velocityX, velocityY);

    m_velocity = velocity;
    m_duration = (int) (1000 * velocity / m_deceleration);
    m_startTime = wyUtils::currentTimeMillis();
    m_startX = startX;
    m_startY = startY;

    m_coeffX = velocity == 0 ? 1.0f : velocityX / velocity;
    m_coeffY = velocity == 0 ? 1.0f : velocityY / velocity;

    int totalDistance = (int) ((velocity * velocity) / (2 * m_deceleration));
    m_minX = minX;
    m_maxX = maxX;
    m_minY = minY;
    m_maxY = maxY;

    // Pin to mMinX <= mFinalX <= mMaxX
    m_finalX = startX + round(totalDistance * m_coeffX);
    m_finalX = MIN(m_finalX, m_maxX);
    m_finalX = MAX(m_finalX, m_minX);

    // Pin to mMinY <= mFinalY <= mMaxY
    m_finalY = startY + round(totalDistance * m_coeffY);
    m_finalY = MIN(m_finalY, m_maxY);
    m_finalY = MAX(m_finalY, m_minY);
}

float wyScroller::viscousFluid(float x) {
    x *= m_viscousFluidScale;
    if (x < 1.0f) {
        x -= (1.0f - (float)exp(-x));
    } else {
        float start = 0.36787944117f;   // 1/e == exp(-1)
        x = 1.0f - (float)exp(1.0f - x);
        x = start + x * (1.0f - start);
    }
    x *= m_viscousFluidNormalize;
    return x;
}

void wyScroller::abortAnimation() {
    m_currX = m_finalX;
    m_currY = m_finalY;
    m_finished = true;
}

void wyScroller::extendDuration(int extend) {
    int passed = timePassed();
    m_duration = passed + extend;
    m_durationReciprocal = 1.0f / (float)m_duration;
    m_finished = false;
}

void wyScroller::setFinalX(float newX) {
    m_finalX = newX;
    m_deltaX = m_finalX - m_startX;
    m_finished = false;
}

void wyScroller::setFinalY(float newY) {
    m_finalY = newY;
    m_deltaY = m_finalY - m_startY;
    m_finished = false;
}
