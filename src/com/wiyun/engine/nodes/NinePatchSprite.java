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

import com.wiyun.engine.nodes.Node.IBlendableTextureOwner;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;

/**
 * 点9精灵图片对象. 可以对一个图片指定一个可缩放区域, 这样一个小图片可以被缩放
 * 为任意大小. 这类似于Android提供的.9图片格式, 不过并不支持不连续的缩放区域.
 *
 * 目前NinePatchSprite不支持旋转过的图片集图片, 即rotated属性为true的图片集
 * 图片尚不支持
 */
public class NinePatchSprite extends Node implements Node.IColorable, Node.ISizable, IBlendableTextureOwner {
	/**
	 * 构造\link NinePatchSprite NinePatchSprite对象指针\endlink
	 *
	 * @param tex \link Texture2D Texture2D对象指针\endlink
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link NinePatchSprite NinePatchSprite对象指针\endlink
	 */
	public static NinePatchSprite make(Texture2D tex, WYRect patchRect) {
		WYRect r = WYRect.make(0, 0, tex.getWidth(), tex.getHeight());
		return make(tex, r, patchRect);
	}
	
	/**
	 * 构造\link NinePatchSprite NinePatchSprite对象指针\endlink
	 *
	 * @param tex \link Texture2D Texture2D对象指针\endlink
	 * @param texRect 如果tex代表了一个图片集, 则可以通过\c texRect 指定图片集中的图片矩形
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link NinePatchSprite NinePatchSprite对象指针\endlink
	 */
	public static NinePatchSprite make(Texture2D tex, WYRect texRect, WYRect patchRect) {
		return new NinePatchSprite(tex, texRect, patchRect);
	}
	
	public static NinePatchSprite from(int pointer) {
		return pointer == 0 ? null : new NinePatchSprite(pointer);
	}
	
	protected NinePatchSprite() {
	}
	
    protected NinePatchSprite(int pointer) {
    	super(pointer);
    }
    
    protected NinePatchSprite(Texture2D tex, WYRect texRect, WYRect patchRect) {
    	nativeInit(tex, texRect, patchRect);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Texture2D tex, WYRect texRect, WYRect patchRect);
    
    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    public native void setTexture(Texture2D texture);
    
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
	
	/**
	 * 是否进行alpha渲染
	 *
	 * @return true表示打开alpha blending
	 */
	public native boolean isBlend();
	
	/**
	 * 是否打开alpha渲染, 对于不透明的大图片, 可以考虑关闭blend以提升性能
	 *
	 * @param flag true表示打开alpha渲染
	 */
	public native void setBlend(boolean flag);
	
	/**
	 * 设置画图时所用的贴图区域，单位为像素
	 * 
	 * @param rect 矩形区域
	 */
	public native void setTextureRect(WYRect rect);
	
	private native void nativegetTextureRect(WYRect rect);

	/**
	 * 获得当前使用的贴图区域，单位为像素
	 * 
	 * @return 矩形区域
	 */	
	public WYRect getTextureRect() {
		WYRect rect = WYRect.makeZero();
		nativegetTextureRect(rect);
		return rect;
	}
}
