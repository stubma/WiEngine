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
#ifndef __CEGUIWiEngineGeometryBuffer_h__
#define __CEGUIWiEngineGeometryBuffer_h__

#include "CEGUI.h"
#include "wyTypes.h"
#include "wyGlobal.h"

namespace CEGUI {

class WiEngineRenderer;
class WiEngineTexture;

/**
 * WiEngine based geometry buffer implementation
 */
class CEGUIEXPORT WiEngineGeometryBuffer : public GeometryBuffer {
private:
	/// owner who create me
	WiEngineRenderer& m_owner;
    
    /// last texture that was set as active
    WiEngineTexture* m_activeTexture;
    
    /// texture to material mapping
    typedef std::map<WiEngineTexture*, wyMaterial*> TextureMaterialMap;
    TextureMaterialMap m_tmMap;
    
    /// render pair of this geometry buffer
    typedef struct {
        wyMaterial* mat;
        wyShape* mesh;
    } RenderPair;
    typedef std::vector<RenderPair> RenderPairList;
    RenderPairList m_renderPairs;
    
    /// RenderEffect that will be used by the GeometryBuffer
    RenderEffect* m_effect;
    
    /// translation vector
    Vector3 m_translation;
    
    /// rotation vector
    Vector3 m_rotation;
    
    /// pivot point for rotation
    Vector3 m_pivot;
    
    /// true when d_matrix is valid and up to date
    mutable bool m_matrixValid;
    
    /// rectangular clip region
    wyRect m_clipRect;
    
    /// matrix
    mutable kmMat4 m_matrix;
    
private:
    /// update matrix
    void updateMatrix() const;
    
    /// pick a mesh to append geometry
    wyShape* pickMesh();

public:
	WiEngineGeometryBuffer(WiEngineRenderer& owner);

	virtual ~WiEngineGeometryBuffer();

	/// @see CEGUI::GeometryBuffer::draw
    virtual void draw() const;

	/// @see CEGUI::GeometryBuffer::setTranslation
    virtual void setTranslation(const Vector3& v);

	/// @see CEGUI::GeometryBuffer::setRotation
    virtual void setRotation(const Vector3& r);

	/// @see CEGUI::GeometryBuffer::setPivot
    virtual void setPivot(const Vector3& p);

	/// @see CEGUI::GeometryBuffer::setClippingRegion
    virtual void setClippingRegion(const Rect& region);

	/// @see CEGUI::GeometryBuffer::appendVertex
    virtual void appendVertex(const Vertex& vertex);

	/// @see CEGUI::GeometryBuffer::appendGeometry
    virtual void appendGeometry(const Vertex* const vbuff, uint vertex_count);

	/// @see CEGUI::GeometryBuffer::setActiveTexture
    virtual void setActiveTexture(Texture* texture);

	/// @see CEGUI::GeometryBuffer::reset
    virtual void reset();

	/// @see CEGUI::GeometryBuffer::getActiveTexture
    virtual Texture* getActiveTexture() const;

	/// @see CEGUI::GeometryBuffer::getVertexCount
    virtual uint getVertexCount() const;

	/// @see CEGUI::GeometryBuffer::getBatchCount
    virtual uint getBatchCount() const;

	/// @see CEGUI::GeometryBuffer::setRenderEffect
    virtual void setRenderEffect(RenderEffect* effect);

	/// @see CEGUI::GeometryBuffer::getRenderEffect
    virtual RenderEffect* getRenderEffect();
    
    /// get tranform matrix
    const kmMat4& getMatrix() { return m_matrix; }
};

} // end of namespace CEGUI

#endif // __CEGUIWiEngineGeometryBuffer_h__
