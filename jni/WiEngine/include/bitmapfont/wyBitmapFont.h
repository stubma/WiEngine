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
#ifndef __wyBitmapFont_h__
#define __wyBitmapFont_h__

#include "wyTypes.h"
#include "wyArray.h"
#include "wyHashSet.h"
#include "wyTexture2D.h"
#include "wyCharProvider.h"
#include <stdio.h>

class wyBitmapFontLabel;

/**
 * @typedef wyBitmapFontFormat
 *
 * \if English
 * format of bitmap font description file
 * \else
 * 图片字体描述文件格式
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * HGE bitmap font file format, exported by HGE bitmap font editor
	 * \else
	 * HGE bitmap font editor导出的格式
	 * \endif
	 */
	BFF_HGE,

	/**
	 * \if English
	 * angle code format in plain text, can be exported by Glyph Designer, Bitmap Font Generator
	 * \else
	 * AngelCode的文本格式, 可以通过Glyph Designer导出
	 * \endif
	 */
	BFF_ANGELCODE_TXT,

	/**
	 * \if English
	 * angle code format in xml, can be exported by Glyph Designer, Bitmap Font Generator
	 * \else
	 * AngelCode的XML格式, 可以通过Glyph Designer导出
	 * \endif
	 */
	BFF_ANGELCODE_XML
} wyBitmapFontFormat;

/**
 * @struct wyCharInfo
 *
 * \if English
 * struct to save info of one character
 * \else
 * 用来保存字体文字信息
 * \endif
 */
typedef struct wyCharInfo {
	wyCharInfo() :
			word(0),
			left(0),
			right(0),
			top(0),
			page(0),
			texRect(wyrZero) {
	}

	/**
	 * \if English
	 * the integer format of character in utf-8 encoding, big endian
	 * \else
	 * 字符的utf-8编码使用big endian转换为整数后的形式
	 * \endif
	 */
	int word;

	/**
	 * \if English
	 * left padding of this character
	 * \else
	 * 绘制当前字符时要增加的左侧间距
	 * \endif
	 */
	int left;

	/**
	 * \if English
	 * right padding of this character
	 * \else
	 * 绘制下一个字符时要增加的右侧间距
	 * \endif
	 */
	int right;

	/**
	 * \if English
	 * top paddig of this character
	 * \else
	 * 绘制当前字符时需要增加的顶部间距
	 * \endif
	 */
	int top;

	/**
	 * \if English
	 * page index of character, angle code format can have multiple character atlas and every atlas is a page
	 * \else
	 * 字符所在的atlas页
	 * \endif
	 */
	int page;

	/**
	 * \if English
	 * character texture rectangle in page atlas
	 * \else
	 * 在贴图中的区域，单位为像素
	 * \endif
	 */
	wyRect texRect;
} wyCharInfo;

/**
 * @class wyBitmapFont
 *
 * \if English
 * it loads bitmap font description file and then you can create bitmap font label based on it
 * \else
 * 从资源文件或系统文件加载Bitmap字体. 字体描述文件可以通过WiEngine支持的图片字体工具生成, 目前已经支持
 * 多种格式. 但是基本上都是一个描述文件和一个图片搭配的形式. 描述文件和图片需要统一放置, 可以放在res下, 也
 * 可以放在assets或者文件系统中, 一定不能把它们分开放置, 比如把描述文件放在assets下, 图片放在res下.
 * \endif
 */
class WIENGINE_API wyBitmapFont : public wyCharProvider {
	friend class wyBitmapFontLabel;

private:
	/**
	 * \if English
	 * hash set for character info, key is character code and the code is a integer of character utf-8 encoding value in big endian
	 * \else
	 * 哈希表，保存font的字符位置等信息
	 * \endif
	 */
	wyHashSet* m_charset;

	/**
	 * \if English
	 * page array of bitmap font, it is an array because angle code support multiple character atlas
	 * \else
	 * 贴图, 因为anglecode格式可能包含多张贴图, 因此是个数组
	 * \endif
	 */
	wyArray* m_textures;

	/**
	 * \if English
	 * resource id of bitmap font description file, only used when bitmap font description
	 * file is saved in res folder
	 * \else
	 * 图片字体描述文件的资源ID
	 * \endif
	 */
	int m_resId;

