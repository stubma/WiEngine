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
#ifndef __wyAFCAnimation_h__
#define __wyAFCAnimation_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyAFCFrame.h"

/**
 * @struct wyAFCAnimation
 *
 * \if English
 * This class represents an animation in AFC architecture
 * \else
 * 这个类只代表一个动画，包含了这个动画的所有帧信息.
 * \endif
 */
class WIENGINE_API wyAFCAnimation : public wyObject {
private:
	/**
	 * \if English
	 * Frame list, all are \link wyAFCFrame wyAFCFrame\endlink object
	 * \else
	 * 帧列表，包含了\link wyAFCFrame wyAFCFrame\endlink对象指针
	 * \endif
	 */
	wyArray* m_frameList;

private:
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	wyAFCAnimation();

public:
	virtual ~wyAFCAnimation();
	static wyAFCAnimation* make();

	/**
	 * \if English
	 * Get frame count in this animation
	 *
	 * @return frame count
	 * \else
	 * 得到动画中的帧数
	 *
	 * @return 帧数
	 * \endif
	 */
	int getFrameCount() { return m_frameList->num; }

	/**
	 * \if English
	 * Add a frame to animation
	 *
	 * @param f \link wyAFCFrame wyAFCFrame\endlink
	 * \else
	 * 添加一个帧到动画中
	 *
	 * @param f \link wyAFCFrame wyAFCFrame\endlink
	 * \endif
	 */
	void addFrame(wyAFCFrame* f);

	/**
	 * \if English
	 * Get frame at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link wyAFCFrame wyAFCFrame\endlink object, or NULL if index is invalid
	 * \else
	 * 得到某个位置处的帧
	 *
	 * @param index 帧索引
	 * @return \link wyAFCFrame wyAFCFrame\endlink对象, 如果索引非法, 返回NULL
	 * \endif
	 */
	wyAFCFrame* getFrameAt(int index) { return (wyAFCFrame*)wyArrayGet(m_frameList, index); }
};

#endif // __wyAFCAnimation_h__
