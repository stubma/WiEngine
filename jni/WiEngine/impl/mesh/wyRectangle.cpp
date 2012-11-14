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
#include "wyRectangle.h"
#include "wyAttribute.h"

wyRectangle::wyRectangle() {
	m_mode = TRIANGLE_STRIP;

	// create vertex data
	Vertex* data = (Vertex*)wyCalloc(4, sizeof(Vertex));

	// init color to white
	kmVec4Fill(&data[0].color, 1, 1, 1, 1);
	kmVec4Fill(&data[1].color, 1, 1, 1, 1);
	kmVec4Fill(&data[2].color, 1, 1, 1, 1);
	kmVec4Fill(&data[3].color, 1, 1, 1, 1);

	// create buffer
	wyBuffer* buf = wyBuffer::makeCustom(data, 4, sizeof(Vertex));
	connectAttribute(wyAttribute::NAME[wyAttribute::POSITION], buf, 0, 3);
	connectAttribute(wyAttribute::NAME[wyAttribute::TEXTURE], buf, sizeof(kmVec3), 2);
	connectAttribute(wyAttribute::NAME[wyAttribute::COLOR], buf, sizeof(kmVec3) + sizeof(kmVec2), 4);
}

wyRectangle::~wyRectangle() {
}

wyRectangle* wyRectangle::make() {
	wyRectangle* rect = WYNEW wyRectangle();
	return (wyRectangle*)rect->autoRelease();
}

void wyRectangle::updateColor4B(wyColor4B color) {
	wyBuffer* buf = getFirstConnectedBuffer();
	Vertex* data = (Vertex*)buf->getData();
	for(int i = 0; i < 4; i++)
		kmVec4Fill(&data[i].color, color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
}

void wyRectangle::update() {
    // calculate correct render area and offset
    float x, y, w, h;
    if(m_enableRenderRect) {
        x = m_renderRect.x + m_offsetX;
        y = m_renderRect.y + m_offsetY;
        w = m_renderRect.width;
        h = m_renderRect.height;
    } else {
        w = m_rotate90CCW ? m_texRect.height : m_texRect.width;
        h = m_rotate90CCW ? m_texRect.width : m_texRect.height;
        float sw = m_texSourceWidth == 0 ? w : m_texSourceWidth;
        float sh = m_texSourceHeight == 0 ? h : m_texSourceHeight;
        x = (sw - w) / 2 + m_offsetX;
        y = (sh - h) / 2 + m_offsetY;
    }

	// get vertices
	float vertices[] = {
		x, y, 0.0f,
		w + x, y, 0.0f,
		x, h + y, 0.0f,
		w + x, h + y, 0.0f
	};

	// get texture coordination
    float left = (2 * m_texRect.x + 1) / (2 * m_texPOTWidth);
    float right = left + (m_texRect.width * 2 - 2) / (2 * m_texPOTWidth);
    float top = (2 * m_texRect.y + 1) / (2 * m_texPOTHeight);
    float bottom = top + (m_texRect.height * 2 - 2) / (2 * m_texPOTHeight);
    float texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
    };

    // need rotate?
    if(m_rotate90CCW) {
    	float bl_x = texCoords[0];
    	float bl_y = texCoords[1];

    	// tl -> bl
    	texCoords[0] = texCoords[4];
    	texCoords[1] = texCoords[5];

    	// tr -> tl
    	texCoords[4] = texCoords[6];
    	texCoords[5] = texCoords[7];

    	// br -> tr
    	texCoords[6] = texCoords[2];
    	texCoords[7] = texCoords[3];

    	// bl -> br
    	texCoords[2] = bl_x;
    	texCoords[3] = bl_y;
    }

    // if flip y axis
	if(m_flipY) {
        // save bl
        float bl_x = texCoords[0];
    	float bl_y = texCoords[1];
        
        // tl -> bl
        texCoords[0] = texCoords[4];
    	texCoords[1] = texCoords[5];
        
        // bl -> tl
        texCoords[4] = bl_x;
    	texCoords[5] = bl_y;
        
        // save br
        float br_x = texCoords[2];
    	float br_y = texCoords[3];
        
        // tr -> br
        texCoords[2] = texCoords[6];
    	texCoords[3] = texCoords[7];
        
        // br -> tr
        texCoords[6] = br_x;
    	texCoords[7] = br_y;
	}

	// if flip x axis
	if(m_flipX) {
        // save bl
        float bl_x = texCoords[0];
    	float bl_y = texCoords[1];
        
        // br -> bl
        texCoords[0] = texCoords[2];
        texCoords[1] = texCoords[3];
        
        // bl -> br
        texCoords[2] = bl_x;
        texCoords[3] = bl_y;
        
        // save tl
        float tl_x = texCoords[4];
        float tl_y = texCoords[5];
        
        // tr -> tl
        texCoords[4] = texCoords[6];
        texCoords[5] = texCoords[7];
        
        // tl -> tr
        texCoords[6] = tl_x;
        texCoords[7] = tl_y;
    }

	// update to buffer
	updateMesh(vertices, texCoords);
}

void wyRectangle::updateMesh(float* vertices, float* texCoords) {
	// get buffer
	wyBuffer* buf = getFirstConnectedBuffer();
	Vertex* data = (Vertex*)buf->getData();

	// bottom left
	kmVec3Fill(&data[0].pos, vertices[0], vertices[1], vertices[2]);
	if(texCoords)
		kmVec2Fill(&data[0].tex, texCoords[0], texCoords[1]);

	// bottom right
	kmVec3Fill(&data[1].pos, vertices[3], vertices[4], vertices[5]);
	if(texCoords)
		kmVec2Fill(&data[1].tex, texCoords[2], texCoords[3]);

	// top left
	kmVec3Fill(&data[2].pos, vertices[6], vertices[7], vertices[8]);
	if(texCoords)
		kmVec2Fill(&data[2].tex, texCoords[4], texCoords[5]);

	// top right
	kmVec3Fill(&data[3].pos, vertices[9], vertices[10], vertices[11]);
	if(texCoords)
		kmVec2Fill(&data[3].tex, texCoords[6], texCoords[7]);
}
