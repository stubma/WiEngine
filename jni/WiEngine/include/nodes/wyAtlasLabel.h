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
#ifndef __wyAtlasLabel_h__
#define __wyAtlasLabel_h__

#include "wyNode.h"
#include "wyTextureAtlas.h"
#include "wyHashSet.h"
#include "wyCharProvider.h"

class wyCharMap;

/**
 * @class wyAtlasLabel
 * \if English
 * Label, characters in this type of label is displayed according what it is defined in a picture.
 * \else
 * 图片集标签的封装,根据文字显示图片中的内容,效果可以实现各种字体
 * \endif
 */
class WIENGINE_API wyAtlasLabel : public wyNode {
public:
	/**
	 * \if English
	 * Text alignment
	 * \else
	 * 文字的对其方式
	 * \endif
	 */
	enum Alignment {
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

protected:
	/**
	 * \if English
	 * the label's content
	 * \else
	 * 标签显示内容的文字字符串
	 * \endif
	 */
    const char* m_text;

    /**
     * \if English
     * \link wyTextureAtlas wyTextureAtlas\endlink
     * \else
     * \link wyTextureAtlas wyTextureAtlas\endlink 对象
     * \endif
     */
    wyTextureAtlas* m_atlas;

    /**
     * \if English
     * \link wyCharMap wyCharMap\endlink
     * \else
     * 字符矩形映射表
     * \endif
     */
    wyCharMap* m_map;

	/**
	 * \if English
	 * line width of this label.
	 * If content of the label can't be accommodated by a single line,
	 * multiple lines will be applied. If this value is not specified,
	 * one single line is applied.
	 * \else
	 * 行的宽度，将根据这个宽度决定共显示多少行, 节点的宽度将不超过
	 * 行宽。缺省行宽是无穷大，因此如果不设置行宽，label就只会有
	 * 一行
	 * \endif
	 */
	float m_lineWidth;

	/// line spacing, can be negative
	float m_lineSpacing;

	/**
	 * \if English
	 * see \link wyBlendFunc wyBlendFunc\endlink
	 * \else
	 * 渲染模式\link wyBlendFunc wyBlendFunc结构\endlink
	 * \endif
	 */
    wyBlendFunc m_blendFunc;

    /**
     * \if English
     * see \link wyColor4B wyColor4B\endlink
     * \else
     * 颜色\link wyColor4B wyColor4B结构\endlink
     * \endif
     */
    wyColor4B m_color;

	/// text alignment, can be left, center or right
	Alignment m_alignment;

public:
    /**
     * \if English
     * factory function, used to create a new instance with autoRelease enabled
     *
     * @param text null terminated c string, the string is utf-8 coded
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param map \link wyCharMap wyCharMap\endlink
     * \else
   	 * 静态构造函数
   	 *
   	 * @param text utf-8字符串
   	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
   	 * @param map \link wyCharMap wyCharMap\endlink
   	 * \endif
   	 */
    static wyAtlasLabel* make(const char* text, wyTexture2D* tex, wyCharMap* map);

    /**
     * \if English
     * constructor
     *
     * @param text null terminated c string, the string is utf-8 coded
     * @param tex \link wyTexture2D wyTexture2D\endlink
     * @param map \link wyCharMap wyCharMap\endlink
     * \else
   	 * 构造函数
   	 *
   	 * @param text utf-8字符串
   	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
   	 * @param map \link wyCharMap wyCharMap\endlink
   	 * \endif
   	 */
    wyAtlasLabel(const char* text, wyTexture2D* tex, wyCharMap* map);

    /**
     * \if English
     * destructor
     * \else
	 * 析构函数
	 * \endif
	 */
    virtual ~wyAtlasLabel();

    /// @see wyNode::draw
	virtual void draw();

	/// @see wyNode::getText
	virtual const char* getText() { return m_text; }

	/// @see wyNode::setText
	virtual void setText(const char* text);

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha) { m_color.a = alpha; }

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_blendFunc = func; }

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_atlas->getTexture(); }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex) { m_atlas->setTexture(tex); }

	/**
	 * \if English
	 * setter, to set the line width. The size of the node will be recalculated.
	 *
	 * @param width in pixels, if this value is bigger than the needed width, the needed width will be used
	 * \else
	 * 设置行的宽度. 设置后节点的大小将被重新计算，因此节点大小可能会被改变。
	 *
	 * @param width 行宽, 如该值大于实际所有文字一行所占宽度，则行宽为实际宽度
	 * \endif
	 */
	void setLineWidth(float width);

	/**
	 * \if English
	 * getter, to get the line width
	 * \else
	 * 获得行的宽度
	 *
	 * @return 行宽
	 * \endif
	 */
	float getLineWidth() { return m_lineWidth; }

	/**
	 * \if English
	 * Set text alignment
	 *
	 * @param alignment alignment constant
	 * \else
	 * 设置文字对齐方式
	 *
	 * @param alignment 文字对齐常量
	 * \endif
	 * \see wyBitmapFontLabel::LEFT
	 * \see wyBitmapFontLabel::CENTER
	 * \see wyBitmapFontLabel::RIGHT
	 */
	void setAlignment(Alignment alignment);

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
	 * \see wyBitmapFontLabel::LEFT
	 * \see wyBitmapFontLabel::CENTER
	 * \see wyBitmapFontLabel::RIGHT
	 */
	Alignment getAlignment() { return m_alignment; }

	/**
	 * \if English
	 * Get line spacing
	 *
	 * @return line spacing, can be negative value
	 * \else
	 * 得到行间距
	 *
	 * @return 行间距, 可能为负值
	 * \endif
	 */
	float getLineSpacing() { return m_lineSpacing; }

	/**
	 * \if English
	 * Set line spacing
	 *
	 * @param spacing line spacing, can be negative value
	 * \else
	 * 设置行间距
	 *
	 * @param spacing 行间距, 可以为负值
	 * \endif
	 */
	void setLineSpacing(float spacing);
};

