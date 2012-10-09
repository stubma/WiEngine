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
#include "wySequence.h"
#include "wyNode.h"
#include <stdarg.h>
#include "wyLog.h"

bool wySequence::releaseAction(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

bool wySequence::stopAction(wyArray* arr, void* ptr, int index, void* data) {
	((wyAction*)ptr)->stop();
	return true;
}

wySequence::~wySequence() {
	wyArrayEach(m_actions, releaseAction, NULL);
	wyArrayDestroy(m_actions);
}

wyAction* wySequence::copy() {
	wyAction* action1 = (wyAction*)wyArrayGet(m_actions, 0);
	wyAction* action2 = (wyAction*)wyArrayGet(m_actions, 1);
	wyFiniteTimeAction* fta1 = (wyFiniteTimeAction*)action1->copy();
	wyFiniteTimeAction* fta2 = (wyFiniteTimeAction*)action2->copy();
	return wySequence::make(fta1, fta2, NULL);
}

wyAction* wySequence::reverse() {
	wyAction* action1 = (wyAction*)wyArrayGet(m_actions, 0);
	wyAction* action2 = (wyAction*)wyArrayGet(m_actions, 1);
	wyFiniteTimeAction* fta1 = (wyFiniteTimeAction*)action1->reverse();
	wyFiniteTimeAction* fta2 = (wyFiniteTimeAction*)action2->reverse();
	return wySequence::make(fta2, fta1, NULL);
}

void wySequence::start(wyNode* target) {
	wyIntervalAction::start(target);
	wyFiniteTimeAction* fta1 = (wyFiniteTimeAction*)wyArrayGet(m_actions, 0);
    m_split = fta1->getDuration() / m_duration;
    m_last = -1;
}

void wySequence::stop() {
	// stop current action
	if(m_last >= 0) {
		wyAction* a = (wyAction*)wyArrayGet(m_actions, m_last);
		if(a)
			a->stop();
	}

	// call super to trigger callback
	wyIntervalAction::stop();
}

void wySequence::update(float t) {
    int found;
    float new_t;

    if (t >= m_split) {
        found = 1;
        if (m_split == 1)
            new_t = 1;
        else
            new_t = (t - m_split) / (1 - m_split);
    } else {
        found = 0;
        if (m_split != 0)
            new_t = t / m_split;
        else
            new_t = 1;
    }

    if (m_last == -1 && found == 1) {
    	wyFiniteTimeAction* action1 = (wyFiniteTimeAction*)wyArrayGet(m_actions, 0);
    	action1->start(m_target);
    	action1->update(1.0f);
    	action1->setElapsed(action1->getDuration());
    	action1->stop();
    }

    wyAction* foundAction = (wyAction*)wyArrayGet(m_actions, found);
    if (m_last != found) {
        if (m_last != -1) {
        	wyFiniteTimeAction* lastAction = (wyFiniteTimeAction*)wyArrayGet(m_actions, m_last);
        	lastAction->update(1.0f);
        	lastAction->setElapsed(lastAction->getDuration());
        	lastAction->stop();
        }
        foundAction->start(m_target);
    }
    foundAction->update(new_t);
    m_last = found;

	// super only call callback
	wyIntervalAction::update(t);
}

// create/destroy
wySequence::wySequence(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2) :
		wyIntervalAction(action1->getDuration() + action2->getDuration()),
		m_actions(wyArrayNew(2)),
		m_split(0),
		m_last(0) {
	wyArrayPush(m_actions, action1);
	wyArrayPush(m_actions, action2);
	wyObjectRetain(action1);
	wyObjectRetain(action2);

	action1->setParent(this);
	action2->setParent(this);
}

wySequence* wySequence::make(wyFiniteTimeAction* action1, wyFiniteTimeAction* action2, ...) {
    va_list actions;
    va_start(actions, action2);

    wySequence* prev = WYNEW wySequence(action1, action2);
    for(wyFiniteTimeAction* now = va_arg(actions, wyFiniteTimeAction*); now != NULL; now = va_arg(actions, wyFiniteTimeAction*)) {
		prev->autoRelease();
    	prev = WYNEW wySequence(prev, now);
    }

    va_end(actions);

    return (wySequence*)prev->autoRelease();
}
