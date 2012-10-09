package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 抖动效果 
 */
public class Shaky3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static Shaky3D make(float duration, WYGridSize gridSize, int range, boolean shakeZ) {
		return make(duration, gridSize, range, 0, shakeZ);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 * @return 动作实例
	 */
	public static Shaky3D make(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		return new Shaky3D(duration, gridSize, range, deltaRange, shakeZ);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 抖动的幅度，越大越剧烈
	 * @param deltaRange 抖动的幅度变化值
	 * @param shakeZ 是否在z轴方向上抖动
	 */
	protected Shaky3D(float duration, WYGridSize gridSize, int range, int deltaRange, boolean shakeZ) {
		nativeInit(duration, gridSize.x, gridSize.y, range, deltaRange, shakeZ);
	}
	
    /**
     * 从底层指针获得一个Shaky3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Shaky3D}
     */
    public static Shaky3D from(int pointer) {
    	return pointer == 0 ? null : new Shaky3D(pointer);
    }
	
	protected Shaky3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, int range, int deltaRange, boolean shakeZ);

	@Override
	public Grid3DAction copy() {
		return new Shaky3D(nativeCopy());
	}
}
