package com.wiyun.engine.actions;


/**
 * \if English
 * Hide a node by calling setVisible method. A node which is hidden will not draw and respond to events
 * \else
 * 节点隐藏的动作封装，对节点执行隐藏操作
 * \endif
 */
public class Hide extends InstantAction {
	protected Hide() {
		nativeInit();
	}
	
    public static Hide from(int pointer) {
    	return pointer == 0 ? null : new Hide(pointer);
    }
    
    protected Hide(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit();

    public static Hide make() {
        return new Hide();
    }

    @Override
    public InstantAction copy() {
    	return new Hide(nativeCopy());
    }

    @Override
    public InstantAction reverse() {
        return new Show(nativeCopy());
    }
}
