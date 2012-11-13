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
#include "wyProgress.h"
#include "wyAttribute.h"
#include "wyLog.h"

#define PROGRESS_TEXTURE_COORDS_COUNT 4
#define PROGRESS_TEXTURE_COORDS 0x1e

wyProgress::wyProgress(Style style) :
		m_percentage(0) {
	// set style
	setStyle(style);

	// create buffer
	m_buf = wyBuffer::makeCustom(sizeof(Vertex));

	// connect attribute
	connectAttribute(wyAttribute::NAME[wyAttribute::POSITION], m_buf, 0, 3);
	connectAttribute(wyAttribute::NAME[wyAttribute::TEXTURE], m_buf, sizeof(kmVec3), 2);
	connectAttribute(wyAttribute::NAME[wyAttribute::COLOR], m_buf, sizeof(kmVec3) + sizeof(kmVec2), 4);
}

wyProgress::~wyProgress() {
}

wyProgress* wyProgress::make(Style style) {
	wyProgress* b = WYNEW wyProgress(style);
	return (wyProgress*)b->autoRelease();
}

void wyProgress::setPercentage(float p) {
	m_percentage = MIN(100.0f, MAX(0.0f, p));
}

void wyProgress::setStyle(Style style) {
	m_style = style;

	// set mode
	if(m_style == RADIAL_CCW || m_style == RADIAL_CW) {
		m_mode = TRIANGLE_FAN;
	} else {
		m_mode = TRIANGLE_STRIP;
	}
}

void wyProgress::update() {
	switch(m_style) {
		case RADIAL_CCW:
		case RADIAL_CW:
			updateRadial();
			break;
		case HORIZONTAL_BAR_LR:
		case HORIZONTAL_BAR_RL:
		case VERTICAL_BAR_BT:
		case VERTICAL_BAR_TB:
			updateBar();
			break;
		default:
			break;
	}
}

void wyProgress::updateColor(wyColor4B c, bool premultipliedAlpha) {
	// calculate color
	wyColor4F color = wyc4b2c4f(c);
	if(premultipliedAlpha) {
		float op = c.a / 255.f;
		color.r *= op;
		color.g *= op;
		color.b *= op;
		color.a = op;
	} else {
		color.a = c.a / 255.f;
	}

	// fill all vertex
	int count = m_buf->getElementCount();
	Vertex* v = (Vertex*)m_buf->getData();
	for(int i = 0; i < count; i++) {
		kmVec4Fill(&v[i].color, color.r, color.g, color.b, color.a);
	}
}

