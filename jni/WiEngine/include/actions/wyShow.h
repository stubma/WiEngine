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
#ifndef __wyShow_h__
#define __wyShow_h__

#include "wyInstantAction.h"

/**
 * @class wyShow
 *
 * \if English
 * Make a node visible
 * \else
 * 节点可见的动作封装，对节点执行可见操作
 * \endif
 */
class WIENGINE_API wyShow : public wyInstantAction {
protected:
	wyShow();

public:
	static wyShow* make();

	virtual ~wyShow();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/**
	 * \if English
	 * return the reverse action of show, actually it is a \link wyHide wyHide\endlink
	 *
	 * @return \link wyHide wyHide\endlink
	 * \else
	 * 返回show的反转操作，实际是\link wyHide wyHide\endlink对象指针
	 *
	 * @return \link wyAction wyAction\endlink对象指针
	 * \endif
	 */
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyShow_h__
