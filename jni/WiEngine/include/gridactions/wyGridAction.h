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
#ifndef __wyGridAction_h__
#define __wyGridAction_h__

#include "wyIntervalAction.h"
#include "wyGridController.h"

using namespace std;

/**
 * @class wyGridAction
 * base class of \link wyGrid3DAtcion wyGrid3DAction\enlink and \link wyTiledGrid3DAction wyTiledGrid3DAction\enlink
 */
class WIENGINE_API wyGridAction : public wyIntervalAction {
protected:
	/**
	 * row count of the grid
	 */
	int m_gridX;

	/**
	 * column count of the grid
	 */
	int m_gridY;

	/**
	 * amplitude of the action, not all actions use it
	 */
	float m_amplitude;

	/**
	 * amplitude rate of the action, not all actions use it
	 */
	float m_amplitudeRate;

public:
	/**
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 */
	wyGridAction(float duration, int gridX, int gridY);

	/**
	 * destructor
	 */
	virtual ~wyGridAction();

	/**
	 * to return a grid object, subclass muse implement this method
	 *
	 * @return  \link wyGridController wyGridController\endlink
	 */
	virtual wyGridController* makeGrid() = 0;

	/**
	 * check whether the grid can be reused, subclass must implement this method
	 *
	 * @param grid \link wyGridController wyGridController\endlink
	 * @return true means reusable
	 */
	virtual bool isGridReusable(wyGridController* grid) = 0;

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/**
	 * setter, its effect depends on specific grid action
	 *
	 * @param amp this value is a length in the target node's space
	 */
	void setAmplitude(float amp) { m_amplitude = amp; }

	/**
	 * setter, its effect depends on specific grid action
	 *
	 * @param ar the new value
	 */
	void setAmplitudeRate(float ar) { m_amplitudeRate = ar; }

	/**
	 * getter
	 *
	 * @return the current amplitude
	 */
	float getAmplitude() { return m_amplitude; }

	/**
	 * getter
	 *
	 * @return the current amplitude rate
	 */
	float getAmplitudeRate() { return m_amplitudeRate; }

	/**
	 * getter
	 *
	 * @return row count of the internal grid
	 */
	float getGridX() { return m_gridX; }

	/**
	 * getter
	 *
	 * @return column count of the internal grid
	 */
	float getGridY() { return m_gridY; }
};

#endif // __wyGridAction_h__
