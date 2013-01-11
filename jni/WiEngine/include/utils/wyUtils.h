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
#ifndef __wyUtils_h__
#define __wyUtils_h__

#include "WiEngine-Classes.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "wyTypes.h"
#include "wyTexture2D.h"

// for easy of use
#define DP(x) wyUtils::resolveDp((x))
#define DIP(x) DP(x)
#define PX(x) wyUtils::resolvePx((x))
#define SP(x) wyUtils::resolveSp((x))
#define RES(x) wyUtils::getResId((x))
#define STR(x) wyUtils::getString((x))
#define S8(x) STR(x)
#define STR16(x) wyUtils::getString16((x))
#define S16(x) STR16(x)

/**
 * @class wyUtils
 *
 * utility class which provides many static helper methods
 */
class WIENGINE_API wyUtils {
	friend class wyEventDispatcher;

private:
	/**
	 * Decode an obfuscated data, if no resource obfuscator installed, just
	 * return the incoming data
	 *
	 * @param data encoded data
	 * @param length data length
	 * @param outLen it holds length of decoded data
	 * @return decoded data or \c data if no decoder installed
	 */
	static const char* decodeObfuscatedData(const char* data, size_t length, size_t* outLen);

	/**
	 * Grab current opengl frame and save it in a jpeg file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 */
	static void makeScreenshotJPG(const char* path);

	/**
	 * Grab current opengl frame and save it in a jpeg file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * @param rect screen rect to be shot
	 */
	static void makeScreenshotJPG(const char* path, wyRect rect);

	/**
	 * Grab current opengl frame and save it in a png file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 */
	static void makeScreenshotPNG(const char* path);

	/**
	 * Grab current opengl frame and save it in a png file. Saving may be a little
	 * slow so it is developer's responsibility to show some hint to user. It uses opengl
	 * api to grab screen and the api may not exist in low version Android. Meanwhile it needs
	 * sd card permission because screenshot is saved in external storage.
	 *
	 * @param path the path to save screenshot, and WiEngine creates all intermediate folders if it doesn't
	 * 		exist. If path is NULL, nothing will be saved. The path will be mapped if not Android platform
	 * @param rect screen rect to be shot
	 */
	static void makeScreenshotPNG(const char* path, wyRect rect);

	/**
	 * inflate a zip content
	 *
	 * @param in zipped data
	 * @param inLength length of zipped data
	 * @param out inflated data buffer
	 * @param outLength a pointer to an integer to hold the length of inflated data
	 */
	static size_t internal_gunzip(char* in, size_t inLength, char** out, size_t* outLength);

	/**
	 * Convert KeyEvent java object to \link wyKeyEvent wyKeyEvent\endlink structure
	 *
	 * @param pe platform-dependent key event object
	 * @param event to save converted \link wyKeyEvent wyKeyEvent\endlink structure
	 */
	static void convertKeyEvent(wyPlatformKeyEvent pe, wyKeyEvent* event);

	/**
	 * Convert java MotionEvent object to \link wyMotionEvent wyMotionEvent\endlink structure
	 *
	 * @param pe platform-dependent event object, for Android it is MotionEvent, for iOS it is UIEvent
	 * @param event to save converted \link wyMotionEvent wyMotionEvent\endlink structure
	 * @param type event type, optional
	 */
	static void convertMotionEvent(wyPlatformMotionEvent pe, wyMotionEvent* event, int type = 0);

	/**
	 * Get index of last slash character, if not found, returns -1
	 */
	static ssize_t lastSlashIndex(const char* path);

	/**
	 * Get index of last dot character, if not found, returns -1
	 */
	static ssize_t lastDotIndex(const char* path);

	/**
	 * Load bmp RGBA8888 data from memory bmp data
	 *
	 * @param data bmp file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadBMP(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load png RGBA8888 data from memory png data
	 *
	 * @param data png file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadPNG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load jpg RGBA8888 data from memory png data
	 *
	 * @param data jpg file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadJPG(const char* data, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

public:
	
	/*
	 * resource related operations
	 */

