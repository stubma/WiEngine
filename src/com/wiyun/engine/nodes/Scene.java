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


/**
 * 场景是一个全屏的节点，一般只用作顶层容器。 
 */
public class Scene extends Node {
    /**
     * 创建场景
     * 
     * @return 场景实例
     */
    public static Scene make() {
        return new Scene();
    }
    
    protected Scene() {
    	/*
    	 * 这里需要检查mPointer是否为0，对于TransitionScene以及他们的子类来说，
    	 * 我们不需要打开key事件处理，而且我们也打不开，因为TransitionScene以及
    	 * 它们的子类此时还没有生成底层实例，会导致setKeyEnabled失败，因此必须
    	 * 要做一个空指针检查
    	 */
    	if(mPointer != 0)
    		setKeyEnabled(true);
    }
    
    /**
     * 从底层指针获得一个Scene的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Scene}
     */
    public static Scene from(int pointer) {
    	return pointer == 0 ? null : new Scene(pointer);
    }
    
    protected Scene(int pointer) {
    	super(pointer);
    }
    
	protected void doNativeInit() {
		nativeInit();
	}
    
    private native void nativeInit();
    
    @Override
    protected boolean onBackButton() {
    	Director.getInstance().popScene();
    	return true;
    }
}