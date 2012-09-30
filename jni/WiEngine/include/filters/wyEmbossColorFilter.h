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
#ifndef __wyEmbossColorFilter_h__
#define __wyEmbossColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyEmbossColorFilter
 *
 * \if English
 * Emboss effect for texture
 * \else
 * 浮雕效果的滤镜
 * \endif
 */
class WIENGINE_API wyEmbossColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * gray level for emboss effect, [0, 255] and default is 128
	 * \else
	 * 浮雕效果的灰度级别, 级别越低, 最终的效果越暗. 允许值范围是0到255, 缺省是128
	 * \endif
	 */
	unsigned int m_grayLevel;

protected:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param grayLevel gray level for emboss effect
	 * \else
	 * 构造函数
	 *
	 * param grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	wyEmbossColorFilter(unsigned int grayLevel);

public:
	virtual ~wyEmbossColorFilter();

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param grayLevel gray level for emboss effect
	 * \else
	 * 静态构造函数
	 *
	 * param grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗. 缺省值是128.
	 * \endif
	 */
	static wyEmbossColorFilter* make(unsigned int grayLevel = 128);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * \if English
	 * Set gray level of emboss filter
	 *
	 * @param grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 设置浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @param grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	void setGrayLevel(unsigned int grayLevel) { m_grayLevel = grayLevel; }

	/**
	 * \if English
	 * Get gray level of emboss filter
	 *
	 * @return grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 获得浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @return grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	unsigned int getGrayLevel() { return m_grayLevel; }
};

#endif // __wyEmbossColorFilter_h__
