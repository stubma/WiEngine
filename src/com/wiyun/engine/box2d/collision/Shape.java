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

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

public abstract class Shape extends BaseObject {
	public static final int TYPE_UNKNOWN = -1;
	public static final int TYPE_CIRCLE = 0;
	public static final int TYPE_EDGE = 1;
	public static final int TYPE_POLYGON = 2;
	public static final int TYPE_LOOP = 3;
	
	protected Shape() {
	}

	protected Shape(int pointer) {
		super(pointer);
	}

	/**
	 * 生成当前shape的拷贝
	 * 
	 * @param world {@link World}
	 * @return 生成的shape的指针, 可以用shape的子类包装成java端对象
	 */
	protected native int copy(World world);
	
	/**
	 * Get the type of this shape. You can use this to down cast to the concrete shape.
	 * @return the shape type.
	 */
	public native int getType();
	
	/**
	 * 设置shape类型
	 * 
	 * @param type 类型
	 */
	public native void setType(int type);
	
	/**
	 * 设置半径
	 * 
	 * @param r 半径
	 */
	public native void setRadius(float r);
	
	/**
	 * 获得半径
	 * 
	 * @return 半径
	 */
	public native float getRadius();

	/**
	 * Get the number of child primitives.
	 */
	public native int getChildCount();
	
	/**
	 * Test a point for containment in this shape. This only works for convex shapes.
	 * 
	 * @param xf the shape world transform.
	 * @param p a point in world coordinates.
	 */
	public native boolean testPoint(Transform xf, WYPoint p);
	
	/**
	 * 对shape做一个光线测试
	 * 
	 * @param input {@link RayCastInput}
	 * @param trans {@link Transform}
	 * @param childIndex child index
	 * @return {@link RayCastOutput}
	 */
	public RayCastOutput rayCast(RayCastInput input, Transform trans, int childIndex) {
		RayCastOutput o = new RayCastOutput();
		nativeRayCast(o, input, trans, childIndex);
		return o;
	}
	
	private native void nativeRayCast(RayCastOutput output, RayCastInput input, Transform trans, int childIndex);
	
	/**
	 * Given a transform, compute the associated axis aligned bounding box for a child shape.
	 * 
	 * @param xf the world transform of the shape.
	 * @param childIndex the child shape
	 * @return {@link AABB}
	 */
	public AABB computeAABB(Transform xf, int childIndex) {
		AABB ab = new AABB();
		nativeComputeAABB(ab, xf, childIndex);
		return ab;
	}
	
	private native void nativeComputeAABB(AABB aabb, Transform xf, int childIndex);
	
	/**
	 * Compute the mass properties of this shape using its dimensions and density.
	 * The inertia tensor is computed about the local origin.
	 * 
	 * @param density the density in kilograms per meter squared.
	 * @return {@link MassData}
	 */
	public MassData computeMass(float density) {
		MassData d = new MassData();
		nativeComputeMass(d, density);
		return d;
	}
	
	private native void nativeComputeMass(MassData d, float density);
}
