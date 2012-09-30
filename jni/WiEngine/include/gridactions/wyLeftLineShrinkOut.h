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
#ifndef __wyLeftLineShrinkOut_h__
#define __wyLeftLineShrinkOut_h__

#include "wyTiledGrid3DAction.h"
#include "wyTypes.h"

/**
 * @class wyLeftLineShrinkOut
 * \if English
 * The node performing this action will be divided into columns, and the columns will disappear one by one
 * from left to right, looks like the node shrinks.
 * \else
 * 把屏幕分成若干列，从左边开始收缩每列
 * \endif
 */
class WIENGINE_API wyLeftLineShrinkOut : public wyTiledGrid3DAction {
private:
	float tileTest(wyDimension pos, float time);
	void turnOnTile(wyDimension pos);
	void turnOffTile(wyDimension pos);
	void transformTile(wyDimension pos, float distance);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled.
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * \endif
	 */
	static wyLeftLineShrinkOut* make(float duration, int gridX, int gridY);

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
	wyLeftLineShrinkOut(float duration, int gridX, int gridY);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyLeftLineShrinkOut();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyLeftLineShrinkOut_h__
