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
#include "wyTMXTileMap.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyTMXLoader.h"
#include <stdarg.h>
#include "wyTMXObjectLayer.h"

#define TAG_OBJECT_LAYER 0x7f7f7f7f

wyTMXTileMap::~wyTMXTileMap() {
    wyMapInfoDestroy(m_mapInfo);
}

wyTMXTileMap::wyTMXTileMap() :
		m_mapWidth(0),
		m_mapHeight(0),
		m_tileWidth(0),
		m_tileHeight(0),
		m_color(wyc4bWhite),
		m_debugDrawObjects(false) {
}

wyTMXTileMap* wyTMXTileMap::make(int resId, wyTexture2D* tex1, ...) {
	wyTMXTileMap* tmx = WYNEW wyTMXTileMap();

	// load tmx file
	wyMapInfo* map = wyTMXLoader::load(resId);

	// collect first texture
	wyArray* textures = wyArrayNew(map->tilesets->num);
	wyArrayPush(textures, tex1);

	// collect other textures
    va_list texList;
    va_start(texList, tex1);
    for(wyTexture2D* now = va_arg(texList, wyTexture2D*); now != NULL; now = va_arg(texList, wyTexture2D*)) {
    	wyArrayPush(textures, now);
    }
    va_end(texList);

    // init
    tmx->init(map, textures);

    // destroy temp list
    wyArrayDestroy(textures);

	return (wyTMXTileMap*)tmx->autoRelease();
}

wyTMXTileMap* wyTMXTileMap::make(int resId, wyTexture2D** tex, int texCount) {
	wyTMXTileMap* tmx = WYNEW wyTMXTileMap();

	// load tmx file
	wyMapInfo* map = wyTMXLoader::load(resId);

	// collect textures
	wyArray* textures = wyArrayNew(texCount);
    for(int i = 0; i < texCount; i++) {
    	wyArrayPush(textures, *(tex + i));
    }

    // init
    tmx->init(map, textures);

    // destroy temp list
    wyArrayDestroy(textures);

	return (wyTMXTileMap*)tmx->autoRelease();
}

wyTMXTileMap* wyTMXTileMap::make(const char* path, bool isFile, wyTexture2D* tex1, ...) {
	wyTMXTileMap* tmx = WYNEW wyTMXTileMap();

	// load tmx file
	wyMapInfo* map = wyTMXLoader::load(path, isFile);

	// collect first texture
	wyArray* textures = wyArrayNew(map->tilesets->num);
	wyArrayPush(textures, tex1);

	// collect other textures
    va_list texList;
    va_start(texList, tex1);
    for(wyTexture2D* now = va_arg(texList, wyTexture2D*); now != NULL; now = va_arg(texList, wyTexture2D*)) {
    	wyArrayPush(textures, now);
    }
    va_end(texList);

    // init
    tmx->init(map, textures);

    // destroy temp list
    wyArrayDestroy(textures);

	return (wyTMXTileMap*)tmx->autoRelease();
}

wyTMXTileMap* wyTMXTileMap::make(const char* path, bool isFile, wyTexture2D** tex, int texCount) {
	wyTMXTileMap* tmx = WYNEW wyTMXTileMap();

	// load tmx file
	wyMapInfo* map = wyTMXLoader::load(path, isFile);

	// collect textures
	wyArray* textures = wyArrayNew(texCount);
    for(int i = 0; i < texCount; i++) {
    	wyArrayPush(textures, *(tex + i));
    }

    // init
    tmx->init(map, textures);

    // destroy temp list
    wyArrayDestroy(textures);

	return (wyTMXTileMap*)tmx->autoRelease();
}

void wyTMXTileMap::init(wyMapInfo* map, wyArray* textures) {
	// set anchor percent
	setAnchor(0.f, 0.f);

	// save info
	m_tileWidth = map->tileWidth;
	m_tileHeight = map->tileHeight;
	m_mapWidth = map->mapWidth;
	m_mapHeight = map->mapHeight;
    m_mapInfo = map;
    
    // check textures
    if(textures->num != map->tilesets->num)
        LOGE("wyTMXTileMap::init: tileset count is not same as texture count!");
    
    // append texture to tileset and set tileset size
    for(int i = 0; i < textures->num; i++) {
        wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(map->tilesets, i);
        if(tileset) {
            tileset->texture = (wyTexture2D*)wyArrayGet(textures, i);
            tileset->texture->retain();
            tileset->imageWidth = tileset->texture->getPreciseWidth();
            tileset->imageHeight = tileset->texture->getPreciseHeight();
        }
    }

	// create tmx layer
	int idx = 0;
	for(int i = 0; i < map->layers->num; i++) {
        // create layer
		wyTMXLayer* layer = wyTMXLayer::make(idx, map);

		// check null
		if(layer == NULL)
			continue;

		// add
		addChildLocked(layer, idx, idx);
		idx++;

		// set my size
		setContentSize(MAX(layer->getWidth(), m_width),
				MAX(layer->getHeight(), m_height));
	}
}

