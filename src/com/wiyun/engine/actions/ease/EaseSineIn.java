package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseSineIn extends EaseAction {
    public static EaseSineIn make(IntervalAction action) {
        return new EaseSineIn(action);
    }
    
    public static EaseSineIn make() {
    	return new EaseSineIn();
    }
    
    protected EaseSineIn() {
		nativeInit(null);
	}

    protected EaseSineIn(IntervalAction action) {
    	nativeInit(action);
    }
    
    private native void nativeInit(IntervalAction action);

    /**
     * 从底层指针获得一个EaseSineIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseSineIn}
     */
    public static EaseSineIn from(int pointer) {
    	return pointer == 0 ? null : new EaseSineIn(pointer);
    }
    
    protected EaseSineIn(int pointer) {
    	super(pointer);
	}

    @Override
    public EaseAction reverse() {
        return new EaseSineOut(nativeReverse());
    }
    
    @Override
    public EaseAction copy() {
    	return new EaseSineIn(nativeCopy());
    }
}

