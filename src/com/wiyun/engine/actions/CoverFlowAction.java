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

import com.wiyun.engine.nodes.Cover;

/**
 * \if English
 * Action to move a cover in \link CoverFlow CoverFlow\endlink, it brings target cover
 * to front with an animation
 * \else
 * 节点\link CoverFlow CoverFlow\endlink 的action, 把目标封面移动到最前
 * \endif
 */
public class CoverFlowAction extends IntervalAction {
	/**
	 * \if English
	 * CoverFlowAction doesn't support cloning
	 * \else
	 * CoverFlowAction不支持拷贝方法
	 * \endif
	 */
	@Override
	public IntervalAction copy() {
		throw new UnsupportedOperationException("CoverFlowAction doesn't have reverse action");
	}
	
	/**
	 * \if English
	 * CoverFlowAction doesn't have reverse action
	 * \else
	 * CoverFlowAction不支持逆向动作
	 * \endif
	 */
	@Override
	public IntervalAction reverse() {
		throw new UnsupportedOperationException("CoverFlowAction doesn't have reverse action");
	}
	
	protected CoverFlowAction(){};

	protected CoverFlowAction(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, Cover targetCover);

	protected CoverFlowAction(float duration, Cover targetCover) {
		nativeInit(duration, targetCover);
	}

	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration action duration in seconds
	 * @param targetCover target \link Cover Cover\endlink object which should be moved to front
	 * @return \link CoverFlowAction CoverFlowAction\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动画执行时间
	 * @param targetCover 指定下一个当前cover
	 * @return \link CoverFlowAction CoverFlowAction\endlink
	 * \endif
	 */
	public static CoverFlowAction make(float duration, Cover targetCover) {
		return new CoverFlowAction(duration, targetCover);
	}

	public static CoverFlowAction from(int pointer) {
		return pointer == 0 ? null : new CoverFlowAction(pointer);
	}
}