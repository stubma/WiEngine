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
#ifndef __wyMappingColorFilter_h__
#define __wyMappingColorFilter_h__

#include "wyColorFilter.h"

/**
 * @class wyMappingColorFilter
 *
 * \if English
 * This filter map a color to another color, so you can replace a color to another color easily.
 * This filter by default neglect alpha channel so alpha keep unchanged, but you can set flag to
 * change this behavior.
 *
 * \note
 * If an image will be auto scaled by WiEngine, don't worry about the result because color filter
 * is performed before scaling.
 * \else
 * 这个方法将某个颜色替换为其它颜色, 这样可以方便的修改图片的某色值. 当前前提是你必须知道要替换的色值. 这个
 * 滤镜缺省情况下不操作alpha值, 所以alpha值会保持不变, 但是你可以设置标志让它操作alpha值.
 *
 * \note
 * 不用担心图片自动缩放带来的问题, 因为颜色过滤是在缩放之前进行的, 因此它可以保证自动缩放不会影响滤镜效果.
 * \endif
 */
class WIENGINE_API wyMappingColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * map of colors
	 * \else
	 * 颜色映射表
	 * \endif
	 */
	void* m_colorMap;

	/**
	 * \if English
	 * Map entry count in color map
	 * \else
	 * \c m_colorMap中的映射项
	 * \endif
	 */
	int m_count;

	/**
	 * \if English
	 * Map capacity in color map
	 * \else
	 * \c m_colorMap的容量
	 * \endif
	 */
	int m_capacity;

protected:
	wyMappingColorFilter();

public:
	virtual ~wyMappingColorFilter();
	static wyMappingColorFilter* make();

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * \if English
	 * Define a color mapping
	 *
	 * @param from the color need to be changed, in argb format
	 * @param to destination color, in argb format
	 * @param fromMask mask of \c from color, it decides which part is compared and which part
	 * 		is kept. Default is 0x00ffffff so only rgb of \c from is compared with source color
	 * @param toMask mask of \c to color and it decides which part is copied to source. Default
	 * 		is 0x00ffffff so rgb of \c to is copied to source and alpha of source is kept.
	 * \else
	 * 定义一个颜色映射
	 *
	 * @param from 需要被替换的颜色
	 * @param to 需要被替换成的颜色
	 * @param fromMask 颜色的比较位的掩码, 用来决定颜色的哪些部分参与比较, 哪些部分保持不变. 缺省值是
	 * 		0x00ffffff, 这表示只比较源颜色和\c from的rgb值
	 * @param toMask \c to的掩码值, 表示了什么部分会被拷贝到颜色中, 而这个掩码的反码就是源颜色的保留部分.
	 * 		缺省值是0x00ffffff, 表示\c to的rgb部分会拷贝过去, 而源颜色的alpha值保持不变
	 * \endif
	 */
	void mapColor(int from, int to, int fromMask = 0x00ffffff, int toMask = 0x00ffffff);

	/**
	 * \if English
	 * Unmap a color
	 *
	 * @param from color need to be removed from map
	 * \else
	 * 取消一个颜色的映射
	 *
	 * @param from 需要被取消的颜色映射的原始色
	 * \endif
	 */
	void unmapColor(int from);
};

#endif // __wyMappingColorFilter_h__
