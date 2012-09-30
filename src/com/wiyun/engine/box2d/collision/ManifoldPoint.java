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
package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.types.WYPoint;

public class ManifoldPoint {
	// contact feature
	public static final int TYPE_VERTEX = 0;
	public static final int TYPE_FACE = 1;
	
	/**
	 * local point
	 */
	public WYPoint localPoint;
	
	/**
	 * the non-penetration impulse
	 */
	public float normalImpulse;
	
	/**
	 * the friction impulse
	 */
	public float tangentImpulse;
	
	/**
	 * Feature index on shapeA
	 */
	public int indexA;		
	
	/**
	 * Feature index on shapeB
	 */
	public int indexB;		
	
	/**
	 * The feature type on shapeA
	 */
	public int typeA;		
	
	/**
	 * The feature type on shapeB
	 */
	public int typeB;		
	
	/**
	 * 得到一个唯一标识碰撞点的id
	 * 
	 * @return 碰撞点id
	 */
	public int getContactId() {
		return ((indexA & 0xff) << 24) | ((indexB & 0xff) << 16) | ((typeA & 0xff) << 8) | (typeB & 0xff);
	}
}
