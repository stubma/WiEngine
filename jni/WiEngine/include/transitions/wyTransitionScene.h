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
#ifndef __wyTransitionScene_h__
#define __wyTransitionScene_h__

#include "wyScene.h"
#include "wyIntervalAction.h"
#include "wyEaseAction.h"
#include <stdbool.h>
#include "wyGlobal.h"

/**
 * @class wyTransitionScene
 *
 * 场景切换效果的封装, 是所有场景切换的基类
 */
class WIENGINE_API wyTransitionScene : public wyScene {
protected:
	/// 准备载入的\link wyScene wyScene对象指针\endlink
	wyScene* m_inScene;

	/// 准备载出的\link wyScene wyScene对象指针\endlink，一般为wyDirector::getRunningScene
	wyScene* m_outScene;

	/// 场景切换的持续时间
	float m_duration;

	/// 进场效果的ease动作
	wyEaseAction* m_inEase;

	/// 出场效果的ease动作
	wyEaseAction* m_outEase;

	/// target selector invoked when transition is done
	wyTargetSelector* m_finishSelector;

protected:
	/**
	 * 获得是否准备载入的场景在当前场景的上层
	 *
	 * @return true为是
	 */
	virtual bool shouldInSceneOnTop();

	/**
	 * 当完成场景切换后调用此方法，可以在子类重载该方法
	 */
	virtual void postFinish();

	/**
	 * 对场景准备开始切换做准备工作，可以在子类重载该方法
	 */
	virtual void initScenes();

	/**
	 * 返回载入场景效果的\link wyNode wyNode对象指针\endlink
	 *
	 * @return 载入场景效果的\link wyNode wyNode对象指针\endlink
	 */
	virtual wyNode* getInActionTarget();

	/**
	 * 返回载出场景效果的\link wyNode wyNode对象指针\endlink
	 *
	 * @return 载出场景效果的\link wyNode wyNode对象指针\endlink
	 */
	virtual wyNode* getOutActionTarget();

	/**
	 * 返回载入场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 *
	 * @return 载入场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 */
	virtual wyIntervalAction* getInAction();

	/**
	 * 返回载出场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 *
	 * @return 载出场景动作\link wyIntervalAction wyIntervalAction对象指针\endlink
	 */
	virtual wyIntervalAction* getOutAction();

	/**
	 * 设置wyDirector的当前场景为inScene,并激活事件派发机制
	 */
	void setNewScene(wyTargetSelector* ts);

	/**
	 * 构造函数, 直接使用当前正在运行的场景为载出场景, 载入场景需要指定.
	 *
	 * @param duration 场景切换的持续时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 */
	wyTransitionScene(float duration, wyScene* inScene);

public:
	/**
	 * \if English
	 * Static constructor to create a do-nothing transition
	 *
	 * @param duration duration time of transition, in seconds
	 * @param inScene incoming scene, or NULL if you want to use transiton when pop scene
	 * @return \link wyTransitionScene wyTransitionScene\endlinnk
	 * \else
	 * 创建一个什么也不做的转场效果, 由于这是所有转场效果的基类, 因此其并无任何动画逻辑. 但是也许有时候
	 * 这个还真用得上.
	 *
	 * @param duration 转场持续时间
	 * @param inScene 准备载入的\link wyScene wyScene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link wyDirector wyDirector\endlink
	 * 		会自动设置载入和载出场景.
	 * @return \link wyTransitionScene wyTransitionScene\endlink
	 * \endif
	 */
	static wyTransitionScene* make(float duration, wyScene* inScene);

	/**
	 * 析构函数
	 */
	virtual ~wyTransitionScene();

	/// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::onEnter
	virtual void onEnter();

	/// @see wyNode::onExit
	virtual void onExit();

	/// @see wyScene::isTransition
	virtual bool isTransition() { return true; }

	/**
	 * 当场景切换完成后调用该方法
	 */
	void finish(wyTargetSelector* ts);

	/**
	 * 隐藏载出场景并可见载入场景
	 */
	void hideOutShowIn(wyTargetSelector* ts);

	/**
	 * 获得载入的\link wyScene wyScene对象指针\endlink
	 *
	 * @return 载入的\link wyScene wyScene对象指针\endlink
	 */
	wyScene* getInScene() { return m_inScene; }

	/**
	 * 设置载入场景, 只能在运行前设置.
	 *
	 * @param scene 需要载入的场景
	 */
	void setInScene(wyScene* scene);

	/**
	 * 获得载出的\link wyScene wyScene对象指针\endlink
	 *
	 * @return 载出的\link wyScene wyScene对象指针\endlink
	 */
	wyScene* getOutScene() { return m_outScene; }

	/**
	 * 设置载出场景, 只能在运行前设置.
	 *
	 * @param scene 需要载出的场景
	 */
	void setOutScene(wyScene* scene);

	/**
	 * 获得场景切换设置的时间
	 *
	 * @return 场景切换设置的时间
	 */
	float getDuration() { return m_duration; }

	/**
	 * 设置入场效果的ease动作. 内置的转换效果都是线性的, 如果想给它们设置一个非线性效果, 则
	 * 必须在转换开始之前设置. 不过给转换动画设置非线性效果需要适当的运用, 不然出入场动画不匹配
	 * 则会比较难看.
	 *
	 * @param inEase \link wyEaseAction wyEaseAction\endlink的子类
	 */
	void setInEaseAction(wyEaseAction* inEase);

	/**
	 * 设置出场效果的ease动作. 内置的转换效果都是线性的, 如果想给它们设置一个非线性效果, 则
	 * 必须在转换开始之前设置. 不过给转换动画设置非线性效果需要适当的运用, 不然出入场动画不匹配
	 * 则会比较难看.
	 *
	 * @param outEase \link wyEaseAction wyEaseAction\endlink的子类
	 */
	void setOutEaseAction(wyEaseAction* outEase);

	/**
	 * \if English
	 * Set a target selector which is called when transition is finished
	 *
	 * @param ts target selector object
	 * \else
	 * 设置一个选择子用于在转场结束时调用
	 *
	 * @param ts 被调用的选择子
	 * \endif
	 */
	void setFinishCallback(wyTargetSelector* ts);
};

#endif // __wyTransitionScene_h__
