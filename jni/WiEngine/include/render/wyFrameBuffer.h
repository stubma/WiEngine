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
#ifndef __wyFrameBuffer_h__
#define __wyFrameBuffer_h__

#include "wyGlobal.h"
#include "wyObject.h"
#include "wyTexture2D.h"

/**
 * @class wyFrameBuffer
 *
 * A frame buffer can be used as a render target
 */
class WIENGINE_API wyFrameBuffer : public wyObject {
	friend class wyBaseGrid;

private:
	/// frame buffer id, -1 means invalid
	int m_id;

	/// camera of this frame buffer
	wyCamera* m_camera;

	/// width of texture, not POT width
	float m_texWidth;

	/// height of texture, not POT height
	float m_texHeight;

	/// width of content
	float m_width;

	/// height of content
	float m_height;

protected:
	/// constructor
	wyFrameBuffer();

	/**
	 * Constructor
	 *
	 * @param width width in pixels
	 * @param height height in pixels
	 */
	wyFrameBuffer(int width, int height);

	/// init camera
	void initCamera();

public:
	/**
	 * \if English
	 * Create a texture which is full screen size
	 * \else
	 * 创建一个全屏大小的抓取贴图
	 * \endif
	 */
	static wyFrameBuffer* make();

	/**
	 * \if English
	 * Create a texture with specified size
	 *
	 * @param width width in pixel
	 * @param height height in pixel
	 * \else
	 * 创建一个指定大小的抓取贴图
	 *
	 * @param width 宽度
	 * @param height 高度
	 * \endif
	 */
	static wyFrameBuffer* make(int width, int height);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyFrameBuffer();

	/// create frame buffer
	void create();

	/**
	 * \if English
	 * this function is called before openGL rendering is executed
	 * \else
	 * 渲染之前调用
	 * \endif
	 */
	void beforeRender();

	/**
	 * \if English
	 * this fuction is called after openGL rending is executed
	 * \else
	 * 渲染之后调用
	 * \endif
	 */
	void afterRender();

	/**
	 * \if English
	 * release the frame buffer
	 * \else
	 * 释放缓存
	 * \endif
	 */
	void releaseBuffer();
};

#endif // __wyFrameBuffer_h__
