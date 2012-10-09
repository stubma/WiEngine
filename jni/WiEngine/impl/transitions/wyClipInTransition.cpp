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
#include "wyClipInTransition.h"
#include "wyCallFunc.h"
#include "wySequence.h"

wyClipInTransition::wyClipInTransition(float duration, wyScene* inScene, wyClipIn::Direction direction) :
		wyTransitionScene(duration, inScene),
		m_direction(direction) {
}

wyClipInTransition::~wyClipInTransition() {
}

wyClipInTransition* wyClipInTransition::make(float duration, wyScene* inScene, wyClipIn::Direction direction) {
	wyClipInTransition* t = WYNEW wyClipInTransition(duration, inScene, direction);
	return (wyClipInTransition*)t->autoRelease();
}

void wyClipInTransition::initScenes() {
	m_inScene->setClipRect(wyrZero, true);
}

wyIntervalAction* wyClipInTransition::getInAction() {
	// create clip in
	wyIntervalAction* clipIn = wyClipIn::make(m_duration, m_direction);

	// if inEase is set, use inEase
	if(m_inEase) {
		wyEaseAction* ease = (wyEaseAction*)m_inEase->copy();
		ease->setWrappedAction(clipIn);
		clipIn = ease;
	}

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(clipIn, call, NULL);

    // return
    return seq;
}