	/**
	 * Get resource id by resource name and type
	 *
	 * @param name resource name
	 * @param type resource type
	 * @param type2 fallback type, if \c type is not found, will search type2
	 * @return resource id
	 */
	static int getResId(const char* name, const char* type, const char* type2);

	/**
	 * Get resource id from resource full name, such as R.drawable.abc
	 *
	 * @param fullName full name of resource
	 * @return resource id
	 */
	static int getResId(const char* fullName);

	/**
	 * Is a resource existent or not
	 *
	 * @param path file path of resource file
	 * @param isFile true means \c path is an absolute path in file system, or false
	 * 		means \c path is a relative path under assets
	 * @return true means this resource can be opened
	 */
	static bool isResExistent(const char* path, bool isFile);

	/**
	 * Get string from string full resource name, such as R.string.abc
	 *
	 * @param fullName string resource full name
	 * @return string, caller should release it
	 */
	static const char* getString(const char* fullName);

	/**
	 * Get string from resource id
	 *
	 * @param resId id of string resource
	 * @return string, caller should release it
	 */
	static const char* getString(int resId);

	/**
	 * Get utf-16 string from resource full name
	 *
	 * @param fullName string resource full name
	 * @return string in utf-16 encoding, caller should release it
	 */
	static const char16_t* getString16(const char* fullName);

	/**
	 * Get utf-16 string from string resource id
	 *
	 * @param resId string resource id
	 * @return string in utf-16 encoding, caller should release it
	 */
	static const char16_t* getString16(int resId);
	
	/**
	 * Check a image is png or not
	 *
	 * @param image raw data
	 * @param size raw data length in bytes
	 * @return true means the raw data is a png image, or false if not
	 */
	static bool isPNG(const char* p, size_t size);

	/**
	 * Check a image is jpg or not
	 *
	 * @param image raw data
	 * @param size raw data length in bytes
	 * @return true means the raw data is a jpg image, or false if not
	 */
	static bool isJPG(const char* p, size_t size);

	/**
	 * Check a image is bmp or not
	 *
	 * @param image raw data
	 * @param size raw data length in bytes
	 * @return true means the raw data is a bmp image, or false if not
	 */
	static bool isBMP(const char* p, size_t size);

	/**
	 * Load RGBA8888 data from image resource id, it will auto detect
	 * image file format
	 *
	 * @param resId resource id of image file
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadImage(int resId, float* w, float* h, bool sizeOnly);

	/**
	 * Load RGBA8888 data from an image's C file pointer, it will close file pointer when done. It
	 * will auto detect image file format
	 *
	 * @param f C FILE pointer
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadImage(FILE* f, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load RGBA8888 data from memory image data, it will auto detect image file format
	 *
	 * @param raw image file data in memory
	 * @param length \c data length
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadImage(const char* raw, size_t length, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load RGBA8888 data from assets or file system, it will auto detect image file format
	 *
	 * @param path image file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadImage(const char* path, bool isFile, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load RGBA8888 data from memory file system, it will auto detect image file format
	 *
	 * @param mfsName image file name in memory file system
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 */
	static char* loadImage(const char* mfsName, float* w, float* h, bool sizeOnly, float scaleX, float scaleY);

	/**
	 * Load raw data from a C file pointer, it will close file pointer when done
	 *
	 * @param f C file pointer
	 * @param outLen length of data finally returned
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return read data, caller should release it
	 */
	static char* loadRaw(FILE* f, size_t* outLen, bool noDecode = false);

	/**
	 * Load raw data from assets or file system
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param outLen optional, returns file length
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return raw data of file, caller should release it
	 */
	static char* loadRaw(const char* path, bool isFile, size_t* outLen = NULL, bool noDecode = false);

