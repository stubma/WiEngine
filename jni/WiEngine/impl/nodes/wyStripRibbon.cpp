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
#include "wyStripRibbon.h"
#include "wyTexture2D.h"
#include "wyQuadList.h"
#include "wyMaterial.h"

wyStripRibbon* wyStripRibbon::make(wyTexture2D* tex, wyColor4B color, float fade) {
	wyStripRibbon* r = WYNEW wyStripRibbon(tex, color, fade);
	return (wyStripRibbon*)r->autoRelease();
}

wyStripRibbon::wyStripRibbon(wyTexture2D* tex, wyColor4B color, float fade) : wyRibbon(fade) {
	// set texture
	tex->setAntiAlias(false);
	setTexture(tex);

	// create empty material and mesh
	setMaterial(wyMaterial::make());
	setMesh(wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set color
	setColor(color);
}

wyStripRibbon::~wyStripRibbon() {
}

void wyStripRibbon::updateMaterial() {
	// get texture parameter, if none, create
	wyMaterialParameter* mp = getMaterial()->getParameter(wyUniform::NAME[wyUniform::TEXTURE_2D]);
	if(!mp) {
		wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], m_tex);
		m_material->addParameter(p);
	} else {
		wyMaterialTextureParameter* mtp = (wyMaterialTextureParameter*)mp;
		mtp->setTexture(m_tex);
	}
}

void wyStripRibbon::updateMeshColor() {
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->updateColor(m_color);
}

void wyStripRibbon::update(float delta) {
	if(m_fadeTime != 0) {
		wyQuadList* atlas = (wyQuadList*)getMesh();
		atlas->reduceAlpha(delta / m_fadeTime);
	}
}

void wyStripRibbon::addPoint(wyPoint location) {
	// if this is the first point added, cache it and return
	if (m_firstPoint) {
		m_lastLocation = location;
		m_preLastLocation = location;
		m_firstPoint = false;
		m_remaining = 0;
		return;
	}

	// get texture info
	float tW = m_tex->getWidth();
	float tH = m_tex->getHeight();
	float texW = tW / m_tex->getPixelWidth();
	float texH = tH / m_tex->getPixelHeight();

	// get distance between last location and current location
	float len = wypDistance(m_lastLocation, location);

	// delta x/y
	float dx = location.x - m_lastLocation.x;
	float dy = location.y - m_lastLocation.y;

	// get texture end
	float tLen = len / m_tex->getPixelHeight();
	float tEnd = m_remaining + tLen;

	// start cut
	float tStart = m_remaining;
	wyPoint preLoc = m_preLastLocation;
	wyPoint startLoc = m_lastLocation;
	wyPoint cutLoc = startLoc;
	while(tEnd >= texH) {
		float cut = (texH - tStart) / tLen;
		cutLoc.x += dx * cut;
		cutLoc.y += dy * cut;
		addQuad(preLoc, startLoc, cutLoc, tStart, texH, texW);

		// for next loop
		tStart = 0;
		tEnd -= texH;
		preLoc = startLoc;
		startLoc = cutLoc;
	}

	// last segment
	addQuad(preLoc, startLoc, location, tStart, tEnd, texW);

	// save current state
	m_remaining = tEnd;
	m_preLastLocation = m_lastLocation;
	m_lastLocation = location;
}

void wyStripRibbon::reset() {
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->removeAllQuads();
	m_preLastLocation = m_lastLocation = wypZero;
	m_remaining = 0;
	m_firstPoint = true;
}

void wyStripRibbon::addQuad(wyPoint pre, wyPoint from, wyPoint to, float tStart, float tEnd, float texW) {
	float ribbonWidth = m_tex->getWidth() * 0.5f;
	wyPoint sub1 = (pre.x == from.x && pre.y == from.y) ? wypSub(from, to) : wypSub(pre, from);
	wyPoint sub2 = wypSub(from, to);
	float r1 = wypToRadian(sub1) + M_PI / 2;
	float r2 = wypToRadian(sub2) + M_PI / 2;
	wyPoint p1 = { -ribbonWidth, 0 };
	wyPoint p1r1 = wypRotateByAngle(p1, wypZero, r1);
	wyPoint p1r2 = wypRotateByAngle(p1, wypZero, r2);
	wyPoint tl = wypAdd(p1r1, from);
	wyPoint bl = wypAdd(p1r2, to);
	wyPoint p2 = { ribbonWidth, 0 };
	wyPoint p2r1 = wypRotateByAngle(p2, wypZero, r1);
	wyPoint p2r2 = wypRotateByAngle(p2, wypZero, r2);
	wyPoint tr = wypAdd(p2r1, from);
	wyPoint br = wypAdd(p2r2, to);

	wyQuad3D v;
	wyQuad2D t;
	wyq3Set(v, bl.x, bl.y, 0, br.x, br.y, 0, tl.x, tl.y, 0, tr.x, tr.y, 0);
	wyq2Set(t, 0, tEnd, texW, tEnd, 0, tStart, texW, tStart);
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->appendQuad(t, v);
}
