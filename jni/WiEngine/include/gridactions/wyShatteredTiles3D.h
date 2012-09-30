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
#ifndef __wyShatteredTiles3D_h__
#define __wyShatteredTiles3D_h__

#include "wyTiledGrid3DAction.h"
#include "wyTypes.h"

/**
 * @class wyShatteredTiles3D
 * \if English
 * Node performing this action will produce an effect which looks like a glass is shattered.
 * \else
 * 把节点打碎，如同打碎玻璃的效果
 * \endif
 */
class WIENGINE_API wyShatteredTiles3D : public wyTiledGrid3DAction {
protected:
	/**
	 * \if English
	 * specify how serious the shattering would be
	 * \else
	 * 破碎程度
	 * \endif
	 */
	int m_range;

	/**
	 * \if English
	 * specify whether shattering is performed on the z axis
	 * \else
	 * 是否在z轴方向上混淆
	 * \endif
	 */
	bool m_shatterZ;

	bool m_once;

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @range specify how serious the shattering would be
	 * @shatterZ specify whether shattering is performed on the z axis
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 * \endif
	 */
	static wyShatteredTiles3D* make(float duration, int gridX, int gridY, int range, bool shatterZ);

	/**
	 * \if English
	 *
	 * @param duration time, in seconds
	 * @param gridX row count
	 * @param gridY column count
	 * @range specify how serious the shattering would be
	 * @shatterZ specify whether shattering is performed on the z axis
	 * \else
	 * 构造函数
	 *
	 * @param duration 动作持续时间
	 * @param gridX 网格行数
	 * @param gridY 网格列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 * \endif
	 */
	wyShatteredTiles3D(float duration, int gridX, int gridY, int range, bool shatterZ);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyShatteredTiles3D();

	/// @see wyAction::copy
	virtual wyAction* copy();

	/// @see wyAction::update
	virtual void update(float t);
};

#endif // __wyShatteredTiles3D_h__
