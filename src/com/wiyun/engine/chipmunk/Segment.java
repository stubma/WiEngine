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

import com.wiyun.engine.types.WYPoint;

/**
 * 一个平面物体, 可以有厚度 
 */
public class Segment extends Shape {
	/**
	 * 创建segment实例
	 * 
	 * @param body 相关的刚体
	 * @param start 起始点
	 * @param end 结束点
	 * @param thickness 厚度
	 * @return {@link Segment}
	 */
	public static Segment make(Body body, WYPoint start, WYPoint end, float thickness) {
		return make(body, start.x, start.y, end.x, end.y, thickness);
	}
	
	/**
	 * 创建segment实例
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 * @return {@link Segment}
	 */
	public static Segment make(Body body, float startX, float startY, float endX, float endY, float thickness) {
		return new Segment(body, startX, startY, endX, endY, thickness);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 */
	protected Segment(Body body, float startX, float startY, float endX, float endY, float thickness) {
		super(body);
		init(body, startX, startY, endX, endY, thickness);
	}
	
	/**
	 * 初始化Segment
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 */
	private native void init(Body body, float startX, float startY, float endX, float endY, float thickness);
	
	/**
	 * 设置线段物体的端点
	 * 
	 * @param a 端点a
	 * @param b 端点b
	 */
	public void setEndpoints(WYPoint a, WYPoint b) {
		setEndpoints(a.x, a.y, b.x, b.y);
	}
	
	/**
	 * 设置线段物体的端点，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param aX 端点a的x位置
	 * @param aY 端点a的y位置
	 * @param bX 端点b的x位置
	 * @param bY 端点b的y位置
	 */
	public native void setEndpoints(float aX, float aY, float bX, float bY);
	
	/**
	 * 获得线段物体的原始端点，这个方法返回的坐标是相对于刚体的
	 * 
	 * @param endpoints 必须是一个长度为2的{@link WYPoint}数组
	 */
	public native void getEndpoints(WYPoint[] endpoints);
	
	/**
	 * 获得线段物体的法线，这个法线是针对原始端点的，如果端点不变则它也不变。
	 * 这个方法返回的坐标是相对于刚体的
	 * 
	 * @param normal {@link WYPoint}
	 */
	public native void getNormal(WYPoint normal);
	
	/**
	 * 获得线段物体的当前端点，这个方法返回的坐标是相对于全局的
	 * 
	 * @param endpoints 必须是一个长度为2的{@link WYPoint}数组
	 */
	public native void getTransformedEndpoints(WYPoint[] endpoints);
	
	/**
	 * 获得线段物体的当前法线，这个法线是针对当前端点的，因此可能是变化的。
	 * 这个方法返回的坐标是相对于全局的
	 * 
	 * @param normal {@link WYPoint}
	 */
	public native void getTransformedNormal(WYPoint normal);
	
	/**
	 * 设置线段物体的厚度，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param thickness 厚度
	 */
	public native void setThickness(float thickness);
	
	/**
	 * 获得线段物体的厚度
	 * 
	 * @return 线段物体的厚度
	 */
	public native float getThickness();
}
