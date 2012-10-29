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
#include "wyTMXLayer.h"
#include "wyLog.h"
#include <stdlib.h>
#include <string.h>
#include "wyTextureManager.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyQuadList.h"

typedef struct wyTileSetAtlasInfo {
    int atlasIndex;
    int tilesetIndex;
} wyTileSetAtlasInfo;

wyTMXLayer::wyTMXLayer(int layerIndex, wyMapInfo* mapInfo) :
        m_mapInfo(mapInfo),
        m_layerInfo(NULL),
        m_color(wyc4bWhite),
		m_tileWidth(mapInfo->tileWidth),
		m_tileHeight(mapInfo->tileHeight),
        m_batchNodes((wySpriteBatchNode**)wyCalloc(mapInfo->tilesets->num, sizeof(wySpriteBatchNode*))),   
		m_useAutomaticVertexZ(false),
		m_vertexZAt(0),
		m_alphaFuncValue(0) {
    // get layer info
    wyLayerInfo* layerInfo = (wyLayerInfo*)wyArrayGet(mapInfo->layers, layerIndex);
    m_layerInfo = layerInfo;

	// set name
	setName(layerInfo->name);
            
    // init layer members
    m_layerWidth = layerInfo->layerWidth;
    m_layerHeight = layerInfo->layerHeight;
    m_tiles = layerInfo->tiles;
    m_color.a = layerInfo->alpha;
    m_minGid = layerInfo->minGid;
    m_maxGid = layerInfo->maxGid;
    
    // allocate memory for atlas indices
    size_t size = layerInfo->layerWidth * layerInfo->layerHeight * sizeof(wyTileSetAtlasInfo);
    m_atlasInfos = (wyTileSetAtlasInfo*)wyMalloc(size);
    memset(m_atlasInfos, 0xff, size);

	// set anchor percent
	setAnchor(0.f, 0.f);

	// set content size
	switch(m_mapInfo->orientation) {
		case ORIENTATION_ISOMETRIC:
		case ORIENTATION_ORTHOGONAL:
			setContentSize(m_layerWidth * m_tileWidth, m_layerHeight * m_tileHeight);
			break;
		case ORIENTATION_HEXAGONAL:
			setContentSize(m_layerWidth * m_tileWidth * 3 / 4 + m_tileWidth / 4,
					m_layerHeight * m_tileHeight + (m_layerWidth > 1 ? (m_tileHeight / 2) : 0));
			break;
	}

	// set visible or not
	setVisible(layerInfo->visible);

	// set position
	wyPoint offset = calculateLayerOffset(layerInfo->offsetX, layerInfo->offsetY);
	setPosition(offset.x, offset.y);

	// setup tiles
	setupTiles();
}

wyTMXLayer::~wyTMXLayer() {
    wyFree(m_batchNodes);
	wyFree(m_atlasInfos);
}

wyTMXLayer* wyTMXLayer::make(int layerIndex, wyMapInfo* mapInfo) {
	wyTMXLayer* l = WYNEW wyTMXLayer(layerIndex, mapInfo);
	return (wyTMXLayer*)l->autoRelease();
}

wyPoint wyTMXLayer::getPositionForOrthoAt(int posX, int posY) {
	 float x = posX * m_tileWidth;
	 float y = (m_layerHeight - posY - 1) * m_tileHeight;
	 return wyp(x, y);
}

wyPoint wyTMXLayer::getPositionForIsoAt(int posX, int posY) {
	float x = m_tileWidth / 2 * (m_layerWidth + posX - posY - 1);
	float y = m_tileHeight / 2 * (m_layerHeight * 2 - posX - posY - 2);
	return wyp(x, y);
}

wyPoint wyTMXLayer::getPositionForHexAt(int posX, int posY) {
	float diffY = 0;
	if(posX % 2 == 0)
		diffY = m_tileHeight / 2;

	float x = posX * m_tileWidth * 3 / 4;
	float y = (m_layerHeight - posY - 1) * m_tileHeight + diffY;
	return wyp(x, y);
}

