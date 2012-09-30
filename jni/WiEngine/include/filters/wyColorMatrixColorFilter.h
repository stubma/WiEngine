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
#ifndef __wyColorMatrixColorFilter_h__
#define __wyColorMatrixColorFilter_h__

#include "wyColorFilter.h"
#include "wyColorMatrix.h"

/**
 * @class wyColorMatrixColorFilter
 *
 * \if English
 * color filter which use a color matrix to transform colors
 * \else
 * 使用颜色矩阵对颜色进行转换的过滤器
 * \endif
 */
class WIENGINE_API wyColorMatrixColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * \link wyColorMatrix wyColorMatrix\endlink
	 * \else
	 * \link wyColorMatrix wyColorMatrix\endlink
	 * \endif
	 */
	wyColorMatrix* m_matrix;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param m \link wyColorMatrix wyColorMatrix\endlink
	 * \else
	 * 构造函数
	 *
	 * @param m \link wyColorMatrix wyColorMatrix\endlink
	 * \endif
	 */
	wyColorMatrixColorFilter(wyColorMatrix* m);

public:
	virtual ~wyColorMatrixColorFilter();

	/**
	 * \if English
	 * create a color matrix filter
	 *
	 * @param m \link wyColorMatrix wyColorMatrix\endlink
	 * @return \link wyColorMatrixColorFilter wyColorMatrixColorFilter\endlink
	 * \else
	 * 创建一个颜色矩阵过滤器
	 *
	 * @param m \link wyColorMatrix wyColorMatrix\endlink
	 * @return \link wyColorMatrixColorFilter wyColorMatrixColorFilter\endlink
	 * \endif
	 */
	static wyColorMatrixColorFilter* make(wyColorMatrix* m);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);
};

#endif // __wyColorMatrixColorFilter_h__
