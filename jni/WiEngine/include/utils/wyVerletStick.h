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
#ifndef __wyVerletStick_h__
#define __wyVerletStick_h__

#include "wyObject.h"
#include "wyVerletPoint.h"

class wyVerletRope;

/**
 * @class wyVerletStick
 *
 * Segment of between two \link wyVerletPoint wyVerletPoint\endlink
 */
class WIENGINE_API wyVerletStick : public wyObject {
	friend class wyVerletRope;

private:
	/// point a
	wyVerletPoint* m_pointA;

	/// point b
	wyVerletPoint* m_pointB;

	/// pixel distance between point a and b
	float m_length;

	/// current length of stick
	float m_currentLength;

protected:
	/**
	 * 设置stick的长度
	 *
	 * @param length 长度
	 */
	void setLength(float length);

public:
	wyVerletStick(wyVerletPoint* a, wyVerletPoint* b);
	virtual ~wyVerletStick();

	/**
	 * Contract this segment to approach original length. It is not done
	 * immediately but repeatly.
	 *
	 * @param reverse true means treat a point as b, treat b as a
	 */
	void contract(bool reverse);

	/**
	 * Get point a
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 */
	wyVerletPoint* getPointA() { return m_pointA; }

	/**
	 * Get point b
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 */
	wyVerletPoint* getPointB() { return m_pointB; }

	/**
	 * Get original length
	 *
	 * @return original length
	 */
	float getLength() { return m_length; }

	/**
	 * Get current length
	 *
	 * @return current length
	 */
	float getCurrentLength() { return m_currentLength; }
};

#endif // __wyVerletStick_h__
