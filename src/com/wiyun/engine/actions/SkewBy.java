package com.wiyun.engine.actions;


/**
 * \if English
 * Skew x/y axis
 * \else
 * 改变x/y轴倾斜度的动作
 * \endif
 */
public class SkewBy extends IntervalAction {
	/**
	 * \if English
	 * Static creator
	 *
	 * @param duration action duration time in seconds
	 * @param skewX the angle between y axis and node left border, positive value means
	 * 		clockwise
	 * @param skewY the angle between x axis and node bottom border, positive value means
	 * 		clockwise
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续时间, 秒
	 * @param skewX x方向变化的倾斜度, 表示y轴和节点左边界的夹角, 正值表示顺时针
	 * @param skewY y方向变化的倾斜度, 表示x轴和节点下边界的夹角, 正式表示顺时针
	 * \endif
	 */
    public static SkewBy make(float duration, float skewX, float skewY) {
        return new SkewBy(duration, skewX, skewY);
    }

    protected SkewBy(float duration, float skewX, float skewY) {
    	nativeInit(duration, skewX, skewY);
    }
    
    private native void nativeInit(float duration, float skewX, float skewY);

    public static SkewBy from(int pointer) {
    	return pointer == 0 ? null : new SkewBy(pointer);
    }
    
    protected SkewBy(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new SkewBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new SkewBy(nativeReverse());
    }
}
