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
#include "wyLiquid.h"
#include "wyNode.h"

wyAction* wyLiquid::copy() {
	return wyLiquid::make(m_duration, m_gridX, m_gridY, m_amplitude, m_deltaAmplitude, m_waves);
}

void wyLiquid::update(float t) {
	int i, j;

	wyDimension gridPos = wydZero;
	for(i = 1; i < m_gridX; i++) {
		for(j = 1; j < m_gridY; j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D v = getOriginalVertex(gridPos);
			v.x += wyMath::sin(t * M_PI * m_waves * 2 + v.x * .01f) * m_lastAmplitude * m_amplitudeRate;
			v.y += wyMath::sin(t * M_PI * m_waves * 2 + v.y * .01f) * m_lastAmplitude * m_amplitudeRate;
			setVertex(gridPos, v);
		}
	}

	m_lastAmplitude = m_amplitude + m_deltaAmplitude * t;

	// super only call callback
	wyGrid3DAction::update(t);
}

wyLiquid::~wyLiquid() {
}

wyLiquid::wyLiquid(float duration, int gridX, int gridY, float amplitude, float deltaAmplitude, float waves) :
		wyGrid3DAction(duration, gridX, gridY),
		m_waves(waves),
		m_deltaAmplitude(deltaAmplitude),
		m_lastAmplitude(m_lastAmplitude) {
	m_amplitude = amplitude;
}

wyLiquid* wyLiquid::make(float duration, int gridX, int gridY, float amplitude, float deltaAmplitude, float waves) {
	wyLiquid* a = WYNEW wyLiquid(duration, gridX, gridY, amplitude, deltaAmplitude, waves);
	return (wyLiquid*)a->autoRelease();
}
