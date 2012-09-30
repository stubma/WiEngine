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

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.World;

/**
 * 其它控制器的基类. 控制器是Box2D中的扩展模块, 用来封装一些常用的功能.
 */
public abstract class Controller extends BaseObject {
	protected Controller() {
	}

	protected Controller(int pointer) {
		super(pointer);
	}

	/**
	 * 添加一个{@link Body}到{@link Controller}
	 * 
	 * @param body {@link Body}
	 */
	public native void addBody(Body body);

	/**
	 * 从{@link Controller}删除一个{@link Body}
	 * 
	 * @param body {@link Body}
	 */
	public native void removeBody(Body body);

	/**
	 * 删除{@link Controller}中所有的{@link Body}
	 */
	public native void clear();

	/**
	 * 获得下一个{@link Controller}的底层指针
	 * 
	 * @return {@link Controller}的底层指针, 可以通过具体子类的from方法得到java端实例
	 */
	public native int getNext();

	/**
	 * 获得{@link World}的底层指针
	 * 
	 * @return {@link World}的底层指针, 可以通过from方法得到java端实例
	 */
	public native int getWorld();

	/**
	 * 得到第一个{@link ControllerEdge}的底层指针
	 * 
	 * @return 第一个{@link ControllerEdge}的底层指针, 可以通过from方法得到java端实例
	 */
	public native int getBodyList();
}
