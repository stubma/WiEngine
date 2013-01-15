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
import com.wiyun.engine.types.WYRect;

/**
 * 图片对象
 */ 
public class Sprite extends TextureNode implements Node.IFrames {
    /**
     * 从png资源文件中创建图片节点。这个API主要为了兼容目的存在，如果为了从
     * 其它文件格式中创建Sprite，请使用Texture2D的make系列方法创建Texture2D
     * 对象，再创建Sprite
     * 
     * @param resId 图片资源id
     * @return 图片对象
     */
    public static Sprite make(int resId) {
    	return new Sprite((Texture2D)Texture2D.make(resId).autoRelease());
    }

    /**
     * 从一个贴图对象中创建图片节点
     * 
     * @param tex {@link Texture2D}
     * @return 图片对象
     */
    public static Sprite make(Texture2D tex) {
        return new Sprite(tex);
    }

    /**
     * 从一个贴图对象中创建图片节点
     * 
     * @param tex {@link Texture2D}
     * @param texRect 贴图区域，单位为像素
     * @return 图片对象
     */
    public static Sprite make(Texture2D tex, WYRect texRect) {
    	return new Sprite(tex, texRect);
    }
    
    /**
     * 构造函数
     * 
     * @param tex {@link Texture2D}
     */
    protected Sprite(Texture2D tex) {
    	nativeInit(tex);
    }

    /**
     * 构造函数
     * 
     * @param tex {@link Texture2D}
     * @param texRect 贴图区域矩形
     */
    protected Sprite(Texture2D tex, WYRect texRect) {
    	nativeInit(tex);
    	setTextureRect(texRect);
    }
    
    /**
     * 从底层指针获得一个Sprite的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Sprite}
     */
    public static Sprite from(int pointer) {
    	return pointer == 0 ? null : new Sprite(pointer);
    }
    
    protected Sprite(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Texture2D tex);
}
