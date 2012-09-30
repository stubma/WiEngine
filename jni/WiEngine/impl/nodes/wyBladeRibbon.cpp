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
#include "wyBladeRibbon.h"
#include <stdio.h>
#include <stdlib.h>
#include "wyLog.h"

// max distance between adjacent points
#define MAX_POINT_DISTANCE 5

/**
 * @struct wyBlade
 *
 * 刀痕段
 */
typedef struct wyBlade {
	/// texture of ribbon, wyBlade doesn't retain it
	wyTexture2D* m_texture;

	/// path point list
	wyPoint* m_path;

	/// vertex buffer
	wyPoint* m_vertices;

	/// texture coordinate buffer
	wyPoint* m_texCoords;

	/// point count
	int m_pointCount;

	/// max point allowed in ribbon
	int m_maxPointCount;

	/// color used to render
	wyColor4B m_color;

    /// fade out time
    float m_fadeTime;

    /// deletion time accumulated
    float m_delta;

    /// true means vertices need to be repopulated
    bool m_dirty;

    /// point already rendered
    int m_drawnPointCount;

	wyBlade(wyTexture2D* tex, wyColor4B color, float fade) :
			m_texture(tex),
			m_color(color),
			m_fadeTime(fade),
			m_delta(0),
			m_drawnPointCount(0),
			m_dirty(false),
			m_pointCount(0),
			m_maxPointCount(50) {
		// allocate buffer
		m_path = (wyPoint*)wyMalloc(m_maxPointCount * sizeof(wyPoint));
		m_vertices = (wyPoint*)wyMalloc(2 * m_maxPointCount * sizeof(wyPoint));
		m_texCoords = (wyPoint*)wyMalloc(2 * m_maxPointCount * sizeof(wyPoint));
	}

	~wyBlade() {
		m_texture = NULL;
		wyFree(m_path);
		wyFree(m_vertices);
		wyFree(m_texCoords);
	}

	void setMaxPointCount(int max) {
		if(max > m_maxPointCount) {
			m_maxPointCount = max;

			// reallocate buffer
			m_path = (wyPoint*)wyRealloc(m_path, sizeof(wyPoint) * max);
			m_vertices = (wyPoint*)wyRealloc(m_vertices, sizeof(wyPoint) * 2 * max);
			m_texCoords = (wyPoint*)wyRealloc(m_texCoords, sizeof(wyPoint) * 2 * max);
		}
	}

	void addPoint(wyPoint location) {
		if(m_pointCount == 0) {
			m_path[m_pointCount++] = location;
		} else {
			float distance = wypDistance(m_path[m_pointCount - 1], location);
			if(distance < MAX_POINT_DISTANCE) {
				if(m_pointCount >= m_maxPointCount) {
					memmove(m_path, m_path + 1, sizeof(wyPoint) * (m_maxPointCount - 1));
					m_pointCount--;
				}
				m_path[m_pointCount++] = location;
			} else {
				// get step of segment
				int segment = distance / MAX_POINT_DISTANCE + 1;
				segment = MIN(m_maxPointCount - 1, segment);
				wyPoint step = wypMul2(wypSub(location, m_path[m_pointCount - 1]), 1.f / segment);

				// ensure has enough space
				if(m_pointCount + segment > m_maxPointCount) {
					int need = MIN(m_pointCount, segment - m_maxPointCount + m_pointCount);
					memmove(m_path, m_path + need, sizeof(wyPoint) * (m_pointCount - need));
					m_pointCount -= need;
				}

				// add segment
				for(int i = 0 ; i < segment; i++) {
					wyPoint segPoint = wypAdd(m_path[m_pointCount - 1], step);
					m_path[m_pointCount++] = segPoint;
				}
			}
		}
	}

	void draw() {
		if(m_texture == NULL)
			return;

		// populate if dirty
		if(m_dirty) {
			populate();
			m_dirty = false;
		}

		// ensure texture is loaded
		m_texture->load();

		// enable state
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);

		// set color
		glColor4f(m_color.r / 255.f, m_color.g / 255.f, m_color.b / 255.f, m_color.a / 255.f);

		// bind texture
		glBindTexture(GL_TEXTURE_2D, m_texture->getTexture());

		// pointer
		glVertexPointer(2, GL_FLOAT, 0, m_vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);

		// draw
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 2 * m_pointCount);
		m_drawnPointCount = m_pointCount;

		// restore color
		glColor4f(1, 1, 1, 1);

		// disable state
		glDisable(GL_TEXTURE_2D);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	void populate() {
		// get texture height
		float tH2 = m_texture->getHeight() / 2;

		// get height segment step
		// two points is kept for arrow
		float tailStep = tH2 / MAX(1, m_pointCount - 3);
		float headStep = tH2 / 2;

		// update tail
		wyPoint pre = m_path[0];
		for(int i = 0; i < m_pointCount; i++) {
			// calculate height
			float height = 0;
			if(m_pointCount > 3)
				height = (i > m_pointCount - 3) ? (headStep * (m_pointCount - i - 1)) : (tailStep * i);
			
			// rotate border point along the direction
			float distance = wypDistance(pre, m_path[i]);
			float angle = (float)wypToRadian(wypSub(m_path[i], pre));
			m_vertices[i * 2] = wypRotateByAngle(wyp(pre.x + distance, pre.y + height), pre, angle);
			m_vertices[i * 2 + 1] = wypRotateByAngle(wyp(pre.x + distance, pre.y - height), pre, angle);
			
			// set texture coordinates
			m_texCoords[i * 2].x = 0.1;
			m_texCoords[i * 2].y = 0;
			m_texCoords[i * 2 + 1].x = 0.2;
			m_texCoords[i * 2 + 1].y = 1;

			// go to next
			pre = m_path[i];
		}
	}

	void deletePoint(float delta) {
		if(m_fadeTime > 0) {
			// get point count to be deleted
			m_delta += delta;
			int count = m_delta / m_fadeTime;
			m_delta -= m_fadeTime * count;

			if(count > 0) {
				count = MIN(m_drawnPointCount, count);
				if(count > 0) {
					memmove(m_path, m_path + count, sizeof(wyPoint) * (m_pointCount - count));
					m_pointCount -= count;
					m_drawnPointCount -= count;

					// set flag
					m_dirty = true;
				}
			}
		}
	}
	
	void reset() {
		m_pointCount = 0;
		m_drawnPointCount = 0;
		m_delta = 0;
		m_dirty = false;
	}
} wyBlade;