/**
 * @class wyCharMap
 * \if English
 * To manage the mapping between a character and its rectangle size, needed by \link wyAtlasLabel wyAtlasLabel\endlink
 * \else
 * 维护一个字符与矩形的映射表，在构造\link wyAtlasLabel wyAtlasLabel\endlink 时，需要
 * 传入该类。
 * \endif
 */
class WIENGINE_API wyCharMap : public wyObject, public wyCharProvider {
	friend class wyAtlasLabel;

private:
	/**
	 * \if English
	 * hash map
	 * \else
	 * 字符映射表
	 * \endif
	 */
	wyHashSet* m_charMap;

	/**
	 * \if English
	 * the width of blank space character, if not specified by the font, this value will be used.
	 * The default value is 6dp.
	 * \else
	 * 空格字符的像素宽度，如果位图字体中没有空格，则会使用
	 * 这个宽度来作为空格的宽度, 缺省值是6dp
	 * \endif
	 */
	float m_spaceWidth;

	/**
	 * \if English
	 * the space count of character tab, 4 is used by default
	 * \else
	 * 一个制表符占的空格数，缺省是4
	 * \endif
	 */
	int m_tabSize;

	/// total height of all characters
	float m_totalCharHeight;

private:
	static int charHashEquals(void* ptr, void* elt);
	static void* buildCharHash(void* ptr, void* data);
    static bool releaseHash(void* elt, void* data);

private:
	static bool reverseVertices(wyTextureAtlas* atlas, wyQuad3D* v, void* data);

	static void releaseLine(const char* line);

protected:
    /**
     * to update the character info in the \link wyTextureAtlas wyTextureAtlas\endlink
     *
     * @param text null terminated c string, the string is utf-8 coded.
     * @param lineWidth line width
     * @param lineSpacing spacing between lines
     * @param alignment text alignment
     * @param atlas \link wyTextureAtlas wyTextureAtlas\endlink
     * @param w to return the updated width, can be NULL
     * @param h to return the updated height, can be NULL
     */
    void updateAtlas(const char* text, float lineWidth, float lineSpacing, wyAtlasLabel::Alignment alignment, wyTextureAtlas* atlas, float* w, float* h);

	/**
	 * Measure width of every lines
	 *
	 * @param lines vector contains every single line
	 * @param spaceWidth space width in pixels
	 * @param tabSize how many space one tab equals to
	 * @return vector contains width of every single line
	 */
	vector<float>* measureWidth(vector<const char*>* lines);
	
public:
    static wyCharMap* make();

    wyCharMap();
    virtual ~wyCharMap();

    /// @see wyCharProvider::measureText
    virtual float measureText(const char* chars, int length, float spaceWidth, float tabSize);

    /**
     * \if English
     * to map a character to a rectangle
     *
     * @param rect the character's rectangle in the atlas picture
     * @param c the character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     * \else
     * 映射矩形和字符
     *
     * @param rect 字符图片在图片集中的矩形
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     * \endif
     */
    void mapChar(wyRect rect, int c, float leftPadding = 0, float rightPadding = 0);

    /**
     * \if English
     * to map a character to a  zwoptex frame
     *
     * @param frameName the frame name defined in the zwoptex description file
     * @param c character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     * \else
     * 映射矩形和字符
     *
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     * \endif
     */
    void mapChar(const char* frameName, int c, float leftPadding = 0, float rightPadding = 0);

    /**
     * \if English
     * to map a character to a zwoptex frame
     *
     * @param zwoptexName the zwoptex name
     * @param frameName the frame name defined in the zwoptex description file
     * @param c character value
     * @param leftPadding left padding
     * @param rightPadding right padding
     * \else
     * 映射矩形和字符
     *
     * @param zwoptexName zwoptex名
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     * \endif
     */
    void mapChar(const char* zwoptexName, const char* frameName, int c, float leftPadding = 0, float rightPadding = 0);

	/**
	 * \if English
	 * to set the width of blank space, in pixels
	 *
	 * @param w the width, in pixels
	 * \else
	 * 设置一个空格的像素宽度
	 *
	 * @param w 空格的像素宽度
	 * \endif
	 */
	void setSpaceWidth(float w) { m_spaceWidth = w; }

	/**
	 * \if English
	 * to get the width of blank space
	 *
	 * \else
	 * 得到空格的像素宽度
	 *
	 * @return 空格的像素宽度
	 * \endif
	 */
	float getSpaceWidth() { return m_spaceWidth; }

	/**
	 * \if English
	 * to set the space count of tab
	 *
	 * @param tabSize space count
	 * \else
	 * 设置一个制表符代表的空格数目
	 *
	 * @param tabSize 一个制表符代表的空格数目
	 * \endif
	 */
	void setTabSize(int tabSize) { m_tabSize = tabSize; }

	/**
	 * \if English
	 * to get the space count of tab
	 * \else
	 * 得到一个制表符代表的空格数目
	 *
	 * @return 一个制表符代表的空格数目
	 * \endif
	 */
	int getTabSize() { return m_tabSize; }

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
	float getEmptyLineHeight() { return m_totalCharHeight / m_charMap->entries; }
};

#endif // __wyAtlasLabel_h__
