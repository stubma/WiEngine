package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBounceOut extends EaseBounce {
    public static EaseBounceOut make(IntervalAction action) {
        return new EaseBounceOut(action);
    }
    
    public static EaseBounceOut make() {
    	return new EaseBounceOut();
    }
    
    protected EaseBounceOut() {
		nativeInit(null);
	}

    protected EaseBounceOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseBounceOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBounceOut}
     */
    public static EaseBounceOut from(int pointer) {
    	return pointer == 0 ? null : new EaseBounceOut(pointer);
    }

    protected EaseBounceOut(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction copy() {
        return new EaseBounceOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseBounceIn(nativeReverse());
    }
}
