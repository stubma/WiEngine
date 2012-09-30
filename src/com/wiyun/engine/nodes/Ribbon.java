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
import com.wiyun.engine.types.WYPoint;

/**
 * <p>Ribbon是一个动态多边形列表，在渲染时通过一系列三角形绘制出来，形成一个带状的效果。Ribbon
 * 主要的用途是和\link MotionStreak MotionStreak\endlink结合使用用来显示动作轨迹。Ribbon
 * 只是一个抽象的接口定义，每个子类都可能有不同的渲染效果. \link MotionStreak MotionStreak\endlink
 * 中定义了setStyle方法可以让您设置不同的轨迹样式，\link MotionStreak MotionStreak\endlink会根据
 * 轨迹样式使用不同的Ribbon子类</p>
 */
public class Ribbon extends Node implements IBlendableTextureOwner {
    /**
     * 从底层指针获得一个Ribbon的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Ribbon}
     */
    public static Ribbon from(int pointer) {
    	return pointer == 0 ? null : new Ribbon(pointer);
    }
    
    protected Ribbon(int pointer) {
    	super(pointer);
    }
    
    protected Ribbon() {
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    /**
     * 强制指定下一个新端点会产生一个新的RibbonSegment
     */
    public native void forceFirstPoint();

    /**
     * 添加一个新端点
     * 
     * @param location 新端点的位置
     */
    public native void addPoint(WYPoint location);

	/**
     * 被Scheduler调用的方法，不要手动调用
     */
    public native void update(float delta);

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
	
	/**
	 * 重置ribbon，清除当前的点，擦除所有绘制内容
	 */
	public native void reset();
}
