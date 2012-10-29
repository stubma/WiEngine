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
#include "wyTMXObjectLayer.h"
#include "wyLog.h"
#include "wyMaterial.h"
#include "wyShape.h"

wyTMXObjectLayer::wyTMXObjectLayer(wyTMXTileMap* m) :
		m_map(m) {
	setNeedUpdateMesh(true);
}

wyTMXObjectLayer::~wyTMXObjectLayer() {
}

wyTMXObjectLayer* wyTMXObjectLayer::make(wyTMXTileMap* m) {
	wyTMXObjectLayer* l = WYNEW wyTMXObjectLayer(m);
	return (wyTMXObjectLayer*)l->autoRelease();
}

void wyTMXObjectLayer::updateMesh() {
	// clear old render pairs
	clearRenderPairs();

	// common material
	wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);

	// for every object, we push a render pair for it
	wyPointList vertices;
	wyMapInfo* mapInfo = m_map->getMapInfo();
	for(int i = 0; i < mapInfo->objectGroups->num; i++) {
		wyTMXObjectGroup* group = (wyTMXObjectGroup*)wyArrayGet(mapInfo->objectGroups, i);
		int oc = group->getObjectCount();
		for(int i = 0; i < oc; i++) {
			wyTMXObject* obj = group->getObjectAt(i);

			// get object x, y, those x, y is in tmx coordinates
			wyPoint loc = obj->getPosition();

			// is object a polygon?
			bool isNormal = obj->getType() == wyTMXObject::NORMAL;
			bool isClosed = obj->getType() == wyTMXObject::POLYGON;

			// fill vertex buffer
			vertices.clear();
			if(isNormal) {
				// manual add point, remember currently it should be in tmx coordinate space
				wySize s = obj->getSize();
				vertices.addPoint(0, 0);
				vertices.addPoint(0, s.height);
				vertices.addPoint(s.width, s.height);
				vertices.addPoint(s.width, 0);
				vertices.addPoint(0, 0);
			} else {
				// add points
				vertices.addPoints(obj->getPoints());

				// if closed, add first point
				if(isClosed) {
					vertices.addPoint(obj->getPoints().getPointAt(0));
				}
			}

			// convert all points from tmx space to node space
			wyPoint* buffer = vertices.getBuffer();
			for(int i = 0; i < vertices.getCount(); i++) {
				wyPoint p = m_map->tmxToNodeSpace(wyp(buffer[i].x + loc.x, buffer[i].y + loc.y));
				buffer[i].x = p.x;
				buffer[i].y = p.y;
			}

			// set to mesh
			wyShape* s = wyShape::make();
			s->buildPath((float*)buffer, vertices.getCount() * 2);
			s->updateColor(wyc4bGreen);
			addRenderPair(m, s);
		}
	}
}
