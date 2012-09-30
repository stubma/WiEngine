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

public class EdgeShape extends Shape {
	public static EdgeShape from(int pointer) {
		return pointer == 0 ? null : new EdgeShape(pointer);
	}
	
	public static EdgeShape make() {
		return new EdgeShape();
	}
	
	protected EdgeShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected EdgeShape(int pointer) {
		super(pointer);
	}
	
	public EdgeShape clone(World world) {
		return EdgeShape.from(super.copy(world));
	}
	
	/**
	 * 设置线形物体的端点
	 * 
	 * @param x1 端点1坐标x值
	 * @param y1 端点1坐标y值
	 * @param x2 端点2坐标x值
	 * @param y2 端点2坐标y值
	 */
	public native void setEndpoints(float x1, float y1, float x2, float y2);
	
	/**
	 * 获得端点1
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getEndpoint1() {
		WYPoint p = WYPoint.makeZero();
		nativeGetEndpoint1(p);
		return p;
	}
	
	private native void nativeGetEndpoint1(WYPoint p);
	
	/**
	 * 获得端点2
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getEndpoint2() {
		WYPoint p = WYPoint.makeZero();
		nativeGetEndpoint2(p);
		return p;
	}
	
	private native void nativeGetEndpoint2(WYPoint p);
	
	public native boolean hasAdjacentVertex1();
	
	public native boolean hasAdjacentVertex2();
	
	public WYPoint getAdjacentVertex1() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAdjacentVertex1(p);
		return p;
	}
	
	private native void nativeGetAdjacentVertex1(WYPoint p);
	
	public WYPoint getAdjacentVertex2() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAdjacentVertex2(p);
		return p;
	}
	
	private native void nativeGetAdjacentVertex2(WYPoint p);
}
