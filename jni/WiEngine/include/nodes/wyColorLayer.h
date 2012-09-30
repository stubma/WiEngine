/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyColorLayer_h__
#define __wyColorLayer_h__

#include "wyLayer.h"
#include "wyGlobal.h"

/**
 * @class wyColorLayer
 * \if English
 * a color layer, visible
 * \else
 * 有底色显示层的封装
 * \endif
 */
class WIENGINE_API wyColorLayer : public wyLayer {
protected:
	/**
	 * \if English
	 * opengl vertices
	 * \else
	 * opengl顶点
	 * \endif
	 */
	GLfloat* m_vertices;

	/**
	 * \if English
	 * color of the layer, used by opengl
	 * \else
	 * opengl颜色
	 * \endif
	 */
	GLubyte* m_colors;

	/**
	 * \if English
	 * color of the layer, \link wyColor4B wyColor4B\endlink
	 * \else
	 * 颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_color;

private:
	void updateColor();

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param color 颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	static wyColorLayer* make(wyColor4B color = wyc4bTransparent);

	/**
	 * \if English
	 * constructor
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * \else
	 * 构造函数
	 *
	 * @param color 颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColorLayer(wyColor4B color = wyc4bTransparent);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyColorLayer();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);
};

#endif // __wyColorLayer_h__
