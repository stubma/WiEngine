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
#ifndef __CEGUIWiEngineTexture_h__
#define __CEGUIWiEngineTexture_h__

#include "CEGUI.h"
#include "CEGUIWiEngineRenderer.h"
#include "WiEngine-Classes.h"

namespace CEGUI {

/**
 * Texture implementation for the WiEngineRenderer
 */
class CEGUIEXPORT WiEngineTexture : public Texture {
private:
	/// renderer who create me
	WiEngineRenderer& m_owner;

	/// the texture object in WiEngine side
	wyTexture2D* m_tex;

	/// texture POT size
	Size m_potSize;

	/// texture original size
	Size m_originalSize;

	/// texel scaling
	Vector2 m_texelScaling;

private:
	/// update some cached size and scaling value
	void updateCachedValues();

	/// set WiEngine texture
	void setTexture(wyTexture2D* tex);

public:
	WiEngineTexture(WiEngineRenderer& owner);

	virtual ~WiEngineTexture();

	/// @see CEGUI::Texture::getSize
    virtual const Size& getSize() const;

	/// @see CEGUI::Texture::getOriginalDataSize
    virtual const Size& getOriginalDataSize() const;

	/// @see CEGUI::Texture::getTexelScaling
    virtual const Vector2& getTexelScaling() const;

	/// @see CEGUI::Texture::loadFromFile
    virtual void loadFromFile(const String& filename,
                              const String& resourceGroup);

	/// @see CEGUI::Texture::loadFromMemory
    virtual void loadFromMemory(const void* buffer,
                                const Size& buffer_size,
                                PixelFormat pixel_format);

	/// @see CEGUI::Texture::saveToMemory
    virtual void saveToMemory(void* buffer);
};

} // end of namespace CEGUI

#endif // __CEGUIWiEngineTexture_h__
