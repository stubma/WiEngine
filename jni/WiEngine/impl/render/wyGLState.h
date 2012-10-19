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
#ifndef __wyGLState_h__
#define __wyGLState_h__

#include "wyShaderProgram.h"
#include "wyBuffer.h"
#include "wyRenderState.h"
#include "wyTypes.h"

/**
 * @class wyGLState
 *
 * Remember OpenGL state to avoid state switching as more as possible
 */
class wyGLState : public wyObject {
public:
	/// hold info of a GL frame buffer object
	struct FrameBuffer {
		/// base texture
		GLuint texture;

		/// fbo id
		GLuint fbo;

		/// old fbo id when this fbo is used
		GLuint oldFBO;
	};

public:
	/// Current shader program
	wyShaderProgram* activeProgram;

	/// face culling mode
	wyRenderState::CullMode cullMode;

	/// blending mode
	wyRenderState::BlendMode blendMode;

	/// Is color buffer writing enabled or not
	bool colorWriteEnabled;

	/// Is depth buffer writing enabled or not
	bool depthWriteEnabled;

	/// Is depth test enabled
	bool depthTestEnabled;

	/// is dither enabled
	bool ditherEnabled;

	/// Clip enabled or not
	bool clipEnabled;

	/// clip rect
	wyRect clipRect;

	/// Viewport x position
	float viewportX;

	/// Viewport y position
	float viewportY;

	/// viewport width
	float viewportWidth;

	/// viewport height
	float viewportHeight;

	/// Current active texture unit
	int activeTextureUnit;

	/// Bound textures for every texture unit
	GLuint* boundTextures;

	/// max texture unit allowed
	GLint maxVertexTextureUnits;

	/// Point size
	int pointSize;

	/// Line width
	int lineWidth;

	/// bound buffers of attributes
	map<int, wyBuffer*>* attribBoundBuffers;

	/// is vertex array enabled in an attribute?
	map<int, bool>* attribEnableMap;

	/// frame buffer list
	map<int, FrameBuffer>* frameBuffers;

protected:
	wyGLState();

public:
	static wyGLState* make();
	virtual ~wyGLState();

	/**
	 * is attribute vertex array enabled
	 *
	 * @param loc attribute index
	 * @return true means attribute vertex array is enabled
	 */
	bool isAttributeVertexArrayEnabled(int loc);

	/**
	 * Get vertex pointer of an attribute
	 *
	 * @param loc attribute index
	 * @return buffer bound to this attribute, or NULL if none
	 */
	wyBuffer* getAttributeVertexPointer(int loc);

	/**
	 * Clear cached state, will reset all state to default value
	 */
	void reset();

	/**
	 * Find frame buffer by id
	 *
	 * @param id frame buffer id
	 * @return frame buffer structure pointer
	 */
	FrameBuffer* getFrameBuffer(int fid);

	/**
	 * Remove a frame buffer entry
	 *
	 * @param fid frame buffer id
	 */
	void removeFrameBuffer(int fid);
};

#endif // __wyGLState_h__
