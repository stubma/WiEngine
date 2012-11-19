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
#ifndef __wyBitmapFont_h__
#define __wyBitmapFont_h__

#include "wyTypes.h"
#include "wyArray.h"
#include "wyHashSet.h"
#include "wyTexture2D.h"
#include "wyCharProvider.h"
#include <stdio.h>

class wyBitmapFontLabel;

/**
 * @typedef wyBitmapFontFormat
 *
 * format of bitmap font description file
 */
typedef enum {
	/**
	 * HGE bitmap font file format, exported by HGE bitmap font editor
	 */
	BFF_HGE,

	/**
	 * angle code format in plain text, can be exported by Glyph Designer, Bitmap Font Generator
	 */
	BFF_ANGELCODE_TXT,

	/**
	 * angle code format in xml, can be exported by Glyph Designer, Bitmap Font Generator
	 */
	BFF_ANGELCODE_XML
} wyBitmapFontFormat;

/**
 * @struct wyCharInfo
 *
 * struct to save info of one character
 */
typedef struct wyCharInfo {
	wyCharInfo() :
			word(0),
			left(0),
			right(0),
			top(0),
			page(0),
			texRect(wyrZero) {
	}

	/**
	 * the integer format of character in utf-8 encoding, big endian
	 */
	int word;

	/**
	 * left padding of this character
	 */
	int left;

	/**
	 * right padding of this character
	 */
	int right;

	/**
	 * top paddig of this character
	 */
	int top;

	/**
	 * page index of character, angle code format can have multiple character atlas and every atlas is a page
	 */
	int page;

	/**
	 * character texture rectangle in page atlas
	 */
	wyRect texRect;
} wyCharInfo;

/**
 * @class wyBitmapFont
 *
 * it loads bitmap font description file and then you can create bitmap font label based on it
 */
class WIENGINE_API wyBitmapFont : public wyCharProvider {
	friend class wyBitmapFontLabel;

private:
	/**
	 * hash set for character info, key is character code and the code is a integer of character utf-8 encoding value in big endian
	 */
	wyHashSet* m_charset;

	/**
	 * page array of bitmap font, it is an array because angle code support multiple character atlas
	 */
	wyArray* m_textures;

	/**
	 * resource id of bitmap font description file, only used when bitmap font description
	 * file is saved in res folder
	 */
	int m_resId;

	/**
	 * hash of this bitmap font, internal used to avoid to load it again
	 */
	int m_hash;

	/**
	 * file path of bitmap font description file, only used when it is saved
	 * in assets folder or file system
	 */
	const char* m_path;

	/**
	 * true means \c m_path is a relative path in assets folder, false means
	 * \c m_path is an absolute path in file system
	 */
	bool m_isFile;

	/**
	 * line height, default is zero. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 */
	float m_lineHeight;

	/**
	 * A calculated height for empty line, actually it is the average of char height
	 */
	float m_emptyLineHeight;

	/**
	 * hash set for loaded bitmap font
	 */
	static wyHashSet* s_loadedFonts;

private:
	static bool releaseTexture(wyArray* arr, void* ptr, int index, void* data);
	static bool sumCharHeight(void* elt, void* data);

protected:
	wyBitmapFont() {}
	~wyBitmapFont();

	/**
	 * constructor
	 *
	 * @param resId resource id of bitmap font description file
	 * @param format format of description file, default is BFF_HGE
	 */
	wyBitmapFont(int resId, wyBitmapFontFormat format = BFF_HGE);

	/**
	 * constructor
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder
	 * @param format format of description file
	 * @param inDensity density of font
	 */
	wyBitmapFont(const char* path, bool isFile, wyBitmapFontFormat format, float inDensity);

public:
	/**
	 * load a bitmap font description file from resource id. returns existed one if it is already loaded
	 *
	 * @param resId resource id of bitmap font description file
	 * @param format format of description file, default is BFF_HGE
	 */
	static wyBitmapFont* loadFont(int resId, wyBitmapFontFormat format = BFF_HGE);

	/**
	 * load a bitmap font description file from assets folder or file system. returns existed one if it is already loaded
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder. default is false
	 * @param format format of description file, default is BFF_HGE
	 * @param inDensity density of font, default is 1 and it means by default the font is thought as designed for mdpi
	 */
	static wyBitmapFont* loadFont(const char* path, bool isFile = false, wyBitmapFontFormat format = BFF_HGE, float inDensity = 1.0f);

	/**
	 * unload a font
	 */
	static void unloadFont(wyBitmapFont* font);

	/**
	 * unload all fonts
	 */
	static void unloadAll();

	/// @see wyCharProvider::measureText
	virtual float measureText(const char* chars, int length, float spaceWidth, float tabSize);

	/**
	 * add related character atlas, must add it based on page index, i.e., the page whose index is 0 must be added first
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 */
	void addTexture(wyTexture2D* tex);

	/**
	 * get character atlas of specified index
	 *
	 * @param index page index start from zero
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	wyTexture2D* getTexture(int index) { return (wyTexture2D*)wyArrayGet(m_textures, index); }

	/**
	 * get \link wyCharInfo wyCharInfo\endlink of a character
	 *
	 * @param[in] wc integer format of character utf-8 encoding in big endian
	 */
	wyCharInfo* getCharInfo(int wc);

	/**
	 * get resource id of bitmap font description file, or zero if it is not loaded from resource id
	 *
	 * @return resource id of bitmap font description file, or zero if it is not loaded from resource id
	 */
	int getResId() { return m_resId; }

	/**
	 * get hash of this font
	 *
	 * @return hash of this font
	 */
	int getHash() { return m_hash; }

	/**
	 * true if bitmap font description file is from file system, false if it is from assets folder
	 *
	 * @return true if bitmap font description file is from file system, false if it is from assets folder
	 */
	bool isFile() { return m_isFile; }

	/**
	 * get path of bitmap font description file, or NULL if it is not loaded from assets or file system
	 *
	 * @return path of bitmap font description file, or NULL if it is not loaded from assets or file system
	 */
	const char* getPath() { return m_path; }

	/**
	 * add a character info
	 *
	 * @param ci \link wyCharInfo wyCharInfo\endlink
	 */
	void addCharInfo(wyCharInfo* ci);

	/**
	 * get line height, default is zero. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 *
	 * @return line height in pixel
	 */
	float getLineHeight() { return m_lineHeight; }

	/**
	 * set line height. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 *
	 * @param height line height in pixel
	 */
	void setLineHeight(float height) { m_lineHeight = height; }

	/**
	 * Return a height for empty line, actually it is the average height of characters
	 *
	 * @return height for empty line
	 */
	float getEmptyLineHeight() { return m_emptyLineHeight; }
};

#endif
