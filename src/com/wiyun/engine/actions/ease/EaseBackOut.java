package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBackOut extends EaseAction {
	public static EaseBackOut make() {
		return new EaseBackOut();
	}
	
    public static EaseBackOut make(IntervalAction action) {
        return new EaseBackOut(action);
    }
    
    protected EaseBackOut() {
    	nativeInit(null);
    }

    protected EaseBackOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseBackOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBackOut}
     */
    public static EaseBackOut from(int pointer) {
    	return pointer == 0 ? null : new EaseBackOut(pointer);
    }

    protected EaseBackOut(int pointer) {
		super(pointer);
	}
    
    private native void nativeInit(IntervalAction action);

	@Override
    public EaseAction copy() {
        return new EaseBackOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseBackIn(nativeReverse());
    }
}
