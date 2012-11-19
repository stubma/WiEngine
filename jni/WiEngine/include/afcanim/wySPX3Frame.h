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
#ifndef __wySPX3Frame_h__
#define __wySPX3Frame_h__

#include "wyObject.h"
#include "wySPX3TileSet.h"

/**
 * @struct wySPX3Patch
 *
 * Clip in SpriteX 2011, it calls them patch. There is two types of patch:
 * image or shape.
 */
typedef struct wySPX3Patch {
	/**
	 * patch type
	 */
	wySPX3PatchType type;

	union {
		/**
		 * for image type tile
		 */
		struct {
			/**
			 * index of tile set
			 */
			short tileSetIndex;

			/**
			 * index of tile
			 */
			short tileIndex;

			/**
			 * tile x position in frame
			 */
			short x;

			/**
			 * tile y position in frame
			 */
			short y;

			/**
			 * transform of this tile
			 */
			wySPXTransform transform;
		} tile;

		/**
		 * for shape type tile
		 */
		struct {
			/**
			 * drawing mode, useless in WiEngine
			 */
			int mode;

			/**
			 * shape type
			 */
			wySPX3ShapeType shape;

			/**
			 * transform of this tile
			 */
			wySPXTransform transform;

			/**
			 * color of shape
			 */
		    int color;

		    /**
		     * vertex count of shape
		     */
		    short vertexCount;

		    /**
		     * count of shape parameters, first is vertices, then followed by
		     * other parameters
		     */
		    short paramCount;

		    /**
		     * buffer of parameters
		     */
		    short* params;
		} shape;
	};
} wySPX3Patch;

/**
 * @class wySPX3Frame
 *
 * frame in SpriteX 2011
 */
class WIENGINE_API wySPX3Frame : public wyObject {
public:
	/**
	 * flag of frame
	 */
	int m_flags;

	/**
	 * frame rect in animation
	 */
	wySPX3Tile m_rect;

	/**
	 * count of patch
	 */
	int m_patchCount;

	/**
	 * data of all patch
	 */
	wySPX3Patch* m_patches;

	/**
	 * count of collision rectangle
	 */
	int m_collisionCount;

	/**
	 * data of all collision rectangles
	 */
	wySPX3Tile* m_collisionRects;

protected:
	wySPX3Frame();

public:
    virtual ~wySPX3Frame();
    static wySPX3Frame* make();
};

#endif // __wySPX3Frame_h__
