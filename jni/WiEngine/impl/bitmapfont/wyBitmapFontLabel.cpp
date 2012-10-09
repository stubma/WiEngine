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
#include "wyBitmapFontLabel.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyMaterial.h"
#include "wyMaterialTextureParameter.h"
#include "wyBitmapFont.h"

wyBitmapFontLabel::wyBitmapFontLabel(wyBitmapFont* font, const char* text) :
        m_font(font),
        m_text(NULL),
        m_spaceWidth(DP(6)),
        m_tabSize(4),
        m_alignment(LEFT),
        m_lineSpacing(0),
        m_lineHeight(font->getLineHeight()),
        m_lineWidth(MAX_FLOAT) {
	// create material and mesh list
	m_materialList = WYNEW vector<wyMaterial*>();
	m_meshList = WYNEW vector<wyQuadList*>();

	// create atlas for every page
    for(int i = 0; i < m_font->m_textures->num; i++) {
    	// create material for this texture and add it
		wyMaterial* m = wyMaterial::make();
		m->retain();
		wyMaterialTextureParameter* p = wyMaterialTextureParameter::make(wyUniform::NAME[wyUniform::TEXTURE_2D],
				m_font->getTexture(i));
		m->addParameter(p);
		m_materialList->push_back(m);

		// create mesh for material and add
		wyQuadList* quadList = wyQuadList::make();
		quadList->retain();
		m_meshList->push_back(quadList);
    }

    // set text and it will trigger updateContentSize
    setText(text);

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);
}

wyBitmapFontLabel::~wyBitmapFontLabel() {
	// release text
    if(m_text) {
    	wyFree((void*)m_text);
    }

    // release materials
    for(vector<wyMaterial*>::iterator iter = m_materialList->begin(); iter != m_materialList->end(); iter++) {
    	wyObjectRelease(*iter);
    }
    WYDELETE(m_materialList);

    // release meshes
    for(vector<wyQuadList*>::iterator iter = m_meshList->begin(); iter != m_meshList->end(); iter++) {
    	wyObjectRelease(*iter);
    }
    WYDELETE(m_meshList);
}

void wyBitmapFontLabel::clearAtlas() {
    for(vector<wyQuadList*>::iterator iter = m_meshList->begin(); iter != m_meshList->end(); iter++) {
    	(*iter)->removeAllQuads();
    }
}

void wyBitmapFontLabel::setText(const char* text) {
	// null checking
	if(text == NULL)
		return;

	// release old
    if(m_text) {
    	wyFree((void*)m_text);
    	m_text = NULL;
    }

    // save text
    m_text = wyUtils::copy(text);

    // measure
    setLineWidth(m_lineWidth);

    // actually the color should also be updated because
    // text content is changed so quad number may also changed
    updateMeshColor();
}

