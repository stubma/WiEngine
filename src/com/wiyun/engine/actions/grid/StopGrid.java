package com.wiyun.engine.actions.grid;

import com.wiyun.engine.actions.InstantAction;


/**
 * 停止网格特效。 当不需要网格操作时，这个动作会中止网格操作，释放相关资源。
 */
public class StopGrid extends InstantAction {
	/**
	 * 创建动作实例
	 * 
	 * @return 动作实例
	 */
	public static StopGrid make() {
		return new StopGrid();
	}
	
	protected StopGrid() {	
		nativeInit();
	}
	
    /**
     * 从底层指针获得一个StopGrid的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link StopGrid}
     */
    public static StopGrid from(int pointer) {
    	return pointer == 0 ? null : new StopGrid(pointer);
    }
    
	protected StopGrid(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
	
	@Override
	public InstantAction copy() {
		return new StopGrid(nativeCopy());
	}
	
	@Override
	public InstantAction reverse() {
		throw new UnsupportedOperationException("StopGrid doesn't have reverse action");
	}
}
