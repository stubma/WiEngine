package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBounceIn extends EaseBounce {
	public static EaseBounceIn make() {
		return new EaseBounceIn();
	}
	
    public static EaseBounceIn make(IntervalAction action) {
        return new EaseBounceIn(action);
    }
    
    protected EaseBounceIn() {
    	nativeInit(null);
    }

    protected EaseBounceIn(IntervalAction action) {
    	nativeInit(action);
    }

    /**
     * 从底层指针获得一个EaseBounceIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBounceIn}
     */
    public static EaseBounceIn from(int pointer) {
    	return pointer == 0 ? null : new EaseBounceIn(pointer);
    }
    
    protected EaseBounceIn(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction copy() {
        return new EaseBounceIn(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseBounceOut(nativeReverse());
    }
}
