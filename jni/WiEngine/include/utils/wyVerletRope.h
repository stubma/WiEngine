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
#ifndef __wyVerletRope_h__
#define __wyVerletRope_h__

#include "wyObject.h"
#include "wyVerletStick.h"
#include "wyTypes.h"
#include "wyTexture2D.h"
#include "WiEngine-Classes.h"

/**
 * @class wyVerletRope
 *
 * Rope simulated by verlet integral
 */
class WIENGINE_API wyVerletRope : public wyObject {
private:
	/// texture of rope stick
	wyTexture2D* m_tex;

	/// array of all points
	wyArray* m_points;

	/// array of all segments
	wyArray* m_sticks;

	/// quad list mesh of this rope
	wyQuadList* m_mesh;

	/// material
	wyMaterial* m_material;

	/// true means mesh need to be updated
	bool m_dirty;

	/// a adjustable variable to avoid stick gap
	float m_antiSagHack;

	/// orignal length of rope
	float m_length;

	/// original length of stick
	float m_stickLength;

	/// color of rope
	wyColor4B m_color;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * Create a sub rope from other rope
	 *
	 * @param rope original rope
	 * @param startPoint start point index
	 * @param endPoint end point, inclusive
	 */
	wyVerletRope(wyVerletRope* rope, int startPoint, int endPoint);

	/**
	 * Update rope atlas quad
	 */
	void updateQuads();

	/**
	 * According to two points, calculate a quad to insert into atlas
	 *
	 * @param a \link wyVerletPoint wyVerletPoint\endlink
	 * @param b \link wyVerletPoint wyVerletPoint\endlink
	 */
	void appendQuad(wyVerletPoint* a, wyVerletPoint* b);

	/**
	 * Set original length
	 *
	 * @param length original length
	 */
	void setLength(float length) { m_length = length; }

public:
	/**
	 * Constructor
	 *
	 * @param a start point of rope
	 * @param b end point of rope
	 * @param tex texture of rope segment
	 * @param length length of rope, if zero, the rope length is distance between \c a and \c b
	 */
	wyVerletRope(wyPoint a, wyPoint b, wyTexture2D* tex, size_t length = 0);

	virtual ~wyVerletRope();

	/**
	 * Reset a rope with two endpoints
	 *
	 * @param a new start point
	 * @param b new end point
	 */
	void reset(wyPoint a, wyPoint b);

	/**
	 * Update rope state
	 *
	 * @param a new start point
	 * @param b new end point
	 * @param dt time since last \c update calling
	 */
	void update(wyPoint a, wyPoint b, float dt);

	/**
	 * Update rope mesh
	 */
	void updateMesh();

	/**
	 * Get material
	 */
	wyMaterial* getMaterial() { return m_material; }

	/**
	 * Get mesh
	 */
	wyMesh* getMesh();

	/**
	 * Get all rope segments
	 *
	 * @return array of all \link wyVerletStick wyVerletStick\endlink objects
	 */
	wyArray* getSticks() { return m_sticks; }

	/**
	 * Get segment at specified position
	 *
	 * @return \link wyVerletStick wyVerletStick\endlink, or NULL if index is invalid
	 */
	wyVerletStick* getStickAt(int index) { return (wyVerletStick*)wyArrayGet(m_sticks, index); }

	/**
	 * Get total number of rope segments
	 *
	 * @return number of \link wyVerletStick wyVerletStick\endlink
	 */
	int getStickCount() { return m_sticks->num; }

	/**
	 * Get all points in rope path
	 *
	 * @return an array contains all \link wyVerletPoint wyVerletPoint\endlink objects
	 */
	wyArray* getPoints() { return m_points; }

	/**
	 * Get point at specified position
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink object or NULL if index is invalid
	 */
	wyVerletPoint* getPointAt(int index) { return (wyVerletPoint*)wyArrayGet(m_points, index); }

	/**
	 * Get total number of points
	 *
	 * @return total number of points
	 */
	int getPointCount() { return m_points->num; }

	/**
	 * Get current length of rope and it may be larger than rope original length
	 *
	 * @return current length
	 */
	float getCurrentLength();

	/**
	 * Ray cast
	 *
	 * @param s start of ray
	 * @param e end of ray
	 * @return if ray intersects with rope and return index of \link wyVerletStick wyVerletStick\endlink
	 * 		object. Or returns -1 if no intersection. If more than one stick is crossed, only returns
	 * 		first
	 */
	int rayCast(wyPoint s, wyPoint e);

	/**
	 * Get current color
	 *
	 * @return \link wyColor3B wyColor3B\endlink
	 */
	wyColor3B getColor();

	/**
	 * Set rope color
	 *
	 * @param color \link wyColor3B wyColor3B\endlink
	 */
	void setColor(wyColor3B color);

	/**
	 * Set rope color
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void setColor(wyColor4B color);

	/**
	 * Get current alpha value
	 *
	 * @return alpha value
	 */
	int getAlpha() { return m_color.a; }

	/**
	 * Set rope alpha
	 *
	 * @param alpha alpha value
	 */
	void setAlpha(int alpha) { m_color.a = MAX(MIN(255, alpha), 0); }

	/**
	 * Get original length of rope. Original length is the length when rope is
	 * created
	 *
	 * @return original length
	 */
	float getLength() { return m_length; }

	/**
	 * Create a sub rope in parent rope range. Or NULL if index range
	 * is invalid
	 *
	 * @param startPoint start point index of sub rope
	 * @param endPoint end point index of sub rope
	 * @return \link wyVerletRope wyVerletRope\endlink object
	 */
	wyVerletRope* subRope(int startPoint, int endPoint);

	/**
	 * Is rope stretched. When rope length exceeds original length, it is stretched
	 *
	 * @return true means rope length exceeds original length
	 */
	bool isStretched();

	/**
	 * Change rope length
	 *
	 * @param delta delta length to be added to current rope length
	 */
	void changeLength(float delta);

	/**
	 * Get texture of rope
	 */
	wyTexture2D* getTexture() { return m_tex; }

	/**
	 * Set texture
	 */
	void setTexture(wyTexture2D* tex);
};

#endif // __wyVerletRope_h__
