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
#ifndef __wyScene_h__
#define __wyScene_h__

#include "wyNode.h"

/**
 * @class wyScene
 *
 * 场景对象的封装
 */
class WIENGINE_API wyScene : public wyNode {
private:
	/// true means back key is in tracking
	bool m_backKeyTracing;

public:
	static wyScene* make();
	
	/**
	 * 构造函数
	 */
	wyScene();

	/**
	 * 析构函数
	 */
	virtual ~wyScene();

	/// @see wyNode::keyDown
	virtual bool keyDown(wyKeyEvent& event);

	/// @see wyNode::keyUp
	virtual bool keyUp(wyKeyEvent& event);

	/**
	 * Check whether it is a transition scene, if subclass is a transition it should override
	 * it and returns true
	 *
	 * @return true means it is a transition scene, generally it means it is a subclass
	 * of \link wyTransitionScene wyTransitionScene\endlink
	 */
	virtual bool isTransition() { return false; }
};

#endif // __wyScene_h__
