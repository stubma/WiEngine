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
#include "wyGradientColorLayer.h"
#include "wyDirector.h"
#include "wyLog.h"
#include <stdlib.h>
#include <math.h>
#include "wyGlobal.h"
#include "wyMaterial.h"
#include "wyShape.h"

wyGradientColorLayer::wyGradientColorLayer(wyColor4B fromColor, wyColor4B toColor, int degree) :
		m_fromColor(fromColor),
		m_toColor(toColor),
		m_degree(degree) {
	// add render pair
	addRenderPair(wyMaterial::make(wyShaderManager::PROG_PC), wyShape::make());

	// set content size
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);

	// blend mode
	setBlendMode(wyRenderState::ALPHA);

	// dither it
	setDither(true);
}

wyGradientColorLayer* wyGradientColorLayer::make(wyColor4B fromColor, wyColor4B toColor, int degree) {
	wyGradientColorLayer* n = WYNEW wyGradientColorLayer(fromColor, toColor, degree);
	return (wyGradientColorLayer*)n->autoRelease();
}

void wyGradientColorLayer::updateMesh() {
	((wyShape*)getMesh())->buildGradientRect(0, 0, m_width, m_height, m_fromColor, m_toColor, m_degree);
}

wyColor3B wyGradientColorLayer::getFromColor() {
	wyColor3B c = {
		m_fromColor.r,
		m_fromColor.g,
		m_fromColor.b
	};
	return c;
}

void wyGradientColorLayer::setFromColor(wyColor3B color) {
	m_fromColor.r = color.r;
	m_fromColor.g = color.g;
	m_fromColor.b = color.b;
	setNeedUpdateMesh(true);
}

wyColor3B wyGradientColorLayer::getToColor() {
	wyColor3B c = {
		m_toColor.r,
		m_toColor.g,
		m_toColor.b
	};
	return c;
}

void wyGradientColorLayer::setToColor(wyColor3B color) {
	m_toColor.r = color.r;
	m_toColor.g = color.g;
	m_toColor.b = color.b;
	setNeedUpdateMesh(true);
}

wyGradientColorLayer::~wyGradientColorLayer() {
}

void wyGradientColorLayer::setDegree(int degree) {
	m_degree = degree;
	setNeedUpdateMesh(true);
}

int wyGradientColorLayer::getDegree() {
	return m_degree;
}
