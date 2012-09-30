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
#ifndef __wyClipOutTransition_h__
#define __wyClipOutTransition_h__

#include "wyTransitionScene.h"
#include "wyClipOut.h"

/**
 * @class wyClipOutTransition
 *
 * \if English
 * Old scene uses clip out action to hide itself gradually so new scene becomes visible
 * \else
 * 旧的场景通过\link wyClipOut wyClipOut\endlink逐渐隐藏从而显示新场景
 * \endif
 */
class WIENGINE_API wyClipOutTransition : public wyTransitionScene {
private:
	/// clip shrink direction
	wyClipOut::Direction m_direction;

protected:
	/**
	 * Constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene new scene
	 * @param direction clip shrink direction
	 * \see wyClipOut::Direction
	 */
	wyClipOutTransition(float duration, wyScene* inScene, wyClipOut::Direction direction);

	/// @see wyTransitionScene::shouldInSceneOnTop
	virtual bool shouldInSceneOnTop() { return false; }

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

public:
	virtual ~wyClipOutTransition();

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene new scene
	 * @param direction clip shrink direction
	 * @return \link wyClipOutTransition wyClipOutTransition\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param duration 转场持续时间
	 * @param inScene 新场景
	 * @param direction 裁剪区域收缩方向
	 * @return \link wyClipOutTransition wyClipOutTransition\endlink
	 * \endif
	 * \see wyClipOut::Direction
	 */
	static wyClipOutTransition* make(float duration, wyScene* inScene, wyClipOut::Direction direction);
};

#endif // __wyClipOutTransition_h__
