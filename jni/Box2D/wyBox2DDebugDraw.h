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
#ifndef __wyBox2DDebugDraw_h__
#define __wyBox2DDebugDraw_h__

#include <Box2D/Box2D.h>

class wyBox2D;

/**
 * Debug draw interface implementation
 */
class wyBox2DDebugDraw : public b2Draw {
private:
	/// how many pixels for one meter in box2d, by default we treat short edge of screen as 20 meters
	float m_meterPixels;

	/// box2d node
	wyBox2D* m_box2d;

public:
	wyBox2DDebugDraw(wyBox2D* box2d);

	virtual ~wyBox2DDebugDraw() {}

	/// Draw a closed polygon provided in CCW order.
	virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	/// Draw a solid closed polygon provided in CCW order.
	virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	/// Draw a circle.
	virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

	/// Draw a solid circle.
	virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

	/// Draw a line segment.
	virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	virtual void DrawTransform(const b2Transform& xf);

	/// Draw a point
	virtual void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

	/**
	 * Get pixels mapped to one meter
	 */
	float getMeterPixels() { return m_meterPixels; }

	/**
	 * Set how many pixels mapped to one meter
	 */
	void setMeterPixels(float mp) { m_meterPixels = mp; }

	/**
	 * Convert pixel to meter based on current one meter pixel setting
	 *
	 * @param pixel pixel
	 * @return meter
	 */
	float pixel2Meter(float pixel) { return pixel / m_meterPixels; }

	/**
	 * Convert meter to pixel based on current one meter pixel setting
	 *
	 * @param meter meter
	 * @return pixel
	 */
	float meter2Pixel(float meter) { return meter * m_meterPixels; }
};

#endif // __wyBox2DDebugDraw_h__
