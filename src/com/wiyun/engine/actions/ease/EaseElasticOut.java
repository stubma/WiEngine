package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseElasticOut extends EaseElastic {
    public static EaseElasticOut make(IntervalAction action) {
        return new EaseElasticOut(action, 0.3f);
    }

    public static EaseElasticOut make(IntervalAction action, float period) {
        return new EaseElasticOut(action, period);
    }
    
    public static EaseElasticOut make(float period) {
    	return new EaseElasticOut(period);
    }
    
    protected EaseElasticOut(float period) {
		nativeInit(null, period);
	}

    protected EaseElasticOut(IntervalAction action, float period) {
    	nativeInit(action, period);
    }
    
    /**
     * 从底层指针获得一个EaseElasticOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseElasticOut}
     */
    public static EaseElasticOut from(int pointer) {
    	return pointer == 0 ? null : new EaseElasticOut(pointer);
    }

    protected EaseElasticOut(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit(IntervalAction action, float period);

	@Override
    public EaseAction copy() {
        return new EaseElasticOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseElasticIn(nativeReverse());
    }
}
