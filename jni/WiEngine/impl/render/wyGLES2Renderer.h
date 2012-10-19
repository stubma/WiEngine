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
#ifndef __wyGLES2Renderer_h__
#define __wyGLES2Renderer_h__

#include "wyRenderer.h"
#include "wyGLState.h"
#include "wyBuffer.h"
#include "wyMesh.h"

/**
 * @class wyGLES2Renderer
 *
 * \if English
 * Render which use OpenGL ES 2 technology
 * \else
 * OpenGL ES 2.0的渲染器
 * \endif
 */
class wyGLES2Renderer : public wyRenderer {
private:
	/// opengl state cache, to reduce state switch
	wyGLState* m_state;

	/// true indicating use VBO rendering technology
	bool m_useVBO;

	/// act as a stack to maintain the scissor information, \link wyRect wyRect\endlink
	wyRect* m_clipStack;

	/// element count in the m_clipStack
	int m_clipStackCount;

	/// the capacity of m_clipStack
	int m_clipStackCapacity;

protected:
	wyGLES2Renderer();

	/**
	 * Render mesh using VBO
	 *
	 * @param mesh mesh object
	 * @param lodLevel level of detail
	 */
	void renderMeshVBO(wyMesh* mesh, int lodLevel);

	/**
	 * Render mesh in normal way
	 *
	 * @param mesh mesh object
	 * @param lodLevel level of detail
	 */
	void renderMeshDefault(wyMesh* mesh, int lodLevel);

	/**
	 * Apply mesh attribute value
	 *
	 * @param mesh mesh object
	 */
	void bindMeshAttributes(wyMesh* mesh);

	/**
	 * convert buffer format to GL enum
	 *
	 * @param f format constant defined by wyBuffer
	 * @return corresponding GL value
	 */
	GLenum bufferFormatToGL(wyBuffer::Format f);

	/**
	 * Convert mesh render mode to GL enum
	 *
	 * @param m model of mesh renderring
	 * @return corresponding GL value
	 */
	GLenum meshModeToGL(wyMesh::Mode m);

public:
	static wyGLES2Renderer* make();

	virtual ~wyGLES2Renderer();

	/// @see wyRenderer::setBackgroundColor
	virtual void setBackgroundColor(wyColor4B color);

	/// @see wyRenderer::clearBuffers
	virtual void clearBuffers(bool color, bool depth, bool stencil);

	/// @see wyRenderer::setViewport
	virtual void setViewport(float x, float y, float w, float h);

	/// @see wyRenderer::pushClipRect
	virtual void pushClipRect(wyRect& r);

	/// @see wyRenderer::popClipRect
	virtual void popClipRect();

	/// @see wyRenderer::setDepthRange
	virtual void setDepthRange(float start, float end);

	/// @see wyRenderer::setShaderProgram
	virtual void setShaderProgram(wyShaderProgram* program);

	/// @see wyRenderer::setTexture
	virtual void setTexture(int unit, wyTexture2D* tex);

	/// @see wyRenderer::onSurfaceCreated
	virtual void onSurfaceCreated();

	/// @see wyRenderer::onSurfaceDestroyed
	virtual void onSurfaceDestroyed();

	/// @see wyRenderer::renderMesh
	virtual void renderMesh(wyMesh* mesh, int lodLevel);

	/// @see wyRenderer::applyRenderState
	virtual void applyRenderState(wyRenderState* rs);

	/// @see wyRenderer::createFrameBuffer
	virtual int createFrameBuffer(int desiredWidth, int desiredHeight);

	/// @see wyRenderer::setFrameBuffer
	virtual void setFrameBuffer(int fid);

	/// @see wyRenderer::restoreFrameBuffer
	virtual void restoreFrameBuffer(int fid);

	/// @see wyRenderer::releaseFrameBuffer
	virtual void releaseFrameBuffer(int fid);
};

#endif // __wyGLES2Renderer_h__
