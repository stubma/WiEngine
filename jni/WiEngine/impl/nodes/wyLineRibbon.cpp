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
#include "wyLineRibbon.h"
#include "wyLog.h"
#include "wyGlobal.h"

/**
 * @typedef wyStraightLine
 *
 * 一条直线, 我们把每个直线段分成8个顶点
 * 1----3------------------------5----7
 * |    |                        |    |
 * |    a                        b    |
 * |    |                        |    |
 * 0----2------------------------4----6
 * 我们把贴图一分两半, 0123是左边, 4567是右边, 2345是中间的拉伸区域.
 * a: 起始点
 * b: 结束点
 * 0: a的西南点(SW)
 * 1: a的西北点(NW)
 * 2: a的南点(S)
 * 3: a的北点(N)
 * 4: b的南点(N)
 * 5: b的北点(N)
 * 6: b的东南点(SE)
 * 7: b的东北点(NE)
 */
typedef struct wyStraightLine {
	/// vertices for straight line
	wyVertex3D m_vertices[8];

	/// 贴图数组
	wyPoint m_texCoords[8];

	/// 贴图
	wyTexture2D* m_tex;

	wyStraightLine(wyTexture2D* tex) {
		m_tex = tex;
	}

	/**
	 * 根据直线的起始和结束点计算顶点和贴图坐标
	 *
	 * @param start 起始点
	 * @param end 结束点
	 * @param lineWidth 线段宽度
	 * @param head true表示这个线段要包含半圆头部
	 * @param tail true表示这个线段要包含半圆尾部
	 */
	void populate(wyPoint start, wyPoint end, float lineWidth, bool head, bool tail) {
		float length = wypDistance(start, end);
		wyPoint e = length > 0 ? wypMul2(wypNormalize(wypSub(end, start)), lineWidth / 2) : wyp(lineWidth / 2, 0);
		wyPoint N = wyp(-e.y, e.x);
		wyPoint S = wyp(-N.x, -N.y);
		wyPoint NE = wypAdd(N, e);
		wyPoint NW = wypSub(N, e);
		wyPoint SW = wyp(-NE.x, -NE.y);
		wyPoint SE = wyp(-NW.x, -NW.y);

		// 0
		wyPoint p = wypAdd(start, SW);
		m_vertices[0].x = p.x;
		m_vertices[0].y = p.y;
		m_vertices[0].z = 0;

		// 1
		p = wypAdd(start, NW);
		m_vertices[1].x = p.x;
		m_vertices[1].y = p.y;
		m_vertices[1].z = 0;

		// 2
		p = wypAdd(start, S);
		m_vertices[2].x = p.x;
		m_vertices[2].y = p.y;
		m_vertices[2].z = 0;

		// 3
		p = wypAdd(start, N);
		m_vertices[3].x = p.x;
		m_vertices[3].y = p.y;
		m_vertices[3].z = 0;

		// 4
		p = wypAdd(end, S);
		m_vertices[4].x = p.x;
		m_vertices[4].y = p.y;
		m_vertices[4].z = 0;

		// 5
		p = wypAdd(end, N);
		m_vertices[5].x = p.x;
		m_vertices[5].y = p.y;
		m_vertices[5].z = 0;

		// 6
		p = wypAdd(end, SE);
		m_vertices[6].x = p.x;
		m_vertices[6].y = p.y;
		m_vertices[6].z = 0;

		// 7
		p = wypAdd(end, NE);
		m_vertices[7].x = p.x;
		m_vertices[7].y = p.y;
		m_vertices[7].z = 0;

		/*
		 * populate texture coordinates
		 */
		float tW = m_tex->getWidth();
		float tH = m_tex->getHeight();
		float pixelW = m_tex->getPixelWidth();
		float pixelH = m_tex->getPixelHeight();
		float left = 1 / (2 * pixelW);
		float right = left + (tW * 2 - 2) / (2 * pixelW);
	    float bottom = 1 / (2 * pixelH);
	    float top = bottom + (tH * 2 - 2) / (2 * pixelH);
	    float centerW = (left + right) / 2;
	    float centerH = (top + bottom) / 2;
		m_texCoords[0].x = left;
		m_texCoords[0].y = bottom;
		m_texCoords[1].x = left;
		m_texCoords[1].y = top;
		m_texCoords[2].x = centerW;
		m_texCoords[2].y = bottom;
		m_texCoords[3].x = centerW;
		m_texCoords[3].y = top;
		m_texCoords[4].x = centerW;
		m_texCoords[4].y = bottom;
		m_texCoords[5].x = centerW;
		m_texCoords[5].y = top;
		m_texCoords[6].x = right;
		m_texCoords[6].y = bottom;
		m_texCoords[7].x = right;
		m_texCoords[7].y = top;

		// check head, if not head, combine some points
		if(!head) {
			// move 0 to 2
			m_vertices[0].x = m_vertices[2].x;
			m_vertices[0].y = m_vertices[2].y;
			m_vertices[0].z = m_vertices[2].z;
			m_texCoords[0].x = m_texCoords[2].x;
			m_texCoords[0].y = m_texCoords[2].y;

			// move 1 to 3
			m_vertices[1].x = m_vertices[3].x;
			m_vertices[1].y = m_vertices[3].y;
			m_vertices[1].z = m_vertices[3].z;
			m_texCoords[1].x = m_texCoords[3].x;
			m_texCoords[1].y = m_texCoords[3].y;
		}

		// check tail
		if(!tail) {
			// move 6 to 4
			m_vertices[6].x = m_vertices[4].x;
			m_vertices[6].y = m_vertices[4].y;
			m_vertices[6].z = m_vertices[4].z;
			m_texCoords[6].x = m_texCoords[4].x;
			m_texCoords[6].y = m_texCoords[4].y;
			
			// move 7 to 5
			m_vertices[7].x = m_vertices[5].x;
			m_vertices[7].y = m_vertices[5].y;
			m_vertices[7].z = m_vertices[5].z;
			m_texCoords[7].x = m_texCoords[5].x;
			m_texCoords[7].y = m_texCoords[5].y;
		}
	}

	void draw() {
		glVertexPointer(3, GL_FLOAT, 0, (GLvoid*)m_vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, (GLvoid*)m_texCoords);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
	}
} wyStraightLine;

