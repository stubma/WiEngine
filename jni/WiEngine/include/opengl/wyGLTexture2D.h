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
#ifndef __wyGLTexture2D_h__
#define __wyGLTexture2D_h__

#include "wyGlobal.h"
#include <stdbool.h>
#include <stdint.h>
#include "wyTypes.h"
#include "wyTexture2D.h"

class wyEventDispatcher;

/**
 * @class wyGLTexture2D
 *
 * 2D贴图对象。封装了从某个图象资源生成贴图以及贴图渲染的逻辑。
 * 当\link wyGLTexture2D wyGLTexture2D\endlink创建后, \link wyTextureManager wyTextureManager\endlink会
 * 自动将它注册, 并赋予它一个句柄.<br>
 *
 * 应用程序永远不能主动创建\link wyGLTexture2D wyGLTexture2D\endlink对象, 而
 * 只能通过\link wyTexture2D wyTexture2D\endlink来引用实际的贴图, 这样做的
 * 好处是隔离了上层和贴图载入销毁的逻辑, 方便实现贴图资源的管理.
 */
class WIENGINE_API wyGLTexture2D : public wyObject {
	friend class wyTextureManager;
	friend class wyTexture2D;
	friend class wyEventDispatcher;

private:
	/// 贴图类型
	wyTextureSource m_source;

	/// 贴图格式, 设置合适的贴图格式可以提高渲染速度, 缺省格式是RGBA8888
	wyTexturePixelFormat m_pixelFormat;

	/// 透明色, 仅对BMP文件有效
	int m_transparentColor;

	/// android资源id, 仅用于保存在res目录下的图片
	int m_resId;

	// assets路径或者文件系统路径
	const char* m_path;

	/**
	 * When this texture is an image, it is used to flag \c m_path.
	 * When this texture is a label, it is used to flag \c m_fontPath
	 */
	bool m_isFile;

	/// text alignment
	wyTexture2D::TextAlignment m_alignment;

	/// 临时辅助变量
	const char* m_tmp;

	// for label
	float m_fontSize;
	wyFontStyle m_fontStyle;
	const char* m_fontName;
	const char* m_fontPath;
	const char* m_text;
	float m_lineWidth;

	/// 如果图片是一个内存数据，则用于保存内存数据指针
	const char* m_data;

	/// 如果图片是一个内存数据，用于表示\c m_data 中的数据长度
	size_t m_length;

	/// 内存文件系统中的图片标识名称，仅用于内存文件
	const char* m_mfsName;

	/// 标识当Lable有变化，需要重新渲染
	bool m_needUpdateLabel;

	/// 原始尺寸于实际尺寸的比例，例如widthScale=width/pixelWidth
	float m_widthScale, m_heightScale;

	/// OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	int m_texture;

	/// 贴图实际宽度，高度
	int m_pixelWidth, m_pixelHeight;

	/// precise width of image after scaled
	float m_preciseWidth;

	/// precise height of image after scaled
	float m_preciseHeight;

	/// 原始图片的宽度，高度
	float m_width, m_height;

	/// 贴图min filter
	int m_minFilter;

	/// 贴图mag filter
	int m_magFilter;

	/// 贴图参数, 水平方向的wrap设置
	int m_wrapS;

	/// 贴图参数, 垂直方向的wrap设置
	int m_wrapT;

	/// 标识是否以X轴为转动轴翻转图片
	bool m_flipY;

	/// 标识是否以Y轴为转动轴翻转图片
	bool m_flipX;