	/**
	 * Load raw data of a resource file
	 *
	 * @param resId resource id
	 * @param outLen optional, returns file length
	 * @param outScale optional, returns scale of resource
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return raw data, caller should release it
	 */
	static char* loadRaw(int resId, size_t* outLen = NULL, float* outScale = NULL, bool noDecode = false);

	/**
	 * load raw data from a memory file
	 *
	 * @param mfsName memory file name
	 * @param outLen optional, returns file length
	 * @param noDecode true means don't decode even if the data is encoded
	 * @return raw data, caller should release it. or NULL if loading failed
	 */
	static char* loadRaw(const char* mfsName, size_t* outLen = NULL, bool noDecode = false);

	/**
	 * Load a C string from resource id, null terminator is appended automatically.
	 * This resource must be a plain text resource.
	 *
	 * @param resId resource id
	 * @return raw data followed a null terminator so it is a C string. Caller should release it.
	 */
	static char* loadCString(int resId);

	/**
	 * Load a C string from assets or file system, null terminator is appended automatically.
	 * This file must be a plain text resource.
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @return raw data followed a null terminator so it is a C string. Caller should release it.
	 */
	static char* loadCString(const char* path, bool isFile);

	/**
	 * Get a C string froma a memory file. The memory file must be a C string content
	 * and this method doesn't validate it
	 *
	 * @param mfsName memory file name
	 * @return C string, and the caller should release it. Returns NULL if failed
	 */
	static char* loadCString(const char* mfsName);

	/**
	 * Get size of PVR image
	 *
	 * @param data PVR image data
	 * @param length \c data length
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 */
	static bool getPVRSize(const char* data, size_t length, float* w, float* h, float scale);

	/**
	 * Get size of PVR image
	 *
	 * @param resId resource id of PVR file
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param outScale returns scale of PVR resource, decided from resource density
	 * @return true means successful, or false if failed
	 */
	static bool getPVRSize(int resId, float* w, float* h, float* outScale);

	/**
	 * Get size of PVR image
	 *
	 * @param f C file pointer
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 */
	static bool getPVRSize(FILE* f, float* w, float* h, float scale);

	/**
	 * Get size of PVR image
	 *
	 * @param path file path
	 * @param isFile true indicating \c path is an absolute path in file system, false if \c path is a relative path under assets
	 * @param w returns width of PVR, NULL if you don't care
	 * @param h returns height of PVR, NULL if you don't care
	 * @param scale scale rate, 1 for no scale
	 * @return true means successful, or false if failed
	 */
	static bool getPVRSize(const char* path, bool isFile, float* w, float* h, float scale);
	
	/**
	 * Convert byte order of PVR header. It is little endian but we need host endian
	 *
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 */
	static void convertPVRHeaderEndian(wyPVRHeader* header);

	/**
	 * Unpack PVR data
	 *
	 * @param data PVR raw data
	 * @param header \link wyPVRHeader wyPVRHeader\endlink
	 * @param mipmapLens contains length of every mipmap
	 * @param pvrFormatIndex PVR file format index in gPVRFormats array
	 * @param hasAlpha returns flag about PVR alpha channel existence
	 * @return PVR data array for every mipmap
	 */
	static char** unpackPVRData(char* data, wyPVRHeader* header, int** mipmapLens, int* pvrFormatIndex, bool* hasAlpha);

	/**
	 * Scale PVR image
	 *
	 * @param format PVR file format
	 * @param originData image data
	 * @param originWidth width of image
	 * @param originHeight height of image
	 * @param scale scale rate
	 * @return scaled data
	 */
	static char* scalePVR(wyPVRFormat format, char* originData, int originWidth, int originHeight, float scale);

	/**
	 * Check whether a PVR image can be scaled by WiEngine
	 *
	 * @param format PVR format
	 * @return true means we can do that
	 */
	static bool canScalePVR(wyPVRFormat format);

