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
#ifndef __wySPX3FileData_h__
#define __wySPX3FileData_h__

#include "wyAFCFileData.h"
#include "wyArray.h"
#include "wySPX3TileSet.h"
#include "wySPX3Frame.h"
#include "wySPX3Action.h"

class wySPX3Loader;
class wySPX3Manager;

/**
 * @class wySPX3FileData
 *
 * \if English
 * A bean for SpriteX 2011 exported file. In SpriteX 2011, every atlas is represented by
 * a tile set, and tile info is resolved by tile set index and tile index. But anyway,
 * SpriteX 2011 is still an AFC architecture editor.
 * \else
 * 封装SpriteX 2011导出文件中的数据. SpriteX 2011中， 每个图片集被组织成一个分片集，帧中的
 * 分片通过分片集索引和分片索引来确定分片的具体信息。不管具体怎么组织，SpriteX 2011仍然是AFC
 * 架构。
 * \endif
 */
class WIENGINE_API wySPX3FileData : public wyAFCFileData {
	friend class wySPX3Loader;
	friend class wySPX3Manager;

private:
	/**
	 * \if English
	 * array of tile sets
	 * \else
	 * 分片集数组
	 * \endif
	 */
	wyArray* m_tileSets;

	/**
	 * \if English
	 * array of frames
	 * \else
	 * 帧数组
	 * \endif
	 */
	wyArray* m_frames;

	/**
	 * \if English
	 * array of actions
	 * \else
	 * 动画数组
	 * \endif
	 */
	wyArray* m_actions;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * \if English
	 * version of file format
	 * \else
	 * 文件格式版本
	 * \endif
	 */
	int m_version;

	/**
	 * \if English
	 * count of tile set, every tile set responses to an atlas
	 * \else
	 * 分片集数， 每个分片集对应于一个图片集
	 * \endif
	 */
	int m_tileSetCount;

	/**
	 * \if English
	 * frame count
	 * \else
	 * 帧总数
	 * \endif
	 */
	int m_frameCount;

	/**
	 * \if English
	 * animation count
	 * \else
	 * 动画总数
	 * \endif
	 */
	int m_actionCount;

protected:
	wySPX3FileData();

public:
    virtual ~wySPX3FileData();
    static wySPX3FileData* make();

    /**
	 * \if English
	 * Get tile set at given index
	 *
	 * @param index tile set index
	 * @return \link wySPX3TileSet wySPX3TileSet\endlink
	 * \else
	 * 得到指定位置的分片集
	 *
	 * @param index 分片集索引
	 * @return \link wySPX3TileSet wySPX3TileSet\endlink
	 * \endif
	 */
	wySPX3TileSet* getTileSetAt(int index) { return (wySPX3TileSet*)wyArrayGet(m_tileSets, index); }

	/**
	 * \if English
	 * Get frame at given index
	 *
	 * @param index frame index
	 * @return \link wySPX3Frame wySPX3Frame\endlink
	 * \else
	 * 得到指定位置的帧
	 *
	 * @param index 帧索引
	 * @return \link wySPX3Frame wySPX3Frame\endlink
	 * \endif
	 */
	wySPX3Frame* getFrameAt(int index) { return (wySPX3Frame*)wyArrayGet(m_frames, index); }

	/**
	 * \if English
	 * Get animation at an index
	 *
	 * @param index animation index
	 * @return \link wySPX3Action wySPX3Action\endlink, or NULL if index is not valid
	 * \else
	 * 根据索引得到动画
	 *
	 * @param index 动画索引
	 * @return \link wySPX3Action wySPX3Action\endlink对象, 如果索引范围不合法, 返回NULL
	 * \endif
	 */
	wySPX3Action* getActionAt(int index) { return (wySPX3Action*)wyArrayGet(m_actions, index); }
};

#endif // __wySPX3FileData_h__
