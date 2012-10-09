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
#include "wyLabel.h"
#include <stdlib.h>
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyTextureManager.h"
#include "wyTexture2D.h"

wyLabel* wyLabel::make(int resId) {
	const char* text = wyUtils::getString(resId);
	wyLabel* label = (wyLabel*)(WYNEW wyLabel(text, SP(32)))->autoRelease();
	wyFree((void*)text);
	return label;
}

wyLabel* wyLabel::make(int resId, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	const char* text = wyUtils::getString(resId);
	wyLabel* label = (wyLabel*)(WYNEW wyLabel(text, fontSize, fontPath, isFile, width, alignment))->autoRelease();
	wyFree((void*)text);
	return label;
}

wyLabel* wyLabel::make(int resId, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	const char* text = wyUtils::getString(resId);
	wyLabel* label = (wyLabel*)(WYNEW wyLabel(text, fontSize, style, fontName, width, alignment))->autoRelease();
	wyFree((void*)text);
	return label;
}

wyLabel* wyLabel::make(const char* text) {
	return (wyLabel*)(WYNEW wyLabel(text, SP(32)))->autoRelease();
}

wyLabel* wyLabel::make(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) {
	return (wyLabel*)(WYNEW wyLabel(text, fontSize, fontPath, isFile, width, alignment))->autoRelease();
}

wyLabel* wyLabel::make(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) {
	return (wyLabel*)(WYNEW wyLabel(text, fontSize, style, fontName, width, alignment))->autoRelease();
}

wyLabel::wyLabel() : 
		wyTextureNode(NULL),
		m_alignment(wyTexture2D::LEFT),
		m_fontName(NULL),
		m_fontPath(NULL),
		m_isFile(false),
		m_fontStyle(NORMAL),
		m_fontSize(SP(32.0f)),
		m_lineWidth(0) {
}

wyLabel::wyLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment) :
		wyTextureNode(NULL),
		m_alignment(alignment),
		m_fontPath(NULL),
		m_isFile(false),
		m_fontSize(fontSize),
		m_fontStyle(style),
		m_lineWidth(width),
		m_fontName(wyUtils::copy(fontName)) {
	wyTexture2D* tex = wyTexture2D::makeLabel(text, fontSize, style, fontName, width, alignment);
	setTexture(tex);
}

wyLabel::wyLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment) :
		wyTextureNode(NULL),
		m_alignment(alignment),
		m_fontStyle(NORMAL),
		m_fontName(NULL),
		m_fontPath(wyUtils::copy(fontPath)),
		m_isFile(isFile),
		m_fontSize(fontSize),
		m_lineWidth(width) {
	wyTexture2D* tex = wyTexture2D::makeLabel(text, fontSize, fontPath, isFile, width, alignment);
	setTexture(tex);
}

wyLabel::~wyLabel() {
	if(m_fontName)
		wyFree((void*)m_fontName);

	if(m_fontPath)
		wyFree((void*)m_fontPath);
}

void wyLabel::setString(const char* text) {
	if(m_tex == NULL) {
		if(m_fontPath) {
			wyTexture2D* tex = wyTexture2D::makeLabel(text == NULL ? "" : text, m_fontSize, m_fontPath, m_isFile, m_lineWidth, m_alignment);
			setTexture(tex);
		} else {
			wyTexture2D* tex = wyTexture2D::makeLabel(text == NULL ? "" : text, m_fontSize, m_fontStyle, m_fontName, m_lineWidth, m_alignment);
			setTexture(tex);
		}
	} else {
		// set texture again so that the content size will be updated
		if(m_fontPath) {
			m_tex->updateLabel(text == NULL ? "" : text, m_fontSize, m_fontPath, m_isFile, m_lineWidth, m_alignment);
		} else {
			m_tex->updateLabel(text == NULL ? "" : text, m_fontSize, m_fontStyle, m_fontName, m_lineWidth, m_alignment);
		}
		setTexture(m_tex);
	}
}

void wyLabel::setAlignment(wyTexture2D::TextAlignment align) {
	m_alignment = align;
	update();
}

void wyLabel::setString(int resId) {
	const char* text = wyUtils::getString(resId);
	setString(text);
	wyFree((void*)text);
}

void wyLabel::setFontSize(float fontSize) { 
	m_fontSize = fontSize;
	update();
}

void wyLabel::setFontStyle(wyFontStyle fontStyle) { 
	m_fontStyle = fontStyle;
	update();
}

void wyLabel::setFontName(const char* fontName) {
	const char* oldOne = m_fontName;
	m_fontName = wyUtils::copy(fontName);
	update();

	if(oldOne)
		wyFree((void*)oldOne);
}

void wyLabel::setFontPath(const char* fontPath, bool isFile) {
	// release old
	if(m_fontPath) {
		wyFree((void*)m_fontPath);
		m_fontPath = NULL;
	}

	// set new one and update
	m_fontPath = wyUtils::copy(fontPath);
	m_isFile = isFile;
	update();
}

void wyLabel::setLineWidth(float lineWidth) {
	m_lineWidth = lineWidth; 
	update();
}

void wyLabel::update() {
	if(m_fontPath) {
		m_tex->updateLabel(getText(), m_fontSize, m_fontPath, m_isFile, m_lineWidth, m_alignment);
	} else {
		m_tex->updateLabel(getText(), m_fontSize, m_fontStyle, m_fontName, m_lineWidth, m_alignment);
	}

	setTexture(m_tex);
}
