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
#include "wyAStar.h"
#include "wyAStarMap.h"
#include "wyAStarStep.h"
#include "wyAStarTile.h"
#include "wyArray.h"
#include "wyObject.h"
#include <stdlib.h>
#include <math.h>

bool wyAStar::releaseNode(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyAStar::wyAStar(wyAStarMap* mapdata) :
		m_steps(wyArrayNew(mapdata->getTileCount())) {
	m_mapdata = mapdata;
	m_mapdata->retain();
}

wyAStar::~wyAStar() {
	if (m_steps != NULL) {
		wyArrayConcurrentEach(m_steps, releaseNode, NULL);
		wyArrayClear(m_steps);
		wyArrayDestroy(m_steps);
		m_steps = NULL;
	}
	m_mapdata->release();
}

int wyAStar::findPath(int startx, int starty, int endx, int endy, bool ignoreBlock) {
	wyArrayConcurrentEach(m_steps, releaseNode, NULL);
	wyArrayClear(m_steps);

	if ((startx == endx) && (starty == endy))
		return 0;

	if (!ignoreBlock && m_mapdata->isBlockedAt(endx, endy)) {
		return 0;
	}

	wyAStarStep* current = NULL;
	wyAStarStep* neighbor = NULL;
	wyAStarStep* aNode = NULL;

	wyArray* openList = wyArrayNew(m_mapdata->getTileCount());
	wyArray* closedList = wyArrayNew(m_mapdata->getTileCount());

	int gScoreIsBest;

	aNode = WYNEW wyAStarStep(startx, starty);
	wyArrayPush(openList, aNode);

	while (openList->num) {
		current = findLowestCostNode(openList);

		if ((current->getX() == endx) && (current->getY() == endy)) {
			wyArrayInsert(m_steps, current, 0);
			wyObjectRetain((wyObject*)current);

			aNode = current->getParent();
			while (aNode->getParent() != NULL) {
				wyArrayPush(m_steps, aNode);
				wyObjectRetain((wyObject*)aNode);
				aNode = aNode->getParent();
			}
			wyArrayConcurrentEach(openList, releaseNode, NULL);
			wyArrayDestroy(openList);
			openList = NULL;
			wyArrayConcurrentEach(closedList, releaseNode, NULL);
			wyArrayDestroy(closedList);
			closedList = NULL;
			return m_steps->num;
		}
		wyArrayPush(closedList, current);
		wyArrayDeleteObj(openList, current, NULL, NULL);

		wyAStarTile* currTile = m_mapdata->getTileAt(current->getX(), current->getY());
		wyArray * childs = currTile->getChilds();

		for (int i = 0; i < childs->num; i++) {
			wyAStarTile* tile = (wyAStarTile*)wyArrayGet(childs, i);
			if (!tile->isBlocked()) {
				if (!nodeInArray(closedList, tile->getX(), tile->getY())) {
					neighbor = WYNEW wyAStarStep(tile->getX(), tile->getY());
					float gScore = current->getG() + m_mapdata->getStepG(currTile, tile);
					gScoreIsBest = 0;

					if (!nodeInArray(openList, tile->getX(), tile->getY())) {
						gScoreIsBest = 1;
						neighbor->setH(neighbor->getH() +
								heuristic(currTile->getX(), currTile->getY(), tile->getX(), tile->getY()));
						wyArrayPush(openList, neighbor);
						neighbor->retain();

					} else if (gScore < neighbor->getG()) {
						gScoreIsBest = 1;
					}

					if (gScoreIsBest) {
						neighbor->setParent(current);
						neighbor->setG(gScore);
						neighbor->setF(neighbor->getG() + neighbor->getH());
					}
					neighbor->release();
				}
			}
		}
	}
	wyArrayConcurrentEach(openList, releaseNode, NULL);
	wyArrayDestroy(openList);
	openList = NULL;
	wyArrayConcurrentEach(closedList, releaseNode, NULL);
	wyArrayDestroy(closedList);
	closedList = NULL;
	return 0;
}

float wyAStar::heuristic(int startx, int starty, int endx, int endy) {
	int d1 = abs(startx - endx);
	int d2 = abs(starty - endy);
	return sqrt((float)(d1 * d1 + d2 * d2));
}

wyAStarStep* wyAStar::nodeInArray(wyArray* arr, int x, int y) {
	for (int i = 0; i < arr->num; i++) {
		wyAStarStep* node = (wyAStarStep*) wyArrayGet(arr, i);
		if (node->getX() == x && node->getY() == y) {
			return node;
		}
	}
	return NULL;

}

wyAStarStep* wyAStar::findLowestCostNode(wyArray* arr) {
	wyAStarStep* n = NULL;
	wyAStarStep* lowest = NULL;
	for (int i = 0; i < arr->num; i++) {
		n = (wyAStarStep*)wyArrayGet(arr, i);
		if (lowest == NULL) {
			lowest = n;
		} else {
			if (n->getF() < lowest->getF()) {
				lowest = n;
			}
		}
	}
	return lowest;
}
