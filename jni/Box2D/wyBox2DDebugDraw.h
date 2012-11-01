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

/**
 * Debug draw interface implementation
 */
class wyBox2DDebugDraw : public b2Draw {
private:
	/// how many pixels for one meter in box2d, by default we treat short edge of screen as 20 meters
	float m_meterPixels;

public:
	wyBox2DDebugDraw();
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
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	float getMeterPixels() { return m_meterPixels; }

	/**
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 */
	void setMeterPixels(float mp) { m_meterPixels = mp; }

	/**
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 */
	float pixel2Meter(float pixel) { return pixel / m_meterPixels; }

	/**
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 */
	float meter2Pixel(float meter) { return meter * m_meterPixels; }
};

#endif // __wyBox2DDebugDraw_h__
