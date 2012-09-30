/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyCallFunc_h__
#define __wyCallFunc_h__

#include "wyInstantAction.h"
#include "wyTargetSelector.h"

/**
 * @class wyCallFunc
 *
 * \if English
 * Call a function specified by \link wyTargetSelector wyTargetSelector\endlink, this
 * action is an instant action so it is done immediately. Method pointed by \link wyTargetSelector wyTargetSelector\endlink
 * must have no arguments
 * \else
 * 节点调用\link wyTargetSelector wyTargetSelector\endlink的动作封装, \link wyTargetSelector wyTargetSelector\endlink指向的
 * 方法不能有参数
 * \endif
 */
class WIENGINE_API wyCallFunc : public wyInstantAction {
protected:
	/**
	 * \if English
	 * the \link wyTargetSelector wyTargetSelector\endlink object
	 * \else
	 * 动作要执行的\link wyTargetSelector wyTargetSelector\endlink对象指针
	 * \endif
	 */
	wyTargetSelector* m_targetSelector;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param ts \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 构造函数
	 *
	 * @param ts 动作要执行的\link wyTargetSelector wyTargetSelector\endlink对象指针
	 * \endif
	 */
	wyCallFunc(wyTargetSelector* ts);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param ts \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param ts 动作要执行的\link wyTargetSelector wyTargetSelector\endlink对象指针
	 * \endif
	 */
	static wyCallFunc* make(wyTargetSelector* ts);

	virtual ~wyCallFunc();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/**
	 * \if English
	 * This action doesn't have reverse action, so \c reverse method returns NULL
	 *
	 * @return NULL
	 * \else
	 * 此动作不支持反转，返回为NULL
	 *
	 * @return NULL
	 * \endif
	 */
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyCallFunc_h__
