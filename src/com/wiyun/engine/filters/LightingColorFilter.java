package com.wiyun.engine.filters;

/**
 * \if English
 * Color filter that multiplies the RGB channels by one color, and then adds a second color,
 * pinning the result for each component to [0..255]. The alpha components of the mul and add arguments
 * are ignored.
 * \else
 * 这个滤镜对颜色的三原色进行一个乘法, 然后再做一个加法, 最后的结果限制在[0, 255]之内. 透明度不参与乘法和加法.
 *
 * \par
 * 例如: 如果想把图片中的红色清空, 可以指定和0xFF00FFFF相乘, 再和0x00000000相加.
 * \endif
 */
public class LightingColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个LightingColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link LightingColorFilter}
     */
    public static LightingColorFilter from(int pointer) {
    	return pointer == 0 ? null : new LightingColorFilter(pointer);
    }
    
    public static LightingColorFilter make(int mul, int add) {
    	return new LightingColorFilter(mul, add);
    }
    
    protected LightingColorFilter() {
	}
    
    protected LightingColorFilter(int mul, int add) {
    	nativeInit(mul, add);
    }
    
    private native void nativeInit(int mul, int add);

	protected LightingColorFilter(int pointer) {
    	super(pointer);
    }
}
