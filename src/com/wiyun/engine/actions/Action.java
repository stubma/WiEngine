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
package com.wiyun.engine.actions;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.ICopyable;

/**
 * \if English
 * Base class for action. Action defines a special logic which can be performed on a
 * Node. Some actions require a specific Node type but most of them don't
 * \else
 * 动作的基类。动作封装一个特定行为，在运行时赋予动作一个目标，于是这个目标将会执行该动作。
 * 只有节点(Node)的子类才能执行一个动作。有些动作只有特定的节点类型才能运行，但是大部分动作都
 * 不限制节点具体类型
 * \endif
 */
public class Action extends BaseWYObject implements ICopyable {
	/**
	 * \if English
	 * \link Action Action\endlink callback definition.
	 * \else
	 * \link Action Action\endlink 的回调函数结构定义. 通过设置回调, 可以在
	 * \link Action Action\endlink 的执行过程中通过回调了解动作的执行进度, 以及
	 * 何时开始, 何时停止.
	 * \endif
	 */
	public static interface Callback {
		/**
		 * \if English
		 * Invoked when action is started
		 *
		 * @param actionPointer native pointer of action object, can use from method to get
		 * 		java side object
		 * \else
		 * 当动作开始执行时被调用
		 *
		 * @param actionPointer 动作对象的底层句柄，可以使用Action子类的相关方法从这个
		 * 		句柄中得到Action对象
		 * \endif
		 */
		public void onStart(int actionPointer);
		
		/**
		 * \if English
		 * Invoked when action is stopped, should call \c isDone to
		 * check whether action is terminated normally
		 *
		 * @param actionPointer native pointer of action object, can use from method to get
		 * 		java side object
		 * \else
		 * 当动作结束时被调用, 可以通过isDone来判断是否是正常结束
		 *
		 * @param actionPointer 动作对象的底层句柄，可以使用Action子类的相关方法从这个
		 * 		句柄中得到Action对象
		 * \endif
		 */
		public void onStop(int actionPointer);
		
		/**
		 * \if English
		 * Invoked every time when \c update method is called
		 *
		 * @param actionPointer native pointer of action object, can use from method to get
		 * 		java side object
		 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
		 * \else
		 * 在动作执行了update时被调用
		 *
		 * @param actionPointer 动作对象的底层句柄，可以使用Action子类的相关方法从这个
		 * 		句柄中得到Action对象
		 * @param t 当前时间点，从0到1
		 * \endif
		 */
		public void onUpdate(int actionPointer, float t);
	}
	
	/**
	 * \if English
	 * Generate a java action object from a native pointer
	 * 
	 * @param pointer native pointer of an action subclass
	 * @return \link Action Action\endlink
	 * \else
	 * 从底层的指针生成一个java端的动作对象
	 * 
	 * @param pointer 底层的指针
	 * @return \link Action Action\endlink
	 * \endif
	 */
	public static Action from(int pointer) {
		return pointer == 0 ? null : new Action(pointer);
	}
	
	/**
	 * \if English
	 * Get action target.
	 *
	 * @return \link Node Node\endlink object on which this action is running
	 * \else
	 * 获得执行动作节点\link Node Node\endlink对象指针
	 *
	 * @return 执行动作的\link Node Node\endlink对象指针
	 * \endif
	 */
    public Node getTarget() {
    	int pointer = nativeGetTarget();
    	return Node.from(pointer);
    }
    
	/**
	 * \if English
	 * Get action target pointer
	 *
	 * @return target pointer in native layer, or 0 if no node bound
	 * \else
	 * 获得执行动作节点的底层对象指针
	 *
	 * @return 执行动作的节点底层指针, 如果动作尚未开始在某个节点上运行， 则返回0
	 * \endif
	 */
    public int getTargetPointer() {
    	return nativeGetTarget();
    }
    
	/**
	 * \if English
	 * Get action tag
	 *
	 * @return action tag
	 * \else
	 * 获得动作标签
	 *
	 * @return 动作标签
	 * \endif
	 */
    public native int getTag();

	/**
	 * \if English
	 * Set tag for action. A tag can be used as an unique id of action and later
	 * you can retrieve it by Node::getAction method
	 *
	 * @param tag integer for action
	 * \else
	 * 设置动作标签
	 *
	 * @param tag 动作标签
	 * \endif
	 */
    public native void setTag(int tag);
    
    protected Action() {
    }
    
    protected Action(int pointer) {
    	super(pointer);
    }
    
	private native int nativeGetTarget();
    
	/**
	 * \if English
	 * Set java layer callback
	 *
	 * @param callback java side callback object, NULL means clear current callback
	 * \else
	 * 设置动作执行的java回调函数引用
	 *
	 * @param callback java回调函数对象, 如果为NULL，表示清除现有的callback
	 * \endif
	 */
    public native void setCallback(Callback callback);

	/**
	 * \if English
	 * Make a copy of current action object
	 *
	 * @return \link Action Action\endlink pointer
	 * \else
	 * 获得当前动作的复制
	 *
	 * @return \link Action Action\endlink对象指针
	 * \endif
	 */
    public Action copy() {
    	return null;
    }
    
    protected native int nativeCopy();
    
	/**
	 * \if English
	 * Make a reverse copy of this action object
	 *
	 * @return \link Action Action\endlink pointer
	 * \else
	 * 获得动作反转后的指针
	 *
	 * @return \link Action Action\endlink对象指针
	 * \endif
	 */
    public Action reverse() {
    	return null;
    }
    
    protected native int nativeReverse();
    
	/**
	 * \if English
	 * Start action. If callback is set, notify callback
	 *
	 * @param target the \link Node Node \endlink object on which this action is running
	 * \else
	 * 开始执行动作，如果动作有回调，会触发onStart回调函数
	 *
	 * @param target \link Node Node\endlink对象指针
	 * \endif
	 */
    public native void start(Node target);

	/**
	 * \if English
	 * Stop action. If callback is set, notify callback
	 * \else
	 * 停止动作，如果动作有回调，会触发onStop回调函数
	 * \endif
	 */
    public native void stop();

	/**
	 * \if English
	 * Check action state
	 *
	 * @return true indicating action is done
	 * \else
	 * 判断动作是否结束
	 *
	 * @return 动作是否结束
	 * \endif
	 */
    public native boolean isDone();

	/**
	 * \if English
	 * Update action with a single step
	 *
	 * @param t time from last step
	 * \else
	 * 步进动作
	 *
	 * @param t 上一次调用step到现在过去的时间
	 * \endif
	 */
    public native void step(float t);

	/**
	 * \if English
	 * Update action. If callback is set, notify callback.
	 *
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 * \else
	 * 更新动作执行的百分比，如果动作有回调，会触发onUpdate回调函数
	 *
	 * @param t 动作执行的相对时间，取值从0到1
	 * \endif
	 */
    public native void update(float t);
    
	/**
	 * \if English
	 * is action paused? There is not method called setPaused because you can't pause action
	 * directly. \link Node Node\endlink has pauseAction method and you can use that
	 *
	 * @return true means action is paused
	 * \else
	 * 动作是否已停止. 没有setPaused方法可以让你直接暂停动作, 比如通过\link Node Node\endlink的方法
	 * pauseAction暂停动作.
	 *
	 * @return true表示动作已经暂停
	 * \endif
	 */
	public native boolean isPaused();
	
    /**
     * \if English
     * is action running or not
     *
     * @return true means it is running
     * \else
     * 检查动作是否正在执行
     *
     * @return true表示正在执行
     * \endif
     */
	public native boolean isRunning();
}