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
#include "wyProgressTimer.h"
#include <stdlib.h>
#include <math.h>
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"

wyProgressTimer::wyProgressTimer(wySprite* sprite) :
		m_sprite(NULL) {
	setSprite(sprite);
}

wyProgressTimer::~wyProgressTimer() {
	wyObjectRelease(m_sprite);
}

wyProgressTimer* wyProgressTimer::make(wyTexture2D* tex) {
	wyProgressTimer* t = WYNEW wyProgressTimer(wySprite::make(tex));
	return (wyProgressTimer*)t->autoRelease();
}

wyProgressTimer* wyProgressTimer::make(wySprite* sprite) {
	wyProgressTimer* t = WYNEW wyProgressTimer(sprite);
	return (wyProgressTimer*)t->autoRelease();
}

void wyProgressTimer::updateMesh() {
	// get texture and texture rect
	wyTexture2D* tex = m_sprite->getTexture();

	// if texture is get from opengl, it is natural born y-flipped
	bool flipY = tex->getSource() == SOURCE_OPENGL;
	if(m_sprite->isFlipY())
		flipY = !flipY;

	// update mesh
	wyMesh* mesh = getMesh();
	mesh->setTexPOTWidth(tex->getPixelWidth());
	mesh->setTexPOTHeight(tex->getPixelHeight());
	mesh->setTexSourceWidth(m_width);
	mesh->setTexSourceHeight(m_height);
	mesh->setTextureRect(m_sprite->getTextureRect());
	mesh->setFlipX(m_sprite->isFlipX());
	mesh->setFlipY(flipY);
    mesh->setRenderRect(wyr(0, 0, m_width, m_height));
    mesh->setEnableRenderRect(true);
	mesh->setRotate90CCW(m_sprite->isRotatedZwoptex());
	mesh->update();
}

void wyProgressTimer::updateMeshColor() {
	((wyProgress*)getMesh())->updateColor(m_sprite->getColor4B(), m_sprite->getTexture()->hasPremultipliedAlpha());
}

void wyProgressTimer::setPercentage(float percentage) {
	if(percentage != getPercentage()) {
		((wyProgress*)getMesh())->setPercentage(percentage);
		setNeedUpdateMesh(true);
	}
}

void wyProgressTimer::setSprite(wySprite* sprite) {
	if(m_sprite != sprite) {
		// set sprite
		wyObjectRetain(sprite);
		wyObjectRelease(m_sprite);
		m_sprite = sprite;

		// reset content size
		setContentSize(m_sprite->getWidth(), m_sprite->getHeight());

		// add render pair or replace material
		if(getRenderPairCount() > 0) {
			replaceMaterial(m_sprite->getMaterial());
		} else {
			addRenderPair(m_sprite->getMaterial(), wyProgress::make());
		}

		// need update
		setNeedUpdateMesh(true);
		setNeedUpdateMeshColor(true);
	}
}

void wyProgressTimer::setStyle(wyProgress::Style style) {
	if(style != getStyle()) {
		((wyProgress*)getMesh())->setStyle(style);
		setNeedUpdateMesh(true);
	}
}

void wyProgressTimer::increase(float delta) {
	float p = getPercentage() + delta;
	p = MIN(100, p);
	p = MAX(0, p);
	setPercentage(p);
}
