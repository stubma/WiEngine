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
package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.collision.Shape;

public class FixtureDef extends BaseObject {
	public static FixtureDef make() {
		return new FixtureDef();
	}
	
	protected FixtureDef() {
		nativeNew();
	}

	private native void nativeNew();

	protected FixtureDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * 设置相关形状
	 * 
	 * @param shape {@link Shape}的子类
	 */
	public native void setShape(Shape shape);
	
	/**
	 * 得到形状指针
	 * 
	 * @return 形状指针
	 */
	public native int getShape();
	
	/**
	 * 设置摩擦力
	 * 
	 * @param f 摩擦力
	 */
	public native void setFriction(float f);
	
	/**
	 * 得到摩擦力
	 * 
	 * @return 摩擦力
	 */
	public native float getFriction();
	
	/**
	 * 设置弹性系数
	 * 
	 * @param r 弹性系数
	 */
	public native void setRestitution(float r);
	
	/**
	 * 得到弹性系数
	 * 
	 * @return 弹性系数
	 */
	public native float getRestitution();
	
	/**
	 * 设置密度
	 * 
	 * @param d 密度
	 */
	public native void setDensity(float d);
	
	/**
	 * 得到密度
	 * 
	 * @return 密度
	 */
	public native float getDensity();
	
	/**
	 * 设置是否是sensor
	 * 
	 * @param flag true表示是sensor
	 */
	public native void setSensor(boolean flag);
	
	/**
	 * 检查是否是sensor
	 * 
	 * @return true表示是sensor
	 */
	public native boolean isSensor();
	
	/**
	 * 销毁底层的FixtureDef对象
	 */
	public native void destroy();
	
	/**
	 * 碰撞过滤设置
	 * 
	 * @param categoryBits 物体分类
	 * @param maskBits 物体mask
	 * @param groupIndex 物体分组
	 */
	public native void setFilter(int categoryBits, int maskBits, int groupIndex);
	
	/**
	 * 设置物体碰撞分类
	 * 
	 * @param categoryBits 分类
	 */
	public native void setFilterCategory(int categoryBits);
	
	/**
	 * 设置物体碰撞mask
	 * 
	 * @param maskBits mask
	 */
	public native void setFilterMask(int maskBits);
	
	/**
	 * 设置物体分组
	 * 
	 * @param groupIndex 分组
	 */
	public native void setFilterGroupIndex(int groupIndex);
	
	/**
	 * 得到碰撞过滤设置
	 * 
	 * @return {@link Filter}
	 */
	public Filter getFilter() {
		Filter f = new Filter();
		nativeGetFilter(f);
		return f;
	}
	
	private native void nativeGetFilter(Filter f);
	
	/**
	 * 得到用户自定义数据对象
	 * 
	 * @return {@link Object}
	 */
	public native Object getUserData();
	
	/**
	 * 设置用户自定义数据对象
	 * 
	 * @param obj {@link Object}
	 */
	public native void setUserData(Object obj);
}
