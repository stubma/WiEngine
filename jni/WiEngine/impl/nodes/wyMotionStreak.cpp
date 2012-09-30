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
#include "wyMotionStreak.h"
#include <stdlib.h>
#include <math.h>
#include "wyLog.h"
#include "wyStripRibbon.h"
#include "wySpotRibbon.h"
#include "wyBladeRibbon.h"
#include "wyLineRibbon.h"

#define TS_UPDATE -10000

wyMotionStreak::~wyMotionStreak() {
	WYDELETE(m_pendingPoints);
}

wyMotionStreak::wyMotionStreak(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style) :
		m_segThreshold(3),
		m_lastLocation(wyp(-1, -1)),
		m_currentLocation(wyp(-1, -1)),
		m_paused(false) {
	// init member
	m_pendingPoints = WYNEW vector<PendingPoint>();
	m_pendingPoints->reserve(10);

	// create ribbon by style
	switch(style) {
		case MS_STYLE_STRIP:
			m_ribbon = wyStripRibbon::make(tex, color, fade);
			break;
		case MS_STYLE_SPOT:
			m_ribbon = wySpotRibbon::make(tex, color, fade);
			break;
		case MS_STYLE_BLADE:
			m_ribbon = wyBladeRibbon::make(tex, color, fade);
			break;
		case MS_STYLE_LINE:
			m_ribbon = wyLineRibbon::make(tex, color);
			break;
	}

	// add ribbon to motion streak
    addChildLocked(m_ribbon);

    // update ribbon position
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyMotionStreak::update));
    wyTimer* timer = wyTimer::make(ts);
    scheduleLocked(timer);
}

wyMotionStreak* wyMotionStreak::make(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style) {
	wyMotionStreak* n = WYNEW wyMotionStreak(fade, tex, color, style);
	return (wyMotionStreak*)n->autoRelease();
}

void wyMotionStreak::update(wyTargetSelector* ts) {
	float delta = ts->getDelta();
	if(!m_paused) {
		// add every point
		for(vector<PendingPoint>::iterator iter = m_pendingPoints->begin(); iter != m_pendingPoints->end(); iter++) {
			PendingPoint& pp = *iter;
			if(pp.newSegment) {
				m_ribbon->forceFirstPoint();
				m_currentLocation.x = m_currentLocation.y = -1;
				m_lastLocation.x = m_lastLocation.y = -1;
			}

			float len = sqrt(pow(m_currentLocation.x - pp.p.x, 2) + pow(m_currentLocation.y - pp.p.y, 2));
			if (len > m_segThreshold) {
				m_ribbon->addPoint(pp.p);
				m_lastLocation = m_currentLocation;
				m_currentLocation = pp.p;
			}
		}

		// clear
		m_pendingPoints->clear();

		// update
		m_ribbon->update(delta);
	}
}

void wyMotionStreak::setContentSize(float w, float h) {
	LOGW("wyMotionStreak doesn't support setContentSize");
}

void wyMotionStreak::addPoint(float x, float y, bool newSegment) {
	PendingPoint pp = {
			wyp(x, y), newSegment
	};
	m_pendingPoints->push_back(pp);
}

void wyMotionStreak::reset() {
	m_ribbon->reset();
	m_currentLocation.x = m_currentLocation.y = -1;
	m_lastLocation.x = m_lastLocation.y = -1;
	m_pendingPoints->clear();
	m_paused = false;
}
