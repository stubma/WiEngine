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
package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

/**
 * 为{@link Body}提供浮力的模拟
 */
public class BuoyancyController extends Controller {
	/**
	 * 从一个底层指针创建一个{@link BuoyancyController}实例
	 * 
	 * @param pointer 底层指针
	 * @return {@link BuoyancyController}
	 */
	public static BuoyancyController from(int pointer) {
		return pointer == 0 ? null : new BuoyancyController(pointer);
	}
	
	protected BuoyancyController() {
	    super();
    }

	protected BuoyancyController(int pointer) {
	    super(pointer);
    }

	/**
	 * 设置出水面的法线方向 
	 * 
	 * @param x 出水面的法线x方向 
	 * @param y 出水面的法线y方向 
	 */
	public native void setNormal(float x, float y);
	
	/**
	 * 得到出水面的法线
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getNormal() {
		WYPoint n = WYPoint.makeZero();
		nativeGetNormal(n);
		return n;
	}
	
	private native void nativeGetNormal(WYPoint n);
	
	/**
	 * 得到水面在法线方向上的距离
	 * 
	 * @return 水面在法线方向上的距离
	 */
	public native float getOffset();
	
	/**
	 * 设置水面在法线方向上的距离
	 * 
	 * @param offset 水面在法线方向上的距离
	 */
	public native void setOffset(float offset);
	
	/**
	 * 得到水的密度
	 * 
	 * @return 水的密度
	 */
	public native float getDensity();
	
	/**
	 * 设置水的密度
	 * 
	 * @param density 水的密度
	 */
	public native void setDensity(float density);
	
	/**
	 * 设置水的流速
	 * 
	 * @param x 水的x方向流速
	 * @param y 水的y方向流速
	 */
	public native void setVelocity(float x, float y);
	
	/**
	 * 得到水的流速
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getVelocity() {
		WYPoint v = WYPoint.makeZero();
		nativeGetVelocity(v);
		return v;
	}
	
	private native void nativeGetVelocity(WYPoint v);

	/**
	 * 得到物体在水中线性运动时的阻尼系数
	 * 
	 * @return 物体在水中线性运动时的阻尼系数
	 */
	public native float getLinearDrag();
	
	/**
	 * 设置物体在水中线性运动时的阻尼系数
	 * 
	 * @param linearDrag 物体在水中线性运动时的阻尼系数
	 */
	public native void setLinearDrag(float linearDrag);
	
	/**
	 * 得到物体在水中角速度运动时的阻尼系数
	 * 
	 * @return 物体在水中角速度运动时的阻尼系数
	 */
	public native float getAngularDrag();
	
	/**
	 * 设置物体在水中角速度运动时的阻尼系数
	 * 
	 * @param angularDrag 物体在水中角速度运动时的阻尼系数
	 */
	public native void setAngularDrag(float angularDrag);
	
	/**
	 * 是否使用物体本身的密度
	 * 
	 * @return true表示使用物体本身的密度, false表示把所有物体看成具有一个同样的密度
	 */
	public native boolean isUseDensity();
	
	/**
	 * 设置是否使用物体本身的密度
	 * 
	 * @param flag true表示使用物体本身的密度, false表示把所有物体看成具有一个同样的密度
	 */
	public native void setUseDensity(boolean flag);
	
	/**
	 * 是否使用{@link World}中设置的重力
	 * 
	 * @return true表示使用{@link World}中设置的重力, false表示使用setGravity方法设置的重力
	 */
	public native boolean isUseWorldGravity();
	
	/**
	 * 设置是否使用{@link World}中设置的重力
	 * 
	 * @param flag true表示使用{@link World}中设置的重力, false表示使用setGravity方法设置的重力
	 */
	public native void setUseWorldGravity(boolean flag);
	
	/**
	 * 设置重力, 仅当useWorldGravity为true时有效
	 * 
	 * @param x 重力的x值
	 * @param y 重力的y值
	 */
	public native void setGravity(float x, float y);
	
	/**
	 * 得到当前为浮力系统设置的重力, 仅当useWorldGravity为true时有效
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getGravity() {
		WYPoint g = WYPoint.makeZero();
		nativeGetGravity(g);
		return g;
	}
	
	private native void nativeGetGravity(WYPoint g);
}
