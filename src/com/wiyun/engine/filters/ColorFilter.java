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

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * color filter is used to transform colors in a texture
 * \else
 * 颜色过滤器用来对一个贴图中的颜色进行转换
 * \endif
 */
public class ColorFilter extends BaseWYObject {
    /**
     * 从底层指针获得一个ColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorFilter}
     */
    public static ColorFilter from(int pointer) {
    	return pointer == 0 ? null : new ColorFilter(pointer);
    }
    
    protected ColorFilter() {
	}
    
    protected ColorFilter(int pointer) {
    	super(pointer);
    }
    
	/**
	 * \if English
	 * apply this color filter to some image data
	 *
	 * @param data raw data of image which must be RGBA8888 format, it holds transformed result when method returns
	 * @param width image pixel width
	 * @param height image pixel height
	 * \else
	 * 对一个图像数据应用颜色矩阵
	 *
	 * @param data 图像原始数据, 必须是RGBA8888格式, 方法完成后, data中的数据变成转换后的值.
	 * @param width 图像的像素宽度
	 * @param height 图像的像素高度
	 * \endif
	 */
	public native void apply(byte[] data, int width, int height);
}
