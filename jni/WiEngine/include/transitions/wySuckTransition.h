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
#ifndef __wySuckTransition_h__
#define __wySuckTransition_h__

#include "wyTransitionScene.h"

/**
 * @class wySuckTransition
 *
 * Transition which uses suck effect
 */
class WIENGINE_API wySuckTransition : public wyTransitionScene {
protected:
	/**
	 * x position
	 */
	float m_suckX;

	/**
	 * y position
	 */
	float m_suckY;

protected:
	/// @see wyTransitionScene::shouldInSceneOnTop
	virtual bool shouldInSceneOnTop();

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

	/**
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene the scene will be switched in. If not NULL, then out scene is current scene.
	 * 		If NULL, the out scene is not set also and somebody must set them after make returns. Generally
	 * 		you will set \c inScene NULL when uses popSceneWithTransition and \link wyDirector wyDirector\endlink
	 * 		will set in and out scene automatically.
	 * @param suckX x position of sucking
	 * @param suckY y position of sucking
	 */
	wySuckTransition(float duration, wyScene* inScene, float suckX, float suckY);

public:
	/**
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene the scene will be switched in. If not NULL, then out scene is current scene.
	 * 		If NULL, the out scene is not set also and somebody must set them after make returns. Generally
	 * 		you will set \c inScene NULL when uses popSceneWithTransition and \link wyDirector wyDirector\endlink
	 * 		will set in and out scene automatically.
	 * @param suckX x position of sucking
	 * @param suckY y position of sucking
	 * @return \link wySuckTransition wySuckTransition\endlink
	 */
	static wySuckTransition* make(float duration, wyScene* inScene, float suckX, float suckY);

	/**
	 * 析构函数
	 */
	virtual ~wySuckTransition();
};

#endif // __wySuckTransition_h__
