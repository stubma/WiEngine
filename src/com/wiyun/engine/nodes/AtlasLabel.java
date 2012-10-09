package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * @class AtlasLabel
 *
 * 图片集标签的封装,根据文字显示图片中的内容,效果可以实现各种字体
 */
public class AtlasLabel extends Node {
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
     * 从底层指针获得一个AtlasLabel的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link AtlasLabel}
     */
    public static AtlasLabel from(int pointer) {
    	return pointer == 0 ? null : new AtlasLabel(pointer);
    }
    
    public static AtlasLabel make(String text, Texture2D tex, CharMap map) {
    	return new AtlasLabel(text, tex, map);
    }
    
    protected AtlasLabel(int pointer) {
    	super(pointer);
    }
    
    protected AtlasLabel() {
    }
    
	protected AtlasLabel(String text, Texture2D tex, CharMap map) {
		nativeInit(text, tex, map);
	}

	private native void nativeInit(String text, Texture2D tex, CharMap map);

	@Override
    protected void doNativeInit() {
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