wyPoint wyTMXLayer::getPositionAt(int x, int y) {
	switch(m_mapInfo->orientation) {
		case ORIENTATION_ORTHOGONAL:
			return getPositionForOrthoAt(x, y);
		case ORIENTATION_ISOMETRIC:
			return getPositionForIsoAt(x, y);
		case ORIENTATION_HEXAGONAL:
			return getPositionForHexAt(x, y);
		default:
			return wypZero;
	}
}

wyDimension wyTMXLayer::getTileCoordinateAt(float x, float y) {
	wyDimension d = wyd(-1, -1);
	if(x < 0 || y < 0)
		return d;

	switch(m_mapInfo->orientation) {
		case ORIENTATION_ORTHOGONAL:
		{
			d.x = x / m_tileWidth;
			d.y = m_layerHeight - (int)(y / m_tileHeight) - 1;
			break;
		}
		case ORIENTATION_ISOMETRIC:
		{
			// 把相对于节点左下角的坐标转换成以(0, 0)瓦片的最上顶点为原点的坐标
			wyPoint top = getPositionForIsoAt(0, 0);
			top.x += m_tileWidth / 2;
			top.y += m_tileHeight;
			x -= top.x;
			y = top.y - y;

			// 映射转换后的坐标到tile坐标
			d.x = (int)((m_tileWidth * y + m_tileHeight * x) / m_tileWidth / m_tileHeight);
			d.y = (int)((m_tileWidth * y - m_tileHeight * x) / m_tileWidth / m_tileHeight);
			break;
		}
		case ORIENTATION_HEXAGONAL:
		{
			// 把相对于节点左下角的坐标转换成以(0, 0)瓦片的最上顶点为原点的坐标
			wyPoint top = getPositionForHexAt(0, 0);
			float newY = top.y + m_tileHeight - y;

			// 映射
			float xBelt = x / (m_tileWidth * 3 / 4);
			float yEvenBelt = newY / m_tileHeight;
			float yOddBelt = (newY - m_tileHeight / 2) / m_tileHeight;
			bool intermediate = fmod(x, m_tileWidth * 3 / 4) < m_tileWidth / 4;
			if(intermediate) {
				// 得到可能的两个tile
				int posX2 = (int)xBelt;
				int posX1 = posX2 - 1;
				int posY1, posY2;
				if(posX2 % 2 == 0) {
					posY1 = (int)yOddBelt;
					posY2 = (int)yEvenBelt;
				} else {
					posY1 = (int)yEvenBelt;
					posY2 = (int)yOddBelt;
				}

				// 得到两个tile的中心
				wyPoint pos1 = getPositionForHexAt(posX1, posY1);
				wyPoint pos2 = getPositionForHexAt(posX2, posY2);
				pos1.x += m_tileWidth / 2;
				pos1.y += m_tileHeight / 2;
				pos2.x += m_tileWidth / 2;
				pos2.y += m_tileHeight / 2;

				// 计算触摸点和中心的矩形, 距离短的为点击的tile
				wyPoint touch = wyp(x, y);
				float distance1 = wypDistance(pos1, touch);
				float distance2 = wypDistance(pos2, touch);
				if(distance1 < distance2) {
					d.x = posX1;
					d.y = posY1;
				} else {
					d.x = posX2;
					d.y = posY2;
				}
			} else {
				d.x = (int)xBelt;
				if(d.x % 2 == 0)
					d.y = (int)yEvenBelt;
				else
					d.y = (int)yOddBelt;
			}
			break;
		}
	}

	if(d.x < 0 || d.x >= m_layerWidth)
		d.x = -1;
	if(d.y < 0 || d.y >= m_layerHeight)
		d.y = -1;
	return d;
}

float wyTMXLayer::getVertexZAt(int x, int y) {
	float ret = 0;
	int maxVal = 0;
	if(m_useAutomaticVertexZ) {
		switch(m_mapInfo->orientation) {
			case ORIENTATION_ISOMETRIC:
				maxVal = m_layerWidth + m_layerHeight;
				ret = -(maxVal - (x + y));
				break;
			case ORIENTATION_ORTHOGONAL:
				ret = -(m_layerHeight - y);
				break;
			case ORIENTATION_HEXAGONAL:
				// TODO TMX Hexagonal zOrder not supported
				break;
			default:
				LOGW("TMX invalid value");
				break;
		}
	} else {
		ret = m_vertexZAt;
	}

	return ret;
}

