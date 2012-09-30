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
#ifndef __wyFrame_h__
#define __wyFrame_h__

#include "wyObject.h"

/**
 * @class wyFrame
 *
 * \if English
 * wrapper class of frames, base class of wySpriteFrame
 * \else
 * 帧的封装,是所有帧类的基类
 * \endif
 */
class WIENGINE_API wyFrame : public wyObject {
protected:
	/**
	 * \if English
	 * duration of the frame, in seconds
	 * \else
	 * 持续的时间
	 * \endif
	 */
	float m_duration;

public:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * \else
	 * 构造函数
	 *
	 * @param duration 持续的时间
	 * \endif
	 */
	wyFrame(float duration);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyFrame();

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得帧持续的时间
	 *
	 * @return 帧持续的时间
	 * \endif
	 */
	float getDuration() { return m_duration; }

	/**
	 * \if English
	 * setter
	 *
	 * @param duration time, in seconds
	 * \else
	 * 设置帧持续时间
	 *
	 * @param duration 帧持续时间
	 * \endif
	 */
	void setDuration(float duration) { m_duration = duration; }
};

#endif // __wyFrame_h__
