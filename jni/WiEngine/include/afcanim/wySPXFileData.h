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
 * tile size info in SpriteX
 */
typedef struct wySPXTile {
	/**
	 * tile image x position in atlas
	 */
	short x;

	/**
	 * tile image y position in atlas
	 */
	short y;

	/**
	 * tile image width in atlas
	 */
	short w;

	/**
	 * tile image height in atlas
	 */
	short h;
} wySPXTile;

/**
 * @class wySPXFileData
 *
 * A bean for SpriteX file data. In SpriteX, positive direction of x axis is right,
 * positive of y is down and original point is top left corner
 */
class WIENGINE_API wySPXFileData : public wyAFCFileData {
	friend class wySPXLoader;
	friend class wySPXManager;

private:
	/**
	 * all frame
	 */
	wyArray* m_frames;

	/**
	 * all animations
	 */
	wyArray* m_actions;

public:
	/**
	 * tile count
	 */
	int m_tileCount;

	/**
	 * frame count
	 */
	int m_frameCount;

	/**
	 * animation count
	 */
	int m_actionCount;

	/**
	 * data of all tiles
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
	 * Get frame at an index
	 *
	 * @param index frame index
	 * @return \link wySPXFrame wySPXFrame\endlink, or NULL if index is not valid
	 */
	wySPXFrame* getFrameAt(int index) { return (wySPXFrame*)wyArrayGet(m_frames, index); }

	/**
	 * Get animation at an index
	 *
	 * @param index animation index
	 * @return \link wySPXAction wySPXAction\endlink, or NULL if index is not valid
	 */
	wySPXAction* getActionAt(int index) { return (wySPXAction*)wyArrayGet(m_actions, index); }
};

#endif // __wySPXFileData_h__
