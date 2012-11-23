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
#include "CEGUIWiEngineTexture.h"
#include "WiEngine.h"

namespace CEGUI {

WiEngineTexture::WiEngineTexture(WiEngineRenderer& owner) :
		m_owner(owner),
		m_tex(NULL) {
}

WiEngineTexture::~WiEngineTexture() {
	wyObjectRelease(m_tex);
}

const Size& WiEngineTexture::getSize() const {
	return m_potSize;
}

const Size& WiEngineTexture::getOriginalDataSize() const {
	return m_originalSize;
}

const Vector2& WiEngineTexture::getTexelScaling() const {
	return m_texelScaling;
}

void WiEngineTexture::loadFromFile(const String& filename,
                          const String& resourceGroup) {
	// get relative path in assets
	DefaultResourceProvider* rp = (DefaultResourceProvider*)System::getSingleton().getResourceProvider();
	const String& groupDir = rp->getResourceGroupDirectory(resourceGroup);
	String path = groupDir + filename;

	// create texture
	setTexture(wyTexture2D::make(path.c_str()));

	// update size values
	updateCachedValues();
}

void WiEngineTexture::loadFromMemory(const void* buffer,
                            const Size& buffer_size,
                            PixelFormat pixel_format) {
	// create texture
	setTexture(wyTexture2D::makeRaw8888((const char*)buffer, buffer_size.d_width, buffer_size.d_height));

	// update size values
	updateCachedValues();
}

void WiEngineTexture::saveToMemory(void* buffer) {
	// TODO need implement
}

void WiEngineTexture::updateCachedValues() {
	m_originalSize.d_width = m_tex->getWidth();
	m_originalSize.d_height = m_tex->getHeight();

	m_potSize.d_width = m_tex->getPixelWidth();
	m_potSize.d_height = m_tex->getPixelHeight();

	m_texelScaling.d_x = 1.0f / m_potSize.d_width;
	m_texelScaling.d_y = 1.0f / m_potSize.d_height;
}

void WiEngineTexture::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}

} // end of namespace CEGUI
