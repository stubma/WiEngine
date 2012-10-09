package com.wiyun.engine.nodes;

import com.wiyun.engine.utils.BitmapFont;

/**
 * @class BitmapFontLabel
 *
 * 使用{@link BitmapFont}中的文字创建文本标签。
 * 文本内容默认为单行显示。如设置了行宽，则会根据行宽自动换行,
 * 从上到下逐行显示。
 */
public class BitmapFontLabel extends Node {
	/**
	 * \if English
	 * Left alignment
	 * \else
	 * 文字左对齐
	 * \endif
	 */
	public static final int LEFT = 0;

	/**
	 * \if English
	 * center alignment
	 * \else
	 * 居中对齐
	 * \endif
	 */
	public static final int CENTER = 1;

	/**
	 * \if English
	 * right alignment
	 * \else
	 * 右对齐
	 * \endif
	 */
	public static final int RIGHT = 2;
	
	/**
	 * 静态方法，创建一个BitmapFontLabel节点
	 * 
	 * @param font \link BitmapFont BitmapFont \endlink 字体
	 * @param text 要显示的文本内容
	 * @return {@link BitmapFontLabel}
	 */
	public static BitmapFontLabel make(BitmapFont font, String text) {
		return new BitmapFontLabel(font, text);
	}
	
	public static BitmapFontLabel from(int pointer) {
		return pointer == 0 ? null : new BitmapFontLabel(pointer);
	}
	
	protected BitmapFontLabel(int pointer) {
		super(pointer);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 构造函数
	 */
	protected BitmapFontLabel() {
	}
	
	private native void nativeInit(BitmapFont font, String text);
	
	/**
	 * 构造函数
	 *
	 * @param font 字体
	 * @param text 要显示的字符串
	 */
	public BitmapFontLabel(BitmapFont font, String text) {
		nativeInit(font, text);
	}
	
	/**
	 * 设置字体
	 * @param font \link BitmapFont BitmapFont \endlink
	 */
	public native void setFont(BitmapFont font);
	
	private native void nativeGetFont(BitmapFont font);
	
	/**
	 * 获得当前字体
	 * @return \link BitmapFont BitmapFont \endlink
	 */
	public BitmapFont getFont() {
		BitmapFont font = new BitmapFont();
		nativeGetFont(font);
		return font;
	}
	
	/**
	 * 设置文字内容
	 * 
	 * @param text 字符串
	 */
	public native void setText(String text);
	
	/**
	 * 获得文字内容
	 * 
	 * @return 字符串
	 */
	public native String getText();
	
	/**
	 * 设置一个空格的像素宽度
	 *
	 * @param w 空格的像素宽度
	 */
	public native void setSpaceWidth(float w);

	/**
	 * 得到空格的像素宽度
	 *
	 * @return 空格的像素宽度
	 */
	public native float getSpaceWidth();

	/**
	 * 设置一个制表符代表的空格数目
	 *
	 * @param tabSize 一个制表符代表的空格数目
	 */
	public native void setTabSize(int tabSize);

	/**
	 * 得到一个制表符代表的空格数目
	 *
	 * @return 一个制表符代表的空格数目
	 */
	public native int getTabSize();

	/**
	 * 设置行的宽度. 设置后节点的大小将被重新计算，因此节点大小可能会被改变。
	 *
	 * @param width 行宽, 如该值大于实际所有文字一行所占宽度，则行宽为实际宽度
	 */		
	public native void setLineWidth(float width);

	/**
	 * 获得行的宽度
	 *
	 * @return 行宽
	 */
	public native float getLineWidth();
	
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
	 */
	public native void setAlignment(int alignment);

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
	public native int getAlignment();
	
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
	public native float getLineSpacing();

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
	public native void setLineSpacing(float spacing);
}