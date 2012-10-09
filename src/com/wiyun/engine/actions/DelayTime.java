package com.wiyun.engine.actions;


/**
 * \if English
 * Just wait for a while and do nothing
 * \else
 * 延时动作。仅仅就是一段时间内什么也不做，和其它动作组合使用，相当于起到定时的作用。 
 * \endif
 */
public class DelayTime extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration waiting time
	 * @return \link wyDelayTime wyDelayTime\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @return \link wyDelayTime wyDelayTime\endlink
	 * \endif
	 */
    public static DelayTime make(float duration) {
    	return new DelayTime(duration);
    }
    
    public static DelayTime from(int pointer) {
    	return pointer == 0 ? null : new DelayTime(pointer);
    }
    
	protected DelayTime(int pointer) {
		super(pointer);
	}
    
    private native void nativeInit(float duration);

    protected DelayTime(float duration) {
    	nativeInit(duration);
    }

    @Override
    public void update(float duration) {
    }
    
    @Override
    public IntervalAction copy() {
    	return new DelayTime(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new DelayTime(nativeReverse());
    }
}
