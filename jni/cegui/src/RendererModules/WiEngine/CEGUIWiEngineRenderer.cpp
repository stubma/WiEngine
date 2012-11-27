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
#include "CEGUIWiEngineRenderer.h"
#include "CEGUIWiEngineGeometryBuffer.h"
#include "CEGUIWiEngineTexture.h"
#include "CEGUIWiEngineViewportTarget.h"
#include "CEGUIWiEngineTextureTarget.h"
#include <algorithm>
#include "WiEngine.h"

namespace CEGUI {
    
// renderer id initialization
String WiEngineRenderer::s_rendererID("CEGUI::WiEngineRenderer - OpenGL ES 2.0 based WiEngine renderer");

WiEngineRenderer::WiEngineRenderer() :
        m_displayDPI(160, 160),
        m_defaultRoot(NULL),
        m_defaultTarget(NULL) {
    m_defaultTarget = new WiEngineViewportTarget(*this);
    m_defaultRoot = new RenderingRoot(*m_defaultTarget);
}

WiEngineRenderer::~WiEngineRenderer() {
    destroyAllGeometryBuffers();
    destroyAllTextureTargets();
    destroyAllTextures();
    
    delete m_defaultRoot;
    delete m_defaultTarget;
}

RenderingRoot& WiEngineRenderer::getDefaultRenderingRoot() {
    return *m_defaultRoot;
}

GeometryBuffer& WiEngineRenderer::createGeometryBuffer() {
    WiEngineGeometryBuffer* b = new WiEngineGeometryBuffer(*this);
    m_geometryBuffers.push_back(b);
    return *b;
}

void WiEngineRenderer::destroyGeometryBuffer(const GeometryBuffer& buffer) {
    GeometryBufferList::iterator i = std::find(m_geometryBuffers.begin(), m_geometryBuffers.end(), &buffer);
    if (m_geometryBuffers.end() != i) {
        m_geometryBuffers.erase(i);
        delete &buffer;
    }
}

void WiEngineRenderer::destroyAllGeometryBuffers() {
    while (!m_geometryBuffers.empty())
        destroyGeometryBuffer(**m_geometryBuffers.begin());
}

TextureTarget* WiEngineRenderer::createTextureTarget() {
    TextureTarget* t = new WiEngineTextureTarget(*this);
    m_textureTargets.push_back(t);
    return t;
}

void WiEngineRenderer::destroyTextureTarget(TextureTarget* target) {
    TextureTargetList::iterator i = std::find(m_textureTargets.begin(),
                                              m_textureTargets.end(),
                                              target);
    
    if (m_textureTargets.end() != i) {
        m_textureTargets.erase(i);
        delete target;
    }
}

void WiEngineRenderer::destroyAllTextureTargets() {
    while (!m_textureTargets.empty())
        destroyTextureTarget(*m_textureTargets.begin());
}

Texture& WiEngineRenderer::createTexture() {
    WiEngineTexture* tex = new WiEngineTexture(*this);
    m_textures.push_back(tex);
    return *tex;
}

Texture& WiEngineRenderer::createTexture(const String& filename,
							   const String& resourceGroup) {
    WiEngineTexture* tex = new WiEngineTexture(*this);
    tex->loadFromFile(filename, resourceGroup);
    m_textures.push_back(tex);
    return *tex;
}

Texture& WiEngineRenderer::createTexture(const Size& size) {
    WiEngineTexture* tex = new WiEngineTexture(*this);
    tex->loadNull(size);
    m_textures.push_back(tex);
    return *tex;
}

void WiEngineRenderer::destroyTexture(Texture& texture) {
    TextureList::iterator i = std::find(m_textures.begin(),
                                        m_textures.end(),
                                        &texture);
    
    if (m_textures.end() != i) {
        m_textures.erase(i);
        delete &texture;
    }
}

void WiEngineRenderer::destroyAllTextures() {
    while (!m_textures.empty())
        destroyTexture(**m_textures.begin());
}

void WiEngineRenderer::beginRendering() {
}

void WiEngineRenderer::endRendering() {
}

void WiEngineRenderer::setDisplaySize(const Size& size) {
    if (size != m_displaySize) {
        m_displaySize = size;
        
        // update the default target's area
        Rect area(m_defaultTarget->getArea());
        area.setSize(size);
        m_defaultTarget->setArea(area);
    }
}

const Size& WiEngineRenderer::getDisplaySize() const {
    return m_displaySize;
}

const Vector2& WiEngineRenderer::getDisplayDPI() const {
    return m_displayDPI;
}

uint WiEngineRenderer::getMaxTextureSize() const {
    return wyDevice::maxTextureSize;
}

const String& WiEngineRenderer::getIdentifierString() const {
    return s_rendererID;
}

} // end of namespace CEGUI
