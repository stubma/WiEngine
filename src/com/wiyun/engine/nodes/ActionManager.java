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

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.actions.Action;

/**
 * <p>
 * ActionManager负责管理节点和动作之间的映射关系。 
 * </p>
 * 
 * <p>
 * ActionManager是一个单例的动作管理器。一般情况下，不需要直接使用ActionManager，而应该通过Node的方法进行动作的执行。
 * 有些情况下可能需要直接使用ActionManager, 比如你想暂停或者恢复一个动作，又比如当前Node不是动作的目标
 * </p>
 */
public class ActionManager extends BaseWYObject {
    private static ActionManager sInstance = null;

    /**
     * 得到ActionManager的单一实例
     * 
     * @return {@link ActionManager}
     */
    public static ActionManager getInstance() {
        synchronized (ActionManager.class) {
            if (sInstance == null) {
                sInstance = new ActionManager();
            } else {
            	sInstance.setPointer(nativeGetInstance());
            }
            return sInstance;
        }
    }
    

    private ActionManager() {
    	nativeInit();
    }
    
    private native static int nativeGetInstance();
    private native void nativeInit();

    /**
     * 暂停某个节点上的所有动作
     * 
     * @param target {@link Node}
     */
    public void pauseAllActions(Node target) {
    	pauseAllActions(target, false);
    }
    
    /**
     * 暂停某个节点上的所有动作
     * 
     * @param target {@link Node}
     * @param includeChildren true表示也同时暂停target的子节点上的动作
     */
    public native void pauseAllActions(Node target, boolean includeChildren);

    /**
     * 恢复某个节点上的所有动作
     * 
     * @param target {@link Node}
     */
    public void resumeAllActions(Node target) {
    	resumeAllActions(target, false);
    }
    
    /**
     * 恢复某个节点上的所有动作
     * 
     * @param target {@link Node}
     * @param includeChildren true表示也同时恢复target的子节点上的动作
     */
    public native void resumeAllActions(Node target, boolean includeChildren);
    
    /**
     * 添加一个动作到某个节点
     * 
     * @param action 动作
     * @param target 节点
     * @param paused 是否初始处于暂停状态
     */
    public native void addAction(Action action, Node target, boolean paused);

    /**
     * 删除所有节点上的所有动作
     */
    public native void removeAllActions();

    /**
     * 删除某个节点上的所有动作
     * 
     * @param target {@link Node}
     */
    public native void removeAllActions(Node target);
    
    /**
     * 删除某个节点上的所有动作
     * 
     * @param target {@link Node}
     * @param includeChildren true表示也删除子节点下的所有动作
     */
    public native void removeAllActions(Node target, boolean includeChildren);

    /**
     * 删除一个动作
     */
    public native void removeAction(Action action);

    /**
     * 根据tag从某个节点上删除一个动作
     */
    public native void removeAction(Node target, int tag);
    
    /**
     * 返回在某个节点上正在运行的动作的个数，对于组合式动作，只算一个
     */
    public native int getRunningActionCount(Node target);
}
