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
#ifndef __wyTexture2D_h__
#define __wyTexture2D_h__

#include <stdbool.h>
#include <stdint.h>
#include "wyObject.h"
#include "wyTypes.h"

class wyTextureManager;
class wyFrameBuffer;
class wyGLTexture2D;
class wyColorFilter;

/**
 * texture source type
 */
typedef enum {
	/// invalid
	SOURCE_INVALID,

	/// normal image
	SOURCE_IMG,

	/// label
	SOURCE_LABEL,

	/// opengl texture
	SOURCE_OPENGL,

	/// rgba8888 data
	SOURCE_RAW8888
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
	friend class wyFrameBuffer;

public:
	/**
	 * Text alignment of label node
	 */
	enum TextAlignment {
		/**
		 * Left alignment
		 */
		LEFT,

		/**
		 * center alignment
		 */
		CENTER,

		/**
		 * right alignment
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
	 * Create texture from image file which is specified by resource id.
	 * It will auto detect image file format.
	 *
	 * @param resId resource id
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(int resId);

	/**
	 * Create texture from image file which is specified by resource id.
	 * It will auto detect image file format.
	 *
	 * @param resId resource id
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(int resId, int transparentColor);

	/**
	 * Create texture from image file which is specified by resource id.
	 * It will auto detect image file format.
	 *
	 * @param resId resource id
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(int resId, int transparentColor, wyTexturePixelFormat format);

	/**
	 * Create texture from an image file which is specified by assets relative path. It
	 * will auto detect image file format
	 *
	 * @param assetPath relative path of image file in assets
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(const char* assetPath);

	/**
	 * Create texture from an image file which is specified by assets relative path. It
	 * will auto detect image file format
	 *
	 * @param assetPath relative path of image file in assets
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(const char* assetPath, int transparentColor);

	/**
	 * Create texture from an image file which is specified by assets relative path. It
	 * will auto detect image file format
	 *
	 * @param assetPath relative path of image file in assets
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(const char* assetPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * Create texture from an image file which is specified by assets relative path. It
	 * will auto detect image file format
	 *
	 * @param assetPath relative path of image file in assets
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting.
	 * 		By default, density is 1 and can be changed by setting wyDevice::defaultInDensity value
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* make(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * Create texture from image raw data. It will auto detect image file format. "raw" means
	 * the data is directly read from image file without any processing.
	 *
	 * @param data image raw data pointer. the data will be copied so it is safe to release it
	 * 		after method returns
	 * @param length raw data length in bytes
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, size_t length);

	/**
	 * Create texture from image raw data. It will auto detect image file format. "raw" means
	 * the data is directly read from image file without any processing.
	 *
	 * @param data image raw data pointer. the data will be copied so it is safe to release it
	 * 		after method returns
	 * @param length raw data length in bytes
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, size_t length, int transparentColor);

	/**
	 * Create texture from image raw data. It will auto detect image file format. "raw" means
	 * the data is directly read from image file without any processing.
	 *
	 * @param data image raw data pointer. the data will be copied so it is safe to release it
	 * 		after method returns
	 * @param length raw data length in bytes
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format);

	/**
	 * Create texture from image raw data. It will auto detect image file format. "raw" means
	 * the data is directly read from image file without any processing.
	 *
	 * @param data image raw data pointer. the data will be copied so it is safe to release it
	 * 		after method returns
	 * @param length raw data length in bytes
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting.
	 * 		By default, density is 1 and can be changed by setting wyDevice::defaultInDensity value
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeRaw(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * Create texture from memory image file. It will auto detect image file format
	 *
	 * @param mfsName image name in memory file system
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemory(const char* mfsName);

	/**
	 * Create texture from memory image file. It will auto detect image file format
	 *
	 * @param mfsName image name in memory file system
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemory(const char* mfsName, int transparentColor);

	/**
	 * Create texture from memory image file. It will auto detect image file format
	 *
	 * @param mfsName image name in memory file system
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemory(const char* mfsName, int transparentColor, wyTexturePixelFormat format);

	/**
	 * Create texture from memory image file. It will auto detect image file format
	 *
	 * @param mfsName image name in memory file system
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting.
	 * 		By default, density is 1 and can be changed by setting wyDevice::defaultInDensity value
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeMemory(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity);

	/**
	 * Create texture from an image file and the file is saved in file system. It will
	 * auto detect image file format
	 *
	 * @param fsPath image file path in file system, it should be an absolute file path
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFile(const char* fsPath);

	/**
	 * Create texture from an image file and the file is saved in file system. It will
	 * auto detect image file format
	 *
	 * @param fsPath image file path in file system, it should be an absolute file path
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFile(const char* fsPath, int transparentColor);

	/**
	 * Create texture from an image file and the file is saved in file system. It will
	 * auto detect image file format
	 *
	 * @param fsPath image file path in file system, it should be an absolute file path
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFile(const char* fsPath, int transparentColor, wyTexturePixelFormat format);

	/**
	 * Create texture from an image file and the file is saved in file system. It will
	 * auto detect image file format
	 *
	 * @param fsPath image file path in file system, it should be an absolute file path
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting.
	 * 		By default, density is 1 and can be changed by setting wyDevice::defaultInDensity value
	 * @return \link wyTexture2D wyTexture2D\endlink
	 */
	static wyTexture2D* makeFile(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity);

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
	static wyTexture2D* makeRaw8888(const char* data, int width, int height);

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
	static wyTexture2D* makeRaw8888(const char* data, int width, int height, wyTexturePixelFormat format);

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
	 * Get precise scaled width of image
	 */
	float getPreciseWidth();

	/**
	 * Get precise scaled height of image
	 */
	float getPreciseHeight();

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
	 * set color filter. texture has many sources and it doesn't support label or opengl or pvr source. color filter
	 * won't be called when set until you call \c applyFilter. However, \c applyFilter will be automatically
	 * called when texture is loading.
	 *
	 * @param filter subclass of \link wyColorFilter wyColorFilter\endlink, or NULL if you want to
	 * 		remove filter
	 */
	void setColorFilter(wyColorFilter* filter);

	/**
	 * if current color filter is not NULL, apply this filter to texture. that will cause
	 * texture changed immediately.
	 */
	void applyFilter();

	/**
	 * Clone a texture. After returns, this object will point to a new OpenGL texture
	 * object. Every cloned texture should have a clone id to unique identify itself.
	 * If current proxy already points a cloned texture, then source texture will be cloned
	 *
	 * @param cloneId clone id
	 * @param proxy of cloned texture, NULL if clone is failed
	 */
	wyTexture2D* clone(int cloneId);

	/**
	 * Change this proxy texture to a cloned texture proxy. Cloned texture proxy can
	 * not be created directly so you should call this method to switch a proxy to a
	 * cloned proxy. If clone id not found, do nothing
	 *
	 * @param cloneId clone id
	 * @return true means ok, false means there is no clone which has that id
	 */
	bool switchToClone(int cloneId);

	/**
	 * Delete a cloned texture with specified id, it will immediately delete texture both
	 * in cache and in opengl.
	 *
	 * @param cloneId id of cloned texture
	 * @return true means ok, false means no clone has that id
	 */
	bool deleteClone(int cloneId);
};

#endif // __wyTexture2D_h__
