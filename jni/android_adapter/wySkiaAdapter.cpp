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
#include "wySkiaAdapter.h"
#include "SkBitmap.h"
#include "SkStream.h"
#include "SkTypeface.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "wyLog.h"
#include <vector>

// use stl
using namespace std;

// max value
#define MAX_FLOAT 3.4028235E38f

// text alignment
enum Alignment {
	LEFT,
	CENTER,
	RIGHT
};

#ifdef __cplusplus
extern "C" {
#endif

static int getNextPOT(int x) {
	x = x - 1;
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	return x + 1;
}

static const char* copy(const char* src, int start, size_t len) {
	if(src == NULL)
		return NULL;

	char* c = (char*)calloc(len + 1, sizeof(char));
	memcpy(c, src + start, len);
	return c;
}

/**
 * 计算utf8编码块的字节数
 */
static int getUTF8Bytes(unsigned char c) {
	int count = 1;
	if(c >= 128) {
		c <<= 1;
		do {
			count++;
			c <<= 1;
		} while(c > 128);
	}

	return count;
}

static const char* smartTrim(const char* chars, int start, int end, bool startsParagraph) {
	int s = start;
	int e = end;

	// purge leading space
	if(!startsParagraph) {
		for(int i = s; i < e; i++) {
			if(chars[i] == ' ')
				s++;
			else
				break;
		}
	}

	// purge tailing space
	for(int i = e - 1; i >= s; i--) {
		if(chars[i] == ' ')
			e--;
		else
			break;
	}

	// check length, if zero, return all
	int len = e - s;
	if(len == 0) {
		s = start;
		e = end;
		len = end - start;
	}

	// copy string and return
	return copy(chars, s, len);
}

static vector<const char*>* breakLines(const char* chars, SkPaint* paint, float width) {
	vector<const char*>* lines = new vector<const char*>();
	lines->reserve(10);

	if (chars != NULL) {
		// The index of a character that may appear on the
		// next line. For example a space can appear on this
		// line or the next, but a letter in the middle of the
		// word must stay on the same line as the entire word.
		int lastBreakableSpot = 0;

		// The index of the character that starts this line.
		int lineStart = 0;

		// length of all bytes
		size_t length = strlen(chars);

		// prev char
		bool prevIsEN = false;
		bool prevIsNUM = false;

		for (int i = 0; i < length;) {
			// do a basic check for this char
			int utf8Count = getUTF8Bytes((unsigned char)chars[i]);
			bool isSeparator = chars[i] == '-' || chars[i] == '/';
			bool isWhiteSpace = chars[i] == ' ' || chars[i] == '\t';
			bool isNewLine = chars[i] == '\n';
			bool isCarriageReturn = chars[i] == '\r';
			bool isEN = chars[i] >= 'a' && chars[i] <= 'z' || chars[i] >= 'A' && chars[i] <= 'Z';
			bool isNUM = chars[i] >= '0' && chars[i] <= '9';
			bool isDot = chars[i] == '.';

			// special care for x.y, then we think dot is a num
			if(isDot && prevIsNUM)
				isNUM = true;

			// check char type
			if(isNewLine || isCarriageReturn) {
				// Record the line.
				const char* line = smartTrim(chars, lineStart, i, true);
				lines->push_back(line);

				// set new line start
				// need skip new line after carriage return
				if(isCarriageReturn && chars[i + utf8Count] == '\n') {
					lineStart = i + utf8Count + 1;
				} else {
					lineStart = i + utf8Count;
				}
				i = lineStart;
				lastBreakableSpot = lineStart;
				prevIsEN = false;
				prevIsNUM = false;
			} else {
				// measure width of this line which counting current char
				float lineWidth = paint->measureText(chars + lineStart, i + utf8Count - lineStart);

				// can we break here?
				if(isWhiteSpace) {
					lastBreakableSpot = i;
				} else if(isSeparator) {
					if(lineWidth < width)
						lastBreakableSpot = i + utf8Count;
				} else if(isEN) {
					if(!prevIsEN)
						lastBreakableSpot = i;
				} else if(isNUM) {
					if(!prevIsNUM)
						lastBreakableSpot = i;
				} else {
					lastBreakableSpot = i;
				}

				// check width
				if(lineWidth > width) {
					if(i <= lineStart) {
						// line chars is zero, so the width may be very small, we need ensure at least one char is available for one line
						const char* line = smartTrim(chars, lineStart, i + utf8Count, true);
						lines->push_back(line);

						// reset line start
						i += utf8Count;
						lineStart = i;
						prevIsEN = isEN;
						prevIsNUM = isNUM;
					} else {
						if(lastBreakableSpot == lineStart) {
							// if there is no breakable position, we bend it no matter what the line it is
							const char* line = smartTrim(chars, lineStart, i, true);
							lines->push_back(line);

							// reset line start
							lineStart = i;
						} else {
							// break on last breakable spot
							const char* line = smartTrim(chars, lineStart, lastBreakableSpot, true);
							lines->push_back(line);

							// next line start should begin from last breakable spot
							lineStart = lastBreakableSpot;

							// skip one whitespace
							if(lineStart < length) {
								if(chars[lineStart] == ' ' || chars[lineStart] == '\t')
									lineStart++;
							}
						}
					}

					// align last breakable spot to line start
					lastBreakableSpot = lineStart;
				} else {
					i += utf8Count;
					prevIsEN = isEN;
					prevIsNUM = isNUM;
				}
			}
		}

		// add the last line
		if(length > lineStart) {
			const char* lastLine = smartTrim(chars, lineStart, length, true);
			lines->push_back(lastLine);
		}
	}

	return lines;
}

static void internalCalculateTextSize(const char* text, SkPaint* paint, float width, size_t* w, size_t* h) {
	// null checking
	if(!text) {
		if(w)
			*w = 0;
		if(h)
			*h = 0;
		return;
	}

	// get ascent and descent
	struct SkPaint::FontMetrics fm;
	paint->getFontMetrics(&fm);
	int ascent = (int)ceil(-fm.fAscent);
	int descent = (int)ceil(fm.fDescent);

	// if width is zero, use max value to break lines
	// we can just think it is single line because it may contains new line character
	vector<const char*>* lines = breakLines(text, paint, width == 0 ? MAX_FLOAT : width);

	// choose max width as the final width
	float max = 0;
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		const char* line = *iter;
		float lineWidth = paint->measureText(line, strlen(line));
		if(lineWidth > max)
			max = lineWidth;
	}
	*w = max;
	*h = lines->size() * (ascent + descent);

	// release lines
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		free((void*)*iter);
	}
	delete lines;
}

