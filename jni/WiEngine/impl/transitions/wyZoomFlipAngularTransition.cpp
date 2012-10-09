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
#include "wyZoomFlipAngularTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyDelayTime.h"
#include "wySpawn.h"
#include "wyShow.h"
#include "wyHide.h"
#include "wyOrbitCamera.h"
#include "wyScaleTo.h"
#include "wyScaleBy.h"

wyZoomFlipAngularTransition* wyZoomFlipAngularTransition::make(float duration, wyScene* inScene, bool toLeft, float scale) {
	wyZoomFlipAngularTransition* t = WYNEW wyZoomFlipAngularTransition(duration, inScene, toLeft, scale);
	return (wyZoomFlipAngularTransition*)t->autoRelease();
}

void wyZoomFlipAngularTransition::initScenes() {
	m_inScene->setVisible(false);
	m_inScene->setScale(m_scale);
	m_outScene->setScale(1.0f);
}

wyIntervalAction* wyZoomFlipAngularTransition::getInAction() {
    float inDeltaZ, inAngleZ;

    if (m_toLeft) {
    	inAngleZ = 270;
        inDeltaZ = 90;
    } else {
    	inAngleZ = 90;
        inDeltaZ = -90;
    }

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create spawn
    wyOrbitCamera* orbit = wyOrbitCamera::make(m_duration / 2, 1, 0, inAngleZ, inDeltaZ, -45, 0);
    wyScaleTo* scaleTo = wyScaleTo::make(m_duration / 2, m_scale, 1.0f);
    wyIntervalAction* spawn = wySpawn::make(orbit, scaleTo);

	// if ease is set, use ease
	if(m_inEase) {
		m_inEase->setWrappedAction(spawn);
		spawn = m_inEase;
	}

    // create sequence
    wySequence* seq = wySequence::make(wyDelayTime::make(m_duration / 2), wyShow::make(), spawn, call, NULL);

    // return
    return seq;
}

wyIntervalAction* wyZoomFlipAngularTransition::getOutAction() {
    float outDeltaZ, outAngleZ;

    if (m_toLeft) {
        outDeltaZ = 90;
        outAngleZ = 0;
    } else {
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    // create spawn
    wyOrbitCamera* orbit = wyOrbitCamera::make(m_duration / 2, 1, 0, outAngleZ, outDeltaZ, 45, 0);
    wyScaleBy* scaleTo = wyScaleBy::make(m_duration / 2, m_scale);
    wyIntervalAction* spawn = wySpawn::make(orbit, scaleTo);

	// if ease is set, use ease
	if(m_outEase) {
		m_outEase->setWrappedAction(spawn);
		spawn = m_outEase;
	}

    // create sequence
    wySequence* seq = wySequence::make(spawn, wyHide::make(), wyDelayTime::make(m_duration / 2), NULL);

    // return
    return seq;
}

wyZoomFlipAngularTransition::~wyZoomFlipAngularTransition() {
}

wyZoomFlipAngularTransition::wyZoomFlipAngularTransition(float duration, wyScene* inScene, bool toLeft, float scale) :
		wyTransitionScene(duration, inScene),
		m_toLeft(toLeft),
		m_scale(scale) {
}
