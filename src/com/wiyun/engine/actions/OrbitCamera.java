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
package com.wiyun.engine.actions;


/**
 * \if English
 * Camera action, it does animation by changing camera position.
 * \else
 * 轨道镜头动作。可以让视点沿着某条轨迹移动
 * \endif
 */
public class OrbitCamera extends CameraAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration action duration time in second
	 * @param r the initial distance between camera and screen center
	 * @param dr the delta of \c r
	 * @param z the initial angle between z axis and screen normal
	 * @param dz the delta of \c z
	 * @param x the initial angle of x axis
	 * @param dx the delta of \c x
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param r 镜头距离图象中心的距离，称为半径
	 * @param dr 半径在持续时间内变化总量
	 * @param z 动作开始时，镜头到图象中心的连线与z轴的夹角
	 * @param dz z角度的变化总量
	 * @param x x轴的初始倾斜角度
	 * @param dx x轴的总变化角度
	 * \endif
	 */
    public static OrbitCamera make(float duration, float r, float dr, float z, float dz, float x, float dx) {
        return new OrbitCamera(duration, r, dr, z, dz, x, dx);
    }

    /**
     * 构造函数
     * 
     * @param duration 动作持续时间
     * @param r 镜头距离图象中心的距离，称为半径
     * @param dr 半径在持续时间内变化总量
     * @param z 动作开始时，镜头到图象中心的连线与z轴的夹角
     * @param dz z角度的变化总量
     * @param x x轴的初始倾斜角度
     * @param dx x轴的总变化角度
     */
    protected OrbitCamera(float duration, float r, float dr, float z, float dz, float x, float dx) {
    	nativeInit(duration, r, dr, z, dz, x, dx);
    }
    
    /**
     * 从底层指针获得一个OrbitCamera的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link OrbitCamera}
     */
    public static OrbitCamera from(int pointer) {
    	return pointer == 0 ? null : new OrbitCamera(pointer);
    }
    
	protected OrbitCamera(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, float r, float dr, float z, float dz, float x, float dx);

    @Override
	public IntervalAction copy() {
        return new OrbitCamera(nativeCopy());
    }
}
