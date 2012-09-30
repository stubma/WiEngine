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
package com.wiyun.engine.particle;

/**
 * 点粒子系统，每个粒子是由一个点描述的，因此不能实现复杂的效果，但是性能上会比四边形
 * 粒子系统快。
 */
public class PointParticleSystem extends ParticleSystem {
	public PointParticleSystem(int numberOfParticles) {
		nativeInit(numberOfParticles);
	}
	
    /**
     * 从底层指针获得一个PointParticleSystem的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link PointParticleSystem}
     */
    public static PointParticleSystem from(int pointer) {
    	return pointer == 0 ? null : new PointParticleSystem(0, pointer);
    }
    
    protected PointParticleSystem(int dummy, int pointer) {
    	super(0, pointer);
    }
    
	private native void nativeInit(int numberOfParticles);
}
