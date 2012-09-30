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
#ifndef __wyZoomFlipAngularTransition_h__
#define __wyZoomFlipAngularTransition_h__

#include "wyTransitionScene.h"

/**
 * @class wyZoomFlipAngularTransition
 *
 * 新旧场景沿某个角度旋转180度，同时有一定的缩放
 */
class WIENGINE_API wyZoomFlipAngularTransition : public wyTransitionScene {
protected:
	/// 标识向左还是向右旋转，true为向左
	bool m_toLeft;

	/// 缩放比，标识旧场景的目标缩放比和新场景的其实缩放比
	float m_scale;

	/// @see wyTransitionScene::initScenes
	virtual void initScenes();

	/// @see wyTransitionScene::getInAction
	virtual wyIntervalAction* getInAction();

	/// @see wyTransitionScene::getOutAction
	virtual wyIntervalAction* getOutAction();

public:
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 * @param toLeft 标识向左还是向右旋转，true为向左
	 * @param scale 缩放比
	 */
	static wyZoomFlipAngularTransition* make(float duration, wyScene* inScene, bool toLeft, float scale);

	/**
	 * 构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 * @param toLeft 标识向左还是向右旋转，true为向左
	 * @param scale 缩放比
	 */
	wyZoomFlipAngularTransition(float duration, wyScene* inScene, bool toLeft, float scale);

	/**
	 * 析构函数
	 */
	virtual ~wyZoomFlipAngularTransition();
};

#endif // __wyZoomFlipAngularTransition_h__
