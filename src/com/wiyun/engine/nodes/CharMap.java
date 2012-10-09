package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYRect;

/**
 * @class CharMap
 *
 * 维护一个字符与矩形的映射表，在构造\link AtlasLabel AtlasLabel\endlink 时，需要
 * 传入该类。
 */
public class CharMap extends BaseWYObject {
    /**
     * 从底层指针获得一个CharMap的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CharMap}
     */
    public static CharMap from(int pointer) {
    	return pointer == 0 ? null : new CharMap(pointer);
    }
    
    public static CharMap make() {
    	return new CharMap();
    }
    
    protected CharMap() {
    	nativeInit();
    }
    
    private native void nativeInit();
    
    protected CharMap(int pointer) {
    	super(pointer);
    }
    
    /**
     * 映射矩形和字符
     *
     * @param rect 字符图片在图片集中的矩形
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(WYRect rect, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param rect 字符图片在图片集中的矩形
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(WYRect rect, int c, float leftPadding, float rightPadding);

    /**
     * 映射矩形和字符
     *
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(String frameName, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(String frameName, int c, float leftPadding, float rightPadding);

    /**
     * 映射矩形和字符
     *
     * @param zwoptexName zwoptex名
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     */
    public native void mapChar(String zwoptexName, String frameName, int c);
    
    /**
     * 映射矩形和字符
     *
     * @param zwoptexName zwoptex名
     * @param frameName zwoptex中的帧名
     * @param c 映射到的字符, 用整数表示字符的utf-8编码
     * @param leftPadding 字符左边应该保留的空隙
     * @param rightPadding 字符右边应该保留的空隙
     */
    public native void mapChar(String zwoptexName, String frameName, int c, float leftPadding, float rightPadding);
    
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
}