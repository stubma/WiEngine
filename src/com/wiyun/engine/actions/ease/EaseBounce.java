package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

public abstract class EaseBounce extends EaseAction {
    protected EaseBounce(IntervalAction action) {
    }
    
    protected EaseBounce(int pointer) {
    	super(pointer);
    }
    
    protected EaseBounce() {
    }
}
