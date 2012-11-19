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
#ifndef __wyAtlasLabel_h__
#define __wyAtlasLabel_h__

#include "wyNode.h"
#include "wyHashSet.h"
#include "wyCharProvider.h"
#include "WiEngine-Classes.h"

class wyCharMap;

/**
 * Atlas label. Characters in it are texture area in an atlas texture. The mapping
 * between character code and texture rect is managed internally. When rendering
 * a label, character is mapped to texture one by one.
 */
class WIENGINE_API wyAtlasLabel : public wyNode {
public:
	/// Text alignment
	enum Alignment {
		/// Left alignment
		LEFT,

		/// center alignment
		CENTER,

		/// right alignment
		RIGHT
	};

protected:
	/// the label's content
    const char* m_text;

    /// \link wyCharMap wyCharMap\endlink
    wyCharMap* m_map;

	/**
	 * line width of this label.
	 * If content of the label can't be accommodated by a single line,
	 * multiple lines will be applied. If this value is not specified,
	 * one single line is applied.
	 */
	float m_lineWidth;

	/// line spacing, can be negative
	float m_lineSpacing;

	/// text alignment, can be left, center or right
	Alignment m_alignment;

protected:
    /**
     * constructor
     *
     * @param text null terminated c string, the string is utf-8 coded
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param map \link wyCharMap wyCharMap\endlink
   	 */
    wyAtlasLabel(const char* text, wyTexture2D* tex, wyCharMap* map);

public:
    /**
     * factory function, used to create a new instance with autoRelease enabled
     *
     * @param text null terminated c string, the string is utf-8 coded
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param map \link wyCharMap wyCharMap\endlink
   	 */
    static wyAtlasLabel* make(const char* text, wyTexture2D* tex, wyCharMap* map);

    /// destructor
    virtual ~wyAtlasLabel();

	/// @see wyGeometry::updateMesh
	virtual void updateMesh();

	/// @see wyGeometry::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::getText
	virtual const char* getText() { return m_text; }

	/// @see wyNode::setText
	virtual void setText(const char* text);

	/**
	 * setter, to set the line width. The size of the node will be recalculated.
	 *
	 * @param width in pixels, if this value is bigger than the needed width, the needed width will be used
	 */
	void setLineWidth(float width);

	/**
	 * getter, to get the line width
	 */
	float getLineWidth() { return m_lineWidth; }

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

/**
 * To manage the mapping between a character and its rectangle size, needed
 * by \link wyAtlasLabel wyAtlasLabel\endlink
 */
class WIENGINE_API wyCharMap : public wyObject, public wyCharProvider {
	friend class wyAtlasLabel;

private:
	/// hash map of character utf-8 code to character
	wyHashSet* m_charMap;

	/**
	 * the width of blank space character, if not specified by the font, this value will be used.
	 * The default value is 6dp.
	 */
	float m_spaceWidth;

	/// the space count of character tab, 4 is used by default
	int m_tabSize;

	/// total height of all characters
	float m_totalCharHeight;

private:
	static int charHashEquals(void* ptr, void* elt);
	static void* buildCharHash(void* ptr, void* data);
    static bool releaseHash(void* elt, void* data);

protected:
    /**
     * to update the character info
     *
     * @param text null terminated c string, the string is utf-8 coded.
     * @param lineWidth line width
     * @param lineSpacing spacing between lines
     * @param alignment text alignment
     * @param atlas \link wyAtlasLabel wyAtlasLabel\endlink
     * @param w to return the updated width, can be NULL
     * @param h to return the updated height, can be NULL
     */
    void updateAtlas(const char* text, float lineWidth, float lineSpacing, wyAtlasLabel::Alignment alignment, wyAtlasLabel* atlas, float* w, float* h);

	/**
	 * Measure width of every lines
	 *
	 * @param lines vector contains every single line
	 * @param spaceWidth space width in pixels
	 * @param tabSize how many space one tab equals to
	 * @return vector contains width of every single line
	 */
	vector<float>* measureWidth(vector<const char*>* lines);
	
public:
    static wyCharMap* make();

    wyCharMap();
    virtual ~wyCharMap();

    /// @see wyCharProvider::measureText
    virtual float measureText(const char* chars, int length, float spaceWidth, float tabSize);

    /**
     * to map a character to a rectangle
     *
     * @param rect the character's rectangle in the atlas picture
     * @param c the character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     */
    void mapChar(wyRect rect, int c, float leftPadding = 0, float rightPadding = 0);

    /**
     * to map a character to a  zwoptex frame
     *
     * @param frameName the frame name defined in the zwoptex description file
     * @param c character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     */
    void mapChar(const char* frameName, int c, float leftPadding = 0, float rightPadding = 0);

    /**
     * to map a character to a zwoptex frame
     *
     * @param zwoptexName the zwoptex name
     * @param frameName the frame name defined in the zwoptex description file
     * @param c character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     */
    void mapChar(const char* zwoptexName, const char* frameName, int c, float leftPadding = 0, float rightPadding = 0);

	/**
	 * to set the width of blank space, in pixels
	 *
	 * @param w the width, in pixels
	 */
	void setSpaceWidth(float w) { m_spaceWidth = w; }

	/**
	 * to get the width of blank space
	 */
	float getSpaceWidth() { return m_spaceWidth; }

	/**
	 * to set the space count of tab
	 *
	 * @param tabSize space count
	 */
	void setTabSize(int tabSize) { m_tabSize = tabSize; }

	/**
	 * to get the space count of tab
	 */
	int getTabSize() { return m_tabSize; }

	/**
	 * Return a height for empty line, actually it is the average height of characters
	 *
	 * @return height for empty line
	 */
	float getEmptyLineHeight() { return m_totalCharHeight / m_charMap->entries; }
};

#endif // __wyAtlasLabel_h__