void wyTMXLayer::appendTileForGid(int tilesetIndex, int gid, int x, int y) {
	// get next index
    wyQuadList* atlas = (wyQuadList*)m_batchNodes[tilesetIndex]->getMesh();
	int index = atlas->getTotalQuads();

	// save atlas index
	int z = x + y * m_layerWidth;
	m_atlasInfos[z].atlasIndex = index;
    m_atlasInfos[z].tilesetIndex = tilesetIndex;

	// get atlas size
	float atlasWidth = m_batchNodes[tilesetIndex]->getTexture()->getPixelWidth();
	float atlasHeight = m_batchNodes[tilesetIndex]->getTexture()->getPixelHeight();

	// get tile vertex
    wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(m_mapInfo->tilesets, tilesetIndex);
	wyRect rect = wyTileSetInfoGetRect(tileset, gid);
	wyPoint pos = getPositionAt(x, y);
	float left = pos.x;
	float bottom = pos.y;
	float right = left + rect.width;
	float top = bottom + rect.height;

	// get tex coords
	float left2 = (2 * rect.x + 1) / (2 * atlasWidth);
    float right2 = left2 + (2 * rect.width - 2) / (2 * atlasWidth);
	float top2 = (2 * rect.y + 1) / (2 * atlasHeight);
	float bottom2 = top2 + (2 * rect.height - 2) / (2 * atlasHeight);

	// update atlas arrays
	float vertexZ = getVertexZAt(x, y);
	wyQuad2D texCoords = {
		left2, bottom2,
		right2, bottom2,
		left2, top2,
		right2, top2
	};
	wyQuad3D vertex = {
		left, bottom, vertexZ,
		right, bottom, vertexZ,
		left, top, vertexZ,
		right, top, vertexZ
	};
	atlas->insertQuad(index, texCoords, vertex);
	atlas->updateColor(index, m_color);
}

void wyTMXLayer::parseInternalProperties() {
	char* vertexZ = getProperty("cc_vertexz");
	if(!wyUtils::isEmpty(vertexZ)) {
		if(!strcmp("automatic", vertexZ))
			m_useAutomaticVertexZ = true;
		else
			m_vertexZAt = atof(vertexZ);
	}

	char* alpha = getProperty("cc_alpha_func");
	if(!wyUtils::isEmpty(alpha))
		m_alphaFuncValue = atof(alpha);
}

wyPoint wyTMXLayer::calculateLayerOffset(float x, float y) {
	wyPoint ret = wypZero;
	switch(m_mapInfo->orientation) {
		case ORIENTATION_ORTHOGONAL:
			ret.x = x * m_tileWidth;
			ret.y = y * m_tileHeight;
			break;
		case ORIENTATION_ISOMETRIC:
			ret.x = (m_tileWidth / 2) * (x - y);
			ret.y = (m_tileHeight / 2) * (-x - y);
			break;
		case ORIENTATION_HEXAGONAL:
			// TODO offset for hexagonal map not implemented yet
			break;
	}
	return ret;
}

void wyTMXLayer::setupTiles() {
	// Parse cocos2d properties
	parseInternalProperties();

	// add tiles coordinates
	for(int y = 0; y < m_layerHeight; y++) {
		for(int x = 0; x < m_layerWidth; x++) {
			int pos = x + m_layerWidth * y;
			int gid = m_tiles[pos];

			// gid == 0 -> empty tile
			if(gid != 0) {
                // find tileset index
                int tilesetIndex = wyMapInfoGetTileSetIndex(m_mapInfo, gid);
                
                // if corresponded batch not is not created, create it and add it
                if(m_batchNodes[tilesetIndex] == NULL) {
                    wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(m_mapInfo->tilesets, tilesetIndex);
                    wySpriteBatchNode* bn = wySpriteBatchNode::make(tileset->texture);
                    m_batchNodes[tilesetIndex] = bn;
                    addChildLocked(bn, tilesetIndex);
                }
                
                // append tile
				appendTileForGid(tilesetIndex, gid, x, y);
				m_minGid = MIN(m_minGid, gid);
				m_maxGid = MAX(m_maxGid, gid);
			}
		}
	}
}