void wyProgress::updateRadial() {
	//	Texture Max is the actual max coordinates to deal with non-power of 2 textures
	float tOffsetX = m_texRect.x / m_texPOTWidth;
	float tOffsetY = m_texRect.y / m_texPOTHeight;
	wyPoint tMax = {
			m_texRect.width / m_texPOTWidth,
			m_texRect.height / m_texPOTHeight
	};

	//	Grab the midpoint
	wyPoint midpoint = {
		0.5f * tMax.x,
		0.5f * tMax.y
	};
    
    // get percentage value in [0, 1] range
	float alpha = m_percentage / 100.f;

	//	Otherwise we can get the angle from the alpha
	float angle = 2.0f * M_PI * (m_style == RADIAL_CW ? alpha : (1.0f - alpha));

	//	We find the vector to do a hit detection based on the percentage
	//	We know the first vector is the one @ 12 o'clock (top,mid) so we rotate
	//	from that by the progress angle around the midpoint pivot
	wyPoint topMid = { midpoint.x, 0.0f };
	wyPoint percentagePt = wypRotateByAngle(topMid, midpoint, angle);

    // helper variables
	int index = 0;
	wyPoint hit = wypZero;

    // check percentage
	if(alpha == 0.0f) {
		//	More efficient since we don't always need to check intersection
		//	If the alpha is zero then the hit point is top mid and the index is 0.
		hit = topMid;
		index = 0;
	} else if(alpha == 1.0f) {
		//	More efficient since we don't always need to check intersection
		//	If the alpha is one then the hit point is top mid and the index is 4.
		hit = topMid;
		index = 4;
	} else {
		//	We run a for loop checking the edges of the texture to find the
		//	intersection point
		//	We loop through five points since the top is split in half

		float min_t = MAX_FLOAT;
		for(int i = 0; i <= PROGRESS_TEXTURE_COORDS_COUNT; ++i) {
			int pIndex = (i + (PROGRESS_TEXTURE_COORDS_COUNT - 1)) % PROGRESS_TEXTURE_COORDS_COUNT;

			wyPoint edgePtA = boundaryTexCoord(i % PROGRESS_TEXTURE_COORDS_COUNT);
			edgePtA = wypMul(edgePtA, tMax);
			wyPoint edgePtB = boundaryTexCoord(pIndex);
			edgePtB = wypMul(edgePtB, tMax);

			//	Remember that the top edge is split in half for the 12 o'clock position
			//	Let's deal with that here by finding the correct endpoints
			if(i == 0) {
				edgePtB = wypLerp(edgePtA, edgePtB, .5f);
			} else if(i == 4) {
				edgePtA = wypLerp(edgePtA, edgePtB, .5f);
			}

			//	s and t are returned by lineIntersect
			float st[] = { 0.0f, 0.0f };
			if(wypLineIntersect(edgePtA, edgePtB, midpoint, percentagePt, st)) {
				float s = st[0];
				float t = st[1];

				//	Since our hit test is on rays we have to deal with the top edge
				//	being in split in half so we have to test as a segment
				if((i == 0 || i == 4)) {
					//	s represents the point between edgePtA--edgePtB
					if(!(0.f <= s && s <= 1.f)) {
						continue;
					}
				}
				//	As long as our t isn't negative we are at least finding a
				//	correct hitpoint from midpoint to percentagePt.
				if(t >= 0.f) {
					//	Because the percentage line and all the texture edges are
					//	rays we should only account for the shortest intersection
					if(t < min_t) {
						min_t = t;
						index = i;
					}
				}
			}
		}

		//	Now that we have the minimum magnitude we can use that to find our intersection
		wyPoint tmp1 = wypSub(percentagePt, midpoint);
		tmp1 = wypMul(tmp1, wyp(min_t, min_t));
		hit = wypAdd(midpoint, tmp1);
	}

	//	The size of the vertex data is the index from the hitpoint
	//	the 3 is for the midpoint, 12 o'clock point and hitpoint position.
	if(m_buf->getElementCount() < index + 3) {
        m_buf->reserve(index + 3);
    }
	m_buf->setElementCount(index + 3);

	// get buffer pointer
	Vertex* v = (Vertex*)m_buf->getData();

	// First we populate the array with the midpoint, then all
	// vertices/texcoords/colors of the 12 'o clock start and edges and the hitpoint
	int pos = 0;
	wyPoint vertex = vertexFromTexCoord(midpoint.x, midpoint.y);
	kmVec2Fill(&v[pos].tex, midpoint.x, midpoint.y);
	kmVec3Fill(&v[pos].pos, vertex.x, vertex.y, 0);
	kmVec4Fill(&v[pos].color, 1, 1, 1, 1);
	pos++;

	vertex = vertexFromTexCoord(midpoint.x, 0.0f);
	kmVec2Fill(&v[pos].tex, midpoint.x, 0.0f);
	kmVec3Fill(&v[pos].pos, vertex.x, vertex.y, 0);
	kmVec4Fill(&v[pos].color, 1, 1, 1, 1);
	pos++;

	for(int i = 0; i < index; ++i) {
		// get boundary texture coordinates
		wyPoint texCoord = boundaryTexCoord(i);
		texCoord = wypMul(texCoord, tMax);

		// get vertex from texture coordinate
		vertex = vertexFromTexCoord(texCoord.x, texCoord.y);

		// fill into buffer
		kmVec2Fill(&v[pos].tex, texCoord.x, texCoord.y);
		kmVec3Fill(&v[pos].pos, vertex.x, vertex.y, 0);
		kmVec4Fill(&v[pos].color, 1, 1, 1, 1);

		// next pos
		pos++;
	}

	//	hitpoint will go last
	int count = m_buf->getElementCount();
	index = count - 1;
	vertex = vertexFromTexCoord(hit.x, hit.y);
	kmVec2Fill(&v[index].tex, hit.x, hit.y);
	kmVec3Fill(&v[index].pos, vertex.x, vertex.y, 0);
	kmVec4Fill(&v[index].color, 1, 1, 1, 1);
    
    // when zwoptex texture is rotated, the flipY should be preset, so need check real flip y flag
    bool flipY = m_rotate90CCW ? !m_flipY : m_flipY;
    
    // fill all texture coordinates
    for(int i = 0; i < count; i++) {
        if(m_rotate90CCW) {
            float t_x = v[i].tex.x;
            float t_y = v[i].tex.y;
            v[i].tex.x = t_y / (tMax.y / tMax.x);
            v[i].tex.y = t_x * (tMax.y / tMax.x);
        }
        if (m_flipX || flipY) {
            if(m_flipX) {
                if(m_rotate90CCW)
                    v[i].tex.y = tMax.y - v[i].tex.y;
                else
                    v[i].tex.x = tMax.x - v[i].tex.x;
            }
            if(flipY) {
                if(m_rotate90CCW)
                    v[i].tex.x = tMax.x - v[i].tex.x;
                else
                    v[i].tex.y = tMax.y - v[i].tex.y;
            }
        }
        v[i].tex.x += tOffsetX;
        v[i].tex.y += tOffsetY;
    }

	// The vertices order should be in counter clockwise direction, or else it will be culled if
	// the director->setCullFace() is enabled.
	if(RADIAL_CW == m_style) {
		for(int i = 1; i < count; ++i) {
			int targetIndex = count - i;
			if( i < targetIndex) {
				float tmp = v[i].tex.x;
				v[i].tex.x = v[targetIndex].tex.x;
				v[targetIndex].tex.x = tmp;

				tmp = v[i].tex.y;
				v[i].tex.y = v[targetIndex].tex.y;
				v[targetIndex].tex.y = tmp;

				tmp = v[i].pos.x;
				v[i].pos.x = v[targetIndex].pos.x;
				v[targetIndex].pos.x = tmp;

				tmp = v[i].pos.y;
				v[i].pos.y = v[targetIndex].pos.y;
				v[targetIndex].pos.y = tmp;
			}
		}
	}
}

