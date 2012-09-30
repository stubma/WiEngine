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
package com.wiyun.engine.box2d;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.nodes.Node;

/**
 * 对Box2D的节点式封装，使得Box2D可以被当作一个节点被添加到场景中。
 */
public class Box2D extends Node {
	/**
	 * 创建一个Box2D节点
	 * 
	 * @return {@link Chipmunk}
	 */
	public static Box2D make() {
		return new Box2D();
	}
	
	/**
	 * 构造函数
	 */
	protected Box2D() {
		nativeInit();
	}
	
	/**
	 * 初始化box2d, 在使用box2d之前必须调用这个方法
	 */
	private native void nativeInit();
	
    /**
     * 从底层指针获得一个Box2D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Box2D}
     */
    public static Box2D from(int pointer) {
    	return pointer == 0 ? null : new Box2D(pointer);
    }
    
    protected Box2D(int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 得到世界对象指针，世界对象在wyBox2D对象初始化时被创建
	 *
	 * @return b2World对象指针
	 */
	public World getWorld() {
		return World.from(nativeGetWorld());
	}
	
	private native int nativeGetWorld();

	/**
	 * 得到是否是debug draw模式的标志
	 *
	 * @return debug draw模式的标志, true表示是debug draw模式
	 */
	public native boolean isDebugDraw();

	/**
	 * 设置是否debug draw. Debug draw模式下使用简单的线条和色块渲染物体。
	 *
	 * @param flag true表示使用debug draw
	 */
	public native void setDebugDraw(boolean flag);

	/**
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 */
	public native float pixel2Meter(float pixel);

	/**
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 */
	public native float meter2Pixel(float meter);

	/**
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	public native float getMeterPixels();

	/**
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 */
	public native void setMeterPixels(float mp);
	
	/**
	 * 得到底层DebugDraw的实现
	 * 
	 * @return {@link DebugDraw}
	 */
	public DebugDraw getDebugDraw() {
		return DebugDraw.from(nativeGetDebugDraw());
	}
	
	private native int nativeGetDebugDraw();
	
	/**
	 * 设置box2d渲染器, 缺省的{@link Box2DRender}只会渲染有贴图绑定的物体
	 * 
	 * @param render {@link Box2DRender}
	 */
	public native void setBox2DRender(Box2DRender render);
	
	/**
	 * 获得设置的box2d渲染器，如果没有设置，则返回null
	 * 
	 * @return {@link Box2DRender}
	 */
	public Box2DRender getBox2DRender() {
		return Box2DRender.from(nativeGetBox2DRender());
	}
	
	private native int nativeGetBox2DRender();
}
