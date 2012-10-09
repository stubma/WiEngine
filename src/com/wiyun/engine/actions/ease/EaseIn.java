package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseIn extends EaseRateAction {
    public static EaseIn make(IntervalAction action, float rate) {
        return new EaseIn(action, rate);
    }
    
    public static EaseIn make(float rate) {
    	return new EaseIn(rate);
    }
    
    protected EaseIn(float rate) {
    	nativeInit(null, rate);
    }

    protected EaseIn(IntervalAction action, float rate) {
       nativeInit(action, rate);
    }
    
    private native void nativeInit(IntervalAction action, float rate);

    /**
     * 从底层指针获得一个EaseIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseIn}
     */
    public static EaseIn from(int pointer) {
    	return pointer == 0 ? null : new EaseIn(pointer);
    }
    
    protected EaseIn(int pointer) {
    	super(pointer);
    }
    
	@Override
    public EaseAction copy() {
        return new EaseIn(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseIn(nativeReverse());
    }
}
