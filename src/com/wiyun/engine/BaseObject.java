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
 * It is a bridge object from java to native layer. It has a member \c mPointer which
 * is actually a pointer of underlying C++ object. So, every subclass of \c BaseObject
 * is indeed a wrapper object for a C++ counterpart.
 * \else
 * 作为Java层到Native层的桥梁，封装了底层对象的指针以及一些访问指针的方法。这个类代表了
 * 一个通用的由底层实现但是却有java层封装的对象, java层一般只是一个wrap，其包含一个成员
 * 指向底层对象。
 * \endif
 */
public abstract class BaseObject {
	/**
	 * \if English
	 * pointer to underlying C++ object
	 * \else
	 * 底层C++对象的指针
	 * \endif
	 */
	protected int mPointer;
	
	protected BaseObject() {
	}
	
	protected BaseObject(int pointer) {
		mPointer = pointer;
	}
	
	/**
	 * \if English
	 * Set a native pointer to this java wrapper. You must ensure
	 * the native pointer type appropriate for this java type. This operation
	 * eliminates need to create new java wrapper for every native object so it
	 * is more efficient.
	 * 
	 * @param pointer native object pointer
	 * \else
	 * 手动修改java对象对应的native层对象指针, 这个操作具有一定的危险性, 
	 * 在这么做之前务必清楚你在做什么. 不过如果应用频繁的从底层指针生成
	 * java对象, 则这个方法会更有效率, 可以节省内存. 不然使用对象的from
	 * 方法, 每次都会生成一个新对象, 对内存是一个浪费.
	 * 
	 * @param pointer 底层对象指针
	 * \endif
	 */
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	/**
	 * \if English
	 * Get pointer of native object
	 * 
	 * @return pointer of native object
	 * \else
	 * 获得底层对象的指针
	 * 
	 * @return 底层对象的指针
	 * \endif
	 */
	public int getPointer() {
		return mPointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof BaseObject)
			return mPointer == ((BaseObject)o).getPointer();
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
}