	/// 源图片的density，对于通过资源id载入的图片没有意义
	float m_inDensity;

private:
	/**
	 * Create texture from image file which is specified by resource id.
	 * It will auto detect image file format.
	 *
	 * @param resId resource id
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param pixelFormat destination opengl texture format
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* make(int resId, int transparentColor = 0, wyTexturePixelFormat pixelFormat = WY_TEXTURE_PIXEL_FORMAT_RGBA8888);

	/**
	 * Create texture from an image file which is specified by assets relative path. It
	 * will auto detect image file format
	 *
	 * @param assetPath relative path of image file in assets
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param pixelFormat destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* make(const char* assetPath, int transparentColor = 0, wyTexturePixelFormat pixelFormat = WY_TEXTURE_PIXEL_FORMAT_RGBA8888, float inDensity = 0);

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
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeRaw(const char* data, size_t length, int transparentColor = 0, wyTexturePixelFormat pixelFormat = WY_TEXTURE_PIXEL_FORMAT_RGBA8888, float inDensity = 0);

	/**
	 * Create texture from memory image file. It will auto detect image file format
	 *
	 * @param mfsName image name in memory file system
	 * @param transparentColor transparent color, format is 0xaarrggbb but alpha component
	 * 		is ignored. Every pixel of image will be compared with this color and pixel whose
	 * 		rgb value is same as it will be cleared
	 * @param format destination opengl texture format
	 * @param inDensity density of image file, zero means uses system default setting.
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeMemory(const char* mfsName, int transparentColor = 0, wyTexturePixelFormat pixelFormat = WY_TEXTURE_PIXEL_FORMAT_RGBA8888, float inDensity = 0);

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
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeFile(const char* fsPath, int transparentColor = 0, wyTexturePixelFormat pixelFormat = WY_TEXTURE_PIXEL_FORMAT_RGBA8888, float inDensity = 0);

	/**
	 * 通过一个字符串生成一个贴图
	 *
	 * @param text C字符串
	 * @param fontSize 字体大小，单位是px, 在传入时应该用resolveSp进行转换
	 * @param fontPath 自定义字体文件在assets中的路径，如果为NULL，则使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 最大行宽，为0表示不折行
	 * @param alignment 文字对齐方式, 缺省为左对齐
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeLabel(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * 通过一个字符串生成一个贴图
	 *
	 * @param text C字符串
	 * @param fontSize 字体大小，单位是px, 在传入时应该用resolveSp进行转换
	 * @param style 字体样式
	 * @param fontName 字体名称，为NULL则使用系统缺省字体
	 * @param width 最大行宽，为0表示不折行
	 * @param alignment 文字对齐方式, 缺省为左对齐
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * 把一个已有的OpenGL贴图id包装成\link wyGLTexture2D wyGLTexture2D对象\endlink
	 *
	 * @param texture OpenGL贴图id
	 * @param w 贴图宽度
	 * @param h 贴图高度
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeGL(int texture, int w, int h);

	/**
	 * 根据已经展开的原始像素数据创建一个贴图。这里说的原始数据已经是RGBA8888格式。对于这种方式创建
	 * 的贴图，WiEngine不会再进行缩放.
	 *
	 * @param data 已经展开的像素数据, 这个数组由texture manager托管. 这些数据必须是RGBA8888格式, 数据的长度
	 * 			应该是宽乘以高乘以4. 调用者必须保证数据的完整性.
	 * @param width 数据所代表的图片的宽度
	 * @param height 数据所代表的图片的高度
	 * @param format 期望生成的贴图格式
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	static wyGLTexture2D* makeRaw8888(const char* data, int width, int height, wyTexturePixelFormat format = WY_TEXTURE_PIXEL_FORMAT_RGBA8888);

	/**
	 * 构造函数
	 */
	wyGLTexture2D();

	/**
	 * 初始化贴图尺寸参数
	 *
	 * @param realWidth 贴图的有效像素宽度
	 * @param realHeight 贴图的有效像素高度
	 */
	void initSize(float realWidth, float realHeight);

	/**
	 * 把RGBA8888格式的数据转换成为当前贴图格式的数据
	 *
	 * @param data RGBA8888格式数据
	 * @return 转换后的数据, 如果没有转换, 则直接返回data
	 */
	const char* convertPixelFormat(const char* data);

	/**
	 * 载入贴图, 这个方法一定会在OpenGL线程中调用
	 */
	void doLoad();

	/**
	 * 更新贴图, 这个方法一定会在OpenGL线程中调用
	 */
	void doUpdateRaw();

	/**
	 * 删除OpenGL中的贴图对象，如果你不是通过TextureManager创建的Texture2D, 则你
	 * 可以通过这个方法删除底层的OpenGL贴图对象。这个方法需要在OpenGL线程中调用。
	 *
	 * @param noDeleteGL 是否在OpenGL中删除，默认是false，不删除
	 */
	void deleteTexture(bool noDeleteGL = false);

	/**
	 * 确保贴图对象已经被载入，这个方法将把贴图对应的图象资源转换成OpenGL中的贴图对象.
	 * 如果当前线程不是OpenGL线程, 则会堵塞当前线程知道贴图载入完成
	 */
	void load();

