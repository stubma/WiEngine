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

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * Renderer of box2d. It can bind texture to fixture and render it. This is a simple
 * way but not a high performance way.
 * \else
 * Box2D的渲染器, 通过这个类可以为物体绑定贴图, 绑定的贴图将被这个渲染器所渲染. 这是一种较为
 * 省事的方式, 但性能并不好.
 * \endif
 */
public class Box2DRender extends BaseWYObject {
	public static Box2DRender make() {
		return new Box2DRender();
	}
	
	public static Box2DRender from(int pointer) {
		return pointer == 0 ? null : new Box2DRender(pointer);
	}
	
	protected Box2DRender() {
		nativeInit();
	}
	
	protected Box2DRender(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
	
	/**
	 * 给某个fixture绑定一个贴图
	 *
	 * @param f {@link Fixture}对象
	 * @param tex {@link Texture2D}对象, 如果为NULL， 则是取消之前的绑定
	 */
	public native void bindTexture(Fixture f, Texture2D tex);

	/**
	 * 给某个fixture绑定一个贴图
	 *
	 * @param f {@link Fixture}对象
	 * @param tex {@link Texture2D}对象, 如果为NULL， 则是取消之前的绑定
	 * @param rect {@link WYRect}
	 */
	public native void bindTexture(Fixture f, Texture2D tex, WYRect rect);
}
