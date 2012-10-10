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
#include "wyNinePatchSprite.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyGlobal.h"
#include "wyEventDispatcher.h"
#include "PVRTMemoryFileSystem.h"
#include "wyResourceDecoder.h"
#include "wyAssetInputStream.h"
#include "wyMD5.h"
#include "wySequence.h"
#include "wyFadeOut.h"
#include "wyDelayTime.h"
#include "wyDirector.h"
#include "wyRunnable.h"
#include "wyHashSet.h"
#include "wyMath.h"
#include "wyCharProvider.h"
#include "wyAction.h"
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <zlib.h>
#include <ctype.h>

// global resource decoder
extern wyResourceDecoder* gResDecoder;

// base64 mapping table
static const unsigned char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// pvr header sig
static char sPVRTexIdentifier[5] = "PVR!";

void wyUtils::makeScreenshot(const char* path, wyRect rect) {
	if (endsWith(path, ".png") || endsWith(path, ".PNG")) {
		makeScreenshotPNG(path, rect);
	} else if(endsWith(path, ".jpg") || endsWith(path, ".jpeg") || endsWith(path, ".JPG") || endsWith(path, ".JPEG")) {
		makeScreenshotJPG(path, rect);
	} else {
		LOGW("unknown screenshots type, only suppert png and jpg");
	}
}

void wyUtils::makeScreenshot(const char* path) {
	makeScreenshot(path, wyr(0, 0, wyDevice::realWidth, wyDevice::realHeight));
}

void wyUtils::makeScreenshotPNG(const char* path) {
	makeScreenshotPNG(path, wyr(0, 0, wyDevice::realWidth, wyDevice::realHeight));
}

void wyUtils::makeScreenshotJPG(const char* path) {
	makeScreenshotJPG(path, wyr(0, 0, wyDevice::realWidth, wyDevice::realHeight));
}

const char* wyUtils::getString(const char* fullName) {
	return getString(getResId(fullName));
}

const char16_t* wyUtils::getString16(const char* fullName) {
	return getString16(getResId(fullName));
}

const char* wyUtils::replaceChar(const char* s, char c, char sub) {
	if(s == NULL)
		return NULL;

	size_t len = strlen(s);
	char* ret = (char*)wyMalloc((len + 1) * sizeof(char));
	int j = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == c) {
			if(sub != 0)
				ret[j++] = sub;
		} else {
			ret[j++] = s[i];
		}
	}

	ret[j] = 0;
	return ret;
}

int wyUtils::readLine(char** data, char* buf) {
	char* start = *data;
	char* end = *data;
	while(*end) {
		if(*end == '\r') {
			end++;

			if(*end == '\n')
				end++;

			break;
		} else if(*end == '\n') {
			end++;
			break;
		} else {
			end++;
		}
	}

	size_t len = end - start;
	if(len > 0)
		memcpy(buf, *data, end - start);
	buf[len] = 0;

	*data = end;
	return len;
}

bool wyUtils::startsWith(const char* s, const char* sub) {
	return strstr(s, sub) == s;
}

bool wyUtils::endsWith(const char* s, const char* sub) {
	int slen = strlen(s);
	int plen = strlen(sub);
	if (slen < plen) {
	  return false;
	}
	return (strcmp(&s[slen-plen], sub) == 0);
}

int wyUtils::utf32toutf8(char32_t c) {
	char16_t* s16 = (char16_t*)wyCalloc(2, sizeof(char16_t));
	s16[0] = c & 0xffff;
	const char* s8 = utf16toutf8(s16);
	wyFree((void*)s16);

	char* p = (char*)s8;
	int ret = 0;
	int b = getUTF8Bytes(*p);
	while(b-- > 0) {
		ret <<= 8;
		ret |= *p & 0xff;
		p++;
	}
	wyFree((void*)s8);
	return ret;
}

size_t wyUtils::strlen16(const char16_t* str) {
    if(!str)
        return 0;

    size_t len = 0;
    while(*str++ != 0) {
        len++;
    }
    return len;
}

