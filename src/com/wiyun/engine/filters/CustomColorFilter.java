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
 * Custom color filter, filter is implemented by setting a delegate
 * \else
 * 自定义的滤镜实现, 通过设置一个代理来让开发者实现滤镜方法
 * \endif
 */
public class CustomColorFilter extends ColorFilter {
	public static interface IColorFilterDelegate {
		/**
		 * \if English
		 * process image data
		 *
		 * @param imageData raw data of image which must be RGBA8888 format, it holds transformed result when method returns
		 * @param width image pixel width, it is the original size before autoscaling
		 * @param height image pixel height, it is the original size before autoscaling
		 * \else
		 * 对一个图像数据应用自定义的滤镜算法
		 *
		 * @param imageData 图像原始数据, 必须是RGBA8888格式, 方法完成后, data中的数据变成转换后的值.
		 * @param width 图像的像素宽度, 为未自动缩放前的大小
		 * @param height 图像的像素高度, 为未自动缩放前的大小
		 * \endif
		 */
		public void apply(byte[] imageData, int width, int height);
	}
	
    /**
     * 从底层指针获得一个CustomColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CustomColorFilter}
     */
    public static CustomColorFilter from(int pointer) {
    	return pointer == 0 ? null : new CustomColorFilter(pointer);
    }
    
    public static CustomColorFilter make(IColorFilterDelegate delegate) {
    	return new CustomColorFilter(delegate);
    }
    
    protected CustomColorFilter(IColorFilterDelegate delegate) {
    	nativeInit(delegate);
    }
    
    private native void nativeInit(IColorFilterDelegate delegate);

	protected CustomColorFilter(int pointer) {
    	super(pointer);
    }
	
	/**
	 * \if English
	 * Set delegate
	 *
	 * @param delegate \link IColorFilterDelegate IColorFilterDelegate\endlink
	 * \else
	 * 设置代理
	 *
	 * @param delegate \link IColorFilterDelegate IColorFilterDelegate\endlink 
	 * \endif
	 */
	public native void setDelegate(IColorFilterDelegate delegate);
}
