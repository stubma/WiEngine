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
#include "wyBox2D.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyBox2DDebugDraw.h"

wyBox2D* wyBox2D::make() {
	wyBox2D* box2d = WYNEW wyBox2D();
	return (wyBox2D*)box2d->autoRelease();
}

wyBox2D::wyBox2D() :
		wyNode(),
		m_world(new b2World(b2Vec2(0, 0))),
		m_ddImpl(NULL),
		m_debugDraw(false) {
	// create debug draw
	m_ddImpl = WYNEW wyBox2DDebugDraw(this);

	// default meter pixels
	setMeterPixels(MIN(wyDevice::winWidth, wyDevice::winHeight) / 20);

	// set debug draw callback
	m_world->SetDebugDraw(m_ddImpl);
	m_world->SetBox2D(this);
}

wyBox2D::~wyBox2D() {
	delete m_world;
	m_world = NULL;

	WYDELETE(m_ddImpl);
	m_ddImpl = NULL;
}

void wyBox2D::beforeRender() {
	if(m_debugDraw) {
		removeRenderPairsByTag(-1);
		m_world->DrawDebugData();
	}
}

float wyBox2D::getMeterPixels() {
	return m_ddImpl->getMeterPixels();
}

void wyBox2D::setMeterPixels(float mp) {
	m_ddImpl->setMeterPixels(mp);
}

float wyBox2D::pixel2Meter(float pixel) {
	return m_ddImpl->pixel2Meter(pixel);
}

float wyBox2D::meter2Pixel(float meter) {
	return m_ddImpl->meter2Pixel(meter);
}
