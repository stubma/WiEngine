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
#ifndef __wyAnimate_h__
#define __wyAnimate_h__

#include "wyIntervalAction.h"
#include "wyAnimation.h"

/**
 * @class wyAnimate
 *
 * \if English
 * Encapsulate animation action, it requires a \link wyAnimation wyAnimation\endlink object which
 * provides frame info
 * \else
 * 动画播放动作的封装
 * \endif
 */
class WIENGINE_API wyAnimate : public wyIntervalAction {
protected:
	/**
	 * \if English
	 * \link wyAnimation wyAnimation\endlink pointer
	 * \else
	 * 动画 \link wyAnimation wyAnimation\endlink 对象指针
	 * \endif
	 */
	wyAnimation* m_anim;

	/**
	 * \if English
	 * the original frame before animation started, it will be restored
	 * if fill after is set to false
	 * \else
	 * 起始帧 \link wyFrame wyFrame\endlink 对象指针
	 * \endif
	 */
	wyFrame* m_originFrame;

	/**
	 * \if English
	 * false indicating original frame should be restored after animation ended, true means
	 * keep last frame
	 * \else
	 * 动作停止后是否覆盖起始帧，true为覆盖
	 * \endif
	 */
	bool m_fillAfter;

	/// true表示原始帧已经保存过
	bool m_originFrameSaved;

protected:
	/**
	 * Constructor
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 */
	wyAnimate(wyAnimation* anim, bool fillAfter = false);

public:
	/**
	 * \if English
	 * Static factory method
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 * \else
	 * 静态构造函数
	 *
	 * @param anim 动画\link wyAnimation wyAnimation\endlink 对象指针
	 * @param fillAfter 动作停止后是否回到sprite的原始图片，true为不回到，false表示回到原来的图片. 缺省是false
	 * \endif
	 */
	static wyAnimate* make(wyAnimation* anim, bool fillAfter = false);

	virtual ~wyAnimate();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::reverse
	virtual wyAction* reverse();

	/// @see wyAction::start
	virtual void start(wyNode* target);

	/// @see wyAction::stop
	virtual void stop();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyAnimate_h__
