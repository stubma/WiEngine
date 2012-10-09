package com.wiyun.engine.actions;

/**
 * \if English
 * Blink a node
 * \else
 * 控制节点闪烁动作的封装
 * \endif
 */
public class Blink extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time in second
	 * @param times times of blink
	 * @return \link wyBlink wyBlink\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param times 节点闪烁的次数
	 * @return \link wyBlink wyBlink\endlink
	 * \endif
	 */
    public static Blink make(float duration, int times) {
        return new Blink(duration, times);
    }

    protected Blink(float duration, int times) {
    	nativeInit(duration, times);
    }

    public static Blink from(int pointer) {
    	return pointer == 0 ? null : new Blink(pointer);
    }
    
	protected Blink(int pointer) {
		super(pointer);
	}
	
    private native void nativeInit(float duration, int times);
    
    @Override
    public IntervalAction copy() {
    	return new Blink(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new Blink(nativeReverse());
    }
}
