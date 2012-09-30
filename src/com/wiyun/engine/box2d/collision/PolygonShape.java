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

public class PolygonShape extends Shape {
	public static PolygonShape from(int pointer) {
		return pointer == 0 ? null : new PolygonShape(pointer);
	}
	
	public static PolygonShape make() {
		return new PolygonShape();
	}

	protected PolygonShape() {
		nativeNew();
	}

	private native void nativeNew();

	protected PolygonShape(int pointer) {
		super(pointer);
	}
	
	public PolygonShape clone(World world) {
		return PolygonShape.from(super.copy(world));
	}
	
	/**
	 * 设置顶点
	 * 
	 * @param vertices 顶点数组
	 */
	public native void setVertices(WYPoint[] vertices);
	
	/**
	 * 设置为一个矩形
	 * 
	 * @param x 宽的一半
	 * @param y 高的一半
	 */
	public native void setAsBox(float x, float y);
	
	/**
	 * 设置为一个矩形
	 * 
	 * @param x 宽的一半
	 * @param y 高的一半
	 * @param centerX 矩形中心x
	 * @param centerY 矩形中心y
	 * @param angle 矩形的自身旋转角度, 以弧度为单位
	 */
	public native void setAsBox(float x, float y, float centerX, float centerY, float angle);
	
	/**
	 * 得到多边形的顶点个数
	 * 
	 * @return 多边形的顶点个数
	 */
	public native int getVertexCount();
	
	/**
	 * 得到某个顶点
	 * 
	 * @param index 顶点的索引
	 */
	public WYPoint getVertex(int index) {
		WYPoint p = WYPoint.makeZero();
		nativeGetVertex(p, index);
		return p;
	}
	
	private native void nativeGetVertex(WYPoint p, int index);
	
	/**
	 * 得到重心位置
	 * 
	 * @return 重心位置
	 */
	public WYPoint getCentroid() {
		WYPoint p = WYPoint.makeZero();
		nativeGetCentroid(p);
		return p;
	}
	
	private native void nativeGetCentroid(WYPoint p);
	
	/**
	 * Validate convexity. This is a very time consuming operation.
	 * 
	 * @returns true if valid
	 */
	public native boolean validate();
}
