package com.wiyun.engine.filters;

/**
 * \if English
 * Blur filter, using average filter algorithm
 * \else
 * 模糊滤镜, 使用平均模糊算法
 * \endif
 */
public class BlurColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个BlurColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link BlurColorFilter}
     */
    public static BlurColorFilter from(int pointer) {
    	return pointer == 0 ? null : new BlurColorFilter(pointer);
    }
    
    public static BlurColorFilter make(int radius) {
    	return new BlurColorFilter(radius, 0);
    }
    
    protected BlurColorFilter(int radius, int dummy) {
    	nativeInit(radius);
    }
    
    private native void nativeInit(int radius);

	protected BlurColorFilter(int pointer) {
    	super(pointer);
    }

	/**
	 * \if English
	 * Set blur radius
	 *
	 * @param radius blur radius
	 * \else
	 * 设置模糊半径
	 *
	 * @param radius 模糊半径
	 * \endif
	 */
	public native void setRadius(int radius);

	/**
	 * \if English
	 * Get blur radius
	 *
	 * @return blur radius
	 * \else
	 * 得到模糊半径
	 *
	 * @return 模糊半径
	 * \endif
	 */
	public native int getRadius();
}
