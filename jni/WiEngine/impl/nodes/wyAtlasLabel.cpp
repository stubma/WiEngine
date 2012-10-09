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
#include "wyAtlasLabel.h"
#include <stdlib.h>
#include "wyLog.h"
#include "wyZwoptexManager.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyMaterial.h"
#include "wyQuadList.h"
#include "wyMaterialTextureParameter.h"
#if ANDROID
	#include "wyJNI.h"
#endif

typedef struct wyCharHash {
	// for simple rect
	wyRect r;

	// for zwoptex
	wyZwoptexFrame* f;

	// char
	size_t c;

	// 左边的空白区域
	float leftPadding;

	// 右边的空白区域
	float rightPadding;
} wyCharHash;

typedef struct wyCharHashData {
	// for simple rect
	wyRect r;

	// for zwoptex
	wyZwoptexFrame* f;

	// 左边的空白区域
	float leftPadding;

	// 右边的空白区域
	float rightPadding;
} wyCharHashData;

wyCharMap::wyCharMap() :
		m_charMap(wyHashSetNew(10, charHashEquals, buildCharHash)),
        m_spaceWidth(DP(6)),
        m_totalCharHeight(0),
        m_tabSize(4) {
}

wyCharMap::~wyCharMap() {
	wyHashSetFilter(m_charMap, releaseHash, NULL);
	wyHashSetDestroy(m_charMap);
}

wyCharMap* wyCharMap::make() {
	wyCharMap* cm = WYNEW wyCharMap();
	return (wyCharMap*)cm->autoRelease();
}

bool wyCharMap::releaseHash(void* elt, void* data) {
	wyFree(elt);
	return false;
}

int wyCharMap::charHashEquals(void* ptr, void* elt) {
	size_t c = (size_t)ptr;
	wyCharHash* hash = (wyCharHash*)elt;
	return hash->c == c;
}

void* wyCharMap::buildCharHash(void* ptr, void* data) {
	wyCharHashData* d = (wyCharHashData*)data;
	size_t c = (size_t)ptr;
	wyCharHash* hash = (wyCharHash*)wyMalloc(sizeof(wyCharHash));
	hash->c = c;
	hash->f = d->f;
	hash->r = d->r;
	hash->leftPadding = d->leftPadding;
	hash->rightPadding = d->rightPadding;
	return hash;
}

vector<float>* wyCharMap::measureWidth(vector<const char*>* lines) {
	vector<float>* widthList = WYNEW vector<float>();
	widthList->reserve(lines->size());

	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		char* p = (char*)(*iter);
		bool firstLineChar = true;
		float x = 0;

	    while(*p != 0) {
	    	// get char integer
	    	int c = 0;
	    	int b = wyUtils::getUTF8Bytes(*p);
	    	while(b-- > 0) {
	    		c <<= 8;
	    		c |= *p & 0xff;
	    		p++;
	    	}

	    	wyCharHash* hash = (wyCharHash*)wyHashSetFind(m_charMap, (size_t)c, (void*)c);
	    	if(hash) {
	        	// if first, add left
	        	if(!firstLineChar) {
	        		x += hash->leftPadding;
	        	}

	        	// add width
				// get char size
				if(hash->f != NULL) {
					x += hash->f->sourceSize.width;
				} else {
					x += hash->r.width;
				}

	        	// add right padding
	        	x += hash->rightPadding;
	    	} else {
				if(c == ' ') {
					x += m_spaceWidth;
				} else if(c == '\t') {
					x += m_spaceWidth * m_tabSize;
				}
	    	}

			// we can clear line first char flag here
			firstLineChar = false;
	    }

	    // save width
	    widthList->push_back(x);
	}

	return widthList;
}

