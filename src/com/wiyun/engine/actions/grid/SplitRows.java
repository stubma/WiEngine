package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 按照网格的行数，对每行进行交错滑动。 
 */
public class SplitRows extends TiledGrid3DAction {
	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	public static SplitRows make(float duration, WYGridSize gSize) {
		return new SplitRows(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected SplitRows(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个SplitRows的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link SplitRows}
     */
    public static SplitRows from(int pointer) {
    	return pointer == 0 ? null : new SplitRows(pointer);
    }
	
	protected SplitRows(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);

	@Override
	public TiledGrid3DAction copy() {
		return new SplitRows(nativeCopy());
	}
}
