package com.wiyun.engine.nodes;

import android.graphics.Typeface;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.utils.ResolutionIndependent;

/**
 * 标签对象。可以用于显示文字，和菜单项的区别是它不能被点击。 
 */
public class Label extends TextureNode {
	/**
	 * 创建标签，使用缺省字体和缺省字体大小
	 * 
	 * @param string 标签文字
	 * @return 标签实例
	 */
	public static Label make(String string) {
		return make(string, MenuItem.DEFAULT_FONT_SIZE, Typeface.NORMAL, MenuItem.DEFAULT_FONT_NAME, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签，使用缺省字体
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小
	 * @return 标签实例
	 */
	public static Label make(String string, float fontSize) {
		return make(string, fontSize, Typeface.NORMAL, MenuItem.DEFAULT_FONT_NAME, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param style 字体样式，定义在{@link Typeface}中
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, int style) {
		return new Label(string, fontSize, style, MenuItem.DEFAULT_FONT_NAME, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param style 字体样式，定义在{@link Typeface}中
	 * @param fontName 字体名称, 如果为null则使用系统缺省字体
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, int style, String fontName) {
		return new Label(string, fontSize, style, fontName, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param style 字体样式，定义在{@link Typeface}中
	 * @param fontName 字体名称, 如果为null则使用系统缺省字体
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, int style, String fontName, float width) {
		return new Label(string, fontSize, style, fontName, width, Texture2D.LEFT);
	}

	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param style 字体样式，定义在{@link Typeface}中
	 * @param fontName 字体名称, 如果为null则使用系统缺省字体
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @param alignment 文字对齐方式
	 * @return {@link Label}
	 * @see Texture2D::LEFT
	 * @see Texture2D::CENTER
	 * @see Texture2D::RIGHT
	 */
	public static Label make(String string, float fontSize, int style, String fontName, float width, int alignment) {
		return new Label(string, fontSize, style, fontName, width, alignment);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param fontPath 自定义字体文件在assets中的相对路径, 如果为null则使用系统缺省字体
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, String fontPath) {
		return new Label(string, fontSize, fontPath, false, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param fontPath 自定义字体文件的路径, 如果为null则使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个assets下的相对路径
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, String fontPath, boolean isFile) {
		return new Label(string, fontSize, fontPath, isFile, 0, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param fontPath 自定义字体文件的路径, 如果为null则使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个assets下的相对路径
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @return {@link Label}
	 */
	public static Label make(String string, float fontSize, String fontPath, boolean isFile, float width) {
		return new Label(string, fontSize, fontPath, isFile, width, Texture2D.LEFT);
	}
	
	/**
	 * 创建标签
	 * 
	 * @param string 标签文字
	 * @param fontSize 字体大小，单位是SP
	 * @param fontPath 自定义字体文件的路径, 如果为null则使用系统缺省字体
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个assets下的相对路径
	 * @param width 文字的最大行宽，如果文字很长，则可能会折行成为多行标签
	 * @param alignment 文字对齐方式
	 * @return {@link Label}
	 * @see Texture2D::LEFT
	 * @see Texture2D::CENTER
	 * @see Texture2D::RIGHT
	 */
	public static Label make(String string, float fontSize, String fontPath, boolean isFile, float width, int alignment) {
		return new Label(string, fontSize, fontPath, isFile, width, alignment);
	}
	
	protected Label(String string, float fontSize, String fontPath, boolean isFile, float width, int alignment) {
		nativeInit(string, ResolutionIndependent.resolveSp(fontSize), fontPath, isFile, width, alignment);
	}
	
	protected Label(String string, float fontSize, int style, String fontName, float width, int alignment) {
		nativeInit(string, ResolutionIndependent.resolveSp(fontSize), style, fontName, width, alignment);
	}
	
	private native void nativeInit(String string, float fontSize, String fontPath, boolean isFile, float width, int alignment);
	private native void nativeInit(String string, float fontSize, int style, String fontName, float width, int alignment);
	
    /**
     * 从底层指针获得一个Label的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Label}
     */
    public static Label from(int pointer) {
    	return pointer == 0 ? null : new Label(pointer);
    }
    
    protected Label(int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	public native void setText(String string);
	
	public native String getText();
	
	/**
	 * 设置字体大小
	 *
	 * @param fontSize 字体大小
	 */
	public native void setFontSize(float fontSize);

	/**
	 * 获得字体大小
	 */
	public native float getFontSize();

	/**
	 * 设置字体样式
	 *
	 * @param fontStyle 字体样式
	 */
	public native void setFontStyle(int fontStyle);

	/**
	 * 获得字体样式
	 */
	public native int getFontStyle();

	/**
	 * 设置所用字体名字
	 *
	 * @param fontName 字体名字
	 */
	public native void setFontName(String fontName);

	/**
	 * 获得正在使用的字体名字
	 */
	public native String getFontName();

	/**
	 * 设置字体路径
	 *
	 * fontPath 字体路径
	 */
	public native void setFontPath(String fontPath, boolean isFile);

	/**
	 * 获得字体路径
	 */
	public native String getFontPath();
	
	/**
	 * \if English
	 * Is font path an absolute path in file system?
	 *
	 * @return true means font path is an absolute path in file system, or false
	 * 		means font path is a relative path in assets
	 * \else
	 * 字体路径是否是个文件系统路径
	 *
	 * @return true表示字体路径是文件系统中的绝对路径, false表示字体路径是assets
	 * 		下的相对路径
	 * \endif
	 */
	public native boolean isFileFontPath();

	/**
	 * 设置标签宽度
	 */
	public native void setLineWidth(float lineWidth);

	/**
	 * 获得标签宽度
	 */
	public native float getLineWidth();
	
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
	 * \see Texture2D::LEFT
	 * \see Texture2D::CENTER
	 * \see Texture2D::RIGHT
	 */
	public native void setAlignment(int align);

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
	 * \see Texture2D::LEFT
	 * \see Texture2D::CENTER
	 * \see Texture2D::RIGHT
	 */
	public native int getAlignment();
}
