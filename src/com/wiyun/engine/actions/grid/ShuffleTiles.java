package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网格洗牌动作。 把网格打算重新放置。
 */
public class ShuffleTiles extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @return 动作实例
	 */
	public static ShuffleTiles make(float duration, WYGridSize gSize) {
		return new ShuffleTiles(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected ShuffleTiles(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个ShuffleTiles的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ShuffleTiles}
     */
    public static ShuffleTiles from(int pointer) {
    	return pointer == 0 ? null : new ShuffleTiles(pointer);
    }
	
	protected ShuffleTiles(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);

	@Override
	public TiledGrid3DAction copy() {
		return new ShuffleTiles(nativeCopy());
	}
}
