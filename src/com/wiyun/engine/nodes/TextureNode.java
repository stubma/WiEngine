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
 * 贴图节点，封装一个{@link Texture2D}对象。
 */
public class TextureNode extends Node implements Node.IColorable, Node.ISizable, IBlendableTextureOwner {
	public static TextureNode from(int pointer) {
		return new TextureNode(pointer);
	}
	
	protected TextureNode() {
	}
	
    protected TextureNode(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    	nativeInit();
    }
    
    private native void nativeInit();
    
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
	 * 得到是否渲染的时候要反向x轴
	 * 
	 * @return true表示渲染时要在x方向翻转图片
	 */
	public native boolean isFlipX();

	/**
	 * 是否渲染的时候要反向x轴
	 * 
	 * @param flipX true表示渲染时要在x方向翻转图片
	 */
	public native void setFlipX(boolean flipX);

	/**
	 * 得到是否渲染的时候要反向y轴
	 * 
	 * @return true表示渲染时要在y方向翻转图片
	 */
	public native boolean isFlipY();

	/**
	 * 是否渲染的时候要反向y轴
	 * 
	 * @param flipY true表示渲染时要在y方向翻转图片
	 */
	public native void setFlipY(boolean flipY);
	
	/**
	 * 是否打开抖动
	 *
	 * @return true表示打开抖动, false表示不打开抖动
	 */
	public native boolean isDither();

	/**
	 * 设置是否打开抖动
	 *
	 * @param flag true表示打开抖动, false表示不打开抖动
	 */
	public native void setDither(boolean flag);
	
    public native void setDisplayFrame(Frame frame);

    public native void setDisplayFrame(int animId, int frameIndex);

    public native boolean isFrameDisplayed(Frame frame);

    public Frame getDisplayFrame() {
    	return new SpriteFrame(nativeGetDisplayFrame());
    }
    
    private native int nativeGetDisplayFrame();

    public native void addAnimation(Animation anim);

    public Animation getAnimationById(int id) {
    	return Animation.from(nativeGetAnimationById(id));
    }
    
    private native int nativeGetAnimationById(int id);
    
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
	
	/**
	 * 设置图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @param flag true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	public native void setRotatedZwoptex(boolean flag);

	/**
	 * 是否图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @return true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	public native boolean isRotatedZwoptex();
	
	/**
	 * 设置是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @param flag true表示自动拉伸贴图以便能匹配节点大小
	 */
	public native void setAutoFit(boolean flag);

	/**
	 * 是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @return true表示自动拉伸贴图以便能匹配节点大小
	 */
	public native boolean isAutoFit();
	
	/**
	 * 将自身包装成一个\link SpriteFrame SpriteFrame\endlink, 生成的\link SpriteFrame SpriteFrame\endlink
	 * 的duration是0, 需要在返回后由开发者设置.
	 */
	public SpriteFrame makeFrame() {
		return SpriteFrame.from(nativeMakeFrame());
	}
	
	private native int nativeMakeFrame();
	
	/**
	 * \if English
	 * Set alpha function. If alpha function is set to GL_ALWAYS, then
	 * alpha test is disabled
	 *
	 * @param func alpha test function
	 * @param ref alpha reference value
	 * \else
	 * 设置alpha比较方式. 如果把alpha比较方式设置为GL_ALWAYS, 则相当于
	 * 禁止alpha测试
	 *
	 * @param func alpha比较方式, 由OpenGL定义, 缺省是GL_ALWAYS
	 * @param ref alpha参考值
	 * \endif
	 * @see GL10.GL_ALWAYS
	 * @see GL10.GL_NEVER
	 * @see GL10.GL_LESS
	 * @see GL10.GL_LEQUAL
	 * @see GL10.GL_EQUAL
	 * @see GL10.GL_GEQUAL
	 * @see GL10.GL_GREATER
	 * @see GL10.GL_NOTEQUAL
	 */
	public native void setAlphaFunc(int func, float ref);
}