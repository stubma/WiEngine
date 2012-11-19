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
#ifndef __wyAreaColorFilter_h__
#define __wyAreaColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyAreaColorFilter
 *
 * Map color at some area to other color. The area shape can be point, line, rectangle, circle
 */
class WIENGINE_API wyAreaColorFilter : public wyColorFilter {
private:
	/**
	 * buffer holds mapping info
	 */
	void* m_mapBuffer;

	/**
	 * Map entry count in color map
	 */
	int m_count;

	/**
	 * Map capacity in color map
	 */
	int m_capacity;

private:
	/**
	 * Ensure buffer size is enough
	 */
	void ensureCapacity();

protected:
	wyAreaColorFilter();

public:
	virtual ~wyAreaColorFilter();
	static wyAreaColorFilter* make();

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * Map color at a point to other color
	 *
	 * @param x the x position, uses top-left corner of image as origin
	 * @param y the y position, uses top-left corner of image as origin
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 */
	void mapPoint(int x, int y, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * Remove a position mapping
	 *
	 * @param x the x position, uses top-left corner of image as origin
	 * @param y the y position, uses top-left corner of image as origin
	 */
	void removePoint(int x, int y);

	/**
	 * Map colors at a line to other color
	 *
	 * @param x1 start x position, uses top-left corner of image as origin
	 * @param y1 start y position, uses top-left corner of image as origin
	 * @param x2 end x position, uses top-left corner of image as origin
	 * @param y2 end y position, uses top-left corner of image as origin
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 */
	void mapLine(int x1, int y1, int x2, int y2, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * Remove a line mapping
	 *
	 * @param x1 start x position, uses top-left corner of image as origin
	 * @param y1 start y position, uses top-left corner of image as origin
	 * @param x2 end x position, uses top-left corner of image as origin
	 * @param y2 end y position, uses top-left corner of image as origin
	 */
	void removeLine(int x1, int y1, int x2, int y2);

	/**
	 * Map colors in a rectangle to other color
	 *
	 * @param x rect top-left x position, origin is top-left of image
	 * @param y rect top-left y position, origin is top-left of image
	 * @param w rect width
	 * @param h rect height
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 */
	void mapRect(int x, int y, int w, int h, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * Remove a rectangle mapping
	 *
	 * @param x rect top-left x position, origin is top-left of image
	 * @param y rect top-left y position, origin is top-left of image
	 * @param w rect width
	 * @param h rect height
	 */
	void removeRect(int x, int y, int w, int h);

	/**
	 * Map colors in a circle to other color
	 *
	 * @param centerX center of circle, origin is top-left of image
	 * @param centerY centerY of circle, origin is top-left of image
	 * @param radius circle radius
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 */
	void mapCircle(int centerX, int centerY, int radius, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * Remove a circle mapping
	 *
	 * @param centerX center of circle, origin is top-left of image
	 * @param centerY centerY of circle, origin is top-left of image
	 * @param radius circle radius
	 */
	void removeCircle(int centerX, int centerY, int radius);
};

#endif // __wyAreaColorFilter_h__
