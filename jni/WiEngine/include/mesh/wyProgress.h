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
#ifndef __wyProgress_h__
#define __wyProgress_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * A progress mesh, its mesh vertex can be controlled by percentage from 0 to 100
 */
class WIENGINE_API wyProgress : public wyMesh {
public:
	/// style of progress mesh
	enum Style {
		/// sector in counter-clockwise
		RADIAL_CCW = 1,

		/// sector in clockwise
		RADIAL_CW,

		/// horizontal bar from left to right
		HORIZONTAL_BAR_LR,

		/// horizontal bar from right to left
		HORIZONTAL_BAR_RL,

		/// vertical bar from bottom to top
		VERTICAL_BAR_BT,

		/// vertical bar from top to bottom
		VERTICAL_BAR_TB
	};

private:
	/// vertex buffer
	wyBuffer* m_buf;

	/// mesh style
	Style m_style;

	/// percentage, from 0 to 100
	float m_percentage;

protected:
	/**
	 * Constructor
	 *
	 * @param style mesh style
	 */
	wyProgress(Style style);

	/// update mesh when style is bar
	void updateBar();

	/// update mesh when style is radial
	void updateRadial();

	/// get boundary point texture coordinates
	wyPoint boundaryTexCoord(int index);

	/// get vertex from texture coordinates
	wyPoint vertexFromTexCoord(float u, float v);

public:
	virtual ~wyProgress();

	/// create a empty bar mesh
	static wyProgress* make(Style style = RADIAL_CCW);

	/// @see wyMesh::getElementCount
	virtual int getElementCount() { return m_buf->getElementCount(); }

	/// @see wyMesh::update
	virtual void update();

	/// @see wyMesh::updateColor4B
	virtual void updateColor4B(wyColor4B color) { updateColor(color, false); }

	/// set mesh style
	void setStyle(Style style);

	/// get mesh style
	Style getStyle() { return m_style; }

	/// get percentage
	float getPercentage() { return m_percentage; }

	/// set percentage
	void setPercentage(float p);

	/**
	 * update color
	 *
	 * @param c color
	 * @param premultipliedAlpha true means should process the color as a premultiplied alpha color
	 */
	void updateColor(wyColor4B c, bool premultipliedAlpha);
};

#endif // __wyProgress_h__
