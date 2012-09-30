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

#ifndef __wyEventDispatcher_android_h__
#define __wyEventDispatcher_android_h__

#if ANDROID

#include "wyEventDispatcher.h"
#include <jni.h>

/**
 * @class wyEventDispatcher_android
 *
 * \if English
 * Android implementation of event dispatcher
 * \else
 * android平台事件派发器的特定实现部分
 * \endif
 */
class wyEventDispatcher_android : public wyEventDispatcher {
	friend class wyEventDispatcher;

protected:
	wyEventDispatcher_android();

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

	/// @see wyEventDispatcher::processUncommonEvent
	virtual void processUncommonEvent(wyEvent* e);

	/*
	 * dispatch
	 */

	virtual void dispatchAccelerometerChanged(wyNode* node, float accelX, float accelY, float accelZ);
	virtual bool dispatchKeyDown(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchKeyUp(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchKeyMultiple(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchTouchesBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesMoved(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesCancelled(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesPointerBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesPointerEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDoubleTap(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDoubleTapEvent(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnSingleTapConfirmed(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDown(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnFling(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float velocityX, float velocityY);
	virtual void dispatchOnLongPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnScroll(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float distanceX, float distanceY);
	virtual void dispatchOnShowPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnSingleTapUp(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);

public:
	virtual ~wyEventDispatcher_android();

	/**
	 * 把一个java端的runnable对象放入事件队列中, 这通常用来调度执行一些需要在OpenGL线程中执行
	 * 的操作, 只为java端API使用
	 */
	void queueRunnableLocked(jobject runnable);
};

#endif // #if ANDROID

#endif // __wyEventDispatcher_android_h__
