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
#ifndef __wyTransitionScene_h__
#define __wyTransitionScene_h__

#include "wyScene.h"
#include "wyIntervalAction.h"
#include "wyEaseAction.h"
#include <stdbool.h>
#include "wyGlobal.h"

/**
 * Transition means effect when switching scenes. This is the base class for
 * other transition implementation
 */
class WIENGINE_API wyTransitionScene : public wyScene {
private:
	/// flag indicating finish method is already called
	bool m_finished;

protected:
	/// the scene will be swapped in
	wyScene* m_inScene;

	/// the scene will be swapped out, it is always the current scene
	wyScene* m_outScene;

	/// duration time of transition animation
	float m_duration;

	/// ease action of in scene
	wyEaseAction* m_inEase;

	/// ease action of out scene
	wyEaseAction* m_outEase;

	/// target selector invoked when transition is done
	wyTargetSelector* m_finishSelector;

protected:
	/**
	 * invoked when transition is done, subclass can customize it
	 */
	virtual void postFinish();

	/**
	 * setup something before transition, subclass can customize it
	 */
	virtual void initScenes();

	/**
	 * Whether in scene should be on top of out scene
	 *
	 * @return true means in scene should be on top of out scene
	 */
	virtual bool shouldInSceneOnTop();

	/**
	 * get the target will be imposed with in action
	 */
	virtual wyNode* getInActionTarget();

	/**
	 * get the target will be imposed with out action
	 */
	virtual wyNode* getOutActionTarget();

	/**
	 * get action will be performed on in target
	 */
	virtual wyIntervalAction* getInAction();

	/**
	 * get action will be performed on out target
	 */
	virtual wyIntervalAction* getOutAction();

	/**
	 * internally invoked when transition is done
	 */
	void setNewScene(wyTargetSelector* ts);

	/**
	 * Constructor
	 *
	 * @param duration duration time of transition animation
	 * @param inScene the scene will be swapped out, if not NULL, the out scene will be automatically set
	 *		to current scene. if NULL, then out scene will not be set and you must set them later
	 */
	wyTransitionScene(float duration, wyScene* inScene);

public:
	/**
	 * Static constructor to create a do-nothing transition
	 *
	 * @param duration duration time of transition, in seconds
	 * @param inScene incoming scene, or NULL if you want to use transiton when pop scene
	 * @return \link wyTransitionScene wyTransitionScene\endlinnk
	 */
	static wyTransitionScene* make(float duration, wyScene* inScene);

	virtual ~wyTransitionScene();

	/// @see wyNode::onEnter
	virtual void onEnter();

	/// @see wyNode::onExit
	virtual void onExit();

	/// @see wyScene::isTransition
	virtual bool isTransition() { return true; }

	/// @see wyNode::afterRender
	virtual void afterRender();

	/**
	 * this method must be called when transition should be ended, it is not
	 * intend to be called by developer
	 */
	void finish(wyTargetSelector* ts);

	/**
	 * hide out scene and show in scene
	 */
	void hideOutShowIn(wyTargetSelector* ts);

	/**
	 * get the scene will be swapped in
	 */
	wyScene* getInScene() { return m_inScene; }

	/**
	 * set the scene will be swapped in, you can only call it before transition is performed
	 */
	void setInScene(wyScene* scene);

	/**
	 * get the scene will be swapped out
	 */
	wyScene* getOutScene() { return m_outScene; }

	/**
	 * set the scene will be swapped out, you can only call it before transition is performed
	 */
	void setOutScene(wyScene* scene);

	/**
	 * set duration time of transition animation
	 */
	float getDuration() { return m_duration; }

	/**
	 * set non-linear effect for in animation, that makes transition animation more flexible.
	 * it must be called before transition is performed
	 *
	 * @param inEase subclass of \link wyEaseAction wyEaseAction\endlink
	 */
	void setInEaseAction(wyEaseAction* inEase);

	/**
	 * set non-linear effect for out animation, that makes transition animation more flexible.
	 * it must be called before transition is performed
	 *
	 * @param outEase subclass of \link wyEaseAction wyEaseAction\endlink
	 */
	void setOutEaseAction(wyEaseAction* outEase);

	/**
	 * Set a target selector which is called when transition is finished
	 *
	 * @param ts target selector object
	 */
	void setFinishCallback(wyTargetSelector* ts);
};

#endif // __wyTransitionScene_h__
