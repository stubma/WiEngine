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
#ifndef __wyAnimate_h__
#define __wyAnimate_h__

#include "wyIntervalAction.h"
#include "WiEngine-Classes.h"

/**
 * Encapsulate animation action, it requires a \link wyAnimation wyAnimation\endlink object which
 * provides frame info
 */
class WIENGINE_API wyAnimate : public wyIntervalAction {
protected:
	/// \link wyAnimation wyAnimation\endlink pointer
	wyAnimation* m_anim;

	/**
	 * the original frame before animation started, it will be restored
	 * if fill after flag is set to false
	 */
	wyFrame* m_originFrame;

	/**
	 * false indicating original frame should be restored after animation ended, true means
	 * keep last frame
	 */
	bool m_fillAfter;

	/// true means original frame is saved
	bool m_originFrameSaved;

protected:
	/**
	 * Constructor
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 */
	wyAnimate(wyAnimation* anim, bool fillAfter = false);

public:
	/**
	 * Static factory method
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 */
	static wyAnimate* make(wyAnimation* anim, bool fillAfter = false);

	virtual ~wyAnimate();

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

#endif // __wyAnimate_h__
