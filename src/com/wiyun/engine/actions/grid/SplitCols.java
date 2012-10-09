package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 按照网格的列数，对每列进行交错滑动。 
 */
public class SplitCols extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @return 动作实例
	 */
	public static SplitCols make(float duration, WYGridSize gSize) {
		return new SplitCols(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected SplitCols(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个SplitCols的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link SplitCols}
     */
    public static SplitCols from(int pointer) {
    	return pointer == 0 ? null : new SplitCols(pointer);
    }
	
	protected SplitCols(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);

	@Override
	public TiledGrid3DAction copy() {
		return new SplitCols(nativeCopy());
	}
}
