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
#ifndef __wySPXFrame_h__
#define __wySPXFrame_h__

#include "wyObject.h"
#include "wySPXConstants.h"

class wySPXLoader;

/**
 * @typedef wySPXFrameTile
 *
 * tile info in a frame
 */
typedef struct wySPXFrameTile {
	/**
	 * index of tile
	 */
	int index;

	/**
	 * tile x position in frame
	 */
	int x;

	/**
	 * tile y position in frame
	 */
	int y;

	/**
	 * transform of this tile
	 */
	wySPXTransform transform;
} wySPXFrameTile;

/**
 * @typedef wySPXCollision
 *
 * collision region
 */
typedef struct wySPXCollision {
	/**
	 * x position of collision region
	 */
	int x;

	/**
	 * y position of collision region
	 */
	int y;

	/**
	 * width of collision region
	 */
	int width;

	/**
	 * height of collision region
	 */
	int height;
} wySPXCollision;

/**
 * @typedef wySPXReferencePoint
 *
 * reference point
 */
typedef struct wySPXReferencePoint {
	/**
	 * x location of reference point
	 */
	int x;

	/**
	 * y location of reference point
	 */
	int y;
} wySPXReferencePoint;

/**
 * frame of SpriteX animation
 */
class WIENGINE_API wySPXFrame : public wyObject {
	friend class wySPXLoader;

public:
	/**
	 * width of frame
	 */
	int m_width;

	/**
	 * height of frame
	 */
	int m_height;

	/**
	 * tile count in frame
	 */
	int m_frameTileCount;

	/**
	 * collision rect count in frame
	 */
	int m_collisionCount;

	/**
	 * reference point count in frame
	 */
	int m_referencePointCount;

	/**
	 * tile count in frame
	 */
	wySPXFrameTile* m_tiles;

	/**
	 * collision rect info in frame
	 */
	wySPXCollision* m_collisions;

	/**
	 * reference point in frame
	 */
	wySPXReferencePoint* m_refPoints;

private:
	wySPXFrame();

public:
	virtual ~wySPXFrame();
};

#endif // __wySPXFrame_h__
