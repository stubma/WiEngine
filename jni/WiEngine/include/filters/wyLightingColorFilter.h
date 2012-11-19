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
 * Color filter that multiplies the RGB channels by one color, and then adds a second color,
 * pinning the result for each component to [0..255]. The alpha components of the mul and add arguments
 * are ignored.
 */
class WIENGINE_API wyLightingColorFilter : public wyColorFilter {
private:
	/**
	 * color to be multiplied, format is 0xaarrggbb
	 */
	int m_mul;

	/**
	 * color to be added, format is 0xaarrggbb
	 */
	int m_add;

protected:
	/**
	 * constructor
	 *
	 * @param mul color to be multiplied, format is 0xaarrggbb
	 * @param add color to be added, format is 0xaarrggbb
	 */
	wyLightingColorFilter(int mul, int add);

public:
	virtual ~wyLightingColorFilter();

	/**
	 * static constructor
	 *
	 * @param mul color to be multiplied, format is 0xaarrggbb
	 * @param add color to be added, format is 0xaarrggbb
	 * @return \link wyLightingColorFilter wyLightingColorFilter\endlink
	 */
	static wyLightingColorFilter* make(int mul, int add);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);
};

#endif // __wyLightingColorFilter_h__
