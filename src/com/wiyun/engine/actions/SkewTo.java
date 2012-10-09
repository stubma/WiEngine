package com.wiyun.engine.actions;

/**
 * \if English
 * Skew x/y axis
 * \else
 * 改变x/y轴倾斜度的动作
 * \endif
 */
public class SkewTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param startSkewX start x skew degree
	 * @param endSkewX end x skew degree
	 * @param startSkewY start y skew degree
	 * @param endSkewY end y skew degree
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startSkewX 起始x倾斜角度
	 * @param endSkewX 结束x倾斜角度
	 * @param startSkewY 起始y倾斜角度
	 * @param endSkewY 结束y倾斜角度
	 * \endif
	 */
    public static SkewTo make(float duration, float startSkewX, float endSkewX, float startSkewY, float endSkewY) {
        return new SkewTo(duration, startSkewX, endSkewX, startSkewY, endSkewY);
    }

    protected SkewTo(float duration, float startSkewX, float endSkewX, float startSkewY, float endSkewY) {
    	nativeInit(duration, startSkewX, endSkewX, startSkewY, endSkewY);
    }
   
    public static SkewTo from(int pointer) {
    	return pointer == 0 ? null : new SkewTo(pointer);
    }
    
    protected SkewTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float startSkewX, float endSkewX, float startSkewY, float endSkewY);

    @Override
    public IntervalAction copy() {
        return new SkewTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new SkewTo(nativeReverse());
    }
}
