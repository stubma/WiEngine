package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public class EaseElasticInOut extends EaseElastic {
    public static EaseElasticInOut make(IntervalAction action) {
        return new EaseElasticInOut(action, 0.3f);
    }

    public static EaseElasticInOut make(IntervalAction action, float period) {
        return new EaseElasticInOut(action, period);
    }
    
    public static EaseElasticInOut make(float period) {
    	return new EaseElasticInOut(period);
    }
    
    protected EaseElasticInOut(float period) {
		nativeInit(null, period);
	}

    protected EaseElasticInOut(IntervalAction action, float period) {
    	nativeInit(action, period);
    }
    
    /**
     * 从底层指针获得一个EaseElasticInOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link EaseElasticInOut}
     */
    public static EaseElasticInOut from(int pointer) {
    	return pointer == 0 ? null : new EaseElasticInOut(pointer);
    }

    protected EaseElasticInOut(int pointer) {
		super(pointer);
	}
    
    private native void nativeInit(IntervalAction action, float period);

	@Override
    public EaseAction copy() {
        return new EaseElasticInOut(nativeCopy());
    }

    @Override
    public EaseAction reverse() {
        return new EaseElasticInOut(nativeReverse());
    }
}
