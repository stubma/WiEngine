package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 波浪效果
 */
public class Waves extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @param vertical 是否垂直方向有波浪效果
	 * @param horizontal 是否水平方向有波浪效果
	 * @return 动作实例
	 */
	public static Waves make(float duration, WYGridSize gridSize, float amplitude, int waves, boolean vertical, boolean horizontal) {
		return new Waves(duration, gridSize, amplitude, waves, vertical, horizontal);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @param vertical 是否垂直方向有波浪效果
	 * @param horizontal 是否水平方向有波浪效果
	 */
	protected Waves(float duration, WYGridSize gridSize, float amplitude, int waves, boolean vertical, boolean horizontal) {
		nativeInit(duration, gridSize.x, gridSize.y, amplitude, waves, vertical, horizontal);
	}
	
    /**
     * 从底层指针获得一个Waves的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Waves}
     */
    public static Waves from(int pointer) {
    	return pointer == 0 ? null : new Waves(pointer);
    }
	
	protected Waves(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float amplitude, int waves, boolean vertical, boolean horizontal);

	@Override
	public Grid3DAction copy() {
		return new Waves(nativeCopy());
	}
}
