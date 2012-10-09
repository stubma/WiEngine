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
#include "wyBottomPushInTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyMoveBy.h"
#include "wyEaseOut.h"

wyBottomPushInTransition* wyBottomPushInTransition::make(float duration, wyScene* inScene) {
	wyBottomPushInTransition* t = WYNEW wyBottomPushInTransition(duration, inScene);
	return (wyBottomPushInTransition*)t->autoRelease();
}

void wyBottomPushInTransition::initScenes() {
	m_inScene->setPosition(0, -wyDevice::winHeight);
}

wyIntervalAction* wyBottomPushInTransition::getInAction() {
	wyIntervalAction* moveBy = wyMoveBy::make(m_duration, 0, wyDevice::winHeight);
	wyIntervalAction* action = wyEaseOut::make(2.0f, moveBy);

	// if ease is set, use ease
	if(m_inEase) {
		m_inEase->setWrappedAction(action);
		action = m_inEase;
	}

	return action;
}

wyIntervalAction* wyBottomPushInTransition::getOutAction() {
	// create eased move by
	wyIntervalAction* moveBy = wyMoveBy::make(m_duration, 0, wyDevice::winHeight);
	wyIntervalAction* easeMove = wyEaseOut::make(2.0f, moveBy);

	// if ease is set, use ease
	if(m_outEase) {
		m_outEase->setWrappedAction(easeMove);
		easeMove = m_outEase;
	}

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(easeMove, call, NULL);

    // return
    return seq;
}

wyBottomPushInTransition::~wyBottomPushInTransition() {
}

wyBottomPushInTransition::wyBottomPushInTransition(float duration, wyScene* inScene) : wyTransitionScene(duration, inScene) {
}