char* wyTMXLayer::getProperty(const char* key) {
	return wyLayerInfoGetProperty(m_layerInfo, key);
}

int wyTMXLayer::getGidAt(int x, int y) {
	if(x < 0 || x >= m_layerWidth || y < 0 || y >= m_layerHeight)
		return 0;

	int pos = x + m_layerWidth * y;
	return m_tiles[pos];
}

int* wyTMXLayer::getGids(bool copy) {
	if(copy) {
		int totalNumberOfTiles = m_layerWidth * m_layerHeight;
		int* ret = (int*)wyMalloc(totalNumberOfTiles * sizeof(int));
		memcpy(ret, m_tiles, totalNumberOfTiles * sizeof(int));
		return ret;
	} else {
		return m_tiles;
	}
}

void wyTMXLayer::decreaseIndexIfMoreThan(int tilesetIndex, int index) {
	for(int x = 0; x < m_layerWidth; x++) {
		for(int y = 0; y < m_layerHeight; y++) {
			int z = x + y * m_layerWidth;
			if(m_atlasInfos[z].tilesetIndex == tilesetIndex && m_atlasInfos[z].atlasIndex > index) {
				m_atlasInfos[z].atlasIndex--;
			}
		}
	}
}

void wyTMXLayer::increaseIndexIfEqualOrMoreThan(int tilesetIndex, int index) {
	for(int x = 0; x < m_layerWidth; x++) {
		for(int y = 0; y < m_layerHeight; y++) {
			int z = x + y * m_layerWidth;
			if(m_atlasInfos[z].tilesetIndex == tilesetIndex && m_atlasInfos[z].atlasIndex >= index) {
				m_atlasInfos[z].atlasIndex++;
			}
		}
	}
}

void wyTMXLayer::removeTile(wySpriteEx* sprite) {
	// basic validation
	if(!sprite)
		return;

	// get z
	int z = sprite->getTag();
	if(z < 0 || z >= m_layerWidth * m_layerHeight)
		return;

    // get batch node atlas
    wySpriteBatchNode* bn = m_batchNodes[m_atlasInfos[z].tilesetIndex];

    // remove this sprite from batch node
    bn->removeChild(sprite, true);

    // adjust atlas indices
    decreaseIndexIfMoreThan(m_atlasInfos[z].tilesetIndex, m_atlasInfos[z].atlasIndex);
    m_atlasInfos[z].tilesetIndex = -1;
    m_atlasInfos[z].atlasIndex = -1;

    // remove gid
    m_tiles[z] = 0;
}

void wyTMXLayer::removeTileAt(int x, int y) {
	// find index
	int z = x + y * m_layerWidth;
	int index = m_atlasInfos[z].atlasIndex;
	if(index < 0)
		return;
    
    // get batch node atlas
    wySpriteBatchNode* bn = m_batchNodes[m_atlasInfos[z].tilesetIndex];
    wyQuadList* atlas = (wyQuadList*)bn->getMesh();

	// has sprite?
	wySpriteEx* sprite = (wySpriteEx*)bn->getChildByTag(z);
	if(sprite == NULL) {
		// remove quadratic
		atlas->removeQuad(index);
	} else {
        // remove this sprite from batch node
        bn->removeChild(sprite, true);
	}
    
    // adjust atlas indices
    decreaseIndexIfMoreThan(m_atlasInfos[z].tilesetIndex, index);
    m_atlasInfos[z].tilesetIndex = -1;
    m_atlasInfos[z].atlasIndex = -1;
    
    // remove gid
    m_tiles[z] = 0;
}

