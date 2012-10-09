package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseBackInOut extends EaseAction {
	public static EaseBackInOut make() {
		return new EaseBackInOut();
	}
	
    public static EaseBackInOut make(IntervalAction action) {
        return new EaseBackInOut(action);
    }
    
    protected EaseBackInOut() {
		nativeInit(null);
	}

    protected EaseBackInOut(IntervalAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个EaseBackInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseBackInOut}
     */
    public static EaseBackInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseBackInOut(pointer);
    }

    protected EaseBackInOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(IntervalAction action);
    
    @Override
    public EaseAction copy() {
        return new EaseBackInOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
    	 return new EaseBackInOut(nativeReverse());
    }
}
