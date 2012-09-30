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
#ifndef __wyHide_h__
#define __wyHide_h__

#include "wyInstantAction.h"

/**
 * @class wyHide
 *
 * \if English
 * Hide a node by calling setVisible method. A node which is hidden will not draw and respond to events
 * \else
 * 节点隐藏的动作封装，对节点执行隐藏操作
 * \endif
 */
class WIENGINE_API wyHide : public wyInstantAction {
protected:
	wyHide();

public:
	static wyHide* make();

	virtual ~wyHide();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/**
	 * \if English
	 * Return the reversed action of \link wyHide wyHide\endlink, actually it is a \link wyShow wyShow\endlink object
	 *
	 * @return \link wyAction wyAction \endlink
	 * \else
	 * 返回hide的反转操作，实际是\link wyShow wyShow \endlink对象指针
	 *
	 * @return \link wyAction wyAction \endlink对象指针
	 * \endif
	 */
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyHide_h__
