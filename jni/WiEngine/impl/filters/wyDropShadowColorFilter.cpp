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
#include "wyDropShadowColorFilter.h"
#include "wyLog.h"

wyDropShadowColorFilter::wyDropShadowColorFilter(wyColor3B color, int radius, int highlightRadius, int opacity) :
		m_color(color),
		m_radius(radius),
		m_highlightRadius(highlightRadius),
		m_opacity(opacity) {
}

wyDropShadowColorFilter::~wyDropShadowColorFilter() {
}

wyDropShadowColorFilter* wyDropShadowColorFilter::make(wyColor3B color, int radius, int highlightRadius, int opacity) {
	wyDropShadowColorFilter* f = WYNEW wyDropShadowColorFilter(color, radius, highlightRadius, opacity);
	return (wyDropShadowColorFilter*)f->autoRelease();
}

void wyDropShadowColorFilter::apply(void* data, int width, int height) {
	// if radius is less than 1, just do nothing
	if(m_radius < 1)
		return;

	float highlightRadiusIncrease = m_radius < m_highlightRadius * 2 ? 0.15f : m_radius < m_highlightRadius * 3 ? 0.09f : 0.02f;
	m_opacity = m_opacity > 255 ? 255 : m_opacity < 0 ? 0 : m_opacity;

	int shift = (int) (m_radius * 0.2f);
	unsigned char* line = (unsigned char*)data;

	for(int row = 0; row < m_radius; row++) {
		for(int col = 0; col < shift; col++) {
			line[(height - row - 1) * width * 4 + (col) * 4 + 3] = 0;
			line[(col) * width * 4 + (width - row - 1) * 4 + 3] = 0;
		}
	}

	for (int row = 0; row < height; row++) {
		int alphas = 0;
		if (row < m_radius) {
			// only calculate alpha values for top border. they will reflect to the bottom border
			int intensity = (int) (m_opacity * (((row + 1) / (float)(m_radius))));
			for (int col = 0; col < width / 2 + width % 2; col++) {
				if(col < m_radius) {
					// deal with corners:
					// calculate pixel's distance from image corner
					float hypotenuse = sqrt((float)(pow((float)(m_radius - col - 1), 2) + pow((float)(m_radius - 1 - row), 2)));

					// calculate alpha based on percent distance from image
					alphas = m_opacity * MAX(((m_radius - hypotenuse) / m_radius), 0);

					// add highlight radius
					if(hypotenuse < MIN(m_highlightRadius, m_radius * 0.5f)) {
						alphas = MIN(255, (alphas & 0x0FF) * (1 + highlightRadiusIncrease * MAX(((m_radius - hypotenuse) / m_radius), 0)));
					}
				} else {
					alphas = row > MAX(m_radius - m_highlightRadius - 1, m_radius * 0.5f) ?
							MIN(255, (intensity & 0x0FF) * (1 + highlightRadiusIncrease * row / m_radius)) : intensity;
				}
				line[(height - row - 1) * width * 4 + (col + shift) * 4] = m_color.r;
				line[(height - row - 1) * width * 4 + (col + shift) * 4 + 1] = m_color.g;
				line[(height - row - 1) * width * 4 + (col + shift) * 4 + 2] = m_color.b;
				line[(height - row - 1) * width * 4 + (col + shift) * 4 + 3] = alphas;

				line[(height - row - 1) * width * 4 + (width - col - 1) * 4] = m_color.r;
				line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 1] = m_color.g;
				line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 2] = m_color.b;
				line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 3] = alphas;

				if(col < m_radius && row + shift < height) {
					line[(row + shift) * width * 4 + (width - col - 1) * 4] = m_color.r;
					line[(row + shift) * width * 4 + (width - col - 1) * 4 + 1] = m_color.g;
					line[(row + shift) * width * 4 + (width - col - 1) * 4 + 2] = m_color.b;
					line[(row + shift) * width * 4 + (width - col - 1) * 4 + 3] = alphas;
				}
			}
		} else if (row <= height / 2) {
			// deal with rows the image resides on

			// calculate alpha values
			float intensity = 0.0f;
			for(int col = 0; col < width; col++) {
				if(col < m_radius) {
					intensity = (m_opacity * ((col + 1) / (float) m_radius));
					if(col > MAX(m_radius - m_highlightRadius - 1, m_radius * 0.5f)) {
						intensity = MIN(255, (intensity) * (1 + highlightRadiusIncrease * col / m_radius));
					}
					alphas = (int) (intensity);
					if(row + shift < height) {
						line[(row + shift) * width * 4 + (width - col - 1) * 4] = m_color.r;
						line[(row + shift) * width * 4 + (width - col - 1) * 4 + 1] = m_color.g;
						line[(row + shift) * width * 4 + (width - col - 1) * 4 + 2] = m_color.b;
						line[(row + shift) * width * 4 + (width - col - 1) * 4 + 3] = alphas;
					}

					line[(height - row - 1) * width * 4 + (width - col - 1) * 4] = m_color.r;
					line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 1] = m_color.g;
					line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 2] = m_color.b;
					line[(height - row - 1) * width * 4 + (width - col - 1) * 4 + 3] = alphas;
				}
			}
		}
	}
}
