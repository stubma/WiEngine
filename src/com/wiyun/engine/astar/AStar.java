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
package com.wiyun.engine.astar;

import java.util.ArrayList;

import com.wiyun.engine.BaseWYObject;

/**
 * A*算法封装,根据把地图划分成静态的网格寻找两个点之间的最短路径
 * 算法根据所有点的f(n) = h(n) + g(n)查找最短路径
 * 参考资料 http://baike.baidu.com/view/7850.html
 */
public class AStar extends BaseWYObject {
	public static AStar make(AStarMap map) {
		return new AStar(map);
	}
	
	/**
	 * 构造函数
	 */
	protected AStar(AStarMap map) {
		doNativeInit(map);
	}
	
	public static AStar from(int pointer) {
		return pointer == 0 ? null : new AStar(pointer);
	}
	
	protected AStar(int pointer) {
		super(pointer);
	}
	
	protected void doNativeInit(AStarMap map) {
		nativeInit(map);
	}
	
	private native void nativeInit(AStarMap map);
	
	/**
	 * 路径查询
	 *
	 * @param startx 起始tile　x值
	 * @param starty 起始tile　y值
	 * @param endx   目标tile　x值
	 * @param endy   目标tile　y值
	 * @param ignoreBlock   是否忽略block tile,true为忽略
	 * @return 保存路径\link AStarStep AStarStep\endlink节点集合
	 */
	public final ArrayList<AStarStep> findPath(int startx, int starty, int endx, int endy, boolean ignoreBlock) {
		ArrayList<AStarStep> steps = new ArrayList<AStarStep>();
		int stepCount = nativeFindPath(startx, starty, endx, endy, ignoreBlock);
		if (stepCount == 0) {
			return null;
		}
		int[] pointers = new int[stepCount];
		nativeGetStep(pointers);
		for(int pointer : pointers)
			steps.add(new AStarStep(pointer));
		return steps;
	}
	
	public native final int nativeFindPath(int startx, int starty, int endx, int endy, boolean ignoreBlock);
	
	private native final void nativeGetStep(int[] steps);

	/**
	 * 返回地图状况\link AStarMap AStarMap\endlink对象指针
	 *
	 * @return A*地图状况\link AStarMap AStarMap\endlink对象指针
	 */
	public final AStarMap getAStarMap() {
		int pointer = nativeGetStarMap();
		return new AStarMap(pointer);
	}

	private native final int nativeGetStarMap();
	
	/**
	 * 计算两个tile之间的h值,默认取两节点间欧几理德距离（直线距离）做为估价值，可被子类重载
	 *
	 * @param startx 起始tile　x值
	 * @param starty 起始tile　y值
	 * @param endx   目标tile　x值
	 * @param endy   目标tile　y值
	 * @return 两个tile的h值
	 */
	public float heuristic(int startx, int starty, int endx, int endy) {
		return nativeHeuristic(startx, starty, endx, endy);
	}
	
	private native float nativeHeuristic(int startx, int starty, int endx, int endy);
}
