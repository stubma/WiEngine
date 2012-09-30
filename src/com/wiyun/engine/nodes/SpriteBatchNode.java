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

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.opengl.TextureAtlas;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;

/**
 * 用于图像节点的批处理，仅接受 \link SpriteEx SpriteEx \endlink 作为子节点。
 * 所有子节点共享一张贴图，所有节点的绘制一次完成，可提高性能。
 */
public class SpriteBatchNode extends Node {
	protected SpriteBatchNode() { 
	}
	
	protected SpriteBatchNode(int pointer) {
		super(pointer);
	}
	
	/**
	 * 构造函数
	 *
	 * @param tex 贴图
	 */
	public SpriteBatchNode(Texture2D tex) {
		nativeInit(tex);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 创建一个wySpriteBatchNode类型的节点
	 *
	 * @param tex 贴图
	 */	
	public static SpriteBatchNode make(Texture2D tex) {
		return new SpriteBatchNode(tex);
	}
	
	public static SpriteBatchNode from(int pointer) {
		return pointer == 0 ? null : new SpriteBatchNode(pointer);
	}
	
	//native methods declare
	private native void nativeInit(Texture2D tex);
	private native void nativesetTexture(Texture2D tex);
	private native int nativegetTexture();
	private native int nativegetTexAtlas();

	/**
	 * 设置贴图
	 *
	 * @param tex 贴图
	 */	
	public void setTexture(Texture2D tex) {
		nativesetTexture(tex);
	}
	
	public Texture2D getTexture() {
		int pointer = nativegetTexture();
		return Texture2D.from(pointer);
	}
	
	public TextureAtlas getTexAtlas() {
		int pointer = nativegetTexAtlas();
		return TextureAtlas.from(pointer);
	}
	
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
	 */
	public native void setAlphaFunc(int func, float ref);
	
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
}