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
#ifndef __wyMotionStreak_h__
#define __wyMotionStreak_h__

#include "wyNode.h"
#include "wyRibbon.h"

/**
 * @typedef wyMotionStreakStyle
 * enumeration of motion streak styles
 */
typedef enum {
	/**
	 * the streak shows as a strip, \link wyStripRibbon wyStripRibbon\endlink is used to implement this effect
	 */
	MS_STYLE_STRIP,

	/**
	 * the steak shows as a dotted line, \link wySpotRibbon wySpotRibbon\endlink is used
	 */
	MS_STYLE_SPOT,

	/**
	 * the steak shows as a blade stripe, as fruit ninja's, \link wyBladeRibbon wyBladeRibbon\endlink is used
	 */
	MS_STYLE_BLADE,

	/**
	 * the steak show as a solid bold line, \link wyLineRibbon wyLineRibbon\endlink is used
	 */
	MS_STYLE_LINE
} wyMotionStreakStyle;

/**
 * @class wyMotionStreak
 *
 * To record the sport track of an object. By default, node of this type is located at the (0,0)
 * position of its parent space. Changing its size by setContentSize has no effect.
 */
class WIENGINE_API wyMotionStreak : public wyNode {
private:
	/// pending point need to be added to ribbon
	struct PendingPoint {
		/// position
		wyPoint p;

		/// true means this point is a start of a new segment
		bool newSegment;
	};

protected:
	/**
	 * \link wyRibbon wyRibbon object\endlink, used for rending purpose
	 */
	wyRibbon* m_ribbon;

	/**
	 * the threshold, in pixels, if the node moved beyond this value, new segment will be generated
	 */
	float m_segThreshold;

	/**
	 * last position
	 */
	wyPoint m_lastLocation;

	/**
	 * current position
	 */
	wyPoint m_currentLocation;

	/**
	 * flag to mark whether to stop tracking
	 */
	bool m_paused;

	/**
	 * style, \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 */
	wyMotionStreakStyle m_style;

	/// pending point list
	vector<PendingPoint>* m_pendingPoints;

protected:
	/**
	 * do updating
	 *
	 * @param ts related target selector which triggered this method
	 */
	void update(wyTargetSelector* ts);

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param fade duration, in seconds, after this given time, the ribbon will fade out. 0 means no fading out.
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param color \link wyColor4B wyColor4B object\endlink
	 * @param style \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 */
	static wyMotionStreak* make(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style = MS_STYLE_STRIP);

	/**
	 * constructor
	 *
	 * @param fade duration, in seconds, after this given time, the ribbon will fade out. 0 means no fading out.
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param color \link wyColor4B wyColor4B object\endlink
	 * @param style \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 */
	wyMotionStreak(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style = MS_STYLE_STRIP);

	/**
	 * destructor
	 */
	virtual ~wyMotionStreak();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_ribbon->getBlendFunc(); }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_ribbon->setBlendFunc(func); }

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_ribbon->getTexture(); }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex) { m_ribbon->setTexture(tex); }

	/**
	 * get the ribbon object being used, \link wyRibbon wyRibbon\endlink
	 */
	wyRibbon* getRibbon() { return m_ribbon; }

	/**
	 * getter
	 *
	 * @return \link wyPoint wyPoint\endlink (-1,-1) means the lastLocation is invalid
	 */
	wyPoint getLastLocation() { return m_lastLocation; }

	/**
	 * getter
	 *
	 * @return \link wyPoint wyPoint\endlink, (-1, 1) means currentLocation is invalid
	 */
	wyPoint getCurrentLocation() { return m_currentLocation; }

	/**
	 * set to pause tracking or not
	 *
	 * @param flag true means pause
	 */
	void setPaused(bool flag) { m_paused = flag; }

	/**
	 * getter
	 */
	bool isPaused() { return m_paused; }

	/**
	 * add one point
	 *
	 * @param x x coordinate, relative to the position of the node
	 * @param y y coordinate, relative to the position of the node
	 * @param newSegment true means a new segment is generated
	 */
	void addPoint(float x, float y, bool newSegment = false);

	/**
	 * this operation will clear all the tracks and restore the node to its original state
	 */
	void reset();

	/**
	 * get the style being used
	 *
	 * @return \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 */
	wyMotionStreakStyle getStyle() { return m_style; }

	/**
	 * set the threshold value
	 *
	 * @param threshold, in pixels, if the node moved beyond this value, new segment will be generated
	 */
	void setSegmentThreshold(float threshold) { m_segThreshold = threshold; }

	/**
	 * getter
	 */
	float getSegmentThreshold() { return m_segThreshold; }
};

#endif // __wyMotionStreak_h__
