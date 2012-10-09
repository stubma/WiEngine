package com.wiyun.engine.actions;

/**
 * \if English
 * Toggle visibility of a node
 * \else
 * 节点可见与不可见切换的动作封装
 * \endif
 */
public class ToggleVisibility extends InstantAction {
    public static ToggleVisibility make() {
        return new ToggleVisibility();
    }
    
    public static ToggleVisibility from(int pointer) {
    	return pointer == 0 ? null : new ToggleVisibility(pointer);
    }
    
	protected ToggleVisibility(int pointer) {
		super(pointer);
	}
    
    protected ToggleVisibility() {
    	nativeInit();
    }

	private native void nativeInit();

    @Override
    public InstantAction copy() {
    	return new ToggleVisibility(nativeCopy());
    }
    
    @Override
    public InstantAction reverse() {
    	return new ToggleVisibility(nativeReverse());
    }
}
