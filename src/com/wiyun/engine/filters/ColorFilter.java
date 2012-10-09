package com.wiyun.engine.filters;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * color filter is used to transform colors in a texture
 * \else
 * 颜色过滤器用来对一个贴图中的颜色进行转换
 * \endif
 */
public class ColorFilter extends BaseWYObject {
    /**
     * 从底层指针获得一个ColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorFilter}
     */
    public static ColorFilter from(int pointer) {
    	return pointer == 0 ? null : new ColorFilter(pointer);
    }
    
    protected ColorFilter() {
	}
    
    protected ColorFilter(int pointer) {
    	super(pointer);
    }
    
	/**
	 * \if English
	 * apply this color filter to some image data
	 *
	 * @param data raw data of image which must be RGBA8888 format, it holds transformed result when method returns
	 * @param width image pixel width
	 * @param height image pixel height
	 * \else
	 * 对一个图像数据应用颜色矩阵
	 *
	 * @param data 图像原始数据, 必须是RGBA8888格式, 方法完成后, data中的数据变成转换后的值.
	 * @param width 图像的像素宽度
	 * @param height 图像的像素高度
	 * \endif
	 */
	public native void apply(byte[] data, int width, int height);
}
