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
#ifndef __wyCameraAction_h__
#define __wyCameraAction_h__

#include "wyIntervalAction.h"

/**
 * @class wyCameraAction
 *
 * \if English
 * Base class for camera action
 * \else
 * 相机类动作的基类。相机类动作通过移动视点来产生特殊效果
 * \endif
 */
class WIENGINE_API wyCameraAction : public wyIntervalAction {
protected:
	float m_centerX;
	float m_centerY;
	float m_centerZ;

	float m_eyeX;
	float m_eyeY;
	float m_eyeZ;

	float m_upX;
	float m_upY;
	float m_upZ;

protected:
	/**
	 * Contructor
	 *
	 * @param duration action duration in seconds
	 */
	wyCameraAction(float duration);

public:
	virtual ~wyCameraAction();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);
};

#endif // __wyCameraAction_h__