static void calculateTextSize(const char* text, SkTypeface* typeface, float fontSize, float width, size_t* w, size_t* h) {
	// create paint
	SkPaint* paint = new SkPaint();
	paint->setTypeface(typeface);
	paint->setTextSize(fontSize);
	paint->setAntiAlias(true);

	// delegate to other method
	internalCalculateTextSize(text, paint, width, w, h);

	// delete paint
	delete paint;
}

static SkTypeface* createTypefaceFromData(const char* data, size_t length) {
	if(data == NULL) {
		return NULL;
	} else {
		// create stream
		SkStream* stream = new SkMemoryStream(data, length);

		// create typeface
		SkTypeface* typeface = SkTypeface::CreateFromStream(stream);
		SkSafeUnref(stream);

		return typeface;
	}
}

static SkTypeface* createTypefaceWithName(const char* fontName, bool bold, bool italic) {
	SkTypeface::Style s = SkTypeface::kNormal;
	if(bold && italic)
		s = SkTypeface::kBoldItalic;
	else if(bold)
		s = SkTypeface::kBold;
	else if(italic)
		s = SkTypeface::kItalic;

	return SkTypeface::CreateFromName(fontName, s);
}

static const char* createLabelBitmap(const char* text, SkTypeface* typeface, float fontSize, float width, int alignment) {
    SkPaint* paint = new SkPaint();
    paint->setTypeface(typeface);
    paint->setTextSize(fontSize);
    paint->setAntiAlias(true);
    paint->setColor(0xffffffff);

	// get ascent and descent
	struct SkPaint::FontMetrics fm;
	paint->getFontMetrics(&fm);
	int ascent = (int)ceil(-fm.fAscent);
	int descent = (int)ceil(fm.fDescent);

	// measure text
	int textHeight, textWidth;
	int textLen = text ? strlen(text) : 0;

	// if width is zero, use max value to break lines
	// we can just think it is single line because it may contains new line character
	vector<const char*>* lines = breakLines(text, paint, width == 0 ? MAX_FLOAT : width);
	textHeight = lines->size() * (ascent + descent);

	// to save width of every line
	float* everyLineWidths = (float*)malloc(lines->size() * sizeof(float));

	// choose max width as the final width
	float max = 0;
	int i = 0;
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++, i++) {
		const char* line = *iter;
		everyLineWidths[i] = paint->measureText(line, strlen(line));
		if(everyLineWidths[i] > max)
			max = everyLineWidths[i];
	}
	textWidth = max;

	// get POT size
	float potWidth = getNextPOT(textWidth);
	float potHeight = getNextPOT(textHeight);

    // create POT image
	SkBitmap* bitmap = new SkBitmap();
	bitmap->setConfig(SkBitmap::kARGB_8888_Config, potWidth, potHeight);
	void* pixels = calloc(potWidth * potHeight * 4, sizeof(char));
	bitmap->setPixels(pixels);

	// create canvas
	SkCanvas* canvas = new SkCanvas(*bitmap);

	// clear bitmap
    bitmap->eraseColor(0);

    // draw text, for single line or multiple lines
    i = 0;
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++, i++) {
		const char* line = *iter;
		switch(alignment) {
			case LEFT:
				canvas->drawText(line,
						strlen(line),
						0,
						ascent + i * (ascent + descent),
						*paint);
				break;
			case CENTER:
				canvas->drawText(line,
						strlen(line),
						(textWidth - everyLineWidths[i]) / 2,
						ascent + i * (ascent + descent),
						*paint);
				break;
			case RIGHT:
				canvas->drawText(line,
						strlen(line),
						textWidth - everyLineWidths[i],
						ascent + i * (ascent + descent),
						*paint);
				break;
		}
	}

	// release lines
	for(vector<const char*>::iterator iter = lines->begin(); iter != lines->end(); iter++) {
		free((void*)*iter);
	}
	delete lines;
	free(everyLineWidths);

    // release skia
    delete paint;
    delete bitmap;
    delete canvas;

    return (const char*)pixels;
}

