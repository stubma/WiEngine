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

import java.util.ArrayList;
import java.util.List;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.actions.Animate;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 动画对象。可以用于包含一系列帧。
 */
public class Animation extends BaseWYObject {
	/**
	 * 动画事件回调
	 */
	public static interface IAnimationCallback {
		/**
		 * 帧变化时调用
		 * 
		 * @param animPointer 底层动画对象的指针
		 * @param index 当前帧索引
		 */
		public void onAnimationFrameChanged(int animPointer, int index);
		
		/**
		 * 动画结束时调用，如果{@link Animate}被包含在一个
		 * repeat动作中执行，则每执行一遍这个方法都会被调用一次
		 * 
		 * @param animPointer 底层动画对象的指针
		 */
		public void onAnimationEnded(int animPointer);
	}
	
    public List<? extends Frame> getFrames() {
        List<Frame> frames = new ArrayList<Frame>();
        int size = getFrameCount();
        int[] pointers = new int[size];
        nativeGetFrames(pointers);
        for(int pointer : pointers) {
        	Frame f = new Frame(pointer);
        	frames.add(f);
        }
        return frames;
    }
    
    /**
     * 从底层指针获得一个Animation的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Animation}
     */
    public static Animation from(int pointer) {
    	return pointer == 0 ? null : new Animation(0, pointer);
    }
    
    protected Animation() {
	}
    
    protected Animation(int dummy, int pointer) {
    	super(pointer);
    }

    /**
     * 创建一个空的动画对象
     * 
     * @param id 动画id
     */
    public Animation(int id) {
        this(id, 0, new int[0]);
    }
    
    /**
     * 从一系列资源图片中创建一个动画对象，每帧具有相同的时间间隔。资源都自动添加到
     * TextureManager中，如果想释放相关贴图，可以使用TextureManager.removeTexture方法
     * 
     * @param id 动画id
     * @param frameDuration 每帧的时间
     * @param resIds 每帧的图象资源id
     */
    public Animation(int id, float frameDuration, int... resIds) {
    	nativeInit(id);

        if (resIds != null) {
            for (int resId : resIds) {
            	addFrame(frameDuration, resId);
            }
        }
    }
    
    /**
     * 从一系列贴图对象中创建一个动画对象，每帧具有相同的时间间隔
     * 
     * @param id 动画id
     * @param frameDuration 每帧的时间
     * @param textures 每帧的贴图对象
     */
    public Animation(int id, float frameDuration, Texture2D... textures) {
    	nativeInit(id);

        if (textures != null) {
        	for(Texture2D tex : textures) {
        		addFrame(frameDuration, tex);
        	}
        }
    }
    
    private native void nativeInit(int id);
    
    private native int getFrameCount();
    private native void nativeGetFrames(int[] pointers);

    /**
     * 添加一帧
     * 
     * @param frameDuration 帧显示时间
     * @param resId 帧图片资源id
     */
    public void addFrame(float frameDuration, int resId) {
    	Texture2D tex = (Texture2D)Texture2D.makePNG(resId).autoRelease();
    	addFrame(frameDuration, tex);
    }
    
    /**
     * 添加一帧或多帧
     * 
     * @param duration 帧显示时间
     * @param rects 帧图片在图片集中的位置，可变参数，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
     */
    public void addFrame(float duration, WYRect... rects) {
    	for(WYRect rect : rects) {
    		addFrame(duration, rect);
    	}
    }

    /**
     * 添加一帧
     * 
     * @param frameDuration 帧显示时间
     * @param tex 帧图片贴图
     */
    public native void addFrame(float frameDuration, Texture2D tex);
    
    /**
     * 添加一帧
     * 
     * @param frameDuration 帧显示时间
     * @param rect 帧所在的图片集中的矩形
     */
    public native void addFrame(float frameDuration, WYRect rect);
    
    /**
     * 添加一帧
     * 
     * @param frame {@link Frame}的子类
     */
    public native void addFrame(Frame frame);
    
    /**
     * 得到动画持续时间
     */
    public native float getDuration();
    
    /**
     * 获得动画id
     * 
     * @return 动画id
     */
    public native int getId();
    
    /**
     * 设置回调
     * 
     * @param callback {@link IAnimationCallback}实现类
     */
    public native void setCallback(IAnimationCallback callback); 
}
