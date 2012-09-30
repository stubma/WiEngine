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
package com.wiyun.engine.types;

/**
 * 用于描述一个顶点的3维坐标
 */
public class WYVertex3D {
	/**
	 * byte count of GL format
	 */
	public static final int GL_SIZE = 4 * 3;
	
    public float x;
    public float y;
    public float z;
    
    /**
     * 创建一个实例
     * 
     * @return 值全0的顶点坐标对象
     */
    public static WYVertex3D makeZero() {
    	return WYVertex3D.make(0, 0, 0);
    }
    
    /**
     * 创建一个实例
     * 
     * @param x 顶点的x坐标
     * @param y 顶点的y坐标
     * @param z 顶点的z坐标
     * @return {@link WYVertex3D}
     */
    public static WYVertex3D make(float x, float y, float z) {
    	return new WYVertex3D(x, y, z);
    }

    /**
     * 构造函数
     * 
     * @param x 顶点的x坐标
     * @param y 顶点的y坐标
     * @param z 顶点的z坐标
     */
    protected WYVertex3D(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    @Override
    public String toString() {
    	return "<"  + x + ", " + y + ", " + z + ">";
    }
}
