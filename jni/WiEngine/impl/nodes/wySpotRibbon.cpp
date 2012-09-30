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

wySpotRibbon* wySpotRibbon::make(wyTexture2D* tex, wyColor4B color, float fade) {
	wySpotRibbon* r = WYNEW wySpotRibbon(tex, color, fade);
	return (wySpotRibbon*)r->autoRelease();
}

wySpotRibbon::wySpotRibbon(wyTexture2D* tex, wyColor4B color, float fade) :
		wyRibbon(fade),
		m_distance(DP(20)) {
	m_atlas = wyTextureAtlas::make(NULL);
	m_atlas->retain();
	tex->setAntiAlias(false);
	setTexture(tex);
	m_atlas->setColor(color);
}

wySpotRibbon::~wySpotRibbon() {
	wyObjectRelease(m_atlas);
}

void wySpotRibbon::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	bool newBlend = false;
	if (m_blendFunc.src != DEFAULT_BLEND_SRC || m_blendFunc.dst != DEFAULT_BLEND_DST) {
		newBlend = true;
		glBlendFunc(m_blendFunc.src, m_blendFunc.dst);
	}

	m_atlas->drawAll();

	if (newBlend)
		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void wySpotRibbon::setTexture(wyTexture2D* tex) {
	m_atlas->setTexture(tex);
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
	wyTexture2D* tex = m_atlas->getTexture();
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
			m_atlas->appendQuad(t, v);

			// adjust
			m_remaining -= m_distance;
			m_preLastLocation = m_lastLocation;
			m_lastLocation = p;
		}
	}
}

void wySpotRibbon::update(float delta) {
	if(m_fadeTime != 0)
		m_atlas->reduceAlpha(delta / m_fadeTime);
}

void wySpotRibbon::reset() {
	m_atlas->removeAllQuads();
	m_preLastLocation = m_lastLocation = wypZero;
	m_remaining = 0;
	m_firstPoint = true;
}
