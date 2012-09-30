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

import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;

/**
 * 带颜色的层。它是{@link Layer}子类，支持设置背景色。
 */
public class ColorLayer extends Layer implements Node.IColorable, Node.ISizable {
    /**
     * 创建层, 颜色透明
     * 
     * @return 层实例
     */
    public static ColorLayer make() {
        return new ColorLayer();
    }
    
    /**
     * 创建层
     * 
     * @param color 层背景色
     * @return 层实例
     */
    public static ColorLayer make(WYColor4B color) {
        return new ColorLayer(color);
    }

    /**
     * 构造函数
     */
    protected ColorLayer() {
    	nativeInit(WYColor4B.make(0, 0, 0, 0));
    }
    
    /**
     * 构造函数
     * 
     * @param color 层背景色
     */
    protected ColorLayer(WYColor4B color) {
    	nativeInit(color);
    }
    
    /**
     * 从底层指针获得一个ColorLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorLayer}
     */
    public static ColorLayer from(int pointer) {
    	return pointer == 0 ? null : new ColorLayer(pointer);
    }
    
    protected ColorLayer(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(WYColor4B color);
    
    @Override
    protected void doNativeInit() {
    }

    public native int getAlpha();

    public native void setAlpha(int alpha);
    
	public WYColor3B getColor() {
		WYColor3B color = new WYColor3B();
		nativeGetColor(color);
		return color;
	}
	
	private native void nativeGetColor(WYColor3B color);
	
	public void setColor(WYColor3B color) {
		nativeSetColor(color.r, color.g, color.b);
	}
	
	private native void nativeSetColor(int r, int g, int b);
}