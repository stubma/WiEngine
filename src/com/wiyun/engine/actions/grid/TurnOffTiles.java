package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网格随机消失动作。网格按照随机顺序一个一个消失直到全部消失。
 */
public class TurnOffTiles extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static TurnOffTiles make(float duration, WYGridSize gSize) {
		return new TurnOffTiles(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected TurnOffTiles(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个TurnOffTiles的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TurnOffTiles}
     */
    public static TurnOffTiles from(int pointer) {
    	return pointer == 0 ? null : new TurnOffTiles(pointer);
    }
	
	protected TurnOffTiles(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);

	@Override
	public TiledGrid3DAction copy() {
		return new TurnOffTiles(nativeCopy());
	}
}
