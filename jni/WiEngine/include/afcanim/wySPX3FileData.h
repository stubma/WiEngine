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
 * A bean for SpriteX 2011 exported file. In SpriteX 2011, every atlas is represented by
 * a tile set, and tile info is resolved by tile set index and tile index. But anyway,
 * SpriteX 2011 is still an AFC architecture editor.
 */
class WIENGINE_API wySPX3FileData : public wyAFCFileData {
	friend class wySPX3Loader;
	friend class wySPX3Manager;

private:
	/**
	 * array of tile sets
	 */
	wyArray* m_tileSets;

	/**
	 * array of frames
	 */
	wyArray* m_frames;

	/**
	 * array of actions
	 */
	wyArray* m_actions;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * version of file format
	 */
	int m_version;

	/**
	 * count of tile set, every tile set responses to an atlas
	 */
	int m_tileSetCount;

	/**
	 * frame count
	 */
	int m_frameCount;

	/**
	 * animation count
	 */
	int m_actionCount;

protected:
	wySPX3FileData();

public:
    virtual ~wySPX3FileData();
    static wySPX3FileData* make();

    /**
	 * Get tile set at given index
	 *
	 * @param index tile set index
	 * @return \link wySPX3TileSet wySPX3TileSet\endlink
	 */
	wySPX3TileSet* getTileSetAt(int index) { return (wySPX3TileSet*)wyArrayGet(m_tileSets, index); }

	/**
	 * Get frame at given index
	 *
	 * @param index frame index
	 * @return \link wySPX3Frame wySPX3Frame\endlink
	 */
	wySPX3Frame* getFrameAt(int index) { return (wySPX3Frame*)wyArrayGet(m_frames, index); }

	/**
	 * Get animation at an index
	 *
	 * @param index animation index
	 * @return \link wySPX3Action wySPX3Action\endlink, or NULL if index is not valid
	 */
	wySPX3Action* getActionAt(int index) { return (wySPX3Action*)wyArrayGet(m_actions, index); }
};

#endif // __wySPX3FileData_h__