void wyProgress::updateBar() {
	float alpha = m_percentage / 100.0f;

    // calculate correct render area and offset
    float x, y, w, h;
    x = m_renderRect.x;
    y = m_renderRect.y;
    w = m_renderRect.width;
    h = m_renderRect.height;

	//	Texture Max is the actual max coordinates to deal with non-power of 2 textures
	float tOffsetX = m_texRect.x / m_texPOTWidth;
	float tOffsetY = m_texRect.y / m_texPOTHeight;
	wyPoint tMax = {
			m_texRect.width / m_texPOTWidth,
			m_texRect.height / m_texPOTHeight
	};

	// ensure buffer is enough
	if(m_buf->getElementCount() < PROGRESS_TEXTURE_COORDS_COUNT) {
		m_buf->reserve(PROGRESS_TEXTURE_COORDS_COUNT);
	}
	m_buf->setElementCount(PROGRESS_TEXTURE_COORDS_COUNT);

	// get buffer pointers
	Vertex* v = (Vertex*)m_buf->getData();

	// get texture coordination
	float left = 0;
	float right = tMax.x;
	float top = 0;
	float bottom = tMax.y;
	kmVec2Fill(&v[0].tex, left, bottom);
	kmVec3Fill(&v[0].pos, x, y, 0);
	kmVec4Fill(&v[0].color, 1, 1, 1, 1);
	kmVec2Fill(&v[1].tex, right, bottom);
	kmVec3Fill(&v[1].pos, w + x, y, 0);
	kmVec4Fill(&v[1].color, 1, 1, 1, 1);
	kmVec2Fill(&v[2].tex, left, top);
	kmVec3Fill(&v[2].pos, x, h + y, 0);
	kmVec4Fill(&v[2].color, 1, 1, 1, 1);
	kmVec2Fill(&v[3].tex, right, top);
	kmVec3Fill(&v[3].pos, w + x, h + y, 0);
	kmVec4Fill(&v[3].color, 1, 1, 1, 1);

	// is a rotated zwoptex frame?
	if(m_rotate90CCW) {
		float bl_x = v[0].tex.x;
		float bl_y = v[0].tex.y;
		float t_x = tMax.x;

		// tl -> bl
		v[0].tex.x = v[2].tex.x;
		v[0].tex.y = v[2].tex.y;

		// tr -> tl
		v[2].tex.x = v[3].tex.x;
		v[2].tex.y = v[3].tex.y;

		// br -> tr
		v[3].tex.x = v[1].tex.x;
		v[3].tex.y = v[1].tex.y;

		// bl -> br
		v[1].tex.x = bl_x;
		v[1].tex.y = bl_y;

		tMax.x = tMax.y;
		tMax.y = t_x;
	}

	// now check style, swap values
	if(m_style == HORIZONTAL_BAR_LR) {
		if(m_rotate90CCW) {
			v[1].tex.y = tMax.x * alpha;
			v[3].tex.y = v[1].tex.y;
		} else {
			v[1].tex.x = tMax.x * alpha;
			v[3].tex.x = v[1].tex.x;
		}
		v[1].pos.x = w * alpha;
		v[3].pos.x = v[1].pos.x;
	} else if(m_style == HORIZONTAL_BAR_RL) {
		if(m_rotate90CCW) {
			v[0].tex.y = tMax.x * (1.0f - alpha);
			v[2].tex.y = v[0].tex.y;
		} else {
			v[0].tex.x = tMax.x * (1.0f - alpha);
			v[2].tex.x = v[0].tex.x;
		}
		v[0].pos.x = w * (1.0f - alpha);
		v[2].pos.x = v[0].pos.x;
	} else if(m_style == VERTICAL_BAR_BT) {
		if(m_rotate90CCW) {
			v[2].tex.x = tMax.y * alpha;
			v[3].tex.x = v[2].tex.x;
		} else {
			v[2].tex.y = tMax.y * (1.0f - alpha);
			v[3].tex.y = v[2].tex.y;
		}
		v[2].pos.y = h * alpha;
		v[3].pos.y = v[2].pos.y;
	} else if(m_style == VERTICAL_BAR_TB) {
		if(m_rotate90CCW) {
			v[0].tex.x = tMax.y * (1.0f - alpha);
			v[1].tex.x = v[0].tex.x;
		} else {
			v[0].tex.y = tMax.y * alpha;
			v[1].tex.y = v[0].tex.y;
		}
		v[0].pos.y = h * (1.0f - alpha);
		v[1].pos.y = v[0].pos.y;
	}

	// final compose
	for (int i = 0; i < PROGRESS_TEXTURE_COORDS_COUNT; i++) {
		// handle flip
		if (m_flipY || m_flipX) {
            if(m_flipX) {
                if(m_rotate90CCW)
                    v[i].tex.y = tMax.x - v[i].tex.y;
                else
                    v[i].tex.x = tMax.x - v[i].tex.x;
            }
            if(m_flipY) {
                if(m_rotate90CCW)
                    v[i].tex.x = tMax.y - v[i].tex.x;
                else
                    v[i].tex.y = tMax.y - v[i].tex.y;
            }
		}

		// add offset to final texture coordinates, because it may be an atlas texture
		v[i].tex.x += tOffsetX;
		v[i].tex.y += tOffsetY;
	}
}

wyPoint wyProgress::vertexFromTexCoord(float u, float v) {
	wyPoint ret = { m_texPOTWidth * u , m_texRect.height - m_texPOTHeight * v };

	// map to node space
	ret.x = ret.x * m_texSourceWidth / m_texRect.width;
	ret.y = ret.y * m_texSourceHeight / m_texRect.height;
	return ret;
}

wyPoint wyProgress::boundaryTexCoord(int index) {
	if(index < PROGRESS_TEXTURE_COORDS_COUNT) {
		switch(m_style) {
			case RADIAL_CW:
				return wyp((PROGRESS_TEXTURE_COORDS >> ((index << 1) + 1)) & 1, (PROGRESS_TEXTURE_COORDS >> (index << 1)) & 1);
			case RADIAL_CCW:
				return wyp((PROGRESS_TEXTURE_COORDS >> (7 - (index << 1))) & 1, (PROGRESS_TEXTURE_COORDS >> (7 - ((index << 1) + 1))) & 1);
			default:
				break;
		}
	}
	return wypZero;
}
