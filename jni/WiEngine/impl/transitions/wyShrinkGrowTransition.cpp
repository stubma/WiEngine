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
#include "wyShrinkGrowTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyEaseOut.h"
#include "wyScaleTo.h"

wyShrinkGrowTransition* wyShrinkGrowTransition::make(float duration, wyScene* inScene) {
	wyShrinkGrowTransition* t = WYNEW wyShrinkGrowTransition(duration, inScene);
	return (wyShrinkGrowTransition*)t->autoRelease();
}

void wyShrinkGrowTransition::initScenes() {
	m_inScene->setScale(0.001f);
	m_outScene->setScale(1.0f);

	m_inScene->setAnchor(2 / 3.0f, 0.5f);
	m_outScene->setAnchor(1 / 3.0f, 0.5f);
}

wyIntervalAction* wyShrinkGrowTransition::getInAction() {
	// create scale
	wyScaleTo* scale = wyScaleTo::make(m_duration, m_inScene->getScale(), 1.0f);
	wyIntervalAction* easeScale = wyEaseOut::make(2.0f, scale);

	// use ease if set
	if(m_inEase) {
		m_inEase->setWrappedAction(easeScale);
		easeScale = m_inEase;
	}

	// create ease out
	return easeScale;
}

wyIntervalAction* wyShrinkGrowTransition::getOutAction() {
	// create scale
	wyScaleTo* scale = wyScaleTo::make(m_duration, m_outScene->getScale(), 0.01f);

	// ease scale
	wyIntervalAction* easeScale = wyEaseOut::make(2.0f, scale);

	// use ease if set
	if(m_outEase) {
		m_outEase->setWrappedAction(easeScale);
		easeScale = m_outEase;
	}

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(easeScale, call, NULL);

    // return
    return seq;
}

wyShrinkGrowTransition::~wyShrinkGrowTransition() {
}

wyShrinkGrowTransition::wyShrinkGrowTransition(float duration, wyScene* inScene) : wyTransitionScene(duration, inScene) {
}
