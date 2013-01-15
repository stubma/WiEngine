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
#include "wyAngelCodeTXTFontLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyTextureManager.h"

static void valueForKey(char* line, const char* key, char* value) {
	int keyLen = strlen(key);
	int valueLen = 0;
	char* start = (char*)strstr(line, key);
	if(start != NULL) {
		start += keyLen;

		// must be a = character
		if(*start == '=') {
			start++;

			// skip quota
			while(*start == '"')
				start++;

			// start to find end, end could be a quota or space or carriage return or new line
			char* end = start;
			while(*end) {
				if(*end == '"' || *end == ' ' || *end == '\r' || *end == '\n')
					break;
				else 
					end++;
			}

			valueLen = end - start;
			memcpy(value, start, valueLen);
		}
	}

	value[valueLen] = 0;
}

void wyAngelCodeTXTFontLoader::load(wyBitmapFont* font, const char* data, size_t length, float resScale) {
	char line[256];
	char value[32];
	char* buf = (char*)data;
	while(length > 0) {
		// read one line
		int readLen = wyUtils::readLine(&buf, line);
		length -= readLen;

		// check start token
		if(wyUtils::startsWith(line, "common")) {
			valueForKey(line, "lineHeight", value);
			float height = atof(value) * resScale;
			font->setLineHeight(height);
		} else if(wyUtils::startsWith(line, "page")) {
			valueForKey(line, "file", value);

			// cut extension
			char* dot = strrchr(value, '.');
			if(dot != NULL)
				*dot = 0;

		    // create texture
		    const char* path = font->getPath();
		    if(path) {
		        char* fullPngPath = (char*) wyMalloc((strlen(path) + strlen(value) + 4) * sizeof(char));
		        if(fullPngPath) {
		        	// cut fnt file name
		            memcpy(fullPngPath, path, (strlen(path) + 1) * sizeof(char));
		            char* lastSolidus = fullPngPath;
		            char* temp = fullPngPath;
		            while(temp != NULL) {
		                temp = strstr(temp, "/");
		                if(temp) {
		                    lastSolidus = ++temp;
		                }
		            }

		            // append png file name
		            sprintf(lastSolidus, "%s.png", value);
		            if(font->isFile()) {
		            	font->addTexture(wyTexture2D::makeFile(fullPngPath,
		            			0,
		            			wyTextureManager::getInstance()->getTexturePixelFormat(),
		            			wyDevice::density / resScale));
		            } else {
		            	font->addTexture(wyTexture2D::make(fullPngPath,
		            			0,
		            			wyTextureManager::getInstance()->getTexturePixelFormat(),
		            			wyDevice::density / resScale));
		            }
		            wyFree(fullPngPath);
		        }
		    } else {
		    	font->addTexture(wyTexture2D::make(wyUtils::getResId(value, "drawable", NULL)));
		    }
		} else if(wyUtils::startsWith(line, "char")) {
			// create char info
			wyCharInfo* ci = WYNEW wyCharInfo();

			// x
			valueForKey(line, "x", value);
			ci->texRect.x = atof(value) * resScale;

			// y
			valueForKey(line, "y", value);
			ci->texRect.y = atof(value) * resScale;

			// width
			valueForKey(line, "width", value);
			ci->texRect.width = atof(value) * resScale;

			// height
			valueForKey(line, "height", value);
			ci->texRect.height = atof(value) * resScale;

			// xoffset map to left
			valueForKey(line, "xoffset", value);
			ci->left = atof(value) * resScale;

			// yoffset map to top
			valueForKey(line, "yoffset", value);
			ci->top = atof(value) * resScale;

			// xadvance - xoffset - width ==> right
			valueForKey(line, "xadvance", value);
			ci->right = atof(value) * resScale - ci->texRect.width - ci->left;

			// page
			valueForKey(line, "page", value);
			ci->page = atoi(value);

			// id is unicode, transform it to utf-8
			valueForKey(line, "id", value);
			char32_t c = atoi(value);
			if(c != ' ') {
				c = wyUtils::utf32toutf8(c);
				ci->word = c;
			}

			// add char info
			if(ci->word == 0)
				wyFree(ci);
			else
				font->addCharInfo(ci);
		}
	}
}
