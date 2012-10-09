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
#ifndef __wyDialogTransition_h__
#define __wyDialogTransition_h__

#include "wyIntervalAction.h"

class wyDialog;

/**
 * @class wyDialogTransition
 *
 * \if English
 * Effect when open or close dialog
 * \else
 * 封装对话框出现, 消失的效果
 * \endif
 */
class WIENGINE_API wyDialogTransition : public wyObject {
protected:
	wyDialogTransition();

	/// invoked when out action is stopped
	static void onOutActionStopped(wyAction* action, void* data);

	/// invoked when in action is stopped
	static void onInActionStopped(wyAction* action, void* data);

	/**
	 * Get action which is applied when showing dialog
	 *
	 * @return \link wyIntervalAction wyIntervalAction\endlink
	 */
	virtual wyIntervalAction* getInAction();

	/**
	 * Get action which is applied when dismissing dialog
	 *
	 * @return \link wyIntervalAction wyIntervalAction\endlink
	 */
	virtual wyIntervalAction* getOutAction();

public:
	virtual ~wyDialogTransition();

	/**
	 * \if English
	 * Apply in action to dialog
	 *
	 * @param dialog dialog object
	 * \else
	 * 对对话框执行显示效果
	 *
	 * @param dialog 对话框对象
	 * \endif
	 */
	virtual void applyIn(wyDialog* dialog);

	/**
	 * \if English
	 * Apply out action to dialog
	 *
	 * @param dialog dialog object
	 * \else
	 * 对对话框执行隐藏效果
	 *
	 * @param dialog 对话框对象
	 * \endif
	 */
	virtual void applyOut(wyDialog* dialog);
};

#endif // __wyDialogTransition_h__
