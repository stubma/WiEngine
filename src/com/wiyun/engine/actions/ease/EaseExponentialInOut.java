package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseExponentialInOut extends EaseAction {
    public static EaseExponentialInOut make(IntervalAction action) {
        return new EaseExponentialInOut(action);
    }
    
    public static EaseExponentialInOut make() {
    	return new EaseExponentialInOut();
    }
    
    protected EaseExponentialInOut() {
    	nativeInit(null);
    }

    protected EaseExponentialInOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseExponentialInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseExponentialInOut}
     */
    public static EaseExponentialInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseExponentialInOut(pointer);
    }
    
    protected EaseExponentialInOut(int pointer) {
		super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction copy() {
        return new EaseExponentialInOut(nativeCopy());
    }
    
    @Override
    public EaseAction reverse() {
    	return new EaseExponentialInOut(nativeReverse());
    }
}

