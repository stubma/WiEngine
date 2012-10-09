package com.wiyun.engine.actions.grid;

import com.wiyun.engine.actions.InstantAction;
import com.wiyun.engine.grid.BaseGrid;

/**
 * 复用网格。{@link BaseGrid}对象可以重复利用，可以节省时间。如果两个效果需要使用网格完成，而网格的大小
 * 没有变化，一般可以复用网格。网格内部有复用次数的计数，这个动作就是增加它的复用次数计数。 
 */
public class ReuseGrid extends InstantAction {
	/**
	 * 创建动作实例
	 * 
	 * @param times 复用次数
	 * @return 动作实例
	 */
	public static ReuseGrid make(int times) {
		return new ReuseGrid(times);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param times 复用次数
	 */
	protected ReuseGrid(int times) {
		nativeInit(times);
	}
	
    /**
     * 从底层指针获得一个ReuseGrid的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ReuseGrid}
     */
    public static ReuseGrid from(int pointer) {
    	return pointer == 0 ? null : new ReuseGrid(0, pointer);
    }
    
	protected ReuseGrid(int dummy, int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(int times);
	
	@Override
	public InstantAction copy() {
		return new ReuseGrid(0, nativeCopy());
	}
	
	@Override
	public InstantAction reverse() {
		return new ReuseGrid(0, nativeReverse());
	}
}
