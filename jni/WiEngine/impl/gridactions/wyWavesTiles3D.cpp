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
#include "wyWavesTiles3D.h"
#include "wyNode.h"

wyAction* wyWavesTiles3D::copy() {
	return wyWavesTiles3D::make(m_duration, m_gridX, m_gridY, m_amplitude, m_waves);
}

void wyWavesTiles3D::update(float t) {
	wyDimension gridPos = wydZero;
	for(int i = 0; i < m_gridX; i++) {
		for(int j = 0; j < m_gridY; j++) {
			gridPos.x = i;
			gridPos.y = j;
			wyQuad3D coords = getOriginalTile(gridPos);

			// set z of four corners to same
			coords.bl_z = wyMath::sin(t * M_PI * m_waves * 2 + (coords.bl_y + coords.bl_x) * .01f) * m_amplitude * m_amplitudeRate;
			coords.br_z = coords.bl_z;
			coords.tl_z = coords.bl_z;
			coords.tr_z = coords.bl_z;

			setTile(gridPos, coords);
		}
	}

	// super only call callback
	wyTiledGrid3DAction::update(t);
}

wyWavesTiles3D::~wyWavesTiles3D() {
}

wyWavesTiles3D::wyWavesTiles3D(float duration, int gridX, int gridY, float amplitude, int waves) :
		wyTiledGrid3DAction(duration, gridX, gridY),
		m_waves(waves) {
	m_amplitude = amplitude;
}

wyWavesTiles3D* wyWavesTiles3D::make(float duration, int gridX, int gridY, float amplitude, int waves) {
	wyWavesTiles3D* a = WYNEW wyWavesTiles3D(duration, gridX, gridY, amplitude, waves);
	return (wyWavesTiles3D*)a->autoRelease();
}