wyTMXLayer* wyTMXTileMap::getLayer(const char* name) {
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		wyTMXLayer* layer = dynamic_cast<wyTMXLayer*>(child);
		if(layer != NULL) {
			if(!strcmp(layer->getName(), name))
				return layer;
		}
	}
	return NULL;
}

wyTMXLayer* wyTMXTileMap::getLayerAt(int index) {
	for(int i = 0; i < m_children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(m_children, i);
		wyTMXLayer* layer = dynamic_cast<wyTMXLayer*>(child);
		if(layer != NULL) {
			index--;
			if(index < 0)
				return layer;
		}
	}
	return NULL;
}

wyTMXObjectGroup* wyTMXTileMap::getObjectGroup(const char* name) {
	for(int i = 0; i < m_mapInfo->objectGroups->num; i++) {
		wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayGet(m_mapInfo->objectGroups, i);
		if(!strcmp(group->getName(), name))
			return group;
	}
	return NULL;
}

char* wyTMXTileMap::getProperty(const char* name) {
	wyKeyValueHash* hash = (wyKeyValueHash*)wyHashSetFind(m_mapInfo->properties, wyUtils::strHash(name), (void*)name);
	if(hash != NULL)
		return hash->value;
	else
		return NULL;
}

char* wyTMXTileMap::getTileProperty(int gid, const char* name) {
	wyTileHash* tileHash = (wyTileHash*)wyHashSetFind(m_mapInfo->tileProperties, gid, &gid);
	if(tileHash != NULL) {
		wyKeyValueHash* pHash = (wyKeyValueHash*)wyHashSetFind(tileHash->properties, wyUtils::strHash(name), (void*)name);
		if(pHash != NULL)
			return pHash->value;
	}

	return NULL;
}

void wyTMXTileMap::setDebugDrawObjects(bool flag) {
	if(m_debugDrawObjects != flag) {
		m_debugDrawObjects = flag;

		// add object layer or remove it
		if(m_debugDrawObjects) {
			wyTMXObjectLayer* l = wyTMXObjectLayer::make(this);
			addChildLocked(l, TAG_OBJECT_LAYER, MAX_INT);
		} else {
			removeChildByTagLocked(TAG_OBJECT_LAYER, true);
		}
	}
}

wyPoint wyTMXTileMap::nodeToTMXSpace(wyPoint p) {
	switch(m_mapInfo->orientation) {
		case ORIENTATION_ORTHOGONAL:
		case ORIENTATION_HEXAGONAL:
			// ortho and hex is simple, just convert origin
			return wyp(p.x, m_height - p.y);
		case ORIENTATION_ISOMETRIC:
		{
			// iso map origin is at top vertex of (0, 0) tile, and x&y axis follows edges of that tile
			float x = m_mapHeight * m_tileHeight - p.y - (m_mapWidth * m_tileWidth / 4 - p.x / 2);
			float y = m_mapHeight * m_tileHeight - p.y + (m_mapWidth * m_tileWidth / 4 - p.x / 2);
			return wyp(x, y);
		}
		default:
			return p;
	}
}

wyPoint wyTMXTileMap::tmxToNodeSpace(wyPoint p) {
	switch(m_mapInfo->orientation) {
		case ORIENTATION_ORTHOGONAL:
		case ORIENTATION_HEXAGONAL:
			// ortho and hex is simple, just convert origin
			return wyp(p.x, m_height - p.y);
		case ORIENTATION_ISOMETRIC:
		{
			// iso map origin is at top vertex of (0, 0) tile, and x&y axis follows edges of that tile
			float x = m_mapWidth * m_tileWidth / 2 + p.x - p.y;
			float y = (m_mapHeight * m_tileHeight * 2 - p.x - p.y) / 2;
			return wyp(x, y);
		}
		default:
			return p;
	}
}

void wyTMXTileMap::updateColor() {
	wyArray* children = getChildren();
	for(int i = 0; i < children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(children, i);
		child->setColor(m_color);
	}
}

void wyTMXTileMap::setAlpha(int alpha) {
	m_color.a = alpha;
	updateColor();
}

wyColor3B wyTMXTileMap::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyTMXTileMap::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	updateColor();
}

void wyTMXTileMap::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	updateColor();
}