/**
 * @typedef wyLine
 *
 * 代表了一条可以弯曲的线，它有多个直线段组成
 */
typedef struct wyLine {
	/// point buffer of line
	wyPoint* m_points;

	/// point count
	int m_pointCount;

	/// capacity of point buffer
	int m_capacity;

	/// vertices of line joint
	wyVertex3D* m_jointVertices;

	/// texture coordinates of line joint
	wyPoint* m_jointTexCoords;

	/// texture
	wyTexture2D* m_tex;

	/// color
	wyColor4B m_color;

	/// line width
	float m_lineWidth;

	/**
	 * 所有的直线段
	 */
	wyArray* m_straightLines;

	static bool releaseStraightLine(wyArray* arr, void* ptr, int index, void* data) {
		WYDELETE((wyStraightLine*)ptr);
		return true;
	}

	wyLine(wyTexture2D* tex, wyColor4B color, float lineWidth) {
		m_tex = tex;
		m_pointCount = 0;
		m_capacity = 20;
		m_lineWidth = lineWidth;
		m_color = color;
		m_points = (wyPoint*)wyMalloc(m_capacity * sizeof(wyPoint));
		m_jointVertices = (wyVertex3D*)wyMalloc(m_capacity * 6 * sizeof(wyVertex3D));
		m_jointTexCoords = (wyPoint*)wyMalloc(m_capacity * 6 * sizeof(wyPoint));
		m_straightLines = wyArrayNew(m_capacity);
	}

	~wyLine() {
		wyFree(m_points);
		wyFree(m_jointVertices);
		wyFree(m_jointTexCoords);
		wyArrayEach(m_straightLines, releaseStraightLine, NULL);
		wyArrayDestroy(m_straightLines);
	}

	void draw() {
		// set color
		glColor4f(m_color.r / 255.f, m_color.g / 255.f, m_color.b / 255.f, m_color.a / 255.f);

		// draw straight lines
		for(int i = 0; i < m_straightLines->num; i++) {
			wyStraightLine* sl = (wyStraightLine*)wyArrayGet(m_straightLines, i);
			sl->draw();
		}

		// draw joints
		if(m_straightLines->num > 1) {
			glVertexPointer(3, GL_FLOAT, 0, (GLvoid*)m_jointVertices);
			glTexCoordPointer(2, GL_FLOAT, 0, (GLvoid*)m_jointTexCoords);
			glDrawArrays(GL_TRIANGLES, 0, 6 * (m_straightLines->num - 1));
		}
	}

	void addPoint(wyPoint& loc) {
		// ensure capacity
		while(m_pointCount >= m_capacity) {
			m_capacity *= 2;
			m_points = (wyPoint*)wyRealloc(m_points, m_capacity * sizeof(wyPoint));
			m_jointVertices = (wyVertex3D*)wyRealloc(m_jointVertices, m_capacity * 6 * sizeof(wyVertex3D));
			m_jointTexCoords = (wyPoint*)wyRealloc(m_jointTexCoords, m_capacity * 6 * sizeof(wyPoint));
		}

		// add point
		m_points[m_pointCount++] = loc;

		// get straight line, when point count is 2, don't create new straight line
		bool head = false;
		bool tail = true;
		int lineIndex;
		wyPoint start, end;
		wyStraightLine* sl = NULL;
		if(m_pointCount == 2) {
			lineIndex = 0;
			sl = (wyStraightLine*)wyArrayGet(m_straightLines, lineIndex);

			// decide start and end points
			start = m_points[0];
			end = m_points[1];
			head = true;
		} else {
			sl = WYNEW wyStraightLine(m_tex);
			wyArrayPush(m_straightLines, sl);
			lineIndex = m_straightLines->num - 1;

			// decide start and end points
			if(m_pointCount == 1) {
				start = end = m_points[0];
				head = true;
			} else {
				start = m_points[m_pointCount - 2];
				end = m_points[m_pointCount - 1];
			}
		}

		// populate straight line
		if(sl)
			sl->populate(start, end, m_lineWidth, head, tail);

		// repopulate previous line
		if(lineIndex > 0) {
			lineIndex--;
			wyStraightLine* prevSL = (wyStraightLine*)wyArrayGet(m_straightLines, lineIndex);
			end = start;
			start = m_points[m_pointCount - 3];
			prevSL->populate(start, end, m_lineWidth, lineIndex == 0, false);

			// texture coordinates
			float tW_2 = m_tex->getWidth() / m_tex->getPixelWidth() / 2;
			float tH_2 = m_tex->getHeight() / m_tex->getPixelHeight() / 2;

			// add joint vertices, first triangle
			int pos = lineIndex * 6;
			m_jointVertices[pos].x = end.x;
			m_jointVertices[pos].y = end.y;
			m_jointVertices[pos].z = 0;
			m_jointVertices[pos + 1].x = prevSL->m_vertices[6].x;
			m_jointVertices[pos + 1].y = prevSL->m_vertices[6].y;
			m_jointVertices[pos + 1].z = prevSL->m_vertices[6].z;
			m_jointVertices[pos + 2].x = sl->m_vertices[0].x;
			m_jointVertices[pos + 2].y = sl->m_vertices[0].y;
			m_jointVertices[pos + 2].z = sl->m_vertices[0].z;

			// add joint texture coordinates, first triangle
			m_jointTexCoords[pos].x = tW_2;
			m_jointTexCoords[pos].y = tH_2;
			m_jointTexCoords[pos + 1].x = tW_2;
			m_jointTexCoords[pos + 1].y = tH_2;
			m_jointTexCoords[pos + 2].x = tW_2;
			m_jointTexCoords[pos + 2].y = tH_2;

			// add joint vertices, second triangle
			pos += 3;
			m_jointVertices[pos].x = end.x;
			m_jointVertices[pos].y = end.y;
			m_jointVertices[pos].z = 0;
			m_jointVertices[pos + 1].x = prevSL->m_vertices[7].x;
			m_jointVertices[pos + 1].y = prevSL->m_vertices[7].y;
			m_jointVertices[pos + 1].z = prevSL->m_vertices[7].z;
			m_jointVertices[pos + 2].x = sl->m_vertices[1].x;
			m_jointVertices[pos + 2].y = sl->m_vertices[1].y;
			m_jointVertices[pos + 2].z = sl->m_vertices[1].z;

			// add joint texture coordinates, second triangle
			m_jointTexCoords[pos].x = tW_2;
			m_jointTexCoords[pos].y = tH_2;
			m_jointTexCoords[pos + 1].x = tW_2;
			m_jointTexCoords[pos + 1].y = tH_2;
			m_jointTexCoords[pos + 2].x = tW_2;
			m_jointTexCoords[pos + 2].y = tH_2;
		}
	}
} wyLine;

