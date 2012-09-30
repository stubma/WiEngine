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
package com.wiyun.engine.box2d.common;

import android.util.FloatMath;

import com.wiyun.engine.types.WYPoint;

public class Matrix22 {
	public float col1X;
	public float col1Y;
	public float col2X;
	public float col2Y;
	
	public static Matrix22 makeZero() {
		return new Matrix22(0, 0, 0, 0);
	}
	
	public static Matrix22 make(float col1X, float col1Y, float col2X, float col2Y) {
		return new Matrix22(col1X, col1Y, col2X, col2Y);
	}
	
	protected Matrix22(float col1X, float col1Y, float col2X, float col2Y) {
		this.col1X = col1X;
		this.col1Y = col1Y;
		this.col2X = col2X;
		this.col2Y = col2Y;
	}
	
	public void set(float angle) {
		float c = FloatMath.cos(angle);
		float s = FloatMath.sin(angle);
		col1X = c; 
		col2X = -s;
		col1Y = s;
		col2Y = c;
	}
	
	public WYPoint mul(WYPoint v) {
		return WYPoint.make(col1X * v.x + col2X * v.y, col1Y * v.x + col2Y * v.y);
	}
}
