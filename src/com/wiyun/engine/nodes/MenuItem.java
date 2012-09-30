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

import com.wiyun.engine.utils.TargetSelector;

/**
 * 菜单项 
 */
public abstract class MenuItem extends Node {
    /**
     * 缺省菜单字体大小，单位是SP
     */
    public static final int DEFAULT_FONT_SIZE = 32;
    
    /**
     * 缺省菜单字体名称
     */
    public static final String DEFAULT_FONT_NAME = "DroidSans";

    protected MenuItem() {
    }
    
    /**
     * 构造函数
     * 
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     */
    protected MenuItem(TargetSelector selector) {
    }
    
    /**
     * 构造函数
     * 
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     */
    protected MenuItem(TargetSelector downSelector, TargetSelector upSelector) {
    }
    
    protected MenuItem(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
	/**
	 * \if English
	 * set the scale rate, default value is 1.4f
	 * \else
	 * 设置被点击时候的缩放比, 缺省的缩放比是1.4f
	 * \endif
	 */
	public native float getClickScale();

	/**
	 * \if English
	 * get the scale rate, default value is 1.4f
	 * \else
	 * 得到被点击时候的缩放比, 缺省的缩放比是1.4f
	 * \endif
	 */
	public native void setClickScale(float clickScale);
}