size_t wyUtils::strlen32(const char32_t* str) {
    if(!str)
        return 0;

    size_t len = 0;
    while(*str++ != 0) {
        len++;
    }
    return len;
}

size_t wyUtils::strlenW(const wchar_t* str) {
    if(!str)
        return 0;

    size_t len = 0;
    while(*str++ != 0) {
        len++;
    }
    return len;
}

const char16_t* wyUtils::str16str(const char16_t* str, const char* search) {
    if(!str || !search)
        return NULL;

    const char16_t* ret = NULL;

    while(*str != 0) {
        const char* temp1 = search;
        const char16_t* temp2 = str;
        bool bFound = true;
        while(*temp1 != '\0' && *temp2 != 0) {
            char16_t iSearch = (char16_t)(*temp1++);
            char16_t iStr = *temp2++;
            if(iStr != iSearch) {
                bFound = false;
                break;
            }
        }

        if(bFound && *temp1 == '\0'){
            ret = str;
            break;
        }

        str++;
    }

    return ret;
}

int wyUtils::strlen8(const char* s) {
	if(!s)
		return 0;

	int count = 0;
	char* p = (char*)s;
	while(*p) {
		count++;
		int b = getUTF8Bytes(*p);
		p += b;
	}

	return count;
}

int wyUtils::getUTF8Bytes(unsigned char c) {
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

void wyUtils::convertToGL(wyPoint* p) {
	p->y = wyDevice::winHeight - p->y;
}

void wyUtils::convertToGL(float* x, float* y) {
	*y = wyDevice::winHeight - *y;
}

void wyUtils::swap(float* f, int index1, int index2) {
	float tmp = f[index1];
	f[index1] = f[index2];
	f[index2] = tmp;
}

void wyUtils::swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

float wyUtils::resolveDp(float dp) {
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
		return dp * wyDevice::density;
	else
		return dp;
}

float wyUtils::resolveSp(float sp) {
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
		return sp * wyDevice::scaledDensity;
	else
		return sp;
}

float wyUtils::resolvePx(float px) {
	if(wyDevice::scaleMode == SCALE_MODE_BY_DENSITY)
		return px / wyDevice::density;
	else
		return px;
}

wyRect wyUtils::resolveRect(wyRect rect) {
	rect.x = resolveDp(rect.x);
	rect.y = resolveDp(rect.y);
	rect.width = resolveDp(rect.width);
	rect.height = resolveDp(rect.height);
	return rect;
}

wyPoint wyUtils::resolvePoint(wyPoint point) {
	point.x = resolveDp(point.x);
	point.y = resolveDp(point.y);
	return point;
}

char* wyUtils::encodeBase64(const char* src, size_t len, size_t* out_len) {
	char* out;
	char* pos;
	const char* end;
	const char* in;
	size_t olen;
	size_t line_len;

	olen = len * 4 / 3 + 4; /* 3-byte blocks to 4-byte */
	olen += olen / 72; /* line feeds */
	olen++; /* nul termination */
	out = (char*) wyMalloc(olen * sizeof(char));
	if (out == NULL)
		return NULL;

	end = src + len;
	in = src;
	pos = out;
	line_len = 0;
	while (end - in >= 3) {
		*pos++ = base64_table[in[0] >> 2];
		*pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
		*pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
		*pos++ = base64_table[in[2] & 0x3f];
		in += 3;
		line_len += 4;
		if (line_len >= 72) {
			*pos++ = '\n';
			line_len = 0;
		}
	}

	if (end - in) {
		*pos++ = base64_table[in[0] >> 2];
		if (end - in == 1) {
			*pos++ = base64_table[(in[0] & 0x03) << 4];
			*pos++ = '=';
		} else {
			*pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
			*pos++ = base64_table[(in[1] & 0x0f) << 2];
		}
		*pos++ = '=';
		line_len += 4;
	}

	if (line_len)
		*pos++ = '\n';

	*pos = '\0';
	if (out_len)
		*out_len = pos - out;
	return out;
}

char* wyUtils::decodeBase64(const char* data, size_t length, size_t* retLen) {
	size_t outLen = (length / 4) * 3;
    char* out = (char*)wyCalloc(outLen, sizeof(char));

    unsigned int val;
    int pad = 0;
    for(int i = 0, j = 0; i + 3 < length; i += 4, j += 3) {
        val = 0;
        for(int k = i; k < i + 4; k++) {
            if(data[k] >= 'A' && data[k] <= 'Z') {
                val <<= 6;
                val += data[k] - 'A';
            } else if(data[k] >= 'a' && data[k] <= 'z') {
                val <<= 6;
                val += data[k] - 'a' + 26;
            } else if(data[k] >= '0' && data[k] <= '9') {
                val <<= 6;
                val += data[k] - '0' + 52;
            } else if(data[k] == '+') {
                val <<= 6;
                val += 62;
            } else if(data[k] == '/') {
                val <<= 6;
                val += 63;
            } else {
            	pad++;
                val <<= 6;
            }
        }

		val = htobe32(val);
        memcpy(out + j, ((char*)&val) + 1, 3);
    }

	*retLen = outLen - pad;
	char* ret = NULL;
	if(pad > 0) {
		ret = (char*)wyMalloc(*retLen * sizeof(char));
		memcpy(ret, out, *retLen);
		wyFree(out);
	} else {
		ret = out;
	}
	return ret;
}

size_t wyUtils::internal_gunzip(char* in, size_t inLength, char** out, size_t* outLength) {
	/* ret value */
	int err = Z_OK;

	/* 128k initial decompress buffer */
	size_t bufferSize = 128 * 1024;
	*out = (char*) wyMalloc(bufferSize);

    z_stream d_stream; /* decompression stream */
    d_stream.zalloc = NULL;
    d_stream.zfree = NULL;
    d_stream.opaque = NULL;

    d_stream.next_in  = (Bytef*)in;
    d_stream.avail_in = inLength;
	d_stream.next_out = (Bytef*)*out;
	d_stream.avail_out = bufferSize;

	/* window size to hold 256k */
	if( (err = inflateInit2(&d_stream, 15 + 32)) != Z_OK )
		return err;

    while(true) {
        err = inflate(&d_stream, Z_NO_FLUSH);

		if (err == Z_STREAM_END)
			break;

		switch (err) {
			case Z_NEED_DICT:
				err = Z_DATA_ERROR;
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				inflateEnd(&d_stream);
				return err;
		}

		// not enough memory ?
		if (err != Z_STREAM_END) {
			// increase buf
			char* tmp = (char*)wyRealloc(*out, bufferSize * 2);

			/* not enough memory, ouch */
			if (! tmp ) {
				LOGE("Inflate: realloc failed");
				inflateEnd(&d_stream);
				return Z_MEM_ERROR;
			}

			/* only assign to *out if tmp is valid. it's not guaranteed that realloc will reuse the memory */
			*out = tmp;

			d_stream.next_out = (Bytef*)(*out + bufferSize);
			d_stream.avail_out = bufferSize;
			bufferSize *= 2;
		}
    }

	*outLength = bufferSize - d_stream.avail_out;
    err = inflateEnd(&d_stream);
	return err;
}

size_t wyUtils::gunzip(char* in, size_t inLength, char** out) {
	size_t outLength = 0;
	int err = internal_gunzip(in, inLength, out, &outLength);

	if (err != Z_OK || *out == NULL) {
		if (err == Z_MEM_ERROR)
			LOGE("Inflate: Out of memory while decompressing map data!");
		else if (err == Z_VERSION_ERROR)
			LOGE("Inflate: Incompatible zlib version!");
		else if (err == Z_DATA_ERROR)
			LOGE("Inflate: Incorrect zlib compressed data!");
		else
			LOGE("Inflate: Unknown error while decompressing map data!");

		wyFree(*out);
		*out = NULL;
		outLength = 0;
	}

	return outLength;
}

size_t wyUtils::trim(char* s) {
    char* p = s;
    size_t l = strlen(p);

    while(isspace(p[l - 1]))
    	p[--l] = 0;
    while(*p && isspace(*p))
    	++p, --l;

    memmove(s, p, l + 1);
    return l;
}

bool wyUtils::isEmpty(char* s) {
	return s == NULL || strlen(s) == 0;
}

void wyUtils::toLowercase(char* s) {
	if(!s)
		return;

	size_t len = strlen(s);
    for(int i = 0; i < len; i++)
		if(s[i] >= 0x41 && s[i] <= 0x5A)
			s[i] = s[i] + 0x20;
}

void wyUtils::replaceChar(char* s, char from, char to) {
	if(!s)
		return;

	size_t len = strlen(s);
	for(size_t i = 0; i < len; i++) {
		if(s[i] == from)
			s[i] = to;
	}
}

const char* wyUtils::copy(const char* src) {
	if(src == NULL)
		return NULL;

	size_t len = strlen(src);
	char* c = (char*)wyCalloc(len + 1, sizeof(char));
	memcpy(c, src, len);
	return c;
}

const char* wyUtils::copy(const char* src, int start, size_t len) {
	if(src == NULL)
		return NULL;

	char* c = (char*)wyCalloc(len + 1, sizeof(char));
	memcpy(c, src + start, len);
	return c;
}

const char* wyUtils::copyData(const char* data, size_t len) {
	if(data == NULL)
		return NULL;

	char* c = (char*)wyCalloc(len, sizeof(char));
	memcpy(c, data, len);
	return c;
}

unsigned int wyUtils::strHash(const char* str) {
	unsigned int seed = 131;
	unsigned int hash = 0;
	while(*str) {
		hash = hash * seed + (*str++);
	}

	return hash & 0x7FFFFFFF;
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
	return wyUtils::copy(chars, s, len);
}

vector<const char*>* wyUtils::breakLines(const char* chars, wyCharProvider* provider, float width, float spaceWidth, float tabSize) {
	vector<const char*>* lines = WYNEW vector<const char*>();

	// make width max if less than zero
	if(width <= 0)
		width = MAX_FLOAT;

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
			bool isSeparator = chars[i] == '-' || chars[i] == '/' || chars[i] == '\\';
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
				float lineWidth = provider->measureText(chars + lineStart, i + utf8Count - lineStart, spaceWidth, tabSize);

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

int wyUtils::binarySearch(int* a, size_t len, int key) {
	int low = 0;
	int high = len - 1;

	while(low <= high) {
		int mid = (low + high) >> 1;
		int midVal = a[mid];

		if(midVal < key)
			low = mid + 1;
		else if(midVal > key)
			high = mid - 1;
		else
			return mid; // key found
	}
	return -(low + 1); // key not found.
}

bool wyUtils::getFile(const char* filename, const char** buffer, size_t* size) {
	return CPVRTMemoryFileSystem::GetFile(filename, (const void**)buffer, (size_t*)size);
}

int64_t wyUtils::currentTimeMillis() {
	struct timeval tv;
	gettimeofday(&tv, (struct timezone *) NULL);
	int64_t when = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return when;
}

size_t wyUtils::getFileSize(FILE* f) {
	size_t cur = ftell(f);
	fseek(f, 0, SEEK_END);
	size_t length = ftell(f);
	fseek(f, cur, SEEK_SET);
	return length;
}

const char* wyUtils::getParentPath(const char* path) {
	if(path == NULL)
		return NULL;

	char* slash = (char*)strrchr(path, '/');
	if(slash == NULL)
		return NULL;
	else if(slash == path)
		return wyUtils::copy(path, 0, 1);
	else
		return wyUtils::copy(path, 0, slash - path);
}

bool wyUtils::createIntermediateFolders(const char* path) {
	const char* parent = getParentPath(path);
	bool exist = isPathExistent(parent);
	bool success = true;
	if(!exist) {
		createIntermediateFolders(parent);
		success = createFolder(parent);
	}

	// release
	if(parent != NULL)
		wyFree((void*)parent);

	// return success flag
	return success;
}

ssize_t wyUtils::lastSlashIndex(const char* path) {
	if(path == NULL)
		return -1;

	size_t len = strlen(path);
	int end = len;
	int slash = -1;
	for(int i = len - 1; i >= 0; i--) {
		if(path[i] == WY_PATH_SEPARATOR) {
			if(i == end - 1) {
				end--;
				if(i == 0) {
					slash = 0;
					break;
				}
			} else {
				slash = i;
				break;
			}
		}
	}

	// skip extra slash
	if(slash != -1) {
		while(slash >= 1 && path[slash - 1] == WY_PATH_SEPARATOR)
			slash--;
	}

	// assign to end
	end = slash;
	if(end == 0)
		end = 1;

	return end;
}

ssize_t wyUtils::lastDotIndex(const char* path) {
	if(path == NULL)
		return -1;

	size_t len = strlen(path);
	for(int i = len - 1; i >= 0; i--) {
		if(path[i] == '.')
			return i;
	}

	return -1;
}

const char* wyUtils::deleteLastPathComponent(const char* path) {
	ssize_t end = lastSlashIndex(path);
	if(end < 0)
		return copy(path, 0, 0);
	else
		return copy(path, 0, end);
}

void wyUtils::deleteLastPathComponentInSameBuffer(char* path) {
	ssize_t end = lastSlashIndex(path);
	if(end < 0)
		path[0] = 0;
	else
		path[end] = 0;
}

const char* wyUtils::deletePathExtension(const char* path) {
	ssize_t end = lastDotIndex(path);
	ssize_t slash = lastSlashIndex(path);
	if(end >= 0) {
		if(end > slash)
			return copy(path, 0, end);
		else
			return copy(path);
	} else {
		return copy(path, 0, 0);
	}
}

void wyUtils::deletePathExtensionInSameBuffer(char* path) {
	ssize_t end = lastDotIndex(path);
	ssize_t slash = lastSlashIndex(path);
	if(end >= 0 && end > slash)
		path[end] = 0;
}

const char* wyUtils::appendPathComponent(const char* path, const char* component) {
	// validating
	if(path == NULL) {
		if(component == NULL)
			return NULL;
		else
			return copy(component);
	} else if(component == NULL)
		return copy(path);

	// allocate a big enough buffer
	// plus 2 because one for slash, one for null terminator
	size_t len = strlen(path);
	int cLen = strlen(component);
	char* ret = (char*)wyCalloc(len + cLen + 2, sizeof(char));

	// copy path
	memcpy(ret, path, len);

	// take care of slash
	int start = len;
	if(start > 0) {
		if(ret[start - 1] != WY_PATH_SEPARATOR) {
			ret[start++] = WY_PATH_SEPARATOR;
		} else {
			while(start >= 2 && ret[start - 2] == WY_PATH_SEPARATOR)
				start--;
		}
	}

	// copy component
	int cStart = 0;
	while(cStart < cLen && component[cStart] == WY_PATH_SEPARATOR)
		cStart++;
	if(cStart > 0 && start == 0)
		cStart--;
	memcpy(ret + start, component + cStart, cLen - cStart);

	return (const char*)ret;
}

const char* wyUtils::lastPathComponent(const char* path) {
	size_t len = strlen(path);
	int start = 0;
	int end = len;
	for(int i = len - 1; i >= 0; i--) {
		if(path[i] == WY_PATH_SEPARATOR) {
			if(i == end - 1)
				end--;
			else {
				start = i + 1;
				break;
			}
		}
	}

	if(end < start)
		return copy(path);
	else
		return copy(path, start, end - start);
}

const char* wyUtils::decodeObfuscatedData(const char* data, size_t length, size_t* outLen) {
	if(!data) {
		if(outLen)
			*outLen = 0;
		return NULL;
	} else if(gResDecoder) {
		const char* ret = gResDecoder->decode(data, length, outLen);
		return ret;
	} else {
		if(outLen)
			*outLen = length;
		return data;
	}
}

char* wyUtils::loadCString(const char* mfsName) {
	char* buffer = NULL;
	size_t len;
	if(getFile(mfsName, (const char**)&buffer, &len)) {
		char* cstr = (char*)wyMalloc(sizeof(char) * (len + 1));
		memcpy(cstr, buffer, len);
		cstr[len] = 0;
		return cstr;
	} else {
		return NULL;
	}
}

char* wyUtils::loadBMP(FILE* f, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(f, &length);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadBMP(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadBMP(int resId, float* w, float* h, bool sizeOnly) {
	// load raw data
	size_t length;
	float scale;
	char* raw = loadRaw(resId, &length, &scale);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadBMP(raw, length, w, h, sizeOnly, scale, scale);
	wyFree(raw);
	return data;
}

char* wyUtils::loadBMP(const char* path, bool isFile, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(path, isFile, &length);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadBMP(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadPNG(FILE* f, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(f, &length);
	if(raw == NULL)
		return NULL;
	
	// then deliver to other method
	char* data = loadPNG(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadPNG(int resId, float* w, float* h, bool sizeOnly) {
	// load raw data
	size_t length;
	float scale;
	char* raw = loadRaw(resId, &length, &scale);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadPNG(raw, length, w, h, sizeOnly, scale, scale);
	wyFree(raw);
	return data;
}

char* wyUtils::loadPNG(const char* path, bool isFile, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(path, isFile, &length);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadPNG(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadJPG(FILE* f, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(f, &length);
	if(raw == NULL)
		return NULL;
	
	// then deliver to other method
	char* data = loadJPG(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadJPG(int resId, float* w, float* h, bool sizeOnly) {
	// load raw data
	size_t length;
	float scale;
	char* raw = loadRaw(resId, &length, &scale);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadJPG(raw, length, w, h, sizeOnly, scale, scale);
	wyFree(raw);
	return data;
}

char* wyUtils::loadJPG(const char* path, bool isFile, float* w, float* h, bool sizeOnly, float scaleX, float scaleY) {
	// load raw data
	size_t length;
	char* raw = loadRaw(path, isFile, &length);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	char* data = loadJPG(raw, length, w, h, sizeOnly, scaleX, scaleY);
	wyFree(raw);
	return data;
}

char* wyUtils::loadRaw(FILE* f, size_t* outLen, bool noDecode) {
	// get readable length
	size_t length = getFileSize(f);
	
	// create buffer
	char* data = NULL;
	if ((data = (char*)wyMalloc(length)) == NULL) {
		LOGW("allocate data buffer failed");
		fclose(f);
		return NULL;
	}
	
	// read data
	if(fread(data, sizeof(char), length, f) != length) {
		LOGW("read data failed");
		fclose(f);
		wyFree(data);
		return NULL;
	}
	
	// close file
	fclose(f);
	
	// check decoder flag
	if(!noDecode) {
		if(gResDecoder != NULL && !gResDecoder->hasFlag(wyResourceDecoder::DECODE_FILE))
			noDecode = true;
	}

	// decode data or not
	if(!noDecode) {
		const char* decoded = decodeObfuscatedData(data, length, outLen);
		if(decoded != data) {
			wyFree(data);
			data = (char*)decoded;
		}	
	} else {
		if(outLen)
			*outLen = length;
	}

	return data;
}

bool wyUtils::getPVRSize(const char* data, size_t length, float* w, float* h, float scale) {
	// create buffer
	wyPVRHeader* header = NULL;
	if ((header = (wyPVRHeader*)wyMalloc(sizeof(wyPVRHeader))) == NULL) {
		LOGW("allocate pvr header buffer failed");
		return false;
	}
	
	// convert to pvr header
	memcpy(header, data, sizeof(wyPVRHeader));
	header->height = letoh32(header->height);
	header->width = letoh32(header->width);
	
	// save result
	if(w != NULL)
		*w = header->width;
	if(h != NULL)
		*h = header->height;
	
	/*
	 * XXX: 在iOS平台上缩放PVR有些麻烦, 暂不支持, 为了保持WiEngine在Android和iOS上的行为一致, 这里
	 * 暂时不再缩放PVR贴图
	 */
	// check format if supports scaling
//	wyPVRFormat format = (wyPVRFormat)(header->flags & PVR_TEXTURE_FLAG_TYPE_MASK);
//	if(canScalePVR(format)) {
//		*w = *w * scale;
//		*h = *h * scale;
//	}
	
	// free header
	wyFree(header);
	
	return true;
}

bool wyUtils::getPVRSize(FILE* f, float* w, float* h, float scale) {
	// load raw data
	size_t length;
	char* raw = loadRaw(f, &length);
	if(raw == NULL)
		return NULL;
	
	// forward
	bool ret = getPVRSize(raw, length, w, h, scale);
	wyFree(raw);
	
	return ret;
}

bool wyUtils::getPVRSize(int resId, float* w, float* h, float* outScale) {
	// load raw data
	size_t length;
	char* raw = loadRaw(resId, &length, outScale);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	bool ret = getPVRSize(raw, length, w, h, *outScale);
	wyFree(raw);
	return ret;
}

bool wyUtils::getPVRSize(const char* path, bool isFile, float* w, float* h, float scale) {
	// load raw data
	size_t length;
	char* raw = loadRaw(path, isFile, &length);
	if(raw == NULL)
		return NULL;

	// then deliver to other method
	bool ret = getPVRSize(raw, length, w, h, scale);
	wyFree(raw);
	return ret;
}

void wyUtils::convertPVRHeaderEndian(wyPVRHeader* header) {
	header->headerLength = letoh32(header->headerLength);
	header->height = letoh32(header->height);
	header->width = letoh32(header->width);
	header->numMipmaps = letoh32(header->numMipmaps);
	header->flags = letoh32(header->flags);
	header->dataLength = letoh32(header->dataLength);
	header->bpp = letoh32(header->bpp);
	header->bitmaskRed = letoh32(header->bitmaskRed);
	header->bitmaskGreen = letoh32(header->bitmaskGreen);
	header->bitmaskBlue = letoh32(header->bitmaskBlue);
	header->bitmaskAlpha = letoh32(header->bitmaskAlpha);
	header->pvrTag = letoh32(header->pvrTag);
	header->numSurfs = letoh32(header->numSurfs);
}

char** wyUtils::unpackPVRData(char* data, wyPVRHeader* header, int** mipmapLens, int* pvrFormatIndex, bool* hasAlpha) {
	// to be returned
	int index = 0;
	char** mipmaps = (char**)wyCalloc(header->numMipmaps + 1, sizeof(char*));
	*mipmapLens = (int*)wyCalloc(header->numMipmaps + 1, sizeof(int));

	// check pvr sig
	if((uint32_t)sPVRTexIdentifier[0] != ((header->pvrTag >> 0) & 0xff) ||
			(uint32_t)sPVRTexIdentifier[1] != ((header->pvrTag >> 8) & 0xff) ||
			(uint32_t)sPVRTexIdentifier[2] != ((header->pvrTag >> 16) & 0xff) ||
			(uint32_t)sPVRTexIdentifier[3] != ((header->pvrTag >> 24) & 0xff)) {
		LOGE("ERROR: PVR signature is not matched, may be corrupted");
		return NULL;
	}

	int formatFlags = header->flags & PVR_TEXTURE_FLAG_TYPE_MASK;
	bool flipped = (header->flags & PVR_TEXTURE_FLAG_FLIPPED_MASK) != 0;
	if(flipped)
		LOGW("WARNING: Image is flipped. Regenerate it using PVRTexTool");

	bool success = false;
	int pvrIndex = 0;
	for(; pvrIndex < PVR_FORMAT_TABLE_ELEMENTS; pvrIndex++) {
		if(gPVRFormats[pvrIndex][PVR_INDEX_TEXTURE_FORMAT] == formatFlags) {
			if(header->bitmaskAlpha > 0)
				*hasAlpha = true;
			else
				*hasAlpha = false;

			// Calculate the data size for each texture level and respect
			// the minimum number of blocks
			int dataOffset = 0, dataSize = 0, blockSize = 0, widthBlocks = 0, heightBlocks = 0;
			int dataLength = header->dataLength;
			int width = header->width;
			int height = header->height;
			int bpp = 4;
			while(dataOffset < dataLength) {
				switch(formatFlags) {
					case PVR_PVRTC_2:
						// Pixel by pixel block size for 2bpp
						blockSize = 8 * 4;
						widthBlocks = width / 8;
						heightBlocks = height / 4;
						bpp = 2;
						break;
					case PVR_PVRTC_4:
						// Pixel by pixel block size for 4bpp
						blockSize = 4 * 4;
						widthBlocks = width / 4;
						heightBlocks = height / 4;
						bpp = 4;
						break;
					default:
						blockSize = 1;
						widthBlocks = width;
						heightBlocks = height;
						bpp = gPVRFormats[pvrIndex][PVR_INDEX_BPP];
						break;
				}

				// Clamp to minimum number of blocks
				if(widthBlocks < 2)
					widthBlocks = 2;
				if(heightBlocks < 2)
					heightBlocks = 2;

				dataSize = widthBlocks * heightBlocks * blockSize * bpp / 8;
				(*mipmapLens)[index] = dataSize;
				mipmaps[index] = (char*)wyMalloc(dataSize);
				memcpy(mipmaps[index], data + header->headerLength + dataOffset, dataSize);
				index++;
				dataOffset += dataSize;

				width = MAX(width >> 1, 1);
				height = MAX(height >> 1, 1);
			}

			success = true;
			break;
		}
	}

	if(!success) {
		LOGW("WARNING: Unsupported PVR Pixel Format: %d", formatFlags);

		// release memory allocated
		for(int i = 0; i < header->numMipmaps + 1; i++) {
			if(mipmaps[i] != NULL)
				wyFree(mipmaps[i]);
		}
		wyFree(mipmaps);
		wyFree(*mipmapLens);
		*mipmapLens = NULL;

		return NULL;
	} else {
		// return pvr format index
		*pvrFormatIndex = pvrIndex;

		// return uncompressed data
		return mipmaps;
	}
}

bool wyUtils::canScalePVR(wyPVRFormat format) {
	switch(format) {
		case PVR_RGBA_4444:
		case PVR_RGBA_8888:
		case PVR_RGB_565:
		case PVR_A_8:
			return true;
		default:
			return false;
	}
}

void wyUtils::runOnGLThread(wyRunnable* runnable) {
	wyEventDispatcher::getInstance()->queueRunnableLocked(runnable);
}

const char* wyUtils::fileMd5(const char* path) {
	// open it
	wyAssetInputStream* ais = wyAssetInputStream::make(path, true);

	// file size
	size_t size = ais->getLength();

	// depends on size
	if(size <= 60 * 1024) {
		// allocate buffer
		char* buf = (char*)malloc(size);

		// read until end
		size_t read = 0;
		size_t i = 0;
		do {
			i = ais->read(buf + read, size - read);
			read += i;
		} while(i > 0);

		// not fully read? so it should be error
		if(read != size)
			return NULL;

		// get md5
		const char* md5 = wyMD5::md5((const void*)buf, size);

		// release buffer
		free(buf);

		// return
		return md5;
	} else {
		char buf[60 * 1024];

		// head
		ais->seek(0, SEEK_SET);
		size_t read = 0;
		while(read != 20 * 1024) {
			read += ais->read(buf + read, 20 * 1024 - read);
		}

		// middle
		ais->seek(size / 2 - 10 * 1024, SEEK_SET);
		while(read != 40 * 1024) {
			read += ais->read(buf + read, 40 * 1024 - read);
		}

		// end
		ais->seek(-20 * 1024, SEEK_END);
		while(read != 60 * 1024) {
			read += ais->read(buf + read, 60 * 1024 - read);
		}

		// get md5
		const char* md5 = wyMD5::md5((const void*)buf, 60 * 1024);

		// return
		return md5;
	}
}
