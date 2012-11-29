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
#include "CEGUIWiEngineTextureTarget.h"
#include "CEGUIWiEngineTexture.h"
#include "WiEngine.h"

namespace CEGUI {

WiEngineTextureTarget::WiEngineTextureTarget(WiEngineRenderer& owner) :
        WiEngineRenderTarget(owner),
        m_renderSize(0, 0),
        m_texture(NULL),
        m_fb(NULL) {
}

WiEngineTextureTarget::~WiEngineTextureTarget() {
    if(m_texture) {
        m_owner.destroyTexture(*m_texture);
        m_texture = NULL;
    }
    if(m_fb) {
        m_fb->release();
        m_fb = NULL;
    }
}

bool WiEngineTextureTarget::isImageryCache() const {
	return true;
}

void WiEngineTextureTarget::clear() {
    if(m_fb)
        m_fb->clearBuffer(wyc4bTransparent);
}

Texture& WiEngineTextureTarget::getTexture() const {
    return *m_texture;
}

void WiEngineTextureTarget::declareRenderSize(const Size& sz) {
    // do nothing if size doesn't change
    if(m_renderSize.d_width == sz.d_width && m_renderSize.d_height == sz.d_height)
        return;
    
    // save new size
    m_renderSize = sz;
    
    // destroy old
    if(m_texture) {
        m_owner.destroyTexture(*m_texture);
        m_texture = NULL;
    }
    if(m_fb) {
        m_fb->release();
        m_fb = NULL;
    }
    
    // re-create, must create frame buffer before create texture
    // because the texture is lazy created in framebuffer
    m_fb = wyFrameBuffer::make(sz.d_width, sz.d_height);
    m_fb->retain();
    m_fb->create();
    m_texture = (WiEngineTexture*)&m_owner.createTexture(sz);
    m_texture->setTexture(m_fb->createTexture());
}

bool WiEngineTextureTarget::isRenderingInverted() const {
	return true;
}

void WiEngineTextureTarget::activate() {
    if(m_fb) {
        m_fb->beforeRender();
    }
}

void WiEngineTextureTarget::deactivate() {
    if(m_fb) {
        m_fb->afterRender();
    }
}
    
} // end of namespace CEGUI
