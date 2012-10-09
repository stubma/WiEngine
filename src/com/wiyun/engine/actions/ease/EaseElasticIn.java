package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseElasticIn extends EaseElastic {
    public static EaseElasticIn make(IntervalAction action) {
        return new EaseElasticIn(action, 0.3f);
    }

    public static EaseElasticIn make(IntervalAction action, float period) {
        return new EaseElasticIn(action, period);
    }
    
    public static EaseElasticIn make(float period) {
    	return new EaseElasticIn(period);
    }
    
    protected EaseElasticIn(float period) {
		nativeInit(null, period);
	}

    protected EaseElasticIn(IntervalAction action, float period) {
    	nativeInit(action, period);
    }
    
    /**
     * 从底层指针获得一个EaseElasticIn的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseElasticIn}
     */
    public static EaseElasticIn from(int pointer) {
    	return pointer == 0 ? null : new EaseElasticIn(pointer);
    }

    protected EaseElasticIn(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action, float period);
    
	@Override
    public EaseAction copy() {
        return new EaseElasticIn(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseElasticOut(nativeReverse());
    }
}
