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

import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * Result of collision detection
 * \else
 * 碰撞检测的结果
 * \endif
 */
public class CDResult {
	/**
	 * \if English
	 * collision point count
	 * \else
	 * 碰撞点个数
	 * \endif
	 */
	public int pointCount = 0;

	/**
	 * \if English
	 * collision points, max is two and they are in world coordinates
	 * \else
	 * 碰撞点数组, 最多两个且用的是全局坐标
	 * \endif
	 */
	public WYPoint[] points = new WYPoint[] {
		WYPoint.makeZero(),
		WYPoint.makeZero()
	};

	/**
	 * \if English
	 * normal of collision, in world coordinate. It points from first node
	 * to second node.
	 * \else
	 * 碰撞方向, 以全局坐标表示. 总是从第一个节点指向第二个节点.
	 * \endif
	 */
	public WYPoint normal = WYPoint.makeZero();
	
	/**
	 * \if English
	 * reset result object to all zero
	 * \else
	 * 重置所有数据为0
	 * \endif
	 */
	public void clear() {
		pointCount = 0;
		points[0].x = points[0].y = points[1].x = points[1].y = 0;
		normal.x = normal.y = 0;
	}
	
	/**
	 * \if English
	 * Get float array of collision points
	 * 
	 * @return float array of collision points
	 * \else
	 * 得到碰撞点的浮点数组表示形式
	 * 
	 * @return 碰撞点的浮点数组
	 * \endif
	 */
	public float[] getPoints() {
		if(pointCount == 1)
			return new float[] { points[0].x, points[0].y };
		else if(pointCount == 2)
			return new float[] { points[0].x, points[0].y, points[1].x, points[1].y };
		else
			return new float[0];
	}
}
