package com.wiyun.engine.filters;

import com.wiyun.engine.types.WYColor3B;

/**
 * \if English
 * drop shadow texture
 * \else
 * 阴影滤镜
 * \endif
 */
public class DropShadowColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个DropShadowColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link DropShadowColorFilter}
     */
    public static DropShadowColorFilter from(int pointer) {
    	return pointer == 0 ? null : new DropShadowColorFilter(pointer);
    }
    
    public static DropShadowColorFilter make(WYColor3B color, int radius, int highlightRadius, int opacity) {
    	return new DropShadowColorFilter(color, radius, highlightRadius, opacity);
    }
    
    protected DropShadowColorFilter(WYColor3B color, int radius, int highlightRadius, int opacity) {
    	nativeInit(color, radius, highlightRadius, opacity);
    }
    
    private native void nativeInit(WYColor3B color, int radius, int highlightRadius, int opacity);

	protected DropShadowColorFilter(int pointer) {
    	super(pointer);
    }

	/**
	 * \if English
	 * Set radius
	 *
	 * @param radius blur radius
	 * \else
	 * 设置阴影半径
	 *
	 * @param radius 阴影半径
	 * \endif
	 */
	public native void setRadius(int radius);

	/**
	 * \if English
	 * Get radius
	 *
	 * @return radius
	 * \else
	 * 得到阴影半径
	 *
	 * @return 阴影半径
	 * \endif
	 */
	public native int getRadius();
	
	/**
	 * \if English
	 * Set opacity of the glow
	 *
	 * @param opacity of the glow
	 * \else
	 * 设置阴影透明度
	 *
	 * @param opacity 阴影透明度
	 * \endif
	 */
	public native void setOpacity(int opacity);

	/**
	 * \if English
	 * The opacity of the glow
	 *
	 * @return The opacity of the glow
	 * \else
	 * 得到阴影透明度
	 *
	 * @return 阴影透明度
	 * \endif
	 */
	public native int getOpacity();

	/**
	 * \if English
	 * Set radius of the highlight area
	 *
	 * @param highlightRadius of the highlight area
	 * \else
	 * 设置阴影高亮区域半径
	 *
	 * @param highlightRadius 阴影高亮区域半径
	 * \endif
	 */
	public native void setHighlightRadius(int highlightRadius);

	/**
	 * \if English
	 * The radius of the highlight area
	 *
	 * @return The radius of the highlight area
	 * \else
	 * 得到阴影高亮区域半径
	 *
	 * @return 阴影高亮区域半径
	 * \endif
	 */
	public native int getHighlightRadius();
}
