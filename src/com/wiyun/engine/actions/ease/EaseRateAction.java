package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

/**
 * Base class for Easing actions with mRate parameters
 */
public abstract class EaseRateAction extends EaseAction {
    protected EaseRateAction() {
    }

    protected EaseRateAction(IntervalAction action, float aRate) {
    }
    
    protected EaseRateAction(int pointer) {
    	super(pointer);
    }
}