wyLineRibbon* wyLineRibbon::make(wyTexture2D* tex, wyColor4B color) {
	wyLineRibbon* r = WYNEW wyLineRibbon(tex, color);
	return (wyLineRibbon*)r->autoRelease();
}

wyLineRibbon::wyLineRibbon(wyTexture2D* tex, wyColor4B color) :
		wyRibbon(0),
		m_color(color),
		m_lineWidth(tex->getHeight()),
		m_lines(wyArrayNew(20)) {
	m_tex = tex;
	m_tex->retain();
}

wyLineRibbon::~wyLineRibbon() {
	wyObjectRelease(m_tex);
	wyArrayEach(m_lines, releaseLine, NULL);
	wyArrayDestroy(m_lines);
}

bool wyLineRibbon::releaseLine(wyArray* arr, void* ptr, int index, void* data) {
	WYDELETE((wyLine*)ptr);
	return true;
}

void wyLineRibbon::setLineWidth(float width) {
	m_lineWidth = width;
}

void wyLineRibbon::update(float delta) {
}

void wyLineRibbon::addPoint(wyPoint location) {
	// line to add point
	wyLine* line = NULL;

	// if first point, new a line
	if(m_firstPoint) {
		m_firstPoint = false;
		line = WYNEW wyLine(m_tex, m_color, m_lineWidth);
		wyArrayPush(m_lines, line);
	} else {
		// get last line
		line = (wyLine*)wyArrayPeek(m_lines);

		// if null, create a new
		if(!line) {
			line = WYNEW wyLine(m_tex, m_color, m_lineWidth);
			wyArrayPush(m_lines, line);
		}
	}

	// add point to line
	line->addPoint(location);
}

