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
#ifndef __wyBitmapFontLabel_h__
#define __wyBitmapFontLabel_h__

#include "wyNode.h"
#include "wyQuadList.h"
#include "WiEngine-Classes.h"

/**
 * @class wyBitmapFontLabel
 *
 * Create a label for a bitmap font. Default is single line but you can set a
 * line width and label will auto break if exceeds the width. After a label is
 * created or text is reset, its content size will be auto updated to best size.
 */
class WIENGINE_API wyBitmapFontLabel : public wyNode {
public:
	/**
	 * Text alignment
	 */
	enum Alignment {
		/**
		 * Left alignment
		 */
		LEFT,

		/**
		 * center alignment
		 */
		CENTER,

		/**
		 * right alignment
		 */
		RIGHT
	};

private:
	/// the label string in utf-8 encoding
	const char* m_text;

	/// the related \link wyBitmapFont wyBitmapFont\endlink object
	wyBitmapFont* m_font;

	/**
	 * the pixel width of a space character if there is no space bitmap in font.
	 * default is 6dp
	 */
	float m_spaceWidth;

	/**
	 * how many space character can be mapped to one tab character, default 1 tab equals
	 * 4 space
	 */
	int m_tabSize;

	/// line width of label. default is 0 which means only single line.
	float m_lineWidth;

	/**
	 * line height. default is 0 means line height is dynamically calculated so
	 * every line may have different height. If set, every line is set to same height.
	 */
	float m_lineHeight;

	/// text alignment, can be left, center or right
	Alignment m_alignment;

	/// line spacing, can be negative
	float m_lineSpacing;

private:
	/// clear all quads in every quad list mesh
	void clearAtlas();

protected:
	wyBitmapFontLabel() {}

	/**
	 * Get width of node
	 *
	 * @param lines vector contains every single line
	 * @return width of every lines, caller should release it
	 */
	vector<float>* measureWidth(vector<const char*>* lines);

public:
	/**
	 * static factory method
	 *
	 * @param[in] font releated \link wyBitmapFont wyBitmapFont\endlink object
	 * @param[in] text label text in utf-8 encoding
	 */
	static wyBitmapFontLabel* make(wyBitmapFont* font, const char* text);

	/**
	 * constructor
	 *
	 * @param[in] font releated \link wyBitmapFont wyBitmapFont\endlink object
	 * @param[in] text label text in utf-8 encoding
	 */
	wyBitmapFontLabel(wyBitmapFont* font, const char* text);

	virtual ~wyBitmapFontLabel();

	/// @see wyGeometry::updateMesh
	virtual void updateMesh();

	/// @see wyGeometry::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::setText
	virtual void setText(const char* text);

	/// @see wyNode::getText
	virtual const char* getText() { return m_text; }

	/**
	 * bind this label to other \link wyBitmapFont wyBitmapFont\endlink
	 */
	void setFont(wyBitmapFont* font) { m_font = font; }

	/**
	 * get related \link wyBitmapFont wyBitmapFont\endlink object
	 */
	wyBitmapFont* getFont() { return m_font; };

	/**
	 * set pixel width of space char
	 *
	 * @param w pixel width of space
	 */
	void setSpaceWidth(float w) { m_spaceWidth = w; }

	/**
	 * get pixel width of a space character
	 *
	 * @return pixel width of space character
	 */
	float getSpaceWidth() { return m_spaceWidth; }

	/**
	 * set space number of a tab character
	 *
	 * @param tabSize space number of a tab character
	 */
	void setTabSize(int tabSize) { m_tabSize = tabSize; }

	/**
	 * set space count of a tab character, default is 4
	 *
	 * @return space count of a tab character
	 */
	int getTabSize() { return m_tabSize; }

	/**
	 * set line width and node size will be recalculated. a value <= 0 means single line
	 *
	 * @param width line width in pixel
	 */
	void setLineWidth(float width);

	/**
	 * get line width, a value <= 0 means single line
	 *
	 * @return line width in pixel
	 */
	float getLineWidth() { return m_lineWidth; }

	/**
	 * get line height. a value > 0 means all line use the same height. a value <= 0
	 * means every line's height is calculated dynamically
	 *
	 * @return line height in pixel
	 */
	float getLineHeight() { return m_lineHeight; }

	/**
	 * set line height and node size will be recalculated. a value > 0 means all line use the
	 * same height. a value <= 0 means every line's height is calculated dynamically
	 *
	 * @param height line height in pixel
	 */
	void setLineHeight(float height);

	/**
	 * Set text alignment
	 *
	 * @param alignment alignment constant
	 * \see wyBitmapFontLabel::LEFT
	 * \see wyBitmapFontLabel::CENTER
	 * \see wyBitmapFontLabel::RIGHT
	 */
	void setAlignment(Alignment alignment);

	/**
	 * Get text alignment
	 *
	 * @return text alignment
	 * \see wyBitmapFontLabel::LEFT
	 * \see wyBitmapFontLabel::CENTER
	 * \see wyBitmapFontLabel::RIGHT
	 */
	Alignment getAlignment() { return m_alignment; }

	/**
	 * Get line spacing
	 *
	 * @return line spacing, can be negative value
	 */
	float getLineSpacing() { return m_lineSpacing; }

	/**
	 * Set line spacing
	 *
	 * @param spacing line spacing, can be negative value
	 */
	void setLineSpacing(float spacing);
};

#endif