char* scaleImage(int config, char* originData, int originWidth, int originHeight, float scaleX, float scaleY) {
	// get byte per pixel
	SkBitmap::Config c = (SkBitmap::Config)config;
	int bpp = 0;
	switch(c) {
		case SkBitmap::kARGB_8888_Config:
			bpp = 4;
			break;
		case SkBitmap::kARGB_4444_Config:
		case SkBitmap::kRGB_565_Config:
			bpp = 2;
			break;
		case SkBitmap::kA8_Config:
			bpp = 1;
			break;
		default:
			LOGE("scale image: unsupported config for scaling image");
			return originData;
	}

	// create paint
	SkPaint* paint = new SkPaint();
	paint->setFilterBitmap(true);

	// create origin bitmap
	SkBitmap* origin = new SkBitmap();
	origin->setConfig((SkBitmap::Config)config, originWidth, originHeight);
	origin->setPixels((void*)originData);

	// create scaled bitmap
	SkBitmap* scaled = new SkBitmap();
	int sW = originWidth * scaleX + 0.5f;
	int sH = originHeight * scaleY + 0.5f;
	scaled->setConfig((SkBitmap::Config)config, sW, sH);
	void* pixels = calloc(sW * sH * bpp, sizeof(char));
	scaled->setPixels(pixels);

	// create canvas and scale
	SkCanvas* canvas = new SkCanvas(*scaled);
	canvas->scale(scaleX, scaleY);

	// draw origin bitmap
	canvas->drawBitmap(*origin, 0, 0, paint);

	// release
	delete paint;
	delete canvas;
	delete origin;
	delete scaled;

	// return scaled data
	return (char*)pixels;
}

void calculateTextSizeWithCustomFont(const char* text, float fontSize, const char* fontData, int dataLength, float width, size_t* w, size_t* h) {
	// create typeface and calculate size
	SkTypeface* tf = createTypefaceFromData(fontData, dataLength);
	calculateTextSize(text, tf, fontSize, width, w, h);
	SkSafeUnref(tf);
}

void calculateTextSizeWithFont(const char* text, float fontSize, bool bold, bool italic, const char* fontName, float width, size_t* w, size_t* h) {
	// create typeface and calculate size
	SkTypeface* tf = createTypefaceWithName(fontName, bold, italic);
	calculateTextSize(text, tf, fontSize, width, w, h);
	SkSafeUnref(tf);
}

const char* createLabelBitmapWithFont(const char* text, float fontSize, bool bold, bool italic, const char* fontName, float width, int alignment) {
	// create typeface then create bitmap from it
	SkTypeface* tf = createTypefaceWithName(fontName, bold, italic);
	const char* bitmap = createLabelBitmap(text, tf, fontSize, width, alignment);
	SkSafeUnref(tf);
	return bitmap;
}

const char* createLabelBitmapWithCustomFont(const char* text, float fontSize, const char* fontData, int dataLength, float width, int alignment) {
	// create typeface then create bitmap from it
	SkTypeface* tf = createTypefaceFromData(fontData, dataLength);
	const char* bitmap = createLabelBitmap(text, tf, fontSize, width, alignment);
	SkSafeUnref(tf);
	return bitmap;
}

#ifdef __cplusplus
}
#endif
