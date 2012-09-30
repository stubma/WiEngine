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
#ifndef __wySuck_h__
#define __wySuck_h__

#include "wyGrid3DAction.h"

/**
 * @class wySuck
 *
 * \if English
 * Suck effect, just like the effect when deleting notes in iPhone
 * \else
 * 吸入效果, 指定一个吸入点, 界面中的所有元素都从这个点被吸走, 类似于iPhone中删除备忘录
 * 中的那种效果
 * \endif
 */
class WIENGINE_API wySuck : public wyGrid3DAction {
protected:
	/**
	 * \if English
	 * x position
	 * \else
	 * 吸入点x坐标
	 * \endif
	 */
	float m_positionX;

	/**
	 * \if English
	 * y position
	 * \else
	 * 吸入点y坐标
	 * \endif
	 */
	float m_positionY;

	/**
	 * \if English
	 * max distance between suck point to four corners
	 * \else
	 * 吸入点和四个角距离的最大值
	 * \endif
	 */
	float m_maxDistance;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param positionX x position of sucking
	 * @param positionY y position of sucking
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param positionX 吸入点x坐标
	 * @param positionY 吸入点y坐标
	 * \endif
	 */
	wySuck(float duration, int gridX, int gridY, float positionX, float positionY);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @param positionX x position of sucking
	 * @param positionY y position of sucking
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param positionX 吸入点x坐标
	 * @param positionY 吸入点y坐标
	 * \endif
	 */
	static wySuck* make(float duration, int gridX, int gridY, float positionX, float positionY);

	virtual ~wySuck();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wySuck_h__
