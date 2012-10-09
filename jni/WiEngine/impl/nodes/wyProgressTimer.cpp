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
#include "wyProgressTimer.h"
#include <stdlib.h>
#include <math.h>
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"

#define PROGRESS_TEXTURE_COORDS_COUNT 4
#define PROGRESS_TEXTURE_COORDS 0x1e

wyProgressTimer::wyProgressTimer(wyTexture2D* tex) :
		m_style(RADIAL_CCW),
		m_percentage(0),
		m_sprite(WYNEW wySprite(tex)),
		m_vertices(NULL),
		m_texCoords(NULL),
		m_colors(NULL),
		m_vertexCount(0) {
	setContentSize(tex->getWidth(), tex->getHeight());
}

wyProgressTimer::wyProgressTimer(wySprite* sprite) :
		m_style(RADIAL_CCW),
		m_percentage(0),
		m_sprite(NULL),
		m_vertices(NULL),
		m_texCoords(NULL),
		m_colors(NULL),
		m_vertexCount(0) {
	setSprite(sprite);
}

wyProgressTimer::~wyProgressTimer() {
	wyObjectRelease(m_sprite);
	if(m_vertices != NULL)
		wyFree(m_vertices);
	if(m_texCoords != NULL)
		wyFree(m_texCoords);
	if(m_colors != NULL)
		wyFree(m_colors);
}

wyProgressTimer* wyProgressTimer::make(wyTexture2D* tex) {
	wyProgressTimer* t = WYNEW wyProgressTimer(tex);
	return (wyProgressTimer*)t->autoRelease();
}

wyProgressTimer* wyProgressTimer::make(wySprite* sprite) {
	wyProgressTimer* t = WYNEW wyProgressTimer(sprite);
	return (wyProgressTimer*)t->autoRelease();
}

wyPoint wyProgressTimer::vertexFromTexCoord(float u, float v) {
	wyTexture2D* tex = m_sprite->getTexture();
	wyRect texRect = m_sprite->getTextureRect();
	
	if(tex != NULL) {
		wyPoint ret = {tex->getPixelWidth() * u , texRect.height - tex->getPixelHeight() * v};
		// map to node space
		ret.x = ret.x * m_width / texRect.width;
		ret.y = ret.y * m_height / texRect.height;
		return ret;
	} else {
		return wypZero;
	}
}

