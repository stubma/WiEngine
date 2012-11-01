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
#ifndef __wyBox2D_h__
#define __wyBox2D_h__

#include "wyNode.h"
#include <Box2D/Box2D.h>

class wyBox2DDebugDraw;

/**
 * encapsulation for box2d. wyBox2D is a node so you can add it to scene. every
 * wyBox2D contains a b2World.
 */
class BOX2D_API wyBox2D : public wyNode {
private:
	/// the world contained by wyBox2D node
	b2World* m_world;

	/// implementation of b2Draw, enabled when \c m_debugDraw set to true
	wyBox2DDebugDraw* m_ddImpl;

	/// true indicating using debug render mode
	bool m_debugDraw;

protected:
	/// constructor
	wyBox2D();

public:
	/// create a box2d node
	static wyBox2D* make();

	/// deconstructor
	virtual ~wyBox2D();

	/// @see wyNode::beforeRender
	virtual void beforeRender();

	/**
	 * get world object pointer, the world object is created when wyBox2D created
	 *
	 * @return b2World pointer
	 */
	b2World* getWorld() { return m_world; }

	/**
	 * get flag of debug draw
	 *
	 * @return debug flag of debug draw, true means debug draw is enabled
	 */
	bool isDebugDraw() { return m_debugDraw; }

	/**
	 * set using debug draw or not
	 *
	 * @param flag true means debug draw should be used
	 */
	void setDebugDraw(bool flag) { m_debugDraw = flag; }

	/**
	 * according to current scale rate, convert pixel to meter
	 *
	 * @param pixel pixel
	 * @return meter
	 */
	float pixel2Meter(float pixel);

	/**
	 * according to current scale rate, convert meter to pixel
	 *
	 * @param meter mter
	 * @return pixel
	 */
	float meter2Pixel(float meter);

	/**
	 * Get pixels in one meter
	 *
	 * @return pixels in one meter
	 */
	float getMeterPixels();

	/**
	 * set how many pixels one meter stands for
	 *
	 * @param mp pixels for one meter
	 */
	void setMeterPixels(float mp);

	/**
	 * get b2Draw implementation pointer
	 *
	 * @return b2Draw implementation
	 */
	b2Draw* getDebugDrawImpl() { return (b2Draw*)m_ddImpl; }
};

#endif // __wyBox2D_h__
