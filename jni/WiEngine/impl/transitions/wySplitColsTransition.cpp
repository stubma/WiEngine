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
#include "wySplitColsTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wySplitCols.h"
#include "wyStopGrid.h"

wySplitColsTransition* wySplitColsTransition::make(float duration, wyScene* inScene, int cols) {
	wySplitColsTransition* t = WYNEW wySplitColsTransition(duration, inScene, cols);
	return (wySplitColsTransition*)t->autoRelease();
}

bool wySplitColsTransition::shouldInSceneOnTop() {
	return false;
}

wyIntervalAction* wySplitColsTransition::getOutAction() {
	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create split
    wyIntervalAction* split = wySplitCols::make(m_duration, m_cols, 1);

	// use ease if set
	if(m_outEase) {
		m_outEase->setWrappedAction(split);
		split = m_outEase;
	}

    // create sequence
    wySequence* seq = wySequence::make(split, call, wyStopGrid::make(), NULL);

    // return
    return seq;
}

wySplitColsTransition::~wySplitColsTransition() {
}

wySplitColsTransition::wySplitColsTransition(float duration, wyScene* inScene, int cols) :
		wyTransitionScene(duration, inScene),
		m_cols(cols) {
}
