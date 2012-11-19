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
#ifndef __wyZwoptexLoader_h__
#define __wyZwoptexLoader_h__

#include "wySpriteFrame.h"
#include "wyTypes.h"

typedef unsigned char xmlChar;

// for code simplify
class wyZwoptexFrame;
#define WY_ZWOPTEXFRAME_MAP map<const char*, wyZwoptexFrame*, wyStrPredicate>
#define WY_ZWOPTEXFRAME_ITER WY_ZWOPTEXFRAME_MAP::iterator

/**
 * @class wyZwoptexFrame
 *
 * A frame in zwoptex atlas
 */
class WIENGINE_API wyZwoptexFrame : public wyObject {
public:
	/**
	 * frame name
	 */
	const char* key;

	/**
	 * Image rect in atlas, (x, y) is the top-left corner
	 */
	wyRect rect;

	/**
	 * Minimum rect contains all non-transparent data of an image
	 */
	wyRect sourceColorRect;

	/**
	 * The offset between orignal image center and atlas image center. If
	 * offset is positive then \c sourceColorRect center lies in rightside of
	 * original image center. Or leftside if negative.
	 */
	wyPoint offset;

	/**
	 * Original size of image
	 */
	wySize sourceSize;

	/**
	 * true indicating the image in atlas is rotated 90 degree clockwise.
	 * However, the \c rect is not rotated so you need convert it.
	 */
	bool rotated;

	wyZwoptexFrame();
	virtual ~wyZwoptexFrame();
};

/**
 * @class wyZwoptex
 *
 * A zwoptex object is a large texture manager who maps a bunch of rectangles to
 * the managed texture. Every rectangle is a frame image which could have name, size,
 * position, rotation, etc.
 */
class WIENGINE_API wyZwoptex : public wyObject {
private:
	/// version of zwoptex description file
	int m_format;

	/// pixel size of zwoptex texture
	wySize m_size;

	/// hash map of zwoptex frames
	WY_ZWOPTEXFRAME_MAP* m_frames;

	/// texture of zwoptex
	wyTexture2D* m_tex;

private:
	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);

	static wySize parseSize(const char* v, float resScale = 1.f);
	static wyPoint parsePoint(const char* v, float resScale = 1.f);
	static wyRect parseRect(const char* v, float resScale = 1.f);

private:
	/**
	 * 设置zwoptex文件格式
	 *
	 * @param format 文件格式版本id
	 */
	void setFormat(int format) { m_format = format; }

	/**
	 * 设置zwoptex图片的大小
	 *
	 * @param size \link wySize wySize\endlink
	 */
	void setSize(wySize size) { m_size = size; }

protected:
	void load(int resId);
	void load(const char* path, bool isFile, float inDensity);
	void load(const char* data, size_t length, float resScale);

public:
	/**
	 * Constructor
	 *
	 * @param resId resource id of zwoptex plist file. WiEngine will auto-scale it
	 * 		if adaption mode is density mode
	 */
	wyZwoptex(int resId);

	/**
	 * Constructor
	 *
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, or false
	 * 		means \c path is a relative path under assets
	 * @param inDensity input density of zwoptex description file
	 */
	wyZwoptex(const char* path, bool isFile = false, float inDensity = 0);

	virtual ~wyZwoptex();

	/**
	 * Get format of zwoptex plist file
	 *
	 * @return format id of plist file, can be 1 or larger
	 */
	int getFormat() { return m_format; }

	/**
	 * Get size of zwoptex atlas image
	 *
	 * @return size of zwoptex atlas image
	 */
	wySize getSize() { return m_size; }

	/**
	 * Add a frame to zwoptex
	 *
	 * @param frame \link wyZwoptexFrame wyZwoptexFrame\endlink
	 */
	void addFrame(wyZwoptexFrame* frame);

	/**
	 * Get a zwoptex frame by name
	 *
	 * @param key frame name
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 */
	wyZwoptexFrame* getFrame(const char* key);

	/**
	 * Get a \link wySpriteFrame wySpriteFrame\endlink by name. The frame returned
	 * doesn't have duration and texture so you must set it
	 *
	 * @param key frame name
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if frame is not found
	 */
	wySpriteFrame* getSpriteFrame(const char* key);

	/**
	 * Get frame rect by name
	 *
	 * @param key frame name
	 * @return \link wyRect wyRect\endlink
	 */
	wyRect getFrameRect(const char* key);

	/**
	 * Get all frame rect
	 *
	 * @param count returns count of frame rect
	 * @return frame rect buffer pointer, caller should release memory
	 */
	wyRect* getFrameRects(size_t* count);

	/**
	 * Get name list of all frames
	 *
	 * @param count when returns, it is the number of frames
	 * @return name list of all frames
	 */
	const char** getFrameNames(size_t* count);

	/**
	 * Get related texture object of this zwoptex
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	wyTexture2D* getTexture() { return m_tex; }

	/**
	 * Set zwoptex texture
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 */
	void setTexture(wyTexture2D* tex);

	/**
	 * Get count of frame
	 */
	int getFrameCount() { return m_frames->size(); }
};

#endif // __wyZwoptexLoader_h__
