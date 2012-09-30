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
#include "wyBitmapFont.h"
#include "wyGlobal.h"
#include "wyHGEFontLoader.h"
#include "wyAngelCodeTXTFontLoader.h"
#include "wyAngelCodeXMLFontLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"

wyHashSet* wyBitmapFont::s_loadedFonts = NULL;

static int wyBitmapFontEqlByName(void* ptr, void* elt){
	const char* name = (const char*)ptr;
    wyBitmapFont* font = (wyBitmapFont*)elt;
	if(font->getPath() != NULL)
		return !strcmp(name, font->getPath());
	else
		return false;
}

static int wyBitmapFontEqlByResID(void* ptr, void* elt){
	size_t resId = (size_t)ptr;
    wyBitmapFont* font = (wyBitmapFont*)elt;
    return (font->getPath() ? false : (resId == font->getResId()));
}

static void* wyBitmapFontTransFunc(void* ptr, void* data) {
    return data;
}

static bool wyBitmapFontUnloadFunc(void* elt, void* data) {
    wyBitmapFont* font = (wyBitmapFont*)elt;
    wyBitmapFont::unloadFont(font);
    return true;
}

static int charSetEqlFunc(void* ptr, void* elt){
    size_t wc = (size_t)ptr;
    wyCharInfo* pCi = (wyCharInfo*)elt;
    return pCi->word == wc;
}

static void* charSetTransFunc(void* ptr, void* data) {
    return data;
}

static bool charSetFreeFunc(void* elt, void* data) {
    WYDELETE((wyCharInfo*)elt);
    return true;
}

bool wyBitmapFont::sumCharHeight(void* elt, void* data) {
	wyCharInfo* ci = (wyCharInfo*)elt;
	wyBitmapFont* font = (wyBitmapFont*)data;
	font->m_emptyLineHeight += ci->texRect.height;
	return true;
}

wyBitmapFont::wyBitmapFont(int resId, wyBitmapFontFormat format) :
        m_charset(NULL),
        m_textures(wyArrayNew(3)),
        m_resId(resId),
        m_path(NULL),
        m_lineHeight(0),
        m_emptyLineHeight(0),
        m_hash(resId) {
    m_charset = wyHashSetNew(100, charSetEqlFunc, charSetTransFunc);
    float scale;
    size_t length;
    char* raw = wyUtils::loadRaw(resId, &length, &scale);
    switch(format) {
    	case BFF_HGE:
    		wyHGEFontLoader::load(this, raw, length, scale);
    		break;
    	case BFF_ANGELCODE_TXT:
    		wyAngelCodeTXTFontLoader::load(this, raw, length, scale);
    		break;
    	case BFF_ANGELCODE_XML:
    		wyAngelCodeXMLFontLoader::load(this, raw, length, scale);
    		break;
    }
    wyFree(raw);

    // get a height for empty line
    wyHashSetEach(m_charset, sumCharHeight, this);
    m_emptyLineHeight /= m_charset->entries;
}

wyBitmapFont::wyBitmapFont(const char* path, bool isFile, wyBitmapFontFormat format, float inDensity) :
        m_charset(NULL),
        m_textures(wyArrayNew(3)),
        m_resId(0),
        m_path(NULL),
        m_lineHeight(0),
        m_emptyLineHeight(0),
        m_isFile(false) {
    m_charset = wyHashSetNew(100, charSetEqlFunc, charSetTransFunc);
    m_path = wyUtils::copy(path);
    m_isFile = isFile;
    m_hash = wyUtils::strHash(path);
    size_t length;
    char* raw = wyUtils::loadRaw(path, isFile, &length);
    switch(format) {
    	case BFF_HGE:
    		wyHGEFontLoader::load(this, raw, length, wyDevice::density / inDensity);
    		break;
    	case BFF_ANGELCODE_TXT:
    		wyAngelCodeTXTFontLoader::load(this, raw, length, wyDevice::density / inDensity);
    		break;
    	case BFF_ANGELCODE_XML:
    		wyAngelCodeXMLFontLoader::load(this, raw, length, wyDevice::density / inDensity);
    		break;
    }
    wyFree(raw);

    // get a height for empty line
    wyHashSetEach(m_charset, sumCharHeight, this);
    m_emptyLineHeight /= m_charset->entries;
}        

