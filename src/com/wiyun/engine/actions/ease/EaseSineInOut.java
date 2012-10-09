package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseSineInOut extends EaseAction {
    public static EaseSineInOut make(IntervalAction action) {
        return new EaseSineInOut(action);
    }
    
    public static EaseSineInOut make() {
    	return new EaseSineInOut();
    }
    
    protected EaseSineInOut() {
		nativeInit(null);
	}

    protected EaseSineInOut(IntervalAction action) {
        nativeInit(action);
    }

    /**
     * 从底层指针获得一个EaseSineInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseSineInOut}
     */
    public static EaseSineInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseSineInOut(pointer);
    }
    
    protected EaseSineInOut(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction reverse() {
        return new EaseSineInOut(nativeReverse());
    }
    
    @Override
    public EaseAction copy() {
    	return new EaseSineInOut(nativeCopy());
    }
}