	/**
	 * \if English
	 * hash of this bitmap font, internal used to avoid to load it again
	 * \else
	 * hash值
	 * \endif
	 */
	int m_hash;

	/**
	 * \if English
	 * file path of bitmap font description file, only used when it is saved
	 * in assets folder or file system
	 * \else
	 * 当从系统文件加载字体时，用来保存系统路径
	 * \endif
	 */
	const char* m_path;

	/**
	 * \if English
	 * true means \c m_path is a relative path in assets folder, false means
	 * \c m_path is an absolute path in file system
	 * \else
	 * true表示m_path是文件系统路径
	 * \endif
	 */
	bool m_isFile;

	/**
	 * \if English
	 * line height, default is zero. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 * \else
	 * 行的高度, 如果不设置则缺省是0, 一个任意小于等于0的行高表示动态计算行高, 即会取
	 * 行中最高字符的高度, 因此每行可能都不一样高. 如果设置了一个大于0的行高, 则会使用
	 * 该行高, 那么每行都是一样高.
	 * \endif
	 */
	float m_lineHeight;

	/**
	 * A calculated height for empty line, actually it is the average of char height
	 */
	float m_emptyLineHeight;

	/**
	 * \if English
	 * hash set for loaded bitmap font
	 * \else
	 * 哈希表，静态成员，保存当前所有已经被加载的字体
	 * \endif
	 */
	static wyHashSet* s_loadedFonts;

private:
	static bool releaseTexture(wyArray* arr, void* ptr, int index, void* data);
	static bool sumCharHeight(void* elt, void* data);

protected:
	wyBitmapFont() {}
	~wyBitmapFont();

	/**
	 * \if English
	 * constructor
	 *
	 * @param resId resource id of bitmap font description file
	 * @param format format of description file, default is BFF_HGE
	 * \else
	 * 构造函数
	 *
	 * @param resId 保存font信息的文件资源ID
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * \endif
	 */
	wyBitmapFont(int resId, wyBitmapFontFormat format = BFF_HGE);

	/**
	 * \if English
	 * constructor
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder
	 * @param format format of description file
	 * @param inDensity density of font
	 * \else
	 * 构造函数，根据系统路径加载字体
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile true表示\c path是一个文件系统下的绝对路径，false表示\c path是一个
	 * 		assets下的相对路径
	 * @param format 字体描述文件的格式
	 * @param inDensity 字体文件的密度
	 * \endif
	 */
	wyBitmapFont(const char* path, bool isFile, wyBitmapFontFormat format, float inDensity);

public:
	/**
	 * \if English
	 * load a bitmap font description file from resource id. returns existed one if it is already loaded
	 *
	 * @param resId resource id of bitmap font description file
	 * @param format format of description file, default is BFF_HGE
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param resId 图片字体描述文件的资源ID
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * \endif
	 */
	static wyBitmapFont* loadFont(int resId, wyBitmapFontFormat format = BFF_HGE);

	/**
	 * \if English
	 * load a bitmap font description file from assets folder or file system. returns existed one if it is already loaded
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder. default is false
	 * @param format format of description file, default is BFF_HGE
	 * @param inDensity density of font, default is 1 and it means by default the font is thought as designed for mdpi
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile 默认为false，true表示\c path是一个文件系统下的绝对路径，false表示\c path是一个
	 * 		assets下的相对路径
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * @param inDensity 字体文件的密度, 这关系到WiEngine自动缩放的比例, 缺省是1, 即默认为字体是对mdpi设计的
	 * \endif
	 */
	static wyBitmapFont* loadFont(const char* path, bool isFile = false, wyBitmapFontFormat format = BFF_HGE, float inDensity = 1.0f);

	/**
	 * \if English
	 * unload a font
	 * \else
	 * 静态函数，卸载字体
	 * \endif
	 */
	static void unloadFont(wyBitmapFont* font);

	/**
	 * \if English
	 * unload all fonts
	 * \else
	 * 静态函数，卸载所有字体
	 * \endif
	 */
	static void unloadAll();

	/// @see wyCharProvider::measureText
	virtual float measureText(const char* chars, int length, float spaceWidth, float tabSize);

