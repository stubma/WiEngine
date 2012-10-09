package com.wiyun.engine.actions;


/**
 * \if English
 * Make a node visible
 * \else
 * 节点可见的动作封装，对节点执行可见操作
 * \endif
 */
public class Show extends InstantAction {
    protected Show() {
    	nativeInit();
	}
   
    public static Show from(int pointer) {
    	return pointer == 0 ? null : new Show(pointer);
    }
    
    protected Show(int pointer) {
    	super(pointer);
	}
    
    private native void nativeInit();

    public static Show make() {
        return new Show();
    }

    @Override
    public InstantAction copy() {
    	return new Show(nativeCopy());
    }

    @Override
    public InstantAction reverse() {
        return new Hide(nativeReverse());
    }
}