wyPoint wyProgressTimer::boundaryTexCoord(int index) {
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

void wyProgressTimer::resetCapacity(int c) {
	if(m_vertexCount < c) {
		// release old buffers
		if(m_vertices != NULL)
			wyFree(m_vertices);
		if(m_texCoords != NULL)
			wyFree(m_texCoords);
		if(m_colors != NULL)
			wyFree(m_colors);

		// create buffers
		m_vertices = (GLfloat*)wyMalloc(c * 2 * sizeof(GLfloat));
		m_texCoords = (GLfloat*)wyMalloc(c * 2 * sizeof(GLfloat));
		m_colors = (GLfloat*)wyMalloc(c * 4 * sizeof(GLfloat));
		m_vertexCount = c;
	}
}

void wyProgressTimer::updateColor() {
	wyTexture2D* tex = m_sprite->getTexture();
	wyColor3B c = m_sprite->getColor();
	wyColor4F color = wyc3b2c4f(c);
	if(tex->hasPremultipliedAlpha()) {
		float op = m_sprite->getAlpha() / 255.f;
		color.r *= op;
		color.g *= op;
		color.b *= op;
		color.a = op;
	} else {
		color.a = m_sprite->getAlpha() / 255.f;
	}

	int index = 0;
	for(int i = 0; i < m_vertexCount; i++) {
		m_colors[index++] = color.r;
		m_colors[index++] = color.g;
		m_colors[index++] = color.b;
		m_colors[index++] = color.a;
	}
}

void wyProgressTimer::updateRadial() {
	//	Texture Max is the actual max coordinates to deal with non-power of 2 textures
	wyTexture2D* tex = m_sprite->getTexture();
	wyRect texRect = m_sprite->getTextureRect();
	float tOffsetX = texRect.x / tex->getPixelWidth();
	float tOffsetY = texRect.y / tex->getPixelHeight();
	wyPoint tMax = {
			texRect.width / tex->getPixelWidth(),
			texRect.height / tex->getPixelHeight()
	};

	// if texture is get from opengl, it is natural born y-flipped
	bool flipY = tex->getSource() == SOURCE_OPENGL;
	if(m_sprite->isFlipY())
		flipY = !flipY;

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
	if(m_vertexCount < index + 3) {
        resetCapacity(index + 3);
		updateColor();
    }
    m_vertexCount = index + 3;

	// First we populate the array with the midpoint, then all
	// vertices/texcoords/colors of the 12 'o clock start and edges and the hitpoint
	int pos = 0;
	m_texCoords[pos] = midpoint.x;
	m_texCoords[pos + 1] = midpoint.y;
	wyPoint vertex = vertexFromTexCoord(midpoint.x, midpoint.y);
	m_vertices[pos] = vertex.x;
	m_vertices[pos + 1] = vertex.y;
	pos += 2;

	m_texCoords[pos] = midpoint.x;
	m_texCoords[pos + 1] = 0.0f;
	vertex = vertexFromTexCoord(midpoint.x, 0.0f);
	m_vertices[pos] = vertex.x;
	m_vertices[pos + 1] = vertex.y;
	pos += 2;

	for(int i = 0; i < index; ++i) {
		wyPoint texCoord = boundaryTexCoord(i);
		texCoord = wypMul(texCoord, tMax);

		m_texCoords[pos] = texCoord.x;
		m_texCoords[pos + 1] = texCoord.y;
		vertex = vertexFromTexCoord(texCoord.x, texCoord.y);
		m_vertices[pos] = vertex.x;
		m_vertices[pos + 1] = vertex.y;
		pos += 2;
	}

	//	hitpoint will go last
	index = (m_vertexCount - 1) * 2;
	m_texCoords[index] = hit.x;
	m_texCoords[index + 1] = hit.y;
	vertex = vertexFromTexCoord(hit.x, hit.y);
	m_vertices[index] = vertex.x;
	m_vertices[index + 1] = vertex.y;

    // if sprite is from a rotated zwoptex image, need rotate texture coordinate
    if(m_sprite->isRotatedZwoptex()) {
        float t_x = tMax.x;
        tMax.x = tMax.y;
        tMax.y = t_x;
    }
    
    // fill all texture coordinates
    for(int i = 0; i < m_vertexCount; i++) {
        if(m_sprite->isRotatedZwoptex()) {
            float t_x = m_texCoords[i * 2];
            float t_y = m_texCoords[i * 2 + 1];
            m_texCoords[i*2] = t_y / (tMax.x / tMax.y);
            m_texCoords[i * 2 + 1] = t_x * (tMax.x / tMax.y); 
        }
        if (flipY || m_sprite->isFlipX()) {
            if (m_sprite->isFlipX()) {
                m_texCoords[i * 2] = tMax.x - m_texCoords[i * 2];
            }
            if(flipY) {
                m_texCoords[i * 2 + 1] = tMax.y - m_texCoords[i * 2 + 1];
            }
        }
        m_texCoords[i * 2] += tOffsetX;
        m_texCoords[i * 2 + 1] += tOffsetY;
    }

	// The vertices order should be in counter clockwise direction, or else it will be culled if 
	// the director->setCullFace() is enabled.
	if(RADIAL_CW == m_style) {
		for(int i = 1; i < m_vertexCount; ++i) {
			int targetIndex = m_vertexCount - i;
			if( i < targetIndex) {
				wyUtils::swap(m_texCoords, i * 2, targetIndex * 2);
				wyUtils::swap(m_texCoords, i * 2 + 1, targetIndex * 2 + 1);
				wyUtils::swap(m_vertices, i * 2, targetIndex * 2);
				wyUtils::swap(m_vertices, i * 2 + 1, targetIndex * 2 + 1);
			}
		}
	}
}

void wyProgressTimer::updateBar() {
	float alpha = m_percentage / 100.0f;

	//	Texture Max is the actual max coordinates to deal with non-power of 2 textures
	wyTexture2D* tex = m_sprite->getTexture();
	wyRect texRect = m_sprite->getTextureRect();
	float tOffsetX = texRect.x / tex->getPixelWidth();
	float tOffsetY = texRect.y / tex->getPixelHeight();
	wyPoint tMax = {
			texRect.width / tex->getPixelWidth(),
			texRect.height / tex->getPixelHeight()
	};

	// if texture is get from opengl, it is natural born y-flipped
	bool flipY = tex->getSource() == SOURCE_OPENGL;
	if(m_sprite->isFlipY())
		flipY = !flipY;

	if(m_vertexCount == 0) {
		resetCapacity(PROGRESS_TEXTURE_COORDS_COUNT);
		updateColor();
    }
        
	// get texture coordination
	float left = 0;
	float right = tMax.x;
	float top = 0;
	float bottom = tMax.y;
	m_texCoords[0] = left;
	m_texCoords[1] = bottom;
	m_texCoords[2] = right;
	m_texCoords[3] = bottom;
	m_texCoords[4] = left;
	m_texCoords[5] = top;
	m_texCoords[6] = right;
	m_texCoords[7] = top;

	m_vertices[0] = 0;
	m_vertices[1] = 0;
	m_vertices[2] = m_width;
	m_vertices[3] = 0;
	m_vertices[4] = 0;
	m_vertices[5] = m_height;
	m_vertices[6] = m_width;
	m_vertices[7] = m_height;

	// is a rotated zwoptex frame?
	if(m_sprite->isRotatedZwoptex()) {
		float bl_x = m_texCoords[0];
		float bl_y = m_texCoords[1];
		float t_x = tMax.x;

		// tl -> bl
		m_texCoords[0] = m_texCoords[4];
		m_texCoords[1] = m_texCoords[5];

		// tr -> tl
		m_texCoords[4] = m_texCoords[6];
		m_texCoords[5] = m_texCoords[7];

		// br -> tr
		m_texCoords[6] = m_texCoords[2];
		m_texCoords[7] = m_texCoords[3];

		// bl -> br
		m_texCoords[2] = bl_x;
		m_texCoords[3] = bl_y;

		tMax.x = tMax.y;
		tMax.y = t_x;
	}

	if(m_style == HORIZONTAL_BAR_LR) {
		if(m_sprite->isRotatedZwoptex()) {
			m_texCoords[3] = tMax.x * (alpha);
			m_texCoords[7] = m_texCoords[3];
		} else {
			m_texCoords[2] = tMax.x * (alpha);
			m_texCoords[6] = m_texCoords[2];
		}
		m_vertices[2] = m_width * (alpha);
		m_vertices[6] = m_vertices[2];
	} else if(m_style == HORIZONTAL_BAR_RL) {
		if(m_sprite->isRotatedZwoptex()) {
			m_texCoords[1] = tMax.x * (1.0f - alpha);
			m_texCoords[5] = m_texCoords[1];
		} else {
			m_texCoords[0] = tMax.x * (1.0f - alpha);
			m_texCoords[4] = m_texCoords[0];
		}
		m_vertices[0] = m_width * (1.0f - alpha);
		m_vertices[4] = m_vertices[0];
	} else if(m_style == VERTICAL_BAR_BT) {
		if(m_sprite->isRotatedZwoptex()) {
			m_texCoords[4] = tMax.y * (alpha);
			m_texCoords[6] = m_texCoords[4];
		} else {
			m_texCoords[5] = tMax.y * (1.0f - alpha);
			m_texCoords[7] = m_texCoords[5];
		}
		m_vertices[5] = m_height * (alpha);
		m_vertices[7] = m_vertices[5];
	} else if(m_style == VERTICAL_BAR_TB) {
		if(m_sprite->isRotatedZwoptex()) {
			m_texCoords[0] = tMax.y * (1.0f - alpha);
			m_texCoords[2] = m_texCoords[0];
		} else {
			m_texCoords[1] = tMax.y * (alpha);
			m_texCoords[3] = m_texCoords[1];
		}
		m_vertices[1] = m_height * (1.0f - alpha);
		m_vertices[3] = m_vertices[1];
	}

	for (int i = 0; i < m_vertexCount; i++) {
		// 处理翻转
		if (flipY || m_sprite->isFlipX()) {
			if (m_sprite->isFlipX()) {
				m_texCoords[2 * i] = tMax.x - m_texCoords[2 * i];
			}
			if(flipY) {
				m_texCoords[2 * i + 1] = tMax.y - m_texCoords[2 * i + 1];
			}
		}

		// 给最终的坐标加上偏移，因为可能是个atlas sprite
		m_texCoords[i * 2] += tOffsetX;
		m_texCoords[i * 2 + 1] += tOffsetY;
	}
}

void wyProgressTimer::updateProgress() {
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

void wyProgressTimer::draw() {
	// TODO gles2
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//	if(m_vertexCount == 0)
//		return;
//	if(m_sprite == NULL)
//		return;
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//	glEnable(GL_TEXTURE_2D);
//
//	bool newBlend = false;
//	wyBlendFunc blendFunc = m_sprite->getBlendFunc();
//	if(blendFunc.src != DEFAULT_BLEND_SRC || blendFunc.dst != DEFAULT_BLEND_DST) {
//		newBlend = true;
//		glBlendFunc(blendFunc.src, blendFunc.dst);
//	}
//
//	// ensure texture is loaded
//	wyTexture2D* tex = m_sprite->getTexture();
//	tex->load();
//
//	// bind texture
//	glBindTexture(GL_TEXTURE_2D, tex->getTexture());
//
//	// set pointer
//	glVertexPointer(2, GL_FLOAT, 0, m_vertices);
//	glTexCoordPointer(2, GL_FLOAT, 0, m_texCoords);
//	glColorPointer(4, GL_FLOAT, 0, m_colors);
//
//	// draw
//	if(m_style == RADIAL_CCW || m_style == RADIAL_CW) {
//		glDrawArrays(GL_TRIANGLE_FAN, 0, m_vertexCount);
//	} else if(m_style == HORIZONTAL_BAR_LR || m_style == HORIZONTAL_BAR_RL || m_style == VERTICAL_BAR_BT || m_style == VERTICAL_BAR_TB) {
//		glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vertexCount);
//	}
//
//	if(newBlend)
//		glBlendFunc(DEFAULT_BLEND_SRC, DEFAULT_BLEND_DST);
//
//	glDisable(GL_TEXTURE_2D);
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDisableClientState(GL_COLOR_ARRAY);
}

void wyProgressTimer::setPercentage(float percentage) {
	if(m_percentage != percentage) {
		if(percentage < 0.f)
			m_percentage = 0.f;
		else if(percentage > 100.0f)
			m_percentage = 100.f;
		else
			m_percentage = percentage;

		updateProgress();
	}
}

void wyProgressTimer::setSprite(wySprite* sprite) {
	if(m_sprite != sprite) {
		// set sprite
		wyObjectRetain(sprite);
		wyObjectRelease(m_sprite);
		m_sprite = sprite;

		//	Everytime we set a new sprite, we reset vertex count
		m_vertexCount = 0;

		// reset content size
		setContentSize(sprite->getWidth(), sprite->getHeight());
	}
}

void wyProgressTimer::setStyle(wyProgressTimerStyle style) {
	if(style != m_style) {
		m_style = style;

		//	Everytime we set a new sprite, we reset vertex count
		m_vertexCount = 0;
	}
}

void wyProgressTimer::increase(float delta) {
	float p = m_percentage + delta;
	p = MIN(100, p);
	p = MAX(0, p);
	setPercentage(p);
}
