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
package com.wiyun.engine.chipmunk;

/**
 * 碰撞事件处理器
 */
public interface ICollisionHandler {
	/**
	 * 在两个物体开始接触之前调用，返回0表示要chipmunk忽略这次碰撞，且preSolve和postSolve
	 * 都不会再被调用，但是separate仍然会被调用。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 * @return 返回0表示要chipmunk忽略这次碰撞，非0表示计算这次碰撞
	 */
	public int begin(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体正在接触，但是它们产生的这次碰撞参数还没有被计算出来，返回0表示要chipmunk忽略这次碰撞。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 * @return 返回0表示要chipmunk忽略这次碰撞，非0表示计算这次碰撞
	 */
	public int preSolve(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体正在接触，它们产生的这次碰撞已经被处理，在postSolve时，你可以得到这次
	 * 碰撞的力度。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 */
	public void postSolve(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体刚开始分离。如果一个物体从空间中被删除，则这个方法也会被调用。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 */
	public void separate(int arbiterPointer, int spacePointer, Object data);
}
