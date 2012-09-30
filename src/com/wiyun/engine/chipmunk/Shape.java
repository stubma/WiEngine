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

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;

/**
 * 带形状的物体基类 
 */
public class Shape {
	// underlying cpShape or other shape struct pointer
	int mPointer;
	
	public static Shape from(int pointer) {
		return pointer == 0 ? null : new Shape(pointer);
	}
	
	/**
	 * 构造函数 
	 */
	protected Shape(Body body) {
	}
	
	protected Shape(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof Shape)
			return ((Shape)o).mPointer == mPointer;
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
	
	/**
	 * 在物体上设置一个附加数据对象
	 */
	public native void setData(Object data);
	
	/**
	 * 在当前物体上开始一个动画效果
	 * 
	 * @param anim {@link ShapeAnimation}
	 */
	public void startAnimation(ShapeAnimation anim) {
		anim.start(this);
	}
	
	/**
	 * 停止当前的动画效果，如果有的话
	 */
	public native void clearAnimation();
	
	/**
	 * 重置物体的内部id计数器
	 */
	public static native void resetShapeIdCounter();
	
	/**
	 * 得到关联的刚体
	 * 
	 * @return {@link Body}
	 */
	public Body getBody() {
		return Body.from(nativeGetBody());
	}
	
	private native int nativeGetBody();
	
	/**
	 * 销毁底层占据的资源
	 */
	public native void destroy();
	
	/**
	 * 设置弹性系数
	 * 
	 * param restitution 弹性系数
	 */
	public native void setRestitution(float restitution);
	
	/**
	 * 设置摩擦系数
	 * 
	 * @param friction 摩擦系数
	 */
	public native void setFriction(float friction);
	
	/**
	 * 设置层mask
	 * 
	 * @param mask mask bit
	 */
	public native void setLayerMask(int mask);
	
	/**
	 * 得到层mask
	 * 
	 * @return mask bit
	 */
	public native int getLayerMask();
	
	/**
	 * 获得物体上附加的数据对象
	 * 
	 * @return 附加数据对象
	 */
	public native Object getData();
	
	/**
	 * 设置碰撞类型
	 * 
	 * @param type 碰撞类型，自定义的数值
	 */
	public native void setCollisionType(int type);
	
	/**
	 * 获得碰撞类型
	 * 
	 * @return 碰撞类型
	 */
	public native int getCollisionType();
	
	/**
	 * 设置表面速度
	 * 
	 * @param xVel 表面速度的x分量
	 * @param yVel 表面速度的y分量
	 */
	public native void setSurfaceVelocity(float xVel, float yVel);
	
	/**
	 * 得到物体的表面速度
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getSurfaceVelocity() {
		return WYPoint.make(getSurfaceVelocityX(), getSurfaceVelocityY());
	}
	
	/**
	 * 得到表面速度的x分量
	 * 
	 * @return 表面速度的x分量
	 */
	public native float getSurfaceVelocityX();
	
	/**
	 * 得到表面速度的y分量
	 * 
	 * @return 表面速度的y分量
	 */
	public native float getSurfaceVelocityY();
	
	/**
	 * 设置物体所在组
	 * 
	 * @param group 组id
	 */
	public native void setGroup(int group);
	
	/**
	 * 得到物体所在的组
	 * 
	 * @return 组id
	 */
	public native int getGroup();
	
	/**
	 * 强制更新边框矩形以便保证碰撞检测正确
	 */
	public native void updateBoundingBox();
	
	/**
	 * 得到标志表示物体是否是传感器
	 * 
	 * @return 物体是否是传感器
	 */
	public native boolean isSensor();
	
	/**
	 * 设置物体是否是传感器，一个传感器不会产生碰撞事件
	 * 
	 * @param sensor true表示把该物体设置为传感器
	 */
	public native void setIsSensor(boolean sensor);
	
	/**
	 * 获得贴图对象
	 * 
	 * @return {@link Texture2D}
	 */
	public Texture2D getTexture() {
		return Texture2D.from(nativeGetTexture());
	}
	
	private native int nativeGetTexture();

	/**
	 * 设置贴图对象
	 * 
	 * @param tex {@link Texture2D}
	 */
	public void setTexture(Texture2D tex) {
		setTexture(tex, false);
	}
	
	/**
	 * 设置贴图对象
	 * 
	 * @param tex {@link Texture2D}
	 * @param autoSize true表示把物体更新到和贴图一样大，注意如果为true，则这个操作属于不安全操作，所以要确保
	 * 		不要在空间的step方法中调用，可以通过PostStepCallback的方式调用
	 */
	public native void setTexture(Texture2D tex, boolean autoSize);
	
	/**
	 * 设置图片集贴图
	 * 
	 * @param tex 图片集
	 * @param rect 图片集中的相应位置，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
	 */
	public void setTexture(Texture2D tex, WYRect rect) {
		setTexture(tex, rect, false);
	}
	
	/**
	 * 设置图片集贴图
	 * 
	 * @param tex {@link Texture2D}
	 * @param rect 单幅图片在图片集中的位置矩形，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
	 * @param autoSize true表示把物体更新到和贴图一样大，注意如果为true，则这个操作属于不安全操作，所以要确保
	 * 		不要在空间的step方法中调用，可以通过PostStepCallback的方式调用
	 */
	public native void setTexture(Texture2D tex, WYRect rect, boolean autoSize);
	
	/**
	 * 设置图片集中的贴图位置，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
	 * 
	 * @param rect {@link WYRect}
	 */
	public native void setTextureRect(WYRect rect);
	
	/**
	 * 得到物体的边框矩形，坐标是相对于全局的。由于物体有旋转等效果，所以
	 * 这个边框矩形是可能随时变化的。返回的坐标会受到Chipmunk位置的影响。
	 * 
	 * @param rect {@link WYRect}对象，origin表示物体的左下角
	 */
	public native void getBoundingBox(WYRect rect);
}
