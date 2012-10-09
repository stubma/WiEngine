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
 * \if English
 * Remember OpenGL state to avoid state switching as more as possible
 * \else
 * 记录OpenGL的状态信息以尽可能的减少状态切换
 * \endif
 */
class wyGLState : public wyObject {
public:
	/**
	 * \if English
	 * Current shader program
	 * \else
	 * 当前正在使用的shader程序id
	 * \endif
	 */
	wyShaderProgram* activeProgram;

	/**
	 * \if English
	 * face culling mode
	 * \else
	 * 面裁剪方式
	 * \endif
	 */
	wyRenderState::CullMode cullMode;

	/**
	 * \if English
	 * blending mode
	 * \else
	 * 混合模式
	 * \endif
	 */
	wyRenderState::BlendMode blendMode;

	/**
	 * \if English
	 * Is color buffer writing enabled or not
	 * \else
	 * 颜色缓冲区的写是否打开
	 * \endif
	 */
	bool colorWriteEnabled;

	/**
	 * \if English
	 * Is depth buffer writing enabled or not
	 * \else
	 * 深度缓冲区的写是否打开
	 * \endif
	 */
	bool depthWriteEnabled;

	/**
	 * \if English
	 * Is depth test enabled
	 * \else
	 * 深度测试是否打开
	 * \endif
	 */
	bool depthTestEnabled;

	/**
	 * \if English
	 * is dither enabled
	 * \else
	 * 颜色抖动是否打开
	 * \endif
	 */
	bool ditherEnabled;

	/**
	 * \if English
	 * Clip enabled or not
	 * \else
	 * 剪刀测试是否打开
	 * \endif
	 */
	bool clipEnabled;

	/**
	 * \if English
	 * clip rect
	 * \else
	 * 裁剪区域
	 * \endif
	 */
	wyRect clipRect;

	/**
	 * \if English
	 * Viewport x position
	 * \else
	 * 视口x位置
	 * \endif
	 */
	float viewportX;

	/**
	 * \if English
	 * Viewport y position
	 * \else
	 * 视口y位置
	 * \endif
	 */
	float viewportY;

	/**
	 * \if English
	 * viewport width
	 * \else
	 * 视口宽度
	 * \endif
	 */
	float viewportWidth;

	/**
	 * \if English
	 * viewport height
	 * \else
	 * 视口高度
	 * \endif
	 */
	float viewportHeight;

	/**
	 * \if English
	 * Current active texture unit
	 * \else
	 * 当前激活的贴图单元
	 * \endif
	 */
	int activeTextureUnit;

	/**
	 * \if English
	 * Bound textures for every texture unit
	 * \else
	 * 每个贴图单元上绑定的贴图
	 * \endif
	 */
	GLuint* boundTextures;

	/**
	 * \if English
	 * max texture unit allowed
	 * \else
	 * 最大允许的贴图单元数
	 * \endif
	 */
	GLint maxVertexTextureUnits;

	/**
	 * \if English
	 * Point size
	 * \else
	 * 点大小
	 * \endif
	 */
	int pointSize;

	/**
	 * \if English
	 * Line width
	 * \else
	 * 线宽
	 * \endif
	 */
	int lineWidth;

	/**
	 * \if English
	 * bound buffers of attributes
	 * \else
	 * 属性参数上绑定的缓冲区
	 * \endif
	 */
	map<int, wyBuffer*>* attribBoundBuffers;

	/**
	 * \if English
	 * is vertex array enabled in an attribute?
	 * \else
	 * 记录属性参数上的顶点数据是否打开的哈希表
	 * \endif
	 */
	map<int, bool>* attribEnableMap;

protected:
	wyGLState();

public:
	static wyGLState* make();
	virtual ~wyGLState();

	/**
	 * \if English
	 * is attribute vertex array enabled
	 *
	 * @param loc attribute index
	 * @return true means attribute vertex array is enabled
	 * \else
	 * 是否属性参数的顶点数组已经被打开
	 *
	 * @param loc 属性参数在shader中的位置
	 * @return true表示顶点数组已经打开
	 * \endif
	 */
	bool isAttributeVertexArrayEnabled(int loc);

	/**
	 * \if English
	 * Get vertex pointer of an attribute
	 *
	 * @param loc attribute index
	 * @return buffer bound to this attribute, or NULL if none
	 * \else
	 * 得到属性参数上绑定的数组指针
	 *
	 * @param loc 属性参数在shader中的位置
	 * @return 绑定在属性上的缓冲区
	 * \endif
	 */
	wyBuffer* getAttributeVertexPointer(int loc);

	/**
	 * \if English
	 * Clear cached state
	 * \else
	 * 重置缓存的状态
	 * \endif
	 */
	void reset();
};

#endif // __wyGLState_h__
