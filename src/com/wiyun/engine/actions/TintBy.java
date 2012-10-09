package com.wiyun.engine.actions;


/**
 * \if English
 * It changes color of node by a delta value
 * \else
 * 节点染色的动作封装,根据设置染色量进行移动
 * \endif
 */
public class TintBy extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in seconds
	 * @param r delta value of red component
	 * @param g delta value of green component
	 * @param b delta value of blue component
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param r 红色值变化值
	 * @param g 绿色值变化值
	 * @param b 蓝色值变化值
	 * \endif
	 */
	public static TintBy make(float duration, int r, int g, int b) {
		return new TintBy(duration, r, g, b);
	}

	protected TintBy(float duration, int r, int g, int b) {
		nativeInit(duration, r, g, b);
	}
	
    public static TintBy from(int pointer) {
    	return pointer == 0 ? null : new TintBy(pointer);
    }
	
	protected TintBy(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int r, int g, int b);

	@Override
	public IntervalAction copy() {
		return new TintBy(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new TintBy(nativeReverse());
	}
}
