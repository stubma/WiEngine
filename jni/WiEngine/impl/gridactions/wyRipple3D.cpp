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
#include "wyRipple3D.h"
#include "wyNode.h"

wyAction* wyRipple3D::copy() {
	return wyRipple3D::make(m_duration, m_gridX, m_gridY, m_centerX, m_centerX,
			m_deltaX, m_deltaY, m_radius, m_deltaRadius, m_amplitude, m_deltaAmplitude, m_waves);
}

void wyRipple3D::update(float t) {
	int i, j;

	wyDimension gridPos = wydZero;
	for(i = 0; i < (m_gridX + 1); i++) {
		for(j = 0; j < (m_gridY + 1); j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D v = getOriginalVertex(gridPos);
			wyPoint vect = wyp(m_lastX - v.x, m_lastY - v.y);
			float len = wypLength(vect);

			if(len < m_lastRadius) {
				len = m_lastRadius - len;
				float rate = pow(len / m_lastRadius, 2);
				v.z += wyMath::sin(t * M_PI * m_waves * 2 + len * 0.1f) * m_lastAmplitude * m_amplitudeRate * rate;
			}

			setVertex(gridPos, v);
		}
	}

	m_lastX = m_centerX + m_deltaX * t;
	m_lastY = m_centerY + m_deltaY * t;
	m_lastAmplitude = m_amplitude + m_deltaAmplitude * t;
	m_lastRadius = m_radius + m_deltaRadius * t;

	// super only call callback
	wyGrid3DAction::update(t);
}

wyRipple3D::~wyRipple3D() {
}

wyRipple3D::wyRipple3D(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float amplitude, float deltaAmplitude, float waves) :
		wyGrid3DAction(duration, gridX, gridY),
		m_centerX(centerX),
		m_centerY(centerY),
		m_deltaX(deltaX),
		m_deltaY(deltaY),
		m_radius(radius),
		m_deltaRadius(deltaRadius),
		m_waves(waves),
		m_deltaAmplitude(deltaAmplitude),
		m_lastX(centerX),
		m_lastY(centerY),
		m_lastRadius(radius),
		m_lastAmplitude(amplitude) {
}

wyRipple3D* wyRipple3D::make(float duration, int gridX, int gridY, float centerX, float centerY,
			float deltaX, float deltaY, float radius, float deltaRadius, float amplitude, float deltaAmplitude, float waves) {
	wyRipple3D* a = WYNEW wyRipple3D(duration, gridX, gridY, centerX, centerY, deltaX, deltaY, radius, deltaRadius, amplitude, deltaAmplitude, waves);
	return (wyRipple3D*)a->autoRelease();
}
