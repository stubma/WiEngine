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

import com.wiyun.engine.types.WYPoint;


/**
 * \if English
 * Move a node in a specified path
 * \else
 * 在一个指定的路径上移动节点，路径由若干个点构成
 * \endif
 */
public class MoveByPath extends IntervalAction {
    public static MoveByPath make() {
        return new MoveByPath();
    }

    protected MoveByPath() {
    	nativeInit();
    }
    
    private native void nativeInit();

    public static MoveByPath from(int pointer) {
    	return pointer == 0 ? null : new MoveByPath(pointer);
    }
    
    protected MoveByPath(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new MoveByPath(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new MoveByPath(nativeReverse());
    }
    
	/**
	 * \if English
	 * add a point to path
	 *
	 * @param x x position
	 * @param y y position
	 * @param duration move time between this point and previous point, it will be neglected if it is first point
	 * \else
	 * 添加一个路径点
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param duration 这个点和上一个点之间，移动的持续时间。如果这是第一个点，这个参数将被忽略
	 * \endif
	 */
	public native void addPoint(float x, float y, float duration);
	
	/**
	 * \if English
	 * Get point count in path
	 * \else
	 * 得到路径上的点个数
	 * \endif
	 */
	public native int getPointCount();

	/**
	 * 获得点的位置数组，偶数位置是x坐标，奇数位置是y坐标
	 * 
	 * @return 浮点数组
	 */
	public native float[] getPoints();
	
	/**
	 * \if English
	 * Enable auto rotate, it means the node move by path will be aligned
	 * with path direction.
	 *
	 * @param flag true means enable auto rotate
	 * @param angleDelta the delta to be added to path direction. Position value means
	 * 		clockwise, negative value means counter-clockwise
	 * \else
	 * 是否打开自动旋转，打开自动旋转表示移动的节点会自动保持和路径方向一致.
	 *
	 * @param flag true表示打开自动旋转
	 * @param angleDelta 预设的角度，假如是-90，而当前路径的朝向是180度，那么最终节点将被设置为90度.
	 * 		这里正值表示顺时针旋转，负值表示逆时针旋转
	 * \endif
	 */
	public native void setAutoRotate(boolean flag, float angleDelta);
	
	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param p global coordinate of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
	 *
	 * @param p pin point的全局坐标
	 * \endif
	 */
	public void setPinPoint(WYPoint p) {
		setPinPoint(p.x, p.y);
	}

	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
	 *
	 * @param x pin point的全局x位置
	 * @param y pin point的全局y位置
	 * \endif
	 */
	public native void setPinPoint(float x, float y);

	/**
	 * \if English
	 * get pin point
	 *
	 * @return global coordinate of pin point
	 * \else
	 * 得到pin point
	 *
	 * @return pin point的全局坐标
	 * \endif
	 */
	public WYPoint getPinPoint() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPinPoint(p);
		return p;
	}
	
	private native void nativeGetPinPoint(WYPoint p);

	/**
	 * \if English
	 * clear pin point
	 * \else
	 * 清除掉pin point, 这样节点移动时将不再自动对准pin point
	 * \endif
	 */
	public native void clearPinPoint();

	/**
	 * \if English
	 * set angle delta of pin point rotation
	 *
	 * @param angle to be added to node rotation
	 * \else
	 * 设置附加角度, 仅当pin point被设置时有效
	 *
	 * @param delta 附加角度
	 * \endif
	 */
	public native void setPinAngleDelta(float delta);

	/**
	 * \if English
	 * get angle delta
	 *
	 * @return angle delta
	 * \else
	 * 得到附加角度
	 *
	 * @return 附加角度
	 * \endif
	 */
	public native float getPinAngleDelta();
}
