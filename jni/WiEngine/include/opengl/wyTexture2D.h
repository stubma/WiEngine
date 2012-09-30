/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyTexture2D_h__
#define __wyTexture2D_h__

#include <stdbool.h>
#include <stdint.h>
#include "wyObject.h"
#include "wyTypes.h"

class wyTextureManager;
class wyGrabber;
class wyGLTexture2D;
class wyColorFilter;

/**
 * @typedef wyTextureSource
 *
 * 贴图来源
 */
typedef enum {
	/// 无效的来源
	SOURCE_INVALID,

	/// BMP图片
	SOURCE_BMP,

	/// JPG图片
	SOURCE_JPG,

	/// PNG图片
	SOURCE_PNG,

	/// PVR图片
	SOURCE_PVR,

	/// 字符串
	SOURCE_LABEL,

	/// 来自OpenGL的贴图对象
	SOURCE_OPENGL,

	/// 来自已经展开的RGBA8888像素数据
	SOURCE_RAW
} wyTextureSource;

/**
 * @typedef wyTexturePixelFormat
 *
 * 贴图格式
 */
typedef enum {
	WY_TEXTURE_PIXEL_FORMAT_RGBA8888,
	WY_TEXTURE_PIXEL_FORMAT_RGB565,
	WY_TEXTURE_PIXEL_FORMAT_RGBA4444,
	WY_TEXTURE_PIXEL_FORMAT_RGBA5551,
	WY_TEXTURE_PIXEL_FORMAT_A8
} wyTexturePixelFormat;

/**
 * @class wyTexture2D
 *
 * 2D贴图对象的代理, 可以认为这是一个贴图的句柄, 它的作用是引用一个真正的贴图.<br>
 *
 * 贴图的管理是由WiEngine自动维护的, 每当上层调用wyTexture2D::makeXXX时, WiEngine会
 * 首先检查这个贴图是否存在, 如果存在, 则不会创建新的贴图, 而是返回同样的句柄. 句柄其实
 * 是一个整数, 它被包装在\link wyTexture2D wyTexture2D\endlink类中. 所以\link wyTexture2D wyTexture2D\endlink
 * 的实例可能不同, 但是它们都可能拥有同样的句柄, 也就指向同样的贴图. 而当\link wyTexture2D wyTexture2D\endlink
 * 被销毁时, 通常情况下并不意味着真实的贴图也被销毁了, 因为可能还有其它\link wyTexture2D wyTexture2D\endlink
 * 实例指向了真实的贴图.<br>
 *
 * 当然您也可以通过\link wyTextureManager wyTextureManager\endlink的方法删除贴图, 但是如果
 * 删除贴图后, 这个贴图又在某个地方被访问了, 则这个贴图会被重新载入. 这是WiEngine的自动管理
 * 机制, 它一方面可以让你手动控制贴图的释放以便及时释放内存, 同时又可以按需载入贴图以保证程序正常
 * 运行.<br>
 */
class WIENGINE_API wyTexture2D : public wyObject {
	friend class wyTextureManager;
	friend class wyGrabber;

public:
	/**
	 * \if English
	 * Text alignment of label node
	 * \else
	 * Label文字的对其方式
	 * \endif
	 */
	enum TextAlignment {
		/**
		 * \if English
		 * Left alignment
		 * \else
		 * 文字左对齐
		 * \endif
		 */
		LEFT,

		/**
		 * \if English
		 * center alignment
		 * \else
		 * 居中对齐
		 * \endif
		 */
		CENTER,

		/**
		 * \if English
		 * right alignment
		 * \else
		 * 右对齐
		 * \endif
		 */
		RIGHT
	};

private:
	/// 贴图句柄, 唯一的对应着一个真实的贴图对象. 小于0表示无效句柄.
	size_t m_handle;

	/// 贴图md5键值, \link wyTexture2D wyTexture2D\endlink不需要负责释放
	const char* m_md5;

	/// 贴图来源
	wyTextureSource m_source;

	/// label的文字
	const char* m_text;

	/// label的字体大小
	float m_fontSize;

	/// label的行宽
	float m_width;

	/// label的字体assets路径
	const char* m_fontPath;

	/**
	 * true means \c m_fontPath is an absolute path in file system, or false
	 * means \c m_fontPath is a path relative to assets
	 */
	bool m_isFile;

	/// label的字体样式
	wyFontStyle m_style;

	/// label的字体名称
	const char* m_fontName;

