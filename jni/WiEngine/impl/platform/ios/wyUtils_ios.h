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
#ifndef __wyUtils_ios_h__
#define __wyUtils_ios_h__

#if IOS

#include "wyTypes.h"
#include "wyUtils.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @class wyUtils_ios
 *
 * \if English
 * Utilities only used in iOS platform
 * \else
 * 仅面向于iOS平台的工具方法
 * \endif
 */
class wyUtils_ios : public wyUtils {
public:
	/*
	 * resource helper
	 */

	/**
	 * \if English
	 * Get density of a iOS file
	 *
	 * @param fileName file name
	 * @return density of file
	 * \else
	 * 获得一个文件的Density
	 *
	 * @param fileName 文件名
	 * @return 文件的Density
	 * \endif
	 */
	static float getDensity(NSString* fileName);

	/**
	 * \if English
	 * Get scale modifier of an iOS resource file
	 *
	 * @param path path of iOS resource file
	 * @return scale modifier value, for example, @2x returns 2.
	 * \else
	 * 得到iOS中资源文件中的缩放标识数值
	 *
	 * @param path 路径
	 * @return 缩放标识数值, 比如如果包含@2x则返回2，如果不包含则返回1
	 * \endif
	 */
	static float getScaleModifier(NSString* path);

	/**
	 * \if English
	 * Get RGBA8888 data from UIImage object
	 *
	 * @param image UIImage object
	 * @param w hold final image width, this width is result of original width and scaleX. NULL means you don't care
	 * @param h hold final image height, this height is result of original height and scaleY. NULL means you don't care
	 * @param sizeOnly true indicating only get size, don't load data
	 * @param scaleX x scale, 1 for no scale
	 * @param scaleY y scale, 1 for no scale
	 * @return RGBA8888 data of image, if \c sizeOnly is true, returns NULL, caller should release returned data
	 * \else
	 * 从UIImage对象中生成适合于创建OpenGL贴图的数据
	 *
	 * @param image iOS的UIImage对象
	 * @param w 保存png图片像素宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片像素高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scaleX X缩放比例，为1表示不缩放
	 * @param scaleY Y缩放比例，为1表示不缩放
	 * @return 适合于创建OpenGL贴图的数据, 如果\c sizeOnly是true, 则返回NULL, 调用者需要负责释放返回的数据
	 * \endif
	 */
	static char* loadUIImage(UIImage* image, size_t* w, size_t* h, bool sizeOnly, float scaleX, float scaleY);

	/*
	 * type helper
	 */

	/**
	 * \if English
	 * Convert an Objective C string to utf-8 C string
	 *
	 * @param s Objective C string
	 * @return utf-8 C string, caller should release it
	 * \else
	 * 把一个ObjC字符串转换为utf-8编码的c字符串
	 *
	 * @param s Objective C字符串
	 * @return utf-8编码的c字符串, 调用者要负责释放内存
	 * \endif
	 */
	static const char* to_CString(NSString* s);

	/**
	 * \if English
	 * Convert an Objective C string to utf-8 C string and save it in a buffer
	 *
	 * @param buf a buffer to hold converted C string
	 * @param s Objective C string
	 * \else
	 * 把一个ObjC字符串转换为utf-8编码的c字符串
	 *
	 * @param buf 一个足够大的缓冲区(包含结尾的空字符), 由调用者分配, 也由调用者释放
	 * @param s Objective C字符串
	 * \endif
	 */
	static void to_CString(char* buf, NSString* s);

	/**
	 * \if English
	 * Convert a C string to an Objective C string
	 *
	 * @param text utf-8 string
	 * @return Objective C string object, already auto released
	 * \else
	 * 把一个c字符串转换为ObjC字符串
	 *
	 * @param text utf-8编码的c字符串
	 * @return ObjC字符串
	 * \endif
	 */
	static NSString* to_NSString(const char* text);
	
	/**
	 * \if English
	 * Find an UIViewController
	 * 
	 * @return UIViewController, or NULL if not found
	 * \else
	 * 找到一个可用的UIViewController
	 *
	 * @return UIViewController, 如果找不到, 返回NULL
	 * \endif
	 */
	static UIViewController* findViewController(UIView* view);
};

#endif // #if IOS

#endif // __wyUtils_ios_h__
