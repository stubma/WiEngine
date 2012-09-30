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
#ifndef __wyDropShadowColorFilter_h__
#define __wyDropShadowColorFilter_h__

#include "wyColorFilter.h"
#include "wyTypes.h"

/**
 * @class wyDropShadowColorFilter
 *
 * \if English
 * Glow texture
 * \else
 * 阴影滤镜
 * \endif
 */
class WIENGINE_API wyDropShadowColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * The radius of the glow in pixels
	 * \else
	 * 阴影颜色半径
	 * \endif
	 */
	int m_radius;

	/**
	 * \if English
	 * The color of the glow
	 * \else
	 * 阴影颜色
	 * \endif
	 */
	wyColor3B m_color;

	/**
	 * \if English
	 * The radius of the highlight area
	 * \else
	 * 阴影颜色半径高亮区域
	 * \endif
	 */
	int m_highlightRadius;

	/**
	 * \if English
	 * The opacity of the glow
	 * \else
	 * 阴影透明度
	 * \endif
	 */
	int m_opacity;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param color The color of the glow
	 * @param radius The radius of the glow in pixels
	 * @param highlightRadius The radius of the highlight area
	 * @param opacity The opacity of the glow
	 * \else
	 * 构造函数
	 *
	 * @param color 阴影颜色
	 * @param radius 阴影半径
	 * @param highlightRadius 阴影半径高亮区域
	 * @param opacity 阴影透明度
	 * \endif
	 */
	wyDropShadowColorFilter(wyColor3B color, int radius, int highlightRadius, int opacity);

public:
	virtual ~wyDropShadowColorFilter();

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param color The color of the glow
	 * @param radius The radius of the glow in pixels
	 * @param highlightRadius The radius of the highlight area
	 * @param opacity The opacity of the glow
	 * @return \link wyDropShadowColorFilter wyDropShadowColorFilter\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param color 阴影颜色
	 * @param radius 阴影半径
	 * @param highlightRadius 阴影半径高亮区域
	 * @param opacity 阴影透明度
	 * @return \link wyDropShadowColorFilter wyDropShadowColorFilter\endlink
	 * \endif
	 */
	static wyDropShadowColorFilter* make(wyColor3B color, int radius, int highlightRadius, int opacity);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * \if English
	 * Set blur radius
	 *
	 * @param radius blur radius
	 * \else
	 * 设置模糊半径
	 *
	 * @param radius 阴影半径
	 * \endif
	 */
	void setRadius(int radius) { m_radius = radius; }

	/**
	 * \if English
	 * Get blur radius
	 *
	 * @return blur radius
	 * \else
	 * 得到阴影半径
	 *
	 * @return 模糊半径
	 * \endif
	 */
	int getRadius() { return m_radius; }

	/**
	 * \if English
	 * Set opacity of the glow
	 *
	 * @param opacity of the glow
	 * \else
	 * 设置阴影透明度
	 *
	 * @param opacity 阴影透明度
	 * \endif
	 */
	void setOpacity(int opacity) { m_opacity = opacity; }

	/**
	 * \if English
	 * The opacity of the glow
	 *
	 * @return The opacity of the glow
	 * \else
	 * 得到阴影透明度
	 *
	 * @return 阴影透明度
	 * \endif
	 */
	int getOpacity() { return m_opacity; }

	/**
	 * \if English
	 * Set radius of the highlight area
	 *
	 * @param highlightRadius of the highlight area
	 * \else
	 * 设置阴影高亮区域半径
	 *
	 * @param highlightRadius 阴影高亮区域半径
	 * \endif
	 */
	void setHighlightRadius(int highlightRadius) { m_highlightRadius = highlightRadius; }

	/**
	 * \if English
	 * The radius of the highlight area
	 *
	 * @return The radius of the highlight area
	 * \else
	 * 得到阴影高亮区域半径
	 *
	 * @return 阴影高亮区域半径
	 * \endif
	 */
	int getHighlightRadius() { return m_highlightRadius; }
};

#endif // __wyDropShadowColorFilter_h__