vector<float>* wyBitmapFontLabel::measureWidth(vector<const char*>* lines) {
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

	        wyCharInfo* pCi = m_font->getCharInfo(c);
	        if(pCi) {
				// if not first char of line, add left padding
				if(!firstLineChar) {
					x += pCi->left;
				}

				// adjust x and y
				x += pCi->texRect.width + pCi->right;
	        } else {
	        	// special check for space or tab
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

void wyBitmapFontLabel::setLineHeight(float height) {
	m_lineHeight = height;
	updateMesh();
}

void wyBitmapFontLabel::setLineWidth(float width) {
	m_lineWidth = width;
	updateMesh();
}

void wyBitmapFontLabel::setLineSpacing(float spacing) {
	m_lineSpacing = spacing;
	updateMesh();
}

void wyBitmapFontLabel::setAlignment(Alignment alignment) {
	m_alignment = alignment;
	updateMesh();
}

wyBitmapFontLabel* wyBitmapFontLabel::make(wyBitmapFont* font, const char* text) {
    wyBitmapFontLabel* label = WYNEW wyBitmapFontLabel(font, text);
    label->autoRelease();
    return label;
}

void wyBitmapFontLabel::updateMaterial() {
	// nothing for bitmapfont label because bitmap font label doesn't support change texture
}

void wyBitmapFontLabel::updateMesh() {
	// remove all quads in all atlas
	clearAtlas();

	// if null, do nothing
	if(!m_text)
		return;

	// break line into a vector
	vector<const char*>* lines = wyUtils::breakLines(m_text, m_font, m_lineWidth, m_spaceWidth, m_tabSize);

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

	// render line one by one
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++, line++) {
		char* p = (char*)(*iter);
		float x = 0;
		float lineOffset = 0;
		float charWidth, charHeight;
		bool firstLineChar = true;
		float currentLineHeight = 0;

		// line offset
		switch(m_alignment) {
			case LEFT:
				lineOffset = 0;
				break;
			case CENTER:
				lineOffset = (maxWidth - widthList->at(line)) / 2;
				break;
			case RIGHT:
				lineOffset = maxWidth - widthList->at(line);
				break;
		}

		// if first char of this line, add line spacing
		if(line > 0) {
			y += m_lineSpacing;
			if(prevLineHeight == 0)
				y += m_font->getEmptyLineHeight();
			else
				y += prevLineHeight;
		}

	    while(*p != 0) {
	    	// get char integer
	    	int c = 0;
	    	int b = wyUtils::getUTF8Bytes(*p);
	    	while(b-- > 0) {
	    		c <<= 8;
	    		c |= *p & 0xff;
	    		p++;
	    	}

	        wyCharInfo* pCi = m_font->getCharInfo(c);
	        if(pCi) {
	        	// get char size
	        	charWidth = pCi->texRect.width;
	        	charHeight = pCi->texRect.height;

				// if not first char of line, add left padding
				if(!firstLineChar) {
					x += pCi->left;
				}

				// choose max height as line height
				currentLineHeight = m_lineHeight > 0 ? m_lineHeight : MAX(currentLineHeight, charHeight + pCi->top);

	            // get atlas
				wyQuadList* atlas = m_meshList->at(pCi->page);

	            // get vertex corner
	            float left = x + lineOffset;
	            float right = left + charWidth;
	            float top = -y - pCi->top;
	            float bottom = top - charHeight;

	            // build vertex
	            wyQuad3D v;
	    		v.bl_x = left;
	    		v.bl_y = bottom;
	    		v.bl_z = 0.0f;
	    		v.br_x = right;
	    		v.br_y = bottom;
	    		v.br_z = 0.0f;
	    		v.tl_x = left;
	    		v.tl_y = top;
	    		v.tl_z = 0.0f;
	    		v.tr_x = right;
	    		v.tr_y = top;
	    		v.tr_z = 0.0f;

	    		// build texture coordinates
	    		wyQuad2D t;
	    		wyTexture2D* tex = m_font->getTexture(pCi->page);
	    	    left = pCi->texRect.x / tex->getPixelWidth();
	    	    right = (pCi->texRect.x + charWidth) / tex->getPixelWidth();
	    	    top = pCi->texRect.y / tex->getPixelHeight();
	    	    bottom = (pCi->texRect.y + charHeight) / tex->getPixelHeight();
	    	    t.bl_x = left;
	    	    t.bl_y = bottom;
	    	    t.br_x = right;
	    	    t.br_y = bottom;
	    	    t.tl_x = left;
	    	    t.tl_y = top;
	    	    t.tr_x = right;
	    	    t.tr_y = top;

	    	    // add quad
	    	    atlas->appendQuad(t, v);

				// adjust x and y
				x += charWidth + pCi->right;
	        } else {
	        	// special check for space or tab
	        	if(c == ' ') {
	        		x += m_spaceWidth;
				} else if(c == '\t') {
	        		x += m_spaceWidth * m_tabSize;
				}
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

	// set label content size
	setContentSize(width, y);

	// adjust quad
	for(vector<wyQuadList*>::iterator iter = m_meshList->begin(); iter != m_meshList->end(); iter++) {
		(*iter)->translate(0, m_height, 0);
	}
	
	// release
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		wyFree((void*)*iter);
	}
	WYDELETE(lines);
	WYDELETE(widthList);
}

void wyBitmapFontLabel::updateMeshColor() {
	for(vector<wyQuadList*>::iterator iter = m_meshList->begin(); iter != m_meshList->end(); iter++) {
		(*iter)->updateColor(m_color);
	}
}