	/**
	 * Scale an image
	 *
	 * @param originData original RGBA8888 data of image
	 * @param originWidth original width of image
	 * @param originHeight original height of image
	 * @param scaleX x scale, 1 for no x scale
	 * @param scaleY y scale, 1 for no y scale
	 * @return scaled data, may be same as \c originData if no scale, if not same, then caller should release originData
	 */
	static char* scaleImage(char* originData, int originWidth, int originHeight, float scaleX, float scaleY);

	/*
	 * Event related operations
	 */
	
	/**
	 * Convert point from Android coordinate system to OpenGL coordinate system
	 *
	 * @param p \link wyPoint wyPoint\endlink structure to be converted
	 */
	static void convertToGL(wyPoint* p);
	
	/**
	 * Convert point from Android coordinate system to OpenGL coordinate system
	 *
	 * @param x x position
	 * @param y y position
	 */
	static void convertToGL(float* x, float* y);

	/*
	 * time helper
	 */

	/**
	 * Get milliseconds from 1970-1-1
	 *
	 * @return milliseconds from 1970-1-1
	 */
	static int64_t currentTimeMillis();

	/*
	 * Array helper
	 */

	/**
	 * Swap two elements in a float array
	 *
	 * @param f pointer of float array
	 * @param index1 index of element 1
	 * @param index2 index of element 2
	 */
	static void swap(float* f, int index1, int index2);

	/**
	 * Swap two integers
	 *
	 * @param a pointer of integer 1
	 * @param b pointer of integer 2
	 */
	static void swap(int* a, int* b);

	/**
	 * Do a binary search in an integer array
	 *
	 * @param a pointer to integer array
	 * @param len length of array
	 * @param key number to be found
	 * @return if found, returns index, if not, returns a negative value whose absolute value minus 1 equals to
	 * 		insertion point
	 */
	static int binarySearch(int* a, size_t len, int key);

	/*
	 * encode/decode support
	 */

	/**
	 * Base64 encoder
	 *
	 * @param src source
	 * @param len length of \c src
	 * @param out_len returns length of encoded content
	 * @return data of encoded
	 */
	static char* encodeBase64(const char* src, size_t len, size_t* out_len);

	/**
	 * Decode base64 content
	 *
	 * @param enc data of encoded
	 * @param length length of \c enc
	 * @param retLen returns length of decoded content
	 * @return data of decoded
	 */
	static char* decodeBase64(const char* enc, size_t length, size_t* retLen);

	/**
	 * Unzip
	 *
	 * @param in data of zipped
	 * @param inLength length of \c in
	 * @param out hold bytes of unzipped content
	 * @return length of unzipped content
	 */
	static size_t gunzip(char* in, size_t inLength, char** out);

	/*
	 * string helper
	 */

	/**
	 * Replace a char with other char
	 *
	 * @param s string
	 * @param c char to be replaced
	 * @param sub char to be replaced to
	 * @return new string, caller should release it. returns NULL if \c s is NULL
	 */
	static const char* replaceChar(const char* s, char c, char sub);

	/**
	 * Read data until encounter new line or carriage return. \c data will point to next
	 * line when reading finished
	 *
	 * @param data pointer of data pointer, data encoding must be utf-8
	 * @param buf buffer to hold the line read, including new line or carriage return
	 * @return length of line, contains new line and carriage return character
	 */
	static int readLine(char** data, char* buf);

	/**
	 * Check whether a string starts with another string
	 *
	 * @param s string to check
	 * @param sub sub string
	 * @return true means \c s starts with \c sub
	 */
	static bool startsWith(const char* s, const char* sub);

	/**
	 * Check whether a string ends with another string
	 *
	 * @param s string to check
	 * @param sub sub string
	 * @return true means \c s ends with \c sub
	 */
	static bool endsWith(const char* s, const char* sub);

