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
#ifndef __wySuckTransition_h__
#define __wySuckTransition_h__

#include "wyTransitionScene.h"

/**
 * @class wySuckTransition
 *
 * \if English
 * Transition which uses suck effect
 * \else
 * 使用吸入效果的转场类
 * \endif
 */
class WIENGINE_API wySuckTransition : public wyTransitionScene {
protected:
	/**
	 * \if English
	 * x position
	 * \else
	 * 吸入点x坐标
	 * \endif
	 */
	float m_suckX;

	/**
	 * \if English
	 * y position
	 * \else
	 * 吸入点y坐标
	 * \endif
	 */
	float m_suckY;

protected:
	/// @see wyTransitionScene::shouldInSceneOnTop
	virtual bool shouldInSceneOnTop();

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene the scene will be switched in. If not NULL, then out scene is current scene.
	 * 		If NULL, the out scene is not set also and somebody must set them after make returns. Generally
	 * 		you will set \c inScene NULL when uses popSceneWithTransition and \link wyDirector wyDirector\endlink
	 * 		will set in and out scene automatically.
	 * @param suckX x position of sucking
	 * @param suckY y position of sucking
	 * \else
	 * 构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 * @param suckX 吸入点的x位置
	 * @param suckY 吸入点的y位置
	 * \endif
	 */
	wySuckTransition(float duration, wyScene* inScene, float suckX, float suckY);

public:
	/**
	 * \if English
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
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 * @param suckX 吸入点的x位置
	 * @param suckY 吸入点的y位置
	 * @return \link wySuckTransition wySuckTransition\endlink
	 * \endif
	 */
	static wySuckTransition* make(float duration, wyScene* inScene, float suckX, float suckY);

	/**
	 * 析构函数
	 */
	virtual ~wySuckTransition();
};

#endif // __wySuckTransition_h__
