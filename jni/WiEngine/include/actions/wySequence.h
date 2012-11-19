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
#ifndef __wySequence_h__
#define __wySequence_h__

#include "WiEngine-Classes.h"
#include "wyIntervalAction.h"

/**
 * @class wySequence
 *
 * execute actions one by one
 */
class WIENGINE_API wySequence : public wyIntervalAction {
protected:
	/**
	 * action array
	 */
	wyArray* m_actions;

	/**
	 * the time split of two actions
	 */
	float m_split;

	/**
	 * current action index, 0 for first, 1 for second
	 */
	int m_last;

private:
	static bool releaseAction(wyArray* arr, void* ptr, int index, void* data);
	static bool stopAction(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * constructor
	 *
	 * @param action1 first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 * @param action2 second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 */
	wySequence(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2);

public:
	/**
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink
	 * @param action2 second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction\endlink, you can append more
	 * 		actions after this one and end with a NULL
	 * @return \link wySequence wySequence\endlink
	 */
	static wySequence* make(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2, ...);

	virtual ~wySequence();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wySequence_h__
