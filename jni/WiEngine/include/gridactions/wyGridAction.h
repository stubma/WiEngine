/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

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
#include "wyBaseGrid.h"

using namespace std;

/**
 * @class wyGridAction
 * \if English
 * base class of \link wyGrid3DAtcion wyGrid3DAction\enlink and \link wyTiledGrid3DAction wyTiledGrid3DAction\enlink
 * \else
 * 抽象基类，用于表示所有基于网格的动作
 * \endif
 */
class WIENGINE_API wyGridAction : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * row count of the grid
	 * \else
	 * 网格行数
	 * \endif
	 */
	int m_gridX;

	/**
	 * \if English
	 * column count of the grid
	 * \else
	 * 网格列数
	 * \endif
	 */
	int m_gridY;

	/**
	 * \if English
	 * amplitude of the action, not all actions use it
	 * \else
	 * 动作幅度
	 * \endif
	 */
	float m_amplitude;

	/**
	 * \if English
	 * amplitude rate of the action, not all actions use it
	 * \else
	 * 动作幅度比率
	 * \endif
	 */
	float m_amplitudeRate;

public:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * \endif
	 */
	wyGridAction(float duration, int gridX, int gridY);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyGridAction();

	/**
	 * \if English
	 * to return a grid object, subclass muse implement this method
	 *
	 * @return  \link wyBaseGrid wyBaseGrid\endlink
	 * \else
	 * 返回一个网格对象，子类需要实现这个方法
	 *
	 * @return \link wyBaseGrid wyBaseGrid对象指针\endlink
	 * \endif
	 */
	virtual wyBaseGrid* makeGrid() = 0;

	/**
	 * \if English
	 * check whether the grid can be reused, subclass must implement this method
	 *
	 * @param grid \link wyBaseGrid wyBaseGrid\endlink
	 * @return true means reusable
	 * \else
	 * 检查之前的网格对象是否可以重用
	 *
	 * @param grid \link wyBaseGrid wyBaseGrid\endlink
	 * @return true表示可以重用
	 * \endif
	 */
	virtual bool isGridReusable(wyBaseGrid* grid) = 0;

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/**
	 * \if English
	 * setter, its effect depends on specific grid action
	 *
	 * @param amp this value is a length in the target node's space
	 * \else
	 * 设置动作幅度。有些动作可以设置相应幅度，幅度会影响动作的剧烈程度。
	 *
	 * @param amp 动作幅度大小
	 * \endif
	 */
	void setAmplitude(float amp) { m_amplitude = amp; }

	/**
	 * \if English
	 * setter, its effect depends on specific grid action
	 *
	 * @param ar the new value
	 * \else
	 * 设置动作幅度比率。动作幅度比率可以起到放大的作用。
	 *
	 * @param ar 动作幅度比率
	 * \endif
	 */
	void setAmplitudeRate(float ar) { m_amplitudeRate = ar; }

	/**
	 * \if English
	 * getter
	 *
	 * @return the current amplitude
	 * \else
	 * 获得动作幅度
	 *
	 * @return 动作幅度大小
	 * \endif
	 */
	float getAmplitude() { return m_amplitude; }

	/**
	 * \if English
	 * getter
	 *
	 * @return the current amplitude rate
	 * \else
	 * 得到动作幅度比率
	 *
	 * @return 动作幅度比率
	 * \endif
	 */
	float getAmplitudeRate() { return m_amplitudeRate; }

	/**
	 * \if English
	 * getter
	 *
	 * @return row count of the internal grid
	 * \else
	 * 得到网格行数
	 *
	 * @return 网格行数
	 * \endif
	 */
	float getGridX() { return m_gridX; }

	/**
	 * \if English
	 * getter
	 *
	 * @return column count of the internal grid
	 * \else
	 * 得到网格列数
	 *
	 * @return 网格列数
	 * \endif
	 */
	float getGridY() { return m_gridY; }
};

#endif // __wyGridAction_h__
