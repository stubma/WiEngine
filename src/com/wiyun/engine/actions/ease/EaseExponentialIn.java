package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseExponentialIn extends EaseAction {
    public static EaseExponentialIn make(IntervalAction action) {
        return new EaseExponentialIn(action);
    }
    
    public static EaseExponentialIn make() {
    	return new EaseExponentialIn();
    }
    
    protected EaseExponentialIn() {
    	nativeInit(null);
    }

    protected EaseExponentialIn(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseExponentialIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseExponentialIn}
     */
    public static EaseExponentialIn from(int pointer) {
    	return pointer == 0 ? null : new EaseExponentialIn(pointer);
    }

    protected EaseExponentialIn(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

    @Override
    public EaseAction reverse() {
        return new EaseExponentialOut(nativeReverse());
    }
    
    @Override
    public EaseAction copy() {
    	return new EaseExponentialIn(nativeCopy());
    }
}

