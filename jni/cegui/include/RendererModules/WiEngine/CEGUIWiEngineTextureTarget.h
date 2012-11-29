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
#ifndef __CEGUIWiEngineTextureTarget_h__
#define __CEGUIWiEngineTextureTarget_h__

#include "CEGUIWiEngineRenderTarget.h"

class wyFrameBuffer;

namespace CEGUI {
    
class WiEngineTexture;

/**
 * Texture target
 */
class CEGUIEXPORT WiEngineTextureTarget : public WiEngineRenderTarget, public TextureTarget {
private:
    /// texture related
    WiEngineTexture* m_texture;
    
    /// frame buffer
    mutable wyFrameBuffer* m_fb;
    
    /// render size
    mutable Size m_renderSize;
    
    /// new render size need to be changed to
    Size m_newSize;
    
private:
    /// check render size dirty? if yes, reinit
    void applyRenderSize() const;
    
public:
	WiEngineTextureTarget(WiEngineRenderer& owner);

	virtual ~WiEngineTextureTarget();

	/// @see CEGUI::RenderTarget::isImageryCache
	virtual bool isImageryCache() const;

	/// @see CEGUI::TextureTarget::clear
    virtual void clear();

	/// @see CEGUI::TextureTarget::getTexture
    virtual Texture& getTexture() const;

	/// @see CEGUI::TextureTarget::declareRenderSize
    virtual void declareRenderSize(const Size& sz);

	/// @see CEGUI::TextureTarget::isRenderingInverted
    virtual bool isRenderingInverted() const;
    
    /// @see CEGUI::RenderTarget::activate
	virtual void activate();
    
	/// @see CEGUI::RenderTarget::deactivate
	virtual void deactivate();
};

} // end of namespace CEGUI

#endif // __CEGUIWiEngineTextureTarget_h__
