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

#ifndef __wyEventDispatcher_ios_h__
#define __wyEventDispatcher_ios_h__

#if IOS

#include "wyEventDispatcher.h"
#include "wyTypes.h"
#include "wyUtils.h"

/**
 * @class wyEventDispatcher_ios
 *
 * \if English
 * iOS implementation of event dispatcher
 * \else
 * iOS平台事件派发器的特定实现部分
 * \endif
 */
class wyEventDispatcher_ios : public wyEventDispatcher {
	friend class wyEventDispatcher;
	
protected:
	wyEventDispatcher_ios();

	/// @see wyEventDispatcher::checkAccelHandlers
	virtual void checkAccelHandlers();

	/// @see wyEventDispatcher::checkDoubleTapHandlers
	virtual void checkDoubleTapHandlers();

	/// @see wyEventDispatcher::checkGestureHandlers
	virtual void checkGestureHandlers();

	/// @see wyEventDispatcher::buildKeyEvent
	virtual wyEvent* buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe);

	/// @see wyEventDispatcher::queueMotionEvent
	virtual void queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe);

	/// @see wyEventDispatcher::queueMotionEvent
	virtual void queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy);

public:
	virtual ~wyEventDispatcher_ios();

	/**
	 * 把一个UITouch对象指针进行索引
	 *
	 * @param pointer UITouch的指针
	 */
	static void indexUITouch(int pointer);
	
	/**
	 * 解除某个UITouch对象的索引映射
	 *
	 * @param pointer UITouch的指针
	 */
	static void unindexUITouch(int pointer);
	
	/**
	 * 查找一个UITouch对象的索引
	 *
	 * @param pointer UITouch的指针
	 * @return UITouch对象的索引
	 */
	static int indexOfUITouch(int pointer);
	
	/**
	 * 模拟一个按键按下事件
	 *
	 * @param keyCode 按键的代码, 和android平台的定义一致, 例如KEYCODE_MENU
	 */
	void simulateKeyDown(wyKeyCode keyCode);

	/**
	 * 模拟一个按键松开事件
	 *
	 * @param keyCode 按键的代码, 和android平台的定义一致, 例如KEYCODE_MENU
	 */
	void simulateKeyUp(wyKeyCode keyCode);

	/**
	 * 模拟一个按键长按事件
	 *
	 * @param keyCode 按键的代码, 和android平台的定义一致, 例如KEYCODE_MENU
	 * @param repeatCount 重复次数
	 */
	void simulateKeyMultiple(wyKeyCode keyCode, int repeatCount);
};

#endif // #if IOS

#endif // __wyEventDispatcher_ios_h__
