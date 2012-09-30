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
package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYVertex3D;

/**
 * 3维网格动作的基类。 网格类动作需要Android 2.2以上支持
 */
public abstract class Grid3DAction extends GridAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected Grid3DAction(float duration, WYGridSize gSize) {
	}
	
	protected Grid3DAction() {
	}
	
	protected Grid3DAction(int pointer) {
		super(pointer);
	}

	/**
	 * 获得指定位置的顶点坐标
	 * 
	 * @param pos 顶点行列坐标
	 * @return {@link WYVertex3D}对象
	 */
	public WYVertex3D getVertex(WYGridSize pos) {
		WYVertex3D vertex = WYVertex3D.makeZero();
		getVertex(pos.x, pos.y, vertex);
		return vertex;
	}
	
	private native void getVertex(int x, int y, WYVertex3D vertex);

	/**
	 * 获得指定位置的原始顶点坐标
	 * 
	 * @param pos 顶点行列坐标
	 * @return {@link WYVertex3D}对象
	 */
	public WYVertex3D getOriginalVertex(WYGridSize pos) {
		WYVertex3D vertex = WYVertex3D.makeZero();
		getOriginalVertex(pos.x, pos.y, vertex);
		return vertex;
	}
	
	private native void getOriginalVertex(int x, int y, WYVertex3D vertex);

	/**
	 * 设置指定位置的顶点坐标
	 * 
	 * @param pos 顶点行列坐标
	 * @param vertex 顶点坐标对象
	 */
	public void setVertex(WYGridSize pos, WYVertex3D vertex) {
		setVertex(pos.x, pos.y, vertex.x, vertex.y, vertex.z);
	}
	
	private native void setVertex(int x, int y, float vx, float vy, float vz);
	
	@Override
	public abstract Grid3DAction copy();
}
