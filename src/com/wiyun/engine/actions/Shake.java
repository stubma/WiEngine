package com.wiyun.engine.actions;


/**
 * \if English
 * node is moved randomly in a circle area fast, looks like shaking
 * \else
 * 节点在一个圆形区域范围内随机移动, 造成抖动的效果
 * \endif
 */
public class Shake extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param radius radius of shaking area
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param radius 抖动半径, 节点在不超过这个半径的圆内抖动
	 * \endif
	 */
    public static Shake make(float duration, float radius) {
        return new Shake(duration, radius);
    }

    protected Shake(float duration, float radius) {
    	nativeInit(duration, radius);
    }
    
    public static Shake from(int pointer) {
    	return pointer == 0 ? null : new Shake(pointer);
    }
    
    protected Shake(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float radius);

    @Override
    public IntervalAction copy() {
        return new Shake(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new Shake(nativeReverse());
    }
}
