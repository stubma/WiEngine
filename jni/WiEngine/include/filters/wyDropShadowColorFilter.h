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
 * Glow texture
 */
class WIENGINE_API wyDropShadowColorFilter : public wyColorFilter {
private:
	/**
	 * The radius of the glow in pixels
	 */
	int m_radius;

	/**
	 * The color of the glow
	 */
	wyColor3B m_color;

	/**
	 * The radius of the highlight area
	 */
	int m_highlightRadius;

	/**
	 * The opacity of the glow
	 */
	int m_opacity;

protected:
	/**
	 * constructor
	 *
	 * @param color The color of the glow
	 * @param radius The radius of the glow in pixels
	 * @param highlightRadius The radius of the highlight area
	 * @param opacity The opacity of the glow
	 */
	wyDropShadowColorFilter(wyColor3B color, int radius, int highlightRadius, int opacity);

public:
	virtual ~wyDropShadowColorFilter();

	/**
	 * Static constructor
	 *
	 * @param color The color of the glow
	 * @param radius The radius of the glow in pixels
	 * @param highlightRadius The radius of the highlight area
	 * @param opacity The opacity of the glow
	 * @return \link wyDropShadowColorFilter wyDropShadowColorFilter\endlink
	 */
	static wyDropShadowColorFilter* make(wyColor3B color, int radius, int highlightRadius, int opacity);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * Set blur radius
	 *
	 * @param radius blur radius
	 */
	void setRadius(int radius) { m_radius = radius; }

	/**
	 * Get blur radius
	 *
	 * @return blur radius
	 */
	int getRadius() { return m_radius; }

	/**
	 * Set opacity of the glow
	 *
	 * @param opacity of the glow
	 */
	void setOpacity(int opacity) { m_opacity = opacity; }

	/**
	 * The opacity of the glow
	 *
	 * @return The opacity of the glow
	 */
	int getOpacity() { return m_opacity; }

	/**
	 * Set radius of the highlight area
	 *
	 * @param highlightRadius of the highlight area
	 */
	void setHighlightRadius(int highlightRadius) { m_highlightRadius = highlightRadius; }

	/**
	 * The radius of the highlight area
	 *
	 * @return The radius of the highlight area
	 */
	int getHighlightRadius() { return m_highlightRadius; }
};

#endif // __wyDropShadowColorFilter_h__
