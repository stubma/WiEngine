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
#include "wyAngelCodeXMLFontLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include <libxml/parser.h>

typedef struct wyParseState {
	wyBitmapFont* font;

	// state
	int state;

	// res scale, only used for plist resource
	float resScale;
} wyParseState;

typedef enum {
	TAG_UNKNOWN,
	TAG_FONT,
	TAG_INFO,
	TAG_COMMON,
	TAG_PAGES,
	TAG_PAGE,
	TAG_CHARS,
	TAG_CHAR
} wySparrowTag;

typedef enum {
	ATTR_UNKNOWN,
	ATTR_LINEHEIGHT,
	ATTR_FILE,
	ATTR_WIDTH,
	ATTR_HEIGHT,
	ATTR_PAGE,
	ATTR_XOFFSET,
	ATTR_YOFFSET,
	ATTR_XADVANCE,
	ATTR_ID,
	ATTR_X,
	ATTR_Y
} wySparrowAttr;

static wySparrowTag getTag(const char* name) {
	if(!strcmp(name, "font"))
		return TAG_FONT;
	else if(!strcmp(name, "info"))
		return TAG_INFO;
	else if(!strcmp(name, "common"))
		return TAG_COMMON;
	else if(!strcmp(name, "pages"))
		return TAG_PAGES;
	else if(!strcmp(name, "page"))
		return TAG_PAGE;
	else if(!strcmp(name, "chars"))
		return TAG_CHARS;
	else if(!strcmp(name, "char"))
		return TAG_CHAR;
	else
		return TAG_UNKNOWN;
}

static wySparrowAttr getAttr(const char* name) {
	if(!strcmp(name, "lineHeight"))
		return ATTR_LINEHEIGHT;
	else if(!strcmp(name, "file"))
		return ATTR_FILE;
	else if(!strcmp(name, "width"))
		return ATTR_WIDTH;
	else if(!strcmp(name, "height"))
		return ATTR_HEIGHT;
	else if(!strcmp(name, "page"))
		return ATTR_PAGE;
	else if(!strcmp(name, "xoffset"))
		return ATTR_XOFFSET;
	else if(!strcmp(name, "yoffset"))
		return ATTR_YOFFSET;
	else if(!strcmp(name, "xadvance"))
		return ATTR_XADVANCE;
	else if(!strcmp(name, "id"))
		return ATTR_ID;
	else if(!strcmp(name, "x"))
		return ATTR_X;
	else if(!strcmp(name, "y"))
		return ATTR_Y;
	else
		return ATTR_UNKNOWN;
}

void wyAngelCodeXMLFontLoader::startElement(void* ctx, const xmlChar *name, const xmlChar **atts) {
	// get user data
	wyParseState* state = (wyParseState*)ctx;

	// get tag
	wySparrowTag tag = getTag((const char*)name);

	switch(tag) {
		case TAG_COMMON:
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wySparrowAttr attr = getAttr(key);

				switch(attr) {
					case ATTR_LINEHEIGHT:
						state->font->setLineHeight(atof(value) * state->resScale);
						break;
				}
			}
			break;
		case TAG_PAGE:
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wySparrowAttr attr = getAttr(key);

				switch(attr) {
					case ATTR_FILE:
					{
						// cut extension, but remember restore the old char
						char old = 0;
						char* dot = (char*)strrchr(value, '.');
						if(dot != NULL) {
							old = *dot;
							*dot = 0;
						}

					    // create texture
					    const char* path = state->font->getPath();
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
					            if(state->font->isFile())
					            	state->font->addTexture(wyTexture2D::makeFile(fullPngPath));
					            else
					            	state->font->addTexture(wyTexture2D::make(fullPngPath));
					            wyFree(fullPngPath);
					        }
					    } else {
					    	state->font->addTexture(wyTexture2D::make(wyUtils::getResId(value, "drawable", NULL)));
					    }

					    // restore old char
					    *dot = old;

						break;
					}
				}
			}
			break;
		case TAG_CHAR:
		{
			wyCharInfo* ci = WYNEW wyCharInfo();
			for(int i = 0; atts[i] != NULL; i += 2) {
				// get attr and value
				const char* key = (const char*)atts[i];
				const char* value = (const char*)atts[i + 1];
				wySparrowAttr attr = getAttr(key);

				switch(attr) {
					case ATTR_X:
						ci->texRect.x = atof(value) * state->resScale;
						break;
					case ATTR_Y:
						ci->texRect.y = atof(value) * state->resScale;
						break;
					case ATTR_WIDTH:
						ci->texRect.width = atof(value) * state->resScale;
						break;
					case ATTR_HEIGHT:
						ci->texRect.height = atof(value) * state->resScale;
						break;
					case ATTR_XOFFSET:
						ci->left = atof(value) * state->resScale;
						break;
					case ATTR_YOFFSET:
						ci->top = atof(value) * state->resScale;
						break;
					case ATTR_XADVANCE:
						ci->right = atof(value) * state->resScale - ci->texRect.width - ci->left;
						break;
					case ATTR_PAGE:
						ci->page = atoi(value);
						break;
					case ATTR_ID:
					{
						char32_t c = atoi(value);
						if(c != ' ') {
							c = wyUtils::utf32toutf8(c);
							ci->word = c;
						}
						break;
					}
				}
			}

			// add char info
			if(ci->word == 0)
				wyFree(ci);
			else
				state->font->addCharInfo(ci);

			break;
		}
	}
}

void wyAngelCodeXMLFontLoader::warning(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGW("%s", msg);
    va_end(args);
}

void wyAngelCodeXMLFontLoader::error(void* ctx, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    LOGE("%s", msg);
    va_end(args);
}

void wyAngelCodeXMLFontLoader::load(wyBitmapFont* font, const char* data, size_t length, float resScale) {
	// declare handler
	xmlSAXHandlerV1 saxHandler = {
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		startElement,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		warning,
		error,
		NULL,
		NULL,
		NULL,
		NULL,
		0
	};

	// create map object
	wyParseState* state = (wyParseState*)wyCalloc(1, sizeof(wyParseState));
	state->font = font;
	state->resScale = resScale;

	// start to parser xml file
	xmlSAXUserParseMemory((xmlSAXHandlerPtr)&saxHandler, state, data, length);

	// clean parser
	xmlCleanupParser();

	// release
	wyFree(state);
}
