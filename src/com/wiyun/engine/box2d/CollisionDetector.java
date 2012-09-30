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
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * A collision detector based on Box2D collision detection utility but
 * no need to establish whole world. It encapsulates detailed implementation of
 * Box2D and exposes those features in \link wyNode wyNode\endlink structure.
 * \else
 * 一个基于Box2D的碰撞检测工具, 但是它并不需要去建立整个世界. 这个工具类隐藏Box2D的具体
 * 实现, 提供了一个基于节点架构的接口以方便使用
 * \endif
 */
public class CollisionDetector extends BaseWYObject {
	public static CollisionDetector make() {
		return new CollisionDetector();
	}
	
	public static CollisionDetector from(int pointer) {
		return pointer == 0 ? null : new CollisionDetector(pointer);
	}
	
	protected CollisionDetector() {
		nativeInit();
	}
	
	protected CollisionDetector(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();

	/**
	 * \if English
	 * Are two nodes collided each other?
	 *
	 * @param node1 first node
	 * @param node2 second node
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 两个节点是否发生了碰撞
	 *
	 * @param node1 节点1
	 * @param node2 节点2
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	public native boolean isCollided(Node node1, Node node2, CDResult result);

	/**
	 * \if English
	 * Is node collided with a rectangle
	 *
	 * @param node node
	 * @param r rectangle, must in global coordinate
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 判断一个节点是否和一个矩形发生了碰撞
	 *
	 * @param node 节点
	 * @param r 矩形, 必须是全局坐标
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	public native boolean isCollided(Node node, WYRect r, CDResult result);

	/**
	 * \if English
	 * Are two rectangle collided each other?
	 *
	 * @param r1 first rectangle, must in same coordinates as \c r2
	 * @param r2 second rectangle, must in same coordinates as \c r1
	 * @param result returns result of collision, if NULL, no data written.
	 * 		If not collided, no data written also.
	 * @return true if they are collided
	 * \else
	 * 两个矩形是否发生了碰撞
	 *
	 * @param r1 矩形1, 必须和\c r2在同一个坐标系中
	 * @param r2 矩形2, 必须和\c r1在同一个坐标系中
	 * @param result 用来返回碰撞的结果, 传入NULL表示不希望获得碰撞信息. 如果没有
	 * 		碰撞发生, 也不会写入信息
	 * @return true表示发生了碰撞
	 * \endif
	 */
	public native boolean isCollided(WYRect r1, WYRect r2, CDResult result);
	
	/**
	 * \if English
	 * Set polygon shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param points vertices of shape, must in counter-clockwise sequence and in
	 * 		WiEngine global coordinates.
	 * \else
	 * 修改节点相关的多边形
	 *
	 * @param node 需要修改关联形状的节点对象
	 * @param points 多边形的点, 必须以逆时针顺序指定. 其值必须是WiEngine的全局坐标
	 * \endif
	 */
	public native void setNodeShape(Node node, WYPoint[] points);

	/**
	 * \if English
	 * Set circle shape of a node
	 *
	 * @param node shape of node whose shape need to be defined
	 * @param radius radius of circle
	 * \else
	 * 修改节点的关联形状为圆形
	 *
	 * @param node 需要修改关联形状的节点对象
	 * @param radius 圆的半径, 单位为像素
	 * \endif
	 */
	public native void setNodeShape(Node node, int radius);
}
