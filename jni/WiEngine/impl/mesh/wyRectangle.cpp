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

void wyRectangle::updateColor(wyColor4B color) {
	wyBuffer* buf = getFirstConnectedBuffer();
	Vertex* data = (Vertex*)buf->getData();
	for(int i = 0; i < 4; i++)
		kmVec4Fill(&data[i].color, color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
}

void wyRectangle::updateMesh(float texPixelWidth, float texPixelHeight, float x, float y, float width, float height,
		float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotate90) {
	// get vertices
	float vertices[] = {
		x, y, 0.0f,
		width + x, y, 0.0f,
		x, height + y, 0.0f,
		width + x, height + y, 0.0f
	};

	// get texture coordination
    float left = (2 * texRect.x + 1) / (2 * texPixelWidth);
    float right = left + (texRect.width * 2 - 2) / (2 * texPixelWidth);
    float top = (2 * texRect.y + 1) / (2 * texPixelHeight);
    float bottom = top + (texRect.height * 2 - 2) / (2 * texPixelHeight);
    float texCoords[] = {
		left, bottom,
		right, bottom,
		left, top,
		right, top
    };

    // need rotate?
    if(rotate90) {
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
	if(flipY) {
		wyUtils::swap(texCoords, 0, 4);
		wyUtils::swap(texCoords, 1, 5);
		wyUtils::swap(texCoords, 2, 6);
		wyUtils::swap(texCoords, 3, 7);

		// adjust vertices y value
		vertices[1] = sourceHeight - vertices[1];
		vertices[4] = sourceHeight - vertices[4];
		vertices[7] = sourceHeight - vertices[7];
		vertices[10] = sourceHeight - vertices[10];

		// swap bl and tl, swap br and tr
		wyUtils::swap(vertices, 0, 6);
		wyUtils::swap(vertices, 1, 7);
		wyUtils::swap(vertices, 2, 8);
		wyUtils::swap(vertices, 3, 9);
		wyUtils::swap(vertices, 4, 10);
		wyUtils::swap(vertices, 5, 11);
	}

	// if flip x axis
	if(flipX) {
		wyUtils::swap(texCoords, 0, 2);
		wyUtils::swap(texCoords, 1, 3);
		wyUtils::swap(texCoords, 4, 6);
		wyUtils::swap(texCoords, 5, 7);

		// adjust vertices x value
		vertices[0] = sourceWidth - vertices[0];
		vertices[3] = sourceWidth - vertices[3];
		vertices[6] = sourceWidth - vertices[6];
		vertices[9] = sourceWidth - vertices[9];

		// swap bl and br, swap tl and tr
		wyUtils::swap(vertices, 0, 3);
		wyUtils::swap(vertices, 1, 4);
		wyUtils::swap(vertices, 2, 5);
		wyUtils::swap(vertices, 6, 9);
		wyUtils::swap(vertices, 7, 10);
		wyUtils::swap(vertices, 8, 11);
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
