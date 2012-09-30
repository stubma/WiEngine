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
package com.wiyun.engine.opengl;

import com.wiyun.engine.BaseWYObject;


/**
 * 相机逻辑封装。通过修改镜头位置，可以产生不同的视图。 
 */
public class Camera extends BaseWYObject {
	public static Camera make() {
		return new Camera();
	}
	
	/**
	 * 构造函数
	 */
	protected Camera() {
		nativeInit();
	}
	
	private native int nativeInit();
	
	public static Camera from(int pointer) {
		return pointer == 0 ? null : new Camera(pointer);
	}
	
	/**
	 * 构造函数，该方法仅有WiEngine内部调用，开发者不应该使用
	 * 
	 * @param pointer 内部结构指针
	 */
	protected Camera(int pointer) {
		super(pointer);
		restore();
	}
	
	/**
	 * 得到脏标志
	 * 
	 * @return 得到当前的脏标志
	 */
	public native boolean isDirty();

	/**
	 * 设置脏标志
	 * 
	 * @param value true表示镜头需要重新放置
	 */
	public native void setDirty(boolean value);

	/**
	 * 回复到缺省的镜头设置
	 */
	public native void restore();

	/**
	 * 根据当前设置的各种参数放置镜头
	 */
	public native void locate();

	/**
	 * 获得缺省的镜头z位置
	 * 
	 * @return 缺省的镜头z位置
	 */
	public native static float getZEye();

	/**
	 * 设置当前镜头位置
	 * 
	 * @param x 当前镜头x位置
	 * @param y 当前镜头y位置
	 * @param z 当前镜头z位置
	 */
	public native void setEye(float x, float y, float z);

	/**
	 * 设置当前视线中心位置
	 * 
	 * @param x 当前视线中心x位置
	 * @param y 当前视线中心y位置
	 * @param z 当前视线中心z位置
	 */
	public native void setCenter(float x, float y, float z);

	/**
	 * 设置当前正方向位置 
	 * 
	 * @param x 正方向位置的x值
	 * @param y 正方向位置的y值
	 * @param z 正方向位置的z值
	 */
	public native void setUp(float x, float y, float z);

	/**
	 * 获得当前镜头位置
	 * 
	 * @param v 必须是一个长度为3的浮点数组
	 */
	public native void getEye(float[] v);

	/**
	 * 获得当前视线中心位置
	 * 
	 * @param v 必须是一个长度为3的浮点数组
	 */
	public native void getCenter(float[] v);

	/**
	 * 获得当前正方向位置
	 * 
	 * @param v 必须是一个长度为3的浮点数组
	 */
	public native void getUp(float[] v);
}
