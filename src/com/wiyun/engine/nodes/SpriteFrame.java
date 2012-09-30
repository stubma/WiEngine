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
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;

/**
 * \if English
 * A frame which is related to a texture or part of texture
 * \else
 * 帧引用了某个贴图或者只是某个贴图的一部分
 * \endif
 */
public class SpriteFrame extends Frame {
	/**
	 * 通过矩形创建SpriteFrame, 创建的帧图片为某个图片集中的一部分
	 *
	 * @param duration 帧持续时间
	 * @param rect {@link WYRect}
	 * @return {@link SpriteFrame}
	 */
	public static SpriteFrame make(float duration, WYRect rect) {
		return make(duration, null, rect);
	}
	
	/**
	 * 通过贴图对象创建SpriteFrame, 创建的帧为整个贴图
	 *
	 * @param duration 帧持续时间
	 * @param tex {@link Texture2D}
	 * @return {@link SpriteFrame}
	 */
	public static SpriteFrame make(float duration, Texture2D tex) {
		WYRect rect = WYRect.make(0, 0, tex.getWidth(), tex.getHeight());
		return make(duration, tex, rect);
	}
	
	/**
	 * 通过贴图对象创建wySpriteFrame, 并指定帧图片在贴图中的范围
	 * 
	 * @param duration 帧持续时间
	 * @param tex {@link Texture2D}
	 * @param rect {@link WYRect}
	 * @return {@link SpriteFrame}
	 */
	public static SpriteFrame make(float duration, Texture2D tex, WYRect rect) {
		return make(duration, tex, rect, WYPoint.makeZero(), rect.size);
	}
	
	/**
	 * 通过贴图对象创建wySpriteFrame, 并指定帧图片在贴图中的范围, 以及帧的偏移位置和原始大小
	 *
	 * @param duration 帧持续时间
	 * @param tex {@link Texture2D}
	 * @param rect {@link WYRect}
	 * @param offset {@link WYPoint}
	 * @param originalSize {@link WYSize}
	 * @return {@link SpriteFrame}
	 */
	public static SpriteFrame make(float duration, Texture2D tex, WYRect rect, WYPoint offset, WYSize originalSize) {
		return new SpriteFrame(duration, tex, rect, offset, originalSize, false);
	}
	
	/**
	 * 通过贴图对象创建wySpriteFrame, 并指定帧图片在贴图中的范围, 以及帧的偏移位置和原始大小
	 *
	 * @param duration 帧持续时间
	 * @param tex {@link Texture2D}
	 * @param rect {@link WYRect}
	 * @param offset {@link WYPoint}
	 * @param originalSize {@link WYSize}
	 * @param rotated true表示图片在图片集中顺时针旋转了90度
	 * @return {@link SpriteFrame}
	 */
	public static SpriteFrame make(float duration, Texture2D tex, WYRect rect, WYPoint offset, WYSize originalSize, boolean rotated) {
		return new SpriteFrame(duration, tex, rect, offset, originalSize, rotated);
	}
	
	public static SpriteFrame from(int pointer) {
		return pointer == 0 ? null : new SpriteFrame(pointer);
	}
	
	protected SpriteFrame(float duration, Texture2D tex, WYRect rect, WYPoint offset, WYSize originalSize, boolean rotated) {
		nativeInit(duration, tex, rect, offset, originalSize, rotated);
	}
	
	protected SpriteFrame(int pointer) {
    	super(pointer);
	}
	
	private native void nativeInit(float duration, Texture2D tex, WYRect rect, WYPoint offset, WYSize originalSize, boolean rotated);
	
	public Texture2D getTexture() {
		return Texture2D.from(nativeGetTexture());
	}
	
	private native int nativeGetTexture(); 
	
	public WYRect getRect() {
		WYRect rect = WYRect.makeZero();
		nativeGetRect(rect);
		return rect;
	}
	
	private native void nativeGetRect(WYRect rect);
	
	public WYRect getSourceColorRect() {
		WYRect rect = WYRect.makeZero();
		nativeGetSourceColorRect(rect);
		return rect;
	}
	
	private native void nativeGetSourceColorRect(WYRect rect);
	
	public WYPoint getOffset() {
		WYPoint offset = WYPoint.makeZero();
		nativeGetOffset(offset);
		return offset;
	}
	
	private native void nativeGetOffset(WYPoint offset);
	
	public WYPoint getOriginalSize() {
		WYPoint size = WYPoint.makeZero();
		nativeGetOriginalSize(size);
		return size;
	}
	
	private native void nativeGetOriginalSize(WYPoint size);
	
	public native void setRotated(boolean flag);
	public native boolean isRotated();
	
	/**
	 * 设置贴图
	 * 
	 * @param tex {@link Texture2D}
	 */
	public native void setTexture(Texture2D tex);
}
