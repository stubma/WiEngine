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

/**
 * @class wyRenderTexture
 *
 * 设置自定义frame buffer，使渲染结果保存在贴图中。用于实现一些特殊效果
 */
class WIENGINE_API wyRenderTexture : public wyNode  {
protected:
	/// openGL贴图标识
	int m_texture;

	// buffer
	int m_fbo;
	int m_old_fbo;

	/// 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
	wyBlendFunc m_blendFunc;

	/// 颜色\link wyColor4B wyColor4B结构\endlink
	wyColor4B m_color;

	/// true means texture need to be released
	bool m_needReleaseTexture;

	/// width of texture, not POT width
	float m_texWidth;

	/// height of texture, not POT height
	float m_texHeight;

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

	/// create frame buffer
	void createFrameBuffer(int w, int h);

	/**
	 * Release frame buffer object
	 */
	void releaseBuffer();

	/**
	 * Release texture
	 */
	void releaseTexture();

public:
	/**
	 * \if English
	 * Create a render texture with specified size
	 *
	 * @param width width in pixel
	 * @param height height in pixel
	 * \else
	 * 静态构造函数
	 *
	 * @param width 宽度
	 * @param height 高度
	 * \endif
	 */
	static wyRenderTexture* make(int width, int height);

	/**
	 * \if English
	 * Create a render texture which is full screen size
	 * \else
	 * 创建一个全屏大小的渲染贴图
	 * \endif
	 */
	static wyRenderTexture* make();

	/**
	 * 析构函数
	 */
	virtual ~wyRenderTexture();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha) { m_color.a = alpha; }

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/**
	 * \if English
	 * Start render something into texture
	 * \else
	 * Render之前调用, 开始讲渲染操作重定向到贴图中
	 * \endif
	 */
	void beginRender();

	/**
	 * \if English
	 * Start render something into texture. You can specify background color of
	 * texture
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 * \else
	 * Render之前调用, 开始讲渲染操作重定向到贴图中. 这个方法可以指定贴图背景色
	 *
	 * @param r 背景色的红色部分
	 * @param g 背景色的绿色部分
	 * @param b 背景色的蓝色部分
	 * @param a 背景色的透明度
	 * \endif
	 */
	void beginRender(float r, float g, float b, float a);

	/**
	 * \if English
	 * End render redirecting
	 * \else
	 * Render之后调用, 结束渲染重定向
	 * \endif
	 */
	void endRender();

	/**
	 * \if English
	 * Clear texture with a color
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 * \else
	 * 用某个颜色清空贴图内容
	 *
	 * @param r 背景色的红色部分
	 * @param g 背景色的绿色部分
	 * @param b 背景色的蓝色部分
	 * @param a 背景色的透明度
	 * \endif
	 */
	void clear(float r, float g, float b, float a);

	/**
	 * \if English
	 * Get \link wyTexture2D wyTexture2D\endlink object from render texture
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 从当前对象得到一个\link wyTexture2D wyTexture2D\endlink对象
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	wyTexture2D* createTexture();
};

#endif // __wyRenderTexture_h__
