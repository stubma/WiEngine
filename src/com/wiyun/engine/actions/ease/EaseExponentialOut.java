package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseExponentialOut extends EaseAction {
    public static EaseExponentialOut make(IntervalAction action) {
        return new EaseExponentialOut(action);
    }
    
    public static EaseExponentialOut make() {
    	return new EaseExponentialOut();
    }
    
    protected EaseExponentialOut() {
    	nativeInit(null);
    }

    protected EaseExponentialOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseExponentialOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseExponentialOut}
     */
    public static EaseExponentialOut from(int pointer) {
    	return pointer == 0 ? null : new EaseExponentialOut(pointer);
    }

    protected EaseExponentialOut(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction reverse() {
        return new EaseExponentialIn(nativeReverse());
    }
    
    @Override
    public EaseAction copy() {
    	return new EaseExponentialOut(nativeCopy());
    }
}

