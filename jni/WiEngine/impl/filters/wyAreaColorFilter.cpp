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
#include "wyAreaColorFilter.h"
#include "wyGlobal.h"
#include "wyMath.h"

typedef struct wyPointColorMap {
	int x;
	int y;
	int from;
	int to;
	int fromMask;
	int toMask;
} wyPointColorMap;

wyAreaColorFilter::wyAreaColorFilter() :
		m_mapBuffer((wyPointColorMap*)wyMalloc(sizeof(wyPointColorMap) * 10)),
		m_count(0),
		m_capacity(10) {
}

wyAreaColorFilter::~wyAreaColorFilter() {
	wyFree(m_mapBuffer);
}

wyAreaColorFilter* wyAreaColorFilter::make() {
	wyAreaColorFilter* f = WYNEW wyAreaColorFilter();
	return (wyAreaColorFilter*)f->autoRelease();
}

void wyAreaColorFilter::ensureCapacity() {
	while(m_count >= m_capacity) {
		m_capacity *= 2;
		m_mapBuffer = (wyPointColorMap*)wyRealloc(m_mapBuffer, m_capacity * sizeof(wyPointColorMap));
	}
}

void wyAreaColorFilter::apply(void* data, int width, int height) {
	unsigned char* p = (unsigned char*)data;
	wyPointColorMap* map = (wyPointColorMap*)m_mapBuffer;
	for(int i = 0; i < m_count; i++, map++) {
		if(map->y < height && map->x < width) {
			int start = (map->y * width + map->x) * 4;
			unsigned int r = p[start] & 0xFF;
			unsigned int g = p[start + 1] & 0xFF;
			unsigned int b = p[start + 2] & 0xFF;
			unsigned int a = p[start + 3] & 0xFF;
			unsigned int c = (a << 24) | (r << 16) | (g << 8) | b;

			// if equal, replace source color
			if((c & map->fromMask) == (map->from & map->fromMask)) {
				c = c & ~(map->toMask) | map->to & map->toMask;
				p[start] = (c >> 16) & 0xFF;
				p[start + 1] = (c >> 8) & 0xFF;
				p[start + 2] = c & 0xFF;
				p[start + 3] = (c >> 24) & 0xFF;
			}
		}
	}
}

void wyAreaColorFilter::mapPoint(int x, int y, int from, int to, int fromMask, int toMask) {
	ensureCapacity();

	wyPointColorMap* map = (wyPointColorMap*)m_mapBuffer + m_count;
	map->x = x;
	map->y = y;
	map->from = from;
	map->to = to;
	map->fromMask = fromMask;
	map->toMask = toMask;
	m_count++;
}

void wyAreaColorFilter::removePoint(int x, int y) {
	wyPointColorMap* map = (wyPointColorMap*)m_mapBuffer;
	for(int i = 0; i < m_count; i++, map++) {
		if(map->x == x && map->y == y) {
			memmove(map, map + 1, (m_count - i - 1) * sizeof(wyPointColorMap));
		}
	}
}

void wyAreaColorFilter::mapLine(int x1, int y1, int x2, int y2, int from, int to, int fromMask, int toMask) {
	if(x1 == x2 && y1 == y2)
		mapPoint(x1, y1, from, to, fromMask, toMask);
	else if(x1 == x2) {
		int minY = MIN(y1, y2);
		int maxY = MAX(y1, y2);
		for(int y = minY; y <= maxY; y++) {
			mapPoint(x1, y, from, to, fromMask, toMask);
		}
	} else if(y1 == y2) {
		int minX = MIN(x1, x2);
		int maxX = MAX(x1, x2);
		for(int x = minX; x <= maxX; x++) {
			mapPoint(x, y1, from, to, fromMask, toMask);
		}
	} else {
		int minX = MIN(x1, x2);
		int maxX = MAX(x1, x2);
		float k = (float)(y2 - y1) / (x2 - x1);
		for(int x = minX; x <= maxX; x++) {
			int y = k * x - k * x1 + y1;
			mapPoint(x, y, from, to, fromMask, toMask);
		}
	}
}

void wyAreaColorFilter::removeLine(int x1, int y1, int x2, int y2) {
	if(x1 == x2 && y1 == y2)
		removePoint(x1, y1);
	else if(x1 == x2) {
		int minY = MIN(y1, y2);
		int maxY = MAX(y1, y2);
		for(int y = minY; y <= maxY; y++) {
			removePoint(x1, y);
		}
	} else if(y1 == y2) {
		int minX = MIN(x1, x2);
		int maxX = MAX(x1, x2);
		for(int x = minX; x <= maxX; x++) {
			removePoint(x, y1);
		}
	} else {
		int minX = MIN(x1, x2);
		int maxX = MAX(x1, x2);
		float k = (float)(y2 - y1) / (x2 - x1);
		for(int x = minX; x <= maxX; x++) {
			int y = k * x - k * x1 + y1;
			removePoint(x, y);
		}
	}
}

void wyAreaColorFilter::mapRect(int x, int y, int w, int h, int from, int to, int fromMask, int toMask) {
	int x2 = x + w;
	int y2 = y + h;
	for(int r = y; r < y2; r++) {
		for(int c = x; c < x2; c++) {
			mapPoint(c, r, from, to, fromMask, toMask);
		}
	}
}

void wyAreaColorFilter::removeRect(int x, int y, int w, int h) {
	int x2 = x + w;
	int y2 = y + h;
	for(int r = y; r < y2; r++) {
		for(int c = x; c < x2; c++) {
			removePoint(c, r);
		}
	}
}

void wyAreaColorFilter::mapCircle(int centerX, int centerY, int radius, int from, int to, int fromMask, int toMask) {
	int x1 = centerX - radius;
	int x2 = centerX + radius;
	int y1 = centerY - radius;
	int y2 = centerY + radius;
	int radiusPow2 = radius * radius;
	for(int x = x1; x <= x2; x++) {
		for(int y = y1; y <= y2; y++) {
			int distance = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
			if(distance <= radiusPow2)
				mapPoint(x, y, from, to, fromMask, toMask);
		}
	}
}

void wyAreaColorFilter::removeCircle(int centerX, int centerY, int radius) {
	int x1 = centerX - radius;
	int x2 = centerX + radius;
	int y1 = centerY - radius;
	int y2 = centerY + radius;
	int radiusPow2 = radius * radius;
	for(int x = x1; x <= x2; x++) {
		for(int y = y1; y <= y2; y++) {
			float distance = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
			if(distance <= radiusPow2)
				removePoint(x, y);
		}
	}
}
