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

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 四边形粒子系统，每个粒子其实是由一个四边形进行描述的，因此它的表现能力更丰富，
 * 可以做更多变形。 
 */
public class QuadParticleSystem extends ParticleSystem {
	public QuadParticleSystem(int numberOfParticles) {
		nativeInit(numberOfParticles);
	}
	
    /**
     * 从底层指针获得一个QuadParticleSystem的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link QuadParticleSystem}
     */
    public static QuadParticleSystem from(int pointer) {
    	return pointer == 0 ? null : new QuadParticleSystem(0, pointer);
    }
    
    protected QuadParticleSystem(int dummy, int pointer) {
    	super(0, pointer);
    }
	
	private native void nativeInit(int numberOfParticles);

	/**
	 * 设置粒子贴图为某个图片集的一部分
	 * 
	 * @param texture 图片集贴图对象
	 * @param rect 粒子图片在图片集中的位置，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
	 */
	public native void setTexture(Texture2D texture, WYRect rect);
}