	/// text alignment
	TextAlignment m_alignment;

private:
	/**
	 * 设置OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 *
	 * @param tex OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 */
	void setTexture(int tex);

public:
	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(int resId);

	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(int resId, int transparentColor);

	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(int resId, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath BMP文件在assets下的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(const char* assetPath);

	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(const char* assetPath, int transparentColor);

	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明, 缺省是0即不指定透明色
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明, 缺省是0即不指定透明色
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从BMP文件创建贴图，BMP数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data BMP数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是bmp文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawBMP(const char* data, size_t length);

	/**
	 * 从BMP文件创建贴图，BMP数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data BMP数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是bmp文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawBMP(const char* data, size_t length, int transparentColor);

	/**
	 * 从BMP文件创建贴图，BMP数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data BMP数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是bmp文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从BMP文件创建贴图，BMP数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data BMP数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是bmp文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从BMP文件创建贴图，BMP文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName BMP文件在内存文件系统中的映射名称
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryBMP(const char* mfsName);

	/**
	 * 从BMP文件创建贴图，BMP文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName BMP文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryBMP(const char* mfsName, int transparentColor);

	/**
	 * 从BMP文件创建贴图，BMP文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName BMP文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从BMP文件创建贴图，BMP文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName BMP文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath BMP文件在文件系统中的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileBMP(const char* fsPath);

	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileBMP(const char* fsPath, int transparentColor);

	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(int resId);

	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(int resId, int transparentColor);

	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(int resId, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath JPG文件在assets下的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(const char* assetPath);

	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(const char* assetPath, int transparentColor);

	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从JPG文件创建贴图，JPG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data JPG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawJPG(const char* data, size_t length);

	/**
	 * 从JPG文件创建贴图，JPG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data JPG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawJPG(const char* data, size_t length, int transparentColor);

	/**
	 * 从JPG文件创建贴图，JPG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data JPG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从JPG文件创建贴图，JPG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data JPG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从JPG文件创建贴图，JPG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName JPG文件在内存文件系统中的映射名称
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryJPG(const char* mfsName);

	/**
	 * 从JPG文件创建贴图，JPG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName JPG文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryJPG(const char* mfsName, int transparentColor);

	/**
	 * 从JPG文件创建贴图，JPG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName JPG文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从JPG文件创建贴图，JPG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName JPG文件在内存文件系统中的映射名称
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param fsPath JPG文件在文件系统中的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileJPG(const char* fsPath);

	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param fsPath JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileJPG(const char* fsPath, int transparentColor);

	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param fsPath JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从PNG文件创建贴图，PNG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePNG(int resId);

	/**
	 * 从PNG文件创建贴图，PNG文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePNG(int resId, wyTexturePixelFormat format);

	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath PNG文件在assets下的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePNG(const char* assetPath);

	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath PNG文件在assets下的路径
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePNG(const char* assetPath, wyTexturePixelFormat format);

	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param assetPath PNG文件在assets下的路径
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePNG(const char* assetPath, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从PNG文件创建贴图，PNG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data PNG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawPNG(const char* data, size_t length);

	/**
	 * 从PNG文件创建贴图，PNG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data PNG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format);

	/**
	 * 从PNG文件创建贴图，PNG数据已经被载入内存中, 创建的贴图格式由format参数指定.
	 *
	 * @param data PNG数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是png文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从PNG文件创建贴图，PNG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName PNG文件在内存文件系统中的映射名称
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryPNG(const char* mfsName);

	/**
	 * 从PNG文件创建贴图，PNG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName PNG文件在内存文件系统中的映射名称
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format);

	/**
	 * 从PNG文件创建贴图，PNG文件通过内存文件系统名称指定, 创建的贴图格式由format参数指定.
	 *
	 * @param mfsName PNG文件在内存文件系统中的映射名称
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath PNG文件在文件系统中的路径
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFilePNG(const char* fsPath);

	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath PNG文件在文件系统中的路径
	 * @param format 贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFilePNG(const char* fsPath, wyTexturePixelFormat format);

	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param fsPath PNG文件在文件系统中的路径
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 为0表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFilePNG(const char* fsPath, wyTexturePixelFormat format, float inDensity);

	/**
	 * 从PVR文件创建贴图，PVR文件通过资源id指定
	 *
	 * @param resId 资源id
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePVR(int resId);

	/**
	 * 从PVR文件创建贴图，PVR文件通过assets路径指定
	 *
	 * @param assetPath PVR文件在assets下的路径
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makePVR(const char* assetPath, float inDensity = 0);

	/**
	 * 从PVR文件创建贴图，PVR数据已经被载入内存中
	 *
	 * @param data PVR数据数组, 这个数据会被底层复制，因此方法返回后调用者可以立刻释放该数据。这些数据必须是jpg文件的原始的未经解码的数据
	 * @param length 数据字节长度
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRawPVR(const char* data, size_t length, float inDensity = 0);

	/**
	 * 从PVR文件创建贴图，PVR文件通过内存文件系统名称指定
	 *
	 * @param mfsName PVR文件在内存文件系统中的映射名称
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemoryPVR(const char* mfsName, float inDensity = 0);

	/**
	 * 从PVR文件创建贴图，PVR文件通过文件系统路径指定
	 *
	 * @param fsPath PVR文件在文件系统中的路径
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过wyDirector::setDefaultInDensity指定
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFilePVR(const char* fsPath, float inDensity = 0);

	/**
	 * 通过一个字符串生成一个贴图
	 *
	 * @param text C字符串
	 * @param fontSize 字体大小，单位是px, 在传入时应该用resolveSp进行转换
	 * @param fontPath 自定义字体文件在assets中的路径，如果为NULL，则使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 最大行宽，为0表示不折行, 但是如果文字中包含换行或回车符, 则会自动成为多行
	 * @param alignment 文字对齐方式, 缺省为左对齐
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeLabel(const char* text, float fontSize, const char* fontPath = NULL, bool isFile = false, float width = 0, TextAlignment alignment = LEFT);

	/**
	 * 通过一个字符串生成一个贴图
	 *
	 * @param text C字符串
	 * @param fontSize 字体大小，单位是px, 在传入时应该用resolveSp进行转换
	 * @param style 字体样式
	 * @param fontName 字体名称，为NULL则使用系统缺省字体
	 * @param width 最大行宽，为0表示不折行, 但是如果文字中包含换行或回车符, 则会自动成为多行
	 * @param alignment 文字对齐方式, 缺省为左对齐
	 */
	static wyTexture2D* makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL, float width = 0, TextAlignment alignment = LEFT);

