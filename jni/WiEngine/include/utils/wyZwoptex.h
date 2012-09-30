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
 * \if English
 * A frame in zwoptex atlas
 * \else
 * 表示Zwoptex图片集中的一帧
 * \endif
 */
class WIENGINE_API wyZwoptexFrame : public wyObject {
public:
	/**
	 * \if English
	 * frame name
	 * \else
	 * 帧名称
	 * \endif
	 */
	const char* key;

	/**
	 * \if English
	 * Image rect in atlas, (x, y) is the top-left corner
	 * \else
	 * 图片在图片集中的矩形
	 * \endif
	 */
	wyRect rect;

	/**
	 * \if English
	 * Minimum rect contains all non-transparent data of an image
	 * \else
	 * 图片不透明区域的最小矩形
	 * \endif
	 */
	wyRect sourceColorRect;

	/**
	 * \if English
	 * The offset between orignal image center and atlas image center. If
	 * offset is positive then \c sourceColorRect center lies in rightside of
	 * original image center. Or leftside if negative.
	 * \else
	 * 原始图片的中心和图片在图片集中的矩形的中心偏移。如果偏移的x是正值，则表示
	 * sourceColorRect的中心在原始图片中心的右边。如果偏移的y是正值，则表示sourceColorRect
	 * 的中心在原始图片中心的上边。
	 * \endif
	 */
	wyPoint offset;

	/**
	 * \if English
	 * Original size of image
	 * \else
	 * 图片的原始大小
	 * \endif
	 */
	wySize sourceSize;

	/**
	 * \if English
	 * true indicating the image in atlas is rotated 90 degree clockwise.
	 * However, the \c rect is not rotated so you need convert it.
	 * \else
	 * 图片在图片集中是否顺时针旋转了90度, 一个图片如果旋转了，它在
	 * Zwoptex中的矩形还是没有旋转的矩形，所以需要转换矩形坐标
	 * \endif
	 */
	bool rotated;

	wyZwoptexFrame();
	virtual ~wyZwoptexFrame();
};

