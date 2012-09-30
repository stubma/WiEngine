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

import com.wiyun.engine.nodes.Node.ILabel;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;

/**
 * @class AtlasLabel
 *
 * 图片集标签的封装,根据文字显示图片中的内容,效果可以实现各种字体
 */
public class AtlasLabel extends Node implements ILabel {
	/**
	 * \if English
	 * Left alignment
	 * \else
	 * 文字左对齐
	 * \endif
	 */
	public static final int LEFT = 0;

	/**
	 * \if English
	 * center alignment
	 * \else
	 * 居中对齐
	 * \endif
	 */
	public static final int CENTER = 1;

	/**
	 * \if English
	 * right alignment
	 * \else
	 * 右对齐
	 * \endif
	 */
	public static final int RIGHT = 2;
	
    /**
     * 从底层指针获得一个AtlasLabel的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link AtlasLabel}
     */
    public static AtlasLabel from(int pointer) {
    	return pointer == 0 ? null : new AtlasLabel(pointer);
    }
    
    public static AtlasLabel make(String text, Texture2D tex, CharMap map) {
    	return new AtlasLabel(text, tex, map);
    }
    
    protected AtlasLabel(int pointer) {
    	super(pointer);
    }
    
    protected AtlasLabel() {
    }
    
	protected AtlasLabel(String text, Texture2D tex, CharMap map) {
		nativeInit(text, tex, map);
	}

	private native void nativeInit(String text, Texture2D tex, CharMap map);

	@Override
    protected void doNativeInit() {
    }
    
    public WYBlendFunc getBlendFunc() {
    	return new WYBlendFunc(getBlendFuncSrc(), getBlendFuncDst());
    }
    
    private native int getBlendFuncSrc();
    private native int getBlendFuncDst();
    
    public void setBlendFunc(WYBlendFunc blendFunc) {
    	setBlendFunc(blendFunc.src, blendFunc.dst);
    }
    
    private native void setBlendFunc(int src, int dst);
    
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
    
    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    public native void setTexture(Texture2D texture);
    
	/**
	 * 设置文字内容
	 * 
	 * @param text 字符串
	 */
	public native void setText(String text);
	
	/**
	 * 获得文字内容
	 * 
	 * @return 字符串
	 */
	public native String getText();

	/**
	 * 设置行的宽度. 设置后节点的大小将被重新计算，因此节点大小可能会被改变。
	 *
	 * @param width 行宽, 如该值大于实际所有文字一行所占宽度，则行宽为实际宽度
	 */		
	public native void setLineWidth(float width);

	/**
	 * 获得行的宽度
	 *
	 * @return 行宽
	 */
	public native float getLineWidth();
	
	/**
	 * \if English
	 * Set text alignment
	 *
	 * @param alignment alignment constant
	 * \else
	 * 设置文字对齐方式
	 *
	 * @param alignment 文字对齐常量
	 * \endif
	 */
	public native void setAlignment(int alignment);

	/**
	 * \if English
	 * Get text alignment
	 *
	 * @return text alignment
	 * \else
	 * 得到文字对齐方式
	 *
	 * @return 文字对齐方式
	 * \endif
	 */
	public native int getAlignment();
	
	/**
	 * \if English
	 * Get line spacing
	 *
	 * @return line spacing, can be negative value
	 * \else
	 * 得到行间距
	 *
	 * @return 行间距, 可能为负值
	 * \endif
	 */
	public native float getLineSpacing();

	/**
	 * \if English
	 * Set line spacing
	 *
	 * @param spacing line spacing, can be negative value
	 * \else
	 * 设置行间距
	 *
	 * @param spacing 行间距, 可以为负值
	 * \endif
	 */
	public native void setLineSpacing(float spacing);
}
