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
#ifndef __wyLineRibbon_h__
#define __wyLineRibbon_h__

#include "wyRibbon.h"
#include "wyTypes.h"
#include "wyArray.h"

/**
 * @class wyLineRibbon
 * \if English
 * linear ribbon, with both of its ends smoothed.
 * If the line width is not explicitly specified, the width of the texture will be used.
 * \else
 * 线状连续图形，等宽，头尾有圆角效果
 * \endif
 */
class WIENGINE_API wyLineRibbon : public wyRibbon {
private:
	/**
	 * \if English
	 * \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 贴图
	 * \endif
	 */
    wyTexture2D* m_tex;

    /**
     * \if English
     * to store the lines
     * \else
     * 当前所有的线
     * \endif
     */
    wyArray* m_lines;

    /**
     * \if English
     * color, \link wyColor4B wyColor4B\endlink
     * \else
     * 颜色
     * \endif
     */
    wyColor4B m_color;

    /**
     * \if English
     * the line width, in pixels
     * \else
     * 线宽，单位像素
     * \endif
     */
    float m_lineWidth;

private:
    static bool releaseLine(wyArray* arr, void* ptr, int index, void* data);

public:
    /**
     * \if English
     * factory function, used to create a new instance with autoRelease enabled
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
     * \else
	 * 静态构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * \endif
	 */
    static wyLineRibbon* make(wyTexture2D* tex, wyColor4B color);

    /**
     * \if English
     * constructor
     *
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param color \link wyColor4B wyColor4B\endlink
     * \else
	 * 构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * \endif
	 */
    wyLineRibbon(wyTexture2D* tex, wyColor4B color);

    /**
     * \if English
     * destructor
     * \else
	 * 析构函数
	 * \endif
	 */
    virtual ~wyLineRibbon();

    /// @see wyNode::draw
    virtual void draw();

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_tex; }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex);

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

    /// @see wyRibbon::update
	virtual void update(float delta);

	/// @see wyRibbon::addPoint
	virtual void addPoint(wyPoint location);

	/// @see wyRibbon::reset
	virtual void reset();

	/**
	 * \if English
	 * setter
	 *
	 * @param width the line width, in pixels
	 * \else
	 * 设置线宽，如果不设置，则缺省为贴图的有效高度. 该设置不影响已经存在的线. 设置之后创建的
	 * 线将变成该宽度
	 *
	 * @param width 线宽, 单位像素
	 * \endif
	 */
	void setLineWidth(float width);

	/**
	 * \if English
	 * get the width of a specified line
	 *
	 * @param index index of the line
	 * @return width of the line, in pixels. 0 returned if index is invalid.
	 * \else
	 * 得到某条线的宽度
	 *
	 * @param index 线的索引
	 * @return 线的宽度, 单位像素. 如果索引不合法，返回0
	 * \endif
	 */
	float getLineWidth(int index);

	/**
	 * \if English
	 * get the color of a specified line
	 *
	 * @param index index of the line
	 * @return \link wyColor4B wyColor4B\endlink
	 * \else
	 * 得到某条线的颜色
	 *
	 * @param index 线的索引
	 * @return \link wyColor4B wyColor4B\endlink
	 * \endif
	 */
	wyColor4B getLineColor(int index);

	/**
	 * \if English
	 * get the line count
	 * \else
	 * 得到线的个数
	 *
	 * @return 线段的个数
	 * \endif
	 */
	int getLineCount() { return m_lines->num; }

	/**
	 * \if English
	 * get the point count of a specified line
	 *
	 * @param index index of the line
	 * @return the count, 0 if index is invalid.
	 * \else
	 * 得到某条线的点个数
	 *
	 * @param index 线的索引
	 * @return 线的点个数. 如果索引不合法，返回0
	 * \endif
	 */
	int getLinePointCount(int index);

	/**
	 * \if English
	 * get the array of points of a specified line.
	 *
	 * @param index index of the line
	 * @return array of \link wyPoint wyPoint\endlink, NULL if index is invalid.
	 * \else
	 * 得到线的点列表
	 *
	 * @param index 线的索引
	 * @return \link wyPoint wyPoint\endlink指针，调用者不需要负责释放. 如果索引不合法，返回NULL
	 * \endif
	 */
	wyPoint* getLinePointList(int index);
};

#endif // __wyLineRibbon_h__