	/**
	 * \if English
	 * add related character atlas, must add it based on page index, i.e., the page whose index is 0 must be added first
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 添加一个贴图页
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	void addTexture(wyTexture2D* tex);

	/**
	 * \if English
	 * get character atlas of specified index
	 *
	 * @param index page index start from zero
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 得到某页的贴图
	 *
	 * @param index 页索引, 从0开始
	 * @return \link wyTexture2D wyTexture2D\endlink
	 * \endif
	 */
	wyTexture2D* getTexture(int index) { return (wyTexture2D*)wyArrayGet(m_textures, index); }

	/**
	 * \if English
	 * get \link wyCharInfo wyCharInfo\endlink of a character
	 *
	 * @param[in] wc integer format of character utf-8 encoding in big endian
	 * \else
	 * 获得指定字符在贴图中的位置和大小，单位为像素
	 *
	 * @param[in] wc 字符utf-8编码通过big endian转换为整数的形式
	 * \endif
	 */
	wyCharInfo* getCharInfo(int wc);

	/**
	 * \if English
	 * get resource id of bitmap font description file, or zero if it is not loaded from resource id
	 *
	 * @return resource id of bitmap font description file, or zero if it is not loaded from resource id
	 * \else
	 * 获得资源ID
	 *
	 * @return 资源ID，如果font是从系统文件加载的，返回0
	 * \endif
	 */
	int getResId() { return m_resId; }

	/**
	 * \if English
	 * get hash of this font
	 *
	 * @return hash of this font
	 * \else
	 * 获得hash值
	 *
	 * @return 当前对象在图片字体缓冲区中的索引哈希
	 * \endif
	 */
	int getHash() { return m_hash; }

	/**
	 * \if English
	 * true if bitmap font description file is from file system, false if it is from assets folder
	 *
	 * @return true if bitmap font description file is from file system, false if it is from assets folder
	 * \else
	 * 字体描述文件是否来自文件系统
	 *
	 * @return true表示字体描述文件来自文件系统
	 * \endif
	 */
	bool isFile() { return m_isFile; }

	/**
	 * \if English
	 * get path of bitmap font description file, or NULL if it is not loaded from assets or file system
	 *
	 * @return path of bitmap font description file, or NULL if it is not loaded from assets or file system
	 * \else
	 * 获得文件的完整路径名
	 *
	 * @return 如果font不是从系统文件加载的，返回NULL
	 * \endif
	 */
	const char* getPath() { return m_path; }

	/**
	 * \if English
	 * add a character info
	 *
	 * @param ci \link wyCharInfo wyCharInfo\endlink
	 * \else
	 * 添加一个字符信息
	 *
	 * @param ci \link wyCharInfo wyCharInfo\endlink
	 * \endif
	 */
	void addCharInfo(wyCharInfo* ci);

	/**
	 * \if English
	 * get line height, default is zero. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 *
	 * @return line height in pixel
	 * \else
	 * 获得行的高度, 大于0的值表示是统一行高, 即每行都具有这个高度. 小于等于0表示使用
	 * 动态行高, 每行的高度都可能不一样, 是根据字符高度计算出来的.
	 *
	 * @return 行高
	 * \endif
	 */
	float getLineHeight() { return m_lineHeight; }

	/**
	 * \if English
	 * set line height. a value <= 0 means every line's height is calculated
	 * dynamically. a value > 0 means every line is set to the same height
	 *
	 * @param height line height in pixel
	 * \else
	 * 设置行高. 大于0的值表示是统一行高, 即每行都具有这个高度. 小于等于0表示使用动态行高,
	 * 每行的高度都可能不一样, 是根据字符高度计算出来的.
	 *
	 * @param height 行高.
	 * \endif
	 */
	void setLineHeight(float height) { m_lineHeight = height; }

	/**
	 * \if English
	 * Return a height for empty line, actually it is the average height of characters
	 *
	 * @return height for empty line
	 * \else
	 * 得到一个空行的高度, 实际上这是所有字符的平均高度
	 *
	 * @return 空行高度
	 * \endif
	 */
	float getEmptyLineHeight() { return m_emptyLineHeight; }
};

#endif
