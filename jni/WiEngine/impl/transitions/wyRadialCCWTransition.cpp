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
#include "wyRadialCCWTransition.h"
#include "wyProgressBy.h"
#include "wyCallFunc.h"
#include "wySequence.h"

wyRadialCCWTransition* wyRadialCCWTransition::make(float duration, wyScene* inScene) {
	wyRadialCCWTransition* t = WYNEW wyRadialCCWTransition(duration, inScene);
	return (wyRadialCCWTransition*)t->autoRelease();
}

void wyRadialCCWTransition::initScenes() {
	// make screenshot of out scene
	m_outTexture = wyRenderTexture::make();
	m_outTexture->beginRender();
	m_outScene->visit();
	m_outTexture->endRender();

	// create progress timer
	wyTexture2D* tex = m_outTexture->createTexture();
	m_progressTimer = wyProgressTimer::make(tex);
	m_progressTimer->setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	m_progressTimer->setStyle(getRadialType());
	m_progressTimer->setPercentage(100);
	m_progressTimer->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	addChildLocked(m_progressTimer);

	// out scene is save in out texture, dont' need it
	m_outScene->setVisible(false);
}

wyProgressTimerStyle wyRadialCCWTransition::getRadialType() {
	/*
	 * 这个类型是CW, 不是CCW, 因为我们从100开始减到0, 所以要用CW
	 * 来达到一个CCW的效果
	 */
	return RADIAL_CW;
}

wyIntervalAction* wyRadialCCWTransition::getOutAction() {
	// create progress by action
	wyIntervalAction* progress = wyProgressBy::make(m_duration, -100);

    // use ease if set
    if(m_outEase) {
    	m_outEase->setWrappedAction(progress);
    	progress = m_outEase;
    }

	// create call finish func
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* callFinish = wyCallFunc::make(ts);

    // create sequence
    wySequence* seq = wySequence::make(progress, callFinish, NULL);

    // return sequence
    return seq;
}

void wyRadialCCWTransition::postFinish() {
	removeChildLocked(m_progressTimer, false);
}

wyRadialCCWTransition::wyRadialCCWTransition(float duration, wyScene* inScene) :
		wyTransitionScene(duration, inScene),
		m_outTexture(NULL) {
}

wyRadialCCWTransition::~wyRadialCCWTransition() {
}
