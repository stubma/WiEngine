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
#ifndef __wyMappingColorFilter_h__
#define __wyMappingColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyMappingColorFilter
 *
 * This filter map a color to another color, so you can replace a color to another color easily.
 * This filter by default neglect alpha channel so alpha keep unchanged, but you can set flag to
 * change this behavior.
 *
 * \note
 * If an image will be auto scaled by WiEngine, don't worry about the result because color filter
 * is performed before scaling.
 */
class WIENGINE_API wyMappingColorFilter : public wyColorFilter {
private:
	/**
	 * map of colors
	 */
	void* m_colorMap;

	/**
	 * Map entry count in color map
	 */
	int m_count;

	/**
	 * Map capacity in color map
	 */
	int m_capacity;

protected:
	wyMappingColorFilter();

public:
	virtual ~wyMappingColorFilter();
	static wyMappingColorFilter* make();

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * Define a color mapping
	 *
	 * @param from the color need to be changed, in argb format
	 * @param to destination color, in argb format
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 */
	void mapColor(int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * Unmap a color
	 *
	 * @param from color need to be removed from map
	 */
	void unmapColor(int from);
};

#endif // __wyMappingColorFilter_h__
