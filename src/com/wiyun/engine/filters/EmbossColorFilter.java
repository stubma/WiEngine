package com.wiyun.engine.filters;

/**
 * \if English
 * Emboss effect for texture
 * \else
 * 浮雕效果的滤镜
 * \endif
 */
public class EmbossColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个EmbossColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EmbossColorFilter}
     */
    public static EmbossColorFilter from(int pointer) {
    	return pointer == 0 ? null : new EmbossColorFilter(pointer);
    }
    
    public static EmbossColorFilter make(int grayLevel) {
    	return new EmbossColorFilter(grayLevel, 0);
    }
    
    protected EmbossColorFilter(int grayLevel, int dummy) {
    	nativeInit(grayLevel);
    }
    
    private native void nativeInit(int grayLevel);

	protected EmbossColorFilter(int pointer) {
    	super(pointer);
    }
	
	/**
	 * \if English
	 * Set gray level of emboss filter
	 *
	 * @param grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 设置浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @param grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	public native void setGrayLevel(int grayLevel);

	/**
	 * \if English
	 * Get gray level of emboss filter
	 *
	 * @return grayLevel gray level for emboss effect, from 0 to 255
	 * \else
	 * 获得浮雕滤镜的灰度级别, 级别越低, 最终的效果越暗
	 *
	 * @return grayLevel 浮雕效果的灰度级别, 级别越低, 最终的效果越暗
	 * \endif
	 */
	public native int getGrayLevel();
}
