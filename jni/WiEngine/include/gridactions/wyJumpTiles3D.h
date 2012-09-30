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
#ifndef __wyJumpTiles3D_h__
#define __wyJumpTiles3D_h__

#include "wyTiledGrid3DAction.h"
#include "wyTypes.h"

/**
 * @class wyJumpTiles3D
 * \if English
 * This action produce an effect that tiles of the grid jump up and down
 * \else
 * 网络跳跃，每个Tile形成上下跳跃的效果
 * \endif
 */
class WIENGINE_API wyJumpTiles3D : public wyTiledGrid3DAction {
protected:
	/**
	 * \if English
	 * specify how many times tiles will jump
	 * \else
	 * 跳跃次数
	 * \endif
	 */
	int m_jumps;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count of the grid
	 * @param gridY column count of the grid
	 * @param amplitude the jumping amplitude
	 * @param jumps times tiles will jump
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 动作幅度
	 * @param jumps 跳跃次数
	 * \endif
	 */
	static wyJumpTiles3D* make(float duration, int gridX, int gridY, float amplitude, int jumps);

	/**
	 * \if English
	 * constructor
	 *
	 * @param duration time, in seconds
	 * @param gridX row count of the grid
	 * @param gridY column count of the grid
	 * @param amplitude the jumping amplitude
	 * @param jumps times tiles will jump
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param amplitude 动作幅度
	 * @param jumps 跳跃次数
	 * \endif
	 */
	wyJumpTiles3D(float duration, int gridX, int gridY, float amplitude, int jumps);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyJumpTiles3D();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyJumpTiles3D_h__
