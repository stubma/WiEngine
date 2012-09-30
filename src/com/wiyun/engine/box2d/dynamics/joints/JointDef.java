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
package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;

public abstract class JointDef extends BaseObject {
	public static final int TYPE_UNKNOWN = 0;
	public static final int TYPE_REVOLUTE = 1;
	public static final int TYPE_PRISMATIC = 2;
	public static final int TYPE_DISTANCE = 3;
	public static final int TYPE_PULLEY = 4;
	public static final int TYPE_MOUSE = 5;
	public static final int TYPE_GEAR = 6;
	public static final int TYPE_LINE = 7;
	public static final int TYPE_WELD = 8;
	public static final int TYPE_FRICTION = 9;
	public static final int TYPE_ROPE = 10;
	
	protected JointDef() {
	}

	protected JointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得连接点类型
	 * 
	 * @return 连接点类型
	 */
	public native int getType();
	
	/**
	 * 设置刚体a
	 * 
	 * @param b {@link Body}
	 */
	public native void setBodyA(Body b);
	
	/**
	 * 设置刚体b
	 * 
	 * @param b {@link Body}
	 */
	public native void setBodyB(Body b);
	
	/**
	 * 设置true表示被Joint连接的两个刚体可以产生碰撞
	 * 
	 * @param flag true表示被Joint连接的两个刚体可以产生碰撞
	 */
	public native void setCollideConnected(boolean flag);
	
	/**
	 * 两个刚体是否可以产生碰撞
	 * 
	 * @return true表示两个刚体可以产生碰撞
	 */
	public native boolean isCollideConnected();
	
	/**
	 * 销毁连结点定义对象
	 */
	public native void destroy();
	
	/**
	 * 获得刚体a
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyA() {
		return Body.from(nativeGetBodyA());
	}
	
	private native int nativeGetBodyA();
	
	/**
	 * 获得刚体B
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyB() {
		return Body.from(nativeGetBodyB());
	}
	
	private native int nativeGetBodyB();
}
