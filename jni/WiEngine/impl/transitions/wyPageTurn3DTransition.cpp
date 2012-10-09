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
#include "wyPageTurn3DTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyPageTurn3D.h"
#include "wyCallFunc.h"
#include "wyStopGrid.h"

wyPageTurn3DTransition* wyPageTurn3DTransition::make(float duration, wyScene* inScene) {
	wyPageTurn3DTransition* t = WYNEW wyPageTurn3DTransition(duration, inScene);
	return (wyPageTurn3DTransition*)t->autoRelease();
}

bool wyPageTurn3DTransition::shouldInSceneOnTop() {
	return false;
}

wyIntervalAction* wyPageTurn3DTransition::getOutAction() {
	int x, y;
	if(wyDevice::winWidth > wyDevice::winHeight) {
		x = 16;
		y = 12;
	} else {
		x = 12;
		y = 16;
	}

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create page turn
    wyIntervalAction* pageTurn = wyPageTurn3D::make(m_duration, x, y);

    // use ease if set
    if(m_outEase) {
    	m_outEase->setWrappedAction(pageTurn);
    	pageTurn = m_outEase;
    }

    // create sequence
    wySequence* seq = wySequence::make(pageTurn, call, wyStopGrid::make(), NULL);

    // return
    return seq;
}

wyPageTurn3DTransition::~wyPageTurn3DTransition() {
}

wyPageTurn3DTransition::wyPageTurn3DTransition(float duration, wyScene* inScene) : wyTransitionScene(duration, inScene) {
}
