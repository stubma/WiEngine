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
#include "wyHGEFontLoader.h"
#include "wyTypes.h"
#include "wyUtils.h"

static void mywcstombs(char* str, char16_t* wstr) {
    const char* chTemp = NULL;
    while(*wstr != 0) {
        chTemp = (const char*)(wstr++);
        *(str++) = ((*chTemp == '\0') ? *(chTemp + 1) : *chTemp);
    }
    *str = '\0';
}

void wyHGEFontLoader::load(wyBitmapFont* font, const char* data, size_t length, float resScale) {
    if(!data || length == 0)
        return;

    bool bUnicodeFormat = false;
    char fileName[64] = {0};
    const char* curPos = data;
    const char16_t* curPosW = (const char16_t*)(data + 2);

    // see if it is of our new unicode format
    if(data[0] == (char)0xFF && data[1] == (char)0xFE) {
        bUnicodeFormat = true;
    }

    // get png file name and create the texture
    if(!bUnicodeFormat) {
        curPos = strstr(curPos, "Bitmap=");
        curPos += strlen("Bitmap=");
        sscanf(curPos, "%s.png", fileName);
    } else {
        curPosW = wyUtils::str16str(curPosW, "Bitmap=");

        curPosW += strlen("Bitmap=");
        char16_t fileNameW[64] = {0};

        // get position of ".png"
        const char16_t* dotPngPointer = wyUtils::str16str(curPosW, ".png");
        memcpy(fileNameW, curPosW, (size_t)dotPngPointer - (size_t)curPosW);
        mywcstombs(fileName, fileNameW);
        curPosW = dotPngPointer + strlen(".png");
    }

    // create texture
    const char* path = font->getPath();
    if(path) {
        char* fullPngPath = (char*) wyMalloc((strlen(path) + strlen(fileName) + 4) * sizeof(char));
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
            sprintf(lastSolidus, "%s.png", fileName);
            if(font->isFile())
            	font->addTexture(wyTexture2D::makeFilePNG(fullPngPath));
            else
            	font->addTexture(wyTexture2D::makePNG(fullPngPath));
            wyFree(fullPngPath);
        }
    } else {
    	font->addTexture(wyTexture2D::makePNG(wyUtils::getResId(fileName, "drawable", NULL)));
    }

    // get all words one by one
    if(!bUnicodeFormat) {
        char c = '\0';
        while(1) {
            curPos = strstr(curPos, "Char=");
            if(!curPos || curPos >= data + length)
                break;
            curPos += strlen("Char=");

            // now we find one available
            wyCharInfo* pCi = WYNEW wyCharInfo;
            sscanf(curPos, "\"%c\",%f,%f,%f,%f,%d,%d", &c,
                    &pCi->texRect.x, &pCi->texRect.y, &pCi->texRect.width, &pCi->texRect.height,
                    &pCi->left, &pCi->right);
            pCi->word = c & 0xff;

            // scale it
            pCi->texRect.x *= resScale;
            pCi->texRect.y *= resScale;
            pCi->texRect.width *= resScale;
            pCi->texRect.height *= resScale;
            pCi->left *= resScale;
            pCi->right *= resScale;

            font->addCharInfo(pCi);
        }
    } else {
        while(1) {
            curPosW = wyUtils::str16str(curPosW, "Char=\"");
            if(!curPosW || (const char*)curPosW >= data + length)
                break;
            curPosW += strlen("Char=\"");

            // now we find one available, the format is like "%c\",%f,%f,%f,%f,%d,%d"
            // wcscanf is not used here due to it is not supported by android
            const char16_t* commaPointer = 0;
            char16_t tempW[8] = {0};
            char tempA[8] = {0};
            wyCharInfo* pCi = WYNEW wyCharInfo();

            pCi->word = wyUtils::utf32toutf8((char32_t)*curPosW);

            curPosW += strlen("X\",");
            commaPointer = wyUtils::str16str(curPosW, ",");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            mywcstombs(tempA, tempW);
            tempW[commaPointer - curPosW] = 0;
            pCi->texRect.x = atof(tempA) * resScale;

            curPosW = commaPointer + strlen(",");
            commaPointer = wyUtils::str16str(curPosW, ",");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            tempW[commaPointer - curPosW] = 0;
            mywcstombs(tempA, tempW);
            pCi->texRect.y = atof(tempA) * resScale;

            curPosW = commaPointer + strlen(",");
            commaPointer = wyUtils::str16str(curPosW, ",");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            tempW[commaPointer - curPosW] = 0;
            mywcstombs(tempA, tempW);
            pCi->texRect.width = atof(tempA) * resScale;

            curPosW = commaPointer + strlen(",");
            commaPointer = wyUtils::str16str(curPosW, ",");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            tempW[commaPointer - curPosW] = 0;
            mywcstombs(tempA, tempW);
            pCi->texRect.height = atof(tempA) * resScale;

            curPosW = commaPointer + strlen(",");
            commaPointer = wyUtils::str16str(curPosW, ",");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            tempW[commaPointer - curPosW] = 0;
            mywcstombs(tempA, tempW);
            pCi->left = atoi(tempA) * resScale;

            curPosW = commaPointer + strlen(",");
            commaPointer = wyUtils::str16str(curPosW, "\r");
            memcpy(tempW, curPosW, (size_t)commaPointer - (size_t)curPosW);
            tempW[commaPointer - curPosW] = 0;
            mywcstombs(tempA, tempW);
            pCi->right = atoi(tempA) * resScale;

            font->addCharInfo(pCi);
        }
    }
}
