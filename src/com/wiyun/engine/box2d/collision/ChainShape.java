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

/**
 * A chain shape is a free form sequence of line segments.
 * The chain has two-sided collision, so you can use inside and outside collision.
 * Therefore, you may use any winding order.
 * Since there may be many vertices, they are allocated using b2Alloc.
 * Connectivity information is used to create smooth collisions.
 * WARNING: The chain will not collide properly if there are self-intersections.
 */
public class ChainShape extends Shape {
	public static ChainShape from(int pointer) {
		return pointer == 0 ? null : new ChainShape(pointer);
	}
	
	public static ChainShape make() {
		return new ChainShape();
	}
	
	protected ChainShape() {
		nativeNew();
	}

	protected ChainShape(int pointer) {
		super(pointer);
	}
	
	private native void nativeNew();
	
	public ChainShape clone(World world) {
		return ChainShape.from(super.copy(world));
	}
	
	/**
	 * Create a loop. This automatically adjusts connectivity.
	 * 
	 * @param vertices an array of vertices
	 */
	public native void createLoop(WYPoint[] vertices);
	
	/**
	 * Create a chain with isolated end vertices.
	 * 
	 * @param vertices an array of vertices
	 */
	public native void createChain(WYPoint[] vertices);

	/**
	 * Establish connectivity to a vertex that precedes the first vertex.
	 * Don't call this for loops.
	 */
	public native void SetPrevVertex(WYPoint prevVertex);

	/**
	 * Establish connectivity to a vertex that follows the last vertex.
	 * Don't call this for loops.
	 */
	public native void SetNextVertex(WYPoint nextVertex);
	
	/**
	 * Get previous vertex
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getPrevVertex() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPrevVertex(p);
		return p;
	}
	
	private native void nativeGetPrevVertex(WYPoint p);
	
	/**
	 * Get next vertex
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getNextVertex() {
		WYPoint p = WYPoint.makeZero();
		nativeGetNextVertex(p);
		return p;
	}
	
	private native void nativeGetNextVertex(WYPoint p);
	
	/**
	 * Has previous vertex?
	 * 
	 * @return true means it has
	 */
	public native boolean hasPrevVertex();
	
	/**
	 * Has next vertex
	 * 
	 * @return true means it has
	 */
	public native boolean hasNextVertex();

	/**
	 * Get a child edge. Caller should release returned shape when not used.
	 */
	public EdgeShape getChildEdge(int index) {
		return EdgeShape.from(nativeGetChildEdge(index));
	}
	
	private native int nativeGetChildEdge(int index);
	
	/**
	 * 得到顶点个数
	 * 
	 * @return 顶点个数
	 */
	public native int getCount();
	
	/**
	 * 得到指定顶点
	 * 
	 * @param index 顶点索引位置
	 * @return {@link WYPoint}
	 */
	public WYPoint getVertex(int index) {
		WYPoint p = WYPoint.makeZero();
		nativeGetVertex(p, index);
		return p;
	}
	
	private native void nativeGetVertex(WYPoint p, int index);
	
	/**
	 * Get the vertices, the vertices data is copied from native layer so
	 * change them doesn't affect native layer
	 * 
	 * @return {@link WYPoint} array
	 */
	public WYPoint[] getVertices() {
		WYPoint[] vertices = new WYPoint[getCount()];
		nativeGetVertices(vertices);
		return vertices;
	}
	
	private native void nativeGetVertices(WYPoint[] vertices);
}