/**
 * @class wyZwoptex
 *
 * \if English
 * A zwoptex object is a large texture manager who maps a bunch of rectangles to
 * the managed texture. Every rectangle is a frame image which could have name, size,
 * position, rotation, etc.
 * \else
 * Zwoptex对象是一个单一大贴图管理者, 它维护了一个矩形和名称的映射表, 每个矩形都代表了大贴图中的
 * 一个区域, 代表了一个小贴图. 这个小贴图有名字, 大小, 位置, 是否旋转等关联信息.
 * \endif
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
	 * \if English
	 * Constructor
	 *
	 * @param resId resource id of zwoptex plist file. WiEngine will auto-scale it
	 * 		if adaption mode is density mode
	 * \else
	 * 构造函数
	 *
	 * @param resId zwoptex描述文件的资源id. 如果当前适配模式是密度模式, WiEngine会根据描述文
	 * 		件存放的位置对其中的坐标进行适当的适配。例如：假如描述文件存放在raw-hdpi目录下，但是
	 * 		当前机器是mdpi屏幕，则描述文件中的坐标会被除以1.5, 如果当前机器是hdpi屏幕，则描述文件
	 * 		中的坐标不会有变化。
	 * \endif
	 */
	wyZwoptex(int resId);

	/**
	 * \if English
	 * Constructor
	 *
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, or false
	 * 		means \c path is a relative path under assets
	 * @param inDensity input density of zwoptex description file
	 * \else
	 * 构造函数
	 *
	 * @param path zwoptex描述文件的路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个assets下的相对路径
	 * @param inDensity 密度值, 缺省为0, 表示使用系统缺省的输入密度, 修改系统缺省的输入密度可以通过
	 * 		设置\c wyDevice::defaultInDensity
	 * \endif
	 */
	wyZwoptex(const char* path, bool isFile = false, float inDensity = 0);

	virtual ~wyZwoptex();

	/**
	 * \if English
	 * Get format of zwoptex plist file
	 *
	 * @return format id of plist file, can be 1 or larger
	 * \else
	 * 得到zwoptex描述文件格式
	 *
	 * @return 描述文件格式
	 * \endif
	 */
	int getFormat() { return m_format; }

	/**
	 * \if English
	 * Get size of zwoptex atlas image
	 *
	 * @return size of zwoptex atlas image
	 * \else
	 * 得到zwoptex图片的大小
	 *
	 * @return zwoptex图片的大小
	 * \endif
	 */
	wySize getSize() { return m_size; }

	/**
	 * \if English
	 * Add a frame to zwoptex
	 *
	 * @param frame \link wyZwoptexFrame wyZwoptexFrame\endlink
	 * \else
	 * 手动加入一个帧
	 *
	 * @param frame \link wyZwoptexFrame wyZwoptexFrame\endlink
	 * \endif
	 */
	void addFrame(wyZwoptexFrame* frame);

	/**
	 * \if English
	 * Get a zwoptex frame by name
	 *
	 * @param key frame name
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 * \else
	 * 根据名称查找一个zwoptex帧
	 *
	 * @param key 帧名称
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	wyZwoptexFrame* getFrame(const char* key);

	/**
	 * \if English
	 * Get a \link wySpriteFrame wySpriteFrame\endlink by name. The frame returned
	 * doesn't have duration and texture so you must set it
	 *
	 * @param key frame name
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if frame is not found
	 * \else
	 * 根据名称查找一个帧, 并转换它为\link wySpriteFrame wySpriteFrame\endlink 对象. 转换得到
	 * 的\link wySpriteFrame wySpriteFrame\endlink 对象的持续时间是0, 贴图是NULL, 因为
	 * \link wyZwoptexFrame wyZwoptexFrame\endlink 没有这些信息
	 *
	 * @param key 帧名称
	 * @return \link wySpriteFrame wySpriteFrame\endlink 对象, 如果没有找到, 返回NULL
	 * \endif
	 */
	wySpriteFrame* getSpriteFrame(const char* key);

	/**
	 * \if English
	 * Get frame rect by name
	 *
	 * @param key frame name
	 * @return \link wyRect wyRect\endlink
	 * \else
	 * 根据名称得到某个帧的矩形
	 *
	 * @param key 帧名称
	 * @return \link wyRect wyRect\endlink
	 * \endif
	 */
	wyRect getFrameRect(const char* key);

	/**
	 * \if English
	 * Get all frame rect
	 *
	 * @param count returns count of frame rect
	 * @return frame rect buffer pointer, caller should release memory
	 * \else
	 * 得到所有的帧矩形
	 *
	 * @param count 返回矩形个数
	 * @return 矩形缓冲区, 调用者要负责释放
	 * \endif
	 */
	wyRect* getFrameRects(size_t* count);

	/**
	 * \if English
	 * Get name list of all frames
	 *
	 * @param count when returns, it is the number of frames
	 * @return name list of all frames
	 * \else
	 * 得到所有frame名称的列表
	 *
	 * @param count 返回frame个数
	 * @return 所有frame名称的指针数组
	 * \endif
	 */
	const char** getFrameNames(size_t* count);

	/**
	 * \if English
	 * Get related texture object of this zwoptex
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 得到zwoptex关联的贴图对象
	 *
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	wyTexture2D* getTexture() { return m_tex; }

	/**
	 * \if English
	 * Set zwoptex texture
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 设置与zwoptex关联的贴图对象
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	void setTexture(wyTexture2D* tex);

	/**
	 * \if English
	 * Get count of frame
	 * \else
	 * 得到这个zwoptex里的帧数
	 * \endif
	 */
	int getFrameCount() { return m_frames->size(); }
};

#endif // __wyZwoptexLoader_h__
