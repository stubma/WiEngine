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
#ifndef __wyCustomColorFilter_h__
#define __wyCustomColorFilter_h__

#include "wyColorFilter.h"
#if ANDROID
	#include <jni.h>
#endif

/**
 * @typedef wyColorFilterDelegate
 *
 * \if English
 * Delegate of color filter apply method
 * \else
 * 滤镜的apply方法代理, 实现这个接口并配合\link wyCustomColorFilter wyCustomColorFilter\endlink使用可以
 * 使用自定义的方法处理图像数据.
 * \endif
 */
typedef struct wyColorFilterDelegate {
	/**
	 * \if English
	 * apply this color filter to some image data
	 *
	 * @param imageData raw data of image which must be RGBA8888 format, it holds transformed result when method returns
	 * @param width image pixel width, it is the original size before autoscaling
	 * @param height image pixel height, it is the original size before autoscaling
	 * @param userData extra user data pointer
	 * \else
	 * 对一个图像数据应用自定义的滤镜算法
	 *
	 * @param imageData 图像原始数据, 必须是RGBA8888格式, 方法完成后, data中的数据变成转换后的值.
	 * @param width 图像的像素宽度, 为未自动缩放前的大小
	 * @param height 图像的像素高度, 为未自动缩放前的大小
	 * @param userData 额外数据指针
	 * \endif
	 */
	void (*apply)(void* imageData, int width, int height, void* userData);
} wyColorFilterDelegate;

/**
 * @class wyCustomColorFilter
 *
 * \if English
 * Custom color filter, filter is implemented by setting a delegate
 * \else
 * 自定义的滤镜实现, 通过设置一个回调来让开发者实现滤镜方法
 * \endif
 */
class WIENGINE_API wyCustomColorFilter : public wyColorFilter {
private:
	/**
	 * \if English
	 * Delegate of color filter method
	 * \else
	 * 滤镜的重定向方法
	 * \endif
	 */
	wyColorFilterDelegate m_delegate;

	/**
	 * \if English
	 * User data pointer
	 * \else
	 * 额外用户数据指针
	 * \endif
	 */
	void* m_userData;

#if ANDROID
	/// java端delegate
	jobject m_jDelegate;
#endif

protected:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @param userData extra user data pointer
	 * \else
	 * 构造函数
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @param userData 额外用户数据指针
	 * \endif
	 */
	wyCustomColorFilter(wyColorFilterDelegate* delegate, void* userData);

public:
	virtual ~wyCustomColorFilter();

	/**
	 * \if English
	 * Static constructor
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @param userData extra user data pointer
	 * @return \link wyCustomColorFilter wyCustomColorFilter\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @param userData 额外用户数据指针
	 * @return \link wyCustomColorFilter wyCustomColorFilter\endlink
	 * \endif
	 */
	static wyCustomColorFilter* make(wyColorFilterDelegate* delegate, void* userData);

	/// @see wyColorFilter::apply
	virtual void apply(void* data, int width, int height);

	/**
	 * \if English
	 * Set delegate
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink
	 * @param data extra data pointer
	 * \else
	 * 设置代理
	 *
	 * @param delegate \link wyColorFilterDelegate wyColorFilterDelegate\endlink 结构指针
	 * @param data 附加数据指针
	 * \endif
	 */
	void setDelegate(wyColorFilterDelegate* delegate, void* data);

#if ANDROID
	/**
	 * 设置java端的代理
	 *
	 * @param delegate java端实现了代理接口的类
	 */
	void setDelegate(jobject delegate);
#endif
};

#endif // __wyCustomColorFilter_h__
