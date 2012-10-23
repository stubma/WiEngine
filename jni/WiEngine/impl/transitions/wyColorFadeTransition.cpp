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
#include "wyColorFadeTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyFadeIn.h"
#include "wyFadeOut.h"
#include "wyEaseOut.h"
#include "wyColorLayer.h"
#include "wyLog.h"

#define TAG_FADE_LAYER 0xFADEFADE

wyColorFadeTransition* wyColorFadeTransition::make(float duration, wyScene* inScene, wyColor3B rgb) {
	wyColorFadeTransition* t = WYNEW wyColorFadeTransition(duration, inScene, rgb);
	return (wyColorFadeTransition*)t->autoRelease();
}

void wyColorFadeTransition::postFinish() {
	removeChildByTagLocked(TAG_FADE_LAYER, false);
}

void wyColorFadeTransition::initScenes() {
    wyColorLayer* cl = wyColorLayer::make(m_fadeColor);
    m_inScene->setVisible(false);
    addChildLocked(cl, 2, TAG_FADE_LAYER);
}

wyNode* wyColorFadeTransition::getInActionTarget() {
	return getChildByTagLocked(TAG_FADE_LAYER);
}

wyIntervalAction* wyColorFadeTransition::getInAction() {
	// create fade in
	wyIntervalAction* fadeIn = wyFadeIn::make(m_duration / 2);

	// create fade out
	wyIntervalAction* fadeOut = wyFadeOut::make(m_duration / 2);

	// if inEase is set, use inEase
	if(m_inEase) {
		wyEaseAction* ease = (wyEaseAction*)m_inEase->copy();
		ease->setWrappedAction(fadeIn);
		fadeIn = ease;

		ease = (wyEaseAction*)m_inEase->copy();
		ease->setWrappedAction(fadeOut);
		fadeOut = ease;
	}

	// create call finish func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::hideOutShowIn));
    wyFiniteTimeAction* callHideShow = wyCallFunc::make(ts);

	// create call finish func
    ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* callFinish = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(fadeIn, callHideShow, fadeOut, callFinish, NULL);

    // return
    return seq;
}

wyColorFadeTransition::~wyColorFadeTransition() {
}

wyColorFadeTransition::wyColorFadeTransition(float duration, wyScene* inScene, wyColor3B rgb) :
		wyTransitionScene(duration, inScene),
		m_fadeColor(wyc4b(rgb.r, rgb.g, rgb.b, 0)) {
}
