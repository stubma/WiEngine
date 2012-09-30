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
#ifndef __wySPXAction_h__
#define __wySPXAction_h__

#include "wyObject.h"
#include "wySPXConstants.h"

class wySPXLoader;

/**
 * @typedef wySPXActionFrame
 *
 * \if English
 * frame info in animation
 * \else
 * 动画中帧的信息
 * \endif
 */
typedef struct wySPXActionFrame {
	/**
	 * \if English
	 * frame index
	 * \else
	 * 帧索引
	 * \endif
	 */
	int index;

	/**
	 * \if English
	 * duration of frame
	 * \else
	 * 持续时间, 单位秒
	 * \endif
	 */
	float duration;
} wySPXActionFrame;

/**
 * @class wySPXAction
 *
 * \if English
 * Info bean for one SpriteX animation
 * \else
 * 封装一个SpriteX动画的信息
 * \endif
 */
class WIENGINE_API wySPXAction : public wyObject {
	friend class wySPXLoader;

public:
	/**
	 * \if English
	 * transform of anmation
	 * \else
	 * 动画的转换常量
	 * \endif
	 */
	wySPXTransform m_transform;

	/**
	 * \if English
	 * frame count in this animation
	 * \else
	 * 动画中帧个数
	 * \endif
	 */
	int m_frameCount;

	/**
	 * \if English
	 * max tile count of frame
	 * \else
	 * 所有的帧中, tile数目最多是多少
	 * \endif
	 */
	int m_maxFrameTile;

	/**
	 * \if English
	 * frame info
	 * \else
	 * 帧信息
	 * \endif
	 */
	wySPXActionFrame* m_frames;

private:
	wySPXAction();

public:
	virtual ~wySPXAction();
};

#endif // __wySPXAction_h__
