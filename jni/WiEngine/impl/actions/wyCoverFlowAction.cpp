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
#include "wyCoverFlow.h"
#include "wyCoverFlowAction.h"

wyCoverFlowAction::wyCoverFlowAction(float duration, wyCover* targetCover) :
		wyIntervalAction(duration),
		m_targetCover(targetCover),
		m_startCover(NULL) {
}

wyCoverFlowAction* wyCoverFlowAction::make(float duration, wyCover* targetCover) {
	wyCoverFlowAction* a = WYNEW wyCoverFlowAction(duration, targetCover);
	return (wyCoverFlowAction*)a->autoRelease();
}

void wyCoverFlowAction::start(wyNode* target) {
    wyIntervalAction::start(target);
    wyCoverFlow* cf = dynamic_cast<wyCoverFlow*>(target);
    if(cf) {
        cf->m_bIsShowing = true; 
        m_startCover = cf->getFrontCover();
    }
}

void wyCoverFlowAction::update(float t) {
    wyCoverFlow* coverFlow = dynamic_cast<wyCoverFlow*>(getTarget());
    if(!coverFlow)
        return;

    int indexStart = coverFlow->getIndex(m_startCover);
    int indexTarget = coverFlow->getIndex(m_targetCover);
    if(indexTarget == -1 || indexStart == indexTarget)
        return;
    
    //distance > 0 means moving left
    int distance = indexTarget - indexStart;

    static int prevPhase = 0;
    if(t == 0.0f) {
        prevPhase = 0;
    }

    float t2 = t * abs(distance);
    int curPhase = 0;
    while(t2 > 1) {
        curPhase++;
        t2 -= 1.0f;
    }

    if(curPhase > prevPhase) {
        int count = curPhase - prevPhase;

        while(count--) {
            if(distance > 0.0f) {
                coverFlow->stepLeftUpdate(1.0f);
            } else {
                coverFlow->stepRightUpdate(1.0f);
            }
        }
        prevPhase = curPhase;
    }

    if(distance > 0.0f) {
        coverFlow->stepLeftUpdate(t2);
    } else {
        coverFlow->stepRightUpdate(t2);
    }    
}

void wyCoverFlowAction::stop() {
    wyIntervalAction::stop();
    wyCoverFlow* coverFlow = dynamic_cast<wyCoverFlow*>(getTarget());
    if(!coverFlow)
        return;

    coverFlow->setFrontCover(m_targetCover); 
    coverFlow->m_bIsShowing = false;   
}
