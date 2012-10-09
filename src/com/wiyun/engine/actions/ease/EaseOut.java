package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseOut extends EaseRateAction {
    public static EaseOut make(IntervalAction action, float rate) {
        return new EaseOut(action, rate);
    }
    
    public static EaseOut make(float rate) {
    	return new EaseOut(rate);
    }
    
    protected EaseOut(float rate) {
    	nativeInit(null, rate);
    }

    protected EaseOut(IntervalAction action, float rate) {
    	nativeInit(action, rate);
    }
    
    /**
     * 从底层指针获得一个EaseOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseOut}
     */
    public static EaseOut from(int pointer) {
    	return pointer == 0 ? null : new EaseOut(pointer);
    }
    
    protected EaseOut(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(IntervalAction action, float rate);
    
	@Override
    public EaseAction copy() {
        return new EaseOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseOut(nativeReverse());
    }
}
