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
package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

public class CircleShape extends Shape {
	public static CircleShape from(int pointer) {
		return pointer == 0 ? null : new CircleShape(pointer);
	}
	
	public static CircleShape make() {
		return new CircleShape();
	}

	protected CircleShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected CircleShape(int pointer) {
		super(pointer);
	}
	
	public CircleShape clone(World world) {
		return CircleShape.from(super.copy(world));
	}
	
	/**
	 * 设置圆心位置
	 * 
	 * @param x x位置
	 * @param y y位置
	 */
	public native void setPosition(float x, float y);

	/**
	 * 获得圆心位置
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getPosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPosition(p);
		return p;
    }
	
	private native void nativeGetPosition(WYPoint p);
	
	/**
	 * Get the supporting vertex index in the given direction.
	 */
	public int getSupport(WYPoint d) {
		return getSupport(d.x, d.y);
	}
	
	/**
	 * Get the supporting vertex index in the given direction.
	 */
	public native int getSupport(float x, float y);
	
	/**
	 * Get the supporting vertex in the given direction.
	 */
	public WYPoint getSupportVertex(WYPoint d) {
		return getSupportVertex(d.x, d.y);
	}
	
	/**
	 * Get the supporting vertex in the given direction.
	 */
	public WYPoint getSupportVertex(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetSupportVertex(p, x, y);
		return p;
	}
	
	private native void nativeGetSupportVertex(WYPoint p, float x, float y);
	
	/**
	 * Get the vertex count.
	 */
	public native int getVertexCount();
	
	/**
	 * Get a vertex by index. Used by b2Distance.
	 */
	public WYPoint getVertex(int index) {
		WYPoint p = WYPoint.makeZero();
		nativeGetVertex(p, index);
		return p;
	}
	
	private native void nativeGetVertex(WYPoint p, int index);
}
