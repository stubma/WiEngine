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
#ifndef __wyColorHSV_h__
#define __wyColorHSV_h__

#ifdef __cplusplus
extern "C" {
#endif

static inline wyColorHSV wychsv(float h, float s, float v) {
	wyColorHSV c = { h, s, v };
	return c;
}

/**
 * \if English
 * Convert hsv color to rgb color
 *
 * @param c hsv color
 * @return rgb color
 * \else
 * 将hsv颜色转换为rgb颜色
 *
 * @param c hsv颜色
 * @return rgb颜色
 * \endif
 */
wyColor3B wychsv2c3b(wyColorHSV& c);

/**
 * \if English
 * Convert hsv color to rgba color
 *
 * @param c hsv color
 * @param alpha transparency value
 * @return rgba color
 * \else
 * 将hsv颜色转换为rgba颜色
 *
 * @param c hsv颜色
 * @param alpha 透明度
 * @return rgba颜色
 * \endif
 */
wyColor4B wychsv2c4b(wyColorHSV& c, unsigned char alpha);

#ifdef __cplusplus
}
#endif

#endif // __wyColorHSV_h__
