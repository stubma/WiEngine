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

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYRect;

/**
 * @class CharMap
 *
 * 维护一个字符与矩形的映射表，在构造\link AtlasLabel AtlasLabel\endlink 时，需要
 * 传入该类。
 */
public class CharMap extends BaseWYObject {
    /**
     * 从底层指针获得一个CharMap的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CharMap}
     */
    public static CharMap from(int pointer) {
    	return pointer == 0 ? null : new CharMap(pointer);
    }
    
    public static CharMap make() {
    	return new CharMap();
    }
    
    protected CharMap() {
    	nativeInit();
    }
    
    private native void nativeInit();
    
    protected CharMap(int pointer) {
    	super(pointer);
    }
    
    /**
     * 映射矩形和字符
     *
     * @param rect 字符图片在图片集中的矩形
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(WYRect rect, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param rect 字符图片在图片集中的矩形
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(WYRect rect, int c, float leftPadding, float rightPadding);

    /**
     * 映射矩形和字符
     *
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(String frameName, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(String frameName, int c, float leftPadding, float rightPadding);

    /**
     * 映射矩形和字符
     *
     * @param zwoptexName zwoptex名
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(String zwoptexName, String frameName, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param zwoptexName zwoptex名
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(String zwoptexName, String frameName, int c, float leftPadding, float rightPadding);
    
	/**
	 * 设置一个空格的像素宽度
	 *
	 * @param w 空格的像素宽度
	 */
	public native void setSpaceWidth(float w);

	/**
	 * 得到空格的像素宽度
	 *
	 * @return 空格的像素宽度
	 */
	public native float getSpaceWidth();

	/**
	 * 设置一个制表符代表的空格数目
	 *
	 * @param tabSize 一个制表符代表的空格数目
	 */
	public native void setTabSize(int tabSize);

	/**
	 * 得到一个制表符代表的空格数目
	 *
	 * @return 一个制表符代表的空格数目
	 */
	public native int getTabSize();
}