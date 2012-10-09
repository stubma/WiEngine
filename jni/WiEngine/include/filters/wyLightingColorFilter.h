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
#ifndef __wyLightingColorFilter_h__
#define __wyLightingColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyLightingColorFilter
 *
 * \if English
 * Color filter that multiplies the RGB channels by one color, and then adds a second color,
 * pinning the result for each component to [0..255]. The alpha components of the mul and add arguments
 * are ignored.
 * \else
 * 这个滤镜对颜色的三原色进行一个乘法, 然后再做一个加法, 最后的结果限制在[0, 255]之内. 透明度不参与乘法和加法.
 *
 * \par
 * 例如: 如果想把图片中的红色清空, 可以指定和0xFF00FFFF相乘, 再和0x00000000相加.
 * \endif
 */
class WIENGINE_API wyLightingColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * color to be multiplied, format is 0xaarrggbb
	 * \else
	 * 用来相乘的颜色, 格式是0xaarrggbb
	 * \endif
	 */
	int m_mul;

	/**
	 * \if English
	 * color to be added, format is 0xaarrggbb
	 * \else
	 * 用来相加的颜色, 格式是0xaarrggbb
	 * \endif
	 */
	int m_add;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param mul color to be multiplied, format is 0xaarrggbb
	 * @param add color to be added, format is 0xaarrggbb
	 * \else
	 * 构造函数
	 *
	 * @param mul 用来相乘的颜色, 格式是0xaarrggbb
	 * @param add 用来相加的颜色, 格式是0xaarrggbb
	 * \endif
	 */
	wyLightingColorFilter(int mul, int add);

public:
	virtual ~wyLightingColorFilter();

	/**
	 * \if English
	 * static constructor
	 *
	 * @param mul color to be multiplied, format is 0xaarrggbb
	 * @param add color to be added, format is 0xaarrggbb
	 * @return \link wyLightingColorFilter wyLightingColorFilter\endlink
	 * \else
	 * 构造函数
	 *
	 * @param mul 用来相乘的颜色, 格式是0xaarrggbb
	 * @param add 用来相加的颜色, 格式是0xaarrggbb
	 * @return \link wyLightingColorFilter wyLightingColorFilter\endlink
	 * \endif
	 */
	static wyLightingColorFilter* make(int mul, int add);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);
};

#endif // __wyLightingColorFilter_h__
