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
 * 复合式层。可以用来包含多个层，但任何时刻只有一个层是可见的。
 */
public class MultiplexLayer extends Layer {
    /**
     * 创建复合层
     * 
     * @param params 要包含的层，可变参数
     * @return 复合层实例
     */
    public static MultiplexLayer make(Layer... params) {
        return new MultiplexLayer(params);
    }

    /**
     * 构造函数
     * 
     * @param params 要包含的层，可变参数
     */
    protected MultiplexLayer(Layer... params) {
    	nativeInit();
    	for(Layer layer : params)
    		addLayer(layer);
    }
    
    /**
     * 从底层指针获得一个MultiplexLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MultiplexLayer}
     */
    public static MultiplexLayer from(int pointer) {
    	return pointer == 0 ? null : new MultiplexLayer(pointer);
    }
    
    protected MultiplexLayer(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit();
    
    /**
     * 添加一个层
     * 
     * @param layer {@link Layer}
     */
    public native void addLayer(Layer layer);
    
    /**
     * 得到当前层，-1表示没有当前层
     */
    public native int getCurrentLayerIndex();

    /**
     * 切换到某个层，通过层的索引，第一个添加的层索引是0，依此类推
     * 
     * @param n 层索引，如果小于0，没有效果。如果大于层的个数，会取余数。
     */
    public native void switchTo(int n);
}

