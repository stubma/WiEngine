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
package com.wiyun.engine.box2d;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.types.WYColor3F;
import com.wiyun.engine.types.WYPoint;

/**
 * 调试渲染模式对象，可以通过Box2D得到这个对象，其用处只限于调试性的绘制物体。
 */
public class DebugDraw extends BaseObject {
	public static DebugDraw from(int pointer) {
		return pointer == 0 ? null : new DebugDraw(pointer);
	}

	protected DebugDraw() {
	}

	protected DebugDraw(int pointer) {
		super(pointer);
	}
	
	/**
	 * Draw a closed polygon provided in CCW order.
	 */
	public native void drawPolygon(WYPoint[] vertices, WYColor3F color);

	/**
	 * Draw a solid closed polygon provided in CCW order.
	 */
	public native void drawSolidPolygon(WYPoint[] vertices, WYColor3F color);

	/**
	 * Draw a circle.
	 */
	public native void drawCircle(WYPoint center, float radius, WYColor3F color);
	
	/**
	 * Draw a solid circle.
	 */
	public native void drawSolidCircle(WYPoint center, float radius, WYPoint axis, WYColor3F color);
	
	/**
	 * Draw a line segment.
	 */
	public native void drawSegment(WYPoint p1, WYPoint p2, WYColor3F color);

	/**
	 * Draw a transform. Choose your own length scale.
	 */
	public native void drawTransform(Transform xf);

	/**
	 * Draw a point
	 */
	public native void drawPoint(WYPoint p, float size, WYColor3F color);
}
