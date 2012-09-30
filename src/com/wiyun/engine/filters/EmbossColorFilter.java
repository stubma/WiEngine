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
package com.wiyun.engine.filters;

/**
 * \if English
 * Emboss effect for texture
 * \else
 * 浮雕效果的滤镜
 * \endif
 */
public class EmbossColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个EmbossColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EmbossColorFilter}
     */
    public static EmbossColorFilter from(int pointer) {
    	return pointer == 0 ? null : new EmbossColorFilter(pointer);
    }
    
    public static EmbossColorFilter make(int grayLevel) {
    	return new EmbossColorFilter(grayLevel, 0);
    }
    
    protected EmbossColorFilter(int grayLevel, int dummy) {
    	nativeInit(grayLevel);
    }
    
    private native void nativeInit(int grayLevel);

	protected EmbossColorFilter(int pointer) {
    	super(pointer);
    }
	
	/**
	 * \if English
	 * Set gray level of emboss filter
	 *
	 * @param grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 设置浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @param grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	public native void setGrayLevel(int grayLevel);

	/**
	 * \if English
	 * Get gray level of emboss filter
	 *
	 * @return grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 获得浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @return grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	public native int getGrayLevel();
}
