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
#ifndef __wyAreaColorFilter_h__
#define __wyAreaColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyAreaColorFilter
 *
 * \if English
 * Map color at some area to other color. The area shape can be point, line, rectangle, circle
 * \else
 * 对某些区域的颜色进行映射. 这些区域可以是点, 线, 矩形, 多边形等形状
 * \endif
 */
class WIENGINE_API wyAreaColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * buffer holds mapping info
	 * \else
	 * 保存颜色映射信息的缓冲区
	 * \endif
	 */
	void* m_mapBuffer;

	/**
	 * \if English
	 * Map entry count in color map
	 * \else
	 * \c m_mapBuffer中的映射项
	 * \endif
	 */
	int m_count;

	/**
	 * \if English
	 * Map capacity in color map
	 * \else
	 * \c m_mapBuffer的容量
	 * \endif
	 */
	int m_capacity;

private:
	/**
	 * \if English
	 * Ensure buffer size is enough
	 * \else
	 * 确保缓冲区大小足够
	 * \endif
	 */
	void ensureCapacity();

protected:
	wyAreaColorFilter();

public:
	virtual ~wyAreaColorFilter();
	static wyAreaColorFilter* make();

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * \if English
	 * Map color at a point to other color
	 *
	 * @param x the x position, uses top-left corner of image as origin
	 * @param y the y position, uses top-left corner of image as origin
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 * \else
	 * 替换一个位置上的颜色
	 *
	 * @param x 需要映射的x位置, 原点是图片的左上角
	 * @param y 需要映射的y位置, 原点是图片的左上角
	 * @param from 需要映射的源颜色, 格式是0xaarrggbb
	 * @param to 需要映射到的颜色, 格式是0xaarrggbb
	 * @param fromMask 颜色的比较位的掩码, 用来决定颜色的哪些部分参与比较, 哪些部分保持不变. 缺省值是
	 * 		0x00ffffff, 这表示只比较源颜色和\c from的rgb值
	 * @param toMask \c to的掩码值, 表示了什么部分会被拷贝到颜色中, 而这个掩码的反码就是源颜色的保留部分.
	 * 		缺省值是0x00ffffff, 表示\c to的rgb部分会拷贝过去, 而源颜色的alpha值保持不变
	 * \endif
	 */
	void mapPoint(int x, int y, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * \if English
	 * Remove a position mapping
	 *
	 * @param x the x position, uses top-left corner of image as origin
	 * @param y the y position, uses top-left corner of image as origin
	 * \else
	 * 删除一个点的颜色映射
	 *
	 * @param x 需要删除映射的x位置, 原点是图片的左上角
	 * @param y 需要删除映射的y位置, 原点是图片的左上角
	 * \endif
	 */
	void removePoint(int x, int y);

	/**
	 * \if English
	 * Map colors at a line to other color
	 *
	 * @param x1 start x position, uses top-left corner of image as origin
	 * @param y1 start y position, uses top-left corner of image as origin
	 * @param x2 end x position, uses top-left corner of image as origin
	 * @param y2 end y position, uses top-left corner of image as origin
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 * \else
	 * 替换一个位置上的颜色
	 *
	 * @param x1 线的起始x位置, 原点是图片的左上角
	 * @param y1 线的起始y位置, 原点是图片的左上角
	 * @param x2 线的结束x位置, 原点是图片的左上角
	 * @param y2 线的结束y位置, 原点是图片的左上角
	 * @param from 需要映射的源颜色, 格式是0xaarrggbb
	 * @param to 需要映射到的颜色, 格式是0xaarrggbb
	 * @param fromMask 颜色的比较位的掩码, 用来决定颜色的哪些部分参与比较, 哪些部分保持不变. 缺省值是
	 * 		0x00ffffff, 这表示只比较源颜色和\c from的rgb值
	 * @param toMask \c to的掩码值, 表示了什么部分会被拷贝到颜色中, 而这个掩码的反码就是源颜色的保留部分.
	 * 		缺省值是0x00ffffff, 表示\c to的rgb部分会拷贝过去, 而源颜色的alpha值保持不变
	 * \endif
	 */
	void mapLine(int x1, int y1, int x2, int y2, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * \if English
	 * Remove a line mapping
	 *
	 * @param x1 start x position, uses top-left corner of image as origin
	 * @param y1 start y position, uses top-left corner of image as origin
	 * @param x2 end x position, uses top-left corner of image as origin
	 * @param y2 end y position, uses top-left corner of image as origin
	 * \else
	 * 删除一条线的颜色映射
	 *
	 * @param x1 线的起始x位置, 原点是图片的左上角
	 * @param y1 线的起始y位置, 原点是图片的左上角
	 * @param x2 线的结束x位置, 原点是图片的左上角
	 * @param y2 线的结束y位置, 原点是图片的左上角
	 * \endif
	 */
	void removeLine(int x1, int y1, int x2, int y2);

	/**
	 * \if English
	 * Map colors in a rectangle to other color
	 *
	 * @param x rect top-left x position, origin is top-left of image
	 * @param y rect top-left y position, origin is top-left of image
	 * @param w rect width
	 * @param h rect height
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 * \else
	 * 替换一个位置上的颜色
	 *
	 * @param x 矩形的左上角x位置, 原点是图片的左上角
	 * @param y 矩形的左上角y位置, 原点是图片的左上角
	 * @param w 矩形宽度
	 * @param h 矩形高度
	 * @param from 需要映射的源颜色, 格式是0xaarrggbb
	 * @param to 需要映射到的颜色, 格式是0xaarrggbb
	 * @param fromMask 颜色的比较位的掩码, 用来决定颜色的哪些部分参与比较, 哪些部分保持不变. 缺省值是
	 * 		0x00ffffff, 这表示只比较源颜色和\c from的rgb值
	 * @param toMask \c to的掩码值, 表示了什么部分会被拷贝到颜色中, 而这个掩码的反码就是源颜色的保留部分.
	 * 		缺省值是0x00ffffff, 表示\c to的rgb部分会拷贝过去, 而源颜色的alpha值保持不变
	 * \endif
	 */
	void mapRect(int x, int y, int w, int h, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * \if English
	 * Remove a rectangle mapping
	 *
	 * @param x rect top-left x position, origin is top-left of image
	 * @param y rect top-left y position, origin is top-left of image
	 * @param w rect width
	 * @param h rect height
	 * \else
	 * 删除一个矩形上的颜色映射
	 *
	 * @param x 矩形的左上角x位置, 原点是图片的左上角
	 * @param y 矩形的左上角y位置, 原点是图片的左上角
	 * @param w 矩形宽度
	 * @param h 矩形高度
	 * \endif
	 */
	void removeRect(int x, int y, int w, int h);

	/**
	 * \if English
	 * Map colors in a circle to other color
	 *
	 * @param centerX center of circle, origin is top-left of image
	 * @param centerY centerY of circle, origin is top-left of image
	 * @param radius circle radius
	 * @param from source color to be matched
	 * @param to destination color to be replaced to
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 * \else
	 * 替换一个位置上的颜色
	 *
	 * @param centerX 圆形的中心点x位置, 原点是图片的左上角
	 * @param centerY 圆形的中心点y位置, 原点是图片的左上角
	 * @param radius 圆形半径
	 * @param from 需要映射的源颜色, 格式是0xaarrggbb
	 * @param to 需要映射到的颜色, 格式是0xaarrggbb
	 * @param fromMask 颜色的比较位的掩码, 用来决定颜色的哪些部分参与比较, 哪些部分保持不变. 缺省值是
	 * 		0x00ffffff, 这表示只比较源颜色和\c from的rgb值
	 * @param toMask \c to的掩码值, 表示了什么部分会被拷贝到颜色中, 而这个掩码的反码就是源颜色的保留部分.
	 * 		缺省值是0x00ffffff, 表示\c to的rgb部分会拷贝过去, 而源颜色的alpha值保持不变
	 * \endif
	 */
	void mapCircle(int centerX, int centerY, int radius, int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * \if English
	 * Remove a circle mapping
	 *
	 * @param centerX center of circle, origin is top-left of image
	 * @param centerY centerY of circle, origin is top-left of image
	 * @param radius circle radius
	 * \else
	 * 删除一个圆形上的颜色映射
	 *
	 * @param centerX 圆形的中心点x位置, 原点是图片的左上角
	 * @param centerY 圆形的中心点y位置, 原点是图片的左上角
	 * @param radius 圆形半径
	 * \endif
	 */
	void removeCircle(int centerX, int centerY, int radius);
};

#endif // __wyAreaColorFilter_h__
