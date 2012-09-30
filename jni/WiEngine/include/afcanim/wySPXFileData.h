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
#ifndef __wySPXFileData_h__
#define __wySPXFileData_h__

#include "wyAFCFileData.h"
#include "wyArray.h"
#include "wySPXFrame.h"
#include "wySPXAction.h"

class wySPXLoader;
class wySPXManager;

/**
 * @typedef wySPXTile
 *
 * \if English
 * tile size info in SpriteX
 * \else
 * 一个SpriteX中的tile
 * \endif
 */
typedef struct wySPXTile {
	/**
	 * \if English
	 * tile image x position in atlas
	 * \else
	 * 分片图片在图片集中的左上角x位置
	 * \endif
	 */
	short x;

	/**
	 * \if English
	 * tile image y position in atlas
	 * \else
	 * 分片图片在图片集中的左上角y位置
	 * \endif
	 */
	short y;

	/**
	 * \if English
	 * tile image width in atlas
	 * \else
	 * 分片图片的宽度
	 * \endif
	 */
	short w;

	/**
	 * \if English
	 * tile image height in atlas
	 * \else
	 * 分片图片的高度
	 * \endif
	 */
	short h;
} wySPXTile;

/**
 * @class wySPXFileData
 *
 * \if English
 * A bean for SpriteX file data. In SpriteX, positive direction of x axis is right,
 * positive of y is down and original point is top left corner
 * \else
 * 代表了一个SpriteX文件中的所有数据. SpriteX文件中的坐标系是x往右增加, y往下增加, 原点在左上角.
 * 所以转到WiEngine中时需要注意转换
 * \endif
 */
class WIENGINE_API wySPXFileData : public wyAFCFileData {
	friend class wySPXLoader;
	friend class wySPXManager;

private:
	/**
	 * \if English
	 * all frame
	 * \else
	 * 帧列表
	 * \endif
	 */
	wyArray* m_frames;

	/**
	 * \if English
	 * all animations
	 * \else
	 * 动画列表
	 * \endif
	 */
	wyArray* m_actions;

public:
	/**
	 * \if English
	 * tile count
	 * \else
	 * tile个数
	 * \endif
	 */
	int m_tileCount;

	/**
	 * \if English
	 * frame count
	 * \else
	 * 帧个数
	 * \endif
	 */
	int m_frameCount;

	/**
	 * \if English
	 * animation count
	 * \else
	 * 动画个数
	 * \endif
	 */
	int m_actionCount;

	/**
	 * \if English
	 * data of all tiles
	 * \else
	 * tile的数据
	 * \endif
	 */
	wySPXTile* m_tiles;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

protected:
	wySPXFileData();

public:
	virtual ~wySPXFileData();
	static wySPXFileData* make();

	/**
	 * \if English
	 * Get frame at an index
	 *
	 * @param index frame index
	 * @return \link wySPXFrame wySPXFrame\endlink, or NULL if index is not valid
	 * \else
	 * 根据索引得到帧
	 *
	 * @param index 帧索引
	 * @return \link wySPXFrame wySPXFrame\endlink对象, 如果索引范围不合法, 返回NULL
	 * \endif
	 */
	wySPXFrame* getFrameAt(int index) { return (wySPXFrame*)wyArrayGet(m_frames, index); }

	/**
	 * \if English
	 * Get animation at an index
	 *
	 * @param index animation index
	 * @return \link wySPXAction wySPXAction\endlink, or NULL if index is not valid
	 * \else
	 * 根据索引得到动画
	 *
	 * @param index 动画索引
	 * @return \link wySPXAction wySPXAction\endlink对象, 如果索引范围不合法, 返回NULL
	 * \endif
	 */
	wySPXAction* getActionAt(int index) { return (wySPXAction*)wyArrayGet(m_actions, index); }
};

#endif // __wySPXFileData_h__
