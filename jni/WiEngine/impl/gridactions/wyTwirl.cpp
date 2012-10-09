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
#include "wyTwirl.h"
#include "wyNode.h"

wyAction* wyTwirl::copy() {
	return wyTwirl::make(m_duration, m_gridX, m_gridY, m_centerX, m_centerY,
			m_deltaX, m_deltaY, m_amplitude, m_deltaAmplitude, m_twirls);
}

void wyTwirl::update(float t) {
	int i, j;
	wyDimension gridPos = wydZero;
	for(i = 0; i < (m_gridX + 1); i++) {
		for(j = 0; j < (m_gridY + 1); j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D v = getOriginalVertex(gridPos);

			wyPoint avg = wyp(i - (m_gridX / 2.0f), j - (m_gridY / 2.0f));
			float r = wypLength(avg);

			float amp = 0.1f * m_lastAmplitude * m_amplitudeRate;
			float a = r * wyMath::cos(M_PI / 2.0f + t * M_PI * m_twirls * 2) * amp;

			float dx = wyMath::sin(a) * (v.y - m_lastY) + wyMath::cos(a) * (v.x - m_lastX);
			float dy = wyMath::cos(a) * (v.y - m_lastY) - wyMath::sin(a) * (v.x - m_lastX);

			v.x = m_lastX + dx;
			v.y = m_lastY + dy;

			setVertex(gridPos, v);
		}
	}

	m_lastX = m_centerX + m_deltaX * t;
	m_lastY = m_centerY + m_deltaY * t;
	m_lastAmplitude = m_amplitude + m_deltaAmplitude * t;

	// super only call callback
	wyGrid3DAction::update(t);
}

wyTwirl::~wyTwirl() {
}

wyTwirl::wyTwirl(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude, float deltaAmplitude, float twirls) :
        wyGrid3DAction(duration, gridX, gridY),
        m_centerX(centerX),
        m_centerY(centerY),
        m_deltaX(deltaX),
        m_deltaY(deltaY),
        m_lastX(centerX),
        m_lastY(centerY),
        m_twirls(twirls),
        m_deltaAmplitude(deltaAmplitude),
        m_lastAmplitude(amplitude) {
	m_amplitude = amplitude;
}

wyTwirl* wyTwirl::make(float duration, int gridX, int gridY, float centerX, float centerY, float deltaX, float deltaY, float amplitude,
	        float deltaAmplitude, float twirls) {
	wyTwirl* a = WYNEW wyTwirl(duration, gridX, gridY, centerX, centerY, deltaX, deltaY, amplitude, deltaAmplitude, twirls);
	return (wyTwirl*)a->autoRelease();
}