	/**
	 * Convert utf-16 string to utf-8 string
	 *
	 * @param s16 utf-16 string, can be NULL
	 * @return string in utf-8 encoding, or zero length string if \c s16 is NULL. caller should release it
	 */
	static const char* utf16toutf8(const char16_t* s16);

	/**
	 * Convert utf-16 char to utf-8 char
	 *
	 * @param c integer format of utf-32 char
	 * @return integer format of utf-8 char
	 */
	static int utf32toutf8(char32_t c);

	/**
	 * Convert a wide char string to utf-8 encoded string. However, wchar_t
	 * doesn't have same size in different platform.
	 *
	 * @param ws wide char string
	 * @return utf-8 encoded string, caller should release it
	 */
	static const char* wctoutf8(const wchar_t* ws);

	/**
	 * Convert utf-8 string to utf-16 string
	 *
	 * @param s8 utf-8 string
	 * @return utf-16 string, caller should release it
	 */
	static const char16_t* toUTF16(const char* s8);

	/**
	 * Get length of unicode string, in character
	 *
	 * @param str unicode string
	 * @return count of unicode character
	 */
	static size_t strlen16(const char16_t* str);

	/**
	 * Get length of utf-32 string, in character
	 *
	 * @param str utf-32 string
	 * @return count of unicode character
	 */
	static size_t strlen32(const char32_t* str);

	/**
	 * Get length of wide char string, in character
	 *
	 * @param ws wide char string
	 * @return count of character
	 */
	static size_t strlenW(const wchar_t* ws);

	/**
	 * Search a sub string in an unicode string
	 *
	 * @param str unicode string
	 * @param search utf-8 string
	 * @return if found, return start pointer, or returns NULL if not found
	 */
	static const char16_t* str16str(const char16_t* str, const char* search);

	/**
	 * Get count of utf-8 character in a string
	 *
	 * @param s utf-8 string
	 * @return count of utf-8 character
	 */
	static int strlen8(const char* s);

	/**
	 * Calculate how many bytes of a utf-8 encoded character
	 *
	 * @param c first byte of character in utf-8 encoding
	 * @return byte length of this character
	 */
	static int getUTF8Bytes(unsigned char c);

	/**
	 * Remove heading and tailing white spaces
	 *
	 * @param s input string, after trimming it becomes string without heading and tailing white spaces
	 * @return length after trimming
	 */
	static size_t trim(char* s);

	/**
	 * Check string is empty or not
	 *
	 * @param s string, can be NULL
	 * @return true means string is empty, false if not
	 */
	static bool isEmpty(char* s);

	/**
	 * Convert a string to lowercase, it only converts ASCII characters in string
	 *
	 * @param s string
	 */
	static void toLowercase(char* s);

	/**
	 * Replace character with another in a string
	 *
	 * @param s string
	 * @param from character need to be replaced
	 * @param to character will be replaced to
	 */
	static void replaceChar(char* s, char from, char to);

	/**
	 * Copy a string
	 *
	 * @param src source string
	 * @return copied string, caller should release it
	 */
	static const char* copy(const char* src);

	/**
	 * Copy a string
	 *
	 * @param src source string
	 * @param start start position to copy
	 * @param len length to copy
	 * @return copied string, caller should release it. returns NULL if \c src is NULL
	 */
	static const char* copy(const char* src, int start, size_t len);

	/**
	 * Copy a memory data
	 *
	 * @param data data pointer, caller should release it
	 * @param len length to copy
	 * @param copied data, caller should release it, returns NULL if \c data is NULL
	 */
	static const char* copyData(const char* data, size_t len);

	/**
	 * Calculate hash value of a string, using BKDR algorithm. It can not avoid conflict but result
	 * is acceptable
	 *
	 * @param str string
	 * @return hash value
	 */
	static unsigned int strHash(const char* str);

