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
#ifndef __wyMapInfo_h__
#define __wyMapInfo_h__

#include "wyGlobal.h"
#include "wyArray.h"
#include "wyHashSet.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @typedef wyTMXOrientation
 *
 * TMX地图的类型
 */
typedef enum {
	/// 正交型
	ORIENTATION_ORTHOGONAL = 1,

	/// 等角型
	ORIENTATION_ISOMETRIC,

	/// 六边型
	ORIENTATION_HEXAGONAL
} wyTMXOrientation;

typedef struct wyTileHash {
	int gid;
	wyHashSet* properties;
} wyTileHash;

typedef struct WIENGINE_API wyMapInfo {
	// tmx filename
	char* filename;

	// map orientation
	wyTMXOrientation orientation;

	// map width & height in tiles
	int mapWidth;
	int mapHeight;

	// tiles width & height in pixels
	float tileWidth;
	float tileHeight;

	// Layers
	wyArray* layers;

	// tilesets
	wyArray* tilesets;

	// ObjectGroups
	wyArray* objectGroups;

	// properties
	wyHashSet* properties;

	// tile properties
	wyHashSet* tileProperties;
} wyMapInfo;

// create/destroy
WIENGINE_API wyMapInfo* wyMapInfoNew();
WIENGINE_API void wyMapInfoDestroy(wyMapInfo* info);

// property
WIENGINE_API void wyMapInfoAddProperty(wyMapInfo* info, const char* key, const char* value);
WIENGINE_API char* wyMapInfoGetProperty(wyMapInfo* info, const char* name);
    
// find tileset index by a gid
WIENGINE_API int wyMapInfoGetTileSetIndex(wyMapInfo* info, int gid);

// tile property
WIENGINE_API void wyMapInfoNewTileProperties(wyMapInfo* info, int gid);
WIENGINE_API char* wyMapInfoGetTileProperty(wyMapInfo* info, int gid, const char* key);
WIENGINE_API void wyMapInfoAddTileProperty(wyMapInfo* info, int gid, const char* key, const char* value);

#ifdef __cplusplus
}
#endif

#endif // __wyMapInfo_h__
