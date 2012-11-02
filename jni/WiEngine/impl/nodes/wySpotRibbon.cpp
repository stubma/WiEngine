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
#include "wySpotRibbon.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyQuadList.h"
#include "wyMaterial.h"
#include "wyLog.h"

wySpotRibbon* wySpotRibbon::make(wyTexture2D* tex, wyColor4B color, float fade) {
	wySpotRibbon* r = WYNEW wySpotRibbon(tex, color, fade);
	return (wySpotRibbon*)r->autoRelease();
}

wySpotRibbon::wySpotRibbon(wyTexture2D* tex, wyColor4B color, float fade) :
		wyRibbon(fade),
		m_distance(DP(20)) {
	// create empty material and mesh
	addRenderPair(wyMaterial::make(), wyQuadList::make());

	// set texture
	tex->setAntiAlias(false);
	setTexture(tex);

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set color
	setColor(color);
}

wySpotRibbon::~wySpotRibbon() {
}

void wySpotRibbon::updateMeshColor() {
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->updateColor(m_color);
}

void wySpotRibbon::addPoint(wyPoint location) {
	// if this is the first point added, cache it and return
	if (m_firstPoint) {
		m_lastLocation = location;
		m_preLastLocation = location;
		m_firstPoint = false;
		m_remaining = 0;
		return;
	}

	// get texture info
	wyTexture2D* tex = getTexture();
	float tW = tex->getWidth();
	float tH = tex->getHeight();
	float texW = tW / tex->getPixelWidth();
	float texH = tH / tex->getPixelHeight();

	// get distance between last location and current location
	float len = wypDistance(m_lastLocation, location);

	// delta x/y
	float dx = location.x - m_lastLocation.x;
	float dy = location.y - m_lastLocation.y;

	if(m_remaining + len >= m_distance) {
		// total length
		m_remaining += len;

		// create texture quad
		wyQuad2D t = wyq2(0, texH,
				texW, texH,
				0, 0,
				texW, 0);

		// start to cut gap
		wyQuadList* atlas = (wyQuadList*)getMesh();
		float percent = m_distance / m_remaining;
		while(m_remaining >= m_distance) {
			// get tag point
			wyPoint p = wyp(m_lastLocation.x + percent * dx, m_lastLocation.y + percent * dy);

			// create vertices quad
			wyQuad3D v = wyq3(p.x - tW / 2, p.y - tH / 2, 0,
					p.x + tW / 2, p.y - tH / 2, 0,
					p.x - tW / 2, p.y + tH / 2, 0,
					p.x + tW / 2, p.y + tH / 2, 0);

			// add to atlas
			atlas->appendQuad(t, v, m_color);

			// adjust
			m_remaining -= m_distance;
			m_preLastLocation = m_lastLocation;
			m_lastLocation = p;
		}
	}
}

void wySpotRibbon::update(float delta) {
	if(m_fadeTime != 0) {
		wyQuadList* atlas = (wyQuadList*)getMesh();
		atlas->reduceAlpha(delta / m_fadeTime);
	}
}

void wySpotRibbon::reset() {
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->removeAllQuads();
	m_preLastLocation = m_lastLocation = wypZero;
	m_remaining = 0;
	m_firstPoint = true;
}
