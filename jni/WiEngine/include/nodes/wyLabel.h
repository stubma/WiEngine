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
#ifndef __wyLabel_h__
#define __wyLabel_h__

#include "wyTextureNode.h"

/**
 * @class wyLabel
 *
 * wrapper of label
 */
class WIENGINE_API wyLabel : public wyTextureNode {
private:
	/// text alignment
	wyTexture2D::TextAlignment m_alignment;

	/**
	 * font size
	 */
	float m_fontSize;

	/**
	 * font style
	 */
	wyFontStyle m_fontStyle;

	/**
	 * font name
	 */
	const char*	m_fontName;

	/**
	 * path of font to be used
	 */
	const char* m_fontPath;

	/**
	 * true means \c m_fontPath is an absolute path in file system, or false
	 * means \c m_fontPath is a path relative to assets
	 */
	bool m_isFile;

	/**
	 * width of the label, if the content exceeds one single line, new lines will be added
	 */
	float m_lineWidth;

protected:
	/**
	 * update the texture
	 */
	void update();

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 */
	static wyLabel* make(int resId);

	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 */
	static wyLabel* make(int resId, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 */
	static wyLabel* make(int resId, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 */
	static wyLabel* make(const char* text);

	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width width of the Label, in pixels
	 * @param alignment text alignment, default is left
	 */
	static wyLabel* make(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width width of the label, in pixels
	 * @param alignment text alignment, default is left
	 */
	static wyLabel* make(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * constructor
	 */
	wyLabel();

	/**
	 * constructor
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width width of the label
	 * @param alignment text alignment, default is left
	 */
	wyLabel(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * constructor
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width width of the label, in pixels
	 * @param alignment text alignment, default is left
	 */
	wyLabel(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * destructor
	 */
	virtual ~wyLabel();

	/**
	 * getter
	 *
	 * @return null-terminated C string
	 */
	virtual const char* getText() { return getTexture()->getText(); }

	/**
	 * setter
	 *
	 * @param text C string
	 */
	virtual void setText(const char* text);

	/**
	 * Set label text with a string resource id
	 *
	 * @param resId the resource identifier of the string
	 */
	void setText(int resId);

	/**
	 * set the font size
	 *
	 * @param fontSize font size
	 */
	void setFontSize(float fontSize);

	/**
	 * getter
	 */
	float getFontSize() { return m_fontSize; }

	/**
	 * setter
	 *
	 * @param fontStyle font style, \link wyFontStyle wyFontStyle\endlink
	 */
	void setFontStyle(wyFontStyle fontStyle);

	/**
	 * getter
	 */
	wyFontStyle getFontStyle() { return m_fontStyle; }

	/**
	 * setter
	 *
	 * @param fontName font name
	 */
	void setFontName(const char* fontName);

	/**
	 * getter
	 */
	const char* getFontName() { return m_fontName; }

	/**
	 * Set font path, a font file can be located in file system or assets
	 *
	 * @param fontPath font path
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 */
	void setFontPath(const char* fontPath, bool isFile = false);

	/**
	 * Get font path
	 */
	const char* getFontPath() { return m_fontPath; }	

	/**
	 * Is font path an absolute path in file system?
	 *
	 * @return true means \c m_fontPath is an absolute path in file system, or false
	 * 		means \c m_fontPath is a relative path in assets
	 */
	bool isFileFontPath() { return m_isFile; }

	/**
	 * setter
	 *
	 * @param lineWidth label width
	 */
	void setLineWidth(float lineWidth);

	/**
	 * getter
	 */
	float getLineWidth() { return m_lineWidth; }

	/**
	 * Set text alignment
	 *
	 * @param align alignment of text
	 */
	void setAlignment(wyTexture2D::TextAlignment align);

	/**
	 * Get text alignment
	 *
	 * @return text alignment
	 */
	wyTexture2D::TextAlignment getAlignment() { return m_alignment; }
};

#endif // __wyLabel_h__