wyBladeRibbon* wyBladeRibbon::make(wyTexture2D* tex, wyColor4B color, float fade) {
	wyBladeRibbon* r = WYNEW wyBladeRibbon(tex, color, fade);
	return (wyBladeRibbon*)r->autoRelease();
}

wyBladeRibbon::wyBladeRibbon(wyTexture2D* tex, wyColor4B color, float fade) :
		wyRibbon(fade),
		m_blade(NULL),
		m_color(color),
		m_maxPointCount(50),
		m_dyingBlades(wyArrayNew(5)),
		m_reusableBlades(wyArrayNew(5)),
		m_texture(NULL) {
	tex->setAntiAlias(false);
	setTexture(tex);
}

wyBladeRibbon::~wyBladeRibbon() {
	wyObjectRelease(m_texture);

	wyArrayEach(m_dyingBlades, releaseBlade, NULL);
	wyArrayDestroy(m_dyingBlades);

	wyArrayEach(m_reusableBlades, releaseBlade, NULL);
	wyArrayDestroy(m_reusableBlades);

	if(m_blade) {
		WYDELETE(m_blade);
		m_blade = NULL;
	}
}

bool wyBladeRibbon::releaseBlade(wyArray* arr, void* ptr, int index, void* data) {
	wyBlade* blade = (wyBlade*)ptr;
	WYDELETE(blade);
	return true;
}

void wyBladeRibbon::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	// draw dying blades
	for(int i = 0; i < m_dyingBlades->num; i++) {
		wyBlade* blade = (wyBlade*)wyArrayGet(m_dyingBlades, i);
		blade->draw();
	}

	// draw current blade
	if(m_blade)
		m_blade->draw();
}

void wyBladeRibbon::setAlpha(int alpha) {
	m_color.a = alpha;
	if(m_blade)
		m_blade->m_color.a = alpha;
}

wyColor3B wyBladeRibbon::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyBladeRibbon::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	if(m_blade) {
		m_blade->m_color.r = color.r;
		m_blade->m_color.g = color.g;
		m_blade->m_color.b = color.b;
	}
}

void wyBladeRibbon::setColor(wyColor4B color) {
	m_color = color;
	if(m_blade)
		m_blade->m_color = color;
}

void wyBladeRibbon::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_texture);
	m_texture = tex;
}

void wyBladeRibbon::update(float delta) {
	for(int i = m_dyingBlades->num - 1; i >= 0; i--) {
		// delete point in dying blade
		wyBlade* blade = (wyBlade*)wyArrayGet(m_dyingBlades, i);
		blade->deletePoint(delta);
		
		// if no point, add it to reuse queue
		if(blade->m_pointCount <= 0) {
			blade->reset();
			wyArrayPush(m_reusableBlades, blade);
			wyArrayDeleteIndex(m_dyingBlades, i);
		}
	}
	
	if(m_blade)
		m_blade->deletePoint(delta);
}

void wyBladeRibbon::addPoint(wyPoint location) {
	// if first point and current blade is not NULL, push it to drawing array
	if(m_firstPoint) {
		// let current blade dead
		if(m_blade) {
			wyArrayPush(m_dyingBlades, m_blade);
			m_blade = NULL;
		}
	}

	// get blade allocated if not
	if(!m_blade) {
		if(m_reusableBlades->num > 0)
			m_blade = (wyBlade*)wyArrayPop(m_reusableBlades);
		else {
			m_blade = WYNEW wyBlade(m_texture, m_color, m_fadeTime);
			m_blade->setMaxPointCount(m_maxPointCount);
		}
	}

	// add point
	m_blade->addPoint(location);
	m_firstPoint = false;

	// set flag
	m_blade->m_dirty = true;
}

void wyBladeRibbon::reset() {
	if(m_blade) {
		m_blade->reset();
	}
}

void wyBladeRibbon::setMaxPointCount(int max) {
	if(max > m_maxPointCount) {
		m_maxPointCount = max;

		if(m_blade)
			m_blade->setMaxPointCount(max);
	}
}
