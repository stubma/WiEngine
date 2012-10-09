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
#include "wyMappingColorFilter.h"
#include "wyGlobal.h"

typedef struct wyColorMap {
	int from;
	int to;
	int fromMask;
	int toMask;
} wyColorMap;

wyMappingColorFilter::wyMappingColorFilter() :
		m_count(0),
		m_capacity(10),
		m_colorMap((wyColorMap*)wyMalloc(10 * sizeof(wyColorMap))) {
}

wyMappingColorFilter::~wyMappingColorFilter() {
	wyFree(m_colorMap);
}

wyMappingColorFilter* wyMappingColorFilter::make() {
	wyMappingColorFilter* f = WYNEW wyMappingColorFilter();
	return (wyMappingColorFilter*)f->autoRelease();
}

void wyMappingColorFilter::apply(void* data, int width, int height) {
	unsigned char* p = (unsigned char*)data;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			unsigned int r = p[0] & 0xFF;
			unsigned int g = p[1] & 0xFF;
			unsigned int b = p[2] & 0xFF;
			unsigned int a = p[3] & 0xFF;
			unsigned int c = (a << 24) | (r << 16) | (g << 8) | b;

			// check every mapping
			for(int i = 0; i < m_count; i++) {
				wyColorMap* map = (wyColorMap*)m_colorMap + i;

				// if equal, replace source color
				if((c & map->fromMask) == (map->from & map->fromMask)) {
					c = c & ~(map->toMask) | map->to & map->toMask;
					p[0] = (c >> 16) & 0xFF;
					p[1] = (c >> 8) & 0xFF;
					p[2] = c & 0xFF;
					p[3] = (c >> 24) & 0xFF;

					break;
				}
			}

			p += 4;
		}
	}
}

void wyMappingColorFilter::mapColor(int from, int to, int fromMask, int toMask) {
	while(m_count >= m_capacity) {
		m_capacity *= 2;
		m_colorMap = (wyColorMap*)wyRealloc(m_colorMap, m_capacity * sizeof(wyColorMap));
	}

	wyColorMap* map = (wyColorMap*)m_colorMap + m_count;
	map->from = from;
	map->to = to;
	map->fromMask = fromMask;
	map->toMask = toMask;
	m_count++;
}

void wyMappingColorFilter::unmapColor(int from) {
	for(int i = 0; i < m_count; i++) {
		wyColorMap* map = (wyColorMap*)m_colorMap + i;
		if(map->from == from) {
			memmove(map, map + 1, (m_count - i - 1) * sizeof(wyColorMap));
			break;
		}
	}
}
