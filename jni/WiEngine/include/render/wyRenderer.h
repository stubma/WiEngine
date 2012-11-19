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
#ifndef __wyRenderer_h__
#define __wyRenderer_h__

#include "wyObject.h"
#include "wyTypes.h"
#include "wyShaderProgram.h"
#include "wyTexture2D.h"
#include "wyMesh.h"
#include "wyRenderState.h"

/**
 * @class wyRenderer
 *
 * \c wyRenderer is a virtual class which abstract necessary operation need to be
 * implemented for rendering. It is the interface which connects WiEngine core to
 * specific render technology.
 */
class WIENGINE_API wyRenderer : public wyObject {
protected:
	wyRenderer();

public:
	virtual ~wyRenderer();

	/**
	 * Set background color used to clear buffer
	 *
	 * @param color background color
	 */
	virtual void setBackgroundColor(wyColor4B color) = 0;

	/**
	 * Get current clear color
	 *
	 * @return \link wyColor4B wyColor4B\endlink
	 */
	virtual wyColor4B getBackgroundColor() = 0;

	/**
	 * Clear buffer
	 *
	 * @param color true means color buffer should be cleared
	 * @param depth true means depth buffer should be cleared
	 * @param stencil true means stencil buffer should be cleared
	 */
	virtual void clearBuffers(bool color, bool depth, bool stencil) = 0;

	/**
	 * Set viewport range
	 *
	 * @param x x position of viewport
	 * @param y y position of viewport
	 * @param w width of viewport
	 * @param h height of viewport
	 */
	virtual void setViewport(float x, float y, float w, float h) = 0;

	/**
	 * Push a clip rect to clip rect stack top and enable it
	 *
	 * @param r clip rectangle
	 */
	virtual void pushClipRect(wyRect& r) = 0;

	/**
	 * Pop current clip rect, if no more clip rect in stack, disable clip rect.
	 * If has other clip rect, enable new top clip rect
	 */
	virtual void popClipRect() = 0;

    /**
     * Set the range of the depth values for objects. All rendered
     * objects will have their depth clamped to this range.
     *
     * @param start The range start
     * @param end The range end
     */
	virtual void setDepthRange(float start, float end) = 0;

	/**
	 * Set active shader program
	 *
	 * @param program \link wyShaderProgram wyShaderProgram\endlink, or NULL
	 * 		if you want to remove current shader
	 */
	virtual void setShaderProgram(wyShaderProgram* program) = 0;

	/**
	 * Set using a texture
	 *
	 * @param unit texture unit
	 * @param tex texture object
	 */
	virtual void setTexture(int unit, wyTexture2D* tex) = 0;

	/// Invoked when surface is created
	virtual void onSurfaceCreated() = 0;

	/// Invoked when surface is destroyed
	virtual void onSurfaceDestroyed() = 0;

	/**
	 * Render a mesh with current material and technique
	 *
	 * @param mesh \link wyMesh wyMesh\endlink
	 * @param lodLevel level of detail of mesh
	 */
	virtual void renderMesh(wyMesh* mesh, int lodLevel) = 0;

	/**
	 * Apply render state
	 *
	 * @param rs \link wyRenderState wyRenderState\endlink
	 */
	virtual void applyRenderState(wyRenderState* rs) = 0;

	/**
	 * Create a frame buffer and returns related texture
	 *
	 * @param desiredWidth pixel width of frame buffer
	 * @param desiredHeight pixel height of frame buffer
	 * @return frame buffer id, or -1 means creation failed
	 */
	virtual int createFrameBuffer(int desiredWidth, int desiredHeight) = 0;

	/**
	 * Get underlying texture of frame buffer
	 *
	 * @param fid frame buffer id
	 * @return texture id
	 */
	virtual int getFrameBufferTexture(int fid) = 0;

	/**
	 * Change render target to a frame buffer
	 *
	 * @param fid the frame buffer id to which render will switch
	 */
	virtual void setFrameBuffer(int fid) = 0;

	/**
	 * Restore to old frame buffer related with a frame buffer
	 *
	 * @param fid the id is NOT the frame buffer we want to restore to, it is the frame buffer
	 * 		whose oldFBO property should be checked
	 */
	virtual void restoreFrameBuffer(int fid) = 0;

	/**
	 * Destroy frame buffer and release related resources
	 *
	 * @param fid id of frame buffer will be released
	 * @param releaseTexture true means the base texture should also be released
	 */
	virtual void releaseFrameBuffer(int fid, bool releaseTexture) = 0;
};

#endif // __wyRenderer_h__
