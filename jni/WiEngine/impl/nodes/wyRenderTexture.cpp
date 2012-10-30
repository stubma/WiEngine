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
#include "wyRenderTexture.h"
#include <stdlib.h>
#include "wyUtils.h"
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyRectangle.h"
#include "wyDirector.h"
#include "wyFrameBuffer.h"
#include "wySprite.h"

wyRenderTexture::~wyRenderTexture() {
	wyObjectRelease(m_fb);
}

wyRenderTexture::wyRenderTexture(int width, int height) :
		m_fb(NULL) {
	setContentSize(width, height);
	init(width, height);
}

wyRenderTexture::wyRenderTexture() :
		m_fb(NULL) {
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	init(wyDevice::realWidth, wyDevice::realHeight);
}

void wyRenderTexture::init(int width, int height) {
	// get texture min size
	int w = wyMath::getNextPOT(width);
	int h = wyMath::getNextPOT(height);

	// create frame buffer
	m_fb = wyFrameBuffer::make(width, height);
	m_fb->retain();

	// add render pair
	wyRectangle* mesh = wyRectangle::make();
	mesh->updateMesh(w,
			h,
			0,
			0,
			m_width,
			m_height,
			m_width,
			m_height,
			false,
			true,
			wyr(0, 0, m_width, m_height),
			false);
	addRenderPair(m_fb->getMaterial(), mesh);

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);
}

wyRenderTexture* wyRenderTexture::make(int width, int height) {
	wyRenderTexture* n = WYNEW wyRenderTexture(width, height);
	return (wyRenderTexture*)n->autoRelease();
}

wyRenderTexture* wyRenderTexture::make() {
	wyRenderTexture* n = WYNEW wyRenderTexture();
	return (wyRenderTexture*)n->autoRelease();
}

void wyRenderTexture::clear(float r, float g, float b, float a) {
	beginRender(r, g, b, a);
	endRender();
}

void wyRenderTexture::beginRender(float r, float g, float b, float a) {
	// begin rendering
	beginRender();

	// clear buffer with given color
	m_fb->clearBuffer(wyc4b(r * 255, g * 255, b * 255, a * 255));
}

void wyRenderTexture::beginRender() {
	m_fb->beforeRender();
}

void wyRenderTexture::endRender() {
	m_fb->afterRender();
}

wyTexture2D* wyRenderTexture::createTexture() {
	return m_fb->createTexture();
}

wySprite* wyRenderTexture::createSprite() {
	return wySprite::make(createTexture(), wyr(0, 0, m_fb->getWidth(), m_fb->getHeight()));
}

void wyRenderTexture::updateMeshColor() {
	((wyRectangle*)getMesh())->updateColor(m_color);
}
