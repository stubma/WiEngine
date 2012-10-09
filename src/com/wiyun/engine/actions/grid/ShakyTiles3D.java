package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网格抖动。
 */
public class ShakyTiles3D extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动程度，越大越剧烈
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static ShakyTiles3D make(float duration, WYGridSize gridSize, int range, boolean shakeZ) {
		return make(duration, gridSize, range, 0, shakeZ);
	}

	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动
	 * @param deltaRange 抖动变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static ShakyTiles3D make(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		return new ShakyTiles3D(duration, gridSize, range, deltaRange, shakeZ);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动
	 * @param deltaRange 抖动变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 */
	protected ShakyTiles3D(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		nativeInit(duration, gridSize.x, gridSize.y, range, deltaRange, shakeZ);
	}
	
    /**
     * 从底层指针获得一个ShakyTiles3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ShakyTiles3D}
     */
    public static ShakyTiles3D from(int pointer) {
    	return pointer == 0 ? null : new ShakyTiles3D(pointer);
    }
	
	protected ShakyTiles3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, int range, int deltaRange, boolean shakeZ);

	@Override
	public TiledGrid3DAction copy() {
		return new ShakyTiles3D(nativeCopy());
	}
}
