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
#include "wyJumpZoomTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyDelayTime.h"
#include "wyCallFunc.h"
#include "wyJumpBy.h"
#include "wyScaleTo.h"

wyJumpZoomTransition* wyJumpZoomTransition::make(float duration, wyScene* inScene) {
	wyJumpZoomTransition* t = WYNEW wyJumpZoomTransition(duration, inScene);
	return (wyJumpZoomTransition*)t->autoRelease();
}

void wyJumpZoomTransition::initScenes() {
	m_inScene->setScale(0.5f);
	m_inScene->setPosition(wyDevice::winWidth, 0);
}

wyIntervalAction* wyJumpZoomTransition::getInAction() {
	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create jump and scale
    wyIntervalAction* jump = wyJumpBy::make(m_duration / 4, -wyDevice::winWidth, 0, wyDevice::winWidth / 4, 2);
    wyIntervalAction* scale = wyScaleTo::make(m_duration / 4, m_inScene->getScale(), 1.0f);

    // use ease if set
    if(m_inEase) {
    	wyEaseAction* ease = (wyEaseAction*)m_inEase->copy();
    	ease->setWrappedAction(jump);
    	jump = ease;

    	ease = (wyEaseAction*)m_inEase->copy();
		ease->setWrappedAction(scale);
		scale = ease;
    }

    // create sequence
    wySequence* seq = wySequence::make(wyDelayTime::make(m_duration / 2),
    		jump,
    		scale,
    		call,
			NULL);

    // return
    return seq;
}

wyIntervalAction* wyJumpZoomTransition::getOutAction() {
    // create jump and scale
    wyIntervalAction* jump = wyJumpBy::make(m_duration / 4, -wyDevice::winWidth, 0, wyDevice::winWidth / 4, 2);
    wyIntervalAction* scale = wyScaleTo::make(m_duration / 4, m_outScene->getScale(), 0.5f);

    // use ease if set
    if(m_outEase) {
    	wyEaseAction* ease = (wyEaseAction*)m_outEase->copy();
    	ease->setWrappedAction(jump);
    	jump = ease;

    	ease = (wyEaseAction*)m_outEase->copy();
		ease->setWrappedAction(scale);
		scale = ease;
    }

    // create sequence
    wySequence* seq = wySequence::make(scale, jump, NULL);

    // return
    return seq;
}

wyJumpZoomTransition::~wyJumpZoomTransition() {
}

wyJumpZoomTransition::wyJumpZoomTransition(float duration, wyScene* inScene) : wyTransitionScene(duration, inScene) {
}
