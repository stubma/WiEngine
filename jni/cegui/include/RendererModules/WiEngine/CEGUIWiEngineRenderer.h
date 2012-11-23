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
#ifndef __CEGUIWiEngineRenderer_h__
#define __CEGUIWiEngineRenderer_h__

#include "CEGUI.h"

namespace CEGUI {

class WiEngineGeometryBuffer;

/**
 * WiEngine renderer for CEGUI
 */
class CEGUIEXPORT WiEngineRenderer : public Renderer {
private:
    /// Container used to track geometry buffers
    typedef std::vector<WiEngineGeometryBuffer*> GeometryBufferList;
    GeometryBufferList m_geometryBuffers;

public:
	WiEngineRenderer();
	virtual ~WiEngineRenderer();

	/// @see CEGUI::Renderer::getDefaultRenderingRoot
    virtual RenderingRoot& getDefaultRenderingRoot();

	/// @see CEGUI::Renderer::createGeometryBuffer
    virtual GeometryBuffer& createGeometryBuffer();

	/// @see CEGUI::Renderer::destroyGeometryBuffer
    virtual void destroyGeometryBuffer(const GeometryBuffer& buffer);

	/// @see CEGUI::Renderer::destroyAllGeometryBuffers
    virtual void destroyAllGeometryBuffers();

	/// @see CEGUI::Renderer::createTextureTarget
    virtual TextureTarget* createTextureTarget();

	/// @see CEGUI::Renderer::destroyTextureTarget
    virtual void destroyTextureTarget(TextureTarget* target);

	/// @see CEGUI::Renderer::destroyAllTextureTargets
    virtual void destroyAllTextureTargets();

	/// @see CEGUI::Renderer::createTexture
    virtual Texture& createTexture();

	/// @see CEGUI::Renderer::createTexture
    virtual Texture& createTexture(const String& filename,
                                   const String& resourceGroup);

	/// @see CEGUI::Renderer::createTexture
    virtual Texture& createTexture(const Size& size);

	/// @see CEGUI::Renderer::destroyTexture
    virtual void destroyTexture(Texture& texture);

	/// @see CEGUI::Renderer::destroyAllTextures
    virtual void destroyAllTextures();

	/// @see CEGUI::Renderer::beginRendering
    virtual void beginRendering();

	/// @see CEGUI::Renderer::endRendering
    virtual void endRendering();

	/// @see CEGUI::Renderer::setDisplaySize
    virtual void setDisplaySize(const Size& size);

	/// @see CEGUI::Renderer::getDisplaySize
    virtual const Size& getDisplaySize() const;

	/// @see CEGUI::Renderer::getDisplayDPI
    virtual const Vector2& getDisplayDPI() const;

	/// @see CEGUI::Renderer::getMaxTextureSize
    virtual uint getMaxTextureSize() const;

	/// @see CEGUI::Renderer::getIdentifierString
    virtual const String& getIdentifierString() const;
};

} // end of namespace CEGUI

#endif // __CEGUIWiEngineRenderer_h__
