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
#include "wyTransitionScene.h"
#include <stdlib.h>
#include "wyDirector.h"
#include "wyLog.h"
#include "wyEventDispatcher.h"
#include "wyCallFunc.h"
#include "wySequence.h"
#include "wyDelayTime.h"
#include "wyScheduler.h"
#include "wyCamera.h"
#include "wyRenderManager.h"

extern wyDirector* gDirector;
extern wyEventDispatcher* gEventDispatcher;
extern wyScheduler* gScheduler;

wyTransitionScene::wyTransitionScene(float duration, wyScene* inScene) :
		m_finished(false),
		m_inScene(NULL),
		m_outScene(NULL),
		m_duration(duration),
		m_finishSelector(NULL),
		m_inEase(NULL),
		m_outEase(NULL) {
	if(inScene) {
		setInScene(inScene);
		setOutScene(gDirector->getRunningScene());

		// check scene
		if (m_inScene == m_outScene) {
			LOGE("Incoming scene must be different from the outgoing scene");
		}
	}
}

wyTransitionScene* wyTransitionScene::make(float duration, wyScene* inScene) {
	wyTransitionScene* t = WYNEW wyTransitionScene(duration, inScene);
	return (wyTransitionScene*)t->autoRelease();
}

wyTransitionScene::~wyTransitionScene() {
	wyObjectRelease(m_inScene);
	wyObjectRelease(m_outScene);
	wyObjectRelease(m_inEase);
	wyObjectRelease(m_outEase);
	wyObjectRelease(m_finishSelector);
}

void wyTransitionScene::afterRender() {
	wyDirector* d = wyDirector::getInstance();
	wyRenderManager* rm = d->getRenderManager();

	if(shouldInSceneOnTop()) {
		rm->renderNodeRecursively(m_outScene);
		rm->renderNodeRecursively(m_inScene);
	} else {
		rm->renderNodeRecursively(m_inScene);
		rm->renderNodeRecursively(m_outScene);
	}
}

void wyTransitionScene::setInScene(wyScene* scene) {
	if(m_running) {
		LOGW("Can't call setInScene after transition running");
		return;
	}

	wyObjectRetain(scene);
	wyObjectRelease(m_inScene);
	m_inScene = scene;
}

void wyTransitionScene::setOutScene(wyScene* scene) {
	if(m_running) {
		LOGW("Can't call setOutScene after transition running");
		return;
	}

	wyObjectRetain(scene);
	wyObjectRelease(m_outScene);
	m_outScene = scene;
}

void wyTransitionScene::onEnter() {
	// disable events while transition
	gEventDispatcher->setDispatchEvent(false);

	// call super enter
	wyScene::onEnter();

	// make in scene enter
	m_inScene->onEnter();

	// init scenes
	initScenes();

	// perform action if specified
	wyIntervalAction* in = getInAction();
	wyIntervalAction* out = getOutAction();
	wyNode* inTarget = getInActionTarget();
	wyNode* outTarget = getOutActionTarget();
	if(in != NULL && inTarget != NULL) {
		inTarget->runAction(in);
	}
	if(out != NULL && outTarget != NULL) {
		outTarget->runAction(out);
	}
}

void wyTransitionScene::onExit() {
	wyScene::onExit();
	m_outScene->onExit();

	// inScene should not receive the onExit callback
	// only the onEnterTransitionDidFinish
	m_inScene->onEnterTransitionDidFinish();

	// enable events after transition
	gEventDispatcher->setDispatchEvent(true);
}

bool wyTransitionScene::shouldInSceneOnTop() {
	return true;
}

void wyTransitionScene::postFinish() {
}

void wyTransitionScene::initScenes() {
}

wyNode* wyTransitionScene::getInActionTarget() {
	return m_inScene;
}

wyNode* wyTransitionScene::getOutActionTarget() {
	return m_outScene;
}

wyIntervalAction* wyTransitionScene::getInAction() {
	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(wyDelayTime::make(m_duration), call, NULL);

    // return
    return seq;
}

wyIntervalAction* wyTransitionScene::getOutAction() {
	return NULL;
}

void wyTransitionScene::hideOutShowIn(wyTargetSelector* ts) {
	m_inScene->setVisible(true);
	m_outScene->setVisible(false);
}

void wyTransitionScene::finish(wyTargetSelector* ts) {
	// avoid calling finish more than one time
	if(m_finished)
		return;
	m_finished = true;

	/* clean up */
	m_inScene->setVisible(true);
	m_inScene->setPosition(0, 0);
	m_inScene->setScale(1.0f);
	m_inScene->setRotation(0.0f);
	if(m_inScene->hasCamera())
		m_inScene->getCamera()->restoreCamera();

	m_outScene->setVisible(false);
	m_outScene->setPosition(0, 0);
	m_outScene->setScale(1.0f);
	m_outScene->setRotation(0.0f);
	if(m_outScene->hasCamera())
		m_outScene->getCamera()->restoreCamera();

	// schedule to set new scene
    wyTargetSelector* selSetNewScene = wyTargetSelector::make(this, SEL(wyTransitionScene::setNewScene));
    wyTimer* timer = wyTimer::make(selSetNewScene);
    timer->setOneShot(true);
    gScheduler->scheduleLocked(timer);

    // call back
    if(m_finishSelector)
    	m_finishSelector->invoke();

	// notify subclass transition is finished
	postFinish();
}

void wyTransitionScene::setNewScene(wyTargetSelector* ts) {
	gDirector->replaceScene(m_inScene);

	// restore out scene visibility
	m_outScene->setVisible(true);
}

void wyTransitionScene::setInEaseAction(wyEaseAction* inEase) {
	wyObjectRetain(inEase);
	wyObjectRelease(m_inEase);
	m_inEase = inEase;
}

void wyTransitionScene::setOutEaseAction(wyEaseAction* outEase) {
	wyObjectRetain(outEase);
	wyObjectRelease(m_outEase);
	m_outEase = outEase;
}

void wyTransitionScene::setFinishCallback(wyTargetSelector* ts) {
	wyObjectRetain(ts);
	wyObjectRelease(m_finishSelector);
	m_finishSelector = ts;
}