void wyCharMap::updateAtlas(const char* text, float lineWidth, float lineSpacing, wyAtlasLabel::Alignment alignment, wyAtlasLabel* label, float* w, float* h) {
	// clear atlas
	wyQuadList* atlas = (wyQuadList*)label->getMesh();
	atlas->removeAllQuads();

	// if text is null, do nothing
	if(!text)
		return;

	// break line into a vector
	vector<const char*>* lines = wyUtils::breakLines(text, this, lineWidth, m_spaceWidth, m_tabSize);

	// get width first because we need support text alignment
	vector<float>* widthList = measureWidth(lines);
	
	// get max width
	float maxWidth = 0;
	for(vector<float>::iterator iter = widthList->begin(); iter != widthList->end(); iter++) {
		maxWidth = MAX(maxWidth, *iter);
	}
	
	// line number
	int line = 0;
	
	// real width of final render
	float width = 0;

	// final render y position
	float y = 0;

	// prev line height
	float prevLineHeight = 0;

	// texture size
	float texPixelWidth = label->getTexture()->getPixelWidth();
	float texPixelHeight = label->getTexture()->getPixelHeight();

	// render line one by one
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++, line++) {
		char* p = (char*)(*iter);
		float x = 0;
		float left, right, top, bottom;
		float texLeft, texRight, texTop, texBottom;
		float charWidth, charHeight;
		float currentLineHeight = 0;
		bool firstLineChar = true;
		float lineOffset = 0;
		wyQuad3D v;
		wyQuad2D t;

		// first line offset
		switch(alignment) {
			case wyAtlasLabel::LEFT:
				lineOffset = 0;
				break;
			case wyAtlasLabel::CENTER:
				lineOffset = (maxWidth - widthList->at(line)) / 2;
				break;
			case wyAtlasLabel::RIGHT:
				lineOffset = maxWidth - widthList->at(line);
				break;
		}

		// if first char of this line, add line spacing
		if(line > 0) {
			y += lineSpacing;
			if(prevLineHeight == 0)
				y += getEmptyLineHeight();
			else
				y += prevLineHeight;
		}

		while(*p) {
			// get integer of utf-8 byte sequence
			int c = 0;
			int b = wyUtils::getUTF8Bytes(*p);
			while(b-- > 0) {
				c <<= 8;
				c |= *p & 0xff;
				p++;
			}

			// find mapped hash
			wyCharHash* hash = (wyCharHash*)wyHashSetFind(m_charMap, (size_t)c, (void*)c);
			if(hash != NULL) {
				// get char size
				if(hash->f != NULL) {
					charWidth = hash->f->sourceSize.width;
					charHeight = hash->f->sourceSize.height;
				} else {
					charWidth = hash->r.width;
					charHeight = hash->r.height;
				}

				// if not first char of line, add left padding
				if(!firstLineChar) {
					x += hash->leftPadding;
				}

				// choose max height as line height
				currentLineHeight = MAX(currentLineHeight, charHeight);

				// calculate vertices and texture coordinates
				if(hash->f != NULL) {
				    // calculate offset
					float charColorWidth = hash->f->rotated ? hash->f->rect.height : hash->f->rect.width;
					float charColorHeight = hash->f->rotated ? hash->f->rect.width : hash->f->rect.height;
			        float offsetX = (charWidth - charColorWidth) / 2 + hash->f->offset.x;
			        float offsetY = (charHeight - charColorHeight) / 2 + hash->f->offset.y;

			        // then border
			        left = x + lineOffset + offsetX;
			        right = left + charColorWidth;
			        bottom = y + charHeight - offsetY;
			        top = bottom - charColorHeight;

					texLeft = hash->f->rect.x / texPixelWidth;
					texRight = (hash->f->rect.x + hash->f->rect.width) / texPixelWidth;
					texTop = hash->f->rect.y / texPixelHeight;
					texBottom = (hash->f->rect.y + hash->f->rect.height) / texPixelHeight;
				} else {
					left = x + lineOffset;
					right = left + charWidth;
					top = y;
					bottom = y + charHeight;

					texLeft = hash->r.x / texPixelWidth;
					texRight = (hash->r.x + charWidth) / texPixelWidth;
					texTop = hash->r.y / texPixelHeight;
					texBottom = (hash->r.y + charHeight) / texPixelHeight;
				}

				// adjust x and y
				x += charWidth + hash->rightPadding;

				// build vertices
				v.bl_x = left;
				v.bl_y = bottom;
				v.bl_z = 0;
				v.br_x = right;
				v.br_y = bottom;
				v.br_z = 0;
				v.tl_x = left;
				v.tl_y = top;
				v.tl_z = 0;
				v.tr_x = right;
				v.tr_y = top;
				v.tr_z = 0;

				// build texture coordinates
		        if(hash->f != NULL && hash->f->rotated) {
		    		t.bl_x = texLeft;
		    		t.bl_y = texTop;
		    		t.br_x = texLeft;
		    		t.br_y = texBottom;
		    		t.tl_x = texRight;
		    		t.tl_y = texTop;
		    		t.tr_x = texRight;
		    		t.tr_y = texBottom;
		        } else {
					t.bl_x = texLeft;
					t.bl_y = texBottom;
					t.br_x = texRight;
					t.br_y = texBottom;
					t.tl_x = texLeft;
					t.tl_y = texTop;
					t.tr_x = texRight;
					t.tr_y = texTop;
		        }

				// write to atlas
				atlas->appendQuad(t, v);
			} else {
				if(c == ' ')
					x += m_spaceWidth;
				else if(c == '\t')
					x += m_spaceWidth * m_tabSize;
			}

			// we can clear line first char flag here
			firstLineChar = false;
		}

		// save line height
		prevLineHeight = currentLineHeight;

		// save max width
		width = MAX(width, x);
	}

	// add last line
	if(prevLineHeight != 0) {
		y += prevLineHeight;
	}

	// write back
	if(w != NULL)
		*w = width;
	if(h != NULL)
		*h = y;

	// batch update vertices
	atlas->scale(1, -1, 1);
	atlas->translate(0, y, 0);
	
	// release
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		wyFree((void*)*iter);
	}
	WYDELETE(lines);
	WYDELETE(widthList);
}

