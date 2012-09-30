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
package com.wiyun.engine.chipmunk;

import static com.wiyun.engine.types.WYPoint.*;

import com.wiyun.engine.chipmunk.Space.SegmentQueryInfo;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;

/**
 * Chipmunk节点。封装了一些Chipmunk的全局逻辑，负责渲染Space 
 */
public class Chipmunk extends Node {
	// layer bit mask
	public static final int GRABABLE_MASK_BIT = 1 << 31;
	public static final int NOT_GRABABLE_MASK = ~GRABABLE_MASK_BIT;
	public static final int CP_ALL_LAYERS = 0xffffffff;
	
	// groups
	public static final int CP_NO_GROUP = 0;
	
	/**
	 * 创建一个Chipmunk节点
	 * 
	 * @return {@link Chipmunk}
	 */
	public static Chipmunk make() {
		return new Chipmunk();
	}
	
	/**
	 * 构造函数
	 */
	protected Chipmunk() {
		nativeInit();
	}
	
    /**
     * 从底层指针获得一个Chipmunk的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Chipmunk}
     */
    public static Chipmunk from(int pointer) {
    	return pointer == 0 ? null : new Chipmunk(pointer);
    }
    
    protected Chipmunk(int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	public Space getSpace() {
		return Space.from(nativeGetSpace());
	}
	
	private native int nativeGetSpace();
	
	/**
	 * 初始化chipmunk, 在使用chipmunk之前必须调用这个方法
	 */
	private native void nativeInit();
	
	/**
	 * 计算一个多边形刚体的转动惯量
	 * 
	 * @param mass 质量
	 * @param verts 多边形刚体的顶点
	 * @param offset 转轴位置
	 * @return 转动惯量
	 */
	public static float calculateMomentForPoly(float mass, WYPoint[] verts, WYPoint offset) {
		int numVerts = verts.length;
		WYPoint[] tVerts = new WYPoint[numVerts];
		for(int i = 0; i < numVerts; i++)
			tVerts[i] = add(verts[i], offset);

		float sum1 = 0.0f;
		float sum2 = 0.0f;
		for(int i = 0; i < numVerts; i++) {
			WYPoint v1 = tVerts[i];
			WYPoint v2 = tVerts[(i + 1) % numVerts];

			float a = cross(v2, v1);
			float b = dot(v1, v1) + dot(v1, v2) + dot(v2, v2);

			sum1 += a * b;
			sum2 += a;
		}

		tVerts = null;
		return (mass * sum1) / (6.0f * sum2);
	}
	
	/**
	 * 计算圆形物体的转动惯量
	 * 
	 * @param mass 质量
	 * @param radiusInner 内圆半径，若不是环形则应该为0
	 * @param radiusOuter 外圆半径
	 * @param offset 转轴位置
	 * @return 转动惯量
	 */
	public static float calculateMomentForCircle(float mass, float radiusInner, float radiusOuter, WYPoint offset) {
		return (1.0f / 2.0f) * mass * (radiusInner * radiusInner + radiusOuter * radiusOuter) + mass * dot(offset, offset);
	}
	
	/**
	 * 计算平面线段物体的转动惯量
	 * 
	 * @param mass 质量
	 * @param a 线段物体的端点
	 * @param b 线段物体的端点
	 * @return 转动惯量
	 */
	public static float calculateMomentForSegment(float mass, WYPoint a, WYPoint b) {
		float length = length(sub(b, a));
		WYPoint offset = mul(add(a, b), 1.0f / 2.0f);

		return mass * length * length / 12.0f + mass * dot(offset, offset);
	}
	
	/**
	 * 根据SegmentQuery查询的结果获得撞击点
	 * 
	 * @param start 线段的起始点
	 * @param end 线段的结束点
	 * @param info 线段查询结果
	 * @return 撞击点坐标
	 */
	public static WYPoint querySegmentHitPoint(WYPoint start, WYPoint end, SegmentQueryInfo info) {
		return lerp(start, end, info.distance);
	}
	
	public static float querySegmentHitDistance(WYPoint start, WYPoint end, SegmentQueryInfo info) {
		return distance(start, end) * info.distance;
	}
	
	/**
	 * 设置是否采用调试渲染模式绘制空间
	 * 
	 * @param debugDraw true表示采用调试渲染模式，调试渲染模式下不显示物体上附加的贴图
	 */
	public native void setDebugDraw(boolean debugDraw);
	
	/**
	 * Apply a damped spring force between two bodies.
	 * Warning: Large damping values can be unstable. Use a cpDampedSpring constraint for this instead.
	 */
	public static native void applyDampedSpring(Body a, Body b, WYPoint anchor1, WYPoint anchor2, float rlen, float k, float dmp, float dt);
}
