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

import com.wiyun.engine.types.WYPoint;

/**
 * A transform contains translation and rotation. It is used to represent
 * the position and orientation of rigid frames.
 */
public class Transform {
	public Rotation q;
	public WYPoint p;
	
	public static Transform make() {
		return new Transform();
	}
	
	protected Transform() {
		q = Rotation.makeIdentity();
		p = WYPoint.makeZero();
	}
	
	public void setIdentity() {
		q = Rotation.makeIdentity();
		p = WYPoint.makeZero();
	}
	
	public void set(float x, float y, float angle) {
		p.x = x;
		p.y = y;
		q.set(angle);
	}
	
	public void set(WYPoint position, float angle) {
		p.x = position.x;
		p.y = position.y;
		q.set(angle);
	}
	
	public WYPoint mul(WYPoint v) {
		float x = (q.c * v.x - q.s * v.y) + p.x;
		float y = (q.s * v.x + q.c * v.y) + p.y;

		return WYPoint.make(x, y);
	}
}