	/**
	 * 把一个已有的OpenGL贴图id包装成\link wyTexture2D wyTexture2D对象\endlink
	 *
	 * @param texture OpenGL贴图id
	 * @param w 贴图宽度
	 * @param h 贴图高度
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeGL(int texture, int w, int h);

	/**
	 * 根据已经展开的像素数据创建一个贴图。这里说的数据已经是RGBA8888格式。对于这种方式创建
	 * 的贴图，WiEngine不会再进行缩放.
	 *
	 * @param data 已经展开的像素数据, 这些数据会被底层复制，因此调用者可以在方法返回后立刻释放内存. 这些数据必须是RGBA8888格式, 数据的长度
	 * 			应该是宽乘以高乘以4. 调用者必须保证数据的完整性.
	 * @param width 数据所代表的图片的宽度
	 * @param height 数据所代表的图片的高度
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, int width, int height);

	/**
	 * 根据已经展开的像素数据创建一个贴图。这里说的数据已经是RGBA8888格式。对于这种方式创建
	 * 的贴图，WiEngine不会再进行缩放.
	 *
	 * @param data 已经展开的像素数据, 这些数据会被底层复制，因此调用者可以在方法返回后立刻释放内存. 这些数据必须是RGBA8888格式, 数据的长度
	 * 			应该是宽乘以高乘以4. 调用者必须保证数据的完整性.
	 * @param width 数据所代表的图片的宽度
	 * @param height 数据所代表的图片的高度
	 * @param format 期望生成的贴图格式
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, int width, int height, wyTexturePixelFormat format);

	/**
	 * 构造函数
	 */
	wyTexture2D();

	/**
	 * 析构函数
	 */
	virtual ~wyTexture2D();

	/**
	 * 确保贴图对象已经被载入，这个方法将把贴图对应的图象资源转换成OpenGL中的贴图对象
	 */
	void load();

	/**
	 * 设置显示的字符串内容
	 *
	 * @param text 显示内容的文字字符串
	 */
	void updateLabel(const char* text);

	/**
	 * 设置显示的字符串内容
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小
	 * @param fontPath 字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param lineWidth 行宽
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 */
	void updateLabel(const char* text, float fontSize, const char* fontPath = NULL, bool isFile = false, float lineWidth = 0, TextAlignment alignment = LEFT);

