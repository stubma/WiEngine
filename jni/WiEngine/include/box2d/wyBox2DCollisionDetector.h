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
#ifndef __wyCollisionDetector_h__
#define __wyCollisionDetector_h__

#include <Box2D/Box2D.h>
#include "wyHashSet.h"
#include "wyNode.h"

struct wyNodeHash;

/**
 * @struct wyBox2DCDResult
 *
 * Result of collision detection
 */
typedef struct BOX2D_API wyBox2DCDResult {
	/**
	 * collision point count
	 */
	int pointCount;

	/**
	 * collision points, max is two and they are in world coordinates
	 */
	wyPoint points[2];

	/**
	 * normal of collision, in world coordinate. It points from first node
	 * to second node.
	 */
	wyPoint normal;
} wyBox2DCDResult;

/**
 * @class wyBox2DCollisionDetector
 *
 * A collision detector based on Box2D collision detection utility but
 * no need to establish whole world. It encapsulates detailed implementation of
 * Box2D and exposes those features in \link wyNode wyNode\endlink structure.
 */
class BOX2D_API wyBox2DCollisionDetector : public wyObject {
private:
	/**
	 * mapping from node to shape
	 */
	wyHashSet* m_nodeShapes;

	/**
	 * pixels of one meter
	 */
	float m_meterPixels;

private:
	static int nodeHashEquals(void* ptr, void* elt);
	static void* buildNodeHash(void* ptr, void* data);
	static bool releaseHash(void* elt, void* data);

	/**
	 * Add a node to collision detector so that it will be managed
	 * and you can later call detection method for it. If you want to
	 * perform collision detection on a node, you must add it. Good
	 * news is this method is invoked internally
	 *
	 * @return hash entry of node
	 */
	wyNodeHash* addNode(wyNode* node);

	/**
	 * according to current scale rate, convert pixel to meter
	 *
	 * @param pixel pixel
	 * @return meter
	 */
	float pixel2Meter(float pixel) { return pixel / m_meterPixels; }

	/**
	 * according to current scale rate, convert meter to pixel
	 *
	 * @param meter mter
	 * @return pixel
	 */
	float meter2Pixel(float meter) { return meter * m_meterPixels; }

protected:
	wyBox2DCollisionDetector();

public:
	virtual ~wyBox2DCollisionDetector();
	static wyBox2DCollisionDetector* make();

	/**
	 * Are two nodes collided each other?
	 *
	 * @param node1 first node
	 * @param node2 second node
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 */
	bool isCollided(wyNode* node1, wyNode* node2, wyBox2DCDResult* result);

	/**
	 * Is node collided with a rectangle
	 *
	 * @param node node
	 * @param r rectangle, must in global coordinate
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 */
	bool isCollided(wyNode* node, wyRect& r, wyBox2DCDResult* result);

	/**
	 * Are two rectangle collided each other?
	 *
	 * @param r1 first rectangle, must in same coordinates as \c r2
	 * @param r2 second rectangle, must in same coordinates as \c r1
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 */
	bool isCollided(wyRect& r1, wyRect& r2, wyBox2DCDResult* result);

	/**
	 * Set polygon shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param points vertices of shape, must in counter-clockwise sequence and in
	 * 		WiEngine global coordinates.
	 * @param count point count in \c points
	 */
	void setNodeShape(wyNode* node, wyPoint* points, int count);

	/**
	 * Set circle shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param radius radius of circle
	 */
	void setNodeShape(wyNode* node, int radius);
};

#endif // __wyCollisionDetector_h__
