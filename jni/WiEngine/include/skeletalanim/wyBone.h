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
#ifndef __wyBone_h__
#define __wyBone_h__

#include "wyObject.h"

/**
 * bone
 */
class WIENGINE_API wyBone : public wyObject {
private:
	/// parent bone
	wyBone* m_parent;

	/// bone length
	float m_length;

	/// x offset
	float m_x;

	/// y offset
	float m_y;

	/// rotation in degree, positive value means counter-clockwise, x axis is zero degree
	float m_rotation;

	/// x scale
	float m_scaleX;

	/// y scale
	float m_scaleY;

protected:
	wyBone(wyBone* parent);

public:
	virtual ~wyBone();

	/**
	 * create a bone class
	 *
	 * @param parent parent bone, or NULL if no parent
	 */
	static wyBone* make(wyBone* parent = NULL);

	/// get parent bone
	wyBone* getParent() { return m_parent; }

	/// set length
	void setLength(float len) { m_length = len; }

	/// get length
	float getLength() { return m_length; }

	/// set x offset
	void setX(float x) { m_x = x; }

	/// get x offset
	float getX() { return m_x; }

	/// set y offset
	void setY(float y) { m_y = y; }

	/// get y offset
	float getY() { return m_y; }

	/// set rotation
	void setRotation(float r) { m_rotation = r; }

	/// get rotation
	float getRotation() { return m_rotation; }

	/// set x scale
	void setScaleX(float x) { m_scaleX = x; }

	/// get x scale
	float getScaleX() { return m_scaleX; }

	/// set y scale
	void setScaleY(float y) { m_scaleY = y; }

	/// get y scale
	float getScaleY() { return m_scaleY; }
};

#endif // __wyBone_h__
