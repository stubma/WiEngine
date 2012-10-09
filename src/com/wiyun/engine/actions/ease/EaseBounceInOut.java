package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBounceInOut extends EaseBounce {
    public static EaseBounceInOut make(IntervalAction action) {
        return new EaseBounceInOut(action);
    }
    
    public static EaseBounceInOut make() {
    	return new EaseBounceInOut();
    }
    
    protected EaseBounceInOut() {
    	nativeInit(null);
    }

    protected EaseBounceInOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseBounceInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBounceInOut}
     */
    public static EaseBounceInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseBounceInOut(pointer);
    }
    
    protected EaseBounceInOut(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(IntervalAction action);

    @Override
    public EaseAction copy() {
        return new EaseBounceInOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseBounceInOut(nativeReverse());
    }
}
