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
package com.wiyun.engine;

/**
 * \if English
 * It is java counterpart of C++ wyObject class
 * \else
 * 代表了底层的wyObject类，wyObject通过引用计数维护，因此这个类里提供一些
 * 和引用计数相关的方法。
 * \endif
 */
public abstract class BaseWYObject extends BaseObject {
	protected BaseWYObject() {
	}
	
	protected BaseWYObject(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * \par
	 * WiEngine is implemented with C++, so native object need to be released manually when 
	 * you programming in java layer. That's the purpose of autoRelease. If it is called, 
	 * native object will be released when no objects refer it. This method doesn't release
	 * native object immediately, just ensure they will be released.
	 * 
	 * \par
	 * Duplicated calling is safe and only first time is processed
	 * \else
	 * \par
	 * 由于WiEngine 2.0采用native实现, 当使用java开发时, 底层对象的
	 * 释放需要开发者手动控制, 为此提供了这个方法. 调用这个方法后底层
	 * 的对象将不被java层引用, 因此底层对象将在不被使用时被释放. 注意这个
	 * 方法不能保证底层对象立刻被删除, 只能确保底层对象会被正常删除.
	 * 
	 * \par
	 * 这个方法反复调用是安全的, 不会造成底层引用计数混乱. 多余的调用会被
	 * 底层忽略
	 * \endif
	 */
	public BaseWYObject autoRelease() {
		nativeAutoRelease();
		return this;
	}
	
	private native void nativeAutoRelease();
	
	/**
	 * \if English
	 * Set object name
	 * 
	 * @param name object name
	 * \else
	 * 设置对象名
	 * 
	 * @param name 对象名
	 * \endif
	 */
	public native void setName(String name);
	
	/**
	 * \if English
	 * Get object name
	 * 
	 * @return object name, or null if not set
	 * \else
	 * 获得对象名
	 * 
	 * @return 对象名字符串, 如果没有设置过, 则返回null
	 * \endif
	 */
	public native String getName();
	
	/**
	 * \if English
	 * Make a bridge so that java layer object can receive native target selector event. 
	 * If called, native target selector will be redirected to \c onTargetSelectorInvoked method so
	 * subclass can override it to process native event. This method is designed for easily handle
	 * event for lua.
	 * \else
	 * 使该java对象能够收到底层的target selector事件. 调用这个方法后, 底层的
	 * target selector事件会被派发到\c onTargetSelectorInvoked方法, 因此子类需要
	 * 实现这个方法以便能处理底层事件. 这个方法主要是为了能够处理lua脚本中创建的
	 * target selector.
	 * \endif
	 */
	public native void connectNativeTargetSelector();
	
	/**
	 * \if English
	 * \c onTargetSelectorInvoked is actually an event handler in native layer so generally useless in
	 * java side. But since WiEngine 3.4.0, lua module is refactored so we need a solution to handle
	 * native target selector event. That's why we defined it for lua, only for lua.
	 * 
	 * @param id id of target selector
	 * @param delta time carried by target selector, it makes sense if target selector is triggered
	 * 		by a timer
	 * \else
	 * \c onTargetSelectorInvoked实际上是一个native层的事件处理方法, 在java端是用不到的. 不过从
	 * WiEngine 3.4.0版本之后, lua模块经过了大量重构, 因此需要一种能让java端收到native端target
	 * selector事件的方法. 这个方法就是用于这个目的, 目前它只用于lua脚本的情况, 其它情况下实现
	 * 这个方法并无作用.
	 *
	 * @param id target selector的id
	 * @param delta target selector附带的delta时间, 如果这个target selector是由某个timer触发的, 则该字段有意义
	 * \endif
	 */
	public void onTargetSelectorInvoked(int id, float delta) {
	}
}