void wyTMXLayer::setTileAt(int tilesetIndex, int gid, int x, int y, int z) {
    // get tileset
    wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(m_mapInfo->tilesets, tilesetIndex);
    
    // if coorespond batch not is not created, create it and add it
    if(m_batchNodes[tilesetIndex] == NULL) {
        wySpriteBatchNode* bn = wySpriteBatchNode::make(tileset->texture);
        m_batchNodes[tilesetIndex] = bn;
        addChildLocked(bn, tilesetIndex);
    }
    
    // get atlas and tileset
    wyQuadList* atlas = (wyQuadList*)m_batchNodes[tilesetIndex]->getMesh();
    
    // get atlas size
    float atlasWidth = m_batchNodes[tilesetIndex]->getTexture()->getPixelWidth();
    float atlasHeight = m_batchNodes[tilesetIndex]->getTexture()->getPixelHeight();
    
    // get tile vertex
    wyRect rect = wyTileSetInfoGetRect(tileset, gid);
    wyPoint pos = getPositionAt(x, y);
    float left = pos.x;
    float bottom = pos.y;
    float right = left + rect.width;
    float top = bottom + rect.height;
    
    // get tex coords
    float left2 = (2 * rect.x + 1) / (2 * atlasWidth);
    float right2 = left2 + (2 * rect.width - 2) / (2 * atlasWidth);
    float top2 = (2 * rect.y + 1) / (2 * atlasHeight);
    float bottom2 = top2 + (2 * rect.height - 2) / (2 * atlasHeight);
    
    // update atlas arrays
    float vertexZ = getVertexZAt(x, y);
    wyQuad2D texCoords = {
        left2, bottom2,
        right2, bottom2,
        left2, top2,
        right2, top2
    };
    wyQuad3D vertex = {
        left, bottom, vertexZ,
        right, bottom, vertexZ,
        left, top, vertexZ,
        right, top, vertexZ
    };
    int index = atlas->appendQuad(texCoords, vertex);
    atlas->updateColor(index, m_color);
    
    // save atlas indices
    m_atlasInfos[z].atlasIndex = index;
    m_atlasInfos[z].tilesetIndex = tilesetIndex;
    
    // insert gid
    m_tiles[z] = gid;
}

void wyTMXLayer::setTileAt(int gid, int x, int y) {
    // decide tileset index
    int tilesetIndex = wyMapInfoGetTileSetIndex(m_mapInfo, gid);
    
    // if same tileset, and index is not zero, just update it
    // if same tileset, but index is zero, set it
    // if not same tileset, first remove it and then set it
    int z = x + y * m_layerWidth;
    int index = m_atlasInfos[z].atlasIndex;
    if(m_atlasInfos[z].tilesetIndex == tilesetIndex) {
        if(index >= 0) {
            updateTileAt(gid, x, y);
        } else {
            setTileAt(tilesetIndex, gid, x, y, z);
        }
    } else {
        // first remove it
        if(index >= 0)
            removeTileAt(x, y);
        
        // then set it
        setTileAt(tilesetIndex, gid, x, y, z);
    }
}

