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
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;

/**
 * 动作跟踪对象。动作跟踪对象可以设置不同的轨迹样式，还可以指定淡出效果。动作跟踪
 * 对象的尺寸为0且不能设置大小，其缺省位置在父节点的左下角. \link MotionStreak MotionStreak\endlink使用
 * 了\link Ribbon Ribbon\endlink来进行轨迹渲染，直接使用\link Ribbon Ribbon\endlink也是可以的。
 * \link MotionStreak MotionStreak\endlink只是把\link Ribbon Ribbon\endlink封装的更加容易使用。
 */
public class MotionStreak extends Node implements IBlendableTextureOwner {
	/**
	 * 条状贴图带，连续，等宽，对应的ribbon子类是\link wyStripRibbon wyStripRibbon\endlink
	 */
	public static final int STYLE_STRIP = 0;

	/**
	 * 点状贴图带，不连续，一次全图显示, 类似愤怒小鸟的轨迹效果，对应的ribbon
	 * 子类是\link wySpotRibbon wySpotRibbon\endlink
	 */
	public static final int STYLE_SPOT = 1;

	/**
	 * 刀痕状，连续，不等宽，类似于水果忍者的效果，对应的ribbon类是\link wyBladeRibbon wyBladeRibbon\endlink
	 */
	public static final int STYLE_BLADE = 2;
	
	/**
	 * 连续的线段, 用来渲染一条粗线, 对应的ribbon类是\link wyLineRibbon wyLineRibbon\endlink.
	 * 该式样不支持淡出效果.
	 */
	public static final int STYLE_LINE = 3;
	
	/**
	 * 创建位置跟踪对象. 位置之间的轨迹以指定贴图画出, 轨迹的宽度和贴图宽度一致.
	 *
	 * @param fade Ribbon段的淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 * @param tex 图片资源\link Texture2D Texture2D对象\endlink
	 * @param color 贴图的颜色
	 */
	public static MotionStreak make(float fade, Texture2D tex, WYColor4B color) {
		return make(fade, tex, color, STYLE_STRIP);
	}
	
	/**
	 * 创建位置跟踪对象. 位置之间的轨迹以指定贴图画出, 轨迹的宽度和贴图宽度一致.
	 *
	 * @param fade Ribbon段的淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图的颜色
	 * @param style motion streak轨迹的样式，缺省是条状
	 */
	public static MotionStreak make(float fade, Texture2D tex, WYColor4B color, int style) {
		return new MotionStreak(fade, tex, color, style);
	}
	
    /**
     * 内部包含的Ribbon对象指针
     */
    public native int getRibbon();

    protected MotionStreak(float fade, Texture2D tex, WYColor4B color, int style) {
    	nativeInit(fade, tex, color, style);
    }
    
    /**
     * 从底层指针获得一个MotionStreak的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MotionStreak}
     */
    public static MotionStreak from(int pointer) {
    	return pointer == 0 ? null : new MotionStreak(pointer);
    }
    
    protected MotionStreak(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float fade, Texture2D texture, WYColor4B color, int style);
    
    @Override
    protected void doNativeInit() {
    }
    
	/**
	 * 得到上一个点的位置, 为全局坐标
	 *
	 * @return {@link WYPoint}
	 */
    public WYPoint getLastLocation() {
    	WYPoint p = WYPoint.makeZero();
    	nativeGetLastLocation(p);
    	return p;
    }
    
    private native void nativeGetLastLocation(WYPoint p);
    
    /**
     * 得到当前点的位置, 为全局坐标
     *
     * @return {@link WYPoint}
     */
    public WYPoint getCurrentLocation() {
    	WYPoint p = WYPoint.makeZero();
    	nativeGetCurrentLocation(p);
    	return p;
    }
    
    private native void nativeGetCurrentLocation(WYPoint p);

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
    
    public native void setPaused(boolean flag);
    
    public native boolean isPaused();
    
	/**
	 * 添加一个点到轨迹中
	 *
	 * @param x 点的x值，这个值是相对于\link MotionStreak MotionStreak\endlink自身位置的
	 * @param y 点的y值，这个值是相对于\link MotionStreak MotionStreak\endlink自身位置的
	 */
    public void addPoint(float x, float y) {
    	addPoint(x, y, false);
    }
    
	/**
	 * 添加一个点到轨迹中
	 *
	 * @param x 点的x值，这个值是相对于\link MotionStreak MotionStreak\endlink自身位置的
	 * @param y 点的y值，这个值是相对于\link MotionStreak MotionStreak\endlink自身位置的
	 * @param newSegment true表示强制结束当前分段，另起一个分段。另起一个分段的意思试在一个新
	 * 		的位置开始渲染，而不是上一个位置自动和新位置连接。缺省是false
	 */
	public native void addPoint(float x, float y, boolean newSegment);
	
	/**
	 * 重置，立刻清除当前所有的轨迹点, 回到初始状态
	 */
	public native void reset();
	
	/**
	 * motion streak中轨迹渲染的样式
	 *
	 * @return 样式常量
	 */
	public native int getStyle();
	
	/**
	 * 设置段阈值
	 *
	 * @param threshold 段阈值
	 */
	public native void setSegmentThreshold(float threshold);

	/**
	 * 得到段阈值
	 *
	 * @return 段阈值
	 */
	public native float getSegmentThreshold();
}