	/**
	 * load raw data from texture source
	 *
	 * @param outLen returns length of raw data
	 * @param outScale returns scale rate of resource
     * @param outNeedFree returns flag indicating returned data need to be free or not
	 */
	char* loadRaw(size_t* outLen, float* outScale, bool* outNeedFree);

	/**
	 * It load normal image format, such as jpg, png, bmp, into rgba8888 format
	 *
	 * @param raw raw data of image
	 * @param len byte size of raw data
	 * @param scale scale rate of image
	 * @return rgba8888 format data of image
	 */
	char* loadImage(char* raw, size_t len, float scale);

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
	 * @param alignment 文字对齐方式
	 */
	void updateLabel(const char* text, float fontSize, const char* fontPath, bool isFile = false, float lineWidth = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * 设置显示的字符串内容
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小
	 * @param style 字体样式
	 * @param fontName 字体
	 * @param lineWidth 行宽
	 * @param alignment 文字对齐方式
	 */
	void updateLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL, float lineWidth = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

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
	 * @param x x位置
	 * @param y y位置
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
	float getWidth() { return m_width; }

	/**
	 * 得到原始图片的高度
	 *
	 * @return 原始图片的高度
	 */
	float getHeight() { return m_height; }

	/**
	 * \if English
	 * Get precise scaled width of image
	 * \else
	 * 得到图片缩放后的精确宽度, 这个宽度不会丢失精度
	 * \endif
	 */
	float getPreciseWidth() { return m_preciseWidth; }

	/**
	 * \if English
	 * Get precise scaled height of image
	 * \else
	 * 得到图片缩放后的精确高度, 这个高度不会丢失精度
	 * \endif
	 */
	float getPreciseHeight() { return m_preciseHeight; }

	/**
	 * 得到贴图实际宽度
	 *
	 * @return 贴图实际宽度
	 */
	int getPixelWidth() { return m_pixelWidth; }

	/**
	 * 得到贴图实际高度
	 *
	 * @return 贴图实际高度
	 */
	int getPixelHeight() { return m_pixelHeight; }

	/**
	 * 得到原始图片和贴图实际大小的宽度比例
	 *
	 * @return 宽度比例
	 */
	float getWidthScale() { return m_widthScale; }

	/**
	 * 得到原始图片和贴图实际大小的高度比例
	 *
	 * @return 高度比例
	 */
	float getHeightScale() { return m_heightScale; }

	/**
	 * 得到OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 *
	 * @return OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 */
	int getTexture() { return m_texture; }

	/**
	 * 设置OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 *
	 * @param tex OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	 */
	void setTexture(int tex) { m_texture = tex; }

	/**
	 * 得到标签类型贴图显示的字符串内容
	 *
	 * @return 标签类型贴图显示的字符串内容
	 */
	const char* getText() { return m_text; }

	/**
	 * 得到贴图类型
	 *
	 * @return 贴图类型
	 */
	wyTextureSource getSource() { return m_source; }

	/**
	 * 得到是否以X轴为转动轴翻转图片
	 *
	 * @return 是否以X轴为转动轴翻转图片
	 */
	bool isFlipY() { return m_flipY; }

	/**
	 * 得到是否以Y轴为转动轴翻转图片
	 *
	 * @return 是否以Y轴为转动轴翻转图片
	 */
	bool isFlipX() { return m_flipX; }

	/**
	 * 设置是否以y轴为转动轴翻转图片
	 *
	 * @param flipX 是否以y轴为转动轴翻转图片,true为翻转
	 */
	void setFlipX(bool flipX) { m_flipX = flipX; }

	/**
	 * 设置是否以x轴为转动轴翻转图片
	 *
	 * @param flipY 是否以x轴为转动轴翻转图片,true为翻转
	 */
	void setFlipY(bool flipY) { m_flipY = flipY; }

	/**
	 * 通过原始像素数据更新贴图内容
	 *
	 * @param raw 像素数据，这些数据的格式必须是RGBA8888格式，其长度必须符合当前贴图有效大小.
	 * 		调用者要负责释放该数据.
	 */
	void updateRaw(const char* raw);

public:
	/**
	 * 析构函数
	 */
	virtual ~wyGLTexture2D();
};

#endif // __wyGLTexture2D_h__
