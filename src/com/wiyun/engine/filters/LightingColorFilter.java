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
 * Color filter that multiplies the RGB channels by one color, and then adds a second color,
 * pinning the result for each component to [0..255]. The alpha components of the mul and add arguments
 * are ignored.
 * \else
 * 这个滤镜对颜色的三原色进行一个乘法, 然后再做一个加法, 最后的结果限制在[0, 255]之内. 透明度不参与乘法和加法.
 *
 * \par
 * 例如: 如果想把图片中的红色清空, 可以指定和0xFF00FFFF相乘, 再和0x00000000相加.
 * \endif
 */
public class LightingColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个LightingColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link LightingColorFilter}
     */
    public static LightingColorFilter from(int pointer) {
    	return pointer == 0 ? null : new LightingColorFilter(pointer);
    }
    
    public static LightingColorFilter make(int mul, int add) {
    	return new LightingColorFilter(mul, add);
    }
    
    protected LightingColorFilter() {
	}
    
    protected LightingColorFilter(int mul, int add) {
    	nativeInit(mul, add);
    }
    
    private native void nativeInit(int mul, int add);

	protected LightingColorFilter(int pointer) {
    	super(pointer);
    }
}
