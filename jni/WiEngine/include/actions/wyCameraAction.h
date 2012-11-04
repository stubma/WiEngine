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
#ifndef __wyCameraAction_h__
#define __wyCameraAction_h__

#include "wyIntervalAction.h"

/**
 * Base class for camera action
 */
class WIENGINE_API wyCameraAction : public wyIntervalAction {
protected:
	/// camera center x
	float m_centerX;

	/// camera center y
	float m_centerY;

	/// camera center z
	float m_centerZ;

	/// eye x
	float m_eyeX;

	/// eye y
	float m_eyeY;

	/// eye z
	float m_eyeZ;

	/// positive direction x
	float m_upX;

	/// positive direction y
	float m_upY;

	/// positive direction z
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
