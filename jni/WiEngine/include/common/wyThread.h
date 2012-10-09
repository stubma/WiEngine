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
#ifndef __wyThread_h__
#define __wyThread_h__

#include "wyTargetSelector.h"

/**
 * @class wyThread
 *
 * \if English
 * Encapsulate a thread forking logic which accepts a target selector as thread entry point
 * \else
 * 只用来封装native线程操作, 通过一个\link wyTargetSelector wyTargetSelector\endlink来指定
 * 线程入口
 * \endif
 */
class WIENGINE_API wyThread {
private:
	/**
	 * \if English
	 * New a thread and run it
	 *
	 * @param arg pointer to \link wyThreadCallback wyThreadCallback\endlink
	 * \else
	 * 异步执行函数。
	 *
	 * @param arg 调用参数，为\link wyThreadCallback wyThreadCallback\endlink指针
	 * \endif
	 */
	static void* run(void* arg);

	/**
	 * \if English
	 * Invoked when thread starts
	 *
	 * @return anything which will be passed to \c postRun
	 * \else
	 * 在开始线程时调用
	 *
	 * @return 返回的任意结果, 将会被传递给\c postRun
	 * \endif
	 */
	static void* preRun();

	/**
	 * \if English
	 * Invoked when thread will exit
	 *
	 * @param arg anything returned by \c preRun
	 * \else
	 * 在线程将要退出时调用
	 *
	 * @param arg \c preRun返回的参数
	 * \endif
	 */
	static void postRun(void* arg);

public:
	wyThread();

	virtual ~wyThread();

	/**
	 * \if English
	 * Start a new thread and execute selector
	 *
	 * @param sel the thread entry point
	 * @return status of pthread
	 * \else
	 * 内部启动子线程执行callback方法，只用于native子线程。
	 *
	 * @param sel 回调函数入口的选择子
	 * @return pthread_create返回状态
	 * \endif
	 */
	static int runThread(wyTargetSelector* sel);
};

#endif // __wyThread_h__
