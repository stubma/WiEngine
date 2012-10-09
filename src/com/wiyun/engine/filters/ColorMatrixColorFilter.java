package com.wiyun.engine.filters;

/**
 * \if English
 * color filter which use a color matrix to transform colors
 * \else
 * 使用颜色矩阵对颜色进行转换的过滤器
 * \endif
 */
public class ColorMatrixColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个ColorMatrixColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorMatrixColorFilter}
     */
    public static ColorMatrixColorFilter from(int pointer) {
    	return pointer == 0 ? null : new ColorMatrixColorFilter(pointer);
    }
    
    public static ColorMatrixColorFilter make(ColorMatrix m) {
    	return new ColorMatrixColorFilter(m);
    }
    
    protected ColorMatrixColorFilter() {
	}
    
    protected ColorMatrixColorFilter(ColorMatrix m) {
    	nativeInit(m);
    }
    
    private native void nativeInit(ColorMatrix m);

	protected ColorMatrixColorFilter(int pointer) {
    	super(pointer);
    }
}
