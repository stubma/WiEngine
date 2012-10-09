package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBackIn extends EaseAction {
	public static EaseBackIn make() {
		return new EaseBackIn();
	}
	
    public static EaseBackIn make(IntervalAction action) {
        return new EaseBackIn(action);
    }
    
    protected EaseBackIn() {
    	nativeInit(null);
    }

    protected EaseBackIn(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseBackIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBackIn}
     */
    public static EaseBackIn from(int pointer) {
    	return pointer == 0 ? null : new EaseBackIn(pointer);
    }
    
    protected EaseBackIn(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction copy() {
    	return new EaseBackIn(nativeCopy());
    }
    
    @Override
    public EaseAction reverse() {
    	 return new EaseBackOut(nativeReverse());
    }
}
