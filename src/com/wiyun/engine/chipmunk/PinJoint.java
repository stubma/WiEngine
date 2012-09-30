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
 * 铰链接合，即活动关节点 
 */
public class PinJoint extends Constraint {
	/**
	 * 创建一个活动关节点 
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1 锚点1
	 * @param anchor2 锚点2
	 * @return {@link PinJoint}
	 */
	public static PinJoint make(Body b1, Body b2, WYPoint anchor1, WYPoint anchor2) {
		return make(b1, b2, anchor1.x, anchor1.y, anchor2.x, anchor2.y);
	}
	
	/**
	 * 创建一个活动关节点 
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标
	 * @param anchor2Y 锚点2的y坐标
	 * @return {@link PinJoint}
	 */
	public static PinJoint make(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y) {
		return new PinJoint(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标
	 * @param anchor2Y 锚点2的y坐标
	 */
	protected PinJoint(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y) {
		init(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y);
	}
	
	public static PinJoint from(int pointer) {
		return pointer == 0 ? null : new PinJoint(pointer);
	}
	
	protected PinJoint(int pointer) {
		super(pointer);
	}

	/**
	 * 创建一个活动关节点 
	 * 
	 * @param b1 刚体1
	 * @param b2 刚体2
	 * @param anchor1X 锚点1的x坐标
	 * @param anchor1Y 锚点1的y坐标
	 * @param anchor2X 锚点2的x坐标
	 * @param anchor2Y 锚点2的y坐标
	 */
	private native void init(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y);
	
	/**
	 * 设置连接点的距离
	 * 
	 * @param distance 连接点的距离
	 */
	public native void setDistance(float distance);
	
	/**
	 * 得到连接点的距离
	 * 
	 * @return 连接点的距离
	 */
	public native float getDistance();
	
	/**
	 * 得到锚点1的x位置
	 * 
	 * @return 锚点1的x位置
	 */
	public native float getAnchor1X();
	
	/**
	 * 得到锚点1的y位置
	 * 
	 * @return 锚点1的y位置
	 */
	public native float getAnchor1Y();
	
	/**
	 * 得到锚点1
	 * 
	 * @return 锚点1
	 */
	public WYPoint getAnchor1() {
		return WYPoint.make(getAnchor1X(), getAnchor1Y());
	}
	
	/**
	 * 得到锚点2的x位置
	 * 
	 * @return 锚点2的x位置
	 */
	public native float getAnchor2X();
	
	/**
	 * 得到锚点2的y位置
	 * 
	 * @return 锚点2的y位置
	 */
	public native float getAnchor2Y();
	
	/**
	 * 得到锚点2
	 * 
	 * @return 锚点2
	 */
	public WYPoint getAnchor2() {
		return WYPoint.make(getAnchor2X(), getAnchor2Y());
	}
	
	/**
	 * 设置锚点1
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor1(WYPoint p) {
		setAnchor1(p.x, p.y);
	}
	
	/**
	 * 设置锚点2
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor2(WYPoint p) {
		setAnchor2(p.x, p.y);
	}
	
	/**
	 * 设置锚点1
	 * 
	 * @param x 锚点1的x位置
	 * @param y 锚点1的y位置
	 */
	public native void setAnchor1(float x, float y);
	
	/**
	 * 设置锚点2
	 * 
	 * @param x 锚点2的x位置
	 * @param y 锚点2的y位置
	 */
	public native void setAnchor2(float x, float y);
}
