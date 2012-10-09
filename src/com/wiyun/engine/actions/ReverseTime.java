package com.wiyun.engine.actions;


/**
 * \if English
 * make update time from 1 to 0 so it can easily reverse any action
 * \else
 * 反向执行动作的封装
 * \endif
 */
public class ReverseTime extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param other the action need to be reversed
	 * \else
	 * 静态构造函数
	 *
	 * @param other 要反转执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink指针
	 * \endif
	 */
    public static ReverseTime make(FiniteTimeAction action) {
        return new ReverseTime(action);
    }

    protected ReverseTime(FiniteTimeAction action) {
    	nativeInit(action);
    }
    
    private native void nativeInit(FiniteTimeAction action);

    public static ReverseTime from(int pointer) {
    	return pointer == 0 ? null : new ReverseTime(pointer);
    }
    
    public ReverseTime(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
    	 return new ReverseTime(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new ReverseTime(nativeReverse());
    }
}
