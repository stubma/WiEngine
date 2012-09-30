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
#ifndef __wyGradientColorLayer_h__
#define __wyGradientColorLayer_h__

#include "wyLayer.h"
#include "wyGlobal.h"

/**
 * @class wyGradientColorLayer
 *
 * \if English
 * gradient color layer
 * \else
 * 渐变色显示层的封装
 * \endif
 */
class WIENGINE_API wyGradientColorLayer : public wyLayer {
protected:
	/**
	 * \if English
	 * array of opengl vertices
	 * \else
	 * opengl顶点
	 * \endif
	 */
	GLfloat* m_vertices;

	/**
	 * \if English
	 * array of the original opengl vertices
	 * \else
	 * 原始位置opengl顶点，依次为左上，左下，右上，右下
	 * \endif
	 */
	GLfloat* m_originalVertices;

	/**
	 * \if English
	 * color measured in opengl
	 * \else
	 * opengl颜色
	 * \endif
	 */
	GLubyte* m_colors;

	/**
	 * \if English
	 * the start color, \link wyColor4B wyColor4B\endlink
	 * \else
	 * 起始颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_fromColor;

	/**
	 * \if English
	 * the end color, \link wyColor4B wyColor4B\endlink
	 * \else
	 * 结束颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_toColor;

	/**
	 * \if English
	 * the radiant angle, in degrees, clockwise
	 * \else
	 * 渐变角度,0标识从左到右水平变化，大于0为顺时针
	 * \endif
	 */
	int m_degree;

private:
	void updateColor();
	void updateVertices();

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param fromColor the start color, \link wyColor4B wyColor4B\endlink
	 * @param toColor the end color, \link wyColor4B wyColor4B\endlink
	 * @param degree the radian angle
	 * \else
	 * 静态构造函数
	 *
	 * @param fromColor 起始颜色\link wyColor4B wyColor4B结构\endlink
	 * @param toColor 结束颜色\link wyColor4B wyColor4B结构\endlink
	 * @param degree 渐变角度,0标识从左到右水平变化，大于0为顺时针
	 * \endif
	 */
	static wyGradientColorLayer* make(wyColor4B fromColor, wyColor4B toColor, int degree);

	/**
	 * \if English
	 * constructor
	 *
	 * @param fromColor the start color, \link wyColor4B wyColor4B\endlink
	 * @param toColor the end color, \link wyCoclor4B wyColor4B\endlink
	 * @param degree the radian angle
	 * \else
	 * 构造函数
	 *
	 * @param fromColor 起始颜色\link wyColor4B wyColor4B结构\endlink
	 * @param toColor 结束颜色\link wyColor4B wyColor4B结构\endlink
	 * @param degree 渐变角度,0标识从左到右水平变化，大于0为顺时针
	 * \endif
	 */
	wyGradientColorLayer(wyColor4B fromColor, wyColor4B toColor, int degree);

	/**
	 * \if English
	 * setter
	 *
	 * @param degree in degrees, clockwise
	 * \else
	 * 设置渐变角度
	 *
	 * @param degree 渐变角度
	 * \endif
	 */
	void setDegree(int degree);

	/**
	 * \if English
	 * getter
	 * \else
	 * 得到渐变角度
	 *
	 * @return 渐变角度
	 * \endif
	 */
	int getDegree();

	/**
	 * \if English
	 * setter
	 *
	 * @param color \link wyColor3B wyColor3B\endlink
	 * \else
	 * 设置起始颜色
	 *
	 * @param color 起始颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	void setFromColor(wyColor3B color);

	/**
	 * \if English
	 * getter
	 *
	 * @return \link wyColor3B wyColor3B\endlink
	 * \else
	 * 得到起始颜色
	 *
	 * @return 起始颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	wyColor3B getFromColor();

	/**
	 * \if English
	 * setter
	 *
	 * @param color \link wyColor3B wyColor3B\endlink
	 * \else
	 * 设置结束颜色
	 *
	 * @param color 结束颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	void setToColor(wyColor3B color);

	/**
	 * \if English
	 * getter
	 *
	 * @return \link wyColor3B wyColor3B\endlink
	 * \else
	 * 得到结束颜色
	 *
	 * @return 结束颜色\link wyColor3B wyColor3B结构\endlink
	 * \endif
	 */
	wyColor3B getToColor();

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyGradientColorLayer();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

};

#endif // __wyGradientColorLayer_h__