void wyCharMap::mapChar(wyRect rect, int c, float leftPadding, float rightPadding) {
	wyCharHashData data = {
		rect,
		NULL,
		leftPadding,
		rightPadding
	};
	wyHashSetInsert(m_charMap, (size_t)c, (void*)c, &data);
	m_totalCharHeight += rect.height;
}

void wyCharMap::mapChar(const char* frameName, int c, float leftPadding, float rightPadding) {
	wyZwoptexFrame* f = wyZwoptexManager::getInstance()->getZwoptexFrame(frameName);
	if(f == NULL)
		return;

	wyCharHashData data = {
		wyrZero,
		f,
		leftPadding,
		rightPadding
	};
	wyHashSetInsert(m_charMap, (size_t)c, (void*)c, &data);
	m_totalCharHeight += f->sourceSize.height;
}

void wyCharMap::mapChar(const char* zwoptexName, const char* frameName, int c, float leftPadding, float rightPadding) {
	wyZwoptexFrame* f = wyZwoptexManager::getInstance()->getZwoptexFrame(zwoptexName, frameName);
	if(f == NULL)
		return;

	wyCharHashData data = {
		wyrZero,
		f,
		leftPadding,
		rightPadding
	};
	wyHashSetInsert(m_charMap, (size_t)c, (void*)c, &data);
	m_totalCharHeight += f->sourceSize.height;
}

float wyCharMap::measureText(const char* chars, int length, float spaceWidth, float tabSize) {
	bool firstChar = true;
	float w = 0;
	char* p = (char*)chars;
	for (int i = 0; i < length;) {
		// get character integer
		int b = wyUtils::getUTF8Bytes((unsigned char)chars[i]);
    	i += b;
    	int c = 0;
    	while(b-- > 0) {
    		c <<= 8;
    		c |= *p & 0xff;
    		p++;
    	}

    	// get char info
    	wyCharHash* hash = (wyCharHash*)wyHashSetFind(m_charMap, (size_t)c, (void*)c);
    	if(hash) {
        	// if first, add left
        	if(!firstChar) {
        		w += hash->leftPadding;
        	}

        	// add width
			// get char size
			if(hash->f != NULL) {
				w += hash->f->sourceSize.width;
			} else {
				w += hash->r.width;
			}

        	// add right padding
        	w += hash->rightPadding;
    	} else {
			if(c == ' ') {
				w += spaceWidth;
			} else if(c == '\t') {
				w += spaceWidth * tabSize;
			}
    	}

    	firstChar = false;
	}

	return w;
}

wyAtlasLabel::~wyAtlasLabel() {
	m_map->release();
	if(m_text != NULL)
		wyFree((void*)m_text);
}

wyAtlasLabel::wyAtlasLabel(const char* text, wyTexture2D* tex, wyCharMap* map) :
		m_text(NULL),
		m_lineSpacing(0),
		m_lineWidth(MAX_FLOAT) {
	// create char map
	m_map = map;
	m_map->retain();

	// set texture
	setTexture(tex);

	// create empty material and mesh
	setMaterial(wyMaterial::make());
	setMesh(wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set text
	setText(text);
}

wyAtlasLabel* wyAtlasLabel::make(const char* text, wyTexture2D* tex, wyCharMap* map) {
	wyAtlasLabel* n = WYNEW wyAtlasLabel(text, tex, map);
	return (wyAtlasLabel*)n->autoRelease();
}

void wyAtlasLabel::updateMaterial() {
	// get texture parameter, if none, create
	wyMaterialParameter* mp = getMaterial()->getParameter(wyUniform::NAME[wyUniform::TEXTURE_2D]);
	if(!mp) {
		wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D], m_tex);
		m_material->addParameter(p);
	} else {
		wyMaterialTextureParameter* mtp = (wyMaterialTextureParameter*)mp;
		mtp->setTexture(m_tex);
	}
}

void wyAtlasLabel::updateMesh() {
	float w, h;
	m_map->updateAtlas(m_text, m_lineWidth, m_lineSpacing, m_alignment, this, &w, &h);
	setContentSize(w, h);

	// setContentSize will set flag to true, so clear it because we already updated mesh
	setNeedUpdateMesh(false);
}

void wyAtlasLabel::updateMeshColor() {
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->updateColor(m_color);
}

void wyAtlasLabel::setText(const char* text) {
	size_t len = wyUtils::strlen8(text);

	if(m_text != text) {
		if(m_text != NULL)
			wyFree((void*)m_text);
		m_text = wyUtils::copy(text);
	}

	updateMesh();
}

void wyAtlasLabel::setLineWidth(float width) {
	if(m_lineWidth != width) {
		m_lineWidth = width;
		updateMesh();
	}
}

void wyAtlasLabel::setLineSpacing(float spacing) {
	m_lineSpacing = spacing;
	updateMesh();
}

void wyAtlasLabel::setAlignment(Alignment alignment) {
	m_alignment = alignment;
	updateMesh();
}