void wyTMXLayer::updateTileAt(int gid, int x, int y) {
    // decide tileset index
    int tilesetIndex = wyMapInfoGetTileSetIndex(m_mapInfo, gid);
    
    // if same tileset, but index less than zero, just set it
    // if same tileset, but index >= 0, just update
    // if not same tileset, remove it and then set it
    int z = x + y * m_layerWidth;
	int index = m_atlasInfos[z].atlasIndex;
    if(m_atlasInfos[z].tilesetIndex == tilesetIndex) {
        if(index < 0) {
            setTileAt(tilesetIndex, gid, x, y, z);
        } else {
            // get atlas and tileset
            wyQuadList* atlas = (wyQuadList*)m_batchNodes[tilesetIndex]->getMesh();
            wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(m_mapInfo->tilesets, tilesetIndex);
            
            // get tile sprite if has
            wySpriteEx* sprite = (wySpriteEx*)m_batchNodes[tilesetIndex]->getChildByTag(z);
            if(sprite) {
                wyRect rect = wyTileSetInfoGetRect(tileset, gid);
                sprite->setTextureRect(rect);
            } else {
                // get atlas size
                float atlasWidth = m_batchNodes[tilesetIndex]->getTexture()->getPixelWidth();
                float atlasHeight = m_batchNodes[tilesetIndex]->getTexture()->getPixelHeight();
                
                // get tile vertex
                wyRect rect = wyTileSetInfoGetRect(tileset, gid);
                wyPoint pos = getPositionAt(x, y);
                float left = pos.x;
                float bottom = pos.y;
                float right = left + rect.width;
                float top = bottom + rect.height;
                
                // get tex coords
                float left2 = (2 * rect.x + 1) / (2 * atlasWidth);
                float right2 = left2 + (2 * rect.width - 2) / (2 * atlasWidth);
                float top2 = (2 * rect.y + 1) / (2 * atlasHeight);
                float bottom2 = top2 + (2 * rect.height - 2) / (2 * atlasHeight);
                
                // update atlas arrays
                float vertexZ = getVertexZAt(x, y);
                wyQuad2D texCoords = {
                    left2, bottom2,
                    right2, bottom2,
                    left2, top2,
                    right2, top2
                };
                wyQuad3D vertex = {
                    left, bottom, vertexZ,
                    right, bottom, vertexZ,
                    left, top, vertexZ,
                    right, top, vertexZ
                };
                atlas->updateQuad(index, texCoords, vertex);
            }

            // save gid
            m_tiles[z] = gid;
        }
    } else {
        // first remove it
        if(index >= 0)
            removeTileAt(x, y);
        
        // then set it
        setTileAt(tilesetIndex, gid, x, y, z);
    }
}

wySpriteEx* wyTMXLayer::tileAt(int x, int y) {
	// get gid
	int gid = getGidAt(x, y);
	wySpriteEx* sprite = NULL;

	// if gid is zero, no tile at that location
	if(gid != 0) {
        // decide tileset index
        int tilesetIndex = wyMapInfoGetTileSetIndex(m_mapInfo, gid);
        
        // get batch node and tileset
        wySpriteBatchNode* bn = m_batchNodes[tilesetIndex];
        wyTileSetInfo* tileset = (wyTileSetInfo*)wyArrayGet(m_mapInfo->tilesets, tilesetIndex);
        
		// first check this child exist or not
		int z = x + y * m_layerWidth;
		sprite = (wySpriteEx*)bn->getChildByTag(z);

		// if not exist, create a new
		if(sprite == NULL) {
			wyRect texRect = wyTileSetInfoGetRect(tileset, gid);
			wyPoint pos = getPositionAt(x, y);
			sprite = wySpriteEx::make(bn->getTexture(), texRect);
            sprite->setBatchNode(bn);
            sprite->useBatchNode(true);
			sprite->setAtlasIndex(m_atlasInfos[z].atlasIndex);

			/*
			 * the tile image size may not same as tile size, so anchor percent may
			 * need to be changed also
			 */
			if(m_tileWidth != texRect.width || m_tileHeight != texRect.height) {
				sprite->setAnchor(m_tileWidth / 2 / texRect.width, m_tileHeight / 2 / texRect.height);
			}

			// set other info
			sprite->setPosition(pos.x + m_tileWidth / 2, pos.y + m_tileHeight / 2);
			sprite->setVertexZ(getVertexZAt(x, y));
			sprite->setColor(m_color);
			sprite->setTag(z);

			// add sprite to batch node
            bn->wyNode::addChild(sprite, m_atlasInfos[z].atlasIndex, z);
		}
	}

	return sprite;
}

void wyTMXLayer::updateColor() {
	for(int i = 0; i < m_mapInfo->tilesets->num; i++) {
		if(m_batchNodes[i]) {
			m_batchNodes[i]->setColor(m_color);
		}
	}
}

void wyTMXLayer::setAlpha(int alpha) {
	m_color.a = alpha;
	updateColor();
}

wyColor3B wyTMXLayer::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyTMXLayer::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	updateColor();
}

void wyTMXLayer::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	updateColor();
}