void wyLineRibbon::reset() {
	wyArrayEach(m_lines, releaseLine, NULL);
	wyArrayClear(m_lines);
	m_preLastLocation = m_lastLocation = wypZero;
	m_firstPoint = true;
}

void wyLineRibbon::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}

wyColor3B wyLineRibbon::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyLineRibbon::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
}

void wyLineRibbon::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
}

void wyLineRibbon::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}
	
	// ensure texture object is created
	m_tex->load();

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	
	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, m_tex->getTexture());
	
	// draw all lines
	for(int i = 0; i < m_lines->num; i++) {
		wyLine* line = (wyLine*)wyArrayGet(m_lines, i);
		line->draw();
	}
	
	// restore color
	glColor4f(1, 1, 1, 1);

	// disable state
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

float wyLineRibbon::getLineWidth(int index) {
	if(index < 0 || index >= m_lines->num) {
		LOGW("wyLineRibbon::getLineWidth: index %d is not valid", index);
		return 0;
	} else
		return ((wyLine*)wyArrayGet(m_lines, index))->m_lineWidth;
}

wyColor4B wyLineRibbon::getLineColor(int index) {
	if(index < 0 || index >= m_lines->num) {
		LOGW("wyLineRibbon::getLineColor: index %d is not valid", index);
		return wyc4bWhite;
	} else
		return ((wyLine*)wyArrayGet(m_lines, index))->m_color;
}

int wyLineRibbon::getLinePointCount(int index) {
	if(index < 0 || index >= m_lines->num) {
		LOGW("wyLineRibbon::getLinePointCount: index %d is not valid", index);
		return 0;
	} else
		return ((wyLine*)wyArrayGet(m_lines, index))->m_pointCount;
}

wyPoint* wyLineRibbon::getLinePointList(int index) {
	if(index < 0 || index >= m_lines->num) {
		LOGW("wyLineRibbon::getLinePointList: index %d is not valid", index);
		return 0;
	} else
		return ((wyLine*)wyArrayGet(m_lines, index))->m_points;
}
