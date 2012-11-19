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
#ifndef __wyRenderTexture_h__
#define __wyRenderTexture_h__

#include "wyNode.h"
#include "WiEngine-Classes.h"

/**
 * It is actually a frame buffer wrapper so that rendering can be redirected to it and
 * used later for some special effect.
 */
class WIENGINE_API wyRenderTexture : public wyNode  {
protected:
	/// frame buffer
	wyFrameBuffer* m_fb;

protected:
	/**
	 * Constructor
	 */
	wyRenderTexture();

	/**
	 * Constructor
	 *
	 * @param width width in pixels
	 * @param height height in pixels
	 */
	wyRenderTexture(int width, int height);

	/// init with expected texture size
	void init(int width, int height);

public:
	/**
	 * Create a render texture with specified size
	 *
	 * @param width width in pixel
	 * @param height height in pixel
	 */
	static wyRenderTexture* make(int width, int height);

	/**
	 * Create a render texture which is full screen size
	 */
	static wyRenderTexture* make();

	/**
	 * 析构函数
	 */
	virtual ~wyRenderTexture();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/**
	 * Set render target to this render texture
	 */
	void beginRender();

	/**
	 * Start render something into texture. You can specify background color of
	 * texture
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 */
	void beginRender(float r, float g, float b, float a);

	/**
	 * End render redirecting
	 */
	void endRender();

	/**
	 * Clear texture with a color
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 */
	void clear(float r, float g, float b, float a);

	/**
	 * Get \link wyTexture2D wyTexture2D\endlink object from render texture
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	wyTexture2D* createTexture();

	/**
	 * Create a sprite from render texture
	 *
	 * @return \link wySprite wySprite\endlink
	 */
	wySprite* createSprite();
};

#endif // __wyRenderTexture_h__