	/**
	 * Break lines for an utf-8 encoded string
	 *
	 * @param chars utf-8 encoded string
	 * @param provider provider of characters which can decide how wide a char is
	 * @param width line width in pixels, and zero means no limit
	 * @param spaceWidth space character width in pixels
	 * @param tabSize space count which one tab equals to
	 * @return a vector contains all lines, the caller should release every line and vector
	 */
	static vector<const char*>* breakLines(const char* chars, wyCharProvider* provider, float width, float spaceWidth, float tabSize);

	/*
	 * resolution helper
	 */

	/**
	 * Convert a DP value to pixel value
	 *
	 * @param dp DP value
	 * @return pixel value
	 */
	static float resolveDp(float dp);

	/**
	 * Convert a SP value to pixel value
	 *
	 * @param sp SP value
	 * @return pixel value
	 */
	static float resolveSp(float sp);

	/**
	 * Convert a pixel value to DP value
	 *
	 * @param px pixel value
	 * @return DP value
	 */
	static float resolvePx(float px);

	/**
	 * Treat field in a \link wyRect wyRect\endlink as DP value, convert them to pixel value
	 *
	 * @param rect \link wyRect wyRect\endlink
	 * @return \link wyRect wyRect\endlink converted
	 */
	static wyRect resolveRect(wyRect rect);

	/**
	 * Treat field in a \link wyPoint wyPoint\endlink as DP value, convert them to pixel value
	 *
	 * @param point \link wyPoint wyPoint\endlink
	 * @return \link wyPoint wyPoint\endlink converted
	 */
	static wyPoint resolvePoint(wyPoint point);
	
	/*
	 * system ui helper
	 */

	/**
	 * Show a confirm dialog and the dialog is backed by system, not Node
	 *
	 * @param title title text
	 * @param msg content text
	 * @param positiveButton text of positive button, default is NULL which means it is "OK"
	 * @param negativeButton text of negative button, default is NULL which means it is "Cancel"
	 * @param onOK callback when ok button is clicked
	 * @param onCancel callback when cancel button is clicked
	 */
	static void showSystemConfirmDialog(const char* title, const char* msg, const char* positiveButton = NULL, const char* negativeButton = NULL, wyTargetSelector* onOK = NULL, wyTargetSelector* onCancel = NULL);
    
    /**
	 * Show a alert dialog and the dialog is backed by system, not Node
	 *
	 * @param title title text
	 * @param msg content text
	 * @param positiveButton text of positive button, default is NULL which means it is "OK"
	 * @param onOK callback when ok button is clicked
	 */
	static void showSystemAlertDialog(const char* title, const char* msg, const char* positiveButton = NULL, wyTargetSelector* onOK = NULL);

	/*
	 * font helper
	 */

	/**
	 * Calculate bounding size of a string
	 *
	 * @param text string to be examined
	 * @param fontSize font size in pixel
	 * @param fontPath font file path in assets, or NULL if use system font
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width line width or zero means single line
	 * @return \link wySize wySize\endlink
	 */
	static wySize calculateTextSize(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0);

	/**
	 * Calculate bounding size of a string
	 *
	 * @param text string to be examined
	 * @param fontSize font size in pixel
	 * @param style font style
	 * @param fontName font name, or NULL if use system font
	 * @param width line width or zero means single line
	 * @return \link wySize wySize\endlink
	 */
	static wySize calculateTextSize(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width = 0);

