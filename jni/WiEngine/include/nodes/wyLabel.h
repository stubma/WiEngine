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
#ifndef __wyLabel_h__
#define __wyLabel_h__

#include "wyTextureNode.h"

/**
 * @class wyLabel
 *
 * \if English
 * wrapper of label
 * \else
 * 标签的封装
 * \endif
 */
class WIENGINE_API wyLabel : public wyTextureNode {
private:
	/// text alignment
	wyTexture2D::TextAlignment m_alignment;

	/**
	 * \if English
	 * font size
	 * \else
	 * 字体大小
	 * \endif
	 */
	float m_fontSize;

	/**
	 * \if English
	 * font style
	 * \else
	 * 字体样式
	 * \endif
	 */
	wyFontStyle m_fontStyle;

	/**
	 * \if English
	 * font name
	 * \else
	 * 字体名字
	 * \endif
	 */
	const char*	m_fontName;

	/**
	 * \if English
	 * path of font to be used
	 * \else
	 * 指定所用字体的路径
	 * \endif
	 */
	const char* m_fontPath;

	/**
	 * true means \c m_fontPath is an absolute path in file system, or false
	 * means \c m_fontPath is a path relative to assets
	 */
	bool m_isFile;

	/**
	 * \if English
	 * width of the label, if the content exceeds one single line, new lines will be added
	 * \else
	 * 标签宽度，如内容超过此宽度则折行显示
	 * \endif
	 */
	float m_lineWidth;

protected:
	/**
	 * \if English
	 * update the texture
	 * \else
	 * 更新标签的贴图
	 * \endif
	 */
	void update();

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param resId 标签上字符串的资源id
	 * @return \link wyLabel wyLabel对象\endlink
	 * \endif
	 */
	static wyLabel* make(int resId);

	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param resId 标签上字符串的资源id
	 * @param fontSize 文字大小. 单位是像素.
	 * @param fontPath 字体文件路径
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签. 单位是像素.
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return \link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyLabel* make(int resId, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param resId the resource identifier of a string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width the width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param resId 标签上字符串的资源id
	 * @param fontSize 文字大小. 单位是像素. 所以一般需要用SP宏来得到一个分辨率无关的字体大小
	 * @param style 字体样式, 缺省是NORMAL
	 * @param fontName 字体名称, 缺省是NULL, 表示使用缺省字体
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签. 单位是像素.
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return \link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyLabel* make(int resId, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param text 显示内容的文字字符串
	 * @return \link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyLabel* make(const char* text);

	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width width of the Label, in pixels
	 * @param alignment text alignment, default is left
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小. 单位是像素.
	 * @param fontPath 字体文件路径
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签. 单位是像素.
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return \link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyLabel* make(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * \else
	 * 获得\link wyLabel wyLabel对象指针\endlink
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小. 单位是像素. 所以一般需要用SP宏来得到一个分辨率无关的字体大小
	 * @param style 字体样式, 缺省是NORMAL
	 * @param fontName 字体名称, 缺省是NULL, 表示使用缺省字体
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签. 单位是像素.
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * @return \link wyLabel wyLabel对象指针\endlink
	 * \endif
	 */
	static wyLabel* make(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
	wyLabel();

	/**
	 * \if English
	 * constructor
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels
	 * @param fontPath path of the font to be used
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * @param width width of the label
	 * @param alignment text alignment, default is left
	 * \else
	 * 构造函数
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小
	 * @param fontPath 字体文件路径
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * \endif
	 */
	wyLabel(const char* text, float fontSize, const char* fontPath, bool isFile = false, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * constructor
	 *
	 * @param text null-terminated C string
	 * @param fontSize font size, in pixels, so generally you need wrap this with SP macro to get a resolution independent behavior
	 * @param style font style, default is NORMAL
	 * @param fontName font name, defaul is NULL which means use system default font
	 * @param width width of the label, in pixels
	 * @param alignment text alignment, default is left
	 * \else
	 * 构造函数
	 *
	 * @param text 显示内容的文字字符串
	 * @param fontSize 文字大小. 单位是像素. 所以一般需要用SP宏来得到一个分辨率无关的字体大小
	 * @param style 字体样式, 缺省是NORMAL
	 * @param fontName 字体名称, 缺省是NULL, 表示使用缺省字体
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @param alignment 文字对齐方式, 缺省是左对齐
	 * \endif
	 */
	wyLabel(const char* text, float fontSize, wyFontStyle style = NORMAL, const char* fontName = NULL, float width = 0, wyTexture2D::TextAlignment alignment = wyTexture2D::LEFT);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyLabel();

	/**
	 * \if English
	 * getter
	 *
	 * @return null-terminated C string
	 * \else
	 * 获得文字字符串
	 *
	 * @return 文字字符串
	 * \endif
	 */
	virtual const char* getText() { return m_tex->getText(); }

	/**
	 * \if English
	 * setter
	 *
	 * @param text C string
	 * \else
	 * 设置文字字符串
	 *
	 * @param text 文字字符串
	 * \endif
	 */
	virtual void setText(const char* text) { setString(text); }

	/**
	 * \if English
	 * setter
	 *
	 * @param text C string
	 * \else
	 * 设置文字字符串
	 *
	 * @param text 文字字符串
	 * \endif
	 */
	void setString(const char* text);

	/**
	 * \if English
	 * setter
	 *
	 * @param resId the resource identifier of the string
	 * \else
	 * 通过一个字符串资源id设置标签文字
	 *
	 * @param resId 字符串资源id
	 * \endif
	 */
	void setString(int resId);

	/**
	 * \if English
	 * set the font size
	 *
	 * @param fontSize font size
	 * \else
	 * 设置字体大小
	 *
	 * @param fontSize 字体大小
	 * \endif
	 */
	void setFontSize(float fontSize);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得字体大小
	 * \endif
	 */
	float getFontSize() { return m_fontSize; }

	/**
	 * \if English
	 * setter
	 *
	 * @param fontStyle font style, \link wyFontStyle wyFontStyle\endlink
	 * \else
	 * 设置字体样式
	 *
	 * @param fontStyle 字体样式
	 * \endif
	 */
	void setFontStyle(wyFontStyle fontStyle);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得字体样式
	 * \endif
	 */
	wyFontStyle getFontStyle() { return m_fontStyle; }

	/**
	 * \if English
	 * setter
	 *
	 * @param fontName font name
	 * \else
	 * 设置所用字体名字
	 *
	 * @param fontName 字体名字
	 * \endif
	 */
	void setFontName(const char* fontName);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得正在使用的字体名字
	 * \endif
	 */
	const char* getFontName() { return m_fontName; }

	/**
	 * \if English
	 * Set font path, a font file can be located in file system or assets
	 *
	 * @param fontPath font path
	 * @param isFile true means \c fontPath is an absolute path in file system, false means
	 * 		\c fontPath is a relative path under assets
	 * \else
	 * 设置字体路径
	 *
	 * @param fontPath 字体路径
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个相对于assets的相对路径
	 * \endif
	 */
	void setFontPath(const char* fontPath, bool isFile = false);

	/**
	 * \if English
	 * Get font path
	 * \else
	 * 获得字体路径
	 * \endif
	 */
	const char* getFontPath() { return m_fontPath; }	

	/**
	 * \if English
	 * Is font path an absolute path in file system?
	 *
	 * @return true means \c m_fontPath is an absolute path in file system, or false
	 * 		means \c m_fontPath is a relative path in assets
	 * \else
	 * 字体路径是否是个文件系统路径
	 *
	 * @return true表示\c m_fontPath是文件系统中的绝对路径, false表示\c m_fontPath是assets
	 * 		下的相对路径
	 * \endif
	 */
	bool isFileFontPath() { return m_isFile; }

	/**
	 * \if English
	 * setter
	 *
	 * @param lineWidth label width
	 * \else
	 * 设置标签宽度
	 * \endif
	 */
	void setLineWidth(float lineWidth);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得标签宽度
	 * \endif
	 */
	float getLineWidth() { return m_lineWidth; }

	/**
	 * \if English
	 * Set text alignment
	 *
	 * @param align alignment of text
	 * \else
	 * 设置文字对齐方式
	 *
	 * @param align 对齐方式
	 * \endif
	 */
	void setAlignment(wyTexture2D::TextAlignment align);

	/**
	 * \if English
	 * Get text alignment
	 *
	 * @return text alignment
	 * \else
	 * 得到文字对齐方式
	 *
	 * @return 文字对齐方式
	 * \endif
	 */
	wyTexture2D::TextAlignment getAlignment() { return m_alignment; }
};

#endif // __wyLabel_h__
