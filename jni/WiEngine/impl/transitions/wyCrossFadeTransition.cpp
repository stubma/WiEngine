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
#include "wyCrossFadeTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyFadeOut.h"
#include "wyFadeIn.h"

wyCrossFadeTransition* wyCrossFadeTransition::make(float duration, wyScene* inScene) {
	wyCrossFadeTransition* t = WYNEW wyCrossFadeTransition(duration, inScene);
	return (wyCrossFadeTransition*)t->autoRelease();
}

wyCrossFadeTransition::~wyCrossFadeTransition() {
}

bool wyCrossFadeTransition::shouldInSceneOnTop() {
	return false;
}

void wyCrossFadeTransition::postFinish() {
	removeChildLocked(m_inTexture, false);
	removeChildLocked(m_outTexture, false);
}

void wyCrossFadeTransition::initScenes() {
	m_inTexture = wyRenderTexture::make();
	m_inTexture->beginRender();
	// TODO gles2
//	m_inScene->visit();
	m_inTexture->endRender();

	m_outTexture = wyRenderTexture::make();
	m_outTexture->beginRender();
	// TODO gles2
//	m_outScene->visit();
	m_outTexture->endRender();

	m_inTexture->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	m_outTexture->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	addChildLocked(m_inTexture);
	addChildLocked(m_outTexture);

	m_inScene->setVisible(false);
	m_outScene->setVisible(false);
}

wyNode* wyCrossFadeTransition::getInActionTarget() {
	return m_inTexture;
}

wyNode* wyCrossFadeTransition::getOutActionTarget() {
	return m_outTexture;
}

wyIntervalAction* wyCrossFadeTransition::getInAction() {
	// create fade in
	wyIntervalAction* fadeIn = wyFadeIn::make(m_duration);

	// use ease if set
	if(m_inEase) {
		m_inEase->setWrappedAction(fadeIn);
		fadeIn = m_inEase;
	}

	// create call finish func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::hideOutShowIn));
    wyFiniteTimeAction* callHideShow = wyCallFunc::make(ts);

	// create call finish func
    ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* callFinish = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(fadeIn, callHideShow, callFinish, NULL);

    // return
    return seq;
}

wyIntervalAction* wyCrossFadeTransition::getOutAction() {
	// create fade out
	wyIntervalAction* fadeOut = wyFadeOut::make(m_duration);

	// use ease if set
	if(m_outEase) {
		m_outEase->setWrappedAction(fadeOut);
		fadeOut = m_outEase;
	}

	return fadeOut;
}

wyCrossFadeTransition::wyCrossFadeTransition(float duration, wyScene* inScene) :
		wyTransitionScene(duration, inScene),
		m_inTexture(NULL),
		m_outTexture(NULL) {
}
