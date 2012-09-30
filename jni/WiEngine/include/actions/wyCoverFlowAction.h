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
#ifndef __wyCoverFlowAction_h__
#define __wyCoverFlowAction_h__

#include "wyIntervalAction.h"
#include "wyCoverFlow.h"

/**
 * @class wyCoverFlowAction
 *
 * \if English
 * Action to move a cover in \link wyCoverFlow wyCoverFlow\endlink, it brings target cover
 * to front with an animation
 * \else
 * 节点\link wyCoverFlow wyCoverFlow\endlink的action, 执行把m_targetCover移动到当前cover
 * \endif
 */
class WIENGINE_API wyCoverFlowAction : public wyIntervalAction {
private:
	/**
	 * \if English
	 * start cover
	 * \else
	 * action的起始cover，即\link wyCoverFlow wyCoverFlow节点 \endlink 的当前cover
	 * \endif
	 */
    wyCover*        m_startCover;
	
    /**
     * \if English
     * the target cover which should be placed front
     * \else
     * action的目标cover，action结束后，m_targetCover变成当前cover
     * \endif
     */
    wyCover*        m_targetCover;

protected:
	/**
	 * \if English
	 * constructor
	 *
	 * @param duration action duration in seconds
	 * @param targetCover target \link wyCover wyCover\endlink object which should be moved to front
	 * \else
	 * 构造函数
	 *
	 * @param duration 动画执行时间
	 * @param targetCover 指定下一个当前cover
	 * \endif
	 */
	wyCoverFlowAction(float duration, wyCover* targetCover);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration action duration in seconds
	 * @param targetCover target \link wyCover wyCover\endlink object which should be moved to front
	 * @return \link wyCoverFlowAction wyCoverFlowAction\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动画执行时间
	 * @param targetCover 指定下一个当前cover
	 * @return \link wyCoverFlowAction wyCoverFlowAction\endlink
	 * \endif
	 */
	static wyCoverFlowAction* make(float duration, wyCover* targetCover);

	virtual ~wyCoverFlowAction(){}

	/// @see wyIntervalAction::start(wyNode*)
	virtual void start(wyNode* target);
	
	/// @see wyIntervalAction::update(float)
	virtual void update(float t);

	/// @see wyIntervalAction::stop()	
    virtual void stop();
};

#endif
