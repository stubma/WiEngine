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
#include "CEGUIWiEngineGeometryBuffer.h"
#include "CEGUIWiEngineRenderer.h"
#include "CEGUIWiEngineTexture.h"
#include "WiEngine.h"

namespace CEGUI {

WiEngineGeometryBuffer::WiEngineGeometryBuffer(WiEngineRenderer& owner) :
		m_owner(owner),
        m_activeTexture(NULL),
        m_effect(NULL),
        m_matrixValid(false),
        m_clipRect(wyrZero),
        m_translation(0, 0, 0),
        m_rotation(0, 0, 0),
        m_pivot(0, 0, 0) {
    // init material
    m_material = wyMaterial::make();
    m_material->retain();
    m_material->getTechnique()->getRenderState()->blendMode = wyRenderState::ALPHA;
            
    // init mesh
    m_mesh = wyShape::make();
    m_mesh->retain();
    m_mesh->setMode(wyMesh::TRIANGLES);
}

WiEngineGeometryBuffer::~WiEngineGeometryBuffer() {
    wyObjectRelease(m_material);
    wyObjectRelease(m_mesh);
}

void WiEngineGeometryBuffer::draw() const {
    // update matrix if dirty
    if(!m_matrixValid) {
        updateMatrix();
        m_matrixValid = true;
    }
    
    // push world matrix
	kmGLMatrixMode(KM_GL_WORLD);
	kmGLPushMatrix();
    
    // apply matrix of this buffer
    kmGLMultMatrix(&m_matrix);
    
    // get renderer
    wyRenderManager* rm = wyDirector::getInstance()->getRenderManager();
    wyRenderer* r = rm->getRenderer();
    
    // set clip rect
    bool clip = m_clipRect.width != 0 && m_clipRect.height != 0;
    if(clip)
        r->pushClipRect(m_clipRect);
    
    // render it
    rm->renderMaterial(m_material, m_mesh);
    
    // pop clip rect
    if(clip)
        r->popClipRect();
    
    // pop world matrix
    kmGLMatrixMode(KM_GL_WORLD);
	kmGLPopMatrix();
}

void WiEngineGeometryBuffer::setTranslation(const Vector3& v) {
    m_translation = v;
    m_matrixValid = false;
}

void WiEngineGeometryBuffer::setRotation(const Vector3& r) {
    m_rotation = r;
    m_matrixValid = false;
}

void WiEngineGeometryBuffer::setPivot(const Vector3& p) {
    m_pivot = Vector3(p.d_x, p.d_y, p.d_z);
    m_matrixValid = false;
}

void WiEngineGeometryBuffer::setClippingRegion(const Rect& region) {
    Rect cr;
    cr.d_top    = ceguimax(0.0f, PixelAligned(region.d_top));
    cr.d_bottom = ceguimax(0.0f, PixelAligned(region.d_bottom));
    cr.d_left   = ceguimax(0.0f, PixelAligned(region.d_left));
    cr.d_right  = ceguimax(0.0f, PixelAligned(region.d_right));
    
    m_clipRect.x = cr.d_left;
    m_clipRect.y = cr.d_top;
    m_clipRect.width = cr.getWidth();
    m_clipRect.height = cr.getHeight();
}

void WiEngineGeometryBuffer::appendVertex(const Vertex& vertex) {
    appendGeometry(&vertex, 1);
}

void WiEngineGeometryBuffer::appendGeometry(const Vertex* const vbuff, uint vertex_count) {
    wyBuffer* buf = m_mesh->getBuffer();
    wyMesh::Vertex v;
    for(uint i = 0; i < vertex_count; i++) {
        kmVec2Fill(&v.tex, vbuff[i].tex_coords.d_x, vbuff[i].tex_coords.d_y);
        kmVec3Fill(&v.pos, vbuff[i].position.d_x, vbuff[i].position.d_y, vbuff[i].position.d_z);
        kmVec4Fill(&v.color,
                   vbuff[i].colour_val.getRed(),
                   vbuff[i].colour_val.getGreen(),
                   vbuff[i].colour_val.getBlue(),
                   vbuff[i].colour_val.getAlpha());
        buf->append(&v, 1);
    }
}

void WiEngineGeometryBuffer::setActiveTexture(Texture* texture) {
    m_activeTexture = (WiEngineTexture*)texture;
    
    // update material
    wyTexture2D* tex = m_activeTexture->getTexture();
    if(tex) {
        wyMaterialParameter* mp = m_material->getParameter(wyUniform::NAME[wyUniform::TEXTURE_2D]);
        if(!mp) {
            wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], tex);
            m_material->addParameter(p);
        } else {
            wyMaterialTextureParameter* mtp = (wyMaterialTextureParameter*)mp;
            mtp->setTexture(tex);
        }
    }
}

void WiEngineGeometryBuffer::reset() {
    m_mesh->getBuffer()->clear();
    m_activeTexture = NULL;
}

Texture* WiEngineGeometryBuffer::getActiveTexture() const {
    return m_activeTexture;
}

uint WiEngineGeometryBuffer::getVertexCount() const {
    return m_mesh->getElementCount();
}

uint WiEngineGeometryBuffer::getBatchCount() const {
    // TODO not implemented yet, just return 1
    return 1;
}

void WiEngineGeometryBuffer::setRenderEffect(RenderEffect* effect) {
    m_effect = effect;
}

RenderEffect* WiEngineGeometryBuffer::getRenderEffect() {
    return m_effect;
}
    
void WiEngineGeometryBuffer::updateMatrix() const {
    // set matrix to identity
    kmMat4Identity(&m_matrix);
    
    // temp
    kmMat4 m;
    
    // transform
    kmMat4Translation(&m,
                      m_translation.d_x + m_pivot.d_x,
                      m_translation.d_y + m_pivot.d_y,
                      m_translation.d_z + m_pivot.d_z);
    kmMat4Multiply(&m_matrix, &m_matrix, &m);
    kmMat4RotationZ(&m, wyMath::d2r(m_rotation.d_z));
    kmMat4Multiply(&m_matrix, &m_matrix, &m);
    kmMat4RotationY(&m, wyMath::d2r(m_rotation.d_y));
    kmMat4Multiply(&m_matrix, &m_matrix, &m);
    kmMat4RotationX(&m, wyMath::d2r(m_rotation.d_x));
    kmMat4Multiply(&m_matrix, &m_matrix, &m);
    kmMat4Translation(&m, -m_pivot.d_x, -m_pivot.d_y, -m_pivot.d_z);
    kmMat4Multiply(&m_matrix, &m_matrix, &m);
}

} // end of namespace CEGUI
