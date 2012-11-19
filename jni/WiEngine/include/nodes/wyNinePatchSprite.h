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
#ifndef __wyNinePatchSprite_h__
#define __wyNinePatchSprite_h__

#include "wyNode.h"
#include "wyTypes.h"
#include "WiEngine-Classes.h"

/**
 * @class wyNinePatchSprite
 * wrapper class to support nine patch pictures like android .9 picture.
 *
 * Notice:
 * rotated atlas picture is not supported.
 */
class WIENGINE_API wyNinePatchSprite : public wyNode {
private:
	/**
	 * the texture rectangle area to be used, if not specified, the whole texture is used
	 */
	wyRect m_texRect;

	/**
	 * the rectangle area to be scaled, in texture coordinates, the upper left corner is regarded as original point
	 */
	wyRect m_patchRect;

protected:
	/**
	 * constructor
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param texRect the texture rectangle area to be used
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 */
	wyNinePatchSprite(wyTexture2D* tex, wyRect texRect, wyRect patchRect);

	/**
	 * do updating
	 */
	void updateAtlas();

public:
	/**
	 * create a new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 */
	static wyNinePatchSprite* make(wyTexture2D* tex, wyRect patchRect);

	/**
	 * create a new instance with autoRelease enabled
	 *
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param texRect the texture rectangle area to be used
	 * @param patchRect the rectangle area to be scaled， in texture coordinates, the upper left corner is regarded as original point
	 */
	static wyNinePatchSprite* make(wyTexture2D* tex, wyRect texRect, wyRect patchRect);

	/**
	 * destructor
	 */
	virtual ~wyNinePatchSprite();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/**
	 * set the texture rectangle and align the content size to rectangle size.
	 *
	 * @param[in] rect \link wyRect wyRect\endlink, in pixels, (rect.x, rect.y) is the left upper corner
	 */
	void setTextureRect(wyRect rect);

	/**
	 * getter
	 */
	wyRect getTextureRect() { return m_texRect; }
};

#endif // __wyNinePatchSprite_h__