	/**
	 * Create a bitmap for a string, in RGBA8888 format
	 *
	 * @param text string
	 * @param fontSize font size in pixel
	 * @param fontPath font file path in assets, or NULL if use system font
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * @return generated bitmap data, in RGBA8888 format, caller should release it
	 */
	static const char* createLabelBitmap(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * Create a bitmap for a string, in RGBA8888 format
	 *
	 * @param text string
	 * @param fontSize font size in pixel
	 * @param style font style
	 * @param fontName font name, or NULL if use system font
	 * @param width line width or zero means single line
	 * @param alignment text alignment, default is left
	 * @return generated bitmap data, in RGBA8888 format, caller should release it
	 */
	static const char* createLabelBitmap(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);
	
	/*
	 * opengl screenshot
	 */

	/**
	 * Grab current OpenGL frame, and save it as png or jpg image. This method save image to specified path and
	 * may be slow because file I/O involved. It uses glReadPixels API so lower version Android may not support
	 * it. It requires permission of writing external storage.
	 *
	 * @param path destination path of screenshot image, it will be created if it doesn't exist. If NULL, do nothing.
	 * 		The path will be mapped if not Android platform.  The extension of path determinate format of image
	 * 		generated. The extension can be png, jpg, jpeg.
	 */
	static void makeScreenshot(const char* path);

	/**
	 * Grab current OpenGL frame, and save it as png or jpg image. This method save image to specified path and
	 * may be slow because file I/O involved. It uses glReadPixels API so lower version Android may not support
	 * it. It requires permission of writing external storage.
	 *
	 * @param path destination path of screenshot image, it will be created if it doesn't exist. If NULL, do nothing.
	 * 		The path will be mapped if not Android platform.  The extension of path determinate format of image
	 * 		generated. The extension can be png, jpg, jpeg.
	 * @param rect screen rect to be shot
	 */
	static void makeScreenshot(const char* path, wyRect rect);

	/**
	 * file helper
	 */

	/**
	 * Calculate md5 of an file in file system. The md5 is calculated
	 * from file content but it depends on file size. If file size is
	 * smaller or equal than 60k, all file bytes is calculated. If larger than 60k,
	 * MD5 is calculated from head, middle and tail 20k bytes.
	 *
	 * @param path path of file in file system
	 * @return md5 hex string and caller should release it. Returns NULL if failed
	 */
	static const char* fileMd5(const char* path);

	/**
	 * Get file size
	 *
	 * @param f C file pointer
	 * @return byte length of file
	 */
	static size_t getFileSize(FILE* f);

	/**
	 * Get parent path of a path
	 *
	 * \note
	 * It doesn't map path, if input path is /sdcard/test, then returns /sdcard in all platforms
	 *
	 * @param path path string
	 * @return if \c path is NULL, returns NULL. If not NULL, return parent path. If \c path is root path,
	 * 		returns NULL. Caller should release returned path string
	 */
	static const char* getParentPath(const char* path);

	/**
	 * Check existence of a path
	 *
	 * \note
	 * Method will map path in iOS. Generally an absoluate path will be mapped to ~/Documents. So
	 * it ensure no code modification needed when port to iOS platform
	 *
	 * @param path path string
	 * @return true if path exists, or false if not. If \c path is NULL, returns true
	 */
	static bool isPathExistent(const char* path);

	/**
	 * Delete a file pointed by path, if path is a folder, do nothing
	 *
	 * \node
	 * Method will map path in iOS platform. Generally it will be mapped to ~/Documents so no need to
	 * modify code when porting
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 */
	static bool deleteFile(const char* path);

	/**
	 * For a path, create all intermediate folders
	 *
	 * \note
	 * Method will map path if not Android platform.
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 */
	static bool createIntermediateFolders(const char* path);

	/**
	 * Create a folder for a path, which doesn't create intermediate folders
	 *
	 * \note
	 * Method will map path if not Android platform.
	 *
	 * @param path path string
	 * @return true if successful, or false if failed
	 */
	static bool createFolder(const char* path);

	/**
	 * Delete last component in a path, for example:<br>
	 * Input					Output<br>
	 * "/tmp/scratch.tiff"      "/tmp"<br>
	 * "/tmp/scratch"           "/tmp"<br>
	 * "/tmp/"                  "/"<br>
	 * "scratch"                ""<br>
	 * "/" 						"/"<br>
	 *
	 * @param path path string
	 * @return path without last segment, caller should release returned path string
	 */
	static const char* deleteLastPathComponent(const char* path);

	/**
	 * Delete last path component in same string buffer
	 * 
	 * @param path path string
	 */
	static void deleteLastPathComponentInSameBuffer(char* path);

	/**
	 * Delete path extension of last path component
	 *
	 * @param path path string
	 * @return path after deleted extension, caller should release it
	 */
	static const char* deletePathExtension(const char* path);

	/**
	 * Delete path extension of last path component, in passed in \c path buffer
	 *
	 * @param path path string
	 */
	static void deletePathExtensionInSameBuffer(char* path);

	/**
	 * Append a path segment to another path, for example:<br>
	 * Input					Output<br>
	 * "/tmp", "/scratch.tiff"  "/tmp/scratch.tiff"<br>
	 * "/tmp//", "/scratch"     "/tmp/scratch"<br>
	 * "/tmp", "/"              "/tmp"<br>
	 * "/", "tmp/" 				"/tmp/"<br>
	 *
	 * @param path path string
	 * @param component segment to be added
	 * @return new path, caller should release returned path string
	 */
	static const char* appendPathComponent(const char* path, const char* component);

	/**
	 * Return last segment of a path, for example:<br>
	 * Input					Output<br>
	 * "/tmp/scratch.tiff"      "scratch.tiff"<br>
	 * "/tmp/scratch"           "scratch"<br>
	 * "/tmp/"                  "tmp"<br>
	 * "scratch"                "scratch"<br>
	 * "/" 						"/"<br>
	 *
	 * @param path path string
	 * @return last segment of \c path, caller should return returned string
	 */
	static const char* lastPathComponent(const char* path);

	/**
	 * Map an Android file system path to iOS. If current platform is Android, do nothing.
	 *
	 * @param path file path
	 * @preturn mapped path, caller should release returned path string
	 */
	static const char* mapLocalPath(const char* path);

	/**
	 * Map an Android assets path to iOS. If current platform is Android, do nothing.
	 *
	 * @param path path relative to assets
	 * @return mapped path, caller should release returned path string
	 */
	static const char* mapAssetsPath(const char* path);

	/**
	 * List all files, no matter file or directory, in an assets folder
	 *
	 * @param path relative path in assets folder
	 * @param outLen it returns the size of returned string array
	 * @param pattern file name pattern, or NULL if no pattern
	 * @return a file name array which should be released by caller
	 */
	static const char** listAssetFiles(const char* path, size_t* outLen, const char* pattern);

	/*
	 * thread helper
	 */

	/**
	 * Ensure something is executed in OpenGL thread, the logic is packed as
	 * a \link wyRunnable wyRunnable\endlink object
	 *
	 * @param runnable \link wyRunnable wyRunnable\endlink
	 */
	static void runOnGLThread(wyRunnable* runnable);

	/*
	 * video helper
	 */

	/**
	 * Play a video
	 *
	 * @param resId video resource id
	 */
	static void playVideo(int resId);

	/**
	 * Play a video
	 *
	 * @param path path of video
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 *		is a relative path under assets
	 */
	static void playVideo(const char* path, bool isFile = false);

	/*
	 * network helper
	 */

	/**
	 * Open an url, generally it will open a browser
	 *
	 * @param url url string
	 */
	static void openUrl(const char* url);

	/**
	 * add an android string file, e.g.string.xml. After the file is added,
	 * strings defined can be accessed through R.string.xxx
	 * 
	 * \note
     * This function takes no effect on android
	 
	 * @param fileName the file to be added. On windows, it should be a valid file path
	 * @param langId the identity of locale, for example, "en" means english, "zh" means chinese.
	 *
	 */
	static void addAndroidStrings(const char* fileName, const char* langId);

#if ANDROID
	/*
	 * jni helper, only for android
	 */

	/**
	 * Get a pionter of JNIEnv
	 *
	 * @return pointer of JNIEnv
	 */
	static JNIEnv* getJNIEnv();
#endif // #if ANDROID
};

#endif // __wyUtils_h__
