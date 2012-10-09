package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseInOut extends EaseRateAction {
    public static EaseInOut make(IntervalAction action, float rate) {
        return new EaseInOut(action, rate);
    }
    
    public static EaseInOut make(float rate) {
    	return new EaseInOut(rate);
    }
    
    protected EaseInOut(float rate) {
    	nativeInit(null, rate);
    }

    protected EaseInOut(IntervalAction action, float rate) {
       nativeInit(action, rate);
    }

    /**
     * 从底层指针获得一个EaseInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseInOut}
     */
    public static EaseInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseInOut(pointer);
    }
    
    protected EaseInOut(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(IntervalAction action, float rate);
    
	@Override
    public EaseAction copy() {
        return new EaseInOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseInOut(nativeReverse());
    }
}
