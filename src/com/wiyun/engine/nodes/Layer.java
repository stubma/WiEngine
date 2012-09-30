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
package com.wiyun.engine.nodes;


/**
 * \if English
 * Layer is a container for other nodes. Its size by default is set
 * to surface view size and relativeAnchorPoint flag is false
 * \else
 * 层的封装, 层的缺省大小是和屏幕一样大，且relativeAnchorPoint标志
 * 缺省是false
 * \endif
 */
public class Layer extends Node {
	public static Layer make() {
		return new Layer();
	}
	
	protected Layer() {
	}
	
    /**
     * 从底层指针获得一个Layer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Layer}
     */
    public static Layer from(int pointer) {
    	return pointer == 0 ? null : new Layer(pointer);
    }
    
    protected Layer(int pointer) {
    	super(pointer);
    }
    
	private native void nativeInit();
	
	protected void doNativeInit() {
		nativeInit();
	}
}