wyBitmapFont::~wyBitmapFont() {
	wyHashSetEach(m_charset, charSetFreeFunc, NULL);
	wyHashSetDestroy(m_charset);

	wyArrayEach(m_textures, releaseTexture, NULL);
	wyArrayDestroy(m_textures);

    if(m_path) {
    	wyFree((void*)m_path);
    }
}

bool wyBitmapFont::releaseTexture(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

void wyBitmapFont::addTexture(wyTexture2D* tex) {
	if(tex) {
		wyArrayPush(m_textures, tex);
		wyObjectRetain(tex);
	}
}

void wyBitmapFont::addCharInfo(wyCharInfo* ci) {
	wyHashSetInsert(m_charset, ci->word, (void*)ci->word, ci);
}

wyCharInfo* wyBitmapFont::getCharInfo(int wc) {
    return (wyCharInfo*)wyHashSetFind(m_charset, wc, (void*)wc);
}

wyBitmapFont* wyBitmapFont::loadFont(const char* path, bool isFile, wyBitmapFontFormat format, float inDensity) {
    wyBitmapFont* ret = NULL;

    // create hashset if needed
    if(!s_loadedFonts) {
        s_loadedFonts = wyHashSetNew(64, NULL, NULL);
    }

    // see if it is already created
    ret = (wyBitmapFont*)wyHashSetCustomFind(s_loadedFonts, wyUtils::strHash(path), (void*)path, wyBitmapFontEqlByName);
    if(!ret) {
        ret = WYNEW wyBitmapFont(path, isFile, format, inDensity);
        wyHashSetCustomInsert(s_loadedFonts, ret->getHash(), (void*)path, (void*)ret, wyBitmapFontTransFunc, wyBitmapFontEqlByName);
    }
    return ret;
}

wyBitmapFont* wyBitmapFont::loadFont(int resId, wyBitmapFontFormat format) {
    wyBitmapFont* ret = NULL;

    // create hashset if needed
    if(!s_loadedFonts) {
        s_loadedFonts = wyHashSetNew(64, NULL, NULL);
    }

    // see if it is already created
    ret = (wyBitmapFont*)wyHashSetCustomFind(s_loadedFonts, resId, (void*)resId, wyBitmapFontEqlByResID);
    if(!ret) {
        ret = WYNEW wyBitmapFont(resId, format);
        wyHashSetCustomInsert(s_loadedFonts, resId, (void*)resId, (void*)ret, wyBitmapFontTransFunc, wyBitmapFontEqlByResID);
    }

    return ret;
}

void wyBitmapFont::unloadFont(wyBitmapFont* font){
    if(!font || !s_loadedFonts)
        return;

    // delete from hashset
    if(font->getPath()) {
        wyHashSetCustomRemove(s_loadedFonts, font->getHash(), (void*)font->getPath(), wyBitmapFontEqlByName);
    } else {
        wyHashSetCustomRemove(s_loadedFonts, font->getHash(), (void*)font->getResId(), wyBitmapFontEqlByResID);
    }

    // self destroy
    WYDELETE(font);
}

void wyBitmapFont::unloadAll() {
	if(s_loadedFonts != NULL) {
		wyHashSetEach(s_loadedFonts, wyBitmapFontUnloadFunc, NULL);
		wyHashSetDestroy(s_loadedFonts);
		s_loadedFonts = NULL;
	}
}

float wyBitmapFont::measureText(const char* chars, int length, float spaceWidth, float tabSize) {
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
    	wyCharInfo* pCi = getCharInfo(c);
    	if(pCi) {
        	// if first, add left
        	if(!firstChar) {
        		w += pCi->left;
        	}

        	// add width
        	w += pCi->texRect.width;

        	// add right padding
        	w += pCi->right;
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