	/**
	 * 设置显示的字符串内容
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小
	 * @param style 字体样式
	 * @param fontName 字体
	 * @param lineWidth 行宽
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 */
	void updateLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL, float lineWidth = 0, TextAlignment alignment = LEFT);

	/**
	 * 设置贴图的反锯齿效果
	 *
	 * @param on true表示反锯齿，false表示不反锯齿
	 */
	void setAntiAlias(bool on);

	/**
	 * 设置贴图渲染时是否平铺。只能设置都平铺或者都不平铺，如果想要针对不同的方向做不同的设置，
	 * 请使用setParameters方法。缺省情况下是true。
	 *
	 * @param on true表示在水平和垂直方向都平铺，false表示都不平铺
	 */
	void setRepeat(bool on);

	/**
	 * 设置贴图参数，这是更为高级的设置方法，对于比较熟悉OpenGL贴图原理的开发者，可以直接使用
	 * 这个方法。对于不太熟悉的开发者，建议使用setAntiAlias和setRepeat这样的方法。
	 *
	 * @param min 缩小操作参数
	 * @param mag 放大操作参数
	 * @param wrapS 水平翻卷参数
	 * @param wrapT 垂直翻卷参数
	 */
	void setParameters(int min, int mag, int wrapS, int wrapT);

	/**
	 * 在OpenGL中设置贴图参数
	 */
	void applyParameters();

	/**
	 * 贴图是否是pre-multiplied alpha的。 注意：目前生成的贴图都不是pre-multiplied
	 * alpha的，因此总是返回false
	 *
	 * @return true表示是，false表示不是
	 */
	bool hasPremultipliedAlpha();

	/**
	 * 在指定位置绘制贴图，贴图区域为整个贴图大小，图片大小为原始大小
	 *
	 * @param x x位置, 左下角
	 * @param y y位置, 左下角
	 */
	void draw(float x, float y);

	/**
	 * 在指定位置绘制贴图，贴图区域为整个贴图大小，图片大小为原始大小
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 */
	void draw(float x, float y, bool flipX, bool flipY);

	/**
	 * 在指定位置绘制贴图，贴图区域为整个贴图大小，图片大小由参数width，height指定
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 宽度，单位像素
	 * @param height 高度，单位像素
	 */
	void draw(float x, float y, float width, float height);

	/**
	 * 在指定位置绘制贴图，贴图区域为整个贴图大小，图片大小由参数width，height指定
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 宽度，单位像素
	 * @param height 高度，单位像素
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 */
	void draw(float x, float y, float width, float height, bool flipX, bool flipY);

	/**
	 * 在指定位置绘制贴图，贴图区域由参数texRect指定，图片大小由参数width，height指定
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 宽度，单位像素
	 * @param height 高度，单位像素
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 * @param texRect 贴图区域
	 */
	void draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect);

	/**
	 * 在指定位置绘制贴图，贴图区域由参数texRect指定，图片大小由参数width，height指定
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 宽度，单位像素
	 * @param height 高度，单位像素
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 * @param texRect 贴图区域
	 * @param rotatedZwoptex true表示绘制的是一个Zwoptex帧，且该帧在图片集中被顺时针旋转了90度
	 */
	void draw(float x, float y, float width, float height, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex);

	/**
	 * 在指定位置绘制贴图，贴图区域由参数texRect指定，图片大小由参数width，height指定
	 *
	 * @param x x位置
	 * @param y y位置
	 * @param width 宽度，单位像素
	 * @param height 高度，单位像素
	 * @param sourceWidth 图片的原始宽度
	 * @param sourceHeight 图片的原始高度
	 * @param flipX true表示渲染时要在x方向翻转图片
	 * @param flipY true表示渲染时要在y方向翻转图片
	 * @param texRect 贴图区域
	 * @param rotatedZwoptex true表示绘制的是一个Zwoptex帧，且该帧在图片集中被顺时针旋转了90度
	 */
	void draw(float x, float y, float width, float height, float sourceWidth, float sourceHeight, bool flipX, bool flipY, wyRect texRect, bool rotatedZwoptex);

	/**
	 * 得到原始图片的宽度
	 *
	 * @return 原始图片的宽度
	 */
	float getWidth();

	/**
	 * 得到原始图片的高度
	 *
	 * @return 原始图片的高度
	 */
	float getHeight();

	/**
	 * 得到贴图实际宽度
	 *
	 * @return 贴图实际宽度
	 */
	int getPixelWidth();

	/**
	 * 得到贴图实际高度
	 *
	 * @return 贴图实际高度
	 */
	int getPixelHeight();

	/**
	 * 得到原始图片和贴图实际大小的宽度比例
	 *
	 * @return 宽度比例
	 */
	float getWidthScale();

	/**
	 * 得到原始图片和贴图实际大小的高度比例
	 *
	 * @return 高度比例
	 */
	float getHeightScale();

	/**
	 * 得到OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 *
	 * @return OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 */
	int getTexture();

	/**
	 * 得到标签类型贴图显示的字符串内容
	 *
	 * @return 标签类型贴图显示的字符串内容
	 */
	const char* getText();

	/**
	 * 得到贴图类型
	 *
	 * @return 贴图类型
	 */
	wyTextureSource getSource();

	/**
	 * 得到是否以X轴为转动轴翻转图片
	 *
	 * @return 是否以X轴为转动轴翻转图片
	 */
	bool isFlipY();

	/**
	 * 得到是否以Y轴为转动轴翻转图片
	 *
	 * @return 是否以Y轴为转动轴翻转图片
	 */
	bool isFlipX();

	/**
	 * 设置是否以y轴为转动轴翻转图片
	 *
	 * @param flipX 是否以y轴为转动轴翻转图片,true为翻转
	 */
	void setFlipX(bool flipX);

	/**
	 * 设置是否以x轴为转动轴翻转图片
	 *
	 * @param flipY 是否以x轴为转动轴翻转图片,true为翻转
	 */
	void setFlipY(bool flipY);

	/**
	 * 通过原始像素数据更新贴图内容
	 *
	 * @param raw 像素数据，这些数据的格式必须是RGBA8888格式，其长度必须符合当前贴图有效大小.
	 * 		调用者要负责释放该数据.
	 */
	void updateRaw(const char* raw);

	/**
	 * \if English
	 * set color filter. texture has many sources and it doesn't support label or opengl or pvr source. color filter
	 * won't be called when set until you call \c applyFilter. However, \c applyFilter will be automatically
	 * called when texture is loading.
	 *
	 * @param filter subclass of \link wyColorFilter wyColorFilter\endlink, or NULL if you want to
	 * 		remove filter
	 * \else
	 * 设置颜色过滤器, 贴图本身有一个来源标示其类型, 对于标签或opengl或pvr来源的贴图暂时不支持颜色过滤器. 在调用\c setColorFilter
	 * 的时候, 过滤器并不会立刻起作用. 想要过滤器发生效果需要调用\c applyFilter. 但是如果贴图正在被载入, 则\c applyFilter
	 * 会被自动调用.
	 *
	 * @param filter \link wyColorFilter wyColorFilter\endlink的子类, 或者NULL表示删除当前的过滤器
	 * \endif
	 */
	void setColorFilter(wyColorFilter* filter);

	/**
	 * \if English
	 * if current color filter is not NULL, apply this filter to texture. that will cause
	 * texture changed immediately.
	 * \else
	 * 如果当前的颜色过滤器不为空, 则应用这个过滤器, 这会导致OpenGL贴图立刻发生变化
	 * \endif
	 */
	void applyFilter();

	/**
	 * \if English
	 * Clone a texture. After returns, this object will point to a new OpenGL texture
	 * object. Every cloned texture should have a clone id to unique identify itself.
	 * If current proxy already points a cloned texture, then source texture will be cloned
	 *
	 * @param cloneId clone id
	 * @param proxy of cloned texture, NULL if clone is failed
	 * \else
	 * 克隆该贴图. 方法返回后, 该对象会指向一个新的OpenGL贴图对象. 每个克隆的贴图都有一个克隆id来
	 * 进行唯一的标识. 如果当前的贴图代理指向的已经是一个克隆贴图, 则该方法会克隆源贴图.
	 *
	 * @param cloneId 克隆id
	 * @return 克隆贴图代理对象, 如果克隆失败, 返回NULL
	 * \endif
	 */
	wyTexture2D* clone(int cloneId);

	/**
	 * \if English
	 * Change this proxy texture to a cloned texture proxy. Cloned texture proxy can
	 * not be created directly so you should call this method to switch a proxy to a
	 * cloned proxy. If clone id not found, do nothing
	 *
	 * @param cloneId clone id
	 * \else
	 * 把当前的贴图代理对象定位到某个克隆贴图对象上. 这是因为克隆贴图代理不能直接被创建, 只能先
	 * 创建原始贴图代理, 再调用这个方法重新定位. 如果指定的克隆id没有找到, 则该方法无效果
	 *
	 * @param cloneId 克隆贴图id
	 * \endif
	 */
	void switchToClone(int cloneId);
};

#endif // __wyTexture2D_h__
