package com.wiyun.engine.filters;

/**
 * \if English
 * Custom color filter, filter is implemented by setting a delegate
 * \else
 * 自定义的滤镜实现, 通过设置一个代理来让开发者实现滤镜方法
 * \endif
 */
public class CustomColorFilter extends ColorFilter {
	public static interface IColorFilterDelegate {
		/**
		 * \if English
		 * process image data
		 *
		 * @param imageData raw data of image which must be RGBA8888 format, it holds transformed result when method returns
		 * @param width image pixel width, it is the original size before autoscaling
		 * @param height image pixel height, it is the original size before autoscaling
		 * \else
		 * 对一个图像数据应用自定义的滤镜算法
		 *
		 * @param imageData 图像原始数据, 必须是RGBA8888格式, 方法完成后, data中的数据变成转换后的值.
		 * @param width 图像的像素宽度, 为未自动缩放前的大小
		 * @param height 图像的像素高度, 为未自动缩放前的大小
		 * \endif
		 */
		public void apply(byte[] imageData, int width, int height);
	}
	
    /**
     * 从底层指针获得一个CustomColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CustomColorFilter}
     */
    public static CustomColorFilter from(int pointer) {
    	return pointer == 0 ? null : new CustomColorFilter(pointer);
    }
    
    public static CustomColorFilter make(IColorFilterDelegate delegate) {
    	return new CustomColorFilter(delegate);
    }
    
    protected CustomColorFilter(IColorFilterDelegate delegate) {
    	nativeInit(delegate);
    }
    
    private native void nativeInit(IColorFilterDelegate delegate);

	protected CustomColorFilter(int pointer) {
    	super(pointer);
    }
	
	/**
	 * \if English
	 * Set delegate
	 *
	 * @param delegate \link IColorFilterDelegate IColorFilterDelegate\endlink
	 * \else
	 * 设置代理
	 *
	 * @param delegate \link IColorFilterDelegate IColorFilterDelegate\endlink 
	 * \endif
	 */
	public native void setDelegate(IColorFilterDelegate delegate);
}
