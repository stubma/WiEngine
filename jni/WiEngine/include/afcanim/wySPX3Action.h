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
#ifndef __wySPX3Action_h__
#define __wySPX3Action_h__

#include "wyObject.h"
#include "wySPX3TileSet.h"

/**
 * @class wySPX3Action
 *
 * \if English
 * animation of SpriteX 2011
 * \else
 * SpriteX 2011的动画信息
 * \endif
 */
class WIENGINE_API wySPX3Action : public wyObject {
public:
	/**
	 * \if English
	 * data mode of action
	 * \else
	 * 动画的数据模式
	 * \endif
	 */
	wySPX3ActionMode m_mode;

	/**
	 * \if English
	 * collision rect of this animation
	 * \else
	 * 动画的碰撞区域
	 * \endif
	 */
	wySPX3Tile m_collisionRect;

	/**
	 * \if English
	 * frame count in this animation
	 * \else
	 * 动画中的帧数
	 * \endif
	 */
	int m_frameCount;

	/**
	 * \if English
	 * indices of frame
	 * \else
	 * 动画中帧的索引列表
	 * \endif
	 */
	short* m_frameIndices;

	/**
	 * \if English
	 * duration time of frames. useless if data mode is not time
	 * \else
	 * 帧的持续时间列表， 单位秒. SpriteX 2011中存的是毫秒， 需要除1000再存入.
	 * 如果动画的数据模式是无持续时间，则这个字段无用
	 * \endif
	 */
	float* m_delays;

protected:
	wySPX3Action();

public:
    virtual ~wySPX3Action();
    static wySPX3Action* make();
};

#endif // __wySPX3Action_h__
