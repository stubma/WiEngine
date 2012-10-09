package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseSineOut extends EaseAction {
    public static EaseSineOut make(IntervalAction action) {
        return new EaseSineOut(action);
    }
    
    public static EaseSineOut make() {
    	return new EaseSineOut();
    }
    
    protected EaseSineOut() {
    	nativeInit(null);
    }

    protected EaseSineOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    private native void nativeInit(IntervalAction action);

    /**
     * 从底层指针获得一个EaseSineOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseSineOut}
     */
    public static EaseSineOut from(int pointer) {
    	return pointer == 0 ? null : new EaseSineOut(pointer);
    }
    
    protected EaseSineOut(int pointer) {
    	super(pointer);
	}

	@Override
    public EaseAction reverse() {
        return new EaseSineIn(nativeReverse());
    }
    
    @Override
    public EaseAction copy() {
    	return new EaseSineOut(nativeCopy());
    }
}