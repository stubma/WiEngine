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
#ifndef __wyCustomColorFilter_h__
#define __wyCustomColorFilter_h__

#include "wyColorFilter.h"

/**
 * Delegate of custom color filter apply method
 */
class WIENGINE_API wyColorFilterDelegate {
public:
	/**
	 * apply this color filter to some image data
	 *
	 * @param f custom filter object
	 * @param imageData raw data of image which must be RGBA8888 format, it holds transformed result when method returns
	 * @param width image pixel width, it is the original size before autoscaling
	 * @param height image pixel height, it is the original size before autoscaling
	 */
	virtual void applyCustomFilter(wyCustomColorFilter* f, void* imageData, int width, int height) = 0;
};

/**
 * Custom color filter, filter is implemented by setting a delegate
 */
class WIENGINE_API wyCustomColorFilter : public wyColorFilter {
private:
	/// Delegate of color filter method
	wyColorFilterDelegate* m_delegate;

protected:
	/**
	 * Constructor
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 */
	wyCustomColorFilter(wyColorFilterDelegate* delegate);

public:
	virtual ~wyCustomColorFilter();

	/**
	 * Static constructor
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @return \link wyCustomColorFilter wyCustomColorFilter\endlink
	 */
	static wyCustomColorFilter* make(wyColorFilterDelegate* delegate);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * Set delegate
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 */
	void setDelegate(wyColorFilterDelegate* delegate) { m_delegate = delegate; }
};

#endif // __wyCustomColorFilter_h__
