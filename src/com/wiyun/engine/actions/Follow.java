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

import com.wiyun.engine.nodes.Node;


/**
 * \if English
 * An action that "follows" a node
 * \else
 * 跟踪一个节点, 让屏幕内容跟随节点的移动
 * \endif
 */
public class Follow extends Action {
	/**
	 * \if English
	 * Static Constructor
	 *
	 * @param fNode node to follow
	 * @return \link Follow Follow\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param fNode 要跟踪的\link Node Node\endlink节点
	 * @return \link Follow Follow\endlink
	 * \endif
	 */
    public static Follow make(Node fNode) {
        return new Follow(fNode, 0, 0, 0, 0);
    }
    
	/**
	 * \if English
	 * Static Constructor
	 *
	 * @param fNode node to follow
     * @param x tracking box x position in global coordinates
     * @param y tracking box y position in global coordinates
     * @param w width of tracking box
     * @param h height of tracking box
	 * @return \link Follow Follow\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param fNode 要跟踪的\link Node Node\endlink节点
     * @param x 跟踪范围的x坐标, 全局坐标
     * @param y 跟踪范围的y坐标, 全局坐标
     * @param w 跟踪范围的宽度
     * @param h 跟踪范围的高度
	 * @return \link Follow Follow\endlink
	 * \endif
	 */
    public static Follow make(Node fNode, int x, int y, int w, int h) {
    	return new Follow(fNode, x, y, w, h);
    }

    protected Follow(Node fNode, int x, int y, int w, int h) {
    	nativeInit(fNode, x, y, w, h);
    }

    public static Follow from(int pointer) {
    	return pointer == 0 ? null : new Follow(pointer);
    }
    
    public Follow(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(Node fnode, int x, int y, int w, int h);

